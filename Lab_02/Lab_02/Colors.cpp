#include "Colors.h"


double HueToRGB(double arg1, double arg2, double H)
{
    if (H < 0) H += 1;
    if (H > 1) H -= 1;
    if ((6 * H) < 1) { return (arg1 + (arg2 - arg1) * 6 * H); }
    if ((2 * H) < 1) { return arg2; }
    if ((3 * H) < 2) { return (arg1 + (arg2 - arg1) * ((2.0 / 3.0) - H) * 6); }
    return arg1;
}

sf::Color HSLColor::Convert(double Hue, double Saturation, double Luminance)
{
    X = Hue;
    Y = Saturation;
    Z = Luminance;

    const double D_EPSILON = 0.00000000000001;
    double H = Hue / 360.0;
    double S = Saturation / 100.0;
    double L = Luminance / 100.0;

    double arg1, arg2;

    if (S <= D_EPSILON)
    {
        return sf::Color((int)(L * 255), (int)(L * 255), (int)(L * 255));
    }
    else
    {
        if (L < 0.5) { arg2 = L * (1 + S); }
        else { arg2 = (L + S) - (S * L); }
        arg1 = 2 * L - arg2;

        sf::Uint8 r = (int)(255 * HueToRGB(arg1, arg2, (H + 1.0 / 3.0)));
        sf::Uint8 g = (int)(255 * HueToRGB(arg1, arg2, H));
        sf::Uint8 b = (int)(255 * HueToRGB(arg1, arg2, (H - 1.0 / 3.0)));
        return sf::Color(r, g, b);
    }
}



sf::Color HSVColor::Convert(double H, double S, double V)
{
    X = H;
    Y = S;
    Z = V;
    
    S = S / 100;
    V = V / 100;
    double angle, p, q, t, ff, r, g, b;

    if (S <= 0.0)
    {
        return sf::Color(V * 255, V * 255, V * 255);
    }

    angle = H;
    if (angle >= 360.0) angle = 0.0;
    angle /= 60.0;
    int i = (int)angle;
    ff = angle - i;
    p = V * (1.0 - S);
    q = V * (1.0 - (S * ff));
    t = V * (1.0 - (S * (1.0 - ff)));
    switch (i) {
    case 0:
        r = V;
        g = t;
        b = p;
        break;
    case 1:
        r = q;
        g = V;
        b = p;
        break;
    case 2:
        r = p;
        g = V;
        b = t;
        break;

    case 3:
        r = p;
        g = q;
        b = V;
        break;
    case 4:
        r = t;
        g = p;
        b = V;
        break;
    case 5:
    default:
        r = V;
        g = p;
        b = q;
        break;
    }
    return sf::Color(r * 255, g * 255, b * 255);
}



sf::Color CMYColor::Convert(double C, double M, double _Y)
{
    X = C;
    Y = M;
    Z = 255 - _Y;
    return sf::Color(255 - C, 255 - M, 255 - _Y);
}



sf::Color RGBColor::Convert(double R, double G, double B)
{
    X = R;
    Y = G;
    Z = B;
    return sf::Color(R, G, B);
}