// https://www.codeeval.com/open_challenges/199/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

void split_line(string line, string& l, string& r)
{
	stringstream ss(line);
	string temp;
	bool firstTime = true;

	while (getline(ss, temp, ' ')) {
		if (firstTime) {
			l = temp;
			firstTime = false;
		}
		else
			r = temp;
	}
}

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        string l, r;
        split_line(line, l, r);

        for (string::size_type i = 0; i < l.length(); ++i) {
        	if (r[i] == '1')
        		l[i] = toupper(l[i]);
        }

        cout << l << endl;
    }
    
    file.close();
    return 0;
}