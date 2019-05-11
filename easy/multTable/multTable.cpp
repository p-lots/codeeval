// https://www.codeeval.com/open_challenges/23/
// Submitted October 28, 2015

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	for (int i = 1; i <= 12; ++i) {
		printf("%d", i);
		for (int j = 2; j <= 12; ++j) {
			printf("%4d", i * j);
		}

		printf("\n");
	}
}