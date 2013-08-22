////////////////////////////////////////////////////////////////////////
// UITextBox.h
// Contact: genchw
// Copyright (c) Duokan Corporation. All rights reserved.
//
//
////////////////////////////////////////////////////////////////////////

#ifndef __UITEXTBOX_H__
#define __UITEXTBOX_H__

#include "GUI/UIAbstractTextEdit.h"
#include "dkBaseType.h"
#include "GUI/EventArgs.h"
#include "GUI/TextEditController.h"

class UIImage;

#ifdef KINDLE_FOR_TOUCH
typedef BOOL (*FuncKeyPress)(const wchar_t* strText, INT32 iStrLen);
BOOL NormalCallBack(const wchar_t* strText, INT32 iStrLen);
BOOL NumberCallBack(const wchar_t* strText,INT32 iStrLen);
BOOL PercentageCallBack(const wchar_t* strText,INT32 iStrLen);
#else
typedef BOOL (*FuncKeyPress)( const wchar_t* strText, wchar_t* keychar);
BOOL NormalCallBack( const wchar_t* strText, wchar_t* keychar);
BOOL NumberCallBack( const wchar_t* strText, wchar_t* keychar);
BOOL PercentageCallBack( const wchar_t* strText, wchar_t* keychar);
#endif

class UITextBox 
    : public UIAbstractTextEdit
{
public:
    enum EchoMode
    {
        Normal,
        Password,
        PasswordEchoOnEdit
    };

    //static const char* EventTextChange;
    //���캯��
    UITextBox();
    UITextBox(UIContainer* pParent, DWORD rstrId);
    virtual ~UITextBox();
    //ϵͳ��
    virtual LPCSTR GetClassName() const {return ("UITextBox");}
    virtual HRESULT UpdateFocus();
    //��ͼ���� �̳���UIWindow
    virtual HRESULT Draw(DK_IMAGE drawingImg);
    void SetFont(INT32 iFace, INT32 iStyle, INT32 iSize);
    void OnResize(INT32 iWidth, INT32 iHeight);
    EchoMode GetEchoMode() const;
    void SetEchoMode(EchoMode echoMode);
    static void EchoAsAsterisksInstead(void* dummy);
    //��Ϣ���պ��� �̳���UIWindow
    virtual BOOL OnKeyPress(INT32 iKeyCode);
    void SetImage(SPtr<ITpImage> _spImage);
    void SetImage(int imageID, int focusedImageID);
    
    //�������������Ϊ����  
    virtual INT32 SetTip(const wchar_t* strText, INT32 iStrLen = 0);   //������ʾ�ַ�
    virtual INT32 SetTipUTF8(const char* strText, INT32 iStrLen = 0);
    virtual INT32 SetText(const wchar_t* strText, INT32 iStrLen = 0);   //�����ַ�
    virtual INT32 SetTextUTF8(const char* strText, INT32 iStrLen = 0);
    virtual std::string GetTextUTF8() const;
    virtual INT32 InsertText(const wchar_t *strText, INT32 iStrLen = 0);   //�����ַ�
    virtual INT32 DeleteChar();
    void ShowBorder(bool showBorder);
    // ��ʱ�����Ҫ����Ӧ�¼��ĺ��������ж�����ֵ�Ƿ�Ϸ���Ķ���������Ե�ǰ��UITextBox�����޸ģ�����FireEvent���������ѭ��
    void DoFireEvent(bool fireEvent);

    virtual INT32 InsertTextUTF8(LPCSTR strText, INT32 iStrLen = 0);
    virtual INT32 ClearText();                                                //����ַ�
    virtual void SetMaxDataLen(INT32 iMaxLen);
	void SetTextBoxStyle(TextBoxStyle eTextBoxStyle);
	FuncKeyPress GetFuncCallBack();
	virtual void SetNumberOnlyMode();
    BOOL IsEmpty()
    {
        return (0 == this->m_iDataLen);
    }
    
    virtual void SetFontSize(int fontSize);
    virtual int GetCurDataLen() const;

    virtual BOOL OnDeletePress();
    virtual BOOL OnEnterPress();
    virtual BOOL OnDirectionPress(int iKeyCode);
#ifdef KINDLE_FOR_TOUCH
    virtual bool OnTouchEvent(MoveEvent* moveEvent);
#endif

protected:
    //��������
    wchar_t             m_strData[TEXTBOX_DATA_MAX_LEN + 1];    //����
    wchar_t             m_strEchoData[TEXTBOX_DATA_MAX_LEN + 1];//����ʱ��ʾ������
    INT32               m_iMaxDataLen;                            //������ݳ���
    INT32               m_iDataIndex;                           //���λ�� ��0��ʼ
    INT32               m_iDataLen;                             //���ݳ���
    

    //��ʾ���ܱ���
    wchar_t               m_strTip[TEXTBOX_DATA_MAX_LEN + 1]; //�洢��ʾ�ı�
    //����ģʽ����
    INT32               m_iStartIndex;                          //�����ı���֮��ʼ�����ֵ�λ�� ��0��ʼ
    INT32               m_iEndIndex;                            //����λ��
    INT32               m_iStartPosition;                       //����ƫ����
    
    //��������
    INT32               m_rgiALLPosition[TEXTBOX_DATA_MAX_LEN];                     //��¼��������      
    EchoMode            m_echoMode;

    //���� �������
    DKFontAttributes m_ifontAttr;
    INT32  m_iFontColor;
    SPtr<ITpImage>  m_spImage;
    SPtr<ITpImage>  m_spFocusedImage;

    //����
    BOOL m_bIsDisposed;
    bool m_showBorder;
    bool m_fireEvent;
	//the function pointed to should return true if justify ok
	FuncKeyPress KeyPressCallBack;

    virtual BOOL OnActionPress(INT32 iKeyCode);

    //onchange
    void OnChange(INT32 iAction);
    void Change_UpdatePosArr();
    void Change_UpdateIndexs();
    void Change_UpdateStartPos(INT32 iAction);
    void CreateEchoDataFromOriginalData();
    void Init();
};
#endif


