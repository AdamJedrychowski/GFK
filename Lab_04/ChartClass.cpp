#include <wx/dc.h>
#include <memory>

#include "ChartClass.h"
#include "vecmat.h"

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c)
{
    cfg= std::move(c);
    x_step=200;

    Function.reserve(x_step * 2);
    Exp.reserve(x_step * 2);
    XSin.reserve(x_step * 2);
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
 for (int i = 0; i < DrawChart.size(); i += 2) dc->DrawLine(DrawChart[i], DrawChart[i + 1]);

 UpdateFunctions(w, h);
 DrawFunction(dc);

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

std::unique_ptr<wxPoint>&& ChartClass::CutTheLines(int w, int h)
{
    std::unique_ptr<wxPoint> lines(new wxPoint[DrawChart.size()]);

    std::bitset<4> bit;
    for (int i = 0; i < DrawChart.size(); i+=2)
    {
        if(-DrawChart[i].y)
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