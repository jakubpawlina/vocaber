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
    wxSize imageSize(300, 100);
    staticBitmap->SetMaxSize(imageSize);
    this->panel->GetSizer()->Add(staticBitmap, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 50);

    this->filePicker = new wxFilePickerCtrl(
            this->panel, wxID_ANY, "",
            "Select file with learning data (Vocaber JSON)", "JSON files (*.json)|*.json|All files (*.*)|*.*",
            wxDefaultPosition, wxSize(300, 35)
            );
    this->filePicker->Bind(wxEVT_FILEPICKER_CHANGED, &MainFrame::OnFileSelected, this);
    this->panel->GetSizer()->Add(this->filePicker, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    this->startButton = new wxButton(this->panel, wxID_ANY, "Start", wxDefaultPosition, wxSize(100, 35));
    this->startButton->SetBackgroundColour(wxColour(180, 30, 50, 255));
    this->startButton->SetFont(wxFontInfo(wxSize(0, 16)).Bold());
    this->startButton->Bind(wxEVT_BUTTON, &MainFrame::OnStartButtonClicked, this);
    this->panel->GetSizer()->Add(this->startButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    this->aboutButton = new wxButton(this->panel, wxID_ANY, "About", wxDefaultPosition, wxSize(100, 35));
    this->aboutButton->Bind(wxEVT_BUTTON, &MainFrame::OnAboutButtonClicked, this);
    this->panel->GetSizer()->Add(this->aboutButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    this->panel->GetSizer()->Fit(this->panel);
}

void MainFrame::OnStartButtonClicked(wxCommandEvent &evt) {
    std::ifstream file(filePicker->GetPath());
    std::string input{};
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            input += line;
            input += "\n";
        }
        file.close();

        try {
            nlohmann::json input_json = nlohmann::json::parse(input);
            std::string name = input_json.at("name");
            auto* learnFrame = new LearnFrame("Vocaber | Learning: " + name, currentDataFilePath);
            learnFrame->SetClientSize(800, 600);
            learnFrame->Center();
            learnFrame->Show();
        } catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        } catch (const std::domain_error& e) {
            std::cout << "Error: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    } else {
        std::cout << "Unable to open the file." << std::endl;
    }
}

void MainFrame::OnAboutButtonClicked(wxCommandEvent &evt) {
    wxMessageBox(wxT("Vocaber © 2023\n\nAuthor: Jakub Pawlina\n\nCode: https://github.com/jakubpawlina/vocaber"), wxT(""), wxOK | wxICON_INFORMATION, this);
}

void MainFrame::OnFileSelected(wxFileDirPickerEvent& evt) {
    this->currentDataFilePath = evt.GetPath();
}
