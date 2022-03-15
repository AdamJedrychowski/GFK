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
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
     std::cout << "Nacisnieto LEWY klawisz myszy w punkcie: " << event.mouseButton.x << ", " << event.mouseButton.y << std::endl;
    }
    if (event.type == sf::Event::MouseMoved)
    {
    std::cout << "Ruch mysza - wspolrzedne kursora: " << event.mouseMove.x << ", " << event.mouseMove.x << std::endl;
    }
   }
   window.display();
  }
 return 0;
}