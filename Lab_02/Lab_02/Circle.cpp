#include "Circle.h"


Circle::Circle(int num, const char* text, sf::Font& font, sf::PrimitiveType type, std::unique_ptr<Color> wsk, int x, int y)
	: PointsNumber{ num }, Name{ text, font, 16 }, FadeCircle{ type, num }, ConvertColor{ wsk.release() }, Position{ x, y }
{
	FadeCircle[0].position = sf::Vector2f(150, 150);
	FadeCircle[0].color = sf::Color(128, 128, 128);
}


void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}