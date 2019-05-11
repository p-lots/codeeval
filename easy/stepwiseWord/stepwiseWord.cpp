// https://www.codeeval.com/open_challenges/202/

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void split_line(string line, vector<string>& output)
{
	stringstream ss(line);
	string temp;

	while (getline(ss, temp, ' ')) 
		output.push_back(temp);
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		vector<string> words;
		split_line(line, words);

		string::size_type len = 0;
		int longest;
		string longWord;

		for (vector<string>::size_type i = 0; i < words.size(); ++i) {
			if (words[i].length() > len) {
				longWord = words[i];
				len = words[i].length();
			}
		}

		vector<string> output;
		string asterisks;

		for (string::size_type j = 0; j < longWord.length(); ++j) {
			asterisks.clear();
			for (string::size_type k = 0; k < j; ++k)
				asterisks += "*";
			output.push_back(asterisks + longWord[j]);
		}

		for (vector<string>::size_type i = 0; i < output.size(); ++i) {
			cout << output[i] << " ";
		}

		cout << endl;
	}

	return 0;
}