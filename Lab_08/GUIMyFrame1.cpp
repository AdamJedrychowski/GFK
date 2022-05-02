#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent), width{ 800 }, height{ 533 }
{
	ProgressIndicator->Show(false);
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
	//wxImage image(FreeImage_GetBits(bitmap));
	//Photo.LoadFile(OpenFileDialog.GetPath());

	RGBQUAD* data = new RGBQUAD;// = FreeImage_GetRedMask(bitmap);
	//unsigned char* data = FreeImage_GetBits(bitmap);
	OrginalPhoto.assign(FreeImage_GetWidth(bitmap), FreeImage_GetHeight(bitmap), 1, 3);
	for (int j = 0; j < OrginalPhoto.height(); j++)
		for (int i = 0; i < OrginalPhoto.width(); i++)
		{
			FreeImage_GetPixelColor(bitmap, i, OrginalPhoto.height() - j - 1, data);
			OrginalPhoto(i, j, 0) = data->rgbRed;
			OrginalPhoto(i, j, 1) = data->rgbGreen;
			OrginalPhoto(i, j, 2) = data->rgbBlue;
			//data += 3;
		}

	panelPhoto->GetSize(&width, &height);
	EditedPhoto = OrginalPhoto;
	EditedPhoto.resize(width, height);
	//CImgDisplay disp(Photo, "", 0);
	//while (!disp.is_closed() && !disp.key()) { disp.wait(); if (disp.is_resized()) disp.resize(disp).wait(100); }
	//Photo.assign(FreeImage_GetBits(bitmap), FreeImage_GetWidth(bitmap), FreeImage_GetHeight(bitmap), 3, 1);
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
		using namespace std::chrono_literals;
		for (int i = 0; i < 100; i++)
		{
			ProgressIndicator->SetValue(i);
			std::this_thread::sleep_for(100us);
		}
		ProgressIndicator->Hide();
		Layout();
		Start(10);
	}
}

void GUIMyFrame1::Notify()
{
	static float Time = 0;
	if (!checkBoxAnimation->IsChecked())
	{
		Time = 0;
		Stop();
		return;
	}

	wxClientDC dc(panelPhoto);
	EditedPhoto = OrginalPhoto;
	EditedPhoto.resize(width, height);
	CImg<float> gauss1(width, height, 1, 3), gauss2(width, height, 1, 3);
	float color[3]{1.0f, 1.0f, 1.0f};

	gauss1.draw_gaussian(width / 2. - width / 4. * cos(Time * PI / 180.), height / 2. - width / 4. * sin(Time * PI / 180.), 130.0f, color, 1.0f);
	gauss2.draw_gaussian(width / 2. + width / 4. * cos(Time * PI / 180.), height / 2. + width / 4. * sin(Time * PI / 180.), 130.0f, color, 1.0f);
	EditedPhoto.mul(gauss1 + gauss2);
	Time+=20;

	Draw();
}

void GUIMyFrame1::ChangePhotoSize(wxSizeEvent& event)
{
	// TODO: Implement ChangePhotoSize
	if (OrginalPhoto)
	{
		EditedPhoto = OrginalPhoto;
		panelPhoto->GetSize(&width, &height);
		EditedPhoto.resize(width, height);
	}
}

void GUIMyFrame1::wxPanel_Repaint(wxUpdateUIEvent& event)
{
	// TODO: Implement wxPanel_Repaint
	if (EditedPhoto) Draw();
}


void GUIMyFrame1::Draw()
{
	wxClientDC dc(panelPhoto);
	wxImage PhotoDraw(width, height);
	unsigned char* data = PhotoDraw.GetData();
	for (int j = 0; j < height; j++)
		for (int i = 0; i < width; i++)
		{
			data[0] = EditedPhoto(i, j, 0);
			data[1] = EditedPhoto(i, j, 1);
			data[2] = EditedPhoto(i, j, 2);
			data += 3;
		}

	if (PhotoDraw.IsOk()) dc.DrawBitmap(wxBitmap(PhotoDraw), 0, 0);
	PhotoDraw.UnRef();
}
