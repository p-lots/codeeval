// https://www.codeeval.com/open_challenges/208/
// Submitted January 30, 2016

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void readScores(string line, vector<vector<int> >& output)
{
	vector<string> lines;
	string delimiter = " | ";
	string::size_type start = 0, end;
	end = line.find(delimiter);
	while (end != string::npos) {
		lines.push_back(line.substr(start, end - start));
		start = end + delimiter.length();
		end = line.find(delimiter, start);
	}
	lines.push_back(line.substr(start, end));

	for (vector<string>::size_type i = 0; i < lines.size(); ++i) {
		stringstream ss(lines[i]);
		string temp;
		vector<int> row;
		while (getline(ss, temp, ' ')) 
			row.push_back(stoi(temp));
		
		output.push_back(row);
	}
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		vector<vector<int> > data;

		readScores(line, data);

		vector<int>::size_type cols = data[0].size();
		int maxScores[cols];

		for (int i = 0; i < cols; ++i) 
			maxScores[i] = 0;

		for (int j = 0; j < cols; ++j) {
			for (vector<vector<int> >::size_type i = 0; i < data.size(); ++i) {
				if (data[i][j] > maxScores[j])
					maxScores[j] = data[i][j];
			}
		}

	for (int i = 0; i < cols; ++i) 
		cout << maxScores[i] << " ";
	
	cout << endl;	
	}

	return 0;
}