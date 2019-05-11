// https://www.codeeval.com/open_challenges/113/
// Submitted March 23, 2016

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file;
	string line, firstHalf, secondHalf;
	int n1, n2;
	vector<int> vIntA, vIntB;

	file.open(argv[1]);
	while(getline(file,line)) {
		char *temp = new char[line.length() + 1];
		strcpy(temp, line.c_str());

		char *pch = strtok(temp, "|");
		firstHalf = pch;
		pch = strtok(NULL, "n");
		secondHalf = pch;

		char *firstHalfTemp = new char[firstHalf.length() + 1];
		strcpy(firstHalfTemp, firstHalf.c_str());

		char *fpch = strtok(firstHalfTemp, " ");

		while (fpch != NULL) {
			vIntA.push_back(atoi(fpch));
			fpch = strtok(NULL, " ");
		}

		char *secondHalfTemp = new char[secondHalf.length() + 1];
		strcpy(secondHalfTemp, secondHalf.c_str());

		char *spch = strtok(secondHalfTemp, " ");
		while (spch != NULL) {
			vIntB.push_back(atoi(spch));
			spch = strtok(NULL, " ");
		}
		
		vector<int>::iterator iterB = vIntB.begin();

		for (vector<int>::iterator iter = vIntA.begin(); iter != vIntA.end(); ++iter)
			cout << (*iter) * (*iterB++) << " ";

		cout << endl;


		vIntA.clear();
		vIntB.clear();
		delete[] firstHalfTemp;
		delete[] secondHalfTemp;
		delete[] temp;
	}
	file.close();
	return 0;
}