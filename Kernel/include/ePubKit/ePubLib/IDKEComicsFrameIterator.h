//===========================================================================
// Summary:
//		����ҳ��֡ö�ٽӿ�
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2012-12-17
// Author:
//		Zhang JiaFang
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKECOMICSFRAMEITERATOR_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKECOMICSFRAMEITERATOR_H__

//===========================================================================

#include "DKEDef.h"

//===========================================================================

class IDKEComicsFrameIterator
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
	//		��ePubLib 2.3.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_BOOL MoveToNext() = 0;

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
	//		��ePubLib 2.3.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_BOOL MoveToPrev() = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰλ������֡����ͼƬ���Ͻ�Ϊ���յ���Ӿ���
	//  Parameters:
	//		Null
	//	Return Value:
	//	    ��Ӿ���
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.3.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_BOX GetCurFrameBoundaryOnImage() const = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰλ������֡����ҳ�����Ͻ�Ϊ���յ���Ӿ���
	//  Parameters:
	//		Null
	//	Return Value:
	//	    ��Ӿ���
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.3.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_BOX GetCurFrameBoundaryOnPage() const = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ����֡������֡�Ķ������е�λ��
	//  Parameters:
	//		Null
	//	Return Value:
	//	    ֡�Ķ���Ӱ��λ��
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.3.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_LONG GetComicsFrameIndex() const = 0;

public:
    virtual ~IDKEComicsFrameIterator() {}
};

//===========================================================================

#endif // #ifndef __IDKEFOOTNOTEITERATOR_HEADERFILE__
