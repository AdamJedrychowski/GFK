#pragma once
#include "Circle.h"

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
	std::string GetZ() override
	{
		double temp = round(100 - Z * 100 / 255.);
		if(temp<10) return std::string("=" + std::to_string(temp).substr(0, 1) + "%");
		else if(temp>99) return std::string("=" + std::to_string(temp).substr(0, 3) + "%");
		return std::string("=" + std::to_string(temp).substr(0, 2) + "%");
	}
};

class RGBColor : public Color
{
	sf::Color Convert(double, double, double) override;
	std::string GetZ() override { return std::string("=" + std::to_string((int)Z)); }
};