// https://www.codeeval.com/open_challenges/107/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		char toFind = line[0];

		string::size_type end = line.find(toFind, 1);

		string::size_type len = line.substr(0, end).length();

		cout << len << endl;
	}

	file.close();
	return 0;
}