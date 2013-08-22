#ifndef __GUI_DKIMAGE_H__
#define __GUI_DKIMAGE_H__

#include <stdint.h>
#include "dkBaseType.h"
#include "dkRect.h"
#include "Common/Defs.h"

namespace DkFormat
{
struct DK_IMAGE{
    int iColorChannels;            // ɫ��ͨ������Ŀǰ��Ϊ1��8λ�Ҷ�ͼ����3��24λ��ɫͼ��
    uint8_t *pbData;                // ͼ������
    int iHeight;                // ͼ��߶�(�����ص�Ϊ��λ, ÿ���ص���ռ�õ��ֽ�����"ͼ������"����)
    int iWidth;                    // ͼ��ʵ�ʿ��(�����ص�Ϊ��λ, ÿ���ص���ռ�õ��ֽ�����"ͼ������"���� )
    int iStrideWidth;            // ͼ��洢���(���ֽ�Ϊ��λ)

    DK_IMAGE()
        : iColorChannels(1)
          , pbData(NULL)
          , iHeight(0)
          , iWidth(0)
          , iStrideWidth(0)
    {}
    void Reset(int colorChannels, int width, int height)
    {
        if (NULL != pbData)
        {
            free(pbData);
            pbData = NULL;
        }
        iColorChannels = colorChannels;
        iWidth = width;
        iHeight = height;
        iStrideWidth = width * iColorChannels;
        int dataLen = height * iStrideWidth;
        if (dataLen > 0)
        {
            pbData = (unsigned int8_t*)malloc(dataLen);
        }
    }
    uint8_t* GetPointAddress(int x, int y) const;
    HRESULT EraseBackground(dkColor color);
    HRESULT DrawLine(int x, int y, int width, int height, int strokeStyle);
    HRESULT FillRect(int x, int y, int width, int height, dkColor brushColor);
    HRESULT Reverse();
    HRESULT ReverseRect(int x, int y, int width, int height);
};


inline DkRect DkRectFromImage(const DK_IMAGE& img)
{
    return DkRect::FromLeftTopWidthHeight(0, 0, img.iWidth, img.iHeight);
}

HRESULT CropImage(
        DK_IMAGE imgInput, 
        DK_RECT& rcCrop,
        DK_IMAGE *pimgOutput,
        int cBytesPerPixel = 1
        );

HRESULT CopyImage(
        DK_IMAGE pimgOutput,
        DK_IMAGE imgInput, 
        int cBytesPerPixel = 1
        );
HRESULT CopyImageEx(
        DK_IMAGE imgDst,
        int dstX,
        int dstY,
        DK_IMAGE imgSrc, 
        int srcX,
        int srcY,
        int width,
        int height
        );

HRESULT ReverseImage(
        DK_IMAGE imgHandle,
        int cBytesPerPixel = 1
        );
}
#endif        // #ifndef __DKIMAGE_INCLUDED__

