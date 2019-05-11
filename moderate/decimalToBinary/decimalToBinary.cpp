// https://www.codeeval.com/open_challenges/27/

#include <iostream>
#include <fstream>

using namespace std;

string to_bin(int n)
{
	string ret;

	if (n == 0) {
		ret = "0";
		return ret;
	}

	while (n != 0) {
		ret = (n % 2 == 0 ? "0" : "1") + ret;
		n /= 2;
	}

	return ret;
}

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
    	string bin = to_bin(stoi(line));
        cout << bin << endl;
    }
    
    file.close();
    return 0;
}