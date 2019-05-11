// https://www.codeeval.com/open_challenges/40/

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

bool validate(string);

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		if (validate(line))
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}

	file.close();
	return 0;
}

bool validate(string n)
{
	for (string::size_type i = 0;
		i < n.size(); ++i) {
		int val = i, num = n[i] - '0', j = 0;

		string::size_type end, start = 0;

		while (j < num) {
			if (n.find(to_string(val), start) == string::npos)
				return false;
			else {
				while ((end = n.find(to_string(val), start)) != string::npos) {
					++j;
					start = end + 1;
				}
			}
		}

		if (j == num)
			continue;
		else
			return false;
	}

	return true;
}