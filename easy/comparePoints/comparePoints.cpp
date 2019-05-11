// https://www.codeeval.com/open_challenges/192/
// Submitted December 26, 2015

#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string calcvec(vector<int> output)
{
	string ret;

	if (output[0] > output[2]) {
		if (output[1] > output[3])
			ret = "SW";
		else if (output[1] < output[3])
			ret = "NW";
		else
			ret = "W";
	}
	else if (output[0] < output[2]) {
		if (output[1] > output[3])
			ret = "NE";
		else if (output[1] < output[3])
			ret = "SE";
		else
			ret = "E";
	}
	else if (output[0] == output[2]) {
		if (output[1] > output[3])
			ret = "S";
		else if (output[1] < output[3])
			ret = "N";
		else
			ret = "here";
	}
	return ret;
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;
	
	while (getline(file, line)) {
		vector<int> nums;
		stringstream ss(line);
		string temp;
		
		while (getline(ss, temp, ' ')) 
			nums.push_back(stoi(temp));

		string res = calcvec(nums);

		cout << res << endl;

		nums.clear();
	}

	return 0;
}