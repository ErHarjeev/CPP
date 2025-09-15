#include <iostream>
#include <fstream>
#include <map>

using namespace std;

typedef struct icon icon;

int main(int arg, char* args[])
{
    ifstream readFile("../../test.txt");
    ofstream writeFile("result.txt");
    char c;
    map(char, int ) list;

    if(!readFile.is_open())
    {
        cout << "Input file Error" << endl;
        return 1;
    }

    if(!writeFile.is_open())
    {
        cout << "Output file Error" << endl;
        return 2;
    }

    while(readFile.get(c))
    {
        bool check_status = false;
        for(size_t i = 0; i < list.size(); ++i)
        {
            if(c == list[i].symbol)
            {
                list[i].count++;
                check_status = true;
                break;
            }
        }
        if(check_status == false)
        {
            list.emplace_back(icon{c, 1});
        }
    }

    // printing on the file
    cout << "printing on file " << endl;
    for(size_t i = 0; i < list.size(); ++i)
    {
        writeFile << list[i].symbol << " = " << list[i].count << endl;
    }

    return 0;
}
