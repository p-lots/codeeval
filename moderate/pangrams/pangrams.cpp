// https://www.codeeval.com/open_challenges/37/

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
    	vector<char> missing;
    	bool found = false;

    	for (char letter = 'a'; letter < '{'; ++letter) {

	        for (string::size_type i = 0; i < line.length(); ++i) {

	        	if (isalpha(line[i])) {
		        	char test = tolower(line[i]);
		        	if (test == letter) 
		        		found = true;
	        	}
	        }

	        if (!found)
	        	missing.push_back(letter);
	        found = false;
	    }

	    if (!missing.empty()) {
		    for (vector<char>::iterator it = missing.begin(); it != missing.end(); ++it) {
		    	cout << *it;
		    }
		    cout << endl;
		}
		else
			cout << "NULL" << endl;
    }
    
    file.close();
    return 0;
}