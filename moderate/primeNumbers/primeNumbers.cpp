#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isPrime(int n)
{

	for (int i = 2; i < n; ++i) {
		if (n % i == 0 && i != n)
			return false;
	}

	return true;
}

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        unsigned int n = stoi(line);

        vector<unsigned int> primes;

        for (unsigned int i = 2; i < n; ++i) {
        	if (isPrime(i))
        		primes.push_back(i);
        }

        for (vector<unsigned int>::size_type i = 0; i < primes.size(); ++i) {
        	if (i == primes.size() - 1)
        		cout << primes[i] << endl;
        	else
        		cout << primes[i] << ",";
        }
    }
    
    file.close();
    return 0;
}