#include <fstream>
#include"Game2048.h"
#include"board.h"
using std::cout;
using std::cin;
using std::ofstream;
int main() {
	Game2048 x;
	std::cout << "Welcome to the game of 2048" << std::endl;
	x.out();
	while (!x.judge()) {
		char c = x.ask_move(cin);
		if (c == 'q') {
			break;
		}
		x.process(c);
		if (!x.judge_full()) {
			x.plant();
		}
		x.out();
	}
	cout << "Game Over";
	x.end_(time(NULL));
	ofstream file("game2048.csv", ofstream::app);
	x.file_out(file);
	return 0;
}