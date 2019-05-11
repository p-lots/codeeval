// https://www.codeeval.com/open_challenges/19/
// Submitted October 10, 2016
// Given that the number that is to be tested is exactly six digits, 20 is
// adequate for the size of the std::bitset

#include <bitset>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void split_line(std::string line, std::vector<int> &nums)
{
	std::string::size_type start = 0, end;
	while (end != std::string::npos) {
		end = line.find(",", start);
		nums.push_back(std::stoi(line.substr(start, end - start)));
		start = end + 1;
	}
}

int main(int argc, char *argv[])
{
    std::ifstream file(argv[1]);
    std::string line;
    
    while (std::getline(file, line)) {
		std::vector<int> nums;
		split_line(line, nums);

    	std::bitset<20> n_bin(nums[0]);
    	int p1 = nums[1] - 1;
    	int p2 = nums[2] - 1;
    	
    	std::cout << (n_bin.test(p1) == n_bin.test(p2) ? "true" : "false");
    	std::cout << '\n';
    }
    
    file.close();
    return 0;
}