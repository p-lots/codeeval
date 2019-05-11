// https://www.codeeval.com/open_challenges/196/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> swap_nums(vector<string> input)
{
	vector<string> output;
	string begin, middle, end, temp;

	for (vector<string>::size_type i = 0; i < input.size(); ++i) {
		int last = input[i].length() - 1;
		begin = input[i][last];
		middle = input[i].substr(1, input[i].length() - 2);
		end = input[i][0];
		temp = begin + middle + end;
		output.push_back(temp);
	}

	return output;
}

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
		vector<string> sentence;

		split_line(line, sentence);

		vector<string> result = swap_nums(sentence);

		for (vector<string>::size_type i = 0; i < result.size(); ++i) {
			cout << result[i] << " ";
		}

		cout << endl;
	}

	file.close();
	return 0;
}