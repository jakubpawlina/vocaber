#pragma once
#include <wx/wx.h>

#include "FinishFrame.h"

#include "utilities/validate_json_input.h"
#include "classes/Question.h"
#include "utilities/load_questions_from_json.h"

class LearnFrame : public wxFrame {
public:
    explicit LearnFrame(const wxString& title, const wxString& dataFilePath, nlohmann::json &json);

private:
    std::string setTitle{};

    wxStaticText* staticText = new wxStaticText(this, wxID_ANY, "");
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxTextCtrl* userAnswerInput = new wxTextCtrl();
    wxButton* checkAnswerButton = new wxButton();
    wxButton* nextQuestionButton = new wxButton();
    wxStaticBitmap* questionImageBitmap = new wxStaticBitmap();
    wxStaticText* questionText = new wxStaticText();

    wxString dataFilePath{};

    std::vector <Question> questions;
    size_t currentQuestionIndex = 0;

    void CreateControls();
    void BindEventHandlers();

    void OnInputEnter(wxCommandEvent &evt);
    void OnCheckAnswerButtonClicked(wxCommandEvent &evt);
    void OnNextQuestionButtonClicked(wxCommandEvent &evt);

    void CheckUserAnswer();
};
