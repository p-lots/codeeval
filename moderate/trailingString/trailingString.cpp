#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    string line;
    
    while (getline(file, line)) {
        string::size_type end = line.find(",");
        string comp = line.substr(0, end);
        string test = line.substr(end + 1);

        string::size_type j = comp.size();

        bool isSame = false;

        for (int i = test.size(); i >= 0; --i) {
        	if (test[i] == comp[j])
        		isSame = true;

        	else {
        		isSame = false;
        		break;
        	}
        	
        	--j;
        }

        if (isSame)
        	cout << "1" << endl;
        else
        	cout << "0" << endl;
    }
    
    file.close();
    return 0;
}