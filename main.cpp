#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

// function declaration
vector<string> input_to_vector(const string name);

// main program
int main()
{
    vector<string> data = input_to_vector("example.txt");
    for (auto i : data)
    {
        cout << i << endl;
    }

    return 0;
}

// function description
vector<string> input_to_vector(const string name)
{
    vector<string> v1;
    string line;
    ifstream readFile(name);
    if (readFile.is_open())
    {
        while (getline(readFile, line))
        {
            v1.push_back(line);
        }
    }
    return v1;
}