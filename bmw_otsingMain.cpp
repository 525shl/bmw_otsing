/***************************************************************
 * Name:      bmw_otsingMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Janar Kivilo (m@kz.ee)
 * Created:   2015-11-27
 * Copyright: Janar Kivilo (kz.ee)
 * License:
 **************************************************************/

#include "bmw_otsingMain.h"
#include <wx/msgdlg.h>
#include "bmwIcon.h"

//(*InternalHeaders(bmw_otsingFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(bmw_otsingFrame)
const long bmw_otsingFrame::ID_TXTMUDEL = wxNewId();
const long bmw_otsingFrame::ID_MUDELCHOICE = wxNewId();
const long bmw_otsingFrame::ID_TXTGBOX = wxNewId();
const long bmw_otsingFrame::ID_TXTFUEL = wxNewId();
const long bmw_otsingFrame::ID_TXTAXLE = wxNewId();
const long bmw_otsingFrame::ID_TXTCHASSIS = wxNewId();
const long bmw_otsingFrame::ID_TXTKW = wxNewId();
const long bmw_otsingFrame::ID_TXTMAXPRICE = wxNewId();
const long bmw_otsingFrame::ID_CHASSISCHOICE = wxNewId();
const long bmw_otsingFrame::ID_BUTTONMANAUT = wxNewId();
const long bmw_otsingFrame::ID_BUTTONMANUAAL = wxNewId();
const long bmw_otsingFrame::ID_BUTTONAUTOMAAT = wxNewId();
const long bmw_otsingFrame::ID_BUTTONBENSIINDIISEL = wxNewId();
const long bmw_otsingFrame::ID_BUTTONBENSIIN = wxNewId();
const long bmw_otsingFrame::ID_BUTTONDIISEL = wxNewId();
const long bmw_otsingFrame::ID_TEXTHIND = wxNewId();
const long bmw_otsingFrame::ID_BUTTONTAGANELIK = wxNewId();
const long bmw_otsingFrame::ID_BUTTONTAGA = wxNewId();
const long bmw_otsingFrame::ID_BUTTONNELIK = wxNewId();
const long bmw_otsingFrame::ID_TXTMINPOWER = wxNewId();
const long bmw_otsingFrame::ID_TXTPOWERDIV = wxNewId();
const long bmw_otsingFrame::ID_TXTMAXPOWER = wxNewId();
const long bmw_otsingFrame::ID_BUTTONAUTO24 = wxNewId();
const long bmw_otsingFrame::ID_BUTTONMOTORS24 = wxNewId();
const long bmw_otsingFrame::ID_BUTTONSOOV = wxNewId();
const long bmw_otsingFrame::ID_BUTTONOKIDOKI = wxNewId();
const long bmw_otsingFrame::ID_BUTTONKULDNE = wxNewId();
const long bmw_otsingFrame::idMenuQuit = wxNewId();
const long bmw_otsingFrame::idMenuFaq = wxNewId();
const long bmw_otsingFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(bmw_otsingFrame,wxFrame)
    //(*EventTable(bmw_otsingFrame)
    //*)
END_EVENT_TABLE()

bmw_otsingFrame::bmw_otsingFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(bmw_otsingFrame)
    wxFlexGridSizer* soContainer;
    wxMenu* menuFile;
    wxGridBagSizer* gridContainer;
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* powerContainer;
    wxFlexGridSizer* gboxContainer;
    wxFlexGridSizer* kytusContainer;
    wxFlexGridSizer* axleContainer;
    wxMenu* menuHelp;
    wxFlexGridSizer* am24Container;
    wxMenuBar* menuBar;

    Create(parent, id, _("BMW otsing"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetMaxSize(wxSize(380,350));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxBITMAP_PNG_FROM_DATA(bmw_ico)));
    	SetIcon(FrameIcon);
    }
    gridContainer = new wxGridBagSizer(0, 0);
    txtMudel = new wxStaticText(this, ID_TXTMUDEL, _("Aastad"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_TXTMUDEL"));
    gridContainer->Add(txtMudel, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    mudelChoice = new wxChoice(this, ID_MUDELCHOICE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_MUDELCHOICE"));
    mudelChoice->SetSelection( mudelChoice->Append(_("kõik")) );
    mudelChoice->Append(_("E12"));
    mudelChoice->Append(_("E21"));
    mudelChoice->Append(_("E23"));
    mudelChoice->Append(_("E24"));
    mudelChoice->Append(_("E28"));
    mudelChoice->Append(_("E30"));
    mudelChoice->Append(_("E31"));
    mudelChoice->Append(_("E32"));
    mudelChoice->Append(_("E34"));
    mudelChoice->Append(_("E36"));
    mudelChoice->Append(_("E38"));
    mudelChoice->Append(_("E39"));
    mudelChoice->Append(_("E46"));
    gridContainer->Add(mudelChoice, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    txtgBox = new wxStaticText(this, ID_TXTGBOX, _("Käigukast"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_TXTGBOX"));
    gridContainer->Add(txtgBox, wxGBPosition(3, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    txtFuel = new wxStaticText(this, ID_TXTFUEL, _("Kütus"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_TXTFUEL"));
    gridContainer->Add(txtFuel, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    txtAxle = new wxStaticText(this, ID_TXTAXLE, _("Vedav sild"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_TXTAXLE"));
    gridContainer->Add(txtAxle, wxGBPosition(4, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    txtChassis = new wxStaticText(this, ID_TXTCHASSIS, _("Keretüüp"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_TXTCHASSIS"));
    gridContainer->Add(txtChassis, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    txtkW = new wxStaticText(this, ID_TXTKW, _("Võimsus (kW)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_TXTKW"));
    gridContainer->Add(txtkW, wxGBPosition(5, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    txtMaxPrice = new wxStaticText(this, ID_TXTMAXPRICE, _("Hind (max)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_TXTMAXPRICE"));
    gridContainer->Add(txtMaxPrice, wxGBPosition(6, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    chassisChoice = new wxChoice(this, ID_CHASSISCHOICE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHASSISCHOICE"));
    chassisChoice->SetSelection( chassisChoice->Append(_("kõik")) );
    chassisChoice->Append(_("sedaan"));
    chassisChoice->Append(_("universaal"));
    chassisChoice->Append(_("kupee"));
    chassisChoice->Append(_("kabriolett"));
    gridContainer->Add(chassisChoice, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    gboxContainer = new wxFlexGridSizer(1, 3, 0, 0);
    buttonManAut = new wxRadioButton(this, ID_BUTTONMANAUT, _("kõik"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_BUTTONMANAUT"));
    buttonManAut->SetValue(true);
    gboxContainer->Add(buttonManAut, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    buttonManuaal = new wxRadioButton(this, ID_BUTTONMANUAAL, _("manuaal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONMANUAAL"));
    gboxContainer->Add(buttonManuaal, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    buttonAutomaat = new wxRadioButton(this, ID_BUTTONAUTOMAAT, _("automaat"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONAUTOMAAT"));
    gboxContainer->Add(buttonAutomaat, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    gridContainer->Add(gboxContainer, wxGBPosition(3, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    kytusContainer = new wxFlexGridSizer(1, 3, 0, 0);
    buttonBensiinDiisel = new wxRadioButton(this, ID_BUTTONBENSIINDIISEL, _("kõik"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_BUTTONBENSIINDIISEL"));
    buttonBensiinDiisel->SetValue(true);
    kytusContainer->Add(buttonBensiinDiisel, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    buttonBensiin = new wxRadioButton(this, ID_BUTTONBENSIIN, _("bensiin"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONBENSIIN"));
    kytusContainer->Add(buttonBensiin, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    buttonDiisel = new wxRadioButton(this, ID_BUTTONDIISEL, _("diisel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONDIISEL"));
    kytusContainer->Add(buttonDiisel, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    gridContainer->Add(kytusContainer, wxGBPosition(2, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    textHind = new wxTextCtrl(this, ID_TEXTHIND, wxEmptyString, wxDefaultPosition, wxSize(60,-1), 0, wxDefaultValidator, _T("ID_TEXTHIND"));
    textHind->SetMaxLength(9);
    gridContainer->Add(textHind, wxGBPosition(6, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    axleContainer = new wxFlexGridSizer(1, 3, 0, 0);
    buttonTagaNelik = new wxRadioButton(this, ID_BUTTONTAGANELIK, _("kõik"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_BUTTONTAGANELIK"));
    buttonTagaNelik->SetValue(true);
    axleContainer->Add(buttonTagaNelik, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    buttonTaga = new wxRadioButton(this, ID_BUTTONTAGA, _("tagavedu"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONTAGA"));
    axleContainer->Add(buttonTaga, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    buttonNelik = new wxRadioButton(this, ID_BUTTONNELIK, _("nelikvedu"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONNELIK"));
    axleContainer->Add(buttonNelik, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    gridContainer->Add(axleContainer, wxGBPosition(4, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    powerContainer = new wxFlexGridSizer(1, 3, 0, 0);
    txtMinPower = new wxTextCtrl(this, ID_TXTMINPOWER, wxEmptyString, wxDefaultPosition, wxSize(60,-1), 0, wxDefaultValidator, _T("ID_TXTMINPOWER"));
    txtMinPower->SetMaxLength(4);
    powerContainer->Add(txtMinPower, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    txtPowerDivider = new wxStaticText(this, ID_TXTPOWERDIV, _("-"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_TXTPOWERDIV"));
    powerContainer->Add(txtPowerDivider, 1, wxTOP|wxBOTTOM|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    txtMaxPower = new wxTextCtrl(this, ID_TXTMAXPOWER, wxEmptyString, wxDefaultPosition, wxSize(60,-1), 0, wxDefaultValidator, _T("ID_TXTMAXPOWER"));
    txtMaxPower->SetMaxLength(5);
    powerContainer->Add(txtMaxPower, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    gridContainer->Add(powerContainer, wxGBPosition(5, 1), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    am24Container = new wxFlexGridSizer(1, 2, 0, 0);
    goAuto24 = new wxButton(this, ID_BUTTONAUTO24, _("Auto24"), wxDefaultPosition, wxSize(50,-1), 0, wxDefaultValidator, _T("ID_BUTTONAUTO24"));
    am24Container->Add(goAuto24, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
    goMotors24 = new wxButton(this, ID_BUTTONMOTORS24, _("Motors24"), wxDefaultPosition, wxSize(60,-1), 0, wxDefaultValidator, _T("ID_BUTTONMOTORS24"));
    am24Container->Add(goMotors24, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
    gridContainer->Add(am24Container, wxGBPosition(7, 0), wxDefaultSpan, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
    soContainer = new wxFlexGridSizer(1, 3, 0, 0);
    goSoov = new wxButton(this, ID_BUTTONSOOV, _("Soov"), wxDefaultPosition, wxSize(40,-1), 0, wxDefaultValidator, _T("ID_BUTTONSOOV"));
    soContainer->Add(goSoov, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
    goOkidoki = new wxButton(this, ID_BUTTONOKIDOKI, _("Okidoki"), wxDefaultPosition, wxSize(50,-1), 0, wxDefaultValidator, _T("ID_BUTTONOKIDOKI"));
    soContainer->Add(goOkidoki, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
    goKuldne = new wxButton(this, ID_BUTTONKULDNE, _("Kuldne Börs"), wxDefaultPosition, wxSize(70,-1), 0, wxDefaultValidator, _T("ID_BUTTONKULDNE"));
    soContainer->Add(goKuldne, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 3);
    gridContainer->Add(soContainer, wxGBPosition(7, 1), wxDefaultSpan, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
    SetSizer(gridContainer);
    menuBar = new wxMenuBar();
    menuFile = new wxMenu();
    MenuItem1 = new wxMenuItem(menuFile, idMenuQuit, _("Välju\tAlt-F4"), _("Sulge"), wxITEM_NORMAL);
    menuFile->Append(MenuItem1);
    menuBar->Append(menuFile, _("&Fail"));
    menuHelp = new wxMenu();
    MenuItem3 = new wxMenuItem(menuHelp, idMenuFaq, _("KKK"), wxEmptyString, wxITEM_NORMAL);
    menuHelp->Append(MenuItem3);
    MenuItem2 = new wxMenuItem(menuHelp, idMenuAbout, _("Teave\tF1"), wxEmptyString, wxITEM_NORMAL);
    menuHelp->Append(MenuItem2);
    menuBar->Append(menuHelp, _("Abi"));
    SetMenuBar(menuBar);
    gridContainer->Fit(this);
    gridContainer->SetSizeHints(this);
    Center();

    Connect(ID_BUTTONMANAUT,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&bmw_otsingFrame::OnbuttonManAutSelect);
    Connect(ID_BUTTONMANUAAL,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&bmw_otsingFrame::OnbuttonManuaalSelect);
    Connect(ID_BUTTONAUTOMAAT,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&bmw_otsingFrame::OnbuttonAutomaatSelect);
    Connect(ID_BUTTONBENSIINDIISEL,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&bmw_otsingFrame::OnbuttonBensiinDiiselSelect);
    Connect(ID_BUTTONBENSIIN,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&bmw_otsingFrame::OnbuttonBensiinSelect);
    Connect(ID_BUTTONDIISEL,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&bmw_otsingFrame::OnbuttonDiiselSelect);
    Connect(ID_BUTTONTAGANELIK,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&bmw_otsingFrame::OnbuttonTagaNelikSelect);
    Connect(ID_BUTTONTAGA,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&bmw_otsingFrame::OnbuttonTagaSelect);
    Connect(ID_BUTTONNELIK,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&bmw_otsingFrame::OnbuttonNelikSelect);
    Connect(ID_BUTTONAUTO24,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bmw_otsingFrame::OngoAuto24Click);
    Connect(ID_BUTTONMOTORS24,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bmw_otsingFrame::OngoMotors24Click);
    Connect(ID_BUTTONSOOV,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bmw_otsingFrame::OngoSoovClick);
    Connect(ID_BUTTONOKIDOKI,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bmw_otsingFrame::OngoOkidokiClick);
    Connect(ID_BUTTONKULDNE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bmw_otsingFrame::OngoKuldneClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bmw_otsingFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bmw_otsingFrame::OnAbout);
    Connect(idMenuFaq,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bmw_otsingFrame::OnFaq);
    //*)
}

bmw_otsingFrame::~bmw_otsingFrame()
{
    //(*Destroy(bmw_otsingFrame)
    //*)
}

void bmw_otsingFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void bmw_otsingFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxT("Autor: Janar Kivilo\nKontakt: m@kz.ee\n\n0.1a");
    wxMessageBox(msg, _("Programmi teave"));
}
void bmw_otsingFrame::OnFaq(wxCommandEvent& event)
{
    wxString msg = wxT("1. Miks ei ole voimalik valida esivedu?\n- hetkel olen pannud pohirohu mudelitele kuni E46");
    wxMessageBox(msg, _("Korduma kippuvad kusimused"));
}

// MUDELITE AASTAD
wxString yearBeginE12 = wxT("1972");
wxString yearEndE12 = wxT("1981");
wxString yearBeginE21 = wxT("1975");
wxString yearEndE21 = wxT("1981");
wxString yearBeginE23 = wxT("1977");
wxString yearEndE23 = wxT("1984");
wxString yearBeginE24 = wxT("1976");
wxString yearEndE24 = wxT("1988");
wxString yearBeginE28 = wxT("1982");
wxString yearEndE28 = wxT("1987");
wxString yearBeginE30 = wxT("1982");
wxString yearEndE30 = wxT("1993");
wxString yearBeginE31 = wxT("1989");
wxString yearEndE31 = wxT("1999");
wxString yearBeginE32 = wxT("1986");
wxString yearEndE32 = wxT("1994");
wxString yearBeginE34 = wxT("1988");
wxString yearEndE34 = wxT("1995");
wxString yearBeginE36 = wxT("1991");
wxString yearEndE36 = wxT("1998");
wxString yearBeginE38 = wxT("1994");
wxString yearEndE38 = wxT("2002");
wxString yearBeginE39 = wxT("1996");
wxString yearEndE39 = wxT("2003");
wxString yearBeginE46 = wxT("1998");
wxString yearEndE46 = wxT("2006");

// URL-s
wxString a24url = wxT("");
wxString m24url = wxT("");
wxString s24url = wxT("");
wxString o24url = wxT("");
wxString k24url = wxT("");

wxString sHind = wxT("");

wxString sMinKW = wxT("");
wxString sMaxKW = wxT("");

wxInt16 sFuelBensiin = false;
wxInt16 sFuelDiisel = false;

wxInt16 sgBoxMan = false;
wxInt16 sgBoxAut = false;

wxInt16 saxRear = false;
wxInt16 saxAwd = false;

wxInt16 iKere = 0;

wxInt16 iMudel = 0;

void bmw_otsingFrame::OnbuttonBensiinSelect(wxCommandEvent& event)
{
    sFuelBensiin = true;
    sFuelDiisel = false;
}

void bmw_otsingFrame::OnbuttonDiiselSelect(wxCommandEvent& event)
{
    sFuelBensiin = false;
    sFuelDiisel = true;
}

void bmw_otsingFrame::OnbuttonBensiinDiiselSelect(wxCommandEvent& event)
{
    sFuelBensiin = false;
    sFuelDiisel = false;
}

void bmw_otsingFrame::OnbuttonManuaalSelect(wxCommandEvent& event)
{
    sgBoxMan = true;
    sgBoxAut = false;
}

void bmw_otsingFrame::OnbuttonAutomaatSelect(wxCommandEvent& event)
{
    sgBoxMan = false;
    sgBoxAut = true;
}

void bmw_otsingFrame::OnbuttonManAutSelect(wxCommandEvent& event)
{
    sgBoxMan = false;
    sgBoxAut = false;
}

void bmw_otsingFrame::OnbuttonTagaSelect(wxCommandEvent& event)
{
    saxRear = true;
    saxAwd = false;
}

void bmw_otsingFrame::OnbuttonNelikSelect(wxCommandEvent& event)
{
    saxRear = false;
    saxAwd = true;
}

void bmw_otsingFrame::OnbuttonTagaNelikSelect(wxCommandEvent& event)
{
    saxRear = false;
    saxAwd = false;
}
// AUTO24
void bmw_otsingFrame::OngoAuto24Click(wxCommandEvent& event)
{
    // BLANK URL
    a24url = wxT("http://www.auto24.ee/kasutatud/nimekiri.php?bn=2&a=101&aj=&b=4&ae=2&af=50&ag=0&ag=1&otsi=otsi");

    // PRICE _GET
    sHind = textHind->GetValue();
    if(sHind.Len()>0) a24url += wxT("&g2=") + sHind;

    // KW _GET
    sMinKW = txtMinPower->GetValue();
    sMaxKW = txtMaxPower->GetValue();
    if(sMinKW.Len()>0) a24url += wxT("&k1=") + sMinKW;
    if(sMaxKW.Len()>0) a24url += wxT("&k2=") + sMaxKW;

    // CHASSIS _GET
    iKere = chassisChoice->GetSelection();
    if(iKere==1) a24url += wxT("&j=1");
    if(iKere==2) a24url += wxT("&j=3");
    if(iKere==3) a24url += wxT("&j=5");
    if(iKere==4) a24url += wxT("&j=6");

    // YEAR _GET
    iMudel = mudelChoice->GetSelection();
    if(iMudel==1) a24url += wxT("&f1=") + yearBeginE12 + wxT("&f2=") + yearEndE12;
    if(iMudel==2) a24url += wxT("&f1=") + yearBeginE21 + wxT("&f2=") + yearEndE21;
    if(iMudel==3) a24url += wxT("&f1=") + yearBeginE23 + wxT("&f2=") + yearEndE23;
    if(iMudel==4) a24url += wxT("&f1=") + yearBeginE24 + wxT("&f2=") + yearEndE24;
    if(iMudel==5) a24url += wxT("&f1=") + yearBeginE28 + wxT("&f2=") + yearEndE28;
    if(iMudel==6) a24url += wxT("&f1=") + yearBeginE30 + wxT("&f2=") + yearEndE30;
    if(iMudel==7) a24url += wxT("&f1=") + yearBeginE31 + wxT("&f2=") + yearEndE31;
    if(iMudel==8) a24url += wxT("&f1=") + yearBeginE32 + wxT("&f2=") + yearEndE32;
    if(iMudel==9) a24url += wxT("&f1=") + yearBeginE34 + wxT("&f2=") + yearEndE34;
    if(iMudel==10) a24url += wxT("&f1=") + yearBeginE36 + wxT("&f2=") + yearEndE36;
    if(iMudel==11) a24url += wxT("&f1=") + yearBeginE38 + wxT("&f2=") + yearEndE38;
    if(iMudel==12) a24url += wxT("&f1=") + yearBeginE39 + wxT("&f2=") + yearEndE39;
    if(iMudel==13) a24url += wxT("&f1=") + yearBeginE46 + wxT("&f2=") + yearEndE46;

    // FUEL _GET
    if(sFuelBensiin) a24url += wxT("&h=1");
    if(sFuelDiisel) a24url += wxT("&h=2");

    // GEARBOX _GET
    if(sgBoxMan) a24url += wxT("&i=1");
    if(sgBoxAut) a24url += wxT("&i=2");

    // AXLE _GET
    if(saxRear) a24url += wxT("&p=2");
    if(saxAwd) a24url += wxT("&p=3");

    // LAUNCH
    wxLaunchDefaultBrowser(a24url);
}

// MOTORS24
void bmw_otsingFrame::OngoMotors24Click(wxCommandEvent& event)
{
    // BLANK URL
    m24url = wxT("http://auto.motors24.ee/Default.aspx?page=list&reset=1&pg=0&sort=paid&sf=2&virtual=1&make_id=3&search_region=1");

    // PRICE _GET
    sHind = textHind->GetValue();
    if(sHind.Len()>0) m24url += wxT("&price_to=") + sHind;

    // KW _GET
    sMinKW = txtMinPower->GetValue();
    sMaxKW = txtMaxPower->GetValue();
    if(sMinKW.Len()>0) m24url += wxT("&power_from=") + sMinKW;
    if(sMaxKW.Len()>0) m24url += wxT("&power_to=") + sMaxKW;

    // CHASSIS _GET
    iKere = chassisChoice->GetSelection();
    if(iKere==1) m24url += wxT("&body_id=1");
    if(iKere==2) m24url += wxT("&body_id=3");
    if(iKere==3) m24url += wxT("&body_id=4");
    if(iKere==4) m24url += wxT("&body_id=5");

    // YEAR _GET
    iMudel = mudelChoice->GetSelection();
    if(iMudel==1) m24url += wxT("&year_from=1970&year_to=1985");
    if(iMudel==2) m24url += wxT("&year_from=") + yearBeginE21 + wxT("&year_to=1985");
    if(iMudel==3) m24url += wxT("&year_from=1975&year_to=1985");
    if(iMudel==4) m24url += wxT("&year_from=1975&year_to=1990");
    if(iMudel==5) m24url += wxT("&year_from=1980&year_to=1990");
    if(iMudel==6) m24url += wxT("&year_from=1980&year_to=") + yearEndE30;
    if(iMudel==7) m24url += wxT("&year_from=1985&year_to=") + yearEndE31;
    if(iMudel==8) m24url += wxT("&year_from=1985&year_to=") + yearEndE32;
    if(iMudel==9) m24url += wxT("&year_from=1985&year_to=") + yearEndE34;
    if(iMudel==10) m24url += wxT("&year_from=") + yearBeginE36 + wxT("&year_to=") + yearEndE36;
    if(iMudel==11) m24url += wxT("&year_from=") + yearBeginE38 + wxT("&year_to=") + yearEndE38;
    if(iMudel==12) m24url += wxT("&year_from=") + yearBeginE39 + wxT("&year_to=") + yearEndE39;
    if(iMudel==13) m24url += wxT("&year_from=") + yearBeginE46 + wxT("&year_to=") + yearEndE46;

    // FUEL _GET
    if(sFuelBensiin) m24url += wxT("&fuel_type=0");
    if(sFuelDiisel) m24url += wxT("&fuel_type=1");

    // GEARBOX _GET
    if(sgBoxMan) m24url += wxT("&transmission=0");
    if(sgBoxAut) m24url += wxT("&transmission=1");

    // AXLE _GET
    if(saxRear) m24url += wxT("&drive_type=1");
    if(saxAwd) m24url += wxT("&drive_type=2");

    // LAUNCH
    wxLaunchDefaultBrowser(m24url);
}

void bmw_otsingFrame::OngoSoovClick(wxCommandEvent& event)
{
    // BLANK URL
    s24url = wxT("http://www.soov.ee/eesti?q=&cg=1020&w=3&st=s&ps=&pe=&ms=&me=&cxpf=&cxpt=&gb=&fu=&ca=1&l=0&md=th&cb=3");

    // CHASSIS _GET
    iKere = chassisChoice->GetSelection();
    if(iKere==1) s24url += wxT("&ccsd=1");
    if(iKere==2) s24url += wxT("&ccco=1");
    if(iKere==3) s24url += wxT("&ccce=1");
    if(iKere==4) s24url += wxT("&ccca=1");

    // YEAR _GET
    iMudel = mudelChoice->GetSelection();
    if(iMudel==1) s24url += wxT("&mys=1970&mye=") + yearEndE12;
    if(iMudel==2) s24url += wxT("&mys=1970&mye=") + yearEndE21;
    if(iMudel==3) s24url += wxT("&mys=1970&mye=") + yearEndE23;
    if(iMudel==4) s24url += wxT("&mys=1970&mye=") + yearEndE24;
    if(iMudel==5) s24url += wxT("&mys=") + yearBeginE28 + wxT("&mye=") + yearEndE28;
    if(iMudel==6) s24url += wxT("&mys=") + yearBeginE30 + wxT("&mye=") + yearEndE30;
    if(iMudel==7) s24url += wxT("&mys=") + yearBeginE31 + wxT("&mye=") + yearEndE31;
    if(iMudel==8) s24url += wxT("&mys=") + yearBeginE32 + wxT("&mye=") + yearEndE32;
    if(iMudel==9) s24url += wxT("&mys=") + yearBeginE34 + wxT("&mye=") + yearEndE34;
    if(iMudel==10) s24url += wxT("&mys=") + yearBeginE36 + wxT("&mye=") + yearEndE36;
    if(iMudel==11) s24url += wxT("&mys=") + yearBeginE38 + wxT("&mye=") + yearEndE38;
    if(iMudel==12) s24url += wxT("&mys=") + yearBeginE39 + wxT("&mye=") + yearEndE39;
    if(iMudel==13) s24url += wxT("&mys=") + yearBeginE46 + wxT("&mye=") + yearEndE46;

    // FUEL _GET
    if(sFuelBensiin) s24url += wxT("&fu=1");
    if(sFuelDiisel) s24url += wxT("&fu=2");

    // GEARBOX _GET
    if(sgBoxMan) s24url += wxT("&gb=1");
    if(sgBoxAut) s24url += wxT("&gb=2");

    // AXLE _GET
    if(saxRear) s24url += wxT("&cxdw=1");
    if(saxAwd) s24url += wxT("&cxdw=2");

    // LAUNCH
    wxLaunchDefaultBrowser(s24url);
}

void bmw_otsingFrame::OngoOkidokiClick(wxCommandEvent& event)
{
    // BLANK URL
    o24url = wxT("http://www.okidoki.ee/buy/1601/?order=&i=&price_from_value=0&vat=0&c13=1343&c4=&c17=0&c17_to=0");

    // PRICE _GET
    sHind = textHind->GetValue();
    if(sHind.Len()>0) o24url += wxT("&price_to_value=") + sHind;

    // KW _GET
    sMinKW = txtMinPower->GetValue();
    sMaxKW = txtMaxPower->GetValue();
    if(sMinKW.Len()>0) o24url += wxT("&c20=") + sMinKW;
    if(sMaxKW.Len()>0) o24url += wxT("&c20_to=") + sMaxKW;

    // CHASSIS _GET
    iKere = chassisChoice->GetSelection();
    if(iKere==1) o24url += wxT("&c11=15");
    if(iKere==2) o24url += wxT("&c11=16");
    if(iKere==3) o24url += wxT("&c11=18");
    if(iKere==4) o24url += wxT("&c11=17");

    // YEAR _GET
    iMudel = mudelChoice->GetSelection();
    if(iMudel==1) o24url += wxT("&c14=1970&c14_to=1985");
    if(iMudel==2) o24url += wxT("&c14=") + yearBeginE21 + wxT("&c14_to=1985");
    if(iMudel==3) o24url += wxT("&c14=1975&c14_to=1990");
    if(iMudel==4) o24url += wxT("&c14=1975&c14_to=1990");
    if(iMudel==5) o24url += wxT("&c14=1980&c14_to=1990");
    if(iMudel==6) o24url += wxT("&c14=1980&c14_to=1995");
    if(iMudel==7) o24url += wxT("&c14=1985&c14_to=1999");
    if(iMudel==8) o24url += wxT("&c14=1985&c14_to=1995");
    if(iMudel==9) o24url += wxT("&c14=1990&c14_to=") + yearEndE34;
    if(iMudel==10) o24url += wxT("&c14=") + yearBeginE36 + wxT("&c14_to=") + yearEndE36;
    if(iMudel==11) o24url += wxT("&c14=") + yearBeginE38 + wxT("&c14_to=") + yearEndE38;
    if(iMudel==12) o24url += wxT("&c14=") + yearBeginE39 + wxT("&c14_to=") + yearEndE39;
    if(iMudel==13) o24url += wxT("&c14=") + yearBeginE46 + wxT("&c14_to=") + yearEndE46;

    // FUEL _GET
    if(sFuelBensiin) o24url += wxT("&c19=999");
    if(sFuelDiisel) o24url += wxT("&c19=1000");

    // GEARBOX _GET
    if(sgBoxMan) o24url += wxT("&c18=995");
    if(sgBoxAut) o24url += wxT("&c18=996");

    // AXLE _GET
    if(saxRear) o24url += wxT("&c26=1024");
    if(saxAwd) o24url += wxT("&c26=1025");

    // LAUNCH
    wxLaunchDefaultBrowser(o24url);
}

void bmw_otsingFrame::OngoKuldneClick(wxCommandEvent& event)
{
    // BLANK URL
    k24url = wxT("http://kuldnebors.ee/search/search.mec?search_evt=onsearch&search_X_cat_ids=11050&pob_action=search&pob_cat_id=11050&search_O_deal_type=M");

    // PRICE _GET
    sHind = textHind->GetValue();
    if(sHind.Len()>0) k24url += wxT("&search_O_price_to=") + sHind;

    // KW _GET
    sMaxKW = txtMaxPower->GetValue();
    if(sMaxKW.Len()>0) k24url += wxT("&search_O_string=") + sMaxKW + wxT("+kW");

    // CHASSIS _GET
    iKere = chassisChoice->GetSelection();
    if(iKere==1) k24url += wxT("&search_C_body_type=SE");
    if(iKere==2) k24url += wxT("&search_C_body_type=UN");
    if(iKere==3) k24url += wxT("&search_C_body_type=CP");
    if(iKere==4) k24url += wxT("&search_C_body_type=CV");

    // YEAR _GET
    iMudel = mudelChoice->GetSelection();
    if(iMudel==1) k24url += wxT("&search_C_year_from=1970&search_C_year_to=1990");
    if(iMudel==2) k24url += wxT("&search_C_year_from=1970&search_C_year_to=1990");
    if(iMudel==3) k24url += wxT("&search_C_year_from=1970&search_C_year_to=1990");
    if(iMudel==4) k24url += wxT("&search_C_year_from=1970&search_C_year_to=1990");
    if(iMudel==5) k24url += wxT("&search_C_year_from=1980&search_C_year_to=1990");
    if(iMudel==6) k24url += wxT("&search_C_year_from=1980&search_C_year_to=") + yearEndE30;
    if(iMudel==7) k24url += wxT("&search_C_year_from=1980&search_C_year_to=") + yearEndE31;
    if(iMudel==8) k24url += wxT("&search_C_year_from=1980&search_C_year_to=") + yearEndE32;
    if(iMudel==9) k24url += wxT("&search_C_year_from=1980&search_C_year_to=") + yearEndE34;
    if(iMudel==10) k24url += wxT("&search_C_year_from=") + yearBeginE36 + wxT("&search_C_year_to=") + yearEndE36;
    if(iMudel==11) k24url += wxT("&search_C_year_from=") + yearBeginE38 + wxT("&search_C_year_to=") + yearEndE38;
    if(iMudel==12) k24url += wxT("&search_C_year_from=") + yearBeginE39 + wxT("&search_C_year_to=") + yearEndE39;
    if(iMudel==13) k24url += wxT("&search_C_year_from=") + yearBeginE46 + wxT("&search_C_year_to=") + yearEndE46;

    // FUEL _GET
    if(sFuelBensiin) k24url += wxT("&search_C_fuel_type=P");
    if(sFuelDiisel) k24url += wxT("&search_C_fuel_type=D");

    // GEARBOX _GET
    if(sgBoxMan) k24url += wxT("&search_C_gear_type=M");
    if(sgBoxAut) k24url += wxT("&search_C_gear_type=A");

    // AXLE _GET
    if(saxRear) k24url += wxT("&search_C_drive_type=R");
    if(saxAwd) k24url += wxT("&search_C_drive_type=4");

    // LAUNCH
    wxLaunchDefaultBrowser(k24url);
}
