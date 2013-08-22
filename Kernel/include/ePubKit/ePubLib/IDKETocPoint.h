//===========================================================================
// Summary:
//		ePubͼ��Ŀ¼�ӿڡ�
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-09-16
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKETOCPOINT_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKETOCPOINT_H__

//===========================================================================

#include "DKEDef.h"

//===========================================================================

class IDKETocPoint
{
public:
	//-------------------------------------------
	//	Summary:
	//		��ȡĿ¼�ڵ��������ݡ�
	//  Parameters:
	//		Null
	//	Return Value:
	//		Ŀ¼�ڵ��������ݡ�
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual const DK_WCHAR* GetTitle() = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��תĿ�ꡣ
	//  Parameters:
	//		Null
	//	Return Value:
	//		Ŀ������URL���ӡ�
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual const DK_WCHAR* GetDest() const = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��תĿ������λ�á�
	//  Parameters:
	//		[out] destPos           - Ŀ��������ʽ���ꡣ
	//	Return Value:
	//		����ɹ�����DKR_OK��
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_ReturnCode GetDestPosition(DK_FLOWPOSITION& destPos) = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��תĿ��λ�õ�ê�����ơ�
	//  Parameters:
	//		NULL
	//	Return Value:
	//		ê������
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.2��ʼ֧�֡�
	//-------------------------------------------
    virtual const DK_WCHAR* GetDestAnchor() const = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ�ڵ����ȡ�
	//  Parameters:
	//		Null
	//	Return Value:
	//		�ڵ���ȡ�
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_INT GetDepth() const = 0;

	//-------------------------------------------
	//	Summary:
	//		��ǰ�ڵ�Ŀ�������Ƿ���Ч��
	//  Parameters:
	//		Null
	//	Return Value:
	//	    DK_TRUE/DK_FALSE
	//	Remarks:
	//		������� ePub �淶��һ����չ��
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_BOOL IsContentValid() const = 0;

public:
	//-------------------------------------------
	//	Summary:
	//		��ȡ�ӽڵ������
	//  Parameters:
	//		Null
	//	Return Value:
	//		�ӽڵ������
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_LONG GetChildCount() const = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ�ӽڵ㡣
	//  Parameters:
	//		[in] index              - �ӽڵ���������0��ʼ��
	//	Return Value:
	//		�ӽڵ����ӿڡ�
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual IDKETocPoint* GetChildByIndex(DK_UINT index) const = 0;

public:
    virtual ~IDKETocPoint() {}
};

//===========================================================================

#endif // #ifndef __IDKETOCPOINT_HEADERFILE__
