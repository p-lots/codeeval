// https://www.codeeval.com/open_challenges/139/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

static const std::map<std::string, int> month_lookup = {
	{"Jan", 1},
	{"Feb", 2},
	{"Mar", 3},
	{"Apr", 4},
	{"May", 5},
	{"Jun", 6},
	{"Jul", 7},
	{"Aug", 8},
	{"Sep", 9},
	{"Oct", 10},
	{"Nov", 11},
	{"Dec", 12}
};

typedef std::pair<int, int> month_year;
typedef std::pair<month_year, month_year> date_range;
typedef std::vector<date_range> date_range_vec;

void make_ranges(std::string line, date_range_vec &dates)
{
	std::string::size_type start = 0, end;
	std::string delim = "; ";
	while ((end = line.find(delim, start)) != std::string::npos) {
		std::string two_date_pairs = line.substr(start, end - start);

		std::string first_month = two_date_pairs.substr(0, 3);
		int first_year = std::stoi(two_date_pairs.substr(4, 4)) - 1990;
		month_year first_month_year =
			std::make_pair(month_lookup.at(first_month), first_year);

		std::string second_month = two_date_pairs.substr(9, 3);
		int second_year = std::stoi(two_date_pairs.substr(13, 4)) - 1990;
		month_year second_month_year =
			std::make_pair(month_lookup.at(second_month), second_year);

		date_range range = std::make_pair(first_month_year, second_month_year);

		dates.push_back(range);
		
		start = end + delim.length();
	}
	std::string::size_type last_start = line.find_last_of(';') + 2;
	std::string last = line.substr(last_start);

	std::string first_month = last.substr(0, 3);
	int first_year = std::stoi(last.substr(4, 4)) - 1990;
	month_year first_month_year =
		std::make_pair(month_lookup.at(first_month), first_year);

	std::string second_month = last.substr(9, 3);
	int second_year = std::stoi(last.substr(13, 4)) - 1990;
	month_year second_month_year =
		std::make_pair(month_lookup.at(second_month), second_year);

	date_range range = std::make_pair(first_month_year, second_month_year);

	dates.push_back(range);
}

bool date_range_sort(date_range lhs, date_range rhs)
{
	if (lhs.first.second == rhs.first.second) {
		return lhs.first.first < rhs.first.first;
	}
	else if (lhs.first.second < rhs.first.second) {
		return true;
	}
	return false;
}

month_year find_last_date(date_range_vec &vec)
{
	month_year last = std::make_pair(1, 0);
	for (auto it : vec) {
		if (it.second.second > last.second) {
			last.second = it.second.second;
			if (it.second.first > last.first) {
				last.first = it.second.first;
			}
		}
	}
	return last;
}

int main(int argc, char **argv)
{
	std::ifstream file(argv[1]);
	std::string line;

	while (std::getline(file, line)) {
		date_range_vec range_vec;
		make_ranges(line, range_vec);
		std::sort(range_vec.begin(), range_vec.end(), date_range_sort);
		
		month_year last = find_last_date(range_vec);

		std::vector<bool> months(last.second * 12 + last.first - 1, false);

		for (auto it : range_vec) {
			int start = it.first.second * 12 + it.first.first - 1;
			int end = it.second.second * 12 + it.second.first - 1;
			for (unsigned i = start; i <= end; i++) {
				months[i - 1] = true;
			}
		}

		int count = 0;

		for (unsigned i = 0; i < months.size(); i++) {
			if (months[i]) {
				count++;
			}
		}
		
		std::cout << static_cast<int>(std::floor(count / 12)) << '\n';		
	}

	file.close();
	return 0;
}