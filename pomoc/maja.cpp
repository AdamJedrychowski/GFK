///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "maja.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxVERTICAL);

	m_button1 = new wxButton(this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxSize(120, 20), 0);
	bSizer2->Add(m_button1, 0, wxALL, 5);

	m_textCtrl1 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(120, 20), 0);
	bSizer2->Add(m_textCtrl1, 0, wxALL, 5);

	m_slider1 = new wxSlider(this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize(120, 20), wxSL_HORIZONTAL);
	bSizer2->Add(m_slider1, 0, wxALL, 5);

	wxString m_choice1Choices[] = { wxT("Czerwony"), wxT("Bialy"), wxT("Czarny"), wxT("Zielony") };
	int m_choice1NChoices = sizeof(m_choice1Choices) / sizeof(wxString);
	m_choice1 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxSize(120, 20), m_choice1NChoices, m_choice1Choices, 0);
	m_choice1->SetSelection(0);
	bSizer2->Add(m_choice1, 0, wxALL, 5);


	bSizer1->Add(bSizer2, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxVERTICAL);

	m_panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

	bSizer3->Add(m_panel1, 1, wxEXPAND | wxALL, 5);


	bSizer1->Add(bSizer3, 1, wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	m_button1->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::Na_klik), NULL, this);
	m_textCtrl1->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MyFrame1::Na_wpisanie), NULL, this);
	m_slider1->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_choice1->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MyFrame1::Na_wybor), NULL, this);
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_button1->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::Na_klik), NULL, this);
	m_textCtrl1->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MyFrame1::Na_wpisanie), NULL, this);
	m_slider1->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_slider1->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame1::Na_ruch), NULL, this);
	m_choice1->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MyFrame1::Na_wybor), NULL, this);

}