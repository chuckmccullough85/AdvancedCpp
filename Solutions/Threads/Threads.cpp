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