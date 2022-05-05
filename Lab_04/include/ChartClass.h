#ifndef __ChartClass__
#define __ChartClass__

#include <memory>
#include "ConfigClass.h"
#include <vector>
#include <bitset>
#include <cmath>
class Matrix;
# define M_PI 3.14159265358979


class ChartClass
{
    private:
        std::shared_ptr<ConfigClass> cfg;
        int x_step;         // liczba odcinkow z jakich bedzie sie skladal wykres
        double x_min,x_max; // zakres zmiennej x
        double y_min,y_max; // zakres wartosci przyjmowanych przez funkcje
        double GetFunctionValue(double x); // zwraca wartosci rysowanej funkcji


         //poczatek odcinka-liczby parzyste, koniec-nieparzyste
        std::vector<wxPoint> DrawChart; // osie wykresu
        std::vector<wxPoint> Function; // funkcje
        std::vector<wxPoint> Text;
        double Xcorrelation, Ycorrelation, Xunit_min, Xunit_max, Yunit_min, Yunit_max;

       
        void CutLinesAndDraw(int w, int h, wxDC* dc, std::vector<wxPoint> &tab);
        void ChartAxes(const int& w, const int& h);
        void UpdateFunctions(const int& w, const int& h);
        void PointTranslation(const int& w, const int& h, std::vector<wxPoint>& tab);

    public:
        ChartClass(std::shared_ptr<ConfigClass> c);
        void Set_Range();   // ustala wartosci zmiennych x_min,y_min,x_max,y_max
        double Get_Y_min(); // zwraca y_min
        double Get_Y_max(); // zwraca y_max
        void Draw(wxDC *dc, int w, int h);  // rysuje wykres
};

#endif
