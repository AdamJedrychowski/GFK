#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GFK", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;
	sf::Texture texture, tex2;
	sf::Sprite sprite, spr2;
	float x, y, t = 0.0;

	window.setVerticalSyncEnabled(true);

	texture.loadFromFile("eye2.jpg");
	sprite.setTexture(texture);

	tex2.loadFromFile("transparent.png");
	spr2.setTexture(tex2);
	spr2.setPosition(300, 200);

	while (window.isOpen())
	{
		while (window.pollEvent(event)) if (event.type == sf::Event::Closed) window.close();

		window.clear(sf::Color::Black);

		x = 250.0f * sin(0.83f * t) + 250.0f;
		y = 150.0f * cos(0.33f * t) + 150.0f;
		t = t + 0.05f;
		sprite.setPosition(x, y);
		window.draw(sprite);

		spr2.setColor(sf::Color(127.5f * (1.0f + cos(0.25f * t)), 255.0f, 255.0f));
		window.draw(spr2);

		window.display();
	}
	return 0;
}