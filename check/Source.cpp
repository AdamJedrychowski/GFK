#include <wx/wxprec.h>
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
	void Form_Paint(wxPaintEvent& e);
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	MyFrame* frame = new MyFrame();
	frame->Show(true);
	return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Demo 06")
{
	SetTitle(_("Demo 06 - Pióro i pêdzel"));
	SetIcon(wxNullIcon);
	SetSize(8, 8, 394, 421);
	Center();

	Bind(wxEVT_PAINT, &MyFrame::Form_Paint, this);
}

void MyFrame::Form_Paint(wxPaintEvent& event)
{
	std::unique_ptr<wxPaintDC> MyDC(new wxPaintDC(this));

	MyDC->SetBackground(wxBrush(wxColour(255, 255, 255), wxBRUSHSTYLE_SOLID));
	MyDC->Clear();

	MyDC->DrawRectangle(10, 10, 20, 190);
	MyDC->SetBrush(wxBrush(wxColour(192, 192, 192), wxBRUSHSTYLE_SOLID));
	MyDC->DrawRectangle(40, 10, 20, 190);

	MyDC->SetBrush(wxBrush(wxColour(128, 128, 128), wxBRUSHSTYLE_SOLID));
	MyDC->DrawRectangle(70, 10, 20, 190);
	MyDC->SetBrush(wxBrush(wxColour(128, 192, 96), wxBRUSHSTYLE_SOLID));
	MyDC->DrawRectangle(100, 10, 20, 190);

	MyDC->SetBrush(wxBrush(wxColour(96, 192, 255), wxBRUSHSTYLE_FDIAGONAL_HATCH));
	MyDC->DrawRectangle(130, 10, 20, 190);
	MyDC->DrawLine(160, 10, 160, 200);
	MyDC->DrawLine(160, 200, 200, 200);
	MyDC->DrawLine(200, 200, 160, 10);
	MyDC->FloodFill(163, 198, wxColor(0, 0, 0), wxFLOOD_BORDER);

	MyDC->SetBrush(wxBrush(wxColour(192, 192, 192), wxBRUSHSTYLE_SOLID));
	MyDC->DrawRectangle(5, 60, 195, 10);

	MyDC->SetPen(wxPen(wxColour(255, 255, 255), 1, wxPENSTYLE_SOLID));
	MyDC->DrawRectangle(5, 80, 195, 10);

	MyDC->SetPen(wxPen(wxColour(0, 0, 0), 1, wxPENSTYLE_SOLID));
	MyDC->DrawRectangle(5, 100, 195, 10);

	MyDC->SetPen(wxPen(wxColour(0, 0, 0), 1, wxPENSTYLE_TRANSPARENT));
	MyDC->DrawRectangle(5, 120, 195, 10);

	MyDC->SetBrush(wxBrush(wxColour(0, 0, 0), wxBRUSHSTYLE_TRANSPARENT));
	MyDC->SetPen(wxPen(wxColour(0, 0, 0), 1, wxPENSTYLE_SOLID));
	MyDC->DrawRectangle(5, 140, 195, 10);

	MyDC->SetPen(wxPen(wxColour(255, 0, 0), 1, wxPENSTYLE_SOLID));
	MyDC->DrawLine(5, 30, 200, 30);

	MyDC->SetPen(wxPen(wxColour(255, 0, 0), 3, wxPENSTYLE_LONG_DASH));
	MyDC->DrawLine(5, 40, 200, 40);

	MyDC->SetPen(wxPen(wxColour(255, 0, 0), 1, wxPENSTYLE_DOT));
	MyDC->DrawLine(5, 50, 200, 50);

	MyDC->SetPen(wxNullPen);            // ustawienie domyslnego piora dla DC
	MyDC->SetBrush(wxNullBrush);        // ustawienie domyslnego pedzla dla DC

	MyDC->DrawRectangle(5, 180, 150, 20);
}