#include "frame.h"

Frame::Frame(const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, wxT("New Document - NoteC++"), pos, size)
{
    // Panel
    wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, this->GetSize());

    // Box sizer
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);

    // File menu
    wxMenu* menuFile = new wxMenu();
    menuFile->Append(wxID_OPEN, wxT("Open File\tCtrl+O"));
    menuFile->Append(wxID_SAVE, wxT("Save File\tCtrl+S"));
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT, wxT("Close\tCtrl+E"));

    // About
    wxMenu* menuAbout = new wxMenu();
    menuAbout->Append(wxID_ABOUT, wxT("About NoteC++"));

    // Menu bar
    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(menuFile, wxT("File"));
    menuBar->Append(menuAbout, wxT("About"));
    SetMenuBar(menuBar);

    // Text control
    textArea = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, panel->GetSize(), wxTE_MULTILINE);
    textArea->Show(true);

    // Add objects into wxBoxSizer
    boxSizer->Add(textArea, 1, wxEXPAND | wxALL);
    panel->SetSizer(boxSizer);

    // Status bar
    CreateStatusBar();
    SetStatusText(wxEmptyString);

    // Event
    Bind(wxEVT_MENU, &Frame::OnOpen, this, wxID_OPEN);
    Bind(wxEVT_MENU, &Frame::OnSave, this, wxID_SAVE);
    Bind(wxEVT_MENU, &Frame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &Frame::OnExit, this, wxID_EXIT);
}

void Frame::OnOpen(wxCommandEvent& evt)
{
    // Open file dialog
    wxFileDialog openFileDialog(this, wxT("Open Document"), "", "",
        "Text document files (*.txt) | *.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    // Skip if the user click the cancel button
    if (openFileDialog.ShowModal() == wxID_CANCEL) return;

    // Load all data into wxTextCtrl from a file
    textArea->LoadFile(openFileDialog.GetPath());

    // Set program title
    SetTitle(openFileDialog.GetFilename() + wxT(" - NoteC++"));
}

void Frame::OnSave(wxCommandEvent& evt)
{
    // Open file dialog
    wxFileDialog saveFileDialog(this, wxT("Save Document"), "", "",
        "Text document files (*.txt) | *.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    // Skip if the user click the cancel button
    if (saveFileDialog.ShowModal() == wxID_CANCEL) return;

    // Save the current contents into the file
    textArea->SaveFile(saveFileDialog.GetPath());

    // Set program title
    SetTitle(saveFileDialog.GetFilename() + wxT(" - NoteC++"));
}

void Frame::OnAbout(wxCommandEvent& evt)
{
    wxMessageDialog* aboutMsg = new wxMessageDialog(NULL, wxT("This program is made by ReynDev"),
        wxT("About NoteC++"), wxOK);
    aboutMsg->ShowModal();
}

void Frame::OnExit(wxCommandEvent& evt)
{
	Close(true);
}
