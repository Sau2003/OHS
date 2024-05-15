#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mutex1, mutex2;

void thread1() {
    cout << "Thread 1 started" << endl;
    
    mutex1.lock();
    cout << "Thread 1 acquired mutex1" << endl;
    // Simulate some work
    this_thread::sleep_for(chrono::milliseconds(100));

    // Attempt to acquire mutex2
    cout << "Thread 1 attempting to acquire mutex2" << endl;
    mutex2.lock(); // This will lead to a deadlock

    cout << "Thread 1 finished" << endl;

    mutex1.unlock();
    mutex2.unlock();
}

void thread2() {
    cout << "Thread 2 started" << endl;
    
    mutex2.lock();
    cout << "Thread 2 acquired mutex2" << endl;
    // Simulate some work
    this_thread::sleep_for(chrono::milliseconds(100));

    // Attempt to acquire mutex1
    cout << "Thread 2 attempting to acquire mutex1" << endl;
    mutex1.lock(); // This will lead to a deadlock

    cout << "Thread 2 finished" << endl;

    mutex1.unlock();
    mutex2.unlock();
}

int main() {
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    // Check if both mutexes are unlocked
    if (!mutex1.try_lock() && !mutex2.try_lock()) {
        cout << "Both mutexes are unlocked. No deadlock occurred." << endl;
        mutex1.unlock(); // Releasing the lock acquired for the check
        mutex2.unlock(); // Releasing the lock acquired for the check
    } else {
        cout << "Deadlock occurred." << endl;
    }

    cout << "Main thread finished" << endl;

    return 0;
}

