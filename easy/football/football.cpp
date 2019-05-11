// https://www.codeeval.com/open_challenges/230/
// submitted January 8, 2016

#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void fill_vec(string, vector<vector<int> >&);

void get_list(vector<vector<int> >);

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		vector<vector<int> > data;
		fill_vec(line, data);
		
		get_list(data);
	}

	file.close();
	return 0;
}

void fill_vec(string line, vector<vector<int> >& output)
{
	vector<int> countries;

	string delim = "!";

	string::size_type end = line.find(" | ");

	while (end != string::npos) {
		line.replace(end, 3, delim);
		end = line.find(" | ");
	}

	stringstream ss(line);
	string temp;

	while (getline(ss, temp, '!')) {
		stringstream s(temp);
		string t;

		while (getline(s, t, ' ')) {
			countries.push_back(stoi(t));
		}

		sort(countries.begin(), countries.end());

		output.push_back(countries);
		countries.clear();
	}
}

void get_list(vector<vector<int> > data)
{
	vector<vector<int> > results;
	vector<int> teams;

	for (vector<vector<int> >::size_type i = 0; i < data.size(); ++i) {
		for (vector<int>::size_type j = 0; j < data[i].size(); ++j) {
			if (find(teams.begin(), teams.end(), data[i][j]) == teams.end()) {
				teams.push_back(data[i][j]);
			}
		}
	}

	sort(teams.begin(), teams.end());

	for (vector<int>::size_type i = 0; i < teams.size(); ++i) {
		vector<int> row;
		row.push_back(teams[i]);

		for (vector<vector<int> >::size_type k = 0; k < data.size(); ++k) {
			if (find(data[k].begin(), data[k].end(), teams[i]) != data[k].end()) {
				row.push_back(k + 1);
			}
		}

		results.push_back(row);
	}	

	for (vector<vector<int> >::size_type i = 0; i < results.size(); ++i) {
		bool firstTime = true;
		for (vector<int>::size_type j = 0; j < results[i].size(); ++j) {
			if (firstTime) {
				cout << results[i][j] << ":";
				firstTime = false;
			}

			else {
				if (j == results[i].size() - 1) {
					cout << results[i][j] << "; ";
				}

				else {
					cout << results[i][j] << ",";
				}
			}
		}
	}

	cout << endl;
}