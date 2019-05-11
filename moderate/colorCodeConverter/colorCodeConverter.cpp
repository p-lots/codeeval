// https://www.codeeval.com/open_challenges/148/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

struct RGB {
	int r;
	int g;
	int b;
};

RGB parseCMYK(string);

RGB parseHSL(string);

RGB parseHSV(string);

RGB parseHex(string);

int h2d(string);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
    	RGB color;

        if (line[0] == '(') {
        	color = parseCMYK(line);
        }

        else if (line[0] == 'H') {
        	if (line[2] == 'L') {
        		color = parseHSL(line);
        	}

        	else {
        		color = parseHSV(line);
        	}
        }

        else if (line[0] == '#') {
        	color = parseHex(line);
        }

        cout << "RGB(" << color.r << "," << color.g << "," << color.b << ")\n";
    }
    
    file.close();
    return 0;
}

RGB parseCMYK(string line)
{
	RGB ret;
	double c, m, y, k;

	string delim = ",";
	string::size_type start, end = line.find(delim);

	c = stod(line.substr(1, end));

	start = end + 1;
	end = line.find(delim, start);
	m = stod(line.substr(start, end - start));

	start = end + 1;
	end = line.find(delim, start);
	y = stod(line.substr(start, end - start));

	start = end + 1;
	end = line.find(")");
	k = stod(line.substr(start, end - start));

	double dr = 255 * (1 - c) * (1 - k);
	double dg = 255 * (1 - m) * (1 - k);
	double db = 255 * (1 - y) * (1 - k);

	ret.r = dr + 0.5;
	ret.g = dg + 0.5;
	ret.b = db + 0.5;

	return ret;
}

RGB parseHSL(string line)
{
	RGB ret;
	double H;
	double S, L;
	double Rp, Gp, Bp;
	double C, X, m;

	string::size_type start = line.find("("), end = line.find(",");
	H = stod(line.substr(start + 1, end - start));
	
	start = end + 1;
	end = line.find(",", start);
	S = stod(line.substr(start, end - start)) / 100;

	start = end + 1;
	end = line.find(")", start);
	L = stod(line.substr(start, end - start)) / 100;

	C = (1.0 - fabs((2.0 * L) - 1.0)) * S;

	X = C * (1.0 - fabs(fmod((H / 60.0), 2) - 1));

	m = L - (C / 2.0);

	if (H < 60) {
		Rp = C;
		Gp = X;
		Bp = 0;
	}

	else if (H > 59 && H < 120) {
		Rp = X;
		Gp = C;
		Bp = 0;
	}

	else if (H > 119 && H < 180) {
		Rp = 0;
		Gp = C;
		Bp = X;
	}

	else if (H > 179 && H < 240) {
		Rp = 0;
		Gp = X;
		Bp = C;
	}

	else if (H > 239 && H < 300) {
		Rp = X;
		Gp = 0;
		Bp = C;
	}

	else if (H > 299) {
		Rp = C;
		Gp = 0;
		Bp = X;
	}

	double rr = (Rp + m) * 255;
	double gg = (Gp + m) * 255;
	double bb = (Bp + m) * 255;

	ret.r = rr + 0.5;
	ret.g = gg + 0.5;
	ret.b = bb + 0.5;

	return ret;
}

RGB parseHSV(string line)
{
	RGB ret;

	double H;
	double S, V;
	double Rp, Gp, Bp;
	double C, X, m;

	string::size_type start = line.find("("), end = line.find(",");
	H = stod(line.substr(start + 1, end - start));
	
	start = end + 1;
	end = line.find(",", start);
	S = stod(line.substr(start, end - start)) / 100;
	
	start = end + 1;
	end = line.find(")", start);
	V = stod(line.substr(start, end - start)) / 100;

	C = V * S;

	X = C * (1.0 - fabs(fmod((H / 60.0), 2) - 1));

	m = V - C;

	if (H < 60) {
		Rp = C;
		Gp = X;
		Bp = 0;
	}

	else if (H > 59 && H < 120) {
		Rp = X;
		Gp = C;
		Bp = 0;
	}

	else if (H > 119 && H < 180) {
		Rp = 0;
		Gp = C;
		Bp = X;
	}

	else if (H > 179 && H < 240) {
		Rp = 0;
		Gp = X;
		Bp = C;
	}

	else if (H > 239 && H < 300) {
		Rp = X;
		Gp = 0;
		Bp = C;
	}

	else if (H > 299) {
		Rp = C;
		Gp = 0;
		Bp = X;
	}

	double rr = (Rp + m) * 255;
	double gg = (Gp + m) * 255;
	double bb = (Bp + m) * 255;

	ret.r = rr + 0.5;
	ret.g = gg + 0.5;
	ret.b = bb + 0.5;

	return ret;
}

RGB parseHex(string line)
{
	RGB ret;

	string R = line.substr(1, 2);
	string G = line.substr(3, 2);
	string B = line.substr(5);

	ret.r = h2d(R);
	ret.g = h2d(G);
	ret.b = h2d(B);

	return ret;
}

int h2d(string hex)
{
	int ret = 0;

	if (hex[0] > 96) {
		ret += ((hex[0] - 'W') * 16);
	}

	else {
		ret += (hex[0] - '0');
	}

	if (hex[1] > 96) {
		ret += (hex[1] - 'W');
	}

	else {
		ret += (hex[1] - '0');
	}

	return ret;
}