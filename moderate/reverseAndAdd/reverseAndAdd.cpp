#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string reverse(string);

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        int n = stoi(line);
        int r = stoi(reverse(line));
        int p, count = 0;

        bool palindrome = false;

       	while (!palindrome) {
       		p = n + r;
       		++count;
       		if (to_string(p).compare(reverse(to_string(p))) == 0)
       			palindrome = true;
       		n = p;
       		r = stoi(reverse(to_string(p)));
       		if (count > 100)
       			break;
       	}

       	cout << count << " " << p << endl;
       	
    }
    
    file.close();
    return 0;
}

string reverse(string n)
{
	string ret;

	for (int i = n.length() - 1; i >= 0; --i) 
		ret += n.substr(i, 1);
	
	return ret;
}