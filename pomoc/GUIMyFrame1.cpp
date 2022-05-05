#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
	MyFrame1(parent), dc{ m_panel1 }
{
	dc.SetPen(wxPen(RGB(0, 0, 0)));
	time = 0;
	A = B = D = E = 1;
	C = F = 0;
	Draw();
}

void GUIMyFrame1::wxPanel_UpdateUI( wxUpdateUIEvent& event )
{
// TODO: Implement wxPanel_UpdateUI
//Draw();
}

void GUIMyFrame1::wxText_ChangeA( wxCommandEvent& event )
{
// TODO: Implement wxText_ChangeA
if (m_textCtrlA->GetValue().ToDouble(&A))
{
Draw();
}
}

void GUIMyFrame1::wxText_ChangeB( wxCommandEvent& event )
{
// TODO: Implement wxText_ChangeB
if (m_textCtrlB->GetValue().ToDouble(&B))
{
Draw();
}
}

void GUIMyFrame1::wxText_ChangeC( wxCommandEvent& event )
{
// TODO: Implement wxText_ChangeC
if (m_textCtrlC->GetValue().ToDouble(&C))
{
Draw();
}
}

void GUIMyFrame1::wxText_ChangeD( wxCommandEvent& event )
{
// TODO: Implement wxText_ChangeD
if (m_textCtrlD->GetValue().ToDouble(&D))
{
Draw();
}
}

void GUIMyFrame1::wxText_ChangeE( wxCommandEvent& event )
{
// TODO: Implement wxText_ChangeE
if (m_textCtrlE->GetValue().ToDouble(&E))
{
Draw();
}
}

void GUIMyFrame1::wxText_ChangeF( wxCommandEvent& event )
{
// TODO: Implement wxText_ChangeF
if (m_textCtrlF->GetValue().ToDouble(&F))
{
Draw();
}
}


void GUIMyFrame1::Draw()
{
	if (!IsRunning())
	{
		time = 0;
		dc.Clear();
		Start(20);
	}
}

void GUIMyFrame1::Notify()
{	
	dc.DrawLine(200 + 200 * (A * sin(B * time + C)), 200 - 200 * (D * cos(E * time + F)),
		200 + 200 * (A * sin(B * (time + 0.1) + C)), 200 - 200 * (D * cos(E * (time + 0.1) + F)));
	time += 0.1;
	if (time > 2 * PI) Stop();
}