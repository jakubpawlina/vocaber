#pragma once
#include <fstream>
#include <wx/wx.h>
#include <wx/filepicker.h>
#include "../include/nlohmann/json.hpp"
#include "utilities/get_json_from_file.h"
#include "defines/config_path.h"
#include "LearnFrame.h"


class MainFrame : public wxFrame {
public:
    explicit MainFrame(const wxString& title);

private:
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxFilePickerCtrl* dataFilePicker = new wxFilePickerCtrl();
    wxButton* startButton = new wxButton();
    wxButton* aboutButton = new wxButton();
    wxStaticBitmap* logoImageBitmap = new wxStaticBitmap();

    wxString currentDataFilePath{};

    void CreateControls();
    void BindEventHandlers();

    void OnStartButtonClicked(wxCommandEvent &evt);
    void OnAboutButtonClicked(wxCommandEvent &evt);
    void OnFileSelected(wxFileDirPickerEvent& evt);
};
