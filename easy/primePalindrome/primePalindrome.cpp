// https://www.codeeval.com/open_challenges/3/
// Submitted October 26, 2015 

#include <iostream>

bool isPrime(int);

int main(int argc, char* argv[])
{
	int n = 2, i = 2;

	int ret;

	while (i < 1000) {
		if (isPrime(n)) {
			if ((n / 100) == ((n % 100) % 10)) {
			ret = n;
			}
		}
		
		++n;
		++i;
	}

	std::cout << ret;
}

bool isPrime(int number)
{
	for (int i = 2; i < number; ++i) {
		if (number % i == 0 && i != number)
			return false;
	}

	return true;
}