#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void split_line(string, vector<int>&);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        vector<int> nums;
        split_line(line, nums);
        int count = 0;

        sort(nums.begin(), nums.end());

        for (vector<int>::size_type i = 0; i < nums.size() - 3; ++i) {
        	for (vector<int>::size_type j = i + 1; j < nums.size() - 2; ++j) {
        		for (vector<int>::size_type k = j + 1; k < nums.size() - 1; ++k) {
        			for (vector<int>::size_type l = k + 1; l < nums.size(); ++l) {
        				if (nums[i] + nums[j] + nums[k] + nums[l] == 0)
        					count++;
        			}
        		}
        	}
        }

        cout << count << endl;
    }
    
    file.close();
    return 0;
}

void split_line(string line, vector<int>& output)
{
	stringstream ss(line);
	string temp;

	while (getline(ss, temp, ','))
		output.push_back(stoi(temp));
}