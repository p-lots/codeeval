#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int parseArabic(char);

int parseRoman(char);

int getDec(string);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        int dec = getDec(line);

        cout << dec << "\n";
    }
    
    file.close();
    return 0;
}

int parseArabic(char a)
{
	return a - '0';
}

int parseRoman(char r)
{
	int s = r;

	switch (s) {
		case 77: // M
		return 1000;
		break;

		case 68: // D
		return 500;
		break;

		case 67: // C
		return 100;
		break;

		case 76: // L
		return 50;
		break;

		case 88: // X
		return 10;
		break;

		case 86: // V
		return 5;
		break;

		case 73: // I
		return 1;
		break;

		default:
		return 0;
	}
}

int getDec(string line)
{
	int ret;

	if (line.size() == 2) {
		ret = parseArabic(line[0]) * parseRoman(line[1]);
	}

	else if (line.size() == 4) {
		if (parseRoman(line[3]) > parseRoman(line[1])) {
			ret = -(parseArabic(line[0]) * parseRoman(line[1]))
			 + (parseArabic(line[2]) * parseRoman(line[3]));
		}

		else {
			ret = (parseArabic(line[0]) * parseRoman(line[1]))
			 + (parseArabic(line[2]) * parseRoman(line[3]));
		}
	}

	else if (line.size() > 5) {
		int total = parseArabic(line[0]) * parseRoman(line[1]);

		bool firstTime = true;

		for (string::size_type i = 2; i < line.size() - 1; i += 2) {

			if (firstTime) {
				if (parseRoman(line[i + 1]) > parseRoman(line[1])) {
					total = (parseArabic(line[i]) * parseRoman(line[i + 1])) - total;
				}

				else {
					total += (parseArabic(line[i]) * parseRoman(line[i + 1]));
				}

				firstTime = false;
			}

			else {
				if (parseRoman(line[i + 3]) > parseRoman(line[i + 1])) {
					total -= (parseArabic(line[i]) * parseRoman(line[i + 1]));
				}

				else {
					total += (parseArabic(line[i]) * parseRoman(line[i + 1]));
				}
			}
		}

		ret = total;
	}

	return ret;
}