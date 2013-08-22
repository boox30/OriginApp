#ifndef UIABSTRACTTEXT_H
#define UIABSTRACTTEXT_H

#include "GUI/UIWindow.h"
#include "GUI/TextDrawer.h"
#include "dkBuffer.h"
using DkFormat::DkBuffer;
using DkFormat::DkBufferBase;

class UIAbstractText : public UIWindow
{
public:
    enum TextMode {
        TextSingleLine,
        TextMultiLine,
        TextMultiPage,
    };

    virtual LPCSTR GetClassName() const
    {
        return "UIAbstractText";
    }

    UIAbstractText();
    UIAbstractText(UIContainer* pParent, const DWORD dwId);

    virtual ~UIAbstractText();
    void SetEraseBackground(bool eraseBackground);

    /**
     * @brief SetAlign ���ö��뷽ʽ,Ĭ�Ͼ������
     *
     * @param iAlign ALIGN_LEFT, ALIGN_CENTER, ALIGN_RIGHT
     */
    void SetAlign(INT32 iAlign);
    void SetVAlign(INT32 iVAlign);
    void SetFirstLineIndent(double firstLineIndent);
    void SetTabStop(double tabStop);
    void SetForeGroundColor(INT32 iColor);
    void SetBackGroundColor(INT32 iColor);
    void SetForeColor(INT32 iColor);
    void SetBackColor(INT32 iColor);
    /**
     * @brief SetFontSize ���������С
     *
     * @param iSize �����С
     */
    void SetFontSize(INT32 iSize);
    void SetFont(INT32 iFace, INT32 iStyle, INT32 iSize);
    /**
     * @brief SetEndWithEllipsis �����Ƿ���ʡ�ԺŽ�β��Ĭ����ʡ�ԺŽ�β
     *
     * @param endWithEllipsis
     */
    void SetEndWithEllipsis(bool endWithEllipsis);
    /**
     * @brief SetStrikeThrough �����л���
     *
     * @param strikeThrough �Ƿ�����л���
     */
    void SetStrikeThrough(bool strikeThrough);

    /**
     * @brief SetUnderLine �����»���
     *
     * @param underLine �Ƿ�����»���
     */
    void SetUnderLine(bool underLine);
    /**
     * @brief GetText ��ȡ�����ı�����
     *
     * @return 
     */
    virtual LPCSTR GetText() const;

    unsigned int GetTextLength() const
    {
        return m_TextDrawer.GetTextLength();
    }

    /**
     * @brief SetText ���������ı�����
     *
     * @param rstrTxt
     */
    virtual void SetText(const CString& rstrTxt);
    virtual void SetText(const char* pchTxt);
    virtual void SetText(int strId);
    virtual void SetText(const std::wstring& wstrTxt);
    virtual void SetText(const std::string& strTxt)
    {
        return SetText(strTxt.c_str());
    }
    virtual void SetText(SPtr<DkBufferBase> spText);

    void SetKeyword(PCCH _pcchKeyword, UINT _uHightLightStartPos, UINT _uHighLightEndPos);

    /**
     * @brief GetTextHeight ��ȡ�ı����ݵĸ߶�
     *
     * @return 
     */
    virtual int GetTextHeight() const;
    /**
     * @brief GetTextWidth ��ȡ�ı����ݵĿ�ȣ����������SetMaxWidth()�����ĵ����йء�
     *
     * @return 
     */
    virtual int GetTextWidth() const;

    //virtual dkSize GetMinSize() const
    //{
    //    return dkSize(GetTextWidth(), GetTextHeight());
    //}

    virtual void SetMaxWidth(int maxWidth);
    virtual void SetMaxHeight(int maxHeight);

    virtual HRESULT Draw(DK_IMAGE drawingImg);
    virtual void SetBackTransparent(BOOL bIsTransparent);
    virtual void SetTransparent(BOOL bIsTransparent);
    /**
     * @brief SetFontPath ΪTextDrawerָ������·��
     */
    virtual void SetFontPath();

	void SetAnsiFontFile(const char* ansiFontFile);
    void SetGbFontFile(const char* ansiFontFile);
	
    /**
     * @brief GetAutoModifyWidth �Ƿ��Զ��޸Ŀ�ȣ�Ĭ�Ϸ�
     */
    bool GetAutoModifyWidth() const;
    /**
     * @brief SetAutoModifyWidth �����Ƿ��Զ��޸Ŀ�� 
     */
    void SetAutoModifyWidth(bool autoModifyWidth);

    /**
     * @brief GetAutoModifyHeight �Ƿ��Զ��޸ĸ߶ȣ�Ĭ�Ϸ�
     */
    bool GetAutoModifyHeight() const;
    /**
     * @brief SetAutoModifyHeight �����Ƿ��Զ��޸ĸ߶� 
     */
    void SetAutoModifyHeight(bool autoModifyHeight);
    void SetUseTraditionalChinese(bool useTraditionalChinese);

protected:
   void Init();
   void Dispose();
   virtual HRESULT DrawBackGround(DK_IMAGE drawingImg);

    /**
     * @brief IColor2ARGBColor �ⲿʹ����ɫת�����ں���ɫ
     *
     * @param iColor �ⲿʹ����ɫ
     *
     * @return �ں���ɫ
     */
    DK_ARGBCOLOR IColor2ARGBColor(INT32 iColor);

protected:
    mutable TextDrawer m_TextDrawer;

    void OnDispose(BOOL bIsDisposed);
    
    /// <remark>
    /// This flag is used to avoid unnecessary timer message when this window is not visible.
    /// </remark>
    BOOL m_bIsDisposed;
    BOOL  m_bBackTransparent;
    bool m_bIsAutoModifyWidth;
    bool m_bIsAutoModifyHeight;
    bool m_eraseBackground;
};//UIAbstractText



#endif//UIABSTRACTTEXT_H

