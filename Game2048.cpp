#define _CRT_SECURE_NO_WARNINGS
#include"Game2048.h"
#include"board.h"
using std::endl;
Game2048::Game2048(){
	begin = time(NULL);
	end = time(NULL);
}
Game2048::~Game2048() { }
char Game2048::ask_move(std::istream& in) {
	char c;
	while (1) {
		std::cout << "(¡ü:u) (¡ý:d) (¡û:l) (¡ú:r) (quit:q):";
		in >> c;
		if (c == 'u' || c == 'd' || c == 'l' || c == 'r' || c == 'q') {
			break;
		}
	}
	return c;
}
int Game2048::get_score() const {
	return num_.read_score();
}
void Game2048::process(char c) {
	num_.move(c);
	num_.combine(c);
}
void Game2048::plant() {
	num_.random_plant();
}
void Game2048::out()const {
	num_.output();
}
bool Game2048::judge()const {
	if (num_.isFull() && !num_.isAvail()) {
		return true;
	}
	else {
		return false;
	}
}
void Game2048::end_(time_t time) {
	end = time;
}
std::ofstream& Game2048::file_out(std::ofstream& file) {
	std::string cstr(std::ctime(&begin));
	cstr.erase(--cstr.end());
	file << cstr << "," << std::difftime(end, begin) << "," << get_score() << endl;
	return file;
}
bool Game2048::judge_full() {
	return num_.isFull();
}