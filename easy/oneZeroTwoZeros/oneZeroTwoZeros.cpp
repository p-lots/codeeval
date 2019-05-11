// https://www.codeeval.com/open_challenges/217/
// Submitted December 17, 2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string to_bin(int n)
{
	string ret;

	while (n != 0) {
		ret = (n % 2 == 0 ? "0" : "1") + ret;
		n /= 2;
	}

	return ret;
}

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        int zeros, n;
        stringstream ss(line);
        string temp;
        bool firstTime = true;

        while (getline(ss, temp, ' ')) {
        	if (firstTime) {
        		zeros = stoi(temp);
        		firstTime = false;
        	}

        	else {
        		n = stoi(temp);
        	}
        }

        string bin = to_bin(n);

        int count = 0, z = 0;

        while (n > 0) {
        	for (string::size_type i = 0; i < bin.length(); ++i) {
        		if (bin[i] == '0') {
        			z++;
        		}
        	}

        	if (z == zeros)
        		count++;

        	bin = to_bin(--n);
        	z = 0;	
        }
        
        cout << count << endl;
    }
    
    file.close();
    return 0;
}