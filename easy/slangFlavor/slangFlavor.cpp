// https://www.codeeval.com/open_challenges/174/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	vector<string> phrases;
	phrases.push_back(", yeah!");
	phrases.push_back(", this is crazy, I tell ya.");
	phrases.push_back(", can U believe this\?");
	phrases.push_back(", eh\?");
	phrases.push_back(", aw yea.");
	phrases.push_back(", yo.");
	phrases.push_back("\? No way!");
	phrases.push_back(". Awesome!");

	ifstream file(argv[1]);
	string line;

	int punctCounter = 0;
	int phraseCounter = 0;

	while (getline(file, line)) {
		string::size_type start = 0, end;

		while ((end = line.find_first_of(".!\?", start)) != string::npos) {
			if (end > start) {
				punctCounter++;

				if (punctCounter % 2 == 0) {
					line.replace(end, 1, phrases[phraseCounter]);
					phraseCounter++;
				}
			}
			
			start = end + 1 + (punctCounter % 2 == 0 ? phrases[phraseCounter - 1].length() : 0);

			if (phraseCounter > 7)
				phraseCounter = 0;
		}

		if (start < line.length()) {
			punctCounter++;

			if (punctCounter % 2 == 0) {
				line.replace(end - 1, 1, phrases[phraseCounter]);
				phraseCounter++;
			}
		}

		cout << line << endl;

		if (phraseCounter > 7)
			phraseCounter = 0;
	}

	return 0;
}