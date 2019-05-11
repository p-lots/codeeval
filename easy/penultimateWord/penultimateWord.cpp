// https://www.codeeval.com/open_challenges/92/
// Submitted November 18, 2015

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

void split_line(string line, vector<string>& output)
{
	stringstream ss(line);
	string temp;
	while (getline(ss, temp, ' '))
		output.push_back(temp);

}

string rev(vector<string> input)
{
	vector<string> temp;
	for (vector<string>::reverse_iterator it = input.rbegin(); it != input.rend(); ++it)
		temp.push_back(*it);

	return temp[1];
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;
	vector<string> words;

	while (getline(file, line)) {
		split_line(line, words);
		cout << rev(words) << endl;
	}
	
	return 0;
}