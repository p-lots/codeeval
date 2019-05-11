// https://www.codeeval.com/open_challenges/99/
// submitted March 23, 2016

#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

void split_line(string line, vector<int>& output)
{
	output.clear();

	string::size_type start = line.find('(');
	string::size_type end = line.find(',');
	string temp = line.substr(start + 1, end - start);
	int x1 = stoi(temp);
	output.push_back(x1);
	
	start = line.find_first_of(' ');
	end = line.find(')');
	temp = line.substr(start + 1, end - start);
	int y1 = stoi(temp);
	output.push_back(y1);
	
	start = line.find('(', end);
	end = line.find(',', start);
	temp = line.substr(start + 1, end - start);
	int x2 = stoi(temp);
	output.push_back(x2);

	start = line.find(' ', end);
	end = line.find(')', start);
	temp = line.substr(start + 1, end - start);
	int y2 = stoi(temp);
	output.push_back(y2);
}


int main(int argc, char *argv[1])
{
	ifstream file(argv[1]);
	string line;
	vector<int> numbers;
	int dist;

	while (getline(file, line)) {
		split_line(line, numbers);
		dist = sqrt(pow(numbers[2] - numbers[0], 2) + pow(numbers[3] - numbers[1], 2));
		cout << dist << endl;
		
	}
	return 0;
}