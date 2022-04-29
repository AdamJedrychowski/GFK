#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}

void GUIMyFrame1::wxButton_ReadFile( wxCommandEvent& event )
{
// TODO: Implement wxButton_ReadFile
	wxFileDialog OpenFileDialog(this, _("Choose a file"), _(""), _(""), _("(*.jpg)|*.jpg"), wxFD_OPEN);

	if (OpenFileDialog.ShowModal() == wxID_CANCEL) return;

	FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, OpenFileDialog.GetPath(), JPEG_DEFAULT);
	if (!bitmap) return;

	FITAG* tag = NULL;
	FIMETADATA* mdhandle = NULL;
	mdhandle = FreeImage_FindFirstMetadata(FIMD_EXIF_MAIN, bitmap, &tag);
	
	m_richText1->AppendText("Rozmiar obrazka: " + std::to_string(FreeImage_GetWidth(bitmap))
		+ "*" + std::to_string(FreeImage_GetHeight(bitmap)) + "\nEXIF Info:\n");
	if (mdhandle) {
		do {
			m_richText1->AppendText(std::string(FreeImage_GetTagKey(tag)) + ": " +
				std::string(FreeImage_TagToString(FIMD_EXIF_MAIN, tag)) + "\n");
		} while (FreeImage_FindNextMetadata(mdhandle, &tag));
	}
	FreeImage_FindCloseMetadata(mdhandle);


}

void GUIMyFrame1::wxButton_Censure( wxCommandEvent& event )
{
// TODO: Implement wxButton_Censure
}

void GUIMyFrame1::wxButton_Erode( wxCommandEvent& event )
{
// TODO: Implement wxButton_Erode
}

void GUIMyFrame1::wxCheckBox_StartAnimation( wxCommandEvent& event )
{
// TODO: Implement wxCheckBox_StartAnimation
}

void GUIMyFrame1::wxPanel_Repaint( wxUpdateUIEvent& event )
{
// TODO: Implement wxPanel_Repaint
}
