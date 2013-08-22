#ifndef TEXTEDITCONTROLLER_H
#define TEXTEDITCONTROLLER_H

#include <vector>

#include "GUI/EventArgs.h"
#include "GUI/EventSet.h"
#include "GUI/ITpFont.h"
#include "dkImage.h"

using DkFormat::DK_IMAGE;

enum TextEditChangeTypes
{
    eTextEditCurPageChanged,
    eTextEditTotalPageChanged,
    eTextEditContentChanged
};

class TextEditChangeEventArgs : public EventArgs
{
public:
    TextEditChangeEventArgs()
        : textEditChangeType(eTextEditCurPageChanged)
        , pSender(NULL)
    {}

    TextEditChangeEventArgs(TextEditChangeTypes tece, void* sender = NULL)
        : textEditChangeType(tece)
        , pSender(sender)
    {}

    virtual EventArgs* Clone() const
    {
        return new TextEditChangeEventArgs(*this);
    }

    TextEditChangeTypes textEditChangeType;
    void* pSender;
};

class TextEditController : public EventSet 
{

public:
    struct TextLineInfo
    {
        TextLineInfo(int start, int end, const std::vector<unsigned int>& cursorPos)
            : startCharIndex(start)
            , endCharIndex(end)
            , cursorPosition(cursorPos)
        {}

        int startCharIndex;
        int endCharIndex;
        std::vector<unsigned int> cursorPosition;
    };//TextLineInfo

    enum CursorMoveDirection
    {
        MOVE_LEFT,
        MOVE_RIGHT,
        MOVE_UP,
        MOVE_DOWN
    };

    static const char* EventTextEditChange;

    TextEditController();
    ~TextEditController();

    /*��ȡ��ǰ����ҳ��   */
    int GetTotalPages();
    /*��ȡ��ǰ��������   */
    int GetTotalLines();
    /*��ȡ����ַ���   */
    int GetMaxDataLen() const;
    /*��ȡ�������   */
    int GetMaxCapicty() const;
    /*��ȡ��ǰ�ַ���   */
    int GetCurDataLen() const;
    /*��ȡ�������ҳ��   */
    int GetCursorPageIndex() const;
    /*�Ƿ���ʾ���   */
    bool IsCursorShowing() const;

    /*����ҳ����   */
    void SetPageWidth(int w);
    /*����ҳ��߶�   */
    void SetPageHeight(int h);
    /*����ҳ���м��   */
    void SetLineSpace(int linespace);
    /*���������С   */
    void SetFontSize(int fontsize);
    /*����������ɫ   */
    void SetFontColor(int fontColor);
    /*���ñ�����ɫ   */
    void SetBackGroundColor(int backGroundColor);
    /*�����Ƿ���ʾ���   */
    void SetShowCursor(bool show);

    /*���õ�ǰ�༭λ��   */
    void SetCurrentEditIndex(int);

    /**
     * @brief Render ���ݵ�ǰ������Ⱦҳ��
     *
     * @param image ԴͼƬ
     * @param pageIndex ��Ҫ��Ⱦ��ҳ��
     *
     * @return ��Ⱦ���,��pageIndex���Ϸ��򷵻�false
     */
    bool Render(DK_IMAGE& image, int pageIndex);

    /*��¼�Ƿ���Ҫ�ٴ���Ⱦ����   */
    void SetModifyFlag(bool);
    /*��¼�Ƿ���Ҫ�ٴ���Ⱦtips   */
    void SetTipsNeedRenderFlag(bool);

    /**
     * @brief CalcRenderInfos ���ݵ�ǰ���ּ�����Ⱦ�Ľ��ѡ��洢��m_lineInfos
     *
     * @return ������
     */
    bool CalcRenderInfos();

    /**
     * @brief HitCursorPosition ���ݵ�����¹��λ��
     *
     * @param x �����x����
     * @param y �����y����
     * @param curPage ��ǰҳ��
     *
     * @return ���ظ��º�Ĺ��index
     */
    int HitCursorPosition(int x, int y, int curPage);
    /**
     * @brief MoveCursor �ƶ����
     *
     * @param direction �ƶ�����
     *
     * @return ����Ƿ��ƶ�
     */
    bool MoveCursor(CursorMoveDirection direction);

	//�����޸�
    virtual int SetTip(const wchar_t *strText, int iStrLen = 0);   //������ʾ�ַ�
    virtual int SetTipUTF8(LPCSTR strText, int iStrLen = 0);

    virtual int SetText(const wchar_t *strText, int iStrLen = 0);   //�����ַ�
    virtual int SetTextUTF8(LPCSTR strText, int iStrLen = 0);

    virtual std::wstring GetText() const;  //ȡ���ַ�
    virtual std::string GetTextUTF8() const;
    virtual int InsertText(const wchar_t* strText, int iStrLen = 0);   //�����ַ�
    virtual int InsertTextUTF8(const char* strText, int iStrLen = 0);

    virtual int DeleteChar();
    virtual int ClearText();                                                //����ַ�
    virtual void SetMaxDataLen(int iMaxLen);

    bool MoveCursorToPageStart(int page);
    int GetMinHeight() const;

private:
    bool Init();
    void UnInit();

    /*��Ⱦ��startLine,endLine�ķ�Χ�ڵ�����,[)����   */
    bool RenderLineRange(DK_IMAGE& image, int startLine, int endLine);
    /*��Ⱦ��ʾ   */
    bool RenderTips(DK_IMAGE& image);

	//TODO
	int wstrinsert(wchar_t* szDest, int nIndex, int nDestArraySize, const wchar_t* strSrc, int nLen);
	int wstrremove(wchar_t* szDest, int nIndex, int nCount);

    bool CalCursorPosition();//������������,����������е�����ֵ,�������ҳ
    bool CalLineRangeByPageIndex(int pageIndex, int&startLine, int& endLine);
    int CalLineCountPerPage();

    ITpFont* GetCurFont() const;

    int GetClosedCursorIndexInLine(int line, int x);
    bool CursorMoveLeft();
    bool CursorMoveRight();
    bool CursorMoveUp();
    bool CursorMoveDown();

private:
    std::vector<TextLineInfo> m_lineInfos;
    //std::vector<unsigned int> mPageInfos;
    int m_lineSpace;
    int m_fontSize;

    int m_fontColor;
    int m_backGroundColor;

    const unsigned int mMaxCapicty;//��������
    int m_maxDataLen;//�ַ���󳤶�
    int m_dataLen;//�ַ�����

    int m_pageWidth;
    int m_pageHeight;
    int m_LineCountsPerPage;
    int m_startLineOnImage;//TODO,obsoleting
    int m_endLineOnImage;//TODO,obsoleting

    bool m_needRender;
    bool m_needCursorPosCalculated;
    bool m_showCursor;

    int m_cursorPageIndex;//������ڵ�ҳ
    int m_cursorLineIndex;//������ڵ���
    int m_cursorIndexInLine;//����ڸ��е�����
    int m_currentEditIndex;//������������������Ŀ���ܵ��ַ�����1

    bool m_needRenderTips;//��¼�Ƿ���Ҫ����Tips��λ��
    std::vector<TextLineInfo> m_lineTipsInfos;//Tips��ÿ�������ķ�Χ[).

    wchar_t* m_wstrData;
    wchar_t* m_wstrTips;
    char* m_cstrData;
};//TextEditController
#endif//TEXTEDITCONTROLLER_H
