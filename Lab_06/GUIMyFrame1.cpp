#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
 m_staticText1->SetLabel(_(L"Jasno\u015B\u0107"));
 m_b_threshold->SetLabel(_(L"Pr\u00F3g 128"));
 this->SetBackgroundColour(wxColor(192, 192, 192));
 m_scrolledWindow->SetScrollbars(25, 25, 52, 40);
 m_scrolledWindow->SetBackgroundColour(wxColor(192, 192, 192));
}

void GUIMyFrame1::m_scrolledWindow_update( wxUpdateUIEvent& event )
{
 Repaint();
}

void GUIMyFrame1::m_b_grayscale_click( wxCommandEvent& event )
{
 // TO DO: Konwersja do skali szarosci  
	Img_Cpy = Img_Org.Copy();
	Img_Cpy = Img_Cpy.ConvertToGreyscale();
	ClearScreen = 1;
}

void GUIMyFrame1::m_b_blur_click( wxCommandEvent& event )
{
 // TO DO: Rozmywanie obrazu (blur)
	Img_Cpy = Img_Org.Copy();
	Img_Cpy=Img_Cpy.Blur(5);
	ClearScreen = 1;
}

void GUIMyFrame1::m_b_mirror_click( wxCommandEvent& event )
{
 // TO DO: Odbicie lustrzane
	Img_Cpy = Img_Org.Copy();
	Img_Cpy = Img_Cpy.Mirror();
	ClearScreen = 1;
}

void GUIMyFrame1::m_b_replace_click( wxCommandEvent& event )
{
 // TO DO: Zamiana kolorow 
	Img_Cpy = Img_Org.Copy();
	Img_Cpy.Replace(254, 0, 0, 0, 0, 255);
	ClearScreen = 1;
}

void GUIMyFrame1::m_b_rescale_click( wxCommandEvent& event )
{
 // TO DO: Zmiana rozmiarow do 320x240
	Img_Cpy = Img_Org.Copy();
	Img_Cpy = Img_Cpy.Rescale(320, 240);
	ClearScreen = 1;
}

void GUIMyFrame1::m_b_rotate_click( wxCommandEvent& event )
{
 // TO DO: Obrot o 30 stopni
	Img_Cpy = Img_Org.Copy();
	Img_Cpy = Img_Cpy.Rotate(30 * M_PI / 180., wxPoint(Img_Cpy.GetSize().x / 2., Img_Cpy.GetSize().y / 2.)); // dlaczego tak jest????
	ClearScreen = 1;
}

void GUIMyFrame1::m_b_rotate_hue_click( wxCommandEvent& event )
{
 // TO DO: Przesuniecie Hue o 180 stopni
	Img_Cpy = Img_Org.Copy();
	Img_Cpy.RotateHue(0.5);
	ClearScreen = 1;
}

void GUIMyFrame1::m_b_mask_click( wxCommandEvent& event )
{
 // TO DO: Ustawienie maski obrazu
	Img_Cpy = Img_Org.Copy();
	Img_Cpy.SetMaskFromImage(Img_Mask, 0, 0, 0);
	ClearScreen = 1;
}

void GUIMyFrame1::m_s_brightness_scroll( wxScrollEvent& event )
{
// Tutaj, w reakcji na zmiane polozenia suwaka, wywolywana jest funkcja
// Brightness(...), ktora zmienia jasnosc. W tym miejscu nic nie
// zmieniamy. Do uzupelnienia pozostaje funkcja Brightness(...)
Brightness(m_s_brightness->GetValue() - 100);
Repaint();
}

void GUIMyFrame1::m_s_contrast_scroll( wxScrollEvent& event )
{
// Tutaj, w reakcji na zmiane polozenia suwaka, wywolywana jest funkcja
// Contrast(...), ktora zmienia kontrast. W tym miejscu nic nie
// zmieniamy. Do uzupelnienia pozostaje funkcja Contrast(...)
Contrast(m_s_contrast->GetValue() - 100);
Repaint();
}

void GUIMyFrame1::m_b_prewitt_click( wxCommandEvent& event )
{
 // TO DO: Pionowa maska Prewitta
	Img_Cpy = Img_Org.Copy();
	int h = Img_Cpy.GetHeight(), w = Img_Cpy.GetWidth();
	unsigned int pixelcount = h * w;
	std::vector<unsigned char> ImgNew;
	ImgNew.reserve(pixelcount*3);
	unsigned char* data = Img_Cpy.GetData();
	int sum;
	for (unsigned int i = 0; i < pixelcount; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i % w == 0) sum = (int)*(data + 3);
			else if (i % w == w - 1) sum = -(int)*(data - 3);
			else sum = -(int)*(data - 3) + (int)*(data + 3);

			if (abs(sum) > 255) sum = 255;
			ImgNew.push_back(abs(sum));
			data++;
		}
	}
	data = Img_Cpy.GetData();
	for (int i = 0; i < pixelcount*3; i++) data[i] = ImgNew[i];
}

void GUIMyFrame1::m_b_threshold_click( wxCommandEvent& event )
{
 // TO DO: Prog o wartosci 128 dla kazdego kanalu niezaleznie
	Img_Cpy = Img_Org.Copy();

	ClearScreen = 1;
}


void GUIMyFrame1::Contrast(int value)
{
 // TO DO: Zmiana kontrastu obrazu. value moze przyjmowac wartosci od -100 do 100
	Img_Cpy = Img_Org.Copy();

	unsigned int pixelcount = Img_Cpy.GetHeight() * Img_Cpy.GetWidth();
	unsigned char* data = Img_Cpy.GetData();
	int R, G, B;
	float factor = (259 * (value * 255 / 100. + 255)) / (255. * (259 - value * 255 / 100.));
	for (unsigned int i = 0; i < pixelcount; i++) {
		R = factor * ((int)data[0] - 128) + 128;
		G = factor * ((int)data[1] - 128) + 128;
		B = factor * ((int)data[2] - 128) + 128;
		if (R > 255) R = 255;
		else if (R < 0) R = 0;

		if (G > 255) G = 255;
		else if (G < 0) G = 0;

		if (B > 255) B = 255;
		else if (B < 0) B = 0;
		data[0] = R;
		data[1] = G;
		data[2] = B;

		data += 3;
	}
}

void GUIMyFrame1::Repaint()
{
 wxBitmap bitmap(Img_Cpy);          // Tworzymy tymczasowa bitmape na podstawie Img_Cpy
 wxClientDC dc(m_scrolledWindow);   // Pobieramy kontekst okna
 if (ClearScreen)
 {
	 dc.Clear();
	 ClearScreen = 0;
 }
 m_scrolledWindow->DoPrepareDC(dc); // Musimy wywolac w przypadku wxScrolledWindow, zeby suwaki prawidlowo dzialaly
 dc.DrawBitmap(bitmap, 0, 0, true); // Rysujemy bitmape na kontekscie urzadzenia
}

void GUIMyFrame1::Brightness(int value)
{
 // TO DO: Zmiana jasnosci obrazu. value moze przyjmowac wartosci od -100 do 100
	Img_Cpy = Img_Org.Copy();

	unsigned int pixelcount = Img_Cpy.GetHeight() * Img_Cpy.GetWidth();
	unsigned char* data = Img_Cpy.GetData();
	int R, G, B;
	for (unsigned int i = 0; i < pixelcount; i++) {
		R = (int)data[0] + value;
		G = (int)data[1] + value;
		B = (int)data[2] + value;
		if (R > 255) R = 255;
		else if (R < 0) R = 0;

		if (G > 255) G = 255;
		else if (G < 0) G = 0;

		if (B > 255) B = 255;
		else if (B < 0) B = 0;
		data[0] = R;
		data[1] = G;
		data[2] = B;

		data += 3;
	}
}