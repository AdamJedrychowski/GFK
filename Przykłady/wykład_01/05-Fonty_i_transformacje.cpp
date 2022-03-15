#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
 sf::RenderWindow window(sf::VideoMode(800, 600), "GFK",sf::Style::Titlebar | sf::Style::Close);
 sf::Event event;
 sf::Font font1,font2;
 sf::Text text;

 window.setFramerateLimit(60);

 font1.loadFromFile("youmurderer.ttf");
 font2.loadFromFile("garota_bonita.ttf");
 

 while (window.isOpen())
  {
   while (window.pollEvent(event)) if (event.type == sf::Event::Closed) window.close();
   
   window.clear(sf::Color::White);
   
   text.setFont(font1); 
   text.setCharacterSize(50); 
   text.setFillColor(sf::Color::Red);
   text.setPosition(50, 20);
   text.setString("Swiety Grall znajduje sie w Zamku AAaaa...");
   window.draw(text);

   text.setFont(font2);
   text.setCharacterSize(80);
   text.setFillColor(sf::Color::Black);
   text.setPosition(160, 130);
   text.setString("Font Garota Bonita");
   window.draw(text);

   text.setScale(0.8f, 0.5f);
   text.setRotation(45.0f);
   text.move(20.0f, 100.0f);
   window.draw(text);
   text.setScale(1.0f, 1.0f); text.setRotation(0.0f); text.move(0.0f, 0.0f);

   window.display();
  }
 return 0;
}