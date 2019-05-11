// https://www.codeeval.com/open_challenges/34/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

map<int, int> find_sum(int sum, vector<int> nums)
{
	map<int, int> ret;

	vector<bool> exclude;

	for (vector<int>::size_type i = 0; i < nums.size(); ++i)
		exclude.push_back(false);

	for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
		for (vector<int>::size_type j = 0; j < nums.size(); ++j) {
			if (nums[i] + nums[j] == sum && !exclude[i] && !exclude[j]) {
				ret.insert(make_pair(nums[i], nums[j]));
				exclude[i] = true;
				exclude[j] = true;
			}
		}
	}

	return ret;
}

void split_line(string line, vector<int>& nums, int& sum)
{
	string::size_type end = line.find(";");
	string first = line.substr(0, end);
	sum = stoi(line.substr(end + 1));

	string::size_type start = 0;

	while ((end = line.find(",", start)) != string::npos) {
		nums.push_back(stoi(line.substr(start, end - start)));
		start = end + 1;
	}

	nums.push_back(stoi(line.substr(start)));
}

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        vector<int> nums;
        int sum;

        split_line(line, nums, sum);

        map<int, int> pairs = find_sum(sum, nums);

        if (!pairs.empty()) {
	        for (map<int, int>::iterator it = pairs.begin(); it != pairs.end(); ++it) {
	        	cout << it->first << "," << it->second;
	        	
	        	if (it != --pairs.end())
	        		cout << ";";
	        	else
	        		cout << endl;
	        }
	    }
	    else 
	    	cout << "NULL" << endl;
    }
    
    file.close();
    return 0;
}