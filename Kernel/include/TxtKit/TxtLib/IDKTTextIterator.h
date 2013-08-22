//===========================================================================
// Summary:
//		ҳ�����ֶ���������ӿڡ�
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-12-19
// Author:
//		Peng Feng (pengf@duokan.com)
//===========================================================================

#ifndef __KERNEL_TXTKIT_TXTLIB_EXPORT_IDKTTEXTITERATOR_H__
#define __KERNEL_TXTKIT_TXTLIB_EXPORT_IDKTTEXTITERATOR_H__

//===========================================================================

#include "DKTDef.h"
#include "KernelRetCode.h"

//===========================================================================


class IDKTTextIterator
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
	//		���˶�ĩ�Ļس���ҳĩ֮��,���ֻӦͣ���ڿɼ��ַ�ǰ
	//  Availability:
	//		��TxtLib 1.0��ʼ֧�֡�
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
	//		��TxtLib 1.0��ʼ֧�֡�
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
	//		��TxtLib 1.0��ʼ֧�֡�
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
	//		��TxtLib 1.0��ʼ֧�֡�
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
	//		��TxtLib 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_ReturnCode GetCurrentCharInfo(DKT_CHAR_INFO* pCharInfo) const = 0;

public:
    virtual ~IDKTTextIterator() {}
};

//===========================================================================

#endif // #ifndef __IDKETEXTITERATOR_HEADERFILE__
