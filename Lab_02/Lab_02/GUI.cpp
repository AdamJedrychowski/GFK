#include "GUI.h"

GUI::GUI(sf::Font &font)
	: ColorBar{ sf::Quads, 4 }, ColorPointer{ sf::Lines, 4 }, FPScounter{ {"frame per seconds :", font, 16}, {"0 FPS", font, 16} }
{
    ColorBar[0].position = sf::Vector2f(610, 9);
    ColorBar[0].color = sf::Color::Black;
    ColorBar[1].position = sf::Vector2f(650, 9);
    ColorBar[1].color = sf::Color::Black;

    ColorBar[2].position = sf::Vector2f(650, 280);
    ColorBar[2].color = sf::Color::White;
    ColorBar[3].position = sf::Vector2f(610, 280);
    ColorBar[3].color = sf::Color::White;

    ColorPointer[0].position = sf::Vector2f(600, 135);
    ColorPointer[0].color = sf::Color::Black;
    ColorPointer[1].position = sf::Vector2f(607, 135);
    ColorPointer[1].color = sf::Color::Black;
    ColorPointer[2].position = sf::Vector2f(653, 135);
    ColorPointer[2].color = sf::Color::Black;
    ColorPointer[3].position = sf::Vector2f(660, 135);
    ColorPointer[3].color = sf::Color::Black;

    FPScounter[0].setPosition(580, 290);
    FPScounter[0].setFillColor(sf::Color::Black);
    FPScounter[1].setPosition(610, 310);
    FPScounter[1].setFillColor(sf::Color::Black);
}

void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(ColorBar);
    target.draw(ColorPointer);
    target.draw(FPScounter[0]);
    target.draw(FPScounter[1]);
}

int GUI::setPosition(sf::Event& event, bool HoldingMouseButton)
{
    int NewValue;
    if (HoldingMouseButton) NewValue = event.mouseMove.y;
    else NewValue = event.mouseButton.y;

    for (int i = 0; i < 4; i++) ColorPointer[i].position.y = (float)NewValue;

    return 280 - NewValue;
}

void GUI::setFPS(std::string FPS)
{
    FPScounter[1].setString(FPS);
}