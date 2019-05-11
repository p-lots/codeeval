// https://www.codeeval.com/open_challenges/73/

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int check_combinations(string);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        int p;

        if (line.length() == 1) {
        	p = 1;
        }

        else if (line.length() == 2) {
        	if (stoi(line) < 27) {
        		p = 2;
        	}

        	else {
        		p = 1;
        	}
        }

        else if (line.length() == 3) {
        	if (stoi(line.substr(0, 2)) < 27 && stoi(line.substr(1, 2)) < 27) {
        		p = 3;
        	}

        	else if (stoi(line.substr(0, 2)) < 27 || stoi(line.substr(1, 2)) < 27) {
        		p = 2;
        	}

        	else {
        		p = 1;
        	}
        }

        else if (line.length() == 4) {
        	p = check_combinations(line);
        }

        cout << p << endl;
        
    }
    
    file.close();
    return 0;
}

int check_combinations(string line)
{
	int ret = 1;
	vector<vector<int> > combs;

	vector<int> row;
	row.push_back(stoi(line.substr(0, 2))); // 12-3-4
	row.push_back(stoi(line.substr(2, 1)));
	row.push_back(stoi(line.substr(3, 1)));
	combs.push_back(row);
	row.clear();

	row.push_back(stoi(line.substr(0, 1))); // 1-23-4
	row.push_back(stoi(line.substr(1, 2)));
	row.push_back(stoi(line.substr(3, 1)));
	combs.push_back(row);
	row.clear();

	row.push_back(stoi(line.substr(0, 1))); // 1-2-34
	row.push_back(stoi(line.substr(1, 1)));
	row.push_back(stoi(line.substr(2, 2)));
	combs.push_back(row);
	row.clear();

	row.push_back(stoi(line.substr(0, 2))); // 12-34
	row.push_back(stoi(line.substr(2, 2)));
	combs.push_back(row);
	row.clear();

	bool isValid = false, firstTime = true;

	for (vector<vector<int> >::size_type i = 0; i < combs.size(); ++i) {
		for (vector<int>::size_type j = 0; j < combs[i].size(); ++j) {
			if (combs[i][j] < 27) {
				isValid = true;
			}

			else {
				isValid = false;
			}
		}

		if (isValid) {
			ret++;
		}
	}

	return ret;
}