// https://www.codeeval.com/open_challenges/29/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void split_line(string, vector<int>&);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        vector<int> nums;
        split_line(line, nums);

        vector<int>::iterator it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));

        for (vector<int>::iterator i = nums.begin();
        	i != nums.end(); ++i) {
        	
        	cout << *i;

        	if (i == --nums.end())
        		cout << endl;
        	else
        		cout << ",";
        }
    }
    
    file.close();
    return 0;
}

void split_line(string line, vector<int>& nums)
{
	stringstream ss(line);
	string temp;

	while (getline(ss, temp, ','))
		nums.push_back(stoi(temp));
}