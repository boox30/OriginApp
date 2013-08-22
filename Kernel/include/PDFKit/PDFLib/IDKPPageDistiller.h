//===========================================================================
// Summary:
//      IDKPPageDistiller.h
//      ����ҳ��������ȡ������ȡҳ��������ȡ�Ľӿ��ࡣ 
// Usage:
//      Null
// Remarks:
//      Null
// Date:
//      2011-09-14
// Author:
//      Liu Hongjia(liuhj@duokan.com)
//===========================================================================

#ifndef __KERNEL_PDFKIT_PDFLIB_IDKPPAGEDISTILLER_H__
#define __KERNEL_PDFKIT_PDFLIB_IDKPPAGEDISTILLER_H__

#include "DKPTypeDef.h"

class IDKPPageDistiller
{
public:
    //-------------------------------------------
    // Summary:
    //      �ж��Ƿ�Ϊ��ԭʼ�Ű�˳��ѡ��
    // Parameters:
    //      [in] startPoint - ��ʼ�����ꡣ
    //      [in] endPoint   - ��ֹ�����ꡣ
    // Returns:
    //      ���򷵻�DK_TRUE������Ϊ��������ѡ�񷵻�DK_FALSE��
    // SDK Version:
    //      ��DKP 1.0��ʼ֧��
    //-------------------------------------------
    virtual DK_BOOL IsRawSelectionType(DK_POINT startPoint, DK_POINT endPoint) = 0;

    //-------------------------------------------
    // Summary:
    //      ��ȡָ���������ֵ��Ű淽��
    // Parameters:
    //      [in] startPoint - ��ʼ�����ꡣ
    //      [in] endPoint   - ��ֹ�����ꡣ
    // Returns:
    //      ������ת�Ƕȣ�0-360����
    // SDK Version:
    //      ��DKP 1.0��ʼ֧��
    //-------------------------------------------
    virtual DK_DOUBLE GetTextRawDirection(DK_POINT startPoint, DK_POINT endPoint) = 0;

    //-------------------------------------------
    // Summary:
    //      �ж�������Ƿ�λ���ı�����
    // Parameters:
    //      [in] point - �����ꡣ
    // Returns:
    //      ���򷵻�DK_TRUE�����򷵻�DK_FALSE��
    // SDK Version:
    //      ��DKP 1.0��ʼ֧��
    //-------------------------------------------
    virtual DK_BOOL CheckPointOnText(DK_POINT point) = 0;

    //-------------------------------------------
    // Summary:
    //      �ж�������Ƿ�λ��ͼ������
    // Parameters:
    //      [in] point - ������.
    // Returns:
    //      ���򷵻�DK_TRUE�����򷵻�DK_FALSE��
    // SDK Version:
    //      ��DKP 1.0��ʼ֧��
    //-------------------------------------------
    virtual DK_BOOL CheckPointOnImage(DK_POINT point) = 0;

    //-------------------------------------------
    // Summary:
    //      ��ȡ���������ͼ��ĸ�����Ϣ��
    // Parameters:
    //      [in] point          - ������.
    //      [out] pImageContent - ͼ����Ϣ.
    // Returns:
    //      �ɹ��򷵻�DK_TRUE�����򷵻�DK_FALSE��
    // SDK Version:
    //      ��DKP 1.0��ʼ֧��
    //-------------------------------------------
    virtual DK_BOOL PickupSelectedImageInfo(DK_POINT point, DKPIMAGECONTENT* pImageContent) = 0;

    //-------------------------------------------
    // Summary:
    //      �ж�������Ƿ�λ��ע�Ͷ����ϡ�
    // Parameters:
    //      [in] point       - �����ꡣ
    //      [out] annotsInfo - ע�Ͷ������Ӿ��κ����͵���Ϣ��
    // Returns:
    //      ���򷵻�DK_TRUE�����򷵻�DK_FALSE��
    // SDK Version:
    //      ��DKP 2.2.0��ʼ֧��
    //-------------------------------------------
    virtual DK_BOOL CheckPointOnClickable(DK_POINT point, DK_CLICKINFO& annotsInfo) = 0;

    //-------------------------------------------
    // Summary:
    //        ��ȡע�Ͷ���Ķ�����
    // Parameters:
    //        [in] point        - �����ꡣ
    //        [in] eventType    - �������͡�
    //        [out] pActionData - ��������Ϣ��
    // Returns:
    //        �ɹ��򷵻�DK_TRUE�����򷵻�DK_FALSE��
    // SDK Version:
    //        ��DKP 2.2.0��ʼ֧��
    //-------------------------------------------
    virtual DK_BOOL GetClickableActionData(DK_POINT point, DK_CLICKEVENT_TYPE eventType, DK_VOID* pActionData) = 0;

public:
    virtual ~IDKPPageDistiller() {}
};

#endif // #ifndef __KERNEL_PDFKIT_PDFLIB_IDKPPAGEDISTILLER_H__
