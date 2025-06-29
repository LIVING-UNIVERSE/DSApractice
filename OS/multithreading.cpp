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



// producer consumer problem
#include <iostream>
#include <thread>
#include <semaphore.h>
#include <queue>
#include <unistd.h>     // for sleep()
#include <mutex>

using namespace std;

const int BUFFER_SIZE = 5;
queue<int> buffer;

sem_t emptySlots;
sem_t fullSlots;
mutex mtx;

void producer(int id) {
    for (int i = 0; i < 10; ++i) {
        sem_wait(&emptySlots);           // Wait for empty slot

        {
            lock_guard<mutex> lock(mtx); // Lock buffer
            buffer.push(i);
            cout << "Producer " << id << " produced: " << i << endl;
        }

        sem_post(&fullSlots);            // Signal full slot
        sleep(1);
    }
}

void consumer(int id) {
    for (int i = 0; i < 10; ++i) {
        sem_wait(&fullSlots);            // Wait for filled slot

        int item;
        {
            lock_guard<mutex> lock(mtx); // Lock buffer
            item = buffer.front();
            buffer.pop();
            cout << "Consumer " << id << " consumed: " << item << endl;
        }

        sem_post(&emptySlots);           // Signal empty slot
        sleep(2);
    }
}

int main() {
    sem_init(&emptySlots, 0, BUFFER_SIZE);
    sem_init(&fullSlots, 0, 0);

    thread p1(producer, 1);
    thread c1(consumer, 1);

    p1.join();
    c1.join();

    sem_destroy(&emptySlots);
    sem_destroy(&fullSlots);

    return 0;
}



// reader write problem
#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h>  // for sleep()
#include <mutex>

using namespace std;

sem_t wrt;           // Semaphore for writer
mutex readMutex;     // Mutex to protect readCount
int readCount = 0;   // Number of active readers

void reader(int id) {
    while (true) {
        // Entry section
        readMutex.lock();
        readCount++;
        if (readCount == 1)
            sem_wait(&wrt);  // First reader locks writer
        readMutex.unlock();

        // Critical Section (Reading)
        cout << "Reader " << id << " is reading\n";
        sleep(1);

        // Exit section
        readMutex.lock();
        readCount--;
        if (readCount == 0)
            sem_post(&wrt);  // Last reader unlocks writer
        readMutex.unlock();

        sleep(1);  // Simulate delay before next read
    }
}

void writer(int id) {
    while (true) {
        // Entry section
        sem_wait(&wrt);  // Lock access for all readers/writers

        // Critical Section (Writing)
        cout << "Writer " << id << " is writing\n";
        sleep(2);

        // Exit section
        sem_post(&wrt);  // Unlock for others

        sleep(2);  // Simulate delay before next write
    }
}

int main() {
    sem_init(&wrt, 0, 1);

    thread r1(reader, 1);
    thread r2(reader, 2);
    thread w1(writer, 1);
    thread r3(reader, 3);

    r1.join();
    r2.join();
    w1.join();
    r3.join();

    sem_destroy(&wrt);
    return 0;
}


// philosophers dining problem with odd-even
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

using namespace std;

const int NUM_PHILOSOPHERS = 5;
mutex forks[NUM_PHILOSOPHERS];  // One mutex for each fork

void philosopher(int id) {
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    for (int i = 0; i < 3; ++i) {  // Each philosopher eats 3 times
        // Thinking
        cout << "Philosopher " << id << " is thinking.\n";
        this_thread::sleep_for(chrono::milliseconds(1000));

        // To avoid deadlock, pick up lower-numbered fork first
        if (id % 2 == 0) {
            forks[left].lock();
            forks[right].lock();
        } else {
            forks[right].lock();
            forks[left].lock();
        }

        // Eating
        cout << "Philosopher " << id << " is eating.\n";
        this_thread::sleep_for(chrono::milliseconds(1500));

        // Put down forks
        forks[left].unlock();
        forks[right].unlock();

        cout << "Philosopher " << id << " has finished eating.\n";
    }
}

int main() {
    vector<thread> philosophers;

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers.push_back(thread(philosopher, i));
    }

    for (auto& t : philosophers) {
        t.join();
    }

    return 0;
}
