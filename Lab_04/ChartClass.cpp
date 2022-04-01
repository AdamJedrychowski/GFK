#include <wx/dc.h>
#include <memory>

#include "ChartClass.h"
#include "vecmat.h"

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c)
{
    cfg= std::move(c);
    x_step=200;

    Function.reserve(x_step * 2);
    DrawChart.reserve(24);
}

void ChartClass::Set_Range()
{
 double xmin=9999.9,xmax=-9999.9,ymin=9999.9,ymax=-9999.9;
 double x,y,step;
 int i;

 xmin=cfg->Get_x_start();
 xmax=cfg->Get_x_stop();

 step=(cfg->Get_x_stop()-cfg->Get_x_start())/(double)x_step;
 x=cfg->Get_x_start();

 for (i=0;i<=x_step;i++)
  {
   y=GetFunctionValue(x);
   if (y>ymax) ymax=y;
   if (y<ymin) ymin=y;
   x=x+step;
  }

 y_min=ymin;
 y_max=ymax;
 x_min=xmin;
 x_max=xmax;
}


double ChartClass::GetFunctionValue(double x)
{
 if (cfg->Get_F_type()==1) return x*x;
 if (cfg->Get_F_type()==2) return 0.5*exp(4*x-3*x*x);
 return x+sin(x*4.0);
}

void ChartClass::Draw(wxDC *dc, int w, int h)
{
 dc->SetBackground(wxBrush(RGB(255, 255, 255)));
 dc->Clear();
 dc->SetPen(wxPen(RGB(255, 0, 0)));
 dc->DrawRectangle(10, 10, w - 20, h - 20);
 Set_Range();

 ChartAxes(w, h);
 dc->SetPen(wxPen(RGB(0, 0, 255)));
 //for (int i = 0; i < DrawChart.size(); i += 2) dc->DrawLine(DrawChart[i], DrawChart[i + 1]);
 CutLinesAndDraw(w, h, dc, DrawChart);

 UpdateFunctions(w, h);
 dc->SetPen(wxPen(RGB(0, 255, 0)));
 CutLinesAndDraw(w, h, dc, Function);
 //DrawFunction(dc);

 dc->DrawText(wxString::Format("%lf, %lf, %lf, %lf, %d", x_min, x_max, y_min, y_max, x_step), 20, 20);
}

void ChartClass::line2d(Matrix t, double *x1, double *y1, double *x2, double *y2)
{
 // ...... cos .......
}

double ChartClass::Get_Y_min()
{
    Set_Range();
    return y_min;
}

double ChartClass::Get_Y_max()
{
    Set_Range();
    return y_max;
}

void ChartClass::CutLinesAndDraw(int w, int h, wxDC *dc, std::vector<wxPoint> &tab)
{
    std::bitset<4> A_bit, B_bit;
    wxPoint A, B;
    for (int i = 0; i < tab.size(); i+=2)
    {
        // bit 3
        if (y_max - tab[i].y < 0) A_bit.set(3, 1);
        if (y_max - tab[i + 1].y < 0) B_bit.set(3, 1);

        // bit 2
        if (tab[i].y - y_min < 0) A_bit.set(2, 1);
        if (tab[i + 1].y - y_min < 0) B_bit.set(2, 1);

        //bit 1
        if (tab[i].y - x_max < 0) A_bit.set(1, 1);
        if (tab[i + 1].y - x_max < 0) B_bit.set(1, 1);

        //bit 0
        if (x_min - tab[i].y < 0) A_bit.set(0, 1);
        if (x_min - tab[i + 1].y < 0) B_bit.set(0, 1);////////////////////////check

        if (A_bit == 0 && B_bit == 0)
        {
            dc->DrawLine(Function[i], Function[i + 1]); // w obszarze
            continue;
        }
        else if ((A_bit & B_bit) != 0) continue; // poza obszarem
        
        if (A_bit[0] || A_bit[1])
        {
            A.x = x_min;
            A.y = tab[i].y + ((A_bit[0]) ? x_min - tab[i].x : x_max - x_min) * (tab[i + 1].y - tab[i].y) / (tab[i + 1].x - tab[i].x);
        }
        if (B_bit[0] || B_bit[1])
        {
            B.x = x_min;
            B.y = tab[i + 1].y + ((B_bit[0]) ? x_min - tab[i + 1].x : x_max - x_min) * (tab[i].y - tab[i + 1].y) / (tab[i].x - tab[i + 1].x);
        }

        if (A_bit[2] || A_bit[3])
        {
            A.y = (A_bit[2]) ? y_min : y_max;
            A.x = tab[i].x + ((A_bit[2]) ? y_min - tab[i].y : y_max - tab[i].y) * (tab[i + 1].x - tab[i].x) / (tab[i + 1].y - tab[i].y);
        }
        if (B_bit[2] || B_bit[3])
        {
            B.y = (B_bit[2]) ? y_min : y_max;
            B.x = tab[i + 1].x + ((B_bit[2]) ? y_min - tab[i + 1].y : y_max - tab[i + 1].y) * (tab[i].x - tab[i + 1].x) / (tab[i].y - tab[i + 1].y);
        }
        dc->DrawLine(A, B);
    }
}

void ChartClass::ChartAxes(const int &w, const int &h)
{
    DrawChart.clear();
    
    // osie wykresu
    DrawChart.push_back(wxPoint(w / 2 + x_min * ((w - 20) / 2), h / 2));
    DrawChart.push_back(wxPoint(w / 2 + x_max * ((w - 20) / 2), h / 2));
    DrawChart.push_back(wxPoint(w / 2, h / 2 - y_min * ((h - 20) / 4)));
    DrawChart.push_back(wxPoint(w / 2, h / 2 - y_max * ((h - 20) / 4)));

    // podzialki na osi x
    DrawChart.push_back(wxPoint(w / 2 + x_min * ((w - 20) / 4), h / 2 - 5));
    DrawChart.push_back(wxPoint(w / 2 + x_min * ((w - 20) / 4), h / 2 + 5));
    DrawChart.push_back(wxPoint(w / 2 + x_max * ((w - 20) / 6), h / 2 - 5));
    DrawChart.push_back(wxPoint(w / 2 + x_max * ((w - 20) / 6), h / 2 + 5));
    DrawChart.push_back(wxPoint(w / 2 + x_max * ((w - 20) / 3), h / 2 - 5));
    DrawChart.push_back(wxPoint(w / 2 + x_max * ((w - 20) / 3), h / 2 + 5));

    // podzialki na osi y
    DrawChart.push_back(wxPoint(w / 2 - 5, h / 2 - y_min * ((h - 20) / 8)));
    DrawChart.push_back(wxPoint(w / 2 + 5, h / 2 - y_min * ((h - 20) / 8)));
    DrawChart.push_back(wxPoint(w / 2 - 5, h / 2 - y_max * ((h - 20) / 6)));
    DrawChart.push_back(wxPoint(w / 2 + 5, h / 2 - y_max * ((h - 20) / 6)));
    DrawChart.push_back(wxPoint(w / 2 - 5, h / 2 - y_max * ((h - 20) / 12)));
    DrawChart.push_back(wxPoint(w / 2 + 5, h / 2 - y_max * ((h - 20) / 12)));

    // zakonczenia wykresu (strza³ki)
    DrawChart.push_back(wxPoint(w / 2 + x_max * ((w - 20) / 2), h / 2));
    DrawChart.push_back(wxPoint(w / 2 + x_max * ((w - 20) / 2) - 10, h / 2 - 5));
    DrawChart.push_back(wxPoint(w / 2 + x_max * ((w - 20) / 2), h / 2));
    DrawChart.push_back(wxPoint(w / 2 + x_max * ((w - 20) / 2) - 10, h / 2 + 5));
    DrawChart.push_back(wxPoint(w / 2, h / 2 - y_max * ((h - 20) / 4)));
    DrawChart.push_back(wxPoint(w / 2 - 5 , h / 2 - y_max * ((h - 20) / 4) + 10));
    DrawChart.push_back(wxPoint(w / 2, h / 2 - y_max * ((h - 20) / 4)));
    DrawChart.push_back(wxPoint(w / 2 + 5, h / 2 - y_max * ((h - 20) / 4) + 10));
}


void ChartClass::UpdateFunctions(const int& w, const int& h)
{
    double dx = (x_max - x_min) / static_cast<double>(x_step);

    Function.clear();
    double x = x_min;
    for (int i = 0; i < 2 * x_step; i += 2)
    {
        Function.push_back(wxPoint(w / 2 + x * ((w - 20) / 2), h / 2. - GetFunctionValue(x) * ((h - 20) / 4)));
        x += dx;
        Function.push_back(wxPoint(w / 2 + x * ((w - 20) / 2), h / 2. - GetFunctionValue(x) * ((h - 20) / 4)));
    }
}


void ChartClass::DrawFunction(wxDC *dc)
{
    dc->SetPen(wxPen(RGB(0, 255, 0)));
    for (int i = 0; i < Function.size(); i += 2) dc->DrawLine(Function[i], Function[i + 1]);
}