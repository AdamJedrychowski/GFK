#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}

void GUIMyFrame1::wxButton_ReadFile( wxCommandEvent& event )
{
// TODO: Implement wxButton_ReadFile
<<<<<<< HEAD
	wxFileDialog OpenFileDialog(this, _("Choose a file"), _(""), _(""), _("Obraz JPEG (*.jpg)|*.jpg"), wxFD_OPEN);
	if (OpenFileDialog.ShowModal() == wxID_CANCEL) return;

	FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, OpenFileDialog.GetPath(), JPEG_DEFAULT);
	//if (bitmap) {
	//	// bitmap successfully loaded!
	//	FITAG* tag = NULL;
	//	FIMETADATA* mdhandle=NULL;// = FreeImage_FindFirstMetadata(FIMD_EXIF_MAIN, bitmap, &tag);
	//	std::string delim = ": ";
	//
	//	if (mdhandle) {

	//		do {
	//			// convert the tag value to a string
	//			const char* value = FreeImage_TagToString(FIMD_EXIF_MAIN, tag);
	//			// print the tag
	//			// note that most tags do not have a description,
	//			// especially when the metadata specifications are not available
	//			if (FreeImage_GetTagDescription(tag)) {
	//				std::string s = "";
	//				s.append(FreeImage_GetTagKey(tag));
	//				s.append(delim);
	//				s.append(value);
	//				s.append(delim);
	//				s.append(FreeImage_GetTagDescription(tag));
	//				//metadata.push_back(s);
	//			}
	//			else {
	//				std::string s = "";
	//				s.append(FreeImage_GetTagKey(tag));
	//				s.append(delim);
	//				s.append(value);
	//				s.append(delim);
	//				s.append(" ");
	//				//metadata.push_back(s);
	//			}
	//		} while (FreeImage_FindNextMetadata(mdhandle, &tag));
	//	}

	//	FreeImage_FindCloseMetadata(mdhandle);


	//	FreeImage_Unload(bitmap);
	//}
=======
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


>>>>>>> meta data
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
