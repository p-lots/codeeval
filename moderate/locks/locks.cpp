// https://www.codeeval.com/open_challenges/153/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void first_pass(vector<bool>&);

void second_pass(vector<bool>&);

void last_pass(vector<bool>&);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        string delim = " ";
        string::size_type d = line.find(delim);

        int doors = stoi(line.substr(0, d));
        int reps = stoi(line.substr(d + 1)) - 1;

        vector<bool> locks(doors, false); // false = not locked, true = locked

        for (int i = 0; i < reps; ++i) {
        	first_pass(locks);
        	second_pass(locks);
        }

        last_pass(locks);

        int count = 0;

        for (vector<bool>::size_type i = 0; i < locks.size(); ++i) {
        	if (!locks[i])
        		count++;
        }

        cout << count << endl;
    }
    
    file.close();
    return 0;
}

void first_pass(vector<bool>& locks)
{
	for (vector<bool>::size_type i = 0;	i < locks.size(); ++i) {
		if ((i + 1) % 2 == 0 && i != 0 && !locks[i]) { // lock every second door
			locks[i] = true;
		}
	}
}

void second_pass(vector<bool>& locks)
{
	for (vector<bool>::size_type i = 0; i < locks.size(); ++i) {
		if ((i + 1) % 3 == 0 && i != 0) {
			locks[i] = !locks[i];
		}
	}
}

void last_pass(vector<bool>& locks)
{
	vector<bool>::size_type i = locks.size() - 1;
	locks[i] = !locks[i];
}