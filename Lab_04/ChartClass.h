#ifndef __ChartClass__
#define __ChartClass__

#include <memory>
#include "ConfigClass.h"
#include <vector>
#include <bitset>
class Matrix;



class ChartClass
{
    private:
        std::shared_ptr<ConfigClass> cfg;
        int x_step;         // liczba odcinkow z jakich bedzie sie skladal wykres
        double x_min,x_max; // zakres zmiennej x
        double y_min,y_max; // zakres wartosci przyjmowanych przez funkcje
        double GetFunctionValue(double x); // zwraca wartosci rysowanej funkcji
        
        void line2d(Matrix t,double *x1,double *y1,double *x2,double *y2);
        // powyzej sugerowana funkcja transformujaca odcinki (jesli ktos ma 
        // inny pomysl mozna ja usunac)

         //poczatek odcinka-liczby parzyste, koniec-nieparzyste
        std::vector<wxPoint> DrawChart; // osie wykresu
        std::vector<wxPoint> Function; // funkcje

       
    public:
        ChartClass(std::shared_ptr<ConfigClass> c);
        void Set_Range();   // ustala wartosci zmiennych x_min,y_min,x_max,y_max
        double Get_Y_min(); // zwraca y_min
        double Get_Y_max(); // zwraca y_max
        void Draw(wxDC *dc, int w, int h);  // rysuje wykres

        void CutLinesAndDraw(int w, int h, wxDC* dc, std::vector<wxPoint> &tab);
        void ChartAxes(const int& w, const int& h);
        void UpdateFunctions(const int& w, const int& h);
        void DrawFunction(wxDC *dc);
};

#endif
