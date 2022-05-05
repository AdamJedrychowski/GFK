#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent), width{ 800 }, height{ 533 }
{
	ProgressIndicator->Show(false);
}


void Convert_CImg_To_wxImage(wxImage& wximage, CImg<unsigned char>& cimg, int w, int h)
{
	unsigned char* data = wximage.GetData();
	for (int j = 0; j < h; j++)
		for (int i = 0; i < w; i++)
		{
			data[0] = cimg(i, j, 0);
			data[1] = cimg(i, j, 1);
			data[2] = cimg(i, j, 2);
			data += 3;
		}
}


void GUIMyFrame1::wxButton_ReadFile(wxCommandEvent& event)
{
	// TODO: Implement wxButton_ReadFile
	wxFileDialog OpenFileDialog(this, _("Choose a file"), _(""), _(""), _("Obraz JPEG (*.jpg)|*.jpg"), wxFD_OPEN);

	if (OpenFileDialog.ShowModal() == wxID_CANCEL) return;

	FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, OpenFileDialog.GetPath(), JPEG_DEFAULT);
	if (!bitmap) return;

	FITAG* tag = NULL;
	FIMETADATA* mdhandle = NULL;
	mdhandle = FreeImage_FindFirstMetadata(FIMD_EXIF_MAIN, bitmap, &tag);

	AddText->AppendText("Rozmiar obrazka: " + std::to_string(FreeImage_GetWidth(bitmap))
		+ "*" + std::to_string(FreeImage_GetHeight(bitmap)) + "\nEXIF Info:\n");
	if (mdhandle) {
		do {
			AddText->AppendText(std::string(FreeImage_GetTagKey(tag)) + ": " +
				std::string(FreeImage_TagToString(FIMD_EXIF_MAIN, tag)) + "\n");
		} while (FreeImage_FindNextMetadata(mdhandle, &tag));
	}
	FreeImage_FindCloseMetadata(mdhandle);

	std::unique_ptr<RGBQUAD> data=std::make_unique<RGBQUAD>();
	OrginalPhoto.assign(FreeImage_GetWidth(bitmap), FreeImage_GetHeight(bitmap), 1, 3);
	for (int j = 0; j < OrginalPhoto.height(); j++)
		for (int i = 0; i < OrginalPhoto.width(); i++)
		{
			FreeImage_GetPixelColor(bitmap, i, OrginalPhoto.height() - j - 1, data.get());
			OrginalPhoto(i, j, 0) = data->rgbRed;
			OrginalPhoto(i, j, 1) = data->rgbGreen;
			OrginalPhoto(i, j, 2) = data->rgbBlue;
		}

	panelPhoto->GetSize(&width, &height);
	EditedPhoto = OrginalPhoto;
	EditedPhoto.resize(width, height);
	FreeImage_Unload(bitmap);

	Draw();
}


void GUIMyFrame1::wxButton_Censure(wxCommandEvent& event)
{
	// TODO: Implement wxButton_Censure
	if (EditedPhoto && !checkBoxAnimation->IsChecked())
	{
		EditedPhoto = OrginalPhoto;
		EditedPhoto.resize(width, height);
		CImg<unsigned char> temp = OrginalPhoto.get_crop(460, 15, 580, 90).blur(3.5).resize(width * 120 / OrginalPhoto.width(), height * 75 / OrginalPhoto.height());
		EditedPhoto.draw_image(0.575 * width, 0.0281426 * height, temp);
		Draw();
	}
}


void GUIMyFrame1::wxButton_Erode(wxCommandEvent& event)
{
	// TODO: Implement wxButton_Erode
	if (EditedPhoto && !checkBoxAnimation->IsChecked())
	{
		EditedPhoto = OrginalPhoto.get_erode(7);
		EditedPhoto.resize(width, height);
		Draw();
	}
}


void GUIMyFrame1::wxCheckBox_StartAnimation(wxCommandEvent& event)
{
	// TODO: Implement wxCheckBox_StartAnimation
	if (EditedPhoto && checkBoxAnimation->IsChecked())
	{
		ProgressIndicator->Show();
		Layout();

		int w = OrginalPhoto.width(), h = OrginalPhoto.height();
		CImg<float> gauss1(w, h, 1, 3), gauss2(w, h, 1, 3);
		float color[3]{ 1.0f, 1.0f, 1.0f };
		AnimationArray.resize(90);
		for (int i = 0; i < 90; i++)
		{
			ProgressIndicator->SetValue(i * 100 / 180.);
			EditedPhoto = OrginalPhoto;
			gauss1.draw_gaussian(w / 2. - w / 4. * cos(i * PI / 45.), h / 2. - w / 4. * sin(i * PI / 45.), 130.0f, color, 1.0f);
			gauss2.draw_gaussian(w / 2. + w / 4. * cos(i * PI / 45.), h / 2. + w / 4. * sin(i * PI / 45.), 130.0f, color, 1.0f);
			EditedPhoto.mul(gauss1 + gauss2);

			AnimationArray[i].Create(w, h);
			Convert_CImg_To_wxImage(AnimationArray[i], EditedPhoto, w, h);
		}

		ProgressIndicator->Hide();
		Layout();

		Start(1);
	}
}


void GUIMyFrame1::Notify()
{
	static float frame = 0;
	if (!checkBoxAnimation->IsChecked())
	{
		AnimationArray.clear();
		frame = 0;
		Stop();
		return;
	}

	wxClientDC dc(panelPhoto);
	dc.DrawBitmap(wxBitmap(AnimationArray[frame].Scale(width, height)), 0, 0);
	if (frame == 89) frame = 0;
	else frame++;
	
}


void GUIMyFrame1::ChangePhotoSize(wxSizeEvent& event)
{
	// TODO: Implement ChangePhotoSize
	if (OrginalPhoto)
	{
		panelPhoto->GetSize(&width, &height);
		EditedPhoto.resize(width, height);
	}
}


void GUIMyFrame1::wxPanel_Repaint(wxUpdateUIEvent& event)
{
	// TODO: Implement wxPanel_Repaint
	if (EditedPhoto && !checkBoxAnimation->IsChecked()) Draw();
}


void GUIMyFrame1::Draw()
{
	wxClientDC dc(panelPhoto);
	wxImage PhotoDraw(width, height);
	Convert_CImg_To_wxImage(PhotoDraw, EditedPhoto, width, height);

	if (PhotoDraw.IsOk()) dc.DrawBitmap(wxBitmap(PhotoDraw), 0, 0);
	PhotoDraw.UnRef();
}