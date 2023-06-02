#pragma once

#include <wx/wx.h>
#include <wx/wfstream.h>

class Frame : public wxFrame
{
private:
	wxString filename;
	wxString text;

	wxTextCtrl* textArea;
public:
	Frame(const wxPoint& pos, const wxSize& size);

	void OnOpen(wxCommandEvent& evt);
	void OnSave(wxCommandEvent& evt);
	void OnAbout(wxCommandEvent& evt);
	void OnExit(wxCommandEvent& evt);
};

