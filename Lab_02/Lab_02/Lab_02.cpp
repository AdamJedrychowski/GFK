#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 02", sf::Style::Titlebar | sf::Style::Close);
    sf::Clock clock;
    sf::Time time = sf::Time::Zero;
    unsigned int FPS = 0, frame_counter = 0;

    //inicjalizacja 
    clock.restart().asMilliseconds();
    while (window.isOpen())
    {
        sf::Event event;
        window.clear(sf::Color::White);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        //tu wyrysowaæ wszystko na ekran

        //tu wypisaæ na ekran wartoœæ FPS
        if (clock.getElapsedTime().asSeconds() >= 1.0f)
        {
            FPS = (unsigned int)((float)frame_counter / clock.getElapsedTime().asSeconds());
            clock.restart();
            frame_counter = 0;
        }
        frame_counter++;

        window.display();
    }
}