#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
const int XWindowSize = 750, YWindowSize = 600;


class BufferWindow : public sf::Drawable
{
private:
    sf::VertexArray ColorBar;
    sf::VertexArray HSL, _HSV, CMY, RGB;
    sf::RenderTexture ActualWindow;
    sf::Color ShadeOfCircles;
public:
    sf::VertexArray PointerColor[2];
    bool HoldingMouseButton = false;
    BufferWindow();
    
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(sf::Sprite(ActualWindow.getTexture()), states);
    }

    sf::RenderTexture& getActualWindow() { return ActualWindow; }

    void ChangeShade(sf::Event &event, sf::RenderWindow &window)
    {
        int temp, ChangeShade;
        if (HoldingMouseButton) temp = event.mouseMove.y;
        else temp = event.mouseButton.y;

        //Changing position of Pointer bar
        PointerColor[0].operator[](0).position.y = temp;
        PointerColor[0].operator[](1).position.y = temp;
        PointerColor[1].operator[](0).position.y = temp;
        PointerColor[1].operator[](1).position.y = temp;

        if (!HoldingMouseButton)
        {
            ActualWindow.clear(sf::Color::White);

            ActualWindow.draw(PointerColor[0]);
            ActualWindow.draw(PointerColor[1]);
            ActualWindow.draw(HSL);
            ActualWindow.draw(_HSV);
            ActualWindow.draw(CMY);
            ActualWindow.draw(RGB);
            ActualWindow.draw(ColorBar);
            ActualWindow.display();
        }
        else
        {
            ActualWindow.clear(sf::Color::White);

            ActualWindow.draw(HSL);
            ActualWindow.draw(_HSV);
            ActualWindow.draw(CMY);
            ActualWindow.draw(RGB);
            ActualWindow.draw(ColorBar);
            ActualWindow.draw(PointerColor[1]);
            ActualWindow.draw(PointerColor[0]);
            ActualWindow.display();
        }

        ChangeShade = (280 - temp) * 255 / 270.;
        //cos dopisac
    }
};




int main()
{
    sf::RenderWindow window(sf::VideoMode(XWindowSize, YWindowSize), "GFK Lab 02", sf::Style::Titlebar | sf::Style::Close);
    sf::Clock clock;
    sf::Time time = sf::Time::Zero;
    BufferWindow render;
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
            if (event.mouseButton.x > 610 && event.mouseButton.x < 650 && event.mouseButton.y>10 && event.mouseButton.y < 280)
            {
                if (!render.HoldingMouseButton && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                {
                    render.ChangeShade(event, window);
                    render.HoldingMouseButton = true;
                }
                else if (render.HoldingMouseButton && event.type == sf::Event::MouseButtonReleased)
                {
                    render.HoldingMouseButton = false;
                    render.ChangeShade(event, window);
                }
            }
            else if (render.HoldingMouseButton && event.mouseMove.x > 610 && event.mouseMove.x < 650 && event.mouseMove.y>10 && event.mouseMove.y < 280)
            {
                render.ChangeShade(event, window);
            }

        }
        //tu wyrysowaæ wszystko na ekran
        



        render.getActualWindow().display();
        window.draw(render);

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



BufferWindow::BufferWindow() : ColorBar{ sf::Quads, 4 }, HSL{sf::TriangleFan, 511}, _HSV{ sf::TriangleFan, 511 },
CMY{ sf::TriangleFan, 511 }, RGB{ sf::TriangleFan, 511 }
{
    ActualWindow.create(XWindowSize, YWindowSize);
    ColorBar[0].position = sf::Vector2f(610, 10);
    ColorBar[0].color = sf::Color::Black;
    ColorBar[1].position = sf::Vector2f(650, 10);
    ColorBar[1].color = sf::Color::Black;

    ColorBar[2].position = sf::Vector2f(650, 280);
    ColorBar[2].color = sf::Color::White;
    ColorBar[3].position = sf::Vector2f(610, 280);
    ColorBar[3].color = sf::Color::White;


    HSL[0].position = sf::Vector2f(150, 150);
    _HSV[0].position = sf::Vector2f(440, 150);
    CMY[0].position = sf::Vector2f(150, 440);
    RGB[0].position = sf::Vector2f(440, 440);
    for (int i = 1; i < 511; i++)
    {
        HSL[i].position = sf::Vector2f(150+120*cos(1.42*i), 150);
    }



    PointerColor[0].setPrimitiveType(sf::Lines);
    PointerColor[0].resize(2);
    PointerColor[0].operator[](0).position = sf::Vector2f(600, 135);
    PointerColor[0].operator[](0).color = sf::Color::Black;

    PointerColor[0].operator[](1).position = sf::Vector2f(607, 135);
    PointerColor[0].operator[](1).color = sf::Color::Black;

    PointerColor[1].setPrimitiveType(sf::Lines);
    PointerColor[1].resize(2);
    PointerColor[1].operator[](0).position = sf::Vector2f(653, 135);
    PointerColor[1].operator[](0).color = sf::Color::Black;

    PointerColor[1].operator[](1).position = sf::Vector2f(660, 135);
    PointerColor[1].operator[](1).color = sf::Color::Black;



    ActualWindow.draw(PointerColor[0]);
    ActualWindow.draw(PointerColor[1]);
    ActualWindow.draw(HSL);
    ActualWindow.draw(_HSV);
    ActualWindow.draw(CMY);
    ActualWindow.draw(RGB);
    ActualWindow.draw(ColorBar);
    ActualWindow.display();
}