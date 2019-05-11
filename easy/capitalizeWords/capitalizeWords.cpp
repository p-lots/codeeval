// https://www.codeeval.com/open_challenges/93/
// Submitted November 21, 2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		string temp;
		string upper;
		string cocat;
		while (getline(ss, temp, ' ')) {
			char *cstr = new char[temp.length() + 1];
			strcpy(cstr, temp.c_str());
			cstr[0] = toupper(cstr[0]);
			upper = cstr;
			cocat += (upper + " ");
			delete[] cstr;
		}

		cout << cocat << endl;

	}

	return 0;
}