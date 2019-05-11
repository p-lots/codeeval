// https://www.codeeval.com/open_challenges/205/
// Submitted December 17, 2015

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    while (getline(file, line)) {
    	string output;

        for (string::size_type i = 0; i < line.length(); ++i) {
        	if (isalpha(line[i])) {
        		for (string::size_type j = i; j < line.length(); ++j) {
        			if (!isalpha(line[j])) {
        				output += (line.substr(i, j - i) + " ");

        				i = j;

        				break;
        			}
        			else if (line.find_first_not_of(alpha, j) == string::npos) {
        				output += (line.substr(i) + " ");
        				
        				i = line.length();

        				break;
        			}
        		}
        	}
        }

        for (string::size_type i = 0; i < output.size(); ++i) {
            if (isalpha(output[i]))
        	    output[i] = tolower(output[i]);
        }

        cout << output << endl;
    }
    
    file.close();
    return 0;
}