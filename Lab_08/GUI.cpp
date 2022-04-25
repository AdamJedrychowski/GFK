///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_button1 = new wxButton( this, wxID_ANY, wxT("Wczytaj obrazek"), wxDefaultPosition, wxSize( 110,25 ), 0 );
	bSizer2->Add( m_button1, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Cenzura"), wxDefaultPosition, wxSize( 100,25 ), 0 );
	bSizer2->Add( m_button2, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button3 = new wxButton( this, wxID_ANY, wxT("Erode"), wxDefaultPosition, wxSize( 100,25 ), 0 );
	bSizer2->Add( m_button3, 0, wxALIGN_CENTER|wxALL, 5 );

	m_checkBox1 = new wxCheckBox( this, wxID_ANY, wxT("Animacja"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_checkBox1, 0, wxALIGN_CENTER|wxALL, 5 );

	m_gauge1 = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	m_gauge1->SetValue( 0 );
	m_gauge1->Hide();

	bSizer2->Add( m_gauge1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_richText1 = new wxRichTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,-1 ), 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	m_richText1->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer2->Add( m_richText1, 1, wxALL|wxEXPAND, 5 );


	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 800,533 ), wxTAB_TRAVERSAL );
	m_panel2->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_panel2->SetBackgroundColour( wxColour( 0, 0, 0 ) );

	bSizer3->Add( m_panel2, 1, wxALL|wxEXPAND, 0 );


	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wxButton_ReadFile ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wxButton_Censure ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wxButton_Erode ), NULL, this );
	m_checkBox1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::wxCheckBox_StartAnimation ), NULL, this );
	m_panel2->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::wxPanel_Repaint ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wxButton_ReadFile ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wxButton_Censure ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wxButton_Erode ), NULL, this );
	m_checkBox1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::wxCheckBox_StartAnimation ), NULL, this );
	m_panel2->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::wxPanel_Repaint ), NULL, this );

}
