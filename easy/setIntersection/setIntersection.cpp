// https://www.codeeval.com/open_challenges/30/

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void split_line(string line, vector<int>& output1, vector<int>& output2)
{
	stringstream ss(line);
	string temp;
	bool firstTime = true;

	while (getline(ss, temp, ';')) {
		stringstream s(temp);
		string t;
		if (firstTime) {
			while (getline(s, t, ',')) {
				output1.push_back(stoi(t));
			}
			firstTime = false;
		}
		else {
			while (getline(s, t, ',')) 
				output2.push_back(stoi(t));
		}
	}
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		vector<int> nums1, nums2;
		split_line(line, nums1, nums2);
		vector<int> result;

		for (vector<int>::iterator it = nums1.begin();
			it != nums1.end(); ++it) {
			for (vector<int>::iterator jt = nums2.begin();
				jt != nums2.end(); ++jt) {
				if (*it == *jt)
					result.push_back(*it);
			}
		}

		if (!result.empty()) {
			for (vector<int>::iterator it = result.begin();
				it != result.end(); ++it)
				cout << *it << (it == result.end() - 1 ? '\n' : ',');
		}
		else
			cout << endl;
	}

	file.close();
	return 0;
}