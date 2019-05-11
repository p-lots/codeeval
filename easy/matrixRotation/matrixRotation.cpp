// https://www.codeeval.com/open_challenges/178/
// Submitted November 29, 2015

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iterator>
#include <algorithm>

using namespace std;

void get_letters(string line, vector<string>& output)
{
	stringstream ss(line);
	string temp;
	
	while (getline(ss, temp, ' ')) 
		output.push_back(temp);
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		vector<string> matrix;
		get_letters(line, matrix);

		vector<string> inter, output;

		int n = sqrt(matrix.size());
		int it = n - 1;
		int count = 0;
		int first;

		while (count < n * n) {
			first = 0;
			while (first < n) {
				inter.push_back(matrix[first * n + it]);
				++first;
				++count;
			}
			if (it < 1)
				it = n - 1;
			else
				--it;
		}

		copy(inter.rbegin(), inter.rend(), back_inserter(output));

		for (vector<string>::const_iterator iter = output.begin();
			iter != output.end(); ++iter) 
			cout << *iter << " ";

		cout << endl;
	}

	return 0;
}