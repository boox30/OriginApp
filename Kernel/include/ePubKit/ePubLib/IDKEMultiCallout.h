//===========================================================================
//  Summary:
//      ePubͼ���㽻��ͼ����
//  Usage:
//      ͨ��ҳ��ʰȡ�߼���ȡ��ǰ��㽻��ͼ����Ȼ��ͨ���ö�㽻��ͼ���������㽻��ͼ
//  Remarks:
//      Null
//  Date:
//      2013-08-12
// Author:
//      Zhang Jiafang (zhangjf@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEMULTICALLOUT_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEMULTICALLOUT_H__

#include "DKEDef.h"

class IDKEImageIterator;

class IDKEMultiCallout
{
public:
    virtual ~IDKEMultiCallout() {}

public:
    //-------------------------------------------
    //  Summary:
    //      ��ȡ��㽻��ͼ�����ʼλ��
    //  Parameters:
    //      Null
    //  Return Value:
    //      DK_FLOWPOSITION ��ʼλ��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_FLOWPOSITION GetBeginPosition() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��㽻��ͼ��Ľ���λ��
    //  Parameters:
    //      Null
    //  Return Value:
    //      DK_FLOWPOSITION ����λ��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_FLOWPOSITION GetEndPosition() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��㽻��ͼ����ͼƬ��Ϣ
    //  Parameters:
    //      [out]pImgInfo       - ͼƬ��Ϣ
    //  Return Value:
    //      ����ɹ�����DKR_OK�����򷵻�ʧ��
    //  Remarks:
    //      ����FreeBaseImageInfo�ͷ�ͼƬ��Ϣ
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetBaseImageInfo(DKE_HITTEST_OBJECTINFO* pImgInfo) const = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷŶ�㽻��ͼ����ͼƬ��Ϣ
    //  Parameters:
    //      [in]pImgInfo       - ͼƬ��Ϣ
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeBaseImageInfo(DKE_HITTEST_OBJECTINFO* pImgInfo) = 0; 

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��㽻��ͼ����ͼƬ��ö����
    //  Parameters:
    //      Null
    //  Return Value:
    //      IDKEImageIterator ö����
    //  Remarks:
    //      ����FreeBaseImageIterator�ͷ�ö����
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEImageIterator* GetBaseImageIterator() const = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷŶ�㽻��ͼ����ͼƬ��ö����
    //  Parameters:
    //      [in]pImageIterator          - ����ͼƬö����
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeBaseImageIterator(IDKEImageIterator* pImageIterator) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��㽻��ͼ�Ŀɽ�������Ŀ
    //  Parameters:
    //      Null
    //  Return Value:
    //      �ɽ�������Ŀ
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_LONG GetCalloutCount() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ���ö�㽻��ͼ������Ϣ������
    //  Parameters:
    //      Null
    //  Return Value:
    //      ������Ϣ������
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetNavigationBox() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡָ��λ�õĿɽ�����Ļ�����Ϣ
    //  Parameters:
    //      [in]calloutIndex        - �ɽ������λ��
    //      [out]pCalloutInfo       - �ɽ�����Ļ�����Ϣ
    //  Return Value:
    //      ����ɹ�����DKR_OK�����򷵻�ʧ��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetCalloutBasicInfo(DK_LONG calloutIndex, DKE_CALLOUT_INFO* pCalloutInfo) const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡָ��λ�õĿɽ�����ı���
    //  Parameters:
    //      [in]calloutIndex        - �ɽ������λ��
    //      [out]ppTitle            - �ɽ�����ı���
    //  Return Value:
    //      Null
    //  Remarks:
    //      ����FreeCalloutFlexPage�ͷ�ppTitle
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID GetCalloutTitle(DK_LONG calloutIndex, IDKEFlexPage** ppTitle) const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡָ��λ�õĿɽ������˵��
    //  Parameters:
    //      [in]calloutIndex        - �ɽ������λ��
    //      [out]ppCaption          - �ɽ������˵��
    //  Return Value:
    //      Null
    //  Remarks:
    //      ����FreeCalloutFlexPage�ͷ�ppCaption
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID GetCalloutCaption(DK_LONG calloutIndex, IDKEFlexPage** ppCaption) const = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷű����˵����Ӧ�Ŀ�����ҳ
    //  Parameters:
    //      [in]pFlexPage           - �ɽ������λ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeCalloutFlexPage(IDKEFlexPage* pFlexPage) = 0;
};


#endif // __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEMULTICALLOUT_H__
