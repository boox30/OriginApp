//===========================================================================
//  Summary:
//      ePubͼ��Ŀ¼�ӿڡ�
//  Usage:
//      Null
//  Remarks:
//      Null
//  Date:
//      2011-09-16
//  Author:
//      Zhai Guanghe (zhaigh@duokan.com)
//===========================================================================

#ifndef __KERNEL_MOBIKIT_MOBILIB_EXPORT_IDKMTOCPOINT_H__
#define __KERNEL_MOBIKIT_MOBILIB_EXPORT_IDKMTOCPOINT_H__

#include "KernelBaseType.h"

class IDKMTocPoint
{
public:
    //-------------------------------------------
    //  Summary:
    //      ��ȡĿ¼�ڵ��������ݡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      Ŀ¼�ڵ��������ݡ�
    //  Remarks:
    //      Null
    //  Availability:
    //      ��MobiLib 1.0.9��ʼ֧�֡�
    //-------------------------------------------
    virtual const DK_WCHAR * GetTitle() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��תĿ��λ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      Ŀ��λ��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��MobiLib 1.0.9��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_UINT GetDestPosition() const = 0;

public:
    //-------------------------------------------
    //  Summary:
    //      ��ȡ�ӽڵ������
    //  Parameters:
    //      Null
    //  Return Value:
    //      �ӽڵ������
    //  Remarks:
    //      Null
    //  Availability:
    //      ��MobiLib 1.0.9��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_UINT GetChildCount() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�ӽڵ㡣
    //  Parameters:
    //      [in] index              - �ӽڵ���������0��ʼ��
    //  Return Value:
    //      �ӽڵ����ӿڡ�
    //  Remarks:
    //      Null
    //  Availability:
    //      ��MobiLib 1.0.9��ʼ֧�֡�
    //-------------------------------------------
    virtual const IDKMTocPoint * GetChildByIndex(DK_UINT index) const = 0;

public:
    virtual ~IDKMTocPoint() {}
};

#endif // __KERNEL_MOBIKIT_MOBILIB_EXPORT_IDKMTOCPOINT_H__
