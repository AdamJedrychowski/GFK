#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

sf::Color imguiColorToSFMLColor(float fcolor[3])
{
    return sf::Color::Color(
        static_cast<sf::Uint8>(fcolor[0] * 255.f),
        static_cast<sf::Uint8>(fcolor[1] * 255.f),
        static_cast<sf::Uint8>(fcolor[2] * 255.f)
    );
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "GFK", sf::Style::Resize);
    sf::Event event;
    sf::Clock deltaClock;
    sf::CircleShape circle;
    float circleFillColor[3] = { 1.f, 1.f, 1.f };
    float circleOutlineColor[3] = { 1.f, 0.f, 0.f };
    float x = 10.f, y = 10.f, r = 20.f, thick = 3.f;

    window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(window);

    circle.setRadius(r);
    circle.setFillColor(sf::Color::Color(imguiColorToSFMLColor(circleFillColor)));
    circle.setOutlineColor(sf::Color::Color(imguiColorToSFMLColor(circleOutlineColor)));
    circle.setOutlineThickness(thick);
    circle.setPosition(sf::Vector2f(x, y));

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        // ------------- begin ImGui window ---------------------------
        ImGui::Begin("Circle Pamameters...");

        if (ImGui::ColorEdit3("Fill Color", circleFillColor))
            circle.setFillColor(sf::Color::Color(imguiColorToSFMLColor(circleFillColor)));
        if (ImGui::ColorEdit3("Outline Color", circleOutlineColor))
            circle.setOutlineColor(sf::Color::Color(imguiColorToSFMLColor(circleOutlineColor)));

        ImGui::SliderFloat("R", &r, 0.0f, 100.0f);
        circle.setRadius(r);

        ImGui::SliderFloat("thick", &thick, 0.0f, 10.0f);
        circle.setOutlineThickness(thick);

        ImGui::SliderFloat("X", &x, 0.0f, 800.0f);
        ImGui::SliderFloat("Y", &y, 0.0f, 600.0f);
        circle.setPosition(sf::Vector2f(x, y));

        if (ImGui::Button("EXIT")) window.close();

        ImGui::End();
        // ------------- end ImGui window ---------------------------

        window.clear(sf::Color::Black);
        window.draw(circle);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}