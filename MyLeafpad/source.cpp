#include <wx/wx.h>
#include "leafpadUI.h"

//���C���A�v���P�[�V�����N���X:wxApp�̌p���COnInit�̃I�[�o�[���C�h
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

//������wxApp�̑����MyApp���Ă΂��悤�ɐݒ肷��
wxIMPLEMENT_APP(MyApp);

//���C���t���[���N���X:��������MyFrame1�̌p���Cprime_check�̃I�[�o�[���C�h
class MyFrame : public MyFrame1
{
public:
    //�R���X�g���N�^�E�f�R���X�g���N�^��MyFrame1�ƑS�������ɂ���
    using MyFrame1::MyFrame1;

private:
    //***********�ȉ��C�x���g����**********

    //TextCtrl�̕�����̏����ɂ��Ċm�F
    //���b�Z�[�W�_�C�A���O��YES��������Label���󕶎����
    void evt_clear(wxCommandEvent& event)
    {
        auto dlg = new wxMessageDialog(this, wxString("Text will be cleared. Are you sure?"), wxString("Conform"), wxYES_NO);
        if (dlg->ShowModal() == wxID_YES)
        {
            m_textCtrl1->SetLabelText(wxEmptyString);
        }
        delete dlg;
    }

    //���[�h����t�@�C�����_�C�A���O�őI��
    //������(==path)���Ԃ��Ă����炻��path�̃t�@�C����textCtrl�Ƀ��[�h
    void evt_load(wxCommandEvent& event)
    {
        wxString f = wxLoadFileSelector(wxString("Select a file to load"), wxString(".*"));
        if (!f.empty())
        {
            m_textCtrl1->LoadFile(f);

        }
    }
    //���[�h����t�@�C�����_�C�A���O�őI��
    //������(==path)���Ԃ��Ă����炻��path�̃t�@�C����textCtrl��Label���o��
    void evt_save(wxCommandEvent& event)
    {
        wxString f = wxSaveFileSelector(wxString("Select a file to save"), wxString(".*"), wxString("noname.txt"));
        if (!f.empty())
        {
            m_textCtrl1->SaveFile(f);
        }
    }

};




//wxWidgets�ɂ���������I��main�֐�
//��{�I�Ƀ��C���t���[��������C�\�����邾��
bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(NULL);
    frame->Show(true);
    return true;
}