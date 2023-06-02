#include "frame.h"

Frame::Frame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    // Panel
    wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, this->GetSize());

    // Box sizer
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);

    // Menu bar
    // File menu
    wxMenu* menuFile = new wxMenu();
    menuFile->Append(wxID_OPEN, wxT("Open file...\tCtrl+O"));
    menuFile->Append(wxID_EXIT, wxT("Close\tCtrl+E"));

    // Menu bar
    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(menuFile, wxT("File"));
    SetMenuBar(menuBar);

    // Text control
    wxTextCtrl* textArea = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, panel->GetSize(), wxTE_MULTILINE);
    textArea->Show(true);

    // Add objects into wxBoxSizer
    boxSizer->Add(textArea, 1, wxEXPAND | wxALL);
    panel->SetSizer(boxSizer);

    // Status bar
    CreateStatusBar();
    SetStatusText(wxEmptyString);

    // Event
    Bind(wxEVT_MENU, &Frame::OnExit, this, wxID_EXIT);
}

void Frame::OnExit(wxCommandEvent& evt)
{
	Close(true);
}
