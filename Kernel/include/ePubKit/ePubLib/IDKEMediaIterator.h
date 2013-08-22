//===========================================================================
// Summary:
//		ҳ������Ƶ����������ӿڡ�
// Usage:
//		ö�ٵ�ǰҳ������������Ƶ����Ϣ��������Ƶ����Ӿ��Σ�����Ƶԭʼ���ݣ�������ƵURL��
// Remarks:
//      NULL
// Date:
//		2012-02-14
// Author:
//		Liu Hongjia(liuhj@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEMEDIAITERATOR_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEMEDIAITERATOR_H__

//===========================================================================

#include "DKEDef.h"

class IDKEMediaIterator
{
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
	//		��ePubLib 2.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_BOOL MoveToNext() = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰλ�õ�����Ƶ��Ϣ��
	//  Parameters:
	//		[out] pMediaInfo            - ��ǰλ����Ƶ��Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		���� FreeMediaInfo �ͷ� pMediaInfo
	//  Availability:
	//		��ePubLib 2.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_VOID GetCurrentMediaInfo(DKE_HITTEST_OBJECTINFO* pMediaInfo) const = 0;

	//-------------------------------------------
	//	Summary:
	//		�ͷ�����Ƶ��Ϣ��
	//  Parameters:
	//		[in] pMediaInfo             - ���ͷŵ���Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID FreeMediaInfo(DKE_HITTEST_OBJECTINFO* pMediaInfo) = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ����Ƶ����Ӿ���
	//  Parameters:
	//		null
	//	Return Value:
	//	    DK_BOX ��Ӿ���
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_BOX GetCurrentMediaBox() const = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ����Ƶ����������
	//  Parameters:
	//		null
	//	Return Value:
	//	    ��ǰ����Ƶ����������
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.4.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_FLOWPOSITION GetCurrentFlowPosition() const = 0;

public:
    virtual ~IDKEMediaIterator() {}
};

//===========================================================================

#endif // #ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEMEDIAITERATOR_H__
