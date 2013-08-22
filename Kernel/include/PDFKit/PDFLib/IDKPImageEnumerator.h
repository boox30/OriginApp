//===========================================================================
// Summary:
//		IDKPImageEnumerator��ö��ͼ��Ľӿ��ࡣ 
// Usage:
//		��IDKPPage�л�á�
// Remarks:
//		Null
// Date:
//		2011-10-31
// Author:
//		Zhang JingDan (zhangjingdan@duokan.com)
//===========================================================================

#ifndef __KERNEL_PDFKIT_PDFLIB_IDKPIMAGEENUMERATOR_H__
#define __KERNEL_PDFKIT_PDFLIB_IDKPIMAGEENUMERATOR_H__

//===========================================================================

#include "DKPTypeDef.h"

//===========================================================================

class IDKPImageEnumerator
{
public:
	//----------------------------------------------------
	// Summary:
	//		�ص���ʼλ�ã�ÿһ��ö�ٿ�ʼ��Ҫʹ�ô˺�����
	//		������DK_FALSE����Ӧ���ٴ�ö����ȡ�κ����ݡ�
	// SDK Version:
	//		��DKP 5.0.0��ʼ֧��
	//----------------------------------------------------
	virtual DK_BOOL Reset() = 0;

	//----------------------------------------------------
	// Summary:
	// 		ǰ������һ��λ�ã��������DK_FALSE����
	//		Ӧ���ٴ�ö����ȡ�κ����ݡ�
	// SDK Version:
	//		��DKP 5.0.0��ʼ֧��
	//----------------------------------------------------
	virtual DK_BOOL MoveNext() = 0;

	//-------------------------------------------
	// Summary:
	//		ȡ�õ�ǰ��ͼ����Ϣ��
	// Parameters:
	//		[out] imageInfo - �����ͼ����Ϣ��
	// SDK Version:
	//		��DKP 5.0.0��ʼ֧��
	//-------------------------------------------
	virtual DK_BOOL Current(DKPIMAGECONTENT& imageInfo) = 0;

public:
	virtual ~IDKPImageEnumerator() {}
};

//===========================================================================

#endif
