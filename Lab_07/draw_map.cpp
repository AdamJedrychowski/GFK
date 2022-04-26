#include <wx/wx.h>
#include "GUIMyFrame1.h"
#include <vector>

float ShepardMethod(const wxRealPoint& A, const float (*GivenPoint)[3], int N)
{
    float weight, numerator = 0, denominator = 0;
    for (int i = 0; i < N; i++)
    {
        weight = 1 / abs((A.x - GivenPoint[i][0]) * (A.x - GivenPoint[i][0]) + (A.y - GivenPoint[i][1]) * (A.y - GivenPoint[i][1]));

        numerator += weight * GivenPoint[i][2];
        denominator += weight;
    }
    return numerator / denominator;
}


std::vector<std::vector<double>> Interpolation(const float(*GivenPoint)[3], int N)
{
    std::vector<std::vector<double>> tab;
    tab.resize(500);
    wxRealPoint A(-2.5, 2.5);
    for (int i = 0; i < 500; i++)
    {
        tab[i].resize(500);
        for (int j = 0; j < 500; j++)
        {
            tab[i][j] = ShepardMethod(A, GivenPoint, N);
            A.x += 0.01;
        }
        A.x = -2.5;
        A.y -= 0.01;
    }
    return tab;
}

void drawMap(unsigned char* data, std::vector<std::vector<double>> &InterpolationMap, float MinValue, float ScaleOfColor, int MappingType)
{
    float _R, _G, _B, MapColor;

    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        {
            if (data[0] == 0) continue;
            MapColor = (InterpolationMap[i][j] - MinValue) * ScaleOfColor;
            
            switch (MappingType)
            {
            case 1:
                _R = 255 - MapColor;
                _G = 0;
                _B = MapColor;
                break;
            case 2:
                _R = 255 - MapColor * 2;
                _G = (MapColor < 126) ? MapColor * 2 : 255 - (MapColor - 126) * 2;
                _B = (MapColor < 126) ? 0 : (MapColor - 126) * 2;
                break;
            case 3:
                _R = MapColor;
                _G = MapColor;
                _B = MapColor;
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

            data += 3;
        }
    }
}

void drawContour(unsigned char* data, std::vector<std::vector<double>>& InterpolationMap, int NoLevels, float *Levels)
{
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        {
            if (j < 499)
                for (int k = 0; k < NoLevels; k++)
                    if ((InterpolationMap[i][j] <= Levels[k] && Levels[k] <= InterpolationMap[i][j + 1]) ||
                        (InterpolationMap[i][j] >= Levels[k] && Levels[k] >= InterpolationMap[i][j + 1]))
                    {
                        data[0] = data[1] = data[2] = 0;
                    }

            if (i < 499)
                for (int k = 0; k < NoLevels; k++)
                    if ((InterpolationMap[i][j] <= Levels[k] && Levels[k] <= InterpolationMap[i + 1][j]) ||
                        (InterpolationMap[i][j] >= Levels[k] && Levels[k] >= InterpolationMap[i + 1][j]))
                    {
                        data[0] = data[1] = data[2] = 0;
                    }

            data += 3;
        }
    }
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
     float ScaleOfColor = 255 / (MaxValue - MinValue), Step;

     // Numbers of levels and their value
     Step = (MaxValue - MinValue) / (NoLevels + 1);
     Levels[0] = MinValue + Step;
     for (int i = 1; i < NoLevels; i++) Levels[i] = Levels[i - 1] + Step;
    

     // Creating complete image of map
     std::vector<std::vector<double>> InterpolationMap = Interpolation(d, N);
     
     image.Clear(255);
     unsigned char* data = image.GetData();

     // Draw Colored Map
     if (MappingType) drawMap(data, InterpolationMap, MinValue, ScaleOfColor, MappingType);
     // Draw Contour
     if (Contour) drawContour(data, InterpolationMap, NoLevels, Levels);

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
