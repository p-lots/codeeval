// https://www.codeeval.com/open_challenges/147/
// Submitted November 24, 2015

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		double upperPercentage, lowerPercentage;
		double lowerCount = 0.0, upperCount = 0.0;
		for (string::size_type i = 0; i < line.size(); ++i) {
			if (islower(line[i]))
				++lowerCount;
			else if (isupper(line[i]))
				++upperCount;
		}

		upperPercentage = (upperCount / (double)line.length()) * 100;
		lowerPercentage = (lowerCount / (double)line.length()) * 100;

		cout << "lowercase: " << fixed << setprecision(2) << lowerPercentage;
		cout << " uppercase: " << setprecision(2) << upperPercentage;
		cout << endl;
	}

	return 0;
}