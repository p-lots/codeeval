// https://www.codeeval.com/open_challenges/149/
// Submitted December 26, 2015

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

long long b2d(string n)
{
	long long ret = 0;

	int i = 0;

	for (string::reverse_iterator it = n.rbegin(); it != n.rend(); ++it) {
		if (*it == '1') 
			ret += pow(2, i);
		++i;
	}

	return ret;
}

void get_zeros(string line, vector<string>& zeros)
{
	stringstream ss(line);
	string temp;

	while (getline(ss, temp, ' '))
		zeros.push_back(temp);
}

void zeros_to_binary(vector<string> zeros, string& output)
{
	bool onesFlag = false, zerosFlag = false;

	for (vector<string>::size_type it = 0; it < zeros.size(); ++it) {
		if (it % 2 == 0) {
			if (zeros[it].compare("00") == 0){
				onesFlag = true;
				zerosFlag = false;
			}

			else if (zeros[it].compare("0") == 0) {
				zerosFlag = true;
				onesFlag = false;
			}
		}
		else {
			if (onesFlag) {
				for (string::size_type i = 0; i < zeros[it].length(); ++i) 
					output += "1";
				onesFlag = false;
			}

			else if (zerosFlag) {
				for (string::size_type i = 0; i < zeros[it].length(); ++i) 
					output += "0";
				zerosFlag = false;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		vector<string> zeros;
		get_zeros(line, zeros);

		string inter;
		zeros_to_binary(zeros, inter);

		long long decimal = b2d(inter);

		cout << decimal << endl;
	}

	return 0;
}