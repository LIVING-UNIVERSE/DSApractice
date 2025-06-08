#include<iostream>
#include<thread>
#include<chrono>
using namespace std; 

void taskA(){
    for(int i=0;i<10;i++){
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"taskA"<<i<<endl;
    }
}

void taskB(){
    for(int i=0;i<10;i++){
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"taskB"<<i<<endl;
    }
}

int main(){
    thread t1(taskA);
    thread t2(taskB);

    t1.join();
    t2.join();
    return 0;
}



// critical section problem
#include<iostream>
#include<thread>
#include<mutex>
using namespace std; 

int count=0;
mutex mtx;

void task(){
    for(int i=0;i<1000000;i++){
        mtx.lock();
        count++;
        mtx.unlock();
    }
}

// or

void task(){
    for(int i=0;i<100000;i++){
        lock_guard<mutex> lock(mtx);
        count++;
    }
}

int main(){
    thread t1(task);
    thread t2(task);

    t1.join();
    t2.join();
    cout<<count;
    return 0;
}



//(1.) single flag solution for thread synchronization
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int counter = 0;
int turn = 0;  // 0 means thread1's turn, 1 means thread2's turn

void thread1() {
    for (int i = 0; i < 10; ++i) {
        // Wait until it's thread1's turn
        while (turn != 0) {
            this_thread::yield();  // Give up CPU, avoid busy wait
        }

        // Critical Section
        counter++;
        cout << "Thread 1: Counter = " << counter << endl;

        // Give turn to thread2
        turn = 1;

        // Simulate some work
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void thread2() {
    for (int i = 0; i < 10; ++i) {
        // Wait until it's thread2's turn
        while (turn != 1) {
            this_thread::yield();
        }

        // Critical Section
        counter++;
        cout << "Thread 2: Counter = " << counter << endl;

        // Give turn back to thread1
        turn = 0;

        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    cout << "Final Counter: " << counter << endl;

    return 0;
}



// (2.)  Peterson's solution for thread synchronization
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

// Shared variables
int counter = 0;
atomic<bool> flag[2];  // flag[0] for thread1, flag[1] for thread2
atomic<int> turn;      // Indicates whose turn it is

void thread1() {
    for (int i = 0; i < 10; ++i) {
        // Entry Section
        flag[0] = true;
        turn = 1;
        while (flag[1] && turn == 1) {
            this_thread::yield();  // Wait
        }

        // Critical Section
        counter++;
        cout << "Thread 1: Counter = " << counter << endl;

        // Exit Section
        flag[0] = false;

        // Remainder Section
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void thread2() {
    for (int i = 0; i < 10; ++i) {
        // Entry Section
        flag[1] = true;
        turn = 0;
        while (flag[0] && turn == 0) {
            this_thread::yield();  // Wait
        }

        // Critical Section
        counter++;
        cout << "Thread 2: Counter = " << counter << endl;

        // Exit Section
        flag[1] = false;

        // Remainder Section
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {
    // Initialize flags and turn
    flag[0] = false;
    flag[1] = false;
    turn = 0;

    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    cout << "Final Counter: " << counter << endl;

    return 0;
}



//(3.) Thread synchronization using conditional variables
#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>

using namespace std;

condition_variable cond;
mutex mtx;
int done = 1;

void task(const string& name) {
    unique_lock<mutex> lock(mtx);

    if (done == 1) {
        done = 2;
        cout << "Waiting on condition variable cond: " << name << endl;
        cond.wait(lock);  // Releases lock and waits
        cout << "Condition met: " << name << endl;
    } else {
        for (int i = 0; i < 5; ++i) {
            cout << ".";
            cout.flush();
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "\nSignaling condition variable cond: " << name << endl;
        cond.notify_all();
        cout << "Notification done: " << name << endl;
    }
}

int main() {
    thread t1(task, "t1");
    thread t2(task, "t2");

    t1.join();
    t2.join();

    return 0;
}



