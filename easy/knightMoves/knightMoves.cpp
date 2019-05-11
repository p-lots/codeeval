// https://www.codeeval.com/open_challenges/180/
// Submited January 13, 2016

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> makeMoves(string);

bool isValidMove(string);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        vector<string> newMoves = makeMoves(line);

        sort(newMoves.begin(), newMoves.end());

        for (vector<string>::size_type i = 0; i < newMoves.size(); ++i) {
        	if (isValidMove(newMoves[i]))
        		cout << newMoves[i] << " ";

        	if (i == newMoves.size() - 1)
        		cout << endl;
        }
    }
    
    file.close();
    return 0;
}

vector<string> makeMoves(string line)
{
	vector<string> ret;
	string temp;

	temp.push_back(line[0] + 2);
	temp.push_back(line[1] + 1);
	ret.push_back(temp);
	temp.clear();

	temp.push_back(line[0] + 2);
	temp.push_back(line[1] - 1);
	ret.push_back(temp);
	temp.clear();

	temp.push_back(line[0] - 2);
	temp.push_back(line[1] + 1);
	ret.push_back(temp);
	temp.clear();

	temp.push_back(line[0] - 2);
	temp.push_back(line[1] - 1);
	ret.push_back(temp);
	temp.clear();

	temp.push_back(line[0] - 1);
	temp.push_back(line[1] - 2);
	ret.push_back(temp);
	temp.clear();

	temp.push_back(line[0] + 1);
	temp.push_back(line[1] - 2);
	ret.push_back(temp);
	temp.clear();

	temp.push_back(line[0] - 1);
	temp.push_back(line[1] + 2);
	ret.push_back(temp);
	temp.clear();

	temp.push_back(line[0] + 1);
	temp.push_back(line[1] + 2);
	ret.push_back(temp);
	temp.clear();

	return ret;
}

bool isValidMove(string move)
{
	if ((move[0] > 96) && (move[0] < 105) && (move[1] > 48) && (move[1] < 57))
		return true;
	else
		return false;
}