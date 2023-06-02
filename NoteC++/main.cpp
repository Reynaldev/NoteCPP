#include "main.h"
#include "frame.h"

IMPLEMENT_APP(Main);

bool Main::OnInit()
{
    // Frame
    Frame* frame = new Frame(wxT("New - NoteC++"), wxDefaultPosition, wxSize(400, 600));
    frame->Show(true);

    // Panel
    wxPanel* panel = new wxPanel(frame, wxID_ANY, wxDefaultPosition, frame->GetSize());

    // Box sizer
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);

    // Text control
    wxTextCtrl* textArea = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, panel->GetSize(), wxTE_MULTILINE);
    textArea->Show(true);

    // Add objects into wxBoxSizer
    boxSizer->Add(textArea, 1, wxEXPAND | wxALL);
    panel->SetSizer(boxSizer);

    return true;
}