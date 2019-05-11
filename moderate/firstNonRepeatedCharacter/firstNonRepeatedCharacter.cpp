// https://www.codeeval.com/open_challenges/12/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
    	string repeat;

        for (string::size_type i = 0; i < line.length(); ++i) {
        	for (string::size_type j = i; j < line.length(); ++j) {
        		if (line[i] == line[j] && j != i)
        			repeat += line[i];
        	}
        }

        string::size_type first = line.find_first_not_of(repeat);

        cout << line[first] << endl;
    }
    
    file.close();
    return 0;
}