#ifndef UIABSTARCTTEXTEDIT_H
#define UIABSTARCTTEXTEDIT_H

#include "GUI/UIWindow.h"
#include "GUI/TextEditController.h"

#define TEXTBOX_DATA_MAX_LEN 256

enum TextBoxStyle
{
    CHINESE_NORMAL = 0,
    ENGLISH_NORMAL,
    NUMBER_ONLY,
    PERCENTAGE
};

class UIAbstractTextEdit : public UIWindow
{
public:
    static const char* EventTextEditChange;
    UIAbstractTextEdit();
    UIAbstractTextEdit(UIContainer* pParent, DWORD rstrId);
    
    virtual ~UIAbstractTextEdit();

    virtual LPCSTR GetClassName() const { return "UIAbstractTextEdit"; }
    virtual bool OnTextEditChange(const EventArgs& args);
    
    
    //�������������Ϊ����  
    virtual int SetTip(const wchar_t *strText, int iStrLen = 0) = 0;   //������ʾ�ַ�
    virtual int SetTipUTF8(LPCSTR strText, int iStrLen = 0) = 0;
    virtual int SetText(const wchar_t *strText, int iStrLen = 0) = 0;   //�����ַ�
    virtual int SetTextUTF8(LPCSTR strText, int iStrLen = 0) = 0;
    virtual std::string GetTextUTF8() const = 0;
    virtual int InsertText(const wchar_t *strText, int iStrLen = 0) = 0;   //�����ַ�
    virtual int DeleteChar() = 0;

    virtual int InsertTextUTF8(LPCSTR strText, int iStrLen = 0) = 0;
    virtual int ClearText() = 0;                                                //����ַ�
    virtual void SelectAll(BOOL select = TRUE);
    virtual BOOL IsAllSelected();
    virtual void SetMaxDataLen(int iMaxLen) = 0;
    virtual bool IsActionKey(int iKeyCode);
    virtual char KeyCode2Char(int iKeyCode);

    virtual void SetFontSize(int fontSize) = 0;
    virtual int GetCurDataLen() const = 0;

    virtual BOOL OnDeletePress() = 0;
    virtual BOOL OnEnterPress() = 0;
    virtual BOOL OnDirectionPress(int iKeyCode) = 0;
    virtual BOOL OnFontPress();
    virtual BOOL OnBackPress();
    virtual BOOL OnSymPress();

    virtual void SetTextBoxStyle(TextBoxStyle eTextBoxStyle);
    virtual TextBoxStyle GetTextBoxStyle ();
    virtual int GetInputMode();

    virtual void SetMarginLeft(int marginLeft);
    virtual void SetMarginRight(int marginRight);
    virtual void SetMarginTop(int marginTop);
    virtual void SetMarginBottom(int marginBottom);

    virtual int GetMarginLeft() const;
    virtual int GetMarginRight() const;
    virtual int GetMarginTop() const;
    virtual int GetMarginBottom() const;

    virtual void SetBorderLinePixel(int borderLinePixel);
    virtual int GetBorderLinePixel() const;

    virtual void SetBorderSquareCorner(bool squareCorner);
    virtual bool IsBorderSquareCorner() const;

protected:
    void Init();

protected:
    //�߿� �������
    int m_nMarginLeft;      //��߾�
    int m_nMarginRight;     //�ұ߾�
    int m_nMarginTop;       //�ұ߾�
    int m_nMarginBottom;    //�ұ߾�
    bool m_bIsSquareCorner; //�߿�߽��Ƿ�ֱ��/Բ��
    bool m_nBorderLinePixel;//�߿��������
    BOOL m_fIsSelectAll;
    TextBoxStyle m_eTextBoxStyle;
    int m_inputMode;
};//UIAbstractTextEdit
#endif//UIABSTARCTTEXTEDIT_H
