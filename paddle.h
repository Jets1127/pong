#ifndef PADDLE_H
#define PADDLE_H


#include <SFML/Graphics.hpp>

class Paddle {

	friend class sf::RectangleShape;
	friend void paddle_movement(Paddle &p1, Paddle &p2);

public:
	Paddle() : paddle(sf::Vector2f(12.0, 110.0)) {};
	Paddle(float x, float y, sf::Color choice) : paddle(sf::Vector2f(12.0, 40)) 
	{
		(*this).setPos(x, y);
		(*this).set_paddle_color(choice);

	}
	void setPos(float x, float y);
	void set_paddle_color(sf::Color &);
	sf::RectangleShape get_paddle() { return paddle;}
	void move_p1();
	void move_p2();
	

private:
	sf::RectangleShape paddle; 

};

void paddle_movement(Paddle &p1, Paddle &p2);

#endif 