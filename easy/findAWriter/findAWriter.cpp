// https://www.codeeval.com/open_challenges/97/
// Submitted November 23, 2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		if (line.empty()) {
			//
		}
		else {
			stringstream ss(line);
			string temp;

			bool firstTime = true;
			string input;
			vector<int> key;

			while (getline(ss, temp, '|')) {
				if (firstTime) {
					input = temp;
					firstTime = false;
				}
			
				else {
					stringstream sss(temp.substr(1, temp.length()));
					string temp1;
					
					while (getline(sss, temp1, ' ')) 
						key.push_back(stoi(temp1));	
				}
			}
			
			string output;

			for (vector<int>::const_iterator it = key.begin();
				it != key.end(); ++it) {

				output += input[*it - 1];
			}

			cout << output << endl;
		}
	}

	return 0;
}