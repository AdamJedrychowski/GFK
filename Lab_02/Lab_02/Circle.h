#pragma once
#include "Colors.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "font.h"
#include <memory>
#define M_PI 3.14159265358979323846
const int XWindowSize = 750, YWindowSize = 600;

class Circle : sf::Drawable
{
private:
	int PointsNumber;
	sf::Text Name;
	sf::VertexArray FadeCircle;
	std::unique_ptr<Color> ConvertColor;
	sf::Vector2i Position;

public:
	Circle(int num, const char* text, sf::Font& font, sf::PrimitiveType type, std::unique_ptr<Color> wsk, int x, int y);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};