// https://www.codeeval.com/open_challenges/225/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void split_line(string line, string& l, string& r)
{
	stringstream ss(line);
	string temp;

	bool firstTime = true;
	while (getline(ss, temp, '|')) {
		if (firstTime) {
			l = temp.substr(0, temp.length() - 1);
			firstTime = false;
		}
		else
			r = temp.substr(1, temp.length() - 1);
	}
}

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        string l, r;
        split_line(line, l, r);

        int errCount = 0;

        for (string::size_type i = 0; i < l.length(); ++i) {
        	if (l[i] != r[i])
        		errCount++;
        }

        if (errCount > 0 && errCount < 3)
        	cout << "Low" << endl;
        else if (errCount > 2 && errCount < 5)
        	cout << "Medium" << endl;
        else if (errCount > 4 && errCount < 7)
        	cout << "High" << endl;
        else if (errCount > 6)
        	cout << "Critical" << endl;
        else
        	cout << "Done" << endl;
    }
    
    file.close();
    return 0;
}