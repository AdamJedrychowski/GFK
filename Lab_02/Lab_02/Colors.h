#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>
#include <iostream>

class Color
{
public:
	double X,Y,Z;
	friend class Circle;
	virtual sf::Color Convert(double, double, double) { return sf::Color(0, 0, 0); }
	virtual std::string GetZ() { return ""; }
};

class HSLColor : public Color
{
	sf::Color Convert(double, double, double) override;
	std::string GetZ() override { return std::string("=" + std::to_string(Z / 100).substr(0, 4)); }
};

class HSVColor : public Color
{
	sf::Color Convert(double, double, double) override;
	std::string GetZ() override { return std::string("=" + std::to_string(Z / 100).substr(0, 4)); }
};

class CMYColor : public Color
{
	sf::Color Convert(double, double, double) override;
	std::string GetZ() override { return std::string("=" + std::to_string((int)Z) + "%"); }
};

class RGBColor : public Color
{
	sf::Color Convert(double, double, double) override;
	std::string GetZ() override { std::cout << Z; return std::string("=" + std::to_string((int)Z)); }
};