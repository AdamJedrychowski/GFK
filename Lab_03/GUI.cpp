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
	this->SetSizeHints( wxSize( 600,400 ), wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_panel3 = new wxPanel( this, wxID_Panel, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel3->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_panel3->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );

	bSizer4->Add( m_panel3, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	Button_SaveToFile = new wxButton( this, wxID_Save, wxT("Zapis do pliku"), wxDefaultPosition, wxSize( 150,40 ), 0 );
	bSizer3->Add( Button_SaveToFile, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	CheckBox_LoadBanan = new wxCheckBox( this, wxID_Banan, wxT("banan"), wxDefaultPosition, wxSize( 100,30 ), 0 );
	bSizer3->Add( CheckBox_LoadBanan, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	ScrollBar_MoveBanan = new wxScrollBar( this, wxID_Move, wxDefaultPosition, wxSize( 190,30 ), wxSB_HORIZONTAL );
	ScrollBar_MoveBanan->Enable( false );

	bSizer3->Add( ScrollBar_MoveBanan, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	Gauge_BananPosition = new wxGauge( this, wxID_Position, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	Gauge_BananPosition->SetValue( 0 );
	bSizer3->Add( Gauge_BananPosition, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	Button_StarColor = new wxButton( this, wxID_Color, wxT("kolor gwiazdki"), wxDefaultPosition, wxSize( 150,40 ), 0 );
	bSizer3->Add( Button_StarColor, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	TextCtrl_Write = new wxTextCtrl( this, wxID_Write, wxT("tekst"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( TextCtrl_Write, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString Choice_ElementChoices[] = { wxT("gwiazdka"), wxT("księżyc"), wxT("słonko") };
	int Choice_ElementNChoices = sizeof( Choice_ElementChoices ) / sizeof( wxString );
	Choice_Element = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, Choice_ElementNChoices, Choice_ElementChoices, 0 );
	Choice_Element->SetSelection( 0 );
	bSizer3->Add( Choice_Element, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_panel3->Connect( wxEVT_MOVE, wxMoveEventHandler( MyFrame1::UpdateScreen ), NULL, this );
	m_panel3->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::m_panel3OnPaint ), NULL, this );
	Button_SaveToFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::Button_SaveToFileOnButtonClick ), NULL, this );
	CheckBox_LoadBanan->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::CheckBox_LoadBananOnCheckBox ), NULL, this );
	ScrollBar_MoveBanan->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	Button_StarColor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::Button_StarColorOnButtonClick ), NULL, this );
	TextCtrl_Write->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::TextCtrl_WriteOnText ), NULL, this );
	Choice_Element->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::Choice_ElementOnChoice ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_panel3->Disconnect( wxEVT_MOVE, wxMoveEventHandler( MyFrame1::UpdateScreen ), NULL, this );
	m_panel3->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::m_panel3OnPaint ), NULL, this );
	Button_SaveToFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::Button_SaveToFileOnButtonClick ), NULL, this );
	CheckBox_LoadBanan->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::CheckBox_LoadBananOnCheckBox ), NULL, this );
	ScrollBar_MoveBanan->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	ScrollBar_MoveBanan->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::ScrollBar_MoveBananOnScroll ), NULL, this );
	Button_StarColor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::Button_StarColorOnButtonClick ), NULL, this );
	TextCtrl_Write->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::TextCtrl_WriteOnText ), NULL, this );
	Choice_Element->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::Choice_ElementOnChoice ), NULL, this );

}
