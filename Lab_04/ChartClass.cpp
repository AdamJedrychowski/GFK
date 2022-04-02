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
 PointTranslation(w, h, DrawChart);
 dc->SetPen(wxPen(RGB(0, 0, 255)));
 CutLinesAndDraw(w, h, dc, DrawChart);


 UpdateFunctions(w, h);
 PointTranslation(w, h, Function);
 dc->SetPen(wxPen(RGB(0, 255, 0)));
 CutLinesAndDraw(w, h, dc, Function);


 dc->DrawText(wxString::Format("%lf, %lf, %lf, %lf, %d", x_min, x_max, y_min, y_max, x_step), 20, 20);
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
    int yMax = h - 10, yMin = 10, xMax = w - 10, xMin = 10;

    for (int i = 0; i < tab.size(); i += 2)
    {
        A_bit.reset();
        B_bit.reset();
        // bit 3
        if (yMax - tab[i].y < 0) A_bit.set(3, 1);
        if (yMax - tab[i + 1].y < 0) B_bit.set(3, 1);

        // bit 2
        if (tab[i].y - yMin < 0) A_bit.set(2, 1);
        if (tab[i + 1].y - yMin < 0) B_bit.set(2, 1);

        //bit 1
        if (xMax - tab[i].x < 0) A_bit.set(1, 1);
        if (xMax - tab[i + 1].x < 0) B_bit.set(1, 1);

        //bit 0
        if (tab[i].x - xMin < 0) A_bit.set(0, 1);
        if (tab[i + 1].x - xMin < 0) B_bit.set(0, 1);////////////////////////check

        if (A_bit == 0 && B_bit == 0)
        {
            dc->DrawLine(tab[i], tab[i + 1]); // w obszarze
            continue;
        }
        else if ((A_bit & B_bit) != 0) continue; // poza obszarem
        
        A = tab[i];
        B = tab[i + 1];
        if (A_bit[0] || A_bit[1]) // poprawic przypadki gdy 2 bity sa ustawione
        {
            A.y = ((A_bit[0]) ? xMin : xMax) * (A.y - B.y) / ((double)A.x - B.x) + A.y - A.x * (A.y - B.y) / ((double)A.x - B.x);
            A.x = (A_bit[0]) ? xMin : xMax;
        }
        if (B_bit[0] || B_bit[1])
        {
            B.y = ((B_bit[0]) ? xMin : xMax) * (B.y - A.y) / ((double)B.x - A.x) + B.y - B.x * (B.y - A.y) / ((double)B.x - A.x);
            B.x = (B_bit[0]) ? xMin : xMax;
        }

        if (A_bit[2] || A_bit[3])
        {
            A.x = (A.x - B.x) * (((A_bit[2]) ? yMin : yMax) - A.y) / ((double)A.y - B.y) + A.x;
            A.y = (A_bit[2]) ? yMin : yMax;
        }
        if (B_bit[2] || B_bit[3])
        {
            B.x = (B.x - A.x) * (((B_bit[2]) ? yMin : yMax) - B.y) / ((double)B.y - A.y) + B.x;
            B.y = (B_bit[2]) ? yMin : yMax;
        }
        dc->DrawLine(A, B);
    }
}

void ChartClass::ChartAxes(const int &w, const int &h)
{
    DrawChart.clear();
    
    //double Xcorrelation = -cfg->Get_x0() / (-cfg->Get_x0() + cfg->Get_x1());
    //// osie wykresu
    //DrawChart.push_back(wxPoint(w / 2 + x_min / -cfg->Get_x0() * ((w - 20) / 2), h / 2));
    //DrawChart.push_back(wxPoint(w / 2 + x_max / cfg->Get_x1() * ((w - 20) / 2), h / 2));
    //DrawChart.push_back(wxPoint(w * Xcorrelation, h / 2 - y_min * ((h - 20) / 4)));
    //DrawChart.push_back(wxPoint(w * Xcorrelation, h / 2 - y_max * ((h - 20) / 4)));

    double Xcorrelation = fabs(cfg->Get_x0()) / (fabs(cfg->Get_x0()) + cfg->Get_x1());
    double Xunit_min = ((w * Xcorrelation) / (double)-cfg->Get_x0()),
        Xunit_max = ((w - 10 - w * Xcorrelation) / (double)cfg->Get_x1());
    // osie wykresu
    DrawChart.push_back(wxPoint(w * Xcorrelation + x_min * Xunit_min, h / 2));
    DrawChart.push_back(wxPoint(w * Xcorrelation + x_max * Xunit_max, h / 2));
    DrawChart.push_back(wxPoint(w * Xcorrelation, h / 2 - y_min * ((h - 20) / 4)));
    DrawChart.push_back(wxPoint(w * Xcorrelation, h / 2 - y_max * ((h - 20) / 4)));

    // podzialki na osi x
    DrawChart.push_back(wxPoint((w * Xcorrelation + w * Xcorrelation + x_min * Xunit_min) / 2., h / 2 - 5));
    DrawChart.push_back(wxPoint((w * Xcorrelation + w * Xcorrelation + x_min * Xunit_min) / 2., h / 2 + 5));
    DrawChart.push_back(wxPoint(w * Xcorrelation + (w * Xcorrelation + x_max * Xunit_max - w * Xcorrelation) / 3., h / 2 - 5));
    DrawChart.push_back(wxPoint(w * Xcorrelation + (w * Xcorrelation + x_max * Xunit_max - w * Xcorrelation) / 3., h / 2 + 5));
    DrawChart.push_back(wxPoint(w * Xcorrelation + (w * Xcorrelation + x_max * Xunit_max - w * Xcorrelation) * 2 / 3., h / 2 - 5));
    DrawChart.push_back(wxPoint(w * Xcorrelation + (w * Xcorrelation + x_max * Xunit_max - w * Xcorrelation) * 2 / 3., h / 2 + 5));

    // podzialki na osi y
    DrawChart.push_back(wxPoint(w * Xcorrelation - 5, h / 2 - y_min * ((h - 20) / 8)));
    DrawChart.push_back(wxPoint(w * Xcorrelation + 5, h / 2 - y_min * ((h - 20) / 8)));
    DrawChart.push_back(wxPoint(w * Xcorrelation - 5, h / 2 - y_max * ((h - 20) / 6)));
    DrawChart.push_back(wxPoint(w * Xcorrelation + 5, h / 2 - y_max * ((h - 20) / 6)));
    DrawChart.push_back(wxPoint(w * Xcorrelation - 5, h / 2 - y_max * ((h - 20) / 12)));
    DrawChart.push_back(wxPoint(w * Xcorrelation + 5, h / 2 - y_max * ((h - 20) / 12)));

    // zakonczenia wykresu (strza³ki)
    DrawChart.push_back(wxPoint(w * Xcorrelation + x_max * Xunit_max, h / 2));
    DrawChart.push_back(wxPoint(w * Xcorrelation + x_max * Xunit_max - 10, h / 2 - 5));
    DrawChart.push_back(wxPoint(w * Xcorrelation + x_max * Xunit_max, h / 2));
    DrawChart.push_back(wxPoint(w * Xcorrelation + x_max * Xunit_max - 10, h / 2 + 5));
    DrawChart.push_back(wxPoint(w * Xcorrelation, h / 2 - y_max * ((h - 20) / 4)));
    DrawChart.push_back(wxPoint(w * Xcorrelation - 5 , h / 2 - y_max * ((h - 20) / 4) + 10));
    DrawChart.push_back(wxPoint(w * Xcorrelation, h / 2 - y_max * ((h - 20) / 4)));
    DrawChart.push_back(wxPoint(w * Xcorrelation + 5, h / 2 - y_max * ((h - 20) / 4) + 10));
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


void ChartClass::PointTranslation(const int& w, const int& h, std::vector<wxPoint>& tab)
{
    Matrix Rotate;
    double angle = cfg->Get_Alpha() * M_PI / 180.;
    Rotate.data[0][0] = cos(angle);
    Rotate.data[0][1] = -sin(angle);
    Rotate.data[1][0] = sin(angle);
    Rotate.data[1][1] = cos(angle);
    Rotate.data[2][2] = 1;

    Matrix Move;
    Move.data[0][0] = 1;
    Move.data[1][1] = 1;
    Move.data[2][2] = 1;
    Move.data[0][2] = cfg->Get_dX();
    Move.data[1][2] = cfg->Get_dY();

    //Matrix Scale;
    //Scale.data[0][0] = cfg->Get_x0() + cfg->Get_x1() + 1;
    ////Scale.data[1][1] = cfg->Get_y1() / (-cfg->Get_y0() + cfg->Get_y1());
    //Scale.data[1][1] = 1;
    //Scale.data[2][2] = 1;

    Matrix Operations = Rotate * Move;

    Vector basic;
    for (int i = 0; i < tab.size(); i++)
    {
        basic.data[0] = tab[i].x;
        basic.data[1] = tab[i].y;
        basic.data[2] = 1;

        Vector temp = Operations * basic;

        tab[i].x = temp.data[0];
        tab[i].y = temp.data[1];
    }
}