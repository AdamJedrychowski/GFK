#include "GUIMyFrame1.h"


void GUIMyFrame1::UpdateScreen(wxMoveEvent& event)
{
	// TODO: Implement UpdateScreen

}


#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent), RadiusOfBanan{ 0 }, StarColor{ 0,0,0 }, TextToWrite{ "tekst" }
{
	Bind(wxEVT_PAINT, &GUIMyFrame1::m_panel3OnPaint, this);
	Bind(wxEVT_CHECKBOX, &GUIMyFrame1::CheckBox_LoadBananOnCheckBox, this);

	ScrollBar_MoveBanan->SetRange(45);
	ScrollBar_MoveBanan->SetThumbSize(1);
	Gauge_BananPosition->SetRange(45);

	ConnectWithFile.AddHandler(new wxPNGHandler);
	ConnectWithFile.AddHandler(new wxJPEGHandler);
}

void GUIMyFrame1::m_panel3OnPaint(wxPaintEvent& event)
{
	// TODO: Implement m_panel3OnPaint
	std::shared_ptr<wxClientDC> MyDC(new wxClientDC(m_panel3));
	MyDC->Clear();

	int x = m_panel3->GetSize().x, y = m_panel3->GetSize().y;

	//person
	MyDC->DrawLine(x / 2, y / 2 - 10, x / 2, y / 2 + 60);
	MyDC->DrawLine(x / 2, y / 2, x / 2 + 40, y / 2 + 20);
	MyDC->DrawLine(x / 2, y / 2, x / 2 + 44.7214 * cos((154.56505118 + RadiusOfBanan) * PI / 180.),
		y / 2 + 44.7214 * sin((154.56505118 + RadiusOfBanan) * PI / 180.));
	MyDC->DrawLine(x / 2, y / 2 + 60, x / 2 + 30, y / 2 + 90);
	MyDC->DrawLine(x / 2, y / 2 + 60, x / 2 - 30, y / 2 + 90);

	//banan
	if (Banan.IsOk())
	{
		MyDC->DrawBitmap(Banan, x / 2 + 44.7214 * cos((154.56505118 + RadiusOfBanan) * PI / 180.) - 20,
			y / 2 + 44.7214 * sin((154.56505118 + RadiusOfBanan) * PI / 180.) - 20);
	}

	//head
	MyDC->DrawCircle(x / 2, y / 2 - 30, 20);
	MyDC->DrawEllipse(x / 2 - 12, y / 2 - 38, 9, 6);
	if (!Banan.IsOk())
	{
		MyDC->DrawEllipse(x / 2 + 4, y / 2 - 40, 6, 9);
		MyDC->DrawEllipticArc(x / 2 - 15, y / 2 - 25, 30, 10, 0, 180);
	}
	else
	{
		MyDC->DrawEllipse(x / 2 + 3, y / 2 - 38, 9, 6);
		MyDC->DrawEllipticArc(x / 2 - 15, y / 2 - 30, 30, 10, 180, 360);
	}

	//text uzupe³nic o value
	MyDC->DrawText(TextToWrite, x / 2 - 100, y / 2 + 80);
	MyDC->SetFont(wxFont(wxFontInfo(30).Family(wxFONTFAMILY_SCRIPT).Bold().Slant()));
	MyDC->DrawRotatedText(TextToWrite, x / 2 + 70, y / 2 + 90, 90);

	//star
	if (Choice_Element->GetSelection() == 0)
	{
		wxPoint CreateStar[5] = { wxPoint(x / 2 - 80, y / 2 - 100), wxPoint(x / 2 - 60, y / 2 - 50),
			wxPoint(x / 2 - 110, y / 2 - 80), wxPoint(x / 2 - 50, y / 2 - 80), wxPoint(x / 2 - 100, y / 2 - 50) };
		MyDC->SetBrush(wxBrush(StarColor, wxBRUSHSTYLE_SOLID));
		MyDC->SetPen(wxPen(StarColor));
		MyDC->DrawPolygon(5, CreateStar);
	}
	else if (Choice_Element->GetSelection() == 1)
	{
		MyDC->SetBrush(wxColour(200, 200, 200));
		MyDC->SetPen(wxPen(wxColour(200, 200, 200)));
		MyDC->DrawArc(x / 2 - 90, y / 2 - 60, x / 2 - 60, y / 2 - 90, x / 2 - 70, y / 2 - 70);
		MyDC->SetBrush(wxColour(255, 255, 255));
		MyDC->SetPen(wxPen(wxColour(255, 255, 255)));
		MyDC->DrawArc(x / 2 - 90, y / 2 - 60, x / 2 - 60, y / 2 - 90, x / 2 - 80, y / 2 - 80);

		MyDC->SetPen(wxPen(wxColour(0, 0, 0)));
		MyDC->SetBrush(wxColour(0, 0, 0));
		MyDC->DrawCircle(x / 2 - 60, y / 2 - 70, 3);
		MyDC->DrawLine(x / 2 - 70, y / 2 - 62, x / 2 - 65, y / 2 - 58);
	}
	else
	{
		MyDC->SetBrush(wxBrush(wxColor(255, 255, 0), wxBRUSHSTYLE_SOLID));
		MyDC->SetPen(wxPen(wxColor(255, 255, 0)));
		MyDC->DrawCircle(x / 2 - 80, y / 2 - 80, 20);
	}
}

void GUIMyFrame1::Button_SaveToFileOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement Button_SaveToFileOnButtonClick
	std::shared_ptr<wxFileDialog> SaveToFile(new wxFileDialog(this, _("Choose a file"), _(""), _(""), _(""), wxFD_SAVE));

	if (SaveToFile->ShowModal() == wxID_OK)
	{
		wxWindowDC PanelScreen(this);
		wxCoord screenWidth = m_panel3->GetPosition().x, screenHeight = m_panel3->GetPosition().y;

		wxBitmap screenshot(m_panel3->GetSize().x, m_panel3->GetSize().y, -1);
		wxMemoryDC memDC;
		memDC.SelectObject(screenshot);
		memDC.Blit(0, 0, m_panel3->GetSize().x, m_panel3->GetSize().y, &PanelScreen, m_panel3->GetPosition().x + 8, m_panel3->GetPosition().y + 31);
		memDC.SelectObject(wxNullBitmap);
		screenshot.SaveFile(SaveToFile->GetPath(), wxBITMAP_TYPE_JPEG);

		/*if (wxBITMAP_TYPE_JPEG == SaveToFile->GetFilterIndex())
			screenshot.SaveFile(SaveToFile->GetPath(), wxBITMAP_TYPE_JPEG);
		else if (wxBITMAP_TYPE_BMP == SaveToFile->GetFilterIndex())
			screenshot.SaveFile(SaveToFile->GetPath(), wxBITMAP_TYPE_BMP);
		else
			screenshot.SaveFile(SaveToFile->GetPath(), wxBITMAP_TYPE_PNG);*/
	}
}

void GUIMyFrame1::CheckBox_LoadBananOnCheckBox(wxCommandEvent& event)
{
	// TODO: Implement CheckBox_LoadBananOnCheckBox
	if (CheckBox_LoadBanan->IsChecked())
	{
		std::shared_ptr<wxFileDialog> LoadImage(new wxFileDialog(this));
		LoadImage->SetPath(_(".\\banan.png"));

		if (!ConnectWithFile.LoadFile(LoadImage->GetPath(), wxBITMAP_TYPE_PNG))
			wxLogError(_("Nie mo¿na za³adowaæ obrazka"));
		else
		{
			wxImage TempImg(ConnectWithFile);
			TempImg.Rescale(40, 40);
			ConnectWithFile.Paste(TempImg, ConnectWithFile.GetWidth() - 120, 0);
			Banan = wxBitmap(ConnectWithFile);
		}

		ScrollBar_MoveBanan->Enable(true);
		ScrollBar_MoveBanan->SetThumbPosition(RadiusOfBanan);
	}
	else
	{
		ScrollBar_MoveBanan->Enable(false);
		Banan.UnRef();
	}
	SetSize(GetSize().x + 1, GetSize().y);
	SetSize(GetSize().x - 1, GetSize().y);
}

void GUIMyFrame1::ScrollBar_MoveBananOnScroll(wxScrollEvent& event)
{
	// TODO: Implement ScrollBar_MoveBananOnScroll
	RadiusOfBanan = ScrollBar_MoveBanan->GetThumbPosition();
	Gauge_BananPosition->SetValue(RadiusOfBanan);
	SetSize(GetSize().x + 1, GetSize().y);
	SetSize(GetSize().x - 1, GetSize().y);
}

void GUIMyFrame1::Button_StarColorOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement Button_StarColorOnButtonClick

	std::unique_ptr<wxColourDialog> ChooseColor(new wxColourDialog(this));
	if (ChooseColor->ShowModal() == wxID_OK)
	{
		StarColor = ChooseColor->GetColourData().GetColour();
	}
	SetSize(GetSize().x + 1, GetSize().y);
	SetSize(GetSize().x - 1, GetSize().y);
}

void GUIMyFrame1::TextCtrl_WriteOnText(wxCommandEvent& event)
{
	// TODO: Implement TextCtrl_WriteOnText
	TextToWrite = TextCtrl_Write->GetLineText(0);
	SetSize(GetSize().x + 1, GetSize().y);
	SetSize(GetSize().x - 1, GetSize().y);
}

void GUIMyFrame1::Choice_ElementOnChoice(wxCommandEvent& event)
{
	// TODO: Implement Choice_ElementOnChoice
	SetSize(GetSize().x + 1, GetSize().y);
	SetSize(GetSize().x - 1, GetSize().y);
}

