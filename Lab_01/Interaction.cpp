#include "pch.h"
#include "Interaction.h"

void Interaction::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    PrintMode.setString(ActualMode);

    target.draw(line);
    target.draw(DrawRectangle);
    target.draw(FilledRectangle);
    target.draw(circle);

    target.draw(PrintMode);
    target.draw(ShowFillColor);
    target.draw(ShowPaintingColor);
}



void Interaction::StartDraw(sf::RenderWindow& window, sf::Event& e)
{
    if (e.mouseButton.x > 2 && e.mouseButton.x < 798 && e.mouseButton.y>62 && e.mouseButton.y < 598)
    {
        if (ActualMode == 'l')
        {
            line[0].position = sf::Vector2f(e.mouseButton.x, e.mouseButton.y);
            line[1].position = line[0].position;
        }
        else if (ActualMode == 'r')
        {
            DrawRectangle.setPosition(sf::Vector2f(e.mouseButton.x, e.mouseButton.y));
            DrawRectangle.setSize(sf::Vector2f(0, 0));
        }
        else if (ActualMode == 'a')
        {
            FilledRectangle.setPosition(sf::Vector2f(e.mouseButton.x, e.mouseButton.y));
            FilledRectangle.setSize(sf::Vector2f(0, 0));
        }
        else if (ActualMode == 'c')
        {
            circle.setPosition(e.mouseButton.x, e.mouseButton.y);
            circle.setRadius(0);
        }
        ButtonIsPressed = true;
    }
}


void Interaction::ContinueDraw(sf::RenderWindow& window, sf::Event& e)
{
    if (e.mouseMove.x > 2 && e.mouseMove.x < 798 && e.mouseMove.y>62 && e.mouseMove.y < 598)
    {
        if (ActualMode == 'l')
        {
            line[1].position = sf::Vector2f(e.mouseMove.x, e.mouseMove.y);
        }
        else if (ActualMode == 'r')
        {
            DrawRectangle.setSize(sf::Vector2f(e.mouseMove.x, e.mouseMove.y) - DrawRectangle.getPosition());
        }
        else if (ActualMode == 'a')
        {
            FilledRectangle.setSize(sf::Vector2f(e.mouseMove.x, e.mouseMove.y) - FilledRectangle.getPosition());
        }
        else if (ActualMode == 'c')
        {
            double x = (circle.getPosition() - sf::Vector2f(e.mouseMove.x, e.mouseMove.y)).x,
                y = (circle.getPosition() - sf::Vector2f(e.mouseMove.x, e.mouseMove.y)).y,
                r = sqrt(x * x + y * y);
            circle.setRadius(r / 2.);
            circle.setOrigin(r / 2. * (1 - sqrt(2.) / 2), r / 2. * (1 - sqrt(2.) / 2));
            circle.setRotation(-225 + ((e.mouseMove.y < circle.getPosition().y) ? 1 : -1) * acos(x / r) * 180 / M_PI);
        }
    }
}


void Interaction::FinishDraw(sf::RenderWindow& window, sf::RenderTexture& Buffer, sf::Event& e)
{
    if (e.mouseButton.x > 2 && e.mouseButton.x < 798 && e.mouseButton.y>62 && e.mouseButton.y < 598)
    {
        if (ActualMode == 'l')
        {
            window.draw(line);
            line[0].position -= sf::Vector2f(3, 63);
            line[1].position = sf::Vector2f(e.mouseButton.x - 3, e.mouseButton.y - 63);
            Buffer.draw(line);
            line[1].position = line[0].position;
        }
        else if (ActualMode == 'r')
        {
            DrawRectangle.setSize(sf::Vector2f(e.mouseButton.x, e.mouseButton.y) - DrawRectangle.getPosition());
            window.draw(DrawRectangle);
            DrawRectangle.setPosition(DrawRectangle.getPosition() - sf::Vector2f(3, 63));
            Buffer.draw(DrawRectangle);
            DrawRectangle.setSize(sf::Vector2f(0, 0));
        }
        else if (ActualMode == 'a')
        {
            FilledRectangle.setSize(sf::Vector2f(e.mouseButton.x, e.mouseButton.y) - FilledRectangle.getPosition());
            window.draw(FilledRectangle);
            FilledRectangle.setPosition(FilledRectangle.getPosition() - sf::Vector2f(3, 63));
            Buffer.draw(FilledRectangle);
            FilledRectangle.setSize(sf::Vector2f(0, 0));
        }
        else if (ActualMode == 'c')
        {
            window.draw(circle);
            double x = (circle.getPosition().x - e.mouseButton.x),
                y = (circle.getPosition().y - e.mouseButton.y),
                r = sqrt(x * x + y * y);
            circle.setRadius(r / 2.);
            circle.setOrigin(r / 2. * (1 - sqrt(2.) / 2), r / 2. * (1 - sqrt(2.) / 2));
            circle.setRotation(-225 + ((e.mouseButton.y < circle.getPosition().y) ? 1 : -1) * acos(x / r) * 180 / M_PI);
            circle.move(-3, -63);
            Buffer.draw(circle);
            circle.setRadius(0);
        }
        ButtonIsPressed = false;
    }
}


void Interaction::ChangeMode(sf::Event& e, sf::RenderWindow &window)
{
    switch (e.key.code)
    {
    case sf::Keyboard::F:
        ActualMode = 'f';
        break;

    case sf::Keyboard::B:
        ActualMode = 'b';
        break;

    case sf::Keyboard::L:
        ActualMode = 'l';
        break;

    case sf::Keyboard::R:
        ActualMode = 'r';
        break;

    case sf::Keyboard::A:
        ActualMode = 'a';
        break;

    case sf::Keyboard::C:
        ActualMode = 'c';
        break;

    case sf::Keyboard::W:
        ActualMode = 'w';
        break;

    case sf::Keyboard::O:
        ActualMode = 'o';
        break;

    case sf::Keyboard::Escape:
        window.close();
    }
}


void Interaction::ChangeColor(sf::Event& e)
{
    if (e.mouseButton.x > 0 && e.mouseButton.x < GUI.colors_size_x && e.mouseButton.y>0 && e.mouseButton.y < GUI.colors_size_y)
    {
        unsigned char r = GUI.colors_pixels[4 * (e.mouseButton.y * GUI.colors_size_x + e.mouseButton.x) + 0];
        unsigned char g = GUI.colors_pixels[4 * (e.mouseButton.y * GUI.colors_size_x + e.mouseButton.x) + 1];
        unsigned char b = GUI.colors_pixels[4 * (e.mouseButton.y * GUI.colors_size_x + e.mouseButton.x) + 2];

        if (ActualMode == 'f')
        {
            PaintingColor = sf::Color(r, g, b);
            ShowPaintingColor.setFillColor(PaintingColor);

            line[0].color = PaintingColor;
            DrawRectangle.setOutlineColor(PaintingColor);
            FilledRectangle.setOutlineColor(PaintingColor);
            circle.setOutlineColor(PaintingColor);
        }
        if (ActualMode == 'b')
        {
            FillColor = sf::Color(r, g, b);
            ShowFillColor.setFillColor(FillColor);

            line[1].color = FillColor;
            FilledRectangle.setFillColor(FillColor);
        }
    }
}



Interaction::Interaction(sf::Font& font, Menu &menu)
    : GUI{ menu }, PaintingColor{ sf::Color::Black }, FillColor{ sf::Color::Black }, ShowPaintingColor{ sf::Vector2f(32, 30) },
    ShowFillColor{ sf::Vector2f(32, 28) }, ActualMode{ ' ' }, PrintMode{ sf::String(' '), font, 12 }, line{sf::LineStrip, 2}, ButtonIsPressed{false}
{
    ShowPaintingColor.setFillColor(sf::Color::Black);
    ShowPaintingColor.setPosition(sf::Vector2f(GUI.colors_size_x + 2, 1));


    ShowFillColor.setFillColor(sf::Color::Black);
    ShowFillColor.setPosition(sf::Vector2f(GUI.colors_size_x + 2, 32));

    PrintMode.setPosition(720, 615);

    line[0].color = PaintingColor;
    line[1].color = PaintingColor;

    DrawRectangle.setFillColor(sf::Color::Transparent);
    DrawRectangle.setOutlineColor(sf::Color::Black);
    DrawRectangle.setOutlineThickness(1.0f);

    FilledRectangle.setFillColor(sf::Color::Black);
    FilledRectangle.setOutlineColor(sf::Color::Black);
    FilledRectangle.setOutlineThickness(1.0f);

    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(1.0f);
}