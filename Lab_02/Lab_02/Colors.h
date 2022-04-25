#pragma once
#include "Circle.h"


class Color
{
	unsigned char X,Y,Z;
	virtual void Create(unsigned char, unsigned char, unsigned char, std::unique_ptr<Color>&) = 0;
	virtual void Convert(unsigned char, unsigned char, unsigned char, std::unique_ptr<Color>&) = 0;
};

class HSLColor : public Color
{
	void Create(unsigned char, unsigned char, unsigned char, std::unique_ptr<Color>&) override;
	void Convert(unsigned char, unsigned char, unsigned char, std::unique_ptr<Color>&) override;
};