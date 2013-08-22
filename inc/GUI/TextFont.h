#ifndef __TEXTFONT_INCLUDED__
#define __TEXTFONT_INCLUDED__

#include "dkBaseType.h"
#include "dkImage.h"
#include "dkColor.h"
#include "dkObjBase.h"

namespace DkFormat
{
    class ITextFont
    {    
    public:
        virtual ~ITextFont(){};
        ITextFont(){};

        STDMETHOD(LoadFont)(const char* lpszFileName)=0;
        STDMETHOD(SetFontSize)(unsigned int nFontSize)=0; // size is in point unit

        STDMETHOD(GetCharHeight)(unsigned int charCode, int* piCharWidth)=0;
        STDMETHOD(GetCharWidth)(unsigned int charCode, int* piCharWidth)=0;
        STDMETHOD(GetMaxCharWidth)(int* piMaxCharWidth)=0;
        STDMETHOD(GetLineHeight)(int* piLineHeight)=0;
        STDMETHOD(GetDescender)(int* piDecender)=0;
        STDMETHOD(GetAscender)(int* piAscender)=0;
        STDMETHOD(GetFontSize)(int* piFontSize)=0;
        //
        // UTF8 �ַ������ظ߶�
        STDMETHOD(GetStringHeight)(const char *pStr, unsigned int nLength, int* height)=0;

        // Unicode  �ַ������ظ߶�
        STDMETHOD(GetStringHeight)(const wchar_t *pStr, unsigned int nLength, int* height)=0;
        
        // UTF8 �ַ������ؿ��
        STDMETHOD(GetStringWidth)(const char *pStr, unsigned int nLength, int* piWidth)=0;

        // Unicode  �ַ������ؿ��
        STDMETHOD(GetStringWidth)(const wchar_t *pStr, unsigned int nLength, int* piWidth)=0;

        // ��drawRect�����ϵ��ַ�ͼƬ����pbDestȥ
        STDMETHOD(DrawCharImage)(
            DK_IMAGE &rImage,        // Ŀ������
            const DK_POINT_OLD &rPenPos,    // ����λ�ã���drawRect���������ͬһ��ԭ�㣬�ɵ�����ȷ��
            const DK_RECT &rDrawRect,    // ��ʾ����ֻ�е���ǰ�ַ�����drawRect֮�ڣ��򲿷ִ��ڣ����Żử��pbDestȥ
            unsigned int nCharCode,        // Ҫ�����ַ�����, UTF32
            int* piPenOff            // ����֮����Ҫ��pen��ǰ�ƶ��ľ���
        )=0;

        // UTF8 �ַ���
        STDMETHOD(DrawStringUTF8)(
            DK_IMAGE &rImage, 
            const DK_RECT rDrawRect, 
            const char *pStr,
            bool fDrawEllipsis=true,
            unsigned int nCharSpacing=0
        )=0;

        // Unicode �ַ���
        STDMETHOD(DrawStringW)(
            DK_IMAGE &rImage, 
            const DK_RECT &rDrawRect, 
            const wchar_t *pStr,
            bool fDrawEllipsis=true,
            unsigned int nCharSpacing=0
        )=0;


        STDMETHOD(SetFontColor(unsigned char r, unsigned char g, unsigned char b))=0;
    };

    HRESULT CreateTextFontInstance(
        ITextFont **ppTextFont
    );        
}

#endif    // ndef __TEXTFONT_INCLUDED__

