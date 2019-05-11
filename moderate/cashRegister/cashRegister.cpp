// https://www.codeeval.com/open_challenges/54/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void get_change(double pp, double ch, string& output)
{
	double diff = ch - pp;

	if (diff < 0.0) {
		output = "ERROR";
		return;
	}

	else if (diff == 0.0) {
		output = "ZERO";
		return;
	}

	vector<double> valArr;
	valArr.push_back(100.0);
	valArr.push_back(50.0);
	valArr.push_back(20.0);
	valArr.push_back(10.0);
	valArr.push_back(5.0);
	valArr.push_back(2.0);
	valArr.push_back(1.0);
	valArr.push_back(0.5);
	valArr.push_back(0.25);
	valArr.push_back(0.10);
	valArr.push_back(0.05);
	valArr.push_back(0.01);

	vector<string> words;
	words.push_back("ONE HUNDRED");
	words.push_back("FIFTY");
	words.push_back("TWENTY");
	words.push_back("TEN");
	words.push_back("FIVE");
	words.push_back("TWO");
	words.push_back("ONE");
	words.push_back("HALF DOLLAR");
	words.push_back("QUARTER");
	words.push_back("DIME");
	words.push_back("NICKEL");
	words.push_back("PENNY");

	int i = 0;

	while (diff > 0 && i < valArr.size()) {

		if (diff >= valArr[i]) {
			diff -= valArr[i];
			output += (words[i] + (diff > 0.01 ? "," : ""));
		}
		else 
			++i;
	}	
}

void split_line(string line, double& pp, double& ch) 
{
	string::size_type end = line.find(";");
	pp = stod(line.substr(0, end));
	ch = stod(line.substr(end + 1));

}

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        double pp, ch;
        split_line(line, pp, ch);

        string output;
        get_change(pp, ch, output);

        cout << output << endl;
    }
    
    file.close();
    return 0;
}