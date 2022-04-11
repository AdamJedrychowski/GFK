#include "majaMyFrame1.h"
#include <iostream>
#include <string>

majaMyFrame1::majaMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	SquarePosition = 100;
}

void majaMyFrame1::Na_klik(wxCommandEvent& event)
{
	m_button1->SetLabelText("OK");
}

void majaMyFrame1::Na_wpisanie(wxCommandEvent& event)
{

	wxClientDC dc(m_panel1);
	dc.Clear();
	int a = m_slider1->GetValue();
	std::string tekst = std::to_string(a);
	dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
	dc.DrawText(tekst, 100, 120);
	if (m_choice1->GetSelection() == 0)
	{
		dc.Clear();
		int a = m_slider1->GetValue();
		std::string tekst = std::to_string(a);
		dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
		dc.DrawText(tekst, 100, 120);
		dc.SetBrush(wxColor(255, 0, 0));
		dc.DrawRectangle(SquarePosition, 150, 50, 50);
	}
	else if (m_choice1->GetSelection() == 1)
	{
		dc.Clear();
		int a = m_slider1->GetValue();
		std::string tekst = std::to_string(a);
		dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
		dc.DrawText(tekst, 100, 120);
		dc.SetBrush(wxColor(255, 255, 255));
		dc.DrawRectangle(SquarePosition, 150, 50, 50);
	}
	else if (m_choice1->GetSelection() == 2)
	{

		dc.Clear();
		int a = m_slider1->GetValue();
		std::string tekst = std::to_string(a);
		dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
		dc.DrawText(tekst, 100, 120);
		dc.SetBrush(wxColor(0, 0, 0));
		dc.DrawRectangle(SquarePosition, 150, 50, 50);
	}
	else if (m_choice1->GetSelection() == 3)
	{
		dc.Clear();
		int a = m_slider1->GetValue();
		std::string tekst = std::to_string(a);
		dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
		dc.DrawText(tekst, 100, 120);
		dc.SetBrush(wxColor(0, 255, 0));
		dc.DrawRectangle(SquarePosition, 150, 50, 50);
	}
}

void majaMyFrame1::Na_ruch(wxScrollEvent& event)
{
	wxClientDC dc(m_panel1);
	dc.Clear();
	int a = m_slider1->GetValue();
	SquarePosition = 100 + a;
	std::string tekst = std::to_string(a);
	dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
	dc.DrawText(tekst, 100, 120);
	if (m_choice1->GetSelection() == 0)
	{
		dc.Clear();
		int a = m_slider1->GetValue();
		std::string tekst = std::to_string(a);
		dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
		dc.DrawText(tekst, 100, 120);
		dc.SetBrush(wxColor(255, 0, 0));
		dc.DrawRectangle(SquarePosition, 150, 50, 50);
	}
	else if (m_choice1->GetSelection() == 1)
	{
		dc.Clear();
		int a = m_slider1->GetValue();
		std::string tekst = std::to_string(a);
		dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
		dc.DrawText(tekst, 100, 120);
		dc.SetBrush(wxColor(255, 255, 255));
		dc.DrawRectangle(SquarePosition, 150, 50, 50);
	}
	else if (m_choice1->GetSelection() == 2)
	{

		dc.Clear();
		int a = m_slider1->GetValue();
		std::string tekst = std::to_string(a);
		dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
		dc.DrawText(tekst, 100, 120);
		dc.SetBrush(wxColor(0, 0, 0));
		dc.DrawRectangle(SquarePosition, 150, 50, 50);
	}
	else if (m_choice1->GetSelection() == 3)
	{
		dc.Clear();
		int a = m_slider1->GetValue();
		std::string tekst = std::to_string(a);
		dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
		dc.DrawText(tekst, 100, 120);
		dc.SetBrush(wxColor(0, 255, 0));
		dc.DrawRectangle(SquarePosition, 150, 50, 50);
	}
}

void majaMyFrame1::Na_wybor(wxCommandEvent& event)
{
	wxClientDC dc(m_panel1);
	if (m_choice1->GetSelection() == 0)
	{
		dc.Clear();
		int a = m_slider1->GetValue();
		std::string tekst = std::to_string(a);
		dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
		dc.DrawText(tekst, 100, 120);
		dc.SetBrush(wxColor(255,0,0));
		dc.DrawRectangle(SquarePosition, 150, 50, 50);
	}
	else if (m_choice1->GetSelection() == 1)
	{
		dc.Clear();
		int a = m_slider1->GetValue();
		std::string tekst = std::to_string(a);
		dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
		dc.DrawText(tekst, 100, 120);
		dc.SetBrush(wxColor(255, 255, 255));
		dc.DrawRectangle(SquarePosition, 150, 50, 50);
	}
	else if (m_choice1->GetSelection() == 2)
	{

		dc.Clear();
		int a = m_slider1->GetValue();
		std::string tekst = std::to_string(a);
		dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
		dc.DrawText(tekst, 100, 120);
		dc.SetBrush(wxColor(0, 0, 0));
		dc.DrawRectangle(SquarePosition, 150,50, 50);
	}
	else if (m_choice1->GetSelection() == 3)
	{
		dc.Clear();
		int a = m_slider1->GetValue();
		std::string tekst = std::to_string(a);
		dc.DrawText(m_textCtrl1->GetValue(), 100, 100);
		dc.DrawText(tekst, 100, 120);
		dc.SetBrush(wxColor(0, 255, 0));
		dc.DrawRectangle(SquarePosition, 150, 50, 50);
	}
}
