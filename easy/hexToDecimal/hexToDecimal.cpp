// https://www.codeeval.com/open_challenges/67/
// submitted December 16, 2015

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		string::size_type len = line.length() - 1;
		long r = 0;
		int n;

		for (string::size_type i = 0; i < line.length(); ++i) {
			if (line[i] == 'a')
				n = 10;
			else if (line[i] == 'b')
				n = 11;
			else if (line[i] == 'c')
				n = 12;
			else if (line[i] == 'd')
				n = 13;
			else if (line[i] == 'e')
				n = 14;
			else if (line[i] == 'f')
				n = 15;
			else
				n = line[i] - '0';

			r += (pow(16, len--) * n);
		}

		cout << r << endl;
	}

	file.close();
	return 0;
}