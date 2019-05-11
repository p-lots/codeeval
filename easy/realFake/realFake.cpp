// https://www.codeeval.com/open_challenges/227/
// Submitted December 21, 2015

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        vector<int> dubNums;
        vector<int> otherNums;
        vector<string> temp;

        string::size_type start = 0, end;

        while ((end = line.find(" ", start)) != string::npos) {
        	temp.push_back(line.substr(start, end - start));
        	start = end + 1;
        }

        temp.push_back(line.substr(start));

        for (vector<string>::size_type i = 0; i < temp.size(); ++i) {
        	dubNums.push_back(temp[i][0] - '0');
        	otherNums.push_back(temp[i][1] - '0');
        	dubNums.push_back(temp[i][2] - '0');
        	otherNums.push_back(temp[i][3] - '0');
        }

        int dubSum = 0;
        int otherSum = 0;

        for (vector<int>::size_type i = 0; i < dubNums.size(); ++i) {
        	dubSum += (dubNums[i] * 2);
        	otherSum += otherNums[i];
        }

        if ((dubSum + otherSum) % 10 == 0)
        	cout << "Real" << endl;
        else
        	cout << "Fake" << endl;
    }
    
    file.close();
    return 0;
}