#pragma once

#include <wx/wx.h>

class Frame : public wxFrame
{
public:
	Frame(const wxString& title, const wxPoint& pos, const wxSize& size);

	void OnOpen(wxCommandEvent& evt);
	void OnSave(wxCommandEvent& evt);
	void OnAbout(wxCommandEvent& evt);
	void OnExit(wxCommandEvent& evt);
};

