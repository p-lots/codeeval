// https://www.codeeval.com/open_challenges/62/
// Submitted December 31, 2015

#include <stdio.h>

int mod(int n, int m)
{
	if (n == m)
		return 0;
	else if (n > m) {
		while (n > m)
			n -= m;
		return n;
	}
	else {
		return n;
	}
}

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	int n, m, o;
	while(fscanf(file, "%d,%d\n", &n, &m) == 2) {
		o = mod(n, m);
		printf("%d\n", o);
	}
	fclose(file);
	return 0;
}