#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "ball.h"

class Game {

public:
	Game() : divider(sf::Vector2f(1, 350)), p1_score(0), p2_score(0), in_progress(false) 
	{
		divider.setFillColor(sf::Color::White);
		divider.setPosition(250, 0);

		int temp = 270, temp3 = 210;
		int p2_score_count = 0, p1_score_count = 0;

		for (auto &x : p2_tally) {
			x.setSize(sf::Vector2f(1, 17));
			x.setPosition(temp, 10);
			x.setFillColor(sf::Color::Blue);

			if (p2_score_count == 4 || p2_score_count == 9) {
				x.rotate(45);
				x.setPosition((temp + 2), 10);
				temp = temp + 5;
				++p2_score_count;
			}
			else {

				temp = temp + 2;
				++p2_score_count;
			}
			
		}

		for (auto &x : p1_tally) {
			x.setSize(sf::Vector2f(1, 17));
			x.setPosition(temp3, 10);
			x.setFillColor(sf::Color::Blue);

			if (p1_score_count == 4 || p1_score_count == 9) {
				x.rotate(45);
				x.setPosition((temp3 + 2), 10);
				temp3 = temp3 + 5;
				++p1_score_count;
			}
			else {

				temp3 = temp3 + 2;
				++p1_score_count;
			}

		}
	}
	void reset(Ball &balls, Paddle &p1, Paddle &p2);
	void check(Ball &balls, Paddle &p1, Paddle &p2);


	void display_score() { std::cout << p1_score << " - " << p2_score << std::endl; }
	void p1_point() { ++p1_score; }
	void p2_point() { ++p2_score; }
	sf::RectangleShape get_divider() const { return divider; }
	sf::RectangleShape get_p1tally(int a) { return p1_tally[a]; }
	sf::RectangleShape get_p2tally(int x) { return p2_tally[x]; }
	void rotate_tally(int b) { p2_tally[b].rotate(45); }
	int get_p2_score() { return p2_score; }
	int get_p1_score() { return p1_score; }

	bool declare_winner();

private:
	sf::RectangleShape p1_tally[11];
	sf::RectangleShape p2_tally[11];
	sf::RectangleShape divider;
	int p1_score;
	int p2_score; 
	bool in_progress;

};

#endif
