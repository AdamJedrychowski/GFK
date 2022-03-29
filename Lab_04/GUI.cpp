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
	this->SetSizeHints( wxSize( 750,500 ), wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );

	bSizer2->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Układ Świata"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer3->Add( m_staticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("x0:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer6->Add( m_staticText2, 0, wxALL, 5 );

	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer6->Add( m_textCtrl1, 0, wxALL, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("y0:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALL, 5 );

	m_textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer6->Add( m_textCtrl2, 0, wxALL, 5 );


	bSizer3->Add( bSizer6, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("x1:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer7->Add( m_staticText4, 0, wxALL, 5 );

	m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer7->Add( m_textCtrl3, 0, wxALL, 5 );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("y1:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer7->Add( m_staticText5, 0, wxALL, 5 );

	m_textCtrl4 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer7->Add( m_textCtrl4, 0, wxALL, 5 );


	bSizer3->Add( bSizer7, 1, wxEXPAND, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Obrót"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer3->Add( m_staticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Alpha:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer71->Add( m_staticText9, 0, wxALL, 5 );

	m_scrollBar1 = new wxScrollBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSB_HORIZONTAL );
	bSizer71->Add( m_scrollBar1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer71->Add( m_staticText10, 0, wxALL, 5 );


	bSizer3->Add( bSizer71, 1, wxEXPAND, 5 );

	m_radioBtn1 = new wxRadioButton( this, wxID_ANY, wxT("Środek ekranu"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_radioBtn1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_radioBtn2 = new wxRadioButton( this, wxID_ANY, wxT("Środek układu"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_radioBtn2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Translacja o wektor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer3->Add( m_staticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("dX"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer8->Add( m_staticText11, 0, wxALL, 5 );

	m_textCtrl6 = new wxTextCtrl( this, wxID_ANY, wxT("0.0"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer8->Add( m_textCtrl6, 0, wxALL, 5 );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("dY"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer8->Add( m_staticText12, 0, wxALL, 5 );

	m_textCtrl7 = new wxTextCtrl( this, wxID_ANY, wxT("0.0"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer8->Add( m_textCtrl7, 0, wxALL, 5 );


	bSizer3->Add( bSizer8, 0, wxEXPAND, 5 );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Wartości na wykresie:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer3->Add( m_staticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("x_start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer9->Add( m_staticText13, 0, wxALL, 5 );

	m_textCtrl8 = new wxTextCtrl( this, wxID_ANY, wxT("-1.0"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer9->Add( m_textCtrl8, 0, wxALL, 5 );

	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("x_stop"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer9->Add( m_staticText14, 0, wxALL, 5 );

	m_textCtrl9 = new wxTextCtrl( this, wxID_ANY, wxT("2.0"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer9->Add( m_textCtrl9, 0, wxALL, 5 );


	bSizer3->Add( bSizer9, 0, wxEXPAND, 5 );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("y_min:  ? y_max:  ?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer3->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choice1Choices[] = { wxT("x+sin(4x)"), wxT("x^2"), wxT("0.5*e^(4x-3x^2)"), wxEmptyString, wxEmptyString, wxEmptyString };
	int m_choice1NChoices = sizeof( m_choice1Choices ) / sizeof( wxString );
	m_choice1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1NChoices, m_choice1Choices, 0 );
	m_choice1->SetSelection( 0 );
	bSizer3->Add( m_choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button1 = new wxButton( this, wxID_ANY, wxT("Do układu świata"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Wczytaj"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer10->Add( m_button2, 0, wxALL, 5 );

	m_button3 = new wxButton( this, wxID_ANY, wxT("Zapisz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_button3, 0, wxALL, 5 );


	bSizer3->Add( bSizer10, 1, wxEXPAND, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

MyFrame1::~MyFrame1()
{
}
