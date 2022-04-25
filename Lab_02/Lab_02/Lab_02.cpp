#include "Circle.h"
#include "font.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(750, 600), "GFK Lab 02", sf::Style::Titlebar | sf::Style::Close);
    sf::Clock clock;
    sf::Time time = sf::Time::Zero;
    sf::Font font;
    font.loadFromMemory(font_data, font_data_size);

    Circle HSL(362, "HSL", font, sf::TriangleFan, new HSLColor[362], 150, 150);
    Circle HSV(362, "HSV", font, sf::TriangleFan, new HSVColor[362], 440, 150);
    Circle CMY(724, "CMY", font, sf::TriangleStrip, new CMYColor[724], 150, 440);
    Circle RGB(724, "RGB", font, sf::TriangleStrip, new RGBColor[724], 440, 440);


    unsigned int FPS = 0, frame_counter = 0;
    bool HoldingMouseButton = false;
    //inicjalizacja 
    clock.restart().asMilliseconds();
    while (window.isOpen())
    {
        sf::Event event;
        window.clear(sf::Color::White);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.mouseButton.x > 610 && event.mouseButton.x < 650 && event.mouseButton.y >= 10 && event.mouseButton.y <= 280)
            {
                if (!HoldingMouseButton && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                {
                    
                    HoldingMouseButton = true;
                }
                else if (HoldingMouseButton && event.type == sf::Event::MouseButtonReleased)
                {
                    HoldingMouseButton = false;
                    
                }
            }
            else if (HoldingMouseButton && event.mouseMove.x > 610 && event.mouseMove.x < 650 && event.mouseMove.y >= 10 && event.mouseMove.y <= 280)
            {
                
            }

        }
        //tu wyrysowaæ wszystko na ekran
        window.draw(HSL);
        window.draw(HSV);
        window.draw(CMY);
        window.draw(RGB);


        ////tu wypisaæ na ekran wartoœæ FPS
        //if (clock.getElapsedTime().asSeconds() >= 1.0f)
        //{
        //    FPS = (unsigned int)((float)frame_counter / clock.getElapsedTime().asSeconds());
        //    clock.restart();
        //    frame_counter = 0;
        //    render.FPScounter[1].setString(std::to_string(FPS) + " FPS");
        //}
        //frame_counter++;
        //window.draw(render.FPScounter[1]);

        window.display();
    }
}
