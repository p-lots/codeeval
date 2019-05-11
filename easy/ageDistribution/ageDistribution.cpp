// https://www.codeeval.com/open_challenges/152/
// submitted November 23, 2015

#include <fstream>
#include <iostream>
#include <string>

std::string ageEval(int);

int main(int argc, char *argv[])
{
	std::ifstream file(argv[1]);
	std::string line;

	while (std::getline(file, line)) {
		std::string demographic = ageEval(std::stoi(line));
		std::cout << demographic << '\n';
	}
}

std::string ageEval(int age)
{
	if (age >= 0 && age <= 2)
		return "Still in Mama's arms";
	else if (age == 3 || age == 4)
		return "Preschool Maniac";
	else if (age > 4 && age <= 11)
		return "Elementary school";
	else if (age >= 12 && age <= 14)
		return "Middle school";
	else if (age >= 15 && age <= 18)
		return "High school";
	else if (age >= 19 && age <= 22)
		return "College";
	else if (age >= 23 && age <= 65)
		return "Working for the man";
	else if (age > 65 && age <= 100)
		return "The Golden Years";
	else
		return "This program is for humans";
}
