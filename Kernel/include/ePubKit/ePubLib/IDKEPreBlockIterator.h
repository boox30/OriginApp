//===========================================================================
// Summary:
//		ҳ��Pre�����������ӿڡ�
// Usage:
//		ö�ٵ�ǰҳ��������Pre��ö����
// Remarks:
//		Null
// Date:
//		2013-07-17
// Author:
//		Zhang Jiafang (zhangjf@duokan.com)
//===========================================================================


#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEPREBLOCKITERATOR_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEPREBLOCKITERATOR_H__

//===========================================================================

#include "DKEDef.h"

//===========================================================================

class IDKEPreBlockIterator
{
public:
    virtual ~IDKEPreBlockIterator() {}

public:
	//-------------------------------------------
	//	Summary:
	//		�ƶ�����һλ�á�
	//  Parameters:
	//		Null
	//	Return Value:
	//		������� DK_FALSE����Ӧ�ôӵ������м�����ȡ���ݡ�
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.7.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_BOOL MoveToNext() = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰPre�����Ϣ
	//  Parameters:
	//		[out] pPreBlockInfo         - ��ǰPre����Ϣ
	//	Return Value:
	//		Null
	//	Remarks:
	//		����FreeCurPreBlockInfo�ͷ���Դ
	//  Availability:
	//		��ePubLib 2.7.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID GetCurPreBlockInfo(DKE_PREBLOCK_INFO* pPreBlockInfo) const = 0;

    //-------------------------------------------
	//	Summary:
	//		�ͷŵ�ǰPre�����Ϣ
	//  Parameters:
	//		[in] pPreBlockInfo           - ��ǰPre����Ϣ
	//	Return Value:
	//		Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.7.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID FreeCurPreBlockInfo(DKE_PREBLOCK_INFO* pPreBlockInfo) = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰҳ���ϵ�Pre�����ʽ��������
	//  Parameters:
	//		[in] pStartPos              - ��ǰPre�����ʼ����
    //      [in] pEndPos                - ��ǰPre��Ľ�������
	//	Return Value:
	//		Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.7.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID GetFlowPositionRange(DK_FLOWPOSITION* pStartPos, DK_FLOWPOSITION* pEndPos) const = 0;
};


#endif // __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEPREBLOCKITERATOR_H__

