#include <iostream>
#include "paddle.h"
#include "ball.h"
#include "game.h"

void draw_p2score(Game &p, sf::RenderWindow &g);
void draw_p1score(Game &p, sf::RenderWindow &g);

int main()
{
	sf::Font font;

	Paddle p1(50.0, 150.0, sf::Color::Red);
	Paddle p2(450.0, 150.0, sf::Color::Green);
	Ball baller(sf::Color::Blue);
	Game pong;

	if (!font.loadFromFile("arial.ttf")) {
		std::cout << " " << std::endl;
	}

	sf::RenderWindow window(sf::VideoMode(500, 350), "Pong");

	bool started = false;
	bool p1_win = false, p2_win = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		hitter(baller, p1, p2);
		baller.mover();
		baller.boundaries();
		paddle_movement(p1, p2);
		pong.check(baller, p1, p2);

		window.clear();
		window.draw(p1.get_paddle());
		window.draw(p2.get_paddle());
		window.draw(baller.get_ball());
		window.draw(pong.get_divider());

		draw_p2score(pong, window);
		draw_p1score(pong, window);

		window.display();

		if (started == false) {
			baller.start_game();
			started = true;
		}

		if (started == true) {
			p2_win = pong.declare_winner();
			p1_win = pong.declare_winner();
			if (p1_win == true || p2_win == true)
				break;
		}
	}

	return 0;
}

void draw_p2score(Game &p, sf::RenderWindow &g)
{
	for (int i = 0; i < p.get_p2_score(); ++i) {

			g.draw(p.get_p2tally(i));
		
		
	}
}

void draw_p1score(Game &p, sf::RenderWindow &g)
{
	for (int i = 0; i < p.get_p1_score(); ++i) {

		g.draw(p.get_p1tally(i));


	}
}
