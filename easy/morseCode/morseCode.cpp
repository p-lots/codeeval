// https://www.codeeval.com/open_challenges/116/
// Submitted November 23, 2015

#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

char lookup(string morse)
{
	char ret;

	if (morse == ".-")
		ret = 'A';
	else if (morse == "-...")
		ret = 'B';
	else if (morse == "-.-.")
		ret = 'C';
	else if (morse == "-..")
		ret = 'D';
	else if (morse == ".")
		ret = 'E';
	else if (morse == "..-.")
		ret = 'F';
	else if (morse == "--.")
		ret = 'G';
	else if (morse == "....")
		ret = 'H';
	else if (morse == "..")
		ret = 'I';
	else if (morse == ".---")
		ret = 'J';
	else if (morse == "-.-")
		ret = 'K';
	else if (morse == ".-..")
		ret = 'L';
	else if (morse == "--")
		ret = 'M';
	else if (morse == "-.")
		ret = 'N';
	else if (morse == "---")
		ret = 'O';
	else if (morse == ".--.")
		ret = 'P';
	else if (morse == "--.-")
		ret = 'Q';
	else if (morse == ".-.")
		ret = 'R';
	else if (morse == "...")
		ret = 'S';
	else if (morse == "-")
		ret = 'T';
	else if (morse == "..-")
		ret = 'U';
	else if (morse == "...-")
		ret = 'V';
	else if (morse == ".--")
		ret = 'W';
	else if (morse == "-..-")
		ret = 'X';
	else if (morse == "-.--")
		ret = 'Y';
	else if (morse == "--..")
		ret = 'Z';
	else if (morse == ".----")
		ret = '1';
	else if (morse == "..---")
		ret = '2';
	else if (morse == "...--")
		ret = '3';
	else if (morse == "....-")
		ret = '4';
	else if (morse == ".....")
		ret = '5';
	else if (morse == "-....")
		ret = '6';
	else if (morse == "--...")
		ret = '7';
	else if (morse == "---..")
		ret = '8';
	else if (morse == "----.")
		ret = '9';
	else if (morse == "-----")
		ret = '0';

	return ret;
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		string delimit = "  ";
		vector<string> morseCode;
		string token;

		string::size_type pos = 0;
		if ((pos = line.find(delimit)) != string::npos) {
			while ((pos = line.find(delimit)) != string::npos) {
				token = line.substr(0, pos);
				morseCode.push_back(token);
				line.erase(0, pos + delimit.length());
			}

			morseCode.push_back(line);
		}
		else
			morseCode.push_back(line);

		
		
		string sentence;

		for (vector<string>::const_iterator it = morseCode.begin();
			it != morseCode.end(); ++it) {
			
			string oneWord;
			char letter;
			
			stringstream ss(*it);
			string temp;

			while (getline(ss, temp, ' ')) {
				letter = lookup(temp);
				oneWord += letter;
			}

			sentence += (oneWord + " ");
		}

		cout << sentence << endl;	
	}

	return 0;
}