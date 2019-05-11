// https://www.codeeval.com/open_challenges/2/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;

    vector<string> lines;
    bool firstTime = true;
    int n;
    
    while (getline(file, line)) {
    	if (firstTime) {
    		n = stoi(line);
    		firstTime = false;
    	}
    	else 
	        lines.push_back(line);
    }
    
    map<int, string> lengths;

    for (vector<string>::iterator it = lines.begin();
    	it != lines.end(); ++it) {
    	lengths.insert(make_pair(it->length(), *it));
    }

    int i = 0;

    map<int, string>::reverse_iterator it = lengths.rbegin();

    while (i < n) {
    	cout << it->second << endl;
    	++it;
    	++i;
    }
    
    file.close();
    return 0;
}