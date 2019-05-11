// https://www.codeeval.com/open_challenges/1/
// Submitted January 19, 2016

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream file;
	string line;

	file.open(argv[1]);

	ofstream outFile;
	
	while (!file.eof()) {
		getline(file, line);

		vector<int> vecInts;

		// Originally had a rudimentary "manual" strtok implementation here,
		// but decided to try to learn how to use cstrings
		// Open for suggestions on how to improve this

		char *cstr = new char[line.length() + 1];
		strcpy(cstr, line.c_str());
		char *pch = strtok(cstr, " ");
		while (pch != NULL) {
			vecInts.push_back(atoi(pch));
			pch = strtok(NULL, " ");
		}

		int divX = vecInts[0];
		int divY = vecInts[1];
		int maximum = vecInts[2];

		for (int i = 1; i < (maximum + 1); ++i) {
			if (i % (divX * divY) == 0)
				outFile << "FB";
			else if (i % divY == 0)
				outFile << "B";
			else if (i % divX == 0)
				outFile << "F";
			else
				outFile << i;

			if (i < maximum) 
				outFile << " ";
			else if (i == maximum)
				outFile << endl;
			
		}

		delete[] cstr;
	}

	file.close();

	return 0;
}