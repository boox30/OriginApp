//===========================================================================
// Summary:
//      PDFTextIterator.h
//      PDFReader ��ԭ��ʽҳ������ֶ��������ʵ��
// Usage:
//      Null
// Remarks:
//      PDFReader ��ʵ���˷������������бߵȶ���ģʽ��������ֵ�������Ҫ��Ӧ�ò�ʵ��
// Date:
//      2012-03-22
// Author:
//      Liu Hongjia (liuhj@duokan.com)
//===========================================================================

#ifndef __KINDLEAPP_BOOKREADER_PDFREADER_PDFTEXTITERATOR_H__
#define __KINDLEAPP_BOOKREADER_PDFREADER_PDFTEXTITERATOR_H__

#include "PDFTextElement.h"
#include "DKPTypeDef.h"

class PDFTextElementHandler;

class PDFTextIterator
{
public:
    PDFTextIterator(const std::vector<PDFTextElement>& pageElements, const PdfModeController& modeController, bool shouldOwn = false);

public:
    bool MoveToNext();
    bool MoveToPrev();
    bool MoveToPrevAdjacentLine();
    bool MoveToNextAdjacentLine();
    DK_ReturnCode GetCurrentCharInfo(DKP_CHAR_INFO* pCharInfo) const;
    
private:
    bool MoveToAdjacentLine(int dir);
    inline bool IsCursorPosOK(int cursorIndex) const;
    inline bool IsCursorPosShowOK(int cursorIndex) const;

private:
    std::vector<PDFTextElement>* m_pPageElements;
    const std::vector<PDFTextElement>& m_pageElements;
    int m_cursorIndex;
    PdfModeController m_stModeController;
};

#endif // #ifndef __KINDLEAPP_BOOKREADER_PDFREADER_PDFTEXTITERATOR_H__
