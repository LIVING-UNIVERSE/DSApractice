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