// https://www.codeeval.com/open_challenges/102/
// Submitted October 14, 2016

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	std::ifstream file(argv[1]);
	std::string line;

	while (std::getline(file, line)) {
		std::vector<int> value_vec;
		std::string::size_type start_bracket = line.find('[');
		std::string::size_type end_bracket = line.find_last_of(']');
		std::string between_brackets;
		if (end_bracket != std::string::npos) {
			between_brackets = line.substr(start_bracket,
				end_bracket - start_bracket + 1);
		}

		std::string label = "\"label\": ", id = "\"id\": ";
		std::string::size_type label_start, label_end = 0;
		bool label_found = false;

		if (between_brackets.find(label, label_end) != std::string::npos) {
			label_found = true;
			while ((label_start
				= between_brackets.find(label, label_end))
					!= std::string::npos) {
				
				std::string::size_type nearest_opening_curly_brace
					= between_brackets.find_last_of('{', label_start);
				
				std::string::size_type nearest_closing_curly_brace
					= between_brackets.find('}', label_start);
				
				std::string between_curly_braces
					= between_brackets.substr(nearest_opening_curly_brace,
						nearest_closing_curly_brace
						- nearest_opening_curly_brace);

				std::string::size_type id_start
					= between_curly_braces.find(id);
				std::string::size_type num_start = id_start + id.length(),
					num_end = between_curly_braces.find('}', id_start);

				value_vec.push_back(std::stoi(
					between_curly_braces.substr(num_start,
						num_end - num_start)));

				label_end = label_start + label.length();
			}
		}

		int sum = 0;

		if (label_found) {
			for (int n : value_vec) {
				sum += n;
			}
		}

		std::cout << sum << '\n';
	}

	file.close();
	return 0;
}