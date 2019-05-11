// https://www.codeeval.com/open_challenges/131/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		string::size_type pos = 0;
		string delimiter = " ";
		string num;

		while ((pos = line.find(delimiter)) != string::npos) {
			num = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
		}

		string pattern = line;
		string pleft, pright;
		string::size_type end;

		string plusdelim = "+";
		string minusdelim = "-";
		bool isAddition = false, isSubtraction = false;

		if (pattern.find(plusdelim) != string::npos) {
			isAddition = true;
			end = pattern.find(plusdelim);
			pleft = pattern.substr(0, end);
			pright = pattern.substr(end, string::npos);
		}
		else if (pattern.find(minusdelim) != string::npos) {
			isSubtraction = true;
			end = pattern.find(minusdelim);
			pleft = pattern.substr(0, end);
			pright = pattern.substr(end, string::npos);
		}

		string lhs, rhs;
		string::size_type i;

		for (i = 0; i < pleft.length(); ++i) 
			lhs += num[i];
		
		for (string::size_type j = 0; j < pright.length(); ++i, ++j)
			rhs += num[i];

		long long sumdiff = 0;

		if (isAddition) 
			sumdiff = stoll(lhs) + stoll(rhs);
		
		else if (isSubtraction) 
			sumdiff = stoll(lhs) - stoll(rhs);

		cout << sumdiff << endl;
		
	}
}