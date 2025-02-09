#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <future>
#include <fstream>
#include <chrono>

using namespace std;
using ConvertResult = pair<string, int>;

ConvertResult ConvertFileToUpper (const string& fileName)
{
    cout << "Converting file " << fileName << endl;
    ifstream input(fileName);
    ofstream output(fileName + ".out");
    int count = 0;
    string line;
    while (getline(input, line))
    {
        for (auto& c : line)
        {
            char old = c;
            c = toupper(c);
            if (old != c) ++count;
        }
        output << line << endl;
    }
    return make_pair(fileName, count);
}


int main(int argc, char* argv[]) 
{
    cout << "Tasks Project" << endl;
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " file [file] ..." << endl;
        return 1;
    }
    vector<future<ConvertResult>> futures;
    for_each(argv + 1, argv + argc, [&futures](const char* fileName)
    {
        futures.push_back(async(ConvertFileToUpper, fileName));
    });
    for (auto& f : futures)
    {
        auto result = f.get();
        cout << "File " << result.first << " converted " << result.second << " characters" << endl;
    }

    return 0;
}