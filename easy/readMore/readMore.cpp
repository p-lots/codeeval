// https://www.codeeval.com/open_challenges/167/
// Submitted November 25, 2015

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		string finalLine, readMore = "... <Read More>";
		if (line.length() > 55) {
			string newLine = line.substr(0, 40);
			newLine = newLine.substr(0, newLine.find_last_of(" "));
			
			finalLine = newLine + readMore;
		}
		else 
			finalLine = line;
		cout << finalLine << endl;
	}

	return 0;
}