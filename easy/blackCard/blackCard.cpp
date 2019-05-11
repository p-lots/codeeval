// https://www.codeeval.com/open_challenges/222/
// Submitted December 17, 2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void split_line(string line, vector<string>& output, int& n)
{
	stringstream ss(line);
	string temp;
	bool firstTime = true;

	while (getline(ss, temp, '|')) {
		if (firstTime) {
			stringstream s(temp);
			string t;

			while (getline(s, t, ' ')) 
				output.push_back(t);

			firstTime = false;
		}

		else {
			n = stoi(temp);
		}
	}
}

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        vector<string> names;
        int turns;

        split_line(line, names, turns);

        vector<string>::iterator it = names.begin();

        while (names.size() > 1) {
	        for (int i = 1; i < turns; ++i) {
	        	++it;

	        	if (it == names.end())
	        		it = names.begin();
	        }

	        names.erase(it);

	        it = names.begin();
	    }

	    cout << names[0] << endl;
    }
    
    file.close();
    return 0;
}