// https://www.codeeval.com/open_challenges/211/
// Submitted December 26, 2015

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void split_line(string, vector<string>&, string&);

vector<string> hasString(vector<string>, string);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        vector<string> wines;
        string searching;
        split_line(line, wines, searching);
        vector<string> results = hasString(wines, searching);

        if (!results.empty()) {
        	for (vector<string>::size_type i = 0; i < results.size(); ++i) {
        		cout << results[i];

        		if (i == results.size() - 1)
        			cout << endl;
        		else
        			cout << " ";
        	}
        }
        else {
        	cout << "False" << endl;
        } 

    }
    
    file.close();
    return 0;
}

void split_line(string line, vector<string>& wines, string& searching)
{
	stringstream ss(line);
	string temp;
	bool firstTime = true;

	while (getline(ss, temp, '|')) {
		if (firstTime) {
			stringstream s(temp);
			string t;
			
			while (getline(s, t, ' ')) {
				wines.push_back(t);
			}

			firstTime = false;
		}

		else {
			searching = temp.substr(1);
		}
	}
}

vector<string> hasString(vector<string> test, string search)
{
	vector<string> ret;

	bool containsSearch = true, firstTime = true;


	for (vector<string>::size_type i = 0; i < test.size(); ++i) {
		containsSearch = true;
		for (string::size_type j = 0; j < search.size(); ++j) {
			if (firstTime) {
				if (test[i].find(search[j]) != string::npos) {
					containsSearch = true;
				}
				else {
					containsSearch = false;
				}

				firstTime = false;
			}
			else { 
				if (test[i].find(search[j]) != string::npos) {
					containsSearch = true && containsSearch;
				}
				else {
					containsSearch = false;
				}
			}
		}

		
		firstTime = true;

		if (containsSearch) {
			ret.push_back(test[i]);
		}
	}

	return ret;
}