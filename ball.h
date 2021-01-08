#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "paddle.h"

class Ball {


	friend void hitter(Ball &balls, Paddle &p1, Paddle &p2);

public:
	Ball(sf::Color x) : balll(5, 10), dx(0), dy(0), speed(1), num_hits(0)
	{
		(*this).balll.setFillColor(x);
		(*this).balll.setPosition(250, 160);
	}

	sf::CircleShape get_ball() { return balll; }
	void start_game();
	void mover();
	void set_movement(float x, float y);
	void hit_detection(Paddle &player1);
	float determine_yangle(Paddle &player, int paddle_relative_center);
	void boundaries();
	void reverse_direction() { dx *= -1; }
	void set_position(float x, float y) { this->balll.setPosition(x, y); }
	void adjust_y(float y) { dy = y; }
	void reset_num_hits() { num_hits = 0; }
	void ramp_up();
	float get_numhits() { return num_hits; }
	void reset_speed() { speed = 1; }
	void reset_ball_movement();
	

private:
	sf::CircleShape balll;
	float dx;
	float dy;
	float speed;
	float num_hits;
};

void hitter(Ball &balls, Paddle &p1, Paddle &p2);

#endif 