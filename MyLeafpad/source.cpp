#include <wx/wx.h>
#include "leafpadUI.h"

//メインアプリケーションクラス:wxAppの継承，OnInitのオーバーライド
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

//内部でwxAppの代わりにMyAppが呼ばれるように設定する
wxIMPLEMENT_APP(MyApp);

//メインフレームクラス:精製したMyFrame1の継承，prime_checkのオーバーライド
class MyFrame : public MyFrame1
{
public:
    //コンストラクタ・デコンストラクタはMyFrame1と全く同じにする
    using MyFrame1::MyFrame1;

private:
    //***********以下イベント処理**********

    //TextCtrlの文字列の消去について確認
    //メッセージダイアログがYESだったらLabelを空文字列に
    void evt_clear(wxCommandEvent& event)
    {
        auto dlg = new wxMessageDialog(this, wxString("Text will be cleared. Are you sure?"), wxString("Conform"), wxYES_NO);
        if (dlg->ShowModal() == wxID_YES)
        {
            m_textCtrl1->SetLabelText(wxEmptyString);
        }
        delete dlg;
    }

    //ロードするファイルをダイアログで選択
    //文字列(==path)が返ってきたらそのpathのファイルをtextCtrlにロード
    void evt_load(wxCommandEvent& event)
    {
        wxString f = wxLoadFileSelector(wxString("Select a file to load"), wxString(".*"));
        if (!f.empty())
        {
            m_textCtrl1->LoadFile(f);

        }
    }
    //ロードするファイルをダイアログで選択
    //文字列(==path)が返ってきたらそのpathのファイルにtextCtrlのLabelを出力
    void evt_save(wxCommandEvent& event)
    {
        wxString f = wxSaveFileSelector(wxString("Select a file to save"), wxString(".*"), wxString("noname.txt"));
        if (!f.empty())
        {
            m_textCtrl1->SaveFile(f);
        }
    }

};




//wxWidgetsにおける実質的なmain関数
//基本的にメインフレームをつくり，表示するだけ
bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(NULL);
    frame->Show(true);
    return true;
}