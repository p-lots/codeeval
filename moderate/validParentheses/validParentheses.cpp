#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool validate(string);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    int count = 1;
    
    while (getline(file, line)) {
        if (validate(line)) {
        	cout << "True" << endl;
        }
        else {
        	cout << "False" << endl;
        }
    }
    
    file.close();
    return 0;
}

bool validate(string line)
{
	string close = "]})";
	string::size_type start = 0, persClosePos, closePos, openPos;

	closePos = line.find_first_of(close, start);

	if (closePos == string::npos)
		return false;

	while (closePos != string::npos) {
		string comp = line.substr(closePos, 1);

		if (comp.compare("]") == 0) {
			openPos = line.rfind("[", closePos);
			if (openPos == string::npos)
				return false;
			if (line.substr(openPos, (closePos - openPos)).find_first_of("({") != string::npos
				&& line.substr(openPos, (closePos - openPos)).find_last_of(")}") == string::npos)
				return false;
		}

		else if (comp.compare("}") == 0) {
			openPos = line.rfind("{", closePos);
			if (openPos == string::npos)
				return false;
			if (line.substr(openPos, (closePos - openPos)).find_first_of("([") != string::npos
				&& line.substr(openPos, (closePos - openPos)).find_last_of(")]") == string::npos)
				return false;
		}

		else if (comp.compare(")") == 0) {
			openPos = line.rfind("(", closePos);
			if (openPos == string::npos)
				return false;
			if (line.substr(openPos, (closePos - openPos)).find_first_of("{[") != string::npos
				&& line.substr(openPos, (closePos - openPos)).find_last_of("}]") == string::npos)
				return false;
		}

		start = closePos + 1;
		closePos = line.find_first_of(close, start);
	}

	return true;
}