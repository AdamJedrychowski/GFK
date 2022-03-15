#include <iostream>
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
     if (event.type == sf::Event::KeyPressed) 
     {
      std::cout << event.key.code << std::endl;
      if (event.key.code == sf::Keyboard::F) std::cout<< "Nacisnieto klawisz F!" << std::endl;
     }
    }
   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
   {
    std::cout << "<-----" << std::endl;
   }
 
   window.display();
  }
 return 0;
}