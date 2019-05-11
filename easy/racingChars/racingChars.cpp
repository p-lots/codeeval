// https://www.codeeval.com/open_challenges/136/
// Submitted December 16, 2015

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;
	bool firstTime = true;
	string::size_type prevFound;

	while (getline(file, line)) {
		string::size_type found = line.find("C");

		if (found != string::npos) {
			if (firstTime) {
				line.replace(found, 1, "|");

				firstTime = false;
			}
			else {
				if (prevFound < found) 
					line.replace(found, 1, "\\");

				else if (prevFound == found)
					line.replace(found, 1, "|");

				else
					line.replace(found, 1, "/");
			}
		}
		else {
			found = line.find("_");

			if (firstTime) {
				line.replace(found, 1, "|");

				firstTime = false;
			}

			else {
				if (prevFound < found) 
					line.replace(found, 1, "\\");

				else if (prevFound == found)
					line.replace(found, 1, "|");

				else
					line.replace(found, 1, "/");
			}
		}

		prevFound = found;

		cout << line << endl;
	}

	file.close();
	return 0;
}