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

	buttonReadFile = new wxButton( this, wxID_ANY, wxT("Wczytaj obrazek"), wxDefaultPosition, wxSize( 110,25 ), 0 );
	bSizer2->Add( buttonReadFile, 0, wxALIGN_CENTER|wxALL, 5 );

	buttonCenzura = new wxButton( this, wxID_ANY, wxT("Cenzura"), wxDefaultPosition, wxSize( 100,25 ), 0 );
	bSizer2->Add( buttonCenzura, 0, wxALIGN_CENTER|wxALL, 5 );

	buttonErode = new wxButton( this, wxID_ANY, wxT("Erode"), wxDefaultPosition, wxSize( 100,25 ), 0 );
	bSizer2->Add( buttonErode, 0, wxALIGN_CENTER|wxALL, 5 );

	checkBoxAnimation = new wxCheckBox( this, wxID_ANY, wxT("Animacja"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( checkBoxAnimation, 0, wxALIGN_CENTER|wxALL, 5 );

	ProgressIndicator = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	ProgressIndicator->SetValue( 0 );
	ProgressIndicator->Hide();

	bSizer2->Add( ProgressIndicator, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	AddText = new wxRichTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,-1 ), 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	AddText->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer2->Add( AddText, 1, wxALL|wxEXPAND, 5 );


	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	panelPhoto = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 800,533 ), wxTAB_TRAVERSAL );
	panelPhoto->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	panelPhoto->SetBackgroundColour( wxColour( 0, 0, 0 ) );

	bSizer3->Add( panelPhoto, 1, wxALL|wxEXPAND, 0 );


	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	buttonReadFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wxButton_ReadFile ), NULL, this );
	buttonCenzura->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wxButton_Censure ), NULL, this );
	buttonErode->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wxButton_Erode ), NULL, this );
	checkBoxAnimation->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::wxCheckBox_StartAnimation ), NULL, this );
	panelPhoto->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::wxPanel_Repaint ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	buttonReadFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wxButton_ReadFile ), NULL, this );
	buttonCenzura->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wxButton_Censure ), NULL, this );
	buttonErode->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wxButton_Erode ), NULL, this );
	checkBoxAnimation->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::wxCheckBox_StartAnimation ), NULL, this );
	panelPhoto->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::wxPanel_Repaint ), NULL, this );

}
