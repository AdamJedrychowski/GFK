///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/checkbox.h>
#include <wx/scrolbar.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_Panel 1000
#define wxID_Save 1001
#define wxID_Banan 1002
#define wxID_Move 1003
#define wxID_Position 1004
#define wxID_Color 1005
#define wxID_Write 1006

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel3;
		wxButton* Button_SaveToFile;
		wxCheckBox* CheckBox_LoadBanan;
		wxScrollBar* ScrollBar_MoveBanan;
		wxGauge* Gauge_BananPosition;
		wxButton* Button_StarColor;
		wxTextCtrl* TextCtrl_Write;
		wxChoice* Choice_Element;

		// Virtual event handlers, override them in your derived class
		virtual void UpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void Button_SaveToFileOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void CheckBox_LoadBananOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void ScrollBar_MoveBananOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void Button_StarColorOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void TextCtrl_WriteOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void Choice_ElementOnChoice( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GFK Lab 03"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxCAPTION|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU|wxTAB_TRAVERSAL );

		~MyFrame1();

};

