/***************************************************************
 * Name:      bmw_otsingMain.h
 * Purpose:   Defines Application Frame
 * Author:    Janar Kivilo (m@kz.ee)
 * Created:   2015-11-27
 * Copyright: Janar Kivilo (kz.ee)
 * License:
 **************************************************************/

#ifndef BMW_OTSINGMAIN_H
#define BMW_OTSINGMAIN_H

//(*Headers(bmw_otsingFrame)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/choice.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class bmw_otsingFrame: public wxFrame
{
    public:

        bmw_otsingFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~bmw_otsingFrame();

    private:

        //(*Handlers(bmw_otsingFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnFaq(wxCommandEvent& event);
        void OngoAuto24Click(wxCommandEvent& event);
        void OnbuttonBensiinSelect(wxCommandEvent& event);
        void OnbuttonDiiselSelect(wxCommandEvent& event);
        void OnbuttonBensiinDiiselSelect(wxCommandEvent& event);
        void OnbuttonManuaalSelect(wxCommandEvent& event);
        void OnbuttonAutomaatSelect(wxCommandEvent& event);
        void OnbuttonManAutSelect(wxCommandEvent& event);
        void OnbuttonTagaSelect(wxCommandEvent& event);
        void OnbuttonNelikSelect(wxCommandEvent& event);
        void OnbuttonTagaNelikSelect(wxCommandEvent& event);
        void OngoMotors24Click(wxCommandEvent& event);
        void OngoSoovClick(wxCommandEvent& event);
        void OngoOkidokiClick(wxCommandEvent& event);
        void OngoKuldneClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(bmw_otsingFrame)
        static const long ID_TXTMUDEL;
        static const long ID_MUDELCHOICE;
        static const long ID_TXTGBOX;
        static const long ID_TXTFUEL;
        static const long ID_TXTAXLE;
        static const long ID_TXTCHASSIS;
        static const long ID_TXTKW;
        static const long ID_TXTMAXPRICE;
        static const long ID_CHASSISCHOICE;
        static const long ID_BUTTONMANAUT;
        static const long ID_BUTTONMANUAAL;
        static const long ID_BUTTONAUTOMAAT;
        static const long ID_BUTTONBENSIINDIISEL;
        static const long ID_BUTTONBENSIIN;
        static const long ID_BUTTONDIISEL;
        static const long ID_TEXTHIND;
        static const long ID_BUTTONTAGANELIK;
        static const long ID_BUTTONTAGA;
        static const long ID_BUTTONNELIK;
        static const long ID_TXTMINPOWER;
        static const long ID_TXTPOWERDIV;
        static const long ID_TXTMAXPOWER;
        static const long ID_BUTTONAUTO24;
        static const long ID_BUTTONMOTORS24;
        static const long ID_BUTTONSOOV;
        static const long ID_BUTTONOKIDOKI;
        static const long ID_BUTTONKULDNE;
        static const long idMenuQuit;
        static const long idMenuFaq;
        static const long idMenuAbout;
        //*)

        //(*Declarations(bmw_otsingFrame)
        wxChoice* mudelChoice;
        wxStaticText* txtMudel;
        wxStaticText* txtChassis;
        wxStaticText* txtkW;
        wxButton* goSoov;
        wxRadioButton* buttonDiisel;
        wxStaticText* txtgBox;
        wxButton* goOkidoki;
        wxButton* goAuto24;
        wxRadioButton* buttonAutomaat;
        wxButton* goMotors24;
        wxRadioButton* buttonBensiinDiisel;
        wxRadioButton* buttonBensiin;
        wxRadioButton* buttonNelik;
        wxStaticText* txtAxle;
        wxButton* goKuldne;
        wxRadioButton* buttonManAut;
        wxChoice* chassisChoice;
        wxMenuItem* MenuItem3;
        wxStaticText* txtPowerDivider;
        wxRadioButton* buttonTagaNelik;
        wxTextCtrl* txtMaxPower;
        wxTextCtrl* textHind;
        wxRadioButton* buttonManuaal;
        wxRadioButton* buttonTaga;
        wxTextCtrl* txtMinPower;
        wxStaticText* txtMaxPrice;
        wxStaticText* txtFuel;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // BMW_OTSINGMAIN_H
