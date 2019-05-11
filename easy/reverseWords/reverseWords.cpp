// https://www.codeeval.com/open_challenges/8/
// Submitted March 23, 2016

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream file;
	string line;

	file.open(argv[1]);

	while (getline(file, line)) {
		if (!line.empty() || isspace(line[0])) {
			string ret;
			char *temp = new char[line.length() + 1];
			strcpy(temp, line.c_str());
			char *pch;
			pch = strtok(temp, " ");
			while (pch != NULL) {
				ret.insert(0, pch);
				ret.insert(0, " ");
				pch = strtok(NULL, " ");
			}
			cout << ret << endl;
		}
	}
	file.close();
	return 0;
}