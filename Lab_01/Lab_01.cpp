// Calosc mozna dowolnie edytowac wedle uznania. 
#include "pch.h"
#include "font.h"
#include "Interaction.h"

void SaveToFile(sf::RenderTexture& Buffer);

void ReadFromFile(sf::RenderTexture& Buffer);


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 01", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;
    sf::Font font;
    font.loadFromMemory(font_data, font_data_size);
    Menu menu(font);
    Interaction ModifyGUI(font, menu);


    sf::RenderTexture Background;
    Background.create(794, 534);
    Background.clear(sf::Color::Black);    
    sf::Sprite DrawBackground;
    DrawBackground.setPosition(3, 63);


    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        Background.display();
        DrawBackground.setTexture(Background.getTexture());
        window.draw(DrawBackground);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                ModifyGUI.ChangeMode(event, window);
                if (ModifyGUI.getMode() == 'w') SaveToFile(Background);
                else if (ModifyGUI.getMode() == 'o') ReadFromFile(Background);
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (ModifyGUI.getMode() == 'f' || ModifyGUI.getMode() == 'b') ModifyGUI.ChangeColor(event);
            }
            if (ModifyGUI.IsButtonPressed() && event.type == sf::Event::MouseButtonReleased)
            {
                ModifyGUI.FinishDraw(window, Background, event);
            }
            else if (ModifyGUI.IsButtonPressed())
            {
                ModifyGUI.ContinueDraw(window, event);
            }
            else if (ModifyGUI.IsButtonPressed() == false && event.type == sf::Event::MouseButtonPressed)
            {
                ModifyGUI.StartDraw(window, event);
            }
        }

        window.draw(menu);
        window.draw(ModifyGUI);
        window.display();
    }
    return 0;
}


void SaveToFile(sf::RenderTexture& Buffer)
{
    Buffer.getTexture().copyToImage().saveToFile("Screenshot.png");
}


void ReadFromFile(sf::RenderTexture& Buffer)
{
    sf::Texture temp;
    temp.loadFromFile("Screenshot.png");
    Buffer.draw(sf::Sprite(temp));
}