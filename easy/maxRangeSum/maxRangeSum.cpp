// https://www.codeeval.com/open_challenges/186/
// Submitted November 23, 2015

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		string delimiter = ";";
		string::size_type end = line.find(delimiter);
		int numOfDays = stoi(line.substr(0, end));

		string days = line.substr(end + 1, string::npos);
		stringstream ss(days);
		string temp;
		vector<int> totalsOfDays;

		while (getline(ss, temp, ' ')) 
			totalsOfDays.push_back(stoi(temp));

		int innersum = 0, outersum = 0;

		vector<int>::size_type j = 0;

		for (vector<int>::size_type i = 0; i <= totalsOfDays.size() - numOfDays; ++i) {
			
			for (j += i; j < numOfDays + i; ++j) 
				innersum += totalsOfDays[j];
			
			if (innersum > outersum)
				outersum = innersum;

			j = 0;
			innersum = 0;
		}

		cout << outersum << endl;		
	}

	return 0;
}