#include <wx/wxprec.h>
#include <wx/fontenum.h>
#include <memory>

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
	MyFrame();
private:
	wxStaticText* WxStaticText1;
	wxChoice* WxChoice1;
	void Form_Paint(wxPaintEvent& e);
	void WxChoice1_Selected(wxCommandEvent& e);
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	MyFrame* frame = new MyFrame();
	frame->Show(true);
	return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Demo 07")
{
	SetTitle(_("Demo 07 - Czcionki i napisy"));
	SetIcon(wxNullIcon);
	SetSize(8, 8, 729, 422);
	Center();

	WxStaticText1 = new wxStaticText(this, wxID_ANY, _("ABCDEFGabcdefg1234"), wxPoint(46, 28), wxDefaultSize, 0, _("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(25, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _("Tahoma")));

	wxArrayString arrayStringFor_WxChoice1;
	WxChoice1 = new wxChoice(this, wxID_ANY, wxPoint(447, 21), wxSize(234, 23), arrayStringFor_WxChoice1, 0, wxDefaultValidator, _("WxChoice1"));
	wxArrayString SystemFonts;
	SystemFonts = wxFontEnumerator::GetFacenames(); // ---> #include <wx/fontenum.h>
	for (unsigned int i = 0; i < SystemFonts.Count(); i++) WxChoice1->Append(SystemFonts[i]);
	WxChoice1->SetSelection(0);

	Bind(wxEVT_PAINT, &MyFrame::Form_Paint, this);
	WxChoice1->Bind(wxEVT_CHOICE, &MyFrame::WxChoice1_Selected, this);
}

void MyFrame::WxChoice1_Selected(wxCommandEvent& e)
{
	WxStaticText1->SetFont(wxFont(22, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, WxChoice1->GetString(WxChoice1->GetSelection())));
	Refresh();
}

void MyFrame::Form_Paint(wxPaintEvent& e)
{
	std::unique_ptr<wxPaintDC> MyDC(new wxPaintDC(this));
	MyDC->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, WxChoice1->GetString(WxChoice1->GetSelection())));
	MyDC->DrawText("Przyk³adowy tekst (ÊêÓó¥¹Œœ£³¯¿ŸæÑñ)", 20, 70);
	MyDC->SetTextForeground(wxColor(255, 0, 0));
	MyDC->DrawText("Kolorowy text", 20, 90);
	MyDC->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, WxChoice1->GetString(WxChoice1->GetSelection())));
	MyDC->DrawText("Przyk³adowy tekst pogrubiony", 20, 130);
	MyDC->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, WxChoice1->GetString(WxChoice1->GetSelection())));
	MyDC->SetTextForeground(wxColor(0, 0, 255));
	MyDC->DrawText("Przyk³adowy tekst pochy³y", 20, 170);
}