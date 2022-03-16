#include <SFML/Graphics.hpp>
#include <iostream>
const int XWindowSize = 750, YWindowSize = 600;


class BufferWindow : public sf::Drawable
{
private:
    sf::VertexArray ColorBar;
    sf::CircleShape HSL, _HSV, CMY, RGB;
    sf::VertexArray PointerColor[2];
    sf::RenderTexture ActualWindow;


    sf::Color ShadeOfCircles;
    float ColorPointerY = 135;
public:
    BufferWindow();
    
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(sf::Sprite(ActualWindow.getTexture()), states);
    }

    void ChangeShade(sf::Event &event)
    {
        if(event.type==sf::Mouse::) float temp = event.mouseMove.y;

        ColorPointerY;
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

        window.draw(render);
        window.display();
    }
}



BufferWindow::BufferWindow() : ColorBar{ sf::Quads, 4 }
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



    HSL.setPosition(sf::Vector2f(30, 30));
    HSL.setRadius(120);
    HSL.setFillColor(sf::Color::Black);

    _HSV.setPosition(sf::Vector2f(320, 30));
    _HSV.setRadius(120);
    _HSV.setFillColor(sf::Color::Black);

    CMY.setPosition(sf::Vector2f(30, 320));
    CMY.setRadius(120);
    CMY.setFillColor(sf::Color::Black);

    RGB.setPosition(sf::Vector2f(320, 320));
    RGB.setRadius(120);
    RGB.setFillColor(sf::Color::Black);



    PointerColor[0].setPrimitiveType(sf::Lines);
    PointerColor[0].resize(2);
    PointerColor[0].operator[](0).position = sf::Vector2f(600, ColorPointerY);
    PointerColor[0].operator[](0).color = sf::Color::Black;

    PointerColor[0].operator[](1).position = sf::Vector2f(607, ColorPointerY);
    PointerColor[0].operator[](1).color = sf::Color::Black;

    PointerColor[1].setPrimitiveType(sf::Lines);
    PointerColor[1].resize(2);
    PointerColor[1].operator[](0).position = sf::Vector2f(653, ColorPointerY);
    PointerColor[1].operator[](0).color = sf::Color::Black;

    PointerColor[1].operator[](1).position = sf::Vector2f(660, ColorPointerY);
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