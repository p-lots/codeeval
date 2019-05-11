// https://www.codeeval.com/open_challenges/91/

#include <ios>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void split_line(string line, vector<double>& output) {
    string spl_line;
    stringstream ss(line);
    while (getline(ss, spl_line, ' '))
    	output.push_back(stod(spl_line));
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		vector<double> numbers;
		split_line(line, numbers);
		sort(numbers.begin(), numbers.end());
		for (vector<double>::const_iterator it = numbers.begin(); it != numbers.end(); ++it)
			cout << fixed << setprecision(5) << *it << " ";
		cout << endl;
	}

	return 0;
}