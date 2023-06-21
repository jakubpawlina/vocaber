#include "MainFrame.h"


MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    CreateControls();
    BindEventHandlers();
}


void MainFrame::CreateControls() {
    wxFont headlineFont(wxFontInfo(wxSize(0, 24)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0, 16)));

    this->SetFont(mainFont);
    this->sizer->AddStretchSpacer();

    this->logoImageBitmap = new wxStaticBitmap(this, wxID_ANY, wxBitmap("../assets/vocaber_logo.png", wxBITMAP_TYPE_PNG));
    this->logoImageBitmap->SetMaxSize(wxSize(300, 100));
    this->sizer->Add(this->logoImageBitmap, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 50);

    this->dataFilePicker = new wxFilePickerCtrl(
            this, wxID_ANY, "", "Select file with learning data (Vocaber JSON)",
            "JSON files (*.json)|*.json|All files (*.*)|*.*", wxDefaultPosition, wxSize(300, 35));
    this->sizer->Add(this->dataFilePicker, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    this->startButton = new wxButton(this, wxID_ANY, "Start", wxDefaultPosition, wxSize(100, 35));
    this->startButton->SetBackgroundColour(wxColour(180, 30, 50, 255));
    this->startButton->SetFont(wxFontInfo(wxSize(0, 16)).Bold());
    this->sizer->Add(this->startButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    this->aboutButton = new wxButton(this, wxID_ANY, "About", wxDefaultPosition, wxSize(100, 35));
    this->sizer->Add(this->aboutButton, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 30);

    this->sizer->AddStretchSpacer();

    SetSizer(this->sizer);
}


void MainFrame::OnStartButtonClicked(wxCommandEvent &evt) {
    nlohmann::json input_json = vocaber_utilities::get_json_from_file(dataFilePicker->GetPath().ToStdString());
    if (!input_json.empty()) {
        if (vocaber_utilities::validate_json_input(input_json)) {
            std::string name = input_json.at("name");
            auto* learnFrame = new LearnFrame("Vocaber | Learning: " + name, currentDataFilePath);
            learnFrame->SetClientSize(800, 600);
            learnFrame->Center();
            learnFrame->Show();
        } else {
            wxMessageBox(wxT("Selected file is invalid!"), wxT(""), wxICON_ERROR | wxOK);
        }
    } else {
        wxMessageBox(wxT("Unable to read JSON file!"), wxT(""), wxICON_ERROR | wxOK);
    }
}


void MainFrame::OnAboutButtonClicked(wxCommandEvent &evt) {
    wxMessageBox(wxT("Vocaber © 2023\n\nAuthor: Jakub Pawlina\n\nCode: https://github.com/jakubpawlina/vocaber"),
                 wxT(""), wxOK | wxICON_INFORMATION, this);
}


void MainFrame::OnFileSelected(wxFileDirPickerEvent& evt) {
    this->currentDataFilePath = evt.GetPath();
}


void MainFrame::BindEventHandlers() {
    this->dataFilePicker->Bind(wxEVT_FILEPICKER_CHANGED, &MainFrame::OnFileSelected, this);
    this->startButton->Bind(wxEVT_BUTTON, &MainFrame::OnStartButtonClicked, this);
    this->aboutButton->Bind(wxEVT_BUTTON, &MainFrame::OnAboutButtonClicked, this);
}
