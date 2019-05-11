// https://www.codeeval.com/open_challenges/121/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string translate(string);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        string t = translate(line);

        cout << t << endl;
        
    }
    
    file.close();
    return 0;
}

string translate(string line)
{
	string ret = "", lookup = "ynficwlbkuomxsevzpdrjgthaq";
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	for (string::size_type i = 0; i < line.length(); ++i) {
		if (isalpha(line[i])) {
			ret += alpha.substr(lookup.find(line[i]), 1);
		}

		else if (isspace(line[i])) {
			ret += " ";
		}
	}

	return ret;
}