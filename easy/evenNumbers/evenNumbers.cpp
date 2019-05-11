// https://www.codeeval.com/open_challenges/100/
// Submitted November 3, 2015

#include <cstdio>

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");

	int n;

	while (fscanf(file, "%d ", &n) == 1) {
		printf("%d\n", n % 2 == 0 ? 1 : 0);
	}

	fclose(file);
	return 0;
}