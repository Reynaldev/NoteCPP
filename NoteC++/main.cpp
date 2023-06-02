#include "main.h"
#include "frame.h"

IMPLEMENT_APP(Main);

bool Main::OnInit()
{
    // New frame
    Frame* frame = new Frame(wxT("New - NoteC++"), wxDefaultPosition, wxSize(400, 600));
    frame->Show(true);

    return true;
}