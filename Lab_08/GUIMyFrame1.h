#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include
#include <wx/filedlg.h>
#include <FreeImage.h>
#include <vector>
#include <wx/richtext/richtextctrl.h>
/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
	protected:
		// Handlers for MyFrame1 events.
		void wxButton_ReadFile( wxCommandEvent& event );
		void wxButton_Censure( wxCommandEvent& event );
		void wxButton_Erode( wxCommandEvent& event );
		void wxCheckBox_StartAnimation( wxCommandEvent& event );
		void wxPanel_Repaint( wxUpdateUIEvent& event );
	public:
		/** Constructor */
		GUIMyFrame1( wxWindow* parent );
	//// end generated class members

};

#endif // __GUIMyFrame1__
