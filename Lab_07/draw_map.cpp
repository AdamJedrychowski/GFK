#include <wx/wx.h>
#include "GUIMyFrame1.h"
// UWAGA: TO JEST JEDYNY PLIK, KTORY NALEZY EDYTOWAC **************************

float ShepardMethod(const wxRealPoint& A, const float (*GivenPoint)[3], int N)
{
    long double weight, numerator = 0, denominator = 0;
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
     float ScaleOfColor = 255 / (MaxValue - MinValue), temp;

     // Numbers of levels and their value
     temp = (MaxValue - MinValue) / (NoLevels + 1);
     Levels[0] = MinValue + temp;
     //Levels[0] = floor(Levels[0] * 100) / 100.;
     for (int i = 1; i < NoLevels; i++) Levels[i] = Levels[i - 1] + temp;
    

     // Creating complete image of map
     image.Clear(255);
     unsigned char* data = image.GetData();
     wxRealPoint A(-2.5, 2.5), B(-2.49, 2.5), C(-2.5, 2.49);
     float Avalue, Bvalue, Cvalue, _R, _G, _B;
     Avalue = ShepardMethod(A, d, N);
     for (int i = 0; i < 250000; i++)
     {
         if(i && i%500==0)
         {
             C.x = A.x = -2.5;
             B.x = -2.49;
             B.y = A.y -= 0.01;
             C.y -= 0.01;
             
             Avalue = ShepardMethod(A, d, N);
         }
         Bvalue = ShepardMethod(B, d, N);
         
         
         temp = (Avalue - MinValue) * ScaleOfColor;

         if (MappingType)
         {
             switch (MappingType)
             {
             case 1:
                 _R = 255 - temp;
                 _G = 0;
                 _B = temp;
                 break;

             case 2:
                 _R = 255 - temp * 2;
                 _G = (temp < 126) ? temp * 2 : 255 - (temp - 126) * 2;
                 _B = (temp < 126) ? 0 : (temp - 126) * 2;
                 break;

             case 3:
                 _R = temp;
                 _G = temp;
                 _B = temp;
                 break;
             }
             if (_R < 0) _R = 0;
             else if (_R > 255) _R = 255;
             if (_G < 0) _G = 0;
             else if (_G > 255) _G = 255;
             if (_B < 0) _B = 0;
             else if (_B > 255) _B = 255;
             data[0] = _R;
             data[1] = _G;
             data[2] = _B;
         }


         if (Contour)
         {
             for(int j=0; j<NoLevels; j++)
                 if((Avalue <= Levels[j] && Levels[j] <= Bvalue) || (Avalue >= Levels[j] && Levels[j] >= Bvalue))
                 {
                     data[0] = data[1] = data[2] = 0;
                 }
             if (i < 249500)
             {
                 Cvalue = ShepardMethod(C, d, N);
                 for (int j = 0; j < NoLevels; j++)
                     if ((Avalue <= Levels[j] && Levels[j] <= Cvalue) || (Avalue >= Levels[j] && Levels[j] >= Cvalue))
                     {
                         data[0] = data[1] = data[2] = 0;
                     }
             }
         }

         C.x = A.x += 0.01;
         B.x += 0.01;
         Avalue = Bvalue;
         data += 3;
     }


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
             memDC.DrawLine(250 + 100 * d[i][0], 250 - 100 * d[i][1] - 3, 250 + 100 * d[i][0], 250 - 100 * d[i][1] + 4);
             memDC.DrawLine(250 + 100 * d[i][0] - 3, 250 - 100 * d[i][1], 250 + 100 * d[i][0] + 4, 250 - 100 * d[i][1]);
         }
     }
}
