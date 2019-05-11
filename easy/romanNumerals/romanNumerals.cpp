// https://www.codeeval.com/open_challenges/106/

#include <string>
#include <stdio.h>
using namespace std;
string toRomNum(int n, string one, 
				string five, string next)
{
	string ret;
	if (n < 4) {
		for (int i = 0; i < n; ++i)
			ret.append(one);
	}
	else if (n == 4) {
		ret.append(one);
		ret.append(five);
	}
	else if (n == 5)
		ret.append(five);
	else if (n == 9) {
		ret.append(one);
		ret.append(next);
	}
	else {
		ret = five;
		for (int i = 5; i < n; ++i)
			ret.append(one);
	}
	return ret;
}

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	int thD, hD, tD, oD, n;
	string th, h, t, o, ret;
	while(fscanf(file, " %d ", &n) == 1) {
		thD = n / 1000;
		hD = (n / 100) % 10;
		tD = (n % 100) / 10;
		oD = (n % 100) % 10;
		if (thD > 0) {
			for (int i = 0; i < thD; ++i)
				th.append("M");
		}
		h = toRomNum(hD, "C", "D", "M");
		t = toRomNum(tD, "X", "L", "C");
		o = toRomNum(oD, "I", "V", "X");
		ret.append(th);
		ret.append(h);
		ret.append(t);
		ret.append(o);
		printf("%s\n", ret.c_str());
		ret.clear();
		th.clear();
		h.clear();
		t.clear();
		o.clear();
	}
	return 0;
}