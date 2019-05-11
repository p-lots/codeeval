// https://www.codeeval.com/open_challenges/173/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		string::size_type i = 1;
		string::size_type j;

		if (line.length() > 2)
			j = line.length() - 2;
		else
			j = 2;
		
		while (i < j) {
			if (line[i] == line[i + 1] || line[i] == line[i - 1]) {
				line.erase(i, 1);
				--j;
			}
			else
				++i;
		}

		cout << line << endl;
	}

	file.close();
	return 0;
}