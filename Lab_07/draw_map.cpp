#include <wx/wx.h>
#include "GUIMyFrame1.h"
// UWAGA: TO JEST JEDYNY PLIK, KTORY NALEZY EDYTOWAC **************************

float ShepardMethod(const wxRealPoint& A, const float (*GivenPoint)[3], int N)
{
    float square, weight, numerator = 0, denominator = 0;
    for (int i = 0; i < N; i++)
    {
        weight = 1 / abs((A.x - GivenPoint[i][0]) * (A.x - GivenPoint[i][0]) + (A.y - GivenPoint[i][1]) * (A.y - GivenPoint[i][1]));

        numerator += weight * GivenPoint[i][2];
        denominator += weight;
    }
    return numerator / denominator;
}

void GUIMyFrame1::DrawMap(int N, float d[100][3], bool Contour, int MappingType, int NoLevels, bool ShowPoints)
{

     // Minnimal and Maximal value
     float MinValue = d[0][2], MaxValue = d[0][2], Levels[9];
     for (int i = 1; i < N; i++)
     {
         if (MinValue > d[i][2]) MinValue = d[i][2];
         if (MaxValue < d[i][2]) MaxValue = d[i][2];
     }
     float ScaleOfColor = (MaxValue - MinValue) / 255.;

     // Numbers of levels and their value
     Levels[0] = MinValue + (MaxValue - MinValue) / (NoLevels + 1);
     Levels[0] = floor(Levels[0] * 100) / 100.;
     for (int i = 1; i < NoLevels; i++) Levels[i] = Levels[i - 1] + Levels[0];
    

     // Creating complete image of map
     image.Clear(255);
     unsigned char* data = image.GetData();
     wxRealPoint A(-2.5, 2.5);
     float Avalue, temp;
     for (int i = 0; i < 250000; i++)
     {
         Avalue = ShepardMethod(A, d, N);

         switch (MappingType)
         {
         case 1:
             temp = Avalue * ScaleOfColor;
             data[1] = 0;
             if (temp > 255)
             {
                 data[0] = 255;
                 data[2] = 0;
             }
             else if (temp < 0)
             {
                 data[0] = 0;
                 data[2] = 255;
             }
             else
             {
                 data[0] = temp;
                 data[2] = 255 - temp;
             }
             break;

         case 2:

             break;

         case 3:

             break;
         }

         if (Contour)
         {
             for(int j=0; j<NoLevels; j++)
                 if (Avalue < Levels[j] + 0.01 && Avalue > Levels[j] - 0.01)
                 //if(Avalue == Levels[j])
                 {
                     data[0] = data[1] = data[2] = 0;
                 }
         }

         A.x += 0.01;
         //if (A.x >= 2.5)
         if(i%500==0)
         {
             A.x = -2.5;
             A.y -= 0.01;
         }
         data += 3;
     }
     //MemoryBitmap = wxBitmap(image);

     wxMemoryDC memDC;
     memDC.SelectObject(MemoryBitmap);
     memDC.SetBackground(*wxWHITE_BRUSH);
     memDC.Clear();
     memDC.SetPen(*wxBLACK_PEN);
     memDC.SetBrush(*wxTRANSPARENT_BRUSH);
     memDC.DrawBitmap(wxBitmap(image), 0, 0);
    
     // Drawing points
     if (ShowPoints)
     {
         for (int i = 0; i < N; i++)
         {
             //memDC.DrawText(wxString::Format("%lf, %lf", d[i][0], d[i][1]), wxPoint(10, 80+i*20));
             memDC.DrawLine(250 + 100 * d[i][0], 250 - 100 * d[i][1] - 3, 250 + 100 * d[i][0], 250 - 100 * d[i][1] + 4);
             memDC.DrawLine(250 + 100 * d[i][0] - 3, 250 - 100 * d[i][1], 250 + 100 * d[i][0] + 4, 250 - 100 * d[i][1]);
         }
     }

     if (MappingType == 1) memDC.DrawText("Mapa niebiesko-czerwona...", wxPoint(10, 30));
     if (MappingType == 2) memDC.DrawText("Mapa niebiesko-zielono-czerwona...", wxPoint(10, 30));
     if (MappingType == 3) memDC.DrawText("Mapa szara...", wxPoint(10, 30));
     if (Contour) memDC.DrawText("Kontury...", wxPoint(10, 10));
     if (ShowPoints) memDC.DrawText("Punkty...", wxPoint(10, 50));
}
