#include "MainFrame.h"

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    CreateControls();
}

void MainFrame::CreateControls() {
    wxFont headlineFont(wxFontInfo(wxSize(0, 24)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0, 16)));

    panel = new wxPanel(this);
    panel->SetFont(mainFont);

    wxString labelText = "VOCABER";
    wxClientDC dc(panel);
    dc.SetFont(headlineFont);
    wxSize labelSize = dc.GetTextExtent(labelText);
    headlineText = new wxStaticText(panel, wxID_ANY, labelText, wxPoint(0, 40), wxSize(800, labelSize.GetHeight()), wxALIGN_CENTER_HORIZONTAL);
    headlineText->SetFont(headlineFont);

    filePicker = new wxFilePickerCtrl(panel, wxID_ANY, "", "Select file with learning data (Vocaber JSON)", "JSON files (*.json)|*.json|All files (*.*)|*.*", wxPoint(100, 100), wxSize(495, 35));
    filePicker->Bind(wxEVT_FILEPICKER_CHANGED, &MainFrame::OnFileSelected, this);


    startButton = new wxButton(panel, wxID_ANY, "Start test", wxPoint(600, 100), wxSize(100, 35));
    startButton->Bind(wxEVT_BUTTON, &MainFrame::OnStartButtonClicked, this);
}

void MainFrame::OnStartButtonClicked(wxCommandEvent &evt) {
    LearnFrame* learnFrame = new LearnFrame("VOCABER - LEARN", currentDataFilePath);
    learnFrame->SetClientSize(800, 600);
    learnFrame->Center();
    learnFrame->Show();
}

void MainFrame::OnFileSelected(wxFileDirPickerEvent& evt) {
    this->currentDataFilePath = evt.GetPath();
}
