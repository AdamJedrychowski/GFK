#include "Circle.h"


Circle::Circle(int num, const char* text, sf::Font& font, sf::PrimitiveType type, Color* wsk, int x, int y)
	: PointsNumber{ num }, Name{ {text, font, 16}, { text[2], font, 16}}, FadeCircle{type, num}, ConvertColor{std::move(wsk)}, Position{x, y}
{
	if (type == sf::TriangleFan)
	{
		FadeCircle[0].position = sf::Vector2f(Position.x, Position.y);
		FadeCircle[0].color = ConvertColor[0].Convert(0, 0, 50);

		for (int i = 1; i < PointsNumber; i++)
		{
			FadeCircle[i].position = sf::Vector2f(Position.x + 120 * (float)cos((i - 1) * M_PI / 180.), Position.y - 120 * (float)sin((i - 1) * M_PI / 180.));
			FadeCircle[i].color = ConvertColor[i].Convert(i - 1, 100, 50);
		}
	}
	else if (type == sf::TriangleStrip)
	{
		FadeCircle[0].position = sf::Vector2f(Position.x, Position.y);
		FadeCircle[0].color = ConvertColor[0].Convert(0, 0, 128);
		FadeCircle[1].position = sf::Vector2f(Position.x + 120, Position.y);
		FadeCircle[1].color = ConvertColor[1].Convert(255, 0, 128);
		FadeCircle[2].position = sf::Vector2f(Position.x + 120, Position.y - 2.0943);
		FadeCircle[2].color = ConvertColor[2].Convert(255, 1, 128);

		for (int i = 3; i < PointsNumber; i++)
		{
			if (i % 2 == 1)
			{
				FadeCircle[i].position = sf::Vector2f(Position.x, Position.y);
				FadeCircle[i].color = ConvertColor[i].Convert(0, i / 2. * 255 / 362., 128);
			}
			else
			{
				FadeCircle[i].position = sf::Vector2f(Position.x + 120 * (float)cos((i / 2. - 1) * M_PI / 180.), Position.y - 120 * (float)sin((i / 2. - 1) * M_PI / 180.));
				FadeCircle[i].color = ConvertColor[i].Convert(255, i / 2. * 255 / 362., 128);
			}
		}
	}

	Name[0].setFillColor(sf::Color::Black);
	Name[0].setPosition(Position.x - 120, Position.y - 120);
	Name[1].setFillColor(sf::Color::Black);
	Name[1].setPosition(Position.x + 80, Position.y + 100);
	Name[1].setString(char(Name[0].getString().operator[](2)) + ConvertColor[0].GetZ());
}


void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(FadeCircle);
	target.draw(Name[0]);
	target.draw(Name[1]);
}


void Circle::ChangeShade(double NewValue)
{
	
}