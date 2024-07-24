#ifndef GUARD_Game2048_h
#define GUARD_Game2048_h
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include"board.h"
class Game2048 {
public:
	Game2048();
	~Game2048();
	char ask_move(std::istream&);
	int get_score()const;
	void process(char);
	void plant();
	void out()const;
	bool judge()const;
	void end_(time_t);
	std::ofstream& file_out(std::ofstream&);
	bool judge_full();
private:
	board num_;
	time_t begin;
	time_t end;
};
#endif
