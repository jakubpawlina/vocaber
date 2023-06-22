#pragma once
#include <wx/wx.h>
#include <wx/filename.h>
#include "FinishFrame.h"
#include "defines/config_path.h"
#include "utilities/validate_json_input.h"
#include "classes/Question.h"
#include "utilities/load_questions_from_json.h"
#include "utilities/scale_wx_bitmap.h"

class LearnFrame : public wxFrame {
public:
    explicit LearnFrame(const wxString& title, const wxString& dataFilePath, nlohmann::json &json);

private:
    std::string setTitle{};

    const std::string defaultQuestionImagePath = CONFIG_PATH "/question-mark.jpg";

    wxStaticText* staticText = new wxStaticText(this, wxID_ANY, "");
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxTextCtrl* userAnswerInput = new wxTextCtrl();
    wxButton* checkAnswerButton = new wxButton();
    wxButton* nextQuestionButton = new wxButton();
    wxStaticBitmap* questionImageBitmap = new wxStaticBitmap(this, wxID_ANY, wxBitmap());
    wxStaticText* questionText = new wxStaticText();

    wxString dataFilePath{};

    std::vector <Question> questions;
    size_t currentQuestionIndex_ = 0;

    unsigned int acquiredResult = 0;

    void CreateControls();
    void BindEventHandlers();

    wxBitmap getQuestionImage(size_t currentQuestionIndex);

    void OnInputEnter(wxCommandEvent &evt);
    void OnCheckAnswerButtonClicked(wxCommandEvent &evt);
    void OnNextQuestionButtonClicked(wxCommandEvent &evt);

    void CheckUserAnswer();
};
