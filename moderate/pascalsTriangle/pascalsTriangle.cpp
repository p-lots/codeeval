// https://www.codeeval.com/open_challenges/66/

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int pascal(int r, int c, int prev)
{
	return prev * ((r + 1 - c) / (float)c);
}

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        int n = stoi(line);
        vector<int> tri(3, 1);
        int prev;

        for (int i = 2; i < n; ++i) {
        	prev = 1;
        	tri.push_back(prev);
        	for (int j = 1; j < i; ++j) {
        		tri.push_back(pascal(i, j, prev));
        		prev = tri.back();
        	}
        	tri.push_back(1);
        }

        for (vector<int>::size_type i = 0; i < tri.size(); ++i) {
        	cout << tri[i];
        	if (i == tri.size() - 1)
        		cout << endl;
        	else
        		cout << " ";
        }
    }
    
    file.close();
    return 0;
}