#ifndef __UICOMMENTORSUMMARYSELECTDLG_H_
#define __UICOMMENTORSUMMARYSELECTDLG_H_

#include "GUI/UIContainer.h"
#include "GUI/UITouchComplexButton.h"
#include "GUI/UITextSingleLine.h"
#include "GUI/UIText.h"
#include "GUI/UIPlainTextEdit.h"
#include "TouchAppUI/UIDictionaryDialog.h"
#include "GUI/UIButtonGroup.h"
#include "singleton.h"
#include <vector>
#include "KernelEncoding.h"

// class defined in this file
class UICommentWnd;
class UICommentOrSummary;

/*****************************************************
* UICommentOrSummary
*****************************************************/
class UICommentOrSummary : public UIContainer
{
   SINGLETON_H(UICommentOrSummary);
public:
	UICommentOrSummary();
    virtual ~UICommentOrSummary();
    virtual LPCSTR GetClassName() const { return "UICommentOrSummary"; }
    virtual HRESULT Draw(DK_IMAGE drawingImg);
    virtual void OnCommand(DWORD _dwCmdId, UIWindow* _pSender, DWORD _dwParam);
    virtual bool SetVisible(bool _bVisible);

	//������ժ��ǩ��״̬��Ҫ����Ĵ�
    void SetShowStatusAndText(bool hasComment, bool hasDigest, const char* pWord);
	string GetWords();
	void SetIsLink(bool _bIsLink);
    void SetIsDuokanBook(bool isDuokanBook);
    void SetInGallery(bool inGallery);
    virtual bool OnHookTouch(MoveEvent* moveEvent);
    virtual dkSize GetMinSize() const;

    void SetOffsetXY(int offsetX, int offsetY, int maxX, int maxY);

    void SetVerticalDirection(bool vertical)
    {
        m_bIsForVerticalForms = vertical;
    }
    bool IsDirectionVertical() const
    {
        return m_bIsForVerticalForms && !m_bIsShowDictionary;
    }
private:
	void InitUI();
	string GetTranslateMean(string& outPutWord);
	string GetTextFromHtml(const string& strMean);
	
private:
	bool				   m_bIsShowDictionary;  //�Ƿ���ʾ����
	bool				   m_bHasComment;		 //�Ƿ�����ע
	bool 				   m_bHasDigest;		 //�Ƿ�����ժ
	bool				   m_bIsLink;
    bool                   m_bIsDuokanBook;
    bool                   m_bIsForVerticalForms;//����ʱĳЩ����°�ťͬ������
    bool m_inGallery;
    UITouchComplexButton   m_btnLeft;
    UITouchComplexButton   m_btnRight;
    UITouchComplexButton   m_btnShare;
	UITouchComplexButton   m_btnTranslateOrMore;
	UITouchComplexButton   m_btnCancelIcon;   //�˴���û�м̳�UIModalDlg
	UITouchComplexButton   m_btnJumpToLink;
    UITouchComplexButton   m_btnCorrection;
    UITouchComplexButton   m_btnWebSearch;
    UITextSingleLine       m_txtTitle;
	string                 m_szSimpleWord;
	UIText				   m_txtWordMean;
};

#endif
