// https://www.codeeval.com/open_challenges/170/

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int findNumber(int, string);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        string delim = " ";
        string::size_type start = 0, end = line.find(delim, start);

        int range = stoi(line.substr(start, end - start));
        start = end + delim.length();

        int n = findNumber(range, line.substr(start));

        cout << n << "\n";
    }
    
    file.close();
    return 0;
}

int findNumber(int r, string line)
{
	int minN = 0, maxN = r, n, count = 1;

	if ((r + 1) % 2 == 0) {
		n = (r / 2) + 1;
	}

	else {
		n = r / 2;
	}

	string delim = " ";
	string::size_type start = 0, end;

	// cout << "#0\tminN: " << minN << "\tn: " << n << "\tmaxN: " << maxN << "\n";

	while ((end = line.find(delim, start)) != string::npos) {
		if (line.substr(start, end - start).compare("Lower") == 0) {
			maxN = n - 1;

			if (((maxN - minN) + 1) % 2 == 0) {
				n = minN + ((maxN - minN) / 2) + 1;
			}

			else {
				n = minN + ((maxN - minN) / 2);
			}
		}

		else if (line.substr(start, end - start).compare("Higher") == 0) {
			minN = n + 1;

			if (((maxN - minN) + 1) % 2 == 0) {
				n = minN + ((maxN - minN) / 2) + 1;
			}

			else {
				n = minN + ((maxN - minN) / 2);
			}
		}

		cout << line.substr(start, end - start) << "\n";

		start = end + delim.length();

		// cout << "#" << count++ << "\tminN: " << minN << "\tn: " << n << "\tmaxN: " << maxN << "\n";
	}

	return n;
}