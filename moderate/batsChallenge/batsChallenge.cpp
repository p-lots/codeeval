// https://www.codeeval.com/open_challenges/146/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void get_bats(string, int&, int&, int&, vector<int>&);

int fill_wire(int, int, int, vector<int>&);

int howManyBatsBetween(int, int, int);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        int l, d, n;
        vector<int> wire;

        get_bats(line, l, d, n, wire);

        int bats = fill_wire(l, d, n, wire);

        cout << bats << endl;
    }
    
    file.close();
    return 0;
}

void get_bats(string line, int& l, int& d, int& n, vector<int>& wire)
{
	string delim = " ";
	string::size_type start = 0, end = line.find(delim);

	l = stoi(line.substr(start, end - start));
	start = end + delim.length();

	end = line.find(delim, start);
	d = stoi(line.substr(start, end - start));
	start = end + delim.length();

	end = line.find(delim, start);
	n = stoi(line.substr(start, end - start));
	start = end + delim.length();

	if (n == 1) {
		wire.push_back(stoi(line.substr(start)));
	}

	else if (n > 1 && line.find(delim, start) != string::npos) {
		while ((end = line.find(delim, start)) != string::npos) {
			wire.push_back(stoi(line.substr(start, end - start)));
			start = end + delim.length();
		}

		wire.push_back(stoi(line.substr(start)));
	}
}

int fill_wire(int l, int d, int n, vector<int>& wire)
{
	if (n == 0) {
		return (l - 12) / d + 1;
	}

	else {
		if (n > 1) {
			sort(wire.begin(), wire.end());
		}

		int batCounter = (wire.front() - 6) / d;

		if (n > 2) {
			for (vector<int>::size_type i = 1; i < wire.size() - 2; ++i) {
				batCounter += howManyBatsBetween(wire[i], wire[i + 1], d);
			}

			batCounter += ((l - 6) - wire.back()) / d;
		}

		else if (n == 2) {
			batCounter += howManyBatsBetween(wire[0], wire[1], d);
			batCounter += ((l - 6) - wire[1]) / d;
		}

		else {
			batCounter += ((l - 6) - wire.front()) / d;
		}

		return batCounter;
	}
}

int howManyBatsBetween(int first, int second, int d)
{
	int batCount = (second - first) / d - 1;
	return batCount < 0 ? 0 : batCount;
}

