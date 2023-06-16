#pragma once
#include <fstream>

#include <wx/wx.h>
#include <wx/filepicker.h>

#include "../include/nlohmann/json.hpp"

#include "LearnFrame.h"

class MainFrame : public wxFrame {
public:
    explicit MainFrame(const wxString& title);
private:
    wxPanel* panel = new wxPanel(this);
    wxFilePickerCtrl* filePicker = new wxFilePickerCtrl();
    wxButton* startButton = new wxButton();
    wxButton* aboutButton = new wxButton();

    wxString currentDataFilePath{};

    void CreateControls();

    void OnStartButtonClicked(wxCommandEvent &evt);
    void OnAboutButtonClicked(wxCommandEvent &evt);
    void OnFileSelected(wxFileDirPickerEvent& evt);
};
