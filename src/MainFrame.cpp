#include "MainFrame.h"

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    CreateControls();
}

void MainFrame::CreateControls() {
    wxFont headlineFont(wxFontInfo(wxSize(0, 24)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0, 16)));

    this->panel->SetFont(mainFont);
    this->panel->SetSizer(new wxBoxSizer(wxVERTICAL));

    auto* staticBitmap = new wxStaticBitmap(
            this->panel, wxID_ANY, wxBitmap("../assets/vocaber_logo.png", wxBITMAP_TYPE_PNG)
            );
    wxSize imageSize(323, 100);
    staticBitmap->SetMaxSize(imageSize);
    this->panel->GetSizer()->Add(staticBitmap, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 50);

    this->filePicker = new wxFilePickerCtrl(
            this->panel, wxID_ANY, "",
            "Select file with learning data (Vocaber JSON)", "JSON files (*.json)|*.json|All files (*.*)|*.*",
            wxPoint(100, 100), wxSize(380, 35)
            );
    this->filePicker->Bind(wxEVT_FILEPICKER_CHANGED, &MainFrame::OnFileSelected, this);
    this->panel->GetSizer()->Add(this->filePicker, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    this->startButton = new wxButton(this->panel, wxID_ANY, "Start", wxPoint(600, 100), wxSize(100, 35));
    this->startButton->Bind(wxEVT_BUTTON, &MainFrame::OnStartButtonClicked, this);
    this->panel->GetSizer()->Add(this->startButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    this->panel->GetSizer()->Fit(this->panel);
}

void MainFrame::OnStartButtonClicked(wxCommandEvent &evt) {
    auto* learnFrame = new LearnFrame("Vocaber | LEARNING", currentDataFilePath);
    learnFrame->SetClientSize(800, 600);
    learnFrame->Center();
    learnFrame->Show();
}

void MainFrame::OnFileSelected(wxFileDirPickerEvent& evt) {
    this->currentDataFilePath = evt.GetPath();
}
