// https://www.codeeval.com/open_challenges/112/

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		string temp;
		bool firstTime = true;
		vector<int> nums;
		vector<string> instructions;
		vector<int> instnums;

		while (getline(ss, temp, ':')) {
			stringstream ss1(temp);
			string temp1;

			if (firstTime) {	
				while (getline(ss1, temp1, ' ')) 
					nums.push_back(stoi(temp1));
				firstTime = false;
			}
			else {
				while (getline(ss1, temp1, ' ')) {
					stringstream ss2(temp1);
					string temp2;

					while (getline(ss2, temp2, ','))
						instructions.push_back(temp2);					
				}
			}
		}

		for (vector<string>::const_iterator it = instructions.begin();
			it != instructions.end(); ++it) {
			stringstream instss(*it);
			string temp3;
			while (getline(instss, temp3, '-'))
				instnums.push_back(stoi(temp3));
		}

		int tempnum;

		for (vector<int>::size_type i = 0; i < instnums.size(); i += 2) {
			tempnum = nums[instnums[i]];
			nums[instnums[i]] = nums[instnums[i + 1]];
			nums[instnums[i + 1]] = tempnum;

		}

		for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
			cout << *it << " ";
		}
		
		cout << endl;
	
		nums.clear();
		instructions.clear();
		instnums.clear();
	}

	return 0;
}