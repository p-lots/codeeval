// https://www.codeeval.com/open_challenges/63/

#include <iostream>
#include <fstream>
#include <string>

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
        string::size_type end = line.find(",");
        int firstNum = stoi(line.substr(0, end));
        int secondNum = stoi(line.substr(end + 1));

        int count = 0;

        while (firstNum <= secondNum)
        	if (isPrime(firstNum++))
        		count++;

    	cout << count << endl;
    }
    
    file.close();
    return 0;
}