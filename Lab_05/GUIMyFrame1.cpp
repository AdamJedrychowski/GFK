#include "GUIMyFrame1.h"
#include <vector>
#include <fstream>
#include "vecmat.h"
#include <cmath>
#define M_PI 3.141592653589

struct Point {
 float x, y, z;
 Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

struct Color {
 int R, G, B;
 Color(int _R, int _G, int _B) : R(_R), G(_G), B(_B) {}
 operator wxColour() { return wxColour(R, G, B); }
};

struct Segment {
 Point begin, end;
 Color color;
 Segment(Point _begin, Point _end, Color _color) : begin(_begin), end(_end), color(_color) {}
};

std::vector<Segment> data;

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
 m_button_load_geometry->SetLabel(_("Wczytaj Geometri\u0119"));
 m_staticText25->SetLabel(_("Obr\u00F3t X:"));
 m_staticText27->SetLabel(_("Obr\u00F3t Y:"));
 m_staticText29->SetLabel(_("Obr\u00F3t Z:"));

 WxSB_TranslationX->SetRange(0, 200); WxSB_TranslationX->SetValue(100);
 WxSB_TranslationY->SetRange(0, 200); WxSB_TranslationY->SetValue(100);
 WxSB_TranslationZ->SetRange(0, 200); WxSB_TranslationZ->SetValue(100);

 WxSB_RotateX->SetRange(0, 360); WxSB_RotateX->SetValue(0);
 WxSB_RotateY->SetRange(0, 360); WxSB_RotateY->SetValue(0);
 WxSB_RotateZ->SetRange(0, 360); WxSB_RotateZ->SetValue(0);

 WxSB_ScaleX->SetRange(1, 200); WxSB_ScaleX->SetValue(100);
 WxSB_ScaleY->SetRange(1, 200); WxSB_ScaleY->SetValue(100);
 WxSB_ScaleZ->SetRange(1, 200); WxSB_ScaleZ->SetValue(100);
}

void GUIMyFrame1::WxPanel_Repaint( wxUpdateUIEvent& event )
{
 Repaint();
}

void GUIMyFrame1::m_button_load_geometry_click( wxCommandEvent& event )
{
 wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Geometry file (*.geo)|*.geo"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

 if (WxOpenFileDialog.ShowModal() == wxID_OK)
 {
  double x1, y1, z1, x2, y2, z2;
  int r, g, b;

  std::ifstream in(WxOpenFileDialog.GetPath().ToAscii());
  if (in.is_open())
  {
   data.clear();
   while (!in.eof())
   {
    in >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> r >> g >> b;
    data.push_back(Segment(Point(x1, y1, z1), Point(x2, y2, z2), Color(r, g, b)));
   }
   in.close();
  }
 }
}

void GUIMyFrame1::Scrolls_Updated( wxScrollEvent& event )
{
WxST_TranslationX->SetLabel(wxString::Format(wxT("%g"), (WxSB_TranslationX->GetValue() - 100) / 50.0));
WxST_TranslationY->SetLabel(wxString::Format(wxT("%g"), (WxSB_TranslationY->GetValue() - 100) / 50.0));
WxST_TranslationZ->SetLabel(wxString::Format(wxT("%g"), (WxSB_TranslationZ->GetValue() - 100) / 50.0));

WxST_RotateX->SetLabel(wxString::Format(wxT("%d"), WxSB_RotateX->GetValue()));
WxST_RotateY->SetLabel(wxString::Format(wxT("%d"), WxSB_RotateY->GetValue()));
WxST_RotateZ->SetLabel(wxString::Format(wxT("%d"), WxSB_RotateZ->GetValue()));

WxST_ScaleX->SetLabel(wxString::Format(wxT("%g"), WxSB_ScaleX->GetValue() / 100.0));
WxST_ScaleY->SetLabel(wxString::Format(wxT("%g"), WxSB_ScaleY->GetValue() / 100.0));
WxST_ScaleZ->SetLabel(wxString::Format(wxT("%g"), WxSB_ScaleZ->GetValue() / 100.0));


Repaint();
}

Matrix4 TranslationMatrix(double x, double y, double z)
{
    Matrix4 Trans;
    Trans.data[0][0] = 1.;
    Trans.data[1][1] = 1.;
    Trans.data[2][2] = 1.;
    Trans.data[3][3] = 1.;
    Trans.data[0][3] = x;
    Trans.data[1][3] = y;
    Trans.data[2][3] = z;

    return Trans;
}

Matrix4 RotateMartix(int x, int y, int z)
{
    Matrix4 RotX;
    RotX.data[0][0] = 1.;
    RotX.data[3][3] = 1.;
    RotX.data[1][1] = cos(x * M_PI / 180.);
    RotX.data[1][2] = -sin(x * M_PI / 180.);
    RotX.data[2][1] = sin(x * M_PI / 180.);
    RotX.data[2][2] = cos(x * M_PI / 180.);

    Matrix4 RotY;
    RotY.data[1][1] = 1.;
    RotY.data[3][3] = 1.;
    RotY.data[0][0] = cos(y * M_PI / 180.);
    RotY.data[0][2] = sin(y * M_PI / 180.);
    RotY.data[2][0] = -sin(y * M_PI / 180.);
    RotY.data[2][2] = cos(y * M_PI / 180.);

    Matrix4 RotZ;
    RotZ.data[2][2] = 1.;
    RotZ.data[3][3] = 1.;
    RotZ.data[0][0] = cos(z * M_PI / 180.);
    RotZ.data[0][1] = -sin(z * M_PI / 180.);
    RotZ.data[1][0] = sin(z * M_PI / 180.);
    RotZ.data[1][1] = cos(z * M_PI / 180.);

    return RotX * RotY * RotZ;
}

Matrix4 ScaleMatrix(double x, double y, double z)
{
    Matrix4 Scale;
    Scale.data[0][0] = x;
    Scale.data[1][1] = y;
    Scale.data[2][2] = z;
    Scale.data[3][3] = 1.;

    return Scale;
}

Point MakeOperations(Point A, Matrix4 &Trans, Matrix4 &Rot, Matrix4 &Scale)
{
    Vector4 XYZ;
    XYZ.Set(A.x, A.y, A.z);

    XYZ = Trans * Rot * Scale * XYZ;

    return Point(XYZ.GetX(), XYZ.GetY(), XYZ.GetZ());
}

void GUIMyFrame1::Repaint()
{
    wxClientDC dc1(WxPanel);
    wxBufferedDC dc(&dc1);
    dc.Clear();
    int width, height;
    dc.GetSize(&width, &height);

    Matrix4 Translation = TranslationMatrix((WxSB_TranslationX->GetValue() - 100.) / 50.,
        (WxSB_TranslationY->GetValue() - 100.) / 50., (WxSB_TranslationZ->GetValue() - 100.) / 50.);

    Matrix4 Rotate = RotateMartix(WxSB_RotateX->GetValue(),
        WxSB_RotateY->GetValue(), WxSB_RotateZ->GetValue());

    Matrix4 Scale = ScaleMatrix(WxSB_ScaleX->GetValue() / 100.,
        WxSB_ScaleY->GetValue() / 100., WxSB_ScaleZ->GetValue() / 100.);


    for (Segment& it : data)
    {
        it.color.R = 127 + it.begin.y * 128;
        it.color.B = 127 - it.begin.y * 128;

        Point Begin = MakeOperations(it.begin, Translation, Rotate, Scale),
            End = MakeOperations(it.end, Translation, Rotate, Scale);

        wxPoint A(width / 2 * (1 + (Begin.x * 2.0) / (Begin.z + 2.0)), height / 2 * (1 - (Begin.y * 2.0) / (Begin.z + 2.0))),
            B(width / 2 * (1 + (End.x * 2.0) / (End.z + 2.0)), height / 2 * (1 - (End.y * 2.0) / (End.z + 2.0)));

        
        dc.SetPen(wxPen(it.color));
        dc.DrawLine(A, B);
    }
}
