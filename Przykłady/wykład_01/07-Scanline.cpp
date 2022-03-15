#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
 sf::RenderWindow window(sf::VideoMode(800, 600), "GFK",sf::Style::Titlebar | sf::Style::Close);
 sf::Event event;
 sf::Uint8 *pixels = new sf::Uint8[500 * 250 * 4];
 sf::Texture texture;
 sf::Sprite sprite;

 window.setVerticalSyncEnabled(true);

 //czy kolejnosc tych petli ma znaczenie?
 for (unsigned int x = 0; x<500; x++)
  for (unsigned int y = 0; y < 250; y++)
  {
   pixels[4 * (y * 500 + x) + 0] = x/2;
   pixels[4 * (y * 500 + x) + 1] = y;
   pixels[4 * (y * 500 + x) + 2] = (x+y)/3;
   pixels[4 * (y * 500 + x) + 3] = 255;
  }

 texture.create(500,250);
 texture.update(pixels);
 sprite.setTexture(texture);
 sprite.setPosition(150,175);

 while (window.isOpen())
  {
   while (window.pollEvent(event)) if (event.type == sf::Event::Closed) window.close();
   
   window.clear(sf::Color::Black);

   window.draw(sprite);
 
   window.display();
  }
 return 0;
}