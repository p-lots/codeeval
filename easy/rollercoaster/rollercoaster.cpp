// https://www.codeeval.com/open_challenges/156/

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		int letterCount = 0;
		for (string::size_type i = 0; i < line.length(); ++i) {
			if (isalpha(line[i])) {
				if (letterCount % 2 == 0) {
					line[i] = toupper(line[i]);
					++letterCount;
				}
				else {
					line[i] = tolower(line[i]);
					++letterCount;
				}
			}
		}

		cout << line << endl;
	}

	return 0;
}