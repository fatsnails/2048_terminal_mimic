#include"board.h"
#include<iomanip>
using std::setw;
board::board() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			num[i][j] = 0;
		}
	}
	srand(time(NULL));
	int col, line;
	int j = col = rand() % 4;
	int i = line = rand() % 4;
	num[line][col] = 2;
	line = rand() % 4;
	col = rand() % 4;
	while (line == i && col == j) {
		line = rand() % 4;
		col = rand() % 4;
	}
	num[line][col] = 2;
	score = 0;
}
void board::output()const {
	for (int i = 0; i < 4; i++) {
		std::cout << "|-----|-----|-----|-----|" << std::endl;
		for (int j = 0; j < 4; j++) {
			std::cout << "| ";
			if (num[i][j]) {
				std::cout << std::left << setw(3) << num[i][j] << " ";
			}
			else {
				std::cout << "    ";
			}
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "|-----|-----|-----|-----|" << std::endl;
	std::cout << "Your score: " << score << std::endl;
}
int board::count_empty()const {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (num[i][j] == 0) {
				count++;
			}
		}
	}
	return count;
}
void board::random_plant() {
	int x = rand() % 5;
	int y;
	if (x < 4) {
		y = 2;
	}
	else {
		y = 4;
	}
	int n = count_empty();
	int m = rand() % n + 1;
	int t = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (num[i][j] == 0) {
				t++;
			}
			if (t == m) {
				num[i][j] = y;
				break;
			}
		}
		if (t == m) {
			break;
		}
	}
}
void board::move(char c) {
	int n;
	int n_[4];
	int j, p, i;
	if (c == 'u') {
		for (j = 0; j < 4; j++) {
			for (p = 0; p < 4; p++) {
				n_[p] = 0;
			}
			p = 0;
			for (i = 0; i < 4; i++) {
				if (num[i][j] != 0) {
					n_[p] = num[i][j];
					p++;
				}
			}
			for (i = 0; i < 4; i++) {
				num[i][j] = n_[i];
			}
		}
	}
	else if (c == 'd') {
		for (j = 0; j < 4; j++) {
			for (p = 0; p < 4; p++) {
				n_[p] = 0;
			}
			p = 3;
			for (i = 3; i >= 0; i--) {
				if (num[i][j] != 0) {
					n_[p] = num[i][j];
					p--;
				}
			}
			for (i = 0; i < 4; i++) {
				num[i][j] = n_[i];
			}
		}
	}
	else if (c == 'l') {
		for (i = 0; i < 4; i++) {
			for (p = 0; p < 4; p++) {
				n_[p] = 0;
			}
			p = 0;
			for (j = 0;j < 4;j++) {
				if (num[i][j] != 0) {
					n_[p] = num[i][j];
					p++;
				}
			}
			for (j = 0; j < 4; j++) {
				num[i][j] = n_[j];
			}
		}
	}
	else if (c == 'r') {
		for (i = 0; i < 4; i++) {
			for (p = 0; p < 4; p++) {
				n_[p] = 0;
			}
			p = 3;
			for (j = 3; j >= 0; j--) {
				if (num[i][j] != 0) {
					n_[p] = num[i][j];
					p--;
				}
			}
			for (j = 0; j < 4; j++) {
				num[i][j] = n_[j];
			}
		}
	}
	return;
}
int board::combine(char c) {
	int i, j;
	if (c == 'u') {
		for (j = 0; j < 4; j++) {
			for (i = 0; i < 3; i++) {
				if (num[i][j] == num[i + 1][j]) {
					num[i][j] *= 2;
					score += num[i][j];
					for (int t = i + 1; t < 3; t++) {
						num[t][j] = num[t + 1][j];
					}
					num[3][j] = 0;
				}
			}
		}
	}
	else if (c == 'd') {
		for (j = 0; j < 4; j++) {
			for (i = 3; i > 0; i--) {
				if (num[i][j] == num[i - 1][j]) {
					num[i][j] *= 2;
					score += num[i][j];
					for (int t = i - 1; t >= 1; t--) {
						num[t][j] = num[t - 1][j];
					}
					num[0][j] = 0;
				}
			}
		}
	}
	else if (c == 'l') {
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 3; j++) {
				if (num[i][j] == num[i][j + 1]) {
					num[i][j] *= 2;
					score += num[i][j];
					for (int t = j + 1; t < 3; t++) {
						num[i][t] = num[i][t + 1];
					}
					num[i][3] = 0;
				}
			}
		}
	}
	else if (c == 'r') {
		for (i = 0; i < 4; i++) {
			for (j = 3; j > 0; j--) {
				if (num[i][j] == num[i][j - 1]) {
					num[i][j] *= 2;
					score += num[i][j];
					for (int t = j - 1; t >= 1; t--) {
						num[i][t] = num[i][t - 1];
					}
					num[i][0] = 0;
				}
			}
		}
	}
	return score;
}
bool board::isFull() const {
	if (count_empty() == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool board::isAvail() const {
	int t = 0;
	int i, j;
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 3; i++) {
			if (num[i][j] == num[i + 1][j]) {
				return true;
			}
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			if (num[i][j] == num[i][j + 1]) {
				return true;
			}
		}
	}
	return false;
}