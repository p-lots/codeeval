// https://www.codeeval.com/open_challenges/87/
// Submitted March 23, 2016

#include <cstring>
#include <cstdio>

using namespace std;

class QueryClass
{
	int matrix[256][256];
public:
	QueryClass();
	void setRow(int, int);
	void setCol(int, int);
	int queryRow(int);
	int queryCol(int);
};

QueryClass::QueryClass()
{
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 256; ++j)
			matrix[i][j] = 0;
	}
}

void QueryClass::setRow(int row, int val)
{
	for (int i = 0; i < 256; ++i) 
		matrix[row][i] = val;
}

void QueryClass::setCol(int col, int val)
{
	for (int i = 0; i < 256; ++i)
		matrix[i][col] = val;
}

int QueryClass::queryRow(int row)
{
	int acc = 0;
	for (int i = 0; i < 256; ++i) 
		acc += matrix[row][i];
	return acc;
}

int QueryClass::queryCol(int col)
{
	int acc = 0;
	for (int i = 0; i < 256; ++i) 
		acc += matrix[i][col];
	return acc;
}

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");

	QueryClass qc;

	char *scan = new char[9];

	int rowcol, val, ret;

	while (fscanf(file, "%s %d\n", scan, &val) == 2 || fscanf(file, "%s %d %d\n", scan, &rowcol, &val) == 3) {
		if (strcmp(scan, "SetCol") == 0) 
			qc.setCol(rowcol, val);
		
		else if (strcmp(scan, "SetRow") == 0) 
			qc.setRow(rowcol, val);
		
		else if (strcmp(scan, "QueryRow") == 0) {
			ret = qc.queryRow(rowcol);
			printf("%d\n", ret);
		}

		else if (strcmp(scan, "QueryCol") == 0) {
			ret = qc.queryCol(rowcol);
			printf("%d\n", ret);
		}
	}

	delete[] scan;
	fclose(file);
	return 0;
}