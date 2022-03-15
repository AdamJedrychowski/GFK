#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
 sf::RenderWindow window(sf::VideoMode(800, 600), "GFK",sf::Style::Titlebar | sf::Style::Close);
 sf::Event event;

 while (window.isOpen())
  {
   window.clear(sf::Color::White);
   
   while (window.pollEvent(event))
    {
     if (event.type == sf::Event::Closed) window.close();
    }
  
   window.display();
  }
 return 0;
}