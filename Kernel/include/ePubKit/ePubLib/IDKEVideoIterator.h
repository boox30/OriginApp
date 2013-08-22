//===========================================================================
// Summary:
//		ҳ����Ƶ����������ӿڡ�
// Usage:
//		ö�ٵ�ǰҳ����������Ƶ����Ϣ������Ƶ����Ӿ��Σ���Ƶԭʼ���ݣ�����ƵURL��
// Remarks:
//      NULL
// Date:
//		2012-02-14
// Author:
//		Liu Hongjia(liuhj@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEVIDEOITERATOR_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEVIDEOITERATOR_H__

//===========================================================================

#include "DKEDef.h"

class IDKEVideoIterator
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
	//		��ȡ��ǰλ�õ���Ƶ��Ϣ��
	//  Parameters:
	//		[out] pVideoInfo            - ��ǰλ����Ƶ��Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		���� FreeVideoInfo �ͷ� pVideoInfo
	//  Availability:
	//		��ePubLib 2.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_VOID GetCurrentVideoInfo(DKE_HITTEST_OBJECTINFO* pVideoInfo) const = 0;

	//-------------------------------------------
	//	Summary:
	//		�ͷ���Ƶ��Ϣ��
	//  Parameters:
	//		[in] pVideoInfo             - ���ͷŵ���Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID FreeVideoInfo(DKE_HITTEST_OBJECTINFO* pVideoInfo) = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ��Ƶ����Ӿ���
	//  Parameters:
	//		null
	//	Return Value:
	//	    DK_BOX ��Ӿ���
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_BOX GetCurrentVideoBox() const = 0;

public:
    virtual ~IDKEVideoIterator() {}
};

//===========================================================================

#endif // #ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEVIDEOITERATOR_H__
