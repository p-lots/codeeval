// https://www.codeeval.com/open_challenges/160/
// Submitted December 17, 2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        bool firstTime = true;
        stringstream ss(line);
        string temp;
        string r;
        int p;

        while (getline(ss, temp, '.')) {
        	if (firstTime) {
        		firstTime = false;
        		p = stoi(temp);
        	}
        	else
        		r = temp;
        }

        int min, sec;
        float m, s, inbtw = (stof(r)) / (pow(10, r.length()));
        m = inbtw * 60.0;
        min = m;
        s = ((inbtw * 60.0) - min) * 60.0;
        sec = s;

        cout << p << ".";
        cout << setfill('0') << setw(2) << min << "'";
        cout << setfill('0') << setw(2) << sec << "\"";
        cout << endl;
    }
    
    file.close();
    return 0;
}