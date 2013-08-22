#include "GUI/UISizer.h"
#include "CommonUI/UIModifyAccountInfoDlg.h"
#include "CommonUI/UIIMEManager.h"
#include "Common/CAccountManager.h"
#include "Common/WindowsMetrics.h"
#include "I18n/StringManager.h"
#include "Framework/CDisplay.h"
#include <tr1/functional>

using namespace WindowsMetrics;
using namespace dk::account;

UIModifyAccountInfoDlg::UIModifyAccountInfoDlg(UIContainer* pParent)
	: UIModalDlg(pParent, StringManager::GetPCSTRById(TOUCH_SYSTEMSETTING_ACCOUNT_MODIFYUSER))
    , m_pModifyPwdSizer(NULL)
	, m_bIsModifyPwd(false)
    , m_loginAction(LA_NONE)
{
	InitUI();
    SubscribeMessageEvent(CAccountManager::EventAccount,
            *CAccountManager::GetInstance(),
            std::tr1::bind(
                std::tr1::mem_fn(&UIModifyAccountInfoDlg::OnLoginEvent),
                this,
                std::tr1::placeholders::_1));
}

UIModifyAccountInfoDlg::~UIModifyAccountInfoDlg()
{
}

void UIModifyAccountInfoDlg::InitUI()
{
	int modifyFontsize = GetWindowFontSize(UIModifyAccountInfoDlgIndex);
	m_textAlias.SetText(StringManager::GetPCSTRById(TOUCH_SYSTEMSETTING_ALIAS));
	m_textAlias.SetFontSize(modifyFontsize);

	m_textTips.SetFontSize(modifyFontsize);
	m_textTips.SetReversedColor(true);
    m_textTips.SetVisible(false);

	m_editAlias.SetTextUTF8(CAccountManager::GetInstance()->GetAliasFromFile().c_str(), 0);
	m_editAlias.SetFontSize(modifyFontsize);

	m_btnModifyPassword.Initialize(ID_BTN_MODIFY_PASSWORD, StringManager::GetPCSTRById(TOUCH_SYSTEMSETTING_MODIFY_PASSWORD), modifyFontsize);
	m_btnModifyPassword.ShowBorder(false);

	m_btnCancel.Initialize(IDCANCEL,  StringManager::GetStringById(ACTION_CANCEL), modifyFontsize, SPtr<ITpImage>());
	m_btnConfirm.Initialize(IDOK,  StringManager::GetStringById(ACCOUNT_MODIFYUSER), modifyFontsize, SPtr<ITpImage>());

	m_editOldPwd.SetTipUTF8(StringManager::GetPCSTRById(ACCOUNT_OLDPASSWORD));
	m_editOldPwd.SetFontSize(modifyFontsize);

	m_editNewPwd.SetTipUTF8(StringManager::GetPCSTRById(ACCOUNT_NEWPASSWORD));
	m_editNewPwd.SetFontSize(modifyFontsize);

	AppendChild(&m_textAlias);
	AppendChild(&m_editAlias);
	AppendChild(&m_btnModifyPassword);
	AppendChild(&m_editOldPwd);
    AppendChild(&m_editNewPwd);
    AppendChild(&m_textTips);
    m_btnGroup.AddButton(&m_btnCancel);
    m_btnGroup.AddButton(&m_btnConfirm);
    if (m_windowSizer)
    {
        m_editAlias.SetMinHeight(GetWindowMetrics(UIModalDialogEditBoxIndex));
        m_editOldPwd.SetMinHeight(GetWindowMetrics(UIModalDialogEditBoxIndex));
        m_editNewPwd.SetMinHeight(GetWindowMetrics(UIModalDialogEditBoxIndex));

        UISizer* topSizer = new UIBoxSizer(dkHORIZONTAL);
        if (topSizer)
        {
            topSizer->Add(&m_textAlias);
            topSizer->AddStretchSpacer();
            topSizer->Add(&m_textTips);
            m_windowSizer->Add(topSizer, UISizerFlags().Border(dkLEFT | dkRIGHT, GetWindowMetrics(UIModalDialogHorizonMarginIndex)));
        }
        m_windowSizer->AddSpacer(GetWindowMetrics(UIModifyAccountInfoDlgVertMarginIndex));
        m_windowSizer->Add(&m_editAlias, UISizerFlags().Expand().Border(dkLEFT | dkRIGHT, GetWindowMetrics(UIModalDialogHorizonMarginIndex)));
        m_windowSizer->AddSpacer(GetWindowMetrics(UIModifyAccountInfoDlgVertMarginIndex));
        m_windowSizer->Add(&m_btnModifyPassword, UISizerFlags().Align(dkALIGN_RIGHT).Border(dkRIGHT, GetWindowMetrics(UIModalDialogHorizonMarginIndex)));

        if (!m_pModifyPwdSizer)
        {
            m_pModifyPwdSizer = new UIBoxSizer(dkVERTICAL);
            m_pModifyPwdSizer->AddSpacer(GetWindowMetrics(UIModifyAccountInfoDlgVertMarginIndex));
            m_pModifyPwdSizer->Add(&m_editOldPwd, UISizerFlags().Expand());
            m_pModifyPwdSizer->AddSpacer(GetWindowMetrics(UIModifyAccountInfoDlgVertMarginIndex));
            m_pModifyPwdSizer->Add(&m_editNewPwd, UISizerFlags().Expand());
            m_windowSizer->Add(m_pModifyPwdSizer, UISizerFlags().Border(dkLEFT | dkRIGHT, GetWindowMetrics(UIModalDialogHorizonMarginIndex)).Expand());
        }
        m_windowSizer->AddSpacer(GetWindowMetrics(UIModifyAccountInfoDlgVertMarginIndex));
        m_windowSizer->Add(&m_btnGroup, UISizerFlags().Expand());
    }
	ResizeDialog();
	SetChildWindowFocus(GetChildIndex(&m_editAlias), false);
    UIIME* pIME = UIIMEManager::GetIME(IUIIME_ENGLISH_LOWER, &m_editAlias);
    if (pIME)
    {
        pIME->SetShowDelay(true);
    }
}


void UIModifyAccountInfoDlg::OnCommand(DWORD dwCmdId, UIWindow* pSender, DWORD dwParam)
{
	switch (dwCmdId) 
	{
	case ID_BTN_MODIFY_PASSWORD:
		{
			m_bIsModifyPwd = !m_bIsModifyPwd;
			m_editAlias.SetEnable(!m_bIsModifyPwd);
            ResizeDialog();
            if (m_pParent)
                m_pParent->UpdateWindow();
			break;
		}
	case IDOK:
		{
			Modify();
			break;
		}
	case IDCANCEL:
		EndDialog(0);
		break;
	}
}

void UIModifyAccountInfoDlg::SetTips(LPCSTR str)
{
	if (!str)
	{
		DebugPrintf(DLC_ERROR, "Null Pointer! %s::%s, %s(%d)", GetClassName(), __FUNCTION__, __FILE__, __LINE__);
		return;
	}

    m_textTips.SetText(str);
    m_textTips.SetVisible(true);
    Layout();
	m_textTips.UpdateWindow();

}

void UIModifyAccountInfoDlg::ModifyAlias(string alias)
{
    m_loginAction |= LA_CHANGING_ALIAS;
	CAccountManager* pManager = CAccountManager::GetInstance();
	pManager->ChangeAliasAsync(pManager->GetEmailFromFile(), alias);
}

void UIModifyAccountInfoDlg::ModifyPassword(string oldPwd, string newPwd)
{
    m_loginAction |= LA_CHANGING_PASSWORD;
	CAccountManager* pManager = CAccountManager::GetInstance();
	pManager->ChangePasswordAsync(pManager->GetEmailFromFile(), oldPwd, newPwd);
}

void UIModifyAccountInfoDlg::Modify()
{
    m_loginAction = LA_NONE;
	std::string strAlias  = m_editAlias.GetTextUTF8();
	std::string strOldPwd = m_editOldPwd.GetTextUTF8();
	std::string strNewPwd = m_editNewPwd.GetTextUTF8();

	if(m_bIsModifyPwd)
	{
		if (!strOldPwd.empty() && !strNewPwd.empty())
		{
			ModifyPassword(strOldPwd.c_str(), strNewPwd.c_str());
		}
		else
		{
			SetTips(StringManager::GetPCSTRById(TOUCH_SYSTEMSETTING_PWD_MUSTNOT_NULL));
		}
	}
	else
	{
		if (!strAlias.empty())
		{
			ModifyAlias(strAlias.c_str());
		}
		else
		{
			m_editAlias.SetTipUTF8(StringManager::GetPCSTRById(TOUCH_SYSTEMSETTING_ALIAS_MUSTNOT_NULL));
			m_editAlias.SetFocus(TRUE);
			m_editAlias.UpdateWindow();
		}
	}
    if (m_loginAction != LA_NONE)
    {
        m_btnConfirm.SetEnable(false);
    }
}

void UIModifyAccountInfoDlg::ResizeDialog()
{
    if (m_pModifyPwdSizer)
    {
        m_pModifyPwdSizer->Show(m_bIsModifyPwd);
    }
	if (m_bIsModifyPwd) 
    {
		m_btnModifyPassword.SetIcon(ImageManager::GetImage(IMAGE_IME_UP), UIButton::ICON_RIGHT);
	}
	else
	{
		m_btnModifyPassword.SetIcon(ImageManager::GetImage(IMAGE_IME_DOWN), UIButton::ICON_RIGHT);
	}

    if (m_windowSizer)
    {
        const int width = GetWindowMetrics(UIModalDialogWidthIndex);
        const int height = m_windowSizer->GetMinSize().GetHeight();
        MakeCenterAboveIME(width, height);

        Layout();
    }
}

bool UIModifyAccountInfoDlg::OnLoginEvent(const EventArgs& args)
{
    const AccountEventArgs& accountEventArgs = 
        (const AccountEventArgs&)args;
    bool processed = false;
    if (LA_CHANGING_ALIAS & m_loginAction)
    {
        if (AccountEventArgs::LS_CHANGE_ALIAS_FAILED == accountEventArgs.logStatus)
        {
            SetTips(accountEventArgs.errorMessage.c_str());
            m_loginAction &= ~LA_CHANGING_ALIAS;
            m_loginAction |= LA_CHANGING_ALIAS_FAILED;
            processed = true;
        }
        if (AccountEventArgs::LS_CHANGE_ALIAS_SUCCEEDED == accountEventArgs.logStatus)
        {
            SetTips(StringManager::GetPCSTRById(ACCOUNT_USERNAMEMODIFYSUCCEED));
            m_loginAction &= ~(LA_CHANGING_ALIAS | LA_CHANGING_ALIAS_FAILED);
            if (LA_NONE == m_loginAction)
            {
                EndDialog(IDOK);
                processed = true;
            }
        }
    }
    if (LA_CHANGING_PASSWORD & m_loginAction)
    {
        if (AccountEventArgs::LS_CHANGE_PASSWORD_FAILED == accountEventArgs.logStatus)
        {
            SetTips(accountEventArgs.errorMessage.c_str());
            m_loginAction &= ~LA_CHANGING_PASSWORD;
            m_loginAction |= LA_CHANGING_ALIAS_FAILED;
            processed = true;
        }
        if (AccountEventArgs::LS_CHANGE_PASSWORD_SUCCEEDED == accountEventArgs.logStatus)
        {
            SetTips(StringManager::GetPCSTRById(ACCOUNT_PASSWORDMODIFYSUCCEED));
            m_loginAction &= ~(LA_CHANGING_PASSWORD | LA_CHANGING_PASSWORD_FAILED);
            if (LA_NONE == m_loginAction)
            {
                EndDialog(IDOK);
                processed = true;
            }
        }
    }
    if (!(m_loginAction & LA_CHANGING))
    {
        m_btnConfirm.SetEnable(true);
    }
    return processed;
}

