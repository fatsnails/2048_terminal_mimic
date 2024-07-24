#ifndef GUARD_board_h
#define GUARD_board_h
#include<ctime>
#include<cstdlib>
#include<iostream>
class board {
public:
	board();
	void output()const;
	void random_plant();
	void move(char);
	int combine(char);
	int count_empty()const;
	bool isFull()const;
	bool isAvail()const;
	int read_score() const { return score; }
private:
	int num[4][4];
	int score;
};
#endif
