#pragma once
#include <wx/wx.h>
#include <wx/filepicker.h>

#include "LearnFrame.h"

class MainFrame : public wxFrame {
public:
    explicit MainFrame(const wxString& title);
private:
    wxPanel* panel = new wxPanel(this);
    wxStaticText* headlineText = new wxStaticText();
    wxFilePickerCtrl* filePicker = new wxFilePickerCtrl();
    wxButton* startButton = new wxButton();

    wxString currentDataFilePath{};

    void CreateControls();

    void OnStartButtonClicked(wxCommandEvent &evt);
    void OnFileSelected(wxFileDirPickerEvent& evt);
};
