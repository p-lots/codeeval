#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

double distanceBetween(double, double, double, double);

void parseLine(string, double&, double&, double&, double&, double&);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        double centerX, centerY, r, pointX, pointY;

        parseLine(line, centerX, centerY, r, pointX, pointY);

        if (distanceBetween(centerX, centerY, pointX, pointY) < r) {
        	cout << "true\n";
        }

        else {
        	cout << "false\n";
        }
    }
    
    file.close();
    return 0;
}

double distanceBetween(double x1, double y1, double x2, double y2)
{
	if (x1 == x2) {
		return y2 - y1;
	}

	else if (y1 == y2) {
		return x2 - x1;
	}

	else {
		double ret = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		return ret;
	}
}

void parseLine(string line, double& cX, double& cY, double& r, double& pX, double& pY)
{
	string::size_type start = line.find("("), end = line.find(")");

	string cen = line.substr(start, end - start);
	cX = stod(cen.substr(1, cen.find(",")));
	start = cen.find(",") + 2;
	cY = stod(cen.substr(start));

	start = line.find("s: ") + 3;
	end = line.find(";", start);
	r = stod(line.substr(start, end - start));

	start = line.find("t: (") + 4;
	string p = line.substr(start);
	end = p.find(",");
	pX = stod(p.substr(0, end));
	start = end + 2;
	pY = stod(p.substr(start, p.find(")") - 1));
}