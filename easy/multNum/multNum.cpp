// https://www.codeeval.com/open_challenges/18/
// Submitted December 26, 2015

#include <cstdio>

using namespace std;

int main(int argc, char* argv[])
{
	FILE *file = fopen(argv[1], "r");

	int x, n;

	while(fscanf(file, "%d,%d", &x, &n) == 2) {
		while (x > n) 
			n *= 2;
		
		printf("%d\n", n);
	}

	fclose(file);

	return 0;
}