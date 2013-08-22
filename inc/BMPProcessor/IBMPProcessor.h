//===========================================================================
// Summary:
//        IBookReader�ӿڶ���
// Version:
//    0.1 draft - creating.
//    
// Usage:
//        Null
// Remarks:
//        Null
// Date:
//        2011-11-21
// Author:
//        Chen Mao (chenm@duokan.com)
//===========================================================================

#ifndef __KINDLEAPP_INC_BMPPROCESSOR_H__
#define __KINDLEAPP_INC_BMPPROCESSOR_H__

#define _LINUX 1
#include "KernelType.h"
#include "GUI/dkImage.h"

/*
// �����ã�dkImage.h�����Ӧ����Ҫ�޸�
typedef struct __tagDK_IMAGE{
      int   iColorChannels; // ɫ��ͨ������Ŀǰ��Ϊ1��8λ�Ҷ�ͼ����4��32λ��ɫͼ��
      DK_LONG  lWidth;         // ͼ��ʵ�ʿ��(�����ص�Ϊ��λ, ÿ���ص���ռ�õ��ֽ�����"ͼ������"���� )
      DK_LONG  lHeight;         // ͼ��߶�(�����ص�Ϊ��λ, ÿ���ص���ռ�õ��ֽ�����"ͼ������"����)
      DK_LONG  lStride;         // ͼ��洢���(���ֽ�Ϊ��λ)
      unsigned char* pbData;         // ͼ������
      __tagDK_IMAGE()
        : iColorChannels(4)
        , lWidth(600)
        , lHeight(800)
        , lStride(600*4)
        , pbData(DK_NULL)
    {
    };
} DK_IMAGE;
*/

using DkFormat::DK_IMAGE;

// class defined in this header
class IBMPProcessor;
class BMPProcessFactory;
class RotateProcessor;
class SharpenProcessor;
class DarkenProcessor;
class GrayScaleProcessor;

class IBMPProcessor
{
public:
    enum TYPE
    {
        DK_BMPPROCESSOR_ROTATE,
        DK_BMPPROCESSOR_SHARPEN,
        DK_BMPPROCESSOR_DARKEN,
        DK_BMPPROCESSOR_GRAYSCALE
    };

    virtual ~IBMPProcessor(){};
    virtual bool Process(DK_IMAGE* pImage) = 0;
    virtual IBMPProcessor::TYPE GetType () = 0;
};

class BMPProcessFactory
{
public:
    static IBMPProcessor* CreateInstance(IBMPProcessor::TYPE eType, int iPara = 0);
};

//-------------------------------------------
// Summary:
//        ͼ����ת������
//-------------------------------------------
class RotateProcessor: public IBMPProcessor
{
public:
    RotateProcessor(int rotate);
    virtual bool Process(DK_IMAGE* pImage);
    virtual IBMPProcessor::TYPE GetType () { return IBMPProcessor::DK_BMPPROCESSOR_ROTATE; }
};

//-------------------------------------------
// Summary:
//        ͼ���񻯴�����
//-------------------------------------------
class SharpenProcessor: public IBMPProcessor
{
public:
    SharpenProcessor ();

    static  IBMPProcessor* GetInstance();

    void SetSharpenLevel (int iLevel) { m_iSharpenLevel = iLevel; }
    virtual bool Process(DK_IMAGE* pImage);
    virtual IBMPProcessor::TYPE GetType () { return IBMPProcessor::DK_BMPPROCESSOR_SHARPEN; }

private:
    bool SharpenImage(unsigned char* pBuf, unsigned int uWidth, unsigned int uHeight, unsigned int uN, int iLevel);
    void SharpenImage3x3(unsigned char* pBuf, unsigned int uWidth, unsigned int uHeight, unsigned int uN, int iLevel, unsigned char* pResult);

private:
    static IBMPProcessor* m_pInstance;
    int m_iSharpenLevel;
};

//-------------------------------------------
// Summary:
//        ͼ��Ӻڴ�����
//-------------------------------------------
class DarkenProcessor: public IBMPProcessor
{
public:
    DarkenProcessor();

    static  IBMPProcessor* GetInstance();
    
    void SetDarkenLevel (int iLevel) { m_iDarkenLevel = iLevel; }
    virtual bool Process(DK_IMAGE* pImage);
    virtual IBMPProcessor::TYPE GetType () { return IBMPProcessor::DK_BMPPROCESSOR_DARKEN; }

private:
    bool EmboldenImage(unsigned char* pBuf, unsigned int uWidth, unsigned int uHeight, unsigned int uN, int iLevel);

private:
    static IBMPProcessor* m_pInstance;
    int m_iDarkenLevel;
};

//-------------------------------------------
// Summary:
//        ��ɫ�任��Ҷȴ�����
//-------------------------------------------
class GrayScaleProcessor: public IBMPProcessor
{
public:
    static  IBMPProcessor* GetInstance();
    virtual bool Process(DK_IMAGE* pImage);
    virtual IBMPProcessor::TYPE GetType () { return IBMPProcessor::DK_BMPPROCESSOR_GRAYSCALE; }
    
private:
    unsigned char ConvertRGBToGray(unsigned char blue, unsigned char green, unsigned char red);
    bool RGBToGray(DK_IMAGE* pImage);
    
    static IBMPProcessor* m_pInstance;
};

#endif //__KINDLEAPP_INC_BMPPROCESSOR_H__
