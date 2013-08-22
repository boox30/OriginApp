//===========================================================================
// Summary:
//		ҳ���ע����������ӿڡ�
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2012-12-12
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEFOOTNOTEITERATOR_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEFOOTNOTEITERATOR_H__

//===========================================================================

#include "DKEDef.h"

//===========================================================================

class IDKEFootnoteIterator
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
	//		��ȡ��ǰλ�õĽ�ע��Ϣ��
	//  Parameters:
	//		[out] pFnInfo            - ��ǰλ�ý�ע��Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		���տ�����ҳ��չ�ַ�ʽ��DKE_SHOWCONTENT_FLEXPAGE������
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_VOID GetCurrentFootnoteInfo(DKE_FOOTNOTE_INFO* pFnInfo) const = 0;

	//-------------------------------------------
	//	Summary:
	//		�ͷŽ�ע��Ϣ��
	//  Parameters:
	//		[in] pFnInfo             - ���ͷŵĽ�ע��Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID FreeFootnoteInfo(DKE_FOOTNOTE_INFO* pFnInfo) = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ��ע����������
	//  Parameters:
	//		Null
	//	Return Value:
	//	    ��ǰ��ע����������
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.4.0��ʼ֧��
	//-------------------------------------------
    virtual DK_FLOWPOSITION GetCurrentFlowPosition() const = 0;

public:
    virtual ~IDKEFootnoteIterator() {}
};

//===========================================================================

#endif // #ifndef __IDKEFOOTNOTEITERATOR_HEADERFILE__
