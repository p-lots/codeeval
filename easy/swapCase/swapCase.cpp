// https://www.codeeval.com/open_challenges/96/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		string temp;
		string concat;
		string word;
		while (getline(ss, temp, ' ')) {
			char *cstr = new char[temp.length() + 1];
			strcpy(cstr, temp.c_str());
			int i = 0;
			while (cstr[i]) {
				if (islower(cstr[i]))
					cstr[i] = toupper(cstr[i]);
				else if (isupper(cstr[i]))
					cstr[i] = tolower(cstr[i]);
				++i;
			}
			word = cstr;
			concat += (word + ' ');
			delete[] cstr;
		}

		cout << concat << endl;
	}

	return 0;
}