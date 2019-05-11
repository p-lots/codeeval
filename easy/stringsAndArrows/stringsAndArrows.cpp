// https://www.codeeval.com/open_challenges/203/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		string lArrow = "<--<<", rArrow = ">>-->";

		string::size_type start = 0, end;

		int lCount = 0, rCount = 0;

		while ((end = line.find(lArrow, start)) != string::npos) {
			lCount++;
			start = end + lArrow.length() - 1;
		}
		
		start = 0;

		while ((end = line.find(rArrow, start)) != string::npos) {
			rCount++;
			start = end + rArrow.length() - 1;
		}

		int total = lCount + rCount;

		cout << total << endl;
	}

	file.close();
	return 0;
}