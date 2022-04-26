#pragma once
#include <SFML/Graphics.hpp>
#include "Colors.h"
#include <iostream>
#include <cmath>
#include <memory>
#include <cstring>
#include <iostream>
#define M_PI 3.14159265358979323846
class Color;


class Circle : public sf::Drawable
{
private:
	int PointsNumber;
	sf::Text Name[2];
	sf::VertexArray FadeCircle;
	std::unique_ptr<Color[]> ConvertColor;
	sf::Vector2i Position;

public:
	Circle(int num, const char* text, sf::Font &font, sf::PrimitiveType type, Color* wsk, int x, int y);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void ChangeShade(sf::Event& event, bool HoldingMouseButton, int NewShade);
};