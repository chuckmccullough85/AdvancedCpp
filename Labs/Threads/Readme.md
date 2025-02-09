## Overview
In this lab, we convert a synchronous function to a thread. 

| | |
| --------- | --------------------------- |
| Exercise Folder | Threads |
| Builds On | None |
| Time to complete | 20-40 minutes

---

### Setup 
Review the code in the *Threads* folder.  In *main.cpp*, the function *Monitor* accepts a path to a directory.  The function initially displays the contents of the directory and monitors for changes.  The loop has no blocks, so it will be checking for changes at top speed, consuming CPU time and rapid IO.

Follow the steps below to convert the function to use threads.  

### Steps - Monitor
1. So that we can signal when to stop, declare a global `bool running = true; ` and change the while loop in *Monitor* to loop on running instead of true
2. At the bottom of the loop (inside), add a sleep for a second or two so the function isn't running wide open
```this_thread::sleep_for(1s);```

### - Main
1. Allow for multiple directories from the command line, so define a container for multiple threads
```vector<thread> threads;```
2. Loop through the arguments (1 through argc) creating thread objects to call *Monitor* with the path
3. Add the thread to the list
4. Prompt the user to press enter to end
5. Change running to false to stop the Monitor loop
6. Loop through the threads, joining them so that they have all completed before terminating main

** Bonus - if the user provides a bad path, *Monitor* will throw an exception and cause the whole application to terminate.  Add a try/catch so that *Monitor* doesn't crash the program.
*** Bonus Bonus - create a mutex so that the threads aren't writing to **cout** simultaneously.

:::spoiler
```c++
#include <iostream>
#include <thread>
#include <mutex>
#include <filesystem>
#include <vector>

using namespace std;

mutex cout_mutex;
bool running = true;

void Watch(string path) noexcept
try
{
    filesystem::file_time_type lastTime;
    while (running)
    {
        filesystem::file_time_type time = filesystem::last_write_time(path);
        if (time != lastTime)
        {
            lock_guard<mutex> lock(cout_mutex);
            cout << "File changed " << path << endl;
            lastTime = time;
            for (auto file : filesystem::directory_iterator(path))
            {
                cout << file.path() << endl;
            }
        }
        this_thread::sleep_for(1s);
    }
}
catch (exception &e)
{
    cout << "Error: " << e.what() << endl;
}

int main(int argc, char *argv[])
{
    cout << "Threads Project" << endl;
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <path> ..." << endl;
        return 1;
    }
    vector<thread> threads;
    for (int i = 1; i < argc; i++)
    {
        string path = argv[i];
        threads.push_back(thread(Watch, path));
    }

    cout << "Press enter to exit" << endl;
    cin.get();
    running = false;
    for (auto &thread : threads)
        thread.join();
    return 0;
}
```
:::


### JThreads
A jthread (join thread) is a thread that has a join in the destructor.  With the jthread, we don't need to join before letting the parent thread die.  The thread's destructor will execute in the parent thread when it goes out of scope.  The join will make sure the thread has completed.

The thread function can also have an optional first parameter of type ```stop_token``` that can be used instead of the boolean running to control the loop.  The threads destructor signals the token to stop.  In the next pass of the loop, *Monitor* can stop looping and exit.  The destructor can then complete.

Modify the Monitor solution to use *jthreads*

:::spoiler
```c++
#include <iostream>
#include <thread>
#include <mutex>
#include <filesystem>
#include <vector>

using namespace std;

mutex cout_mutex;

void Watch(stop_token stop_token, string path) noexcept
try
{
    filesystem::file_time_type lastTime;
    while (!stop_token.stop_requested())
    {
        filesystem::file_time_type time = filesystem::last_write_time(path);
        if (time != lastTime)
        {
            lock_guard<mutex> lock(cout_mutex);
            cout << "File changed " << path << endl;
            lastTime = time;
            for (auto file : filesystem::directory_iterator(path))
            {
                cout << file.path() << endl;
            }
        }
        this_thread::sleep_for(1s);
    }
}
catch (exception &e)
{
    cout << "Error: " << e.what() << endl;
}

int main(int argc, char *argv[])
{
    cout << "Threads Project" << endl;
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <path> ..." << endl;
        return 1;
    }
    vector<jthread> threads;
    for (int i = 1; i < argc; i++)
    {
        string path = argv[i];
        threads.push_back(jthread(Watch, path));
    }

    cout << "Press enter to exit" << endl;
    cin.get();

    // no need to join - jthreads join on destructor
    // for (auto &thread : threads)
    //     thread.join();
    return 0;
}
```
:::