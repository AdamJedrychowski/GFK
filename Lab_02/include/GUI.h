#pragma once
#include "Circle.h"

class GUI : public sf::Drawable
{
private:
	sf::VertexArray ColorBar, ColorPointer;
	sf::Text FPScounter[2];
public:
	GUI(sf::Font& font);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// returns value from [0; 270]
	int setPosition(sf::Event& event, bool HoldingMouseButton);
	void setFPS(std::string FPS);
};