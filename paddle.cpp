#include <iostream>
#include "paddle.h"

void Paddle::setPos(float x, float y)
{
	(*this).paddle.setPosition(x, y);
}

void Paddle::set_paddle_color(sf::Color &color)
{
	(*this).paddle.setFillColor(color);
}

void Paddle::move_p1()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->paddle.move(0.0, -.07);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->paddle.move(0.0, .07);
	}
}

void Paddle::move_p2()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->paddle.move(0.0, -.07);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		this->paddle.move(0.0, .07);
	}
}

void paddle_movement(Paddle &p1, Paddle &p2)
{
	p1.move_p1();
	p2.move_p2();
}