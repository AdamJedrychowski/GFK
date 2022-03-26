#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
	Bind(wxEVT_PAINT, &GUIMyFrame1::m_panel3OnPaint, this);
}

void GUIMyFrame1::m_panel3OnPaint( wxPaintEvent& event )
{
// TODO: Implement m_panel3OnPaint
	std::unique_ptr<wxClientDC> MyDC(new wxClientDC(m_panel3));
	MyDC->Clear();

	int x = m_panel3->GetSize().x, y = m_panel3->GetSize().y;

	//person
	MyDC->DrawLine(x / 2, y / 2 - 10, x / 2, y / 2 + 60);
	MyDC->DrawLine(x / 2, y / 2, x / 2 + 40, y / 2 + 20);
	MyDC->DrawLine(x / 2, y / 2, x / 2 - 40, y / 2 + 20);
	MyDC->DrawLine(x / 2, y / 2 + 60, x / 2 + 30, y / 2 + 90);
	MyDC->DrawLine(x / 2, y / 2 + 60, x / 2 - 30, y / 2 + 90);

	//head
	MyDC->DrawCircle(x / 2, y / 2 - 30, 20);
	MyDC->DrawEllipse(x / 2 - 12, y / 2 - 38, 9, 6);
	MyDC->DrawEllipse(x / 2 + 4, y / 2 - 40, 6, 9);
	MyDC->DrawEllipticArc(x / 2 - 15, y / 2 - 25, 30, 10, 0, 180);

	//text uzupe³nic o value
	MyDC->DrawText("tekst", x / 2 - 100, y / 2 + 80);
	MyDC->SetFont(wxFont(wxFontInfo(30).Family(wxFONTFAMILY_SCRIPT).Bold().Slant()));
	MyDC->DrawRotatedText("tekst", x / 2 + 70, y / 2 + 90, 90);

	//star
	wxPoint CreateStar[5] = { wxPoint(x / 2 - 80, y / 2 - 100), wxPoint(x / 2 - 60, y / 2 - 50),
		wxPoint(x / 2 - 110, y / 2 - 80), wxPoint(x / 2 - 50, y / 2 - 80), wxPoint(x / 2 - 100, y / 2 - 50) };
	MyDC->SetBrush(wxBrush(wxColour(0, 0, 0), wxBRUSHSTYLE_SOLID));
	MyDC->DrawPolygon(5, CreateStar);
}

void GUIMyFrame1::Button_SaveToFileOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement Button_SaveToFileOnButtonClick
}

void GUIMyFrame1::CheckBox_LoadBananOnCheckBox( wxCommandEvent& event )
{
// TODO: Implement CheckBox_LoadBananOnCheckBox
}

void GUIMyFrame1::ScrollBar_MoveBananOnScroll( wxScrollEvent& event )
{
// TODO: Implement ScrollBar_MoveBananOnScroll
}

void GUIMyFrame1::Button_StarColorOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement Button_StarColorOnButtonClick
}

void GUIMyFrame1::TextCtrl_WriteOnText( wxCommandEvent& event )
{
// TODO: Implement TextCtrl_WriteOnText
}

void GUIMyFrame1::Choice_ElementOnChoice( wxCommandEvent& event )
{
// TODO: Implement Choice_ElementOnChoice
}
