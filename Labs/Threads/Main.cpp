#include <iostream>
#include <thread>
#include <mutex>
#include <filesystem>
#include <vector>

using namespace std;

void Watch(string path) noexcept
try
{
    filesystem::file_time_type lastTime;
    while (true)
    {
        filesystem::file_time_type time = filesystem::last_write_time(path);
        if (time != lastTime)
        {
            cout << "File changed " << path << endl;
            lastTime = time;
            for (auto file : filesystem::directory_iterator(path))
            {
                cout << file.path() << endl;
            }
        }
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
    Watch(argv[1]);
    return 0;
}