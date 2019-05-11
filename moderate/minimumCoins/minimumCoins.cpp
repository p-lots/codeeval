// https://www.codeeval.com/open_challenges/74/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        int total = stoi(line), coins = 0;

        while (total >= 5) {
        	total -= 5;
        	coins++;
        }

        if (total >= 3) {
        	total -= 3;
        	coins++;
        }

        if (total >= 1) {
        	while (total >= 1) {
        		total--;
        		coins++;
        	}
        }

        cout << coins << endl;
    }
    
    file.close();
    return 0;
}