#pragma once
#include <wx/wx.h>
#include <wx/filepicker.h>

#include "LearnFrame.h"

class MainFrame : public wxFrame {
public:
    explicit MainFrame(const wxString& title);
private:
    wxPanel* panel{};
    wxStaticText* headlineText{};
    wxFilePickerCtrl* filePicker{};
    wxButton* startButton{};

    wxString currentDataFilePath{};

    void CreateControls();

    void OnStartButtonClicked(wxCommandEvent &evt);
    void OnFileSelected(wxFileDirPickerEvent& evt);
};
