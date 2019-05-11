// https://www.codeeval.com/open_challenges/22/
// Submitted january 19, 2016

#include <iostream>
#include <fstream>

using namespace std;

int fib(int);

int main(int argc, char *argv[])
{
    ifstream stream(argv[1]);
    string line;
    ofstream outputFile;

    while (getline(stream, line)) {
        int outputInt = fib(stoi(line));
        
	    outputFile << outputInt << endl;

    }

    return 0;
}

int fib (int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}