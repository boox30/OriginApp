//===========================================================================
// Summary:
//		ҳ�����ֶ���������ӿڡ�
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-12-09
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKETEXTITERATOR_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKETEXTITERATOR_H__

//===========================================================================

#include "DKEDef.h"

//===========================================================================

class IDKETextIterator
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
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_BOOL MoveToNext() = 0;

	//-------------------------------------------
	//	Summary:
	//		�ƶ���ǰһλ�á�
	//  Parameters:
	//		Null
	//	Return Value:
	//		������� DK_FALSE����Ӧ�ôӵ������м�����ȡ���ݡ�
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_BOOL MoveToPrev() = 0;

    //-------------------------------------------
	//	Summary:
	//		�ƶ�����һ�е�����λ�á�
	//  Parameters:
	//		Null
	//	Return Value:
	//		������� DK_FALSE����Ӧ�ôӵ������м�����ȡ���ݡ�
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_BOOL MoveToPrevAdjacentLine() = 0;

    //-------------------------------------------
	//	Summary:
	//		�ƶ�����һ�е�����λ�á�
	//  Parameters:
	//		Null
	//	Return Value:
	//		������� DK_FALSE����Ӧ�ôӵ������м�����ȡ���ݡ�
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_BOOL MoveToNextAdjacentLine() = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰλ�õ��ַ���Ϣ��
	//  Parameters:
	//		[out] pCharInfo          - ��ǰλ���ַ���Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_VOID GetCurrentCharInfo(DKE_CHAR_INFO* pCharInfo) const = 0;

public:
    virtual ~IDKETextIterator() {}
};

//===========================================================================

#endif // #ifndef __IDKETEXTITERATOR_HEADERFILE__
