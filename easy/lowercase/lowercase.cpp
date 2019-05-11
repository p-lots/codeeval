// https://www.codeeval.com/open_challenges/20/
// Submitted December 26, 2015

#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	std::ifstream file(argv[1]);
	std::string line;

	while(getline(file, line)) {
		for (int i = 0; i < line.length(); ++i) {
			if ((line[i] > 64) && (line[i] < 97)) {
				printf("%c", line[i] + 32);
			}
			else 
				printf("%c", line[i]);
		}

		printf("\n");
	}

	return 0;
}