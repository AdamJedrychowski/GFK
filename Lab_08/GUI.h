///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/gauge.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxButton* buttonReadFile;
		wxButton* buttonCenzura;
		wxButton* buttonErode;
		wxCheckBox* checkBoxAnimation;
		wxGauge* ProgressIndicator;
		wxRichTextCtrl* AddText;
		wxPanel* panelPhoto;

		// Virtual event handlers, override them in your derived class
		virtual void wxButton_ReadFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void wxButton_Censure( wxCommandEvent& event ) { event.Skip(); }
		virtual void wxButton_Erode( wxCommandEvent& event ) { event.Skip(); }
		virtual void wxCheckBox_StartAnimation( wxCommandEvent& event ) { event.Skip(); }
		virtual void wxPanel_Repaint( wxUpdateUIEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GFK Lab 08"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1100,533 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

