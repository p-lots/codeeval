// https://www.codeeval.com/open_challenges/4/

#include <iostream>

bool isPrime(int);

int main(int argc, char* argv[])
{
	int acc = 0, n = 2, i = 0;

	while (i < 1000) {
		if (isPrime(n)) {
			acc += n;
			++i;
		}

		++n;
	}

	std::cout << acc << std::endl;
}

bool isPrime(int number)
{
	for (int i = 2; i < number; ++i) {
		if (number % i == 0 && i != number)
			return false;
	}

	return true;
}