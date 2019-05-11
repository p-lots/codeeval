// https://www.codeeval.com/open_challenges/166/
// Submitted November 26, 2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

void split_line(string line, string& left, string& right)
{
	stringstream ss(line);
	string temp;
	bool firstTime = true;
	while (getline(ss, temp, ' ')) {
			if (firstTime) {
				firstTime = false;
				left = temp;
			}
			else
				right = temp;
		}
}

void get_times(string line, int& hours, int& mins, int& secs)
{
	stringstream ss(line);
	string temp;
	
	bool firstTime = true, secondTime = true;
	while (getline(ss, temp, ':')) {
		if (firstTime) {
			firstTime = false;
			hours = stoi(temp);
		}
		else if (secondTime) {
			secondTime = false;
			mins = stoi(temp);
		}
		else
			secs = stoi(temp);
	}

	/*
	string::size_type end, start;
	string delimiter = ":";

	end = line.find(delimiter);
	hours = stoi(line.substr(0, end));
	start = end + delimiter.length();

	end = line.find(delimiter, start);
	mins = stoi(line.substr(start, end));
	start = end + delimiter.length();

	secs = stoi(line.substr(start, string::npos));
	*/
}

string secs_to_timestamp(int diff)
{
	int hours = diff / 3600;
	int mins = (diff - (hours * 3600)) / 60;
	int secs = diff - ((hours * 3600) + (mins * 60));

	stringstream ss;
	ss << setfill('0') << setw(2) << hours;
	ss << ":" << setfill('0') << setw(2) << mins;
	ss << ":" << setfill('0') << setw(2) << secs;

	string ret;
	getline(ss, ret);

	return ret;
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		string leftTime, rightTime;
		split_line(line, leftTime, rightTime);
		
		int lHours, lMins, lSecs;
		int rHours, rMins, rSecs;
		get_times(leftTime, lHours, lMins, lSecs);
		get_times(rightTime, rHours, rMins, rSecs);

		int diff;

		int lSeconds = (lHours * 3600) + (lMins * 60) + lSecs;
		int rSeconds = (rHours * 3600) + (rMins * 60) + rSecs;
		diff = abs(lSeconds - rSeconds);

		string output = secs_to_timestamp(diff);

		cout << output << endl;
	}

	return 0;
}