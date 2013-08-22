//===========================================================================
// Summary:
//        PDF ����ҳ�����ֶ���������ӿڡ�
// Usage:
//        Null
// Remarks:
//        Null
// Date:
//        2012-02-25
// Author:
//        Liu Hongjia (liuhj@duokan.com)
//===========================================================================

#ifndef __KERNEL_PDFKIT_PDFLIB_EXPORT_IDKPTEXTITERATOR_H__
#define __KERNEL_PDFKIT_PDFLIB_EXPORT_IDKPTEXTITERATOR_H__

#include "DKPTypeDef.h"
#include "KernelRetCode.h"

class IDKPTextIterator
{
public:
    //-------------------------------------------
    //    Summary:
    //        �ƶ�����һλ�á�
    //  Parameters:
    //        Null
    //    Return Value:
    //        ������� DK_FALSE����Ӧ�ôӵ������м�����ȡ���ݡ�
    //    Remarks:
    //        ���˶�ĩ�Ļس���ҳĩ֮��,���ֻӦͣ���ڿɼ��ַ�ǰ
    //  Availability:
    //        �� PDFLib 1.0 ��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL MoveToNext() = 0;

    //-------------------------------------------
    //    Summary:
    //        �ƶ���ǰһλ�á�
    //  Parameters:
    //        Null
    //    Return Value:
    //        ������� DK_FALSE����Ӧ�ôӵ������м�����ȡ���ݡ�
    //    Remarks:
    //        Null
    //  Availability:
    //        �� PDFLib 1.0 ��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL MoveToPrev() = 0;

    //-------------------------------------------
    //    Summary:
    //        �ƶ�����һ�е�����λ�á�
    //  Parameters:
    //        Null
    //    Return Value:
    //        ������� DK_FALSE����Ӧ�ôӵ������м�����ȡ���ݡ�
    //    Remarks:
    //        Null
    //  Availability:
    //        �� PDFLib 1.0 ��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL MoveToPrevAdjacentLine() = 0;

    //-------------------------------------------
    //    Summary:
    //        �ƶ�����һ�е�����λ�á�
    //  Parameters:
    //        Null
    //    Return Value:
    //        ������� DK_FALSE����Ӧ�ôӵ������м�����ȡ���ݡ�
    //    Remarks:
    //        Null
    //  Availability:
    //        �� PDFLib 1.0 ��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL MoveToNextAdjacentLine() = 0;

    //-------------------------------------------
    //    Summary:
    //        ��ȡ��ǰλ�õ��ַ���Ϣ��
    //  Parameters:
    //        [out] pCharInfo          - ��ǰλ���ַ���Ϣ��
    //    Return Value:
    //        Null
    //    Remarks:
    //        Null
    //  Availability:
    //        �� PDFLib 1.0 ��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetCurrentCharInfo(DKP_CHAR_INFO* pCharInfo) const = 0;

public:
    virtual ~IDKPTextIterator() {}
};

#endif // #ifndef __KERNEL_PDFKIT_PDFLIB_EXPORT_IDKPTEXTITERATOR_H__
