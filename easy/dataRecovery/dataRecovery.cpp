// https://www.codeeval.com/open_challenges/140/
// Submitted December 16, 2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

void split_line(string line, vector<string>& first, vector<string>& second)
{
	stringstream ss(line);
	string temp;
	bool firstTime = true;

	while (getline(ss, temp, ';')) {
		stringstream s(temp);
		string t;

		if (firstTime) {
			while (getline(s, t, ' ')) 
				first.push_back(t);

			firstTime = false;
		}
		else {
			while (getline(s, t, ' '))
				second.push_back(t);
		}
	}
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		vector<string> firstHalf, secondHalf;

		split_line(line, firstHalf, secondHalf);

		map<int, string> sentence;

		if (firstHalf.size() == secondHalf.size()) {
			for (vector<string>::size_type i = 0; i < firstHalf.size(); ++i) {
				sentence.insert(make_pair(stoi(secondHalf[i]), firstHalf[i]));
			}
		}
		else {
			for (vector<string>::size_type i = 0; i < firstHalf.size(); ++i) {
				if (i < secondHalf.size()) {
					sentence.insert(make_pair(stoi(secondHalf[i]), firstHalf[i]));
				}
					
				else {
					int incr = 1;
					for (map<int, string>::iterator it = sentence.begin();
						it != sentence.end(); ++it) {
						if (incr != it->first)
							sentence.insert(make_pair(incr, firstHalf[i]));
						++incr;
					}
					if (incr > secondHalf.size())
						sentence.insert(make_pair(incr, firstHalf[i]));
				}
			}
		}

		if (!sentence.empty()) {
			for (map<int, string>::iterator it = sentence.begin();
				it != sentence.end(); ++it) {
				cout << it->second << " ";
			}
		}

		cout << endl;
		
	}

	file.close();
	return 0;
}