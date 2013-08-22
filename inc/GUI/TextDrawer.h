#ifndef __GUI_TEXTDRAWER_H__
#define __GUI_TEXTDRAWER_H__

#include "dkImage.h"
#include "IDKTRender.h"
#include "Public/Base/TPDef.h"
#include <vector>
#include <stdint.h>

using DkFormat::DK_IMAGE;

class TextDrawer
{
public:
    enum Mode
    {
        // ���������߶����Ű���ȷ��
        TDM_FIXED_LINES, //ֻ�п�Ⱥ�������Ч
        // ����
        TDM_FIXED_HEIGHT, // ֻ�и߶���Ч
        // ���޸�,���ڴ����ݷ�ҳ��ʾ
        TDM_UNLIMITED_HEIGHT

    };
    TextDrawer();
    ~TextDrawer();
    void SetMaxWidth(int maxWidth);
    void SetMaxHeight(int maxHeight);
    void SetText(const char* text);
    void SetMode(Mode mode);
    void SetMaxLines(int maxLines);
    void SetEndWithEllipsis(bool endWithEllipsis);
    void SetAnsiFontFile(const char* ansiFontFile);
    void SetGbFontFile(const char* ansiFontFile);
    void SetFontSize(double fontSize);
    void SetAlign(int align);
    void SetVAlign(int valign);
    void SetFirstLineIndent(double firstLineIndent);
    void SetTabStop(double tabStop);
    void SetPageHeight(int pageHeight);
	void SetLineGap(double lineGap);
    void SetTextColor(const DK_ARGBCOLOR& color);
    void SetBackgroundColor(const DK_ARGBCOLOR& color);
	void SetStrikeThrough(bool strikeThrough);
	void SetUnderLine(bool underLine);
	void SetHighlightIndexRange(int startPos, int endPos);
    void SetUseTraditionalChinese(bool useTraditionalChinese);

	const char* GetText() const;
	Mode GetMode() const;
    int GetPageHeight() const;//ÿһҳ���趨�߶�
    bool GetEndWithEllipsis() const;
    int GetMaxWidth() const;
	int GetTextHeightOfPageIndex(int pageIndex);//ÿһҳ����ʵ��ռ�õĸ߶�
	const DK_ARGBCOLOR& GetBackgroundColor() const;
    bool GetTraditionalChineseUsed() const;
    unsigned int GetTextLength() const
    {
        return m_text.size();
    }

    bool GetBoundingBox(int* width, int* height);
	bool GetTextBoundingBox(int* width, int*height);//�õ����Ǵ����ֵĵľ��Σ����������ܵĿհ�(�������ʱ�����Ŀհ�)
    // ���޸߼���ҳ��
    size_t GetTotalPages();
    bool RenderPage(int pageIndex, DK_IMAGE image, int dstX, int dstY, int dstWidth, int dstHeight);
    bool Render(DK_IMAGE image, int dstX, int dstY, int dstWidth, int dstHeight);
    // �������������ֺ�Ϊ��λ
private:
    void CopyImgage32ToImage8(DK_IMAGE dstImg8, DK_IMAGE srcImg32);
    void ClearRenderInfo();
    void SetModifiedFlag();
    void ClearModifiedFlag();
    bool IsModified();
    bool CalcRenderInfo();
    bool CalcRenderInfoForFixedLines();
    bool CalcRenderInfoForFixedHeight();
    bool CalcRenderInfoForUnlimitedHeight();
    bool CalcRenderInfoForHeight(int height);
	/**
	 * @brief GetRenderCharInfoByIndex ���ַ�index�õ�m_pcharinfos��index
	 *
	 * @param charIndex �ַ�index
	 *
	 * @return ������m_pcharinfos��index
	 */
	IDKTRender::RenderCharInfo* GetRenderCharInfoByIndex(unsigned int charIndex);
	/**
	 * @brief RenderHighlight �����ؼ���
	 *
	 * @param image ԭͼ
	 * @param from �����ؼ��ֵĿ�ʼ����
	 * @param to �����ؼ��ֵ�ĩβ����(������������)
	 * @param baseX �������μ��������ƫ����x
	 * @param baseY  �������μ��������ƫ����y
	 */
	void RenderHighlight(DK_IMAGE image, int from, int to, int baseX = 0, int baseY = 0);
	/**
	 * @brief RenderUnderLine �»��߻���
	 *
	 * @param DK_IMAGE ԭͼ
	 * @param fromline ��ʼ��
	 * @param toline ������
	 */
	void RenderUnderLine(DK_IMAGE, int fromline, int toline);
	/**
	 * @brief RenderStrikeThrough �л��߻���
	 *
	 * @param DK_IMAGE ԭͼ
	 * @param fromline ��ʼ��
	 * @param toline ������
	 */
	void RenderStrikeThrough(DK_IMAGE, int fromline, int toline);
    IDKTRender::LayoutOption BuildLayoutOption();

    TextDrawer(const TextDrawer&);
    TextDrawer& operator=(const TextDrawer&);
    int m_maxWidth;
    int m_maxHeight;
    int m_maxLines;
    bool m_endWithEllipsis;
    bool m_useTraditionalChinese;//traditional chinese or simple chinese
    Mode m_mode;
    static IDKTRender* s_render;
    IDKTRender::RenderCharInfo* m_pCharInfos;
    DK_UINT m_charInfoCount;
    IDKTRender::RenderLineInfo* m_pLineInfos;
    DK_UINT m_lineInfoCount;
    bool m_modified;
    std::string m_text;
    std::wstring m_ansiFontFile;
    std::wstring m_gbFontFile;
    double m_fontSize;
    int m_align;
    int m_valign;
    double m_firstLineIndent;
    double m_tabStop;
    DK_BOOL m_followAfter;
    bool m_renderSucceeded;
    int m_pageHeight;//ֻ�ڷ�ҳʱ��Ч
    std::vector<int> m_pageStartLines;
    DK_ARGBCOLOR m_textColor;
    DK_ARGBCOLOR m_backgroundColor;
	bool m_strikeThrough;
	bool m_underLine;
	int m_highlightStartPos;
	int m_highlightEndPos;
	double m_lineGap;
    int m_cachedTextBoxWidth;
    int m_cachedTextBoxHeight;
};
#endif

