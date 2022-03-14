#include "pch.h"
#include <string>
#include <iostream>
// Calosc mozna dowolnie edytowac wedle uznania. 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "font.h"

class Menu : public sf::Drawable
{
private:
    sf::Font font;
    sf::Text* text;
    sf::RectangleShape* rectangle;
    wchar_t ActualMode;
    sf::Sprite ReadFromFile;

    sf::Texture* colors_texture;
    sf::Sprite* colors_sprite;
    sf::Uint8* colors_pixels;
    const unsigned int colors_size_x = 765;
    const unsigned int colors_size_y = 60;
    inline void draw_to_color_pixels(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b)
    {
        colors_pixels[4 * (y * colors_size_x + x) + 0] = r;
        colors_pixels[4 * (y * colors_size_x + x) + 1] = g;
        colors_pixels[4 * (y * colors_size_x + x) + 2] = b;
        colors_pixels[4 * (y * colors_size_x + x) + 3] = 255;
    }

public:
    mutable bool reading;
    Menu()
    {
        reading = false;
        font.loadFromMemory(font_data, font_data_size);
        text = new sf::Text;
        text->setFont(font);
        text->setCharacterSize(12);
        text->setFillColor(sf::Color::White);

        rectangle = new sf::RectangleShape(sf::Vector2f(796, 536));
        rectangle->setFillColor(sf::Color::Transparent);
        rectangle->setOutlineColor(sf::Color::White);
        rectangle->setOutlineThickness(1.0f);
        rectangle->setPosition(2, 62);

        unsigned int x, y;
        colors_pixels = new sf::Uint8[colors_size_x * colors_size_y * 4];
        for (x = 0; x < 255; x++)
            for (y = 0; y < 30; y++)
            {
                draw_to_color_pixels(x, y, x, 255, 0);
                draw_to_color_pixels(x + 255, y, 255, 255 - x, 0);
                draw_to_color_pixels(x + 510, y, 255, 0, x);
                draw_to_color_pixels(254 - x, y + 30, 0, 255, 255 - x);
                draw_to_color_pixels(509 - x, y + 30, 0, x, 255);
                draw_to_color_pixels(764 - x, y + 30, 255 - x, 0, 255);
            }

        colors_texture = new sf::Texture();
        colors_texture->create(colors_size_x, colors_size_y);
        colors_texture->update(colors_pixels);

        colors_sprite = new sf::Sprite();
        colors_sprite->setTexture(*colors_texture);
        colors_sprite->setPosition(1, 1);
    }

    void outtextxy(sf::RenderTarget& target, float x, float y, const wchar_t* str) const
    {
        text->setPosition(x, y);
        text->setString(str);
        target.draw(*text);
    }


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        outtextxy(target, 5, 600, L"f - wyb�r koloru rysowania");
        outtextxy(target, 5, 615, L"b - wyb�r koloru wype�niania");
        outtextxy(target, 5, 630, L"l - rysowanie linii");

        outtextxy(target, 200, 600, L"r - rysowanie prostok�ta");
        outtextxy(target, 200, 615, L"a - rysowanie wype�nionego prostok�ta");
        outtextxy(target, 200, 630, L"c - rysowanie okr�gu");

        outtextxy(target, 470, 600, L"w - zapis do pliku");
        outtextxy(target, 470, 615, L"o - odczyt z pliku");
        outtextxy(target, 470, 630, L"esc - wyj�cie");

        outtextxy(target, 650, 615, L"Aktualne:");
        outtextxy(target, 720, 615, &ActualMode);

        target.draw(*rectangle);
        target.draw(*colors_sprite);
        if (reading)
        {
            target.draw(ReadFromFile);
            reading = false;
        }
    }

    sf::RectangleShape* getReactangle() { return rectangle; }

    wchar_t& getMode() { return ActualMode; }

    unsigned int getColorSizeX() { return colors_size_x; }

    unsigned int getColorSizeY() { return colors_size_y; }

    sf::Color getPixelColor(unsigned int x, unsigned int y)
    {
        unsigned char r = colors_pixels[4 * (y * colors_size_x + x) + 0];
        unsigned char g = colors_pixels[4 * (y * colors_size_x + x) + 1];
        unsigned char b = colors_pixels[4 * (y * colors_size_x + x) + 2];

        return sf::Color(r, g, b);
    }

    void ReadFile(sf::Texture read)
    {
        ReadFromFile.setTexture(read);
        ReadFromFile.setPosition(2, 62);
    }
};

void clearBuffer(sf::RectangleShape& a, sf::VertexArray& l, sf::RectangleShape& r, sf::CircleShape& c)
{
    l[0].color = sf::Color(sf::Color::Black);
    l[1].color = sf::Color(sf::Color::Black);

    r.setFillColor(sf::Color(0, 0, 0, 0));
    r.setOutlineColor(sf::Color::Black);
    r.setOutlineThickness(1.0f);


    a.setFillColor(sf::Color::Black);
    a.setOutlineColor(sf::Color::Black);
    a.setOutlineThickness(1.0f);


    c.setFillColor(sf::Color(0, 0, 0, 0));
    c.setOutlineColor(sf::Color::Black);
    c.setOutlineThickness(1.0f);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 01", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;
    Menu menu;
    sf::RenderTexture render;
    render.create(800, 650);
    

    sf::Image Screenshot;
    sf::Texture PlaceToDraw, Screen;
    PlaceToDraw.create(window.getSize().x, window.getSize().y);
    Screen.create(796, 536);


    sf::Color PaintingColor = sf::Color::Black, FillColor = sf::Color::Black;
    sf::RectangleShape ShowPaintingColor, ShowFillColor;
    ShowPaintingColor.setSize(sf::Vector2f(32, 30));
    ShowPaintingColor.setFillColor(sf::Color::Black);
    ShowPaintingColor.setPosition(sf::Vector2f(menu.getColorSizeX() + 2, 1));


    ShowFillColor.setSize(sf::Vector2f(32, 28));
    ShowFillColor.setFillColor(sf::Color::Black);
    ShowFillColor.setPosition(sf::Vector2f(menu.getColorSizeX() + 2, 32));


    sf::VertexArray line(sf::LinesStrip, 2);
    line[0].color = PaintingColor;
    line[1].color = PaintingColor;


    sf::RectangleShape DrawRectangle;
    DrawRectangle.setFillColor(sf::Color(0, 0, 0, 0));
    DrawRectangle.setOutlineColor(sf::Color::Black);
    DrawRectangle.setOutlineThickness(1.0f);


    sf::RectangleShape FilledRectangle;
    FilledRectangle.setFillColor(sf::Color::Black);
    FilledRectangle.setOutlineColor(sf::Color::Black);
    FilledRectangle.setOutlineThickness(1.0f);


    sf::CircleShape circle;
    circle.setFillColor(sf::Color(0, 0, 0, 0));
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(1.0f);


    bool ButtonIsPressed = false;

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        window.clear(sf::Color::Black);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::F:
                    menu.getMode() = L'f';
                    break;

                case sf::Keyboard::B:
                    menu.getMode() = L'b';
                    break;

                case sf::Keyboard::L:
                    menu.getMode() = L'l';
                    break;

                case sf::Keyboard::R:
                    menu.getMode() = L'r';
                    break;

                case sf::Keyboard::A:
                    menu.getMode() = L'a';
                    break;

                case sf::Keyboard::C:
                    menu.getMode() = L'c';
                    break;

                case sf::Keyboard::W:
                    menu.getMode() = L'w';
                    break;

                case sf::Keyboard::O:
                    if (Screen.loadFromFile("result.png"))
                    {
                        menu.ReadFile(Screen);
                        menu.reading = true;
                        render.clear();
                        render.draw(menu);
                        window.draw(menu);
                        window.display();
                        //clearBuffer(FilledRectangle, line, DrawRectangle, circle);
                    }
                    break;

                case sf::Keyboard::Escape:
                    window.close();
                }
            }
            if (ButtonIsPressed == true && event.type == sf::Event::MouseButtonReleased
                && event.mouseButton.x > 2 && event.mouseButton.x < 798 && event.mouseButton.y>62 && event.mouseButton.y < 598)
            {
                if (menu.getMode() == 'l')
                {
                    line[1].position = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    render.draw(line);
                }
                else if (menu.getMode() == 'r')
                {
                    DrawRectangle.setSize(sf::Vector2f(event.mouseButton.x, event.mouseButton.y) - DrawRectangle.getPosition());
                    render.draw(DrawRectangle);
                }
                else if (menu.getMode() == 'a')
                {
                    FilledRectangle.setSize(sf::Vector2f(event.mouseButton.x, event.mouseButton.y) - FilledRectangle.getPosition());
                    render.draw(FilledRectangle);
                }
                else if (menu.getMode() == 'c')
                {
                    long double x = (circle.getPosition() - sf::Vector2f(event.mouseButton.x, event.mouseButton.y)).x,
                        y = (circle.getPosition() - sf::Vector2f(event.mouseButton.x, event.mouseButton.y)).y,
                        r = sqrt(x * x + y * y);
                    circle.setPosition(circle.getPosition().x + x / 2 - r, circle.getPosition().y + y / 2 - r);
                    circle.setRadius(r);
                    
                    render.draw(circle);
                }
                ButtonIsPressed = false;
            }
            if (ButtonIsPressed == true && event.mouseMove.x > 2 && event.mouseMove.x < 798 && event.mouseMove.y>62 && event.mouseMove.y < 598)
            {
                if (menu.getMode() == 'l')
                {
                    line[1].position = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
                }
                else if (menu.getMode() == 'r')
                {
                    DrawRectangle.setSize(sf::Vector2f(event.mouseMove.x, event.mouseMove.y) - DrawRectangle.getPosition());
                }
                else if (menu.getMode() == 'a')
                {
                    FilledRectangle.setSize(sf::Vector2f(event.mouseMove.x, event.mouseMove.y) - FilledRectangle.getPosition());
                }
                else if (menu.getMode() == 'c')
                {
                    long double x = (circle.getPosition() - sf::Vector2f(event.mouseMove.x, event.mouseMove.y)).x,
                        y = (circle.getPosition() - sf::Vector2f(event.mouseMove.x, event.mouseMove.y)).y,
                        r = sqrt(x * x + y * y);
                    circle.setRadius(r);
                    circle.setPosition(circle.getPosition().x + x / 2 - r, circle.getPosition().y + y / 2 - r);
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (event.mouseButton.x > 0 && event.mouseButton.x < menu.getColorSizeX() && event.mouseButton.y>0 && event.mouseButton.y < menu.getColorSizeY())
                {
                    if (menu.getMode() == 'f')
                    {
                        PaintingColor = menu.getPixelColor(event.mouseButton.x, event.mouseButton.y);
                        ShowPaintingColor.setFillColor(PaintingColor);

                        line[0].color = PaintingColor;
                        DrawRectangle.setOutlineColor(PaintingColor);
                        FilledRectangle.setOutlineColor(PaintingColor);
                        circle.setOutlineColor(PaintingColor);
                    }
                    if (menu.getMode() == 'b')
                    {
                        FillColor = menu.getPixelColor(event.mouseButton.x, event.mouseButton.y);
                        ShowFillColor.setFillColor(FillColor);

                        line[1].color = FillColor;
                        FilledRectangle.setFillColor(FillColor);
                    }
                }
                else if (event.mouseButton.x > 2 && event.mouseButton.x < 798 && event.mouseButton.y>62 && event.mouseButton.y < 598)
                {
                    if (menu.getMode() == 'l')
                    {
                        line[0].position = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                        line[1].position = line[0].position;
                        ButtonIsPressed = true;
                    }
                    else if (menu.getMode() == 'r')
                    {
                        DrawRectangle.setPosition(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                        DrawRectangle.setSize(sf::Vector2f(0, 0));
                        ButtonIsPressed = true;
                    }
                    else if (menu.getMode() == 'a')
                    {
                        FilledRectangle.setPosition(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                        FilledRectangle.setSize(sf::Vector2f(0, 0));
                        ButtonIsPressed = true;
                    }
                    else if (menu.getMode() == 'c')
                    {
                        circle.setPosition(event.mouseButton.x, event.mouseButton.y);
                        circle.setRadius(0);
                        ButtonIsPressed = true;
                    }
                }
            }
        }
        //Draw BEGIN
        // Pomi�dzy "Draw BEGIN" a "Draw End" trzeba "cos" dopisac :-). Na pewno znajd� si� tam te dwie linijki
        
        window.draw(line);
        window.draw(DrawRectangle);
        window.draw(circle);

        render.display();
        
        window.draw(sf::Sprite(render.getTexture()));
        window.draw(FilledRectangle);
        window.draw(ShowPaintingColor);
        window.draw(ShowFillColor);
        window.draw(menu);
        
        if (menu.getMode() == 'w')
        {
            PlaceToDraw.update(window);
            Screenshot = PlaceToDraw.copyToImage();
            Screenshot.saveToFile("temp.png");
            Screen.loadFromFile("temp.png", sf::IntRect(2, 62, 796, 536));
            Screenshot = Screen.copyToImage();
            Screenshot.saveToFile("result.png");
            remove("temp.png");
        }
        window.display();

        //Draw END
    }
    return 0;
}