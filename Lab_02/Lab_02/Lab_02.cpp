#include <SFML/Graphics.hpp>

class BufferWindow : public sf::Drawable
{
private:
    sf::VertexArray ColorBar;
    sf::CircleShape HSL, _HSV, CMY, RGB;
    sf::VertexArray PointerColor[2];
    sf::RenderTexture ActualWindow;
public:
    BufferWindow() : ColorBar{sf::Quads, 4}
    {
        ActualWindow.create(800, 650);
        ColorBar[0].position = sf::Vector2f(700, 10);
        ColorBar[0].color = sf::Color::Black;
        ColorBar[1].position = sf::Vector2f(730, 10);
        ColorBar[1].color = sf::Color::Black;

        ColorBar[3].position = sf::Vector2f(700, 300);
        ColorBar[3].color = sf::Color::White;
        ColorBar[0].position = sf::Vector2f(730, 300);
        ColorBar[0].color = sf::Color::White;
        
        
        
        HSL.setPosition(sf::Vector2f(120, 120));
        HSL.setRadius(100);
        HSL.setFillColor(sf::Color::Black);
        
        _HSV.setPosition(sf::Vector2f(360, 120));
        _HSV.setRadius(100);
        _HSV.setFillColor(sf::Color::Black);

        CMY.setPosition(sf::Vector2f(120, 360));
        CMY.setRadius(100);
        CMY.setFillColor(sf::Color::Black);

        RGB.setPosition(sf::Vector2f(360, 360));
        RGB.setRadius(100);
        RGB.setFillColor(sf::Color::Black);



        PointerColor[0].setPrimitiveType(sf::Lines);
        PointerColor[0].resize(2);
        PointerColor[0].operator[](0).position = sf::Vector2f(690, 145);
        PointerColor[0].operator[](0).color = sf::Color::Black;

        PointerColor[0].operator[](1).position = sf::Vector2f(697, 145);
        PointerColor[0].operator[](1).color = sf::Color::Black;

        PointerColor[1].setPrimitiveType(sf::Lines);
        PointerColor[1].resize(2);
        PointerColor[1].operator[](0).position = sf::Vector2f(733, 145);
        PointerColor[1].operator[](0).color = sf::Color::Black;

        PointerColor[1].operator[](1).position = sf::Vector2f(740, 145);
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
    
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(sf::Sprite(ActualWindow.getTexture()), states);
    }
};


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 02", sf::Style::Titlebar | sf::Style::Close);
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