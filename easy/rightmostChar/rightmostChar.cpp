// https://www.codeeval.com/open_challenges/31/
// Submitted November 25, 2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		string temp;
		string search;
		string toBeSearched;
		bool firstTime = true;

		while (getline(ss, temp, ',')) {
			if (firstTime) {
				firstTime = false;
				search = temp;
			}
			else
				toBeSearched = temp;
		}

		string::size_type pos = search.find_last_of(toBeSearched);

		if (pos != string::npos) 
			cout << pos << endl;
		else
			cout << "-1" << endl;
	}

	return 0;
}