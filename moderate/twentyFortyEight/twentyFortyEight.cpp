#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef std::vector<std::vector<int> > board_vec;

std::vector<std::string> tokenize(std::string, char);

void slide_left(board_vec &, int, int);

void move_left(board_vec &, int);

void slide_right(board_vec &, int, int);

void move_right(board_vec &, int);

void slide_up(board_vec &, int, int);

void move_up(board_vec &, int);

void slide_down(board_vec &, int, int);

void move_down(board_vec &, int);

void do_move(std::string, board_vec &, int);

board_vec board_vec_tokenize(std::string);

void print_board(board_vec);

int main(int argc, char *argv[])
{
	std::string line;
	std::ifstream file(argv[1]);

	while (std::getline(file, line)) {
		std::vector<std::string> move_n_board = tokenize(line, ';');
		
		std::string move = move_n_board[0];
		int n = std::stoi(move_n_board[1].substr(1));
		board_vec board = board_vec_tokenize(move_n_board[2].substr(1));

		do_move(move, board, n);

		print_board(board);
	}

	return 0;
}

board_vec board_vec_tokenize(std::string line)
{
	board_vec ret;
	std::vector<std::string> step1 = tokenize(line, '|');
	for (std::string row : step1) {
		std::vector<int> temp;
		std::vector<std::string> step2 = tokenize(row, ' ');
		for (std::string num : step2) {
			temp.push_back(std::stoi(num));
		}
		ret.push_back(temp);
	}
	return ret;
}

std::vector<std::string> tokenize(std::string line, char delim)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, delim)) {
		ret.push_back(temp);
	}
	return ret;
}

void slide_left(board_vec &board, int i, int n)
{
	for (int j = 1; j < n; j++) {
		for (int k = j; k > 0; k--) {
			if (board[i][k - 1] == 0) {
				std::swap(board[i][k - 1], board[i][k]);
			}
		}
	}
}

void move_left(board_vec &board, int n)
{
	for (int i = 0; i < n; i++) {
		slide_left(board, i, n);
		for (int j = 1; j < n; j++) {
			if (board[i][j] == board[i][j - 1]) {
				board[i][j] = 0;
				board[i][j - 1] *= 2;
			}
		}
		slide_left(board, i, n);
	}
}

void slide_right(board_vec &board, int i, int n)
{
	for (int j = n - 2; j > -1; j--) {
		for (int k = j; k < n - 1; k++) {
			if (board[i][k + 1] == 0) {
				std::swap(board[i][k], board[i][k + 1]);
			}
		}
	}
}

void move_right(board_vec &board, int n)
{
	for (int i = 0; i < n; i++) {
		slide_right(board, i, n);
		for (int j = n - 2; j > -1; j--) {
			if (board[i][j] == board[i][j + 1]) {
				board[i][j] = 0;
				board[i][j + 1] *= 2;
			}
		}
		slide_right(board, i, n);
	}
}

void slide_up(board_vec &board, int j, int n)
{
	for (int i = 1; i < n; i++) {
		for (int k = i; k > 0; k--) {
			if (board[k - 1][j] == 0) {
				std::swap(board[k][j], board[k - 1][j]);
			}
		}
	}
}

void move_up(board_vec &board, int n)
{
	for (int j = 0; j < n; j++) {
		slide_up(board, j, n);
		for (int i = 1; i < n; i++) {
			if (board[i][j] == board[i - 1][j]) {
				board[i][j] = 0;
				board[i - 1][j] *= 2;
			}
		}
		slide_up(board, j, n);
	}
}

void slide_down(board_vec &board, int j, int n)
{
	for (int i = n - 2; i > -1; i--) {
		for (int k = i; k < n - 1; k++) {
			if (board[k + 1][j] == 0) {
				std::swap(board[k][j], board[k + 1][j]);
			}
		}
	}
}

void move_down(board_vec &board, int n)
{
	for (int j = 0; j < n; j++) {
		slide_down(board, j, n);
		for (int i = n - 2; i > -1; i--) {
			if (board[i][j] == board[i + 1][j]) {
				board[i][j] = 0;
				board[i + 1][j] *= 2;
			}
		}
		slide_down(board, j, n);
	}
}

void do_move(std::string move, board_vec &board, int n)
{
	if (move == "LEFT") {
		move_left(board, n);
	}
	if (move == "UP") {
		move_up(board, n);
	}
	if (move == "RIGHT") {
		move_right(board, n);
	}
	if (move == "DOWN") {
		move_down(board, n);
	}
}

void print_board(board_vec board)
{
	for (auto it = board.begin(); it != board.end(); it++) {
		for (auto it2 = it->begin(); it2 != it->end(); it2++) {
			std::cout << *it2;
			if (it2 != it->end() - 1) {
				std::cout << ' ';
			}
		}
		if (it != board.end() - 1) {
			std::cout << '|';
		}
	}

	std::cout << '\n';
}