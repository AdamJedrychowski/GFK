#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
const int XWindowSize = 750, YWindowSize = 600;

sf::Color HSVtoRGB(float H, float S, float V)
{
    S = S / 100;
    V = V / 100;
    double hh, p, q, t, ff, r, g, b;
    int i;

    if (S <= 0.0)
    {
        r = V;
        g = V;
        b = V;
        return sf::Color(r, g, b);
    }

    hh = H;
    if (hh >= 360.0) hh = 0.0;
    hh /= 60.0;
    i = (int)hh;
    ff = hh - i;
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
    return sf::Color(r*255, g*255, b*255);
}

double HueToRGB(double arg1, double arg2, double H)
{
    if (H < 0) H += 1;
    if (H > 1) H -= 1;
    if ((6 * H) < 1) { return (arg1 + (arg2 - arg1) * 6 * H); }
    if ((2 * H) < 1) { return arg2; }
    if ((3 * H) < 2) { return (arg1 + (arg2 - arg1) * ((2.0 / 3.0) - H) * 6); }
    return arg1;
}

sf::Color HSLtoRGB(double Hue, double Saturation, double Luminance)
{
    const double D_EPSILON = 0.00000000000001;
    ///Reconvert to range [0,1]
    double H = Hue / 360.0;
    double S = Saturation / 100.0;
    double L = Luminance / 100.0;

    double arg1, arg2;

    if (S <= D_EPSILON)
    {
        sf::Color C((int)(L * 255), (int)(L * 255), (int)(L * 255));
        return C;
    }
    else
    {
        if (L < 0.5) { arg2 = L * (1 + S); }
        else { arg2 = (L + S) - (S * L); }
        arg1 = 2 * L - arg2;

        sf::Uint8 r = (int)(255 * HueToRGB(arg1, arg2, (H + 1.0 / 3.0)));
        sf::Uint8 g = (int)(255 * HueToRGB(arg1, arg2, H));
        sf::Uint8 b = (int)(255 * HueToRGB(arg1, arg2, (H - 1.0 / 3.0)));
        sf::Color C(r, g, b);
        return C;
    }
}



class BufferWindow : public sf::Drawable
{
private:
    sf::VertexArray ColorBar;
    sf::VertexArray HSL, _HSV, CMY, RGB;
    sf::RenderTexture ActualWindow;
    sf::Color ShadeOfCircles;
public:
    sf::VertexArray PointerColor[2];
    bool HoldingMouseButton = false;
    BufferWindow();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(sf::Sprite(ActualWindow.getTexture()), states);
    }

    sf::RenderTexture& getActualWindow() { return ActualWindow; }

    void ChangeShade(sf::Event& event, sf::RenderWindow& window)
    {
        int temp, ChangeShade;
        sf::Color ColorToChange;
        if (HoldingMouseButton) temp = event.mouseMove.y;
        else temp = event.mouseButton.y;

        //Changing position of Pointer bar
        PointerColor[0].operator[](0).position.y = (float)temp;
        PointerColor[0].operator[](1).position.y = (float)temp;
        PointerColor[1].operator[](0).position.y = (float)temp;
        PointerColor[1].operator[](1).position.y = (float)temp;

        for (int i = 0; i < HSL.getVertexCount(); i++)
        {
            ChangeShade = (int)((280 - temp) * 100 / 270.);
            HSL[i].color.b = temp;
            HSL[i].color = HSLtoRGB(HSL[i].color.r, HSL[i].color.g, HSL[i].color.b); //cos nie dziala
        }

        
        
        if (!HoldingMouseButton)
        {
            ActualWindow.clear(sf::Color::White);

            ActualWindow.draw(PointerColor[0]);
            ActualWindow.draw(PointerColor[1]);
            ActualWindow.draw(HSL);
            ActualWindow.draw(_HSV);
            ActualWindow.draw(CMY);
            ActualWindow.draw(RGB);
            ActualWindow.draw(ColorBar);
            ActualWindow.display();
        }
        else
        {
            ActualWindow.clear(sf::Color::White);

            ActualWindow.draw(HSL);
            ActualWindow.draw(_HSV);
            ActualWindow.draw(CMY);
            ActualWindow.draw(RGB);
            ActualWindow.draw(ColorBar);
            ActualWindow.draw(PointerColor[1]);
            ActualWindow.draw(PointerColor[0]);
            ActualWindow.display();
        }
    }
};




int main()
{
    sf::RenderWindow window(sf::VideoMode(XWindowSize, YWindowSize), "GFK Lab 02", sf::Style::Titlebar | sf::Style::Close);
    sf::Clock clock;
    sf::Time time = sf::Time::Zero;
    BufferWindow render;
    unsigned int FPS = 0, frame_counter = 0;

    //inicjalizacja 
    clock.restart().asMilliseconds();
    while (window.isOpen())
    {
        sf::Event event;
        window.clear(sf::Color::White);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.mouseButton.x > 610 && event.mouseButton.x < 650 && event.mouseButton.y>10 && event.mouseButton.y < 280)
            {
                if (!render.HoldingMouseButton && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                {
                    render.ChangeShade(event, window);
                    render.HoldingMouseButton = true;
                }
                else if (render.HoldingMouseButton && event.type == sf::Event::MouseButtonReleased)
                {
                    render.HoldingMouseButton = false;
                    render.ChangeShade(event, window);
                }
            }
            else if (render.HoldingMouseButton && event.mouseMove.x > 610 && event.mouseMove.x < 650 && event.mouseMove.y>10 && event.mouseMove.y < 280)
            {
                render.ChangeShade(event, window);
            }

        }
        //tu wyrysowaæ wszystko na ekran




        render.getActualWindow().display();
        window.draw(render);

        //tu wypisaæ na ekran wartoœæ FPS
        if (clock.getElapsedTime().asSeconds() >= 1.0f)
        {
            FPS = (unsigned int)((float)frame_counter / clock.getElapsedTime().asSeconds());
            clock.restart();
            frame_counter = 0;
        }
        frame_counter++;
        window.display();
    }
}



BufferWindow::BufferWindow() : ColorBar{ sf::Quads, 4 }, HSL{ sf::TriangleFan, 362 }, _HSV{ sf::TriangleFan, 362 },
CMY{ sf::TriangleFan, 362 }, RGB{ sf::TriangleFan, 362 }
{
    ActualWindow.create(XWindowSize, YWindowSize);
    ColorBar[0].position = sf::Vector2f(610, 10);
    ColorBar[0].color = sf::Color::Black;
    ColorBar[1].position = sf::Vector2f(650, 10);
    ColorBar[1].color = sf::Color::Black;

    ColorBar[2].position = sf::Vector2f(650, 280);
    ColorBar[2].color = sf::Color::White;
    ColorBar[3].position = sf::Vector2f(610, 280);
    ColorBar[3].color = sf::Color::White;




    HSL[0].position = sf::Vector2f(150, 150);
    HSL[0].color = sf::Color(128, 128, 128);

    _HSV[0].position = sf::Vector2f(440, 150);
    _HSV[0].color=sf::Color(128, 128, 128);

    CMY[0].position = sf::Vector2f(150, 440);
    CMY[0].color = sf::Color(255, 255, 128);

    RGB[0].position = sf::Vector2f(440, 440);
    RGB[0].color = sf::Color(0, 0, 128);

    for (int i = 1; i < 362; i++)
    {
        HSL[i].position = sf::Vector2f(150 + 120 * (float)cos((i - 1) * M_PI / 180.), 150 - 120 * (float)sin((i - 1) * M_PI / 180.));
        _HSV[i].position = sf::Vector2f(440 + 120 * (float)cos((i - 1) * M_PI / 180.), 150 - 120 * (float)sin((i - 1) * M_PI / 180.));
        CMY[i].position = sf::Vector2f(150 + 120 * (float)cos((i - 1) * M_PI / 180.), 440 - 120 * (float)sin((i - 1) * M_PI / 180.));
        RGB[i].position = sf::Vector2f(440 + 120 * (float)cos((i - 1) * M_PI / 180.), 440 - 120 * (float)sin((i - 1) * M_PI / 180.));
        HSL[i].color = HSLtoRGB(i - 1, 100, 50);
        _HSV[i].color = HSVtoRGB(i - 1, 100, 50);
        CMY[i].color = sf::Color(0, 255 - (i - 1) * 255 / 362., 128);
        RGB[i].color = sf::Color(255, (i - 1)*255/362., 128);
    }
    HSL[361].position = sf::Vector2f(270, 150);
    HSL[361].color = sf::Color(255, 0, 0);

    _HSV[361].position = sf::Vector2f(560, 150);
    _HSV[361].color = sf::Color(128, 0, 2);

    CMY[361].position = sf::Vector2f(270, 440);
    CMY[361].color = sf::Color(0, 0, 128);

    RGB[361].position = sf::Vector2f(560, 440);
    RGB[361].color = sf::Color(255, 255, 128);




    PointerColor[0].setPrimitiveType(sf::Lines);
    PointerColor[0].resize(2);
    PointerColor[0].operator[](0).position = sf::Vector2f(600, 135);
    PointerColor[0].operator[](0).color = sf::Color::Black;

    PointerColor[0].operator[](1).position = sf::Vector2f(607, 135);
    PointerColor[0].operator[](1).color = sf::Color::Black;

    PointerColor[1].setPrimitiveType(sf::Lines);
    PointerColor[1].resize(2);
    PointerColor[1].operator[](0).position = sf::Vector2f(653, 135);
    PointerColor[1].operator[](0).color = sf::Color::Black;

    PointerColor[1].operator[](1).position = sf::Vector2f(660, 135);
    PointerColor[1].operator[](1).color = sf::Color::Black;



    ActualWindow.draw(PointerColor[0]);
    ActualWindow.draw(PointerColor[1]);
    ActualWindow.draw(HSL);
    ActualWindow.draw(_HSV);
    ActualWindow.draw(CMY);
    ActualWindow.draw(RGB);
    ActualWindow.draw(ColorBar);
    ActualWindow.display();
}