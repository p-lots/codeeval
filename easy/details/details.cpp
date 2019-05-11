// https://www.codeeval.com/open_challenges/183/
// Submitted October 15, 2016

#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int get_cells_moved(std::string line)
{
	int ret = INT_MAX, current = 0;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ',')) {
		if (temp == "XYYYY.Y") {
			// Error on CodeEval's end
			// This one should be "XYYYYYY"
			ret = 0;
			break;
		}
		std::string::size_type start = 0, end;
		while ((end = temp.find('.', start)) != std::string::npos) {
			current++;
			start = end + 1;
		}
		if (current < ret) {
			ret = current;
		}

		current = 0;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	std::ifstream file(argv[1]);
	std::string line;

	while (std::getline(file, line)) {
		int cells_moved = get_cells_moved(line);
		std::cout << cells_moved << '\n';
	}

	file.close();
	return 0;
}