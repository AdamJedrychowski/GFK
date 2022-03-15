#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
 sf::RenderWindow window(sf::VideoMode(800, 600), "GFK",sf::Style::Titlebar | sf::Style::Close);
 sf::Event event;

 sf::VertexArray line(sf::LinesStrip, 2);
 sf::VertexArray point(sf::Points, 1);
 sf::RectangleShape rectangle;
 sf::CircleShape circle;

 window.setFramerateLimit(60);

 while (window.isOpen())
  {
   while (window.pollEvent(event)) if (event.type == sf::Event::Closed) window.close();
   
   window.clear(sf::Color::White);
   //odcinek
   line[0].position = sf::Vector2f(0.0f,0.0f);     line[0].color = sf::Color(255, 0, 0);
   line[1].position = sf::Vector2f(799.0f, 599.0f); line[1].color = sf::Color(0, 255, 0);
   window.draw(line);
   //prostok¹t
   rectangle.setSize(sf::Vector2f(200.0f,100.0f));
   rectangle.setFillColor(sf::Color(128,128,128));
   rectangle.setOutlineColor(sf::Color::Black);
   rectangle.setOutlineThickness(1.0f);
   rectangle.setPosition(sf::Vector2f(160.0f, 10.0f));
   window.draw(rectangle);
   //okr¹g
   circle.setRadius(20.0f);
   circle.setFillColor(sf::Color::Transparent);
   circle.setOutlineColor(sf::Color::Red);
   circle.setOutlineThickness(5.0f);
   circle.setPosition(sf::Vector2f(10.0f, 160.0f));
   window.draw(circle);
   //punkt(!!!)
   point[0].position = sf::Vector2f(30.0f, 180.0f); point[0].color = sf::Color(0, 0, 0);
   window.draw(point);

   window.display();
  }
 return 0;
}