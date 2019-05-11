#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        string str, rem;
        string::size_type start = 0, end;
        end = line.find(", ");
        str = line.substr(start, end - start);
        start = end + 2; // length of ", " - 1
        rem = line.substr(start);

        for (string::iterator i = str.begin(); i < str.end(); ++i) {
        	for (string::iterator j = rem.begin(); j < rem.end(); ++j) {
        		if (*i == *j) {
        			str.erase(i);
        		}
        		else if (i > str.begin() && *(i - 1) == *j) {
        			str.erase(i - 1);
        		}
        		else if (i < str.end() - 1 && *(i + 1) == *j) {
        			str.erase(i + 1);
        		}
        	}
        }

        if (*(str.end() - 1) == ' ') 
        	str.erase(str.end() - 1);
        
        cout << str << endl;
    }
    
    file.close();
    return 0;
}