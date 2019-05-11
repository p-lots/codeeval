// https://www.codeeval.com/open_challenges/41/

#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void split_line(string, vector<int>&);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
    	if (!line.empty()) {
	        string::size_type semi = line.find(";");
	        int len = stoi(line.substr(0, semi));
	        string numbers = line.substr(semi + 1);

	        vector<int> nums;
	        split_line(numbers, nums);

	        int dupe;

	        for (vector<int>::size_type i = 0; i < nums.size() - 2; ++i) {
	        	for (vector<int>::size_type j = i + 1; j < nums.size() - 1; ++j) {
	        		if (nums[i] == nums[j]) {
	        			dupe = nums[i];
	        			break;
	        		}
	        	}
	        }

	        cout << dupe;
	    }

	    cout << endl;
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