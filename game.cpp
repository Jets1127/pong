#include "game.h"
#include <iostream>

void Game::reset(Ball &b, Paddle &p1, Paddle &p2)
{
	b.reset_ball_movement();
	b.set_position(250, 160);
	p1.setPos(50, 150);
	p2.setPos(450, 150);

}

void Game::check(Ball &b, Paddle &p1, Paddle &p2)
{
	if (b.get_ball().getPosition().x <= 0) {
		p2_point();
		this->reset(b, p1, p2);
		display_score();
		b.reverse_direction();
		sf::sleep(sf::seconds(2));
	}
	else if (b.get_ball().getPosition().x >= 500) {
		p1_point();
		this->reset(b, p1, p2);
		display_score();
		b.reverse_direction();
		sf::sleep(sf::seconds(2));
	}
	else {
	}
}


//return true if p1 has won, return fasle if p2 has won
bool Game::declare_winner()
{
	if (p1_score == 11){
		return true;
	}
	else if (p2_score == 11) {
		return true;
	}
	else {
		return false;
	}

}