// https://www.codeeval.com/open_challenges/111/
// Submitted November 21, 2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		string temp;
		string::size_type len = 0;
		string longWord;
		while (getline(ss, temp, ' ')) {
			if (temp.length() > len) {
				len = temp.length();
				longWord = temp;
			}
		}
		cout << longWord << endl;
	}

	return 0;
}