#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>

using namespace std;

void split_line(string line, vector<int>& output)
{
	stringstream ss(line);
	string temp;

	while (getline(ss, temp, ','))
		output.push_back(stoi(temp));
}

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        vector<int> nums;
        split_line(line, nums);

        int counter = 2;
        long max = LONG_MIN, sum = 0;

        if (nums.size() > 2) {
	        for (vector<int>::size_type it = 0; it < nums.size() - 1; ++it) {
	        	sum = nums[it];

	        	for (counter = 2; counter <= nums.size() - it; ++counter) {
		        	for (vector<int>::size_type jt = it + 1; jt < it + counter; ++jt) {
		        		sum += nums[jt];

		        		if (sum > max) 
		        			max = sum;
		        	}

		        	sum = nums[it];
		        }
				
				sum = 0;
	        }
	    }
        else {
        	for (vector<int>::size_type i = 0; i < nums.size(); ++i)
        		sum += nums[i];

        	max = sum;
        }

        cout << max << endl;
    }
    
    file.close();
    return 0;
}