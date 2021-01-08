#include "ball.h"
#include <random>
#include <iostream>
#include <time.h>
#include <stdlib.h>

void Ball::start_game()
{	
	int temp;

	std::default_random_engine nums(time(0));
	
	temp = nums() % 2;
	sf::sleep(sf::seconds(2));

	if (temp == 0) {
		set_movement(-.055, 0);
		
	}
	else {
		set_movement(.055, 0);
	}
}

void Ball::mover()
{
	dx = dx * speed;
	dy = dy * speed;

	(*this).balll.move(this->dx, this->dy);

}

void Ball::reset_ball_movement()
{
	this->reset_num_hits();
	this->reset_speed();
	if (dx > 0) {
		set_movement(.055, 0);
	}
	else {
		set_movement(-.055, 0);
	}
 
}


void Ball::set_movement(float x, float y)
{
	dx = x;
	dy = y;
}

void Ball::hit_detection(Paddle &player1)
{
	int temp = balll.getPosition().x;
	int temp2 = player1.get_paddle().getPosition().x;

	int paddle1_y = player1.get_paddle().getPosition().y;
	int paddle1_rel_center = paddle1_y + 20;

	int ball_y = balll.getPosition().y;

	if (temp == temp2) {

		if (ball_y >= paddle1_rel_center - 23 && ball_y <= paddle1_rel_center + 23) {
			dx *= -1;
			dy = determine_yangle(player1, paddle1_rel_center);
			++num_hits;
			ramp_up();
			std::cout << "Num hits: " << num_hits << std::endl; 
		}
		
	}
}

float Ball::determine_yangle(Paddle &player, int paddle_relative_center)
{
	float angle; 

	int temp = balll.getPosition().y;
	if (temp == paddle_relative_center) {
		angle = 0.0;
		return angle;
	}
	else if (temp != paddle_relative_center) {

		float determinate = temp - paddle_relative_center;
		angle = determinate / 308;
		return angle;

	}
	else
		std::cout << "JANK!" << std::endl; 
	
}

void Ball::boundaries()
{

	int temp = balll.getPosition().y;

	if (temp == 0 || temp == 350) {
		dy = dy * -1;
	}
}

void Ball::ramp_up()
{
	int temp = get_numhits();
	if (temp % 5 == 0) {
		speed += .00001;
	}
}

void hitter(Ball &balls, Paddle &p1, Paddle &p2)
{
	balls.hit_detection(p1);
	balls.hit_detection(p2);
}

