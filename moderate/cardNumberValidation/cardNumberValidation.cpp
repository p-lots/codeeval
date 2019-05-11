// https://www.codeeval.com/open_challenges/172/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

void toVec(string, vector<int>&);

bool validate(vector<int>);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        vector<int> nums;
        toVec(line, nums);

        if (validate(nums))
        	cout << "1" << endl;
        else
        	cout << "0" << endl;
    }
    
    file.close();
    return 0;
}

void toVec(string line, vector<int>& output)
{
	for (string::size_type i = 0; i < line.length(); ++i) 
		if (isdigit(line[i])) 
			output.push_back(line[i] - '0');
}

bool validate(vector<int> nums)
{
	int doubleSum = 0, otherSum = 0, count = 1;

	for (int i = nums.size() - 1; i >= 0; --i) {
		if (count % 2 == 0) {
			int temp = nums[i] * 2;
			if (temp > 9) 
				temp = temp % 10 + temp / 10;
			doubleSum += temp;
		}
		else 
			otherSum += nums[i];
		count++;
	}

	if ((doubleSum + otherSum) % 10 == 0)
		return true;
	else
		return false;
}