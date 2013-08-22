//===========================================================================
//  Summary:
//      ҳ�����ֶ���������ӿڡ�
//  Usage:
//      Null
//  Remarks:
//      Null
//  Date:
//      2011-12-09
// Author:
//      Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef __KERNEL_MOBIKIT_MOBILIB_EXPORT_IDKMTEXTITERATOR_H__
#define __KERNEL_MOBIKIT_MOBILIB_EXPORT_IDKMTEXTITERATOR_H__

#include "DKMDef.h"

class IDKMTextIterator
{
public:
    //-------------------------------------------
    //  Summary:
    //      �ƶ�����һλ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ������� DK_FALSE����Ӧ�ôӵ������м�����ȡ���ݡ�
    //  Remarks:
    //      Null
    //  Availability:
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL MoveToNext() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ƶ���ǰһλ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ������� DK_FALSE����Ӧ�ôӵ������м�����ȡ���ݡ�
    //  Remarks:
    //      Null
    //  Availability:
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL MoveToPrev() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ƶ�����һ�е�����λ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ������� DK_FALSE����Ӧ�ôӵ������м�����ȡ���ݡ�
    //  Remarks:
    //      Null
    //  Availability:
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL MoveToPrevAdjacentLine() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ƶ�����һ�е�����λ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ������� DK_FALSE����Ӧ�ôӵ������м�����ȡ���ݡ�
    //  Remarks:
    //      Null
    //  Availability:
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL MoveToNextAdjacentLine() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��ǰλ�õ��ַ���Ϣ��
    //  Parameters:
    //      [out] pCharInfo          - ��ǰλ���ַ���Ϣ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID GetCurrentCharInfo(DKM_CHAR_INFO *pCharInfo) const = 0;

public:
    virtual ~IDKMTextIterator() {}
};

#endif // __KERNEL_MOBIKIT_MOBILIB_EXPORT_IDKMTEXTITERATOR_H__
