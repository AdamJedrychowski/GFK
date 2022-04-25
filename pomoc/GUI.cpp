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

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 400,400 ), wxTAB_TRAVERSAL );
	m_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );

	bSizer2->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("A"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer4->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlA = new wxTextCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 40,25 ), 0 );
	bSizer4->Add( m_textCtrlA, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("B"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlB = new wxTextCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 40,25 ), 0 );
	bSizer5->Add( m_textCtrlB, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer3->Add( bSizer5, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("C"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlC = new wxTextCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 40,25 ), 0 );
	bSizer6->Add( m_textCtrlC, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer3->Add( bSizer6, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("D"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer7->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlD = new wxTextCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 40,25 ), 0 );
	bSizer7->Add( m_textCtrlD, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer3->Add( bSizer7, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("E"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer8->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlE = new wxTextCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 40,25 ), 0 );
	bSizer8->Add( m_textCtrlE, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer3->Add( bSizer8, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("F"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer9->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlF = new wxTextCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 40,25 ), 0 );
	bSizer9->Add( m_textCtrlF, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer3->Add( bSizer9, 1, wxEXPAND, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_panel1->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::wxPanel_UpdateUI ), NULL, this );
	m_textCtrlA->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::wxText_ChangeA ), NULL, this );
	m_textCtrlB->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::wxText_ChangeB ), NULL, this );
	m_textCtrlC->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::wxText_ChangeC ), NULL, this );
	m_textCtrlD->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::wxText_ChangeD ), NULL, this );
	m_textCtrlE->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::wxText_ChangeE ), NULL, this );
	m_textCtrlF->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::wxText_ChangeF ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_panel1->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::wxPanel_UpdateUI ), NULL, this );
	m_textCtrlA->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::wxText_ChangeA ), NULL, this );
	m_textCtrlB->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::wxText_ChangeB ), NULL, this );
	m_textCtrlC->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::wxText_ChangeC ), NULL, this );
	m_textCtrlD->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::wxText_ChangeD ), NULL, this );
	m_textCtrlE->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::wxText_ChangeE ), NULL, this );
	m_textCtrlF->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::wxText_ChangeF ), NULL, this );

}
