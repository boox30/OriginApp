//===========================================================================
// Summary:
//		ҳ�滭�ȶ���������ӿڡ�
// Usage:
//		ö�ٵ�ǰҳ�������л���ö����
// Remarks:
//		Null
// Date:
//		2013-03-25
// Author:
//		Zhang Jiafang (zhangjf@duokan.com)
//===========================================================================


#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEGALLERYITERATOR_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEGALLERYITERATOR_H__

//===========================================================================

#include "DKEDef.h"

//===========================================================================

class IDKEGallery;

class IDKEGalleryIterator
{
public:
    virtual ~IDKEGalleryIterator() {}

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
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_BOOL MoveToNext() = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ���ȵ���Ϣ
	//  Parameters:
	//		[out] ppGallery         - ��ǰ������Ϣ
	//	Return Value:
	//		Null
	//	Remarks:
	//		����FreeCurGallery�ͷ���Դ
	//  Availability:
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID GetCurGallery(IDKEGallery** ppGallery) const = 0;

    //-------------------------------------------
	//	Summary:
	//		�ͷŵ�ǰ���ȵĻ�����Ϣ
	//  Parameters:
	//		[in] pGallery           - ��ǰ������Ϣ
	//	Return Value:
	//		Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID FreeCurGallery(IDKEGallery* pGallery) = 0;
};


#endif // __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEGALLERYITERATOR_H__

