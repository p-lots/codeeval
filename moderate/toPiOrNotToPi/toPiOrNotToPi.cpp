#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int to_hex(int);

int to_dec(int);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        int n = stoi(line);

        cout << place << endl;
    }
    
    file.close();
    return 0;
}

int to_hex(int n)
{
    string res, d = "0123456789ABCDEF";
 
    while(n > 0)
    {
        res = d[n % 16] + res;
        n /= 16;
    }
    
    return stoi(str_hex, nullptr, res);
}

int to_dec(int n)
{
    string res = to_string(n);
}