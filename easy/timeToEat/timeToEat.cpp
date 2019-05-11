// https://www.codeeval.com/open_challenges/214/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

bool highest(int lhs, int rhs)
{
	if (lhs > rhs)
		return true;
	else
		return false;
}

string convert_to_timestamp(int seconds)
{
	int hours, mins, secs;
	hours = seconds / 3600;
	mins = (seconds - (hours * 3600)) / 60;
	secs = seconds - ((hours * 3600) + (mins * 60));

	stringstream ss;
	ss << setw(2) << setfill('0') << hours << ":";
	ss << setw(2) << setfill('0') << mins << ":";
	ss << setw(2) << setfill('0') << secs;

	string result;
	ss >> result;

	return result;
}

int convert_to_secs(string timestamp)
{
	stringstream ss(timestamp);
	string temp;
	int multiplier = 3600, result = 0;

	while (getline(ss, temp, ':') && multiplier >= 1) {
		result += (multiplier * stoi(temp));
		multiplier /= 60;
	}

	return result;
}

void sort_line(vector<string>& output)
{
	vector<int> seconds;

	for (vector<string>::const_iterator it = output.cbegin();
		it != output.cend(); ++it) 
		seconds.push_back(convert_to_secs(*it));
	
	sort(seconds.begin(), seconds.end(), highest);

	output.clear();

	for (vector<int>::const_iterator it = seconds.cbegin();
		it != seconds.cend(); ++it) 
		output.push_back(convert_to_timestamp(*it));	
}


void split_line(string line, vector<string>& output)
{
	stringstream ss(line);
	string temp;

	while (getline(ss, temp, ' '))
		output.push_back(temp);
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		vector<string> times;
		split_line(line, times);

		sort_line(times);

		for (vector<string>::const_iterator it = times.cbegin();
			it != times.cend(); ++it)
			cout << *it << " ";

		cout << endl;
	}

	return 0;
}