#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
	Bind(wxEVT_PAINT, &GUIMyFrame1::m_panel1OnPaint, this);
}

void GUIMyFrame1::m_panel1OnPaint(wxPaintEvent& event)
{
	// TODO: Implement m_panel1OnPaint
	std::unique_ptr<wxPaintDC> MyDC(new wxPaintDC(this));

	MyDC->SetPen(wxPen(wxColour(255, 0, 0), 3, wxPENSTYLE_LONG_DASH));
	int x = this->GetSizer()->GetSize().x, y = this->GetSizer()->GetSize().y;
	MyDC->DrawLine(wxPoint(x / 2, y / 2), wxPoint(x / 2, y * 3 / 4.));
	MyDC->DrawLine(1, 1, 100, 100);

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
