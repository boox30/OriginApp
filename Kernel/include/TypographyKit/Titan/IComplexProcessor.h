//===========================================================================
//  Summary:
//      �����Ű洦�����ӿ�
//  Usage:
//      Null
//  Remarks:
//      Null
//  Date:
//      2013-01-04
//  Author:
//      Zhai Guanghe (zhaigh@duokan.com)
//===========================================================================

#ifndef __COMPLEXPROCESSOR_INTERFACE_HEADERFILE__
#define __COMPLEXPROCESSOR_INTERFACE_HEADERFILE__

#include "IComplexBlockProcessor.h"

class ILayoutBoundary;
class ITitanFontEngine;

class IComplexProcessor
{
public:
    virtual ~IComplexProcessor() = 0;

public: // �����Ű滷��
    // ������ʹ��
    virtual DK_VOID SetBoundingBox(const TP_BOX &box) = 0;

    // �����Ű�����
    virtual DK_VOID SetBoundary(const ILayoutBoundary *pLayoutBoundary) = 0;

    // �����Ű�������
    virtual DK_VOID SetTopLine(double dTopLine) = 0;

    // ���������Ű滷��
    virtual DK_VOID SetCJKLayoutEnvironment(TP_CJK_LAYOUT_ENV eLayoutEnv) = 0;

    // ����Hyphenationʹ�õ�����
    virtual DK_VOID SetHyphenationLanguage(TP_HYPHENATION_LANGUAGE eLanguage) = 0;

    // ������������
    virtual DK_VOID SetFontEngine(ITitanFontEngine *pFontEngine) = 0;

    // �����Ű淽��
    virtual DK_VOID SetLayoutDirection(TP_DIRECTION_TYPE eDirect) = 0;

    virtual DK_VOID SetPunctuationVerticalStyle(TP_PUNCTUATION_VERTICAL_STYLE eStyle) = 0;

    // �����Ƿ�ǿ���Ű�
    virtual DK_VOID SetAtLeastOneLine(bool bAtLeastOneLine) = 0;

    // �����Ƿ������Ѫ
    virtual DK_VOID SetAllowBleed(bool bAllowBleed) = 0;

    // ���ó�Ѫ����
    virtual DK_VOID SetBleedLength(double dLength) = 0;

    // �ⲿ���ö��Ű����
    virtual DK_VOID SetCustomParaStyle(const TP_PARASTYLE &paraStyle) = 0;

    // ���ñ�����ѹ���̶�
    virtual DK_VOID SetPuncMaxShrinkRate(double dPuncShrinkRate) = 0;

    // �������������̶�
    virtual DK_VOID SetMaxStretchRate(double dStretchRate) = 0;

    virtual DK_VOID SetCustomParaFont(const TP_FONT &paraFont) = 0;

    virtual DK_VOID ResetCustomParaStyle() = 0;

public:
    // �Ű�����
    virtual TP_LAYOUT_STATE ProcessText(const std::vector<TP_CONTENTPIECE> &vPieces, const TP_INITIALSTATEPARA &isp) = 0;

public:
    // ��ȡ�Ű���ö����
    virtual ILayoutEnumerator * GetLayoutEnumerator() = 0;

    // ��ȡ��ǰ�Ű�߶�
    virtual DK_DOUBLE GetLayoutHeight() = 0;

    // ��ȡ���һ�еĸ߶�
    virtual DK_DOUBLE GetLastLineHeight() = 0;

    // ��ȡ���һ�еĸ߶�
    virtual DK_DOUBLE GetLastLineGap() = 0;

public:
    virtual bool GetLinesHeight(const TP_FONT &baseFont, 
                                double lineGap, 
                                unsigned int lineCount, 
                                const TP_FONT &dropCapFont, 
                                TP_WCHAR dropCapChar, 
                                double *pDropCapFontSize) = 0;
};

//===========================================================================

#endif //#ifndef __COMPLEXPROCESSOR_INTERFACE_HEADERFILE__
