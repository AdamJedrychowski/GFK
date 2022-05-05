#pragma once
#include "Menu.h"

class Interaction : public sf::Drawable
{
private:
    Menu& GUI;
    sf::Color PaintingColor, FillColor;
    sf::RectangleShape ShowPaintingColor, ShowFillColor;
    char ActualMode;
    mutable sf::Text PrintMode;
    
    sf::VertexArray line;
    sf::RectangleShape DrawRectangle, FilledRectangle;
    sf::CircleShape circle;
    bool ButtonIsPressed;
public:
    Interaction(sf::Font& font, Menu &menu);


    void StartDraw(sf::RenderWindow &window, sf::Event &e);

    void ContinueDraw(sf::RenderWindow& window, sf::Event& e);

    void FinishDraw(sf::RenderWindow& window, sf::RenderTexture& Buffer, sf::Event& e);

    void ChangeMode(sf::Event& e, sf::RenderWindow &window);

    void ChangeColor(sf::Event& e);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    char getMode() const { return ActualMode; }

    bool IsButtonPressed() const { return ButtonIsPressed; }
};