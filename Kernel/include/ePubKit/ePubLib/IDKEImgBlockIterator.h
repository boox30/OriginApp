//===========================================================================
// Summary:
//		ҳ���Զ���ͼƬ��ö����
// Usage:
//		ö�ٵ�ǰҳ���������Զ���ͼƬ��
// Remarks:
//		��ö�ٵ��Զ���ͼƬ�������STATIC, SINGLE, CROSSPAGE, MULTICALLOUT
// Date:
//		2013-08-12
// Author:
//		Zhang Jiafang (zhangjf@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEIMGBLOCKITERATOR_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEIMGBLOCKITERATOR_H__

#include "DKEDef.h"

class IDKEMultiCallout;

class IDKEImgBlockIterator
{
public:
    virtual ~IDKEImgBlockIterator() {}

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
	//		��ePubLib 2.6.1��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_BOOL MoveToNext() = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰͼƬ�������
	//  Parameters:
	//		Null
	//	Return Value:
	//		��ǰͼƬ�������
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.6.1��ʼ֧�֡�
	//-------------------------------------------
    virtual DKE_IMAGEBLOCK_TYPE GetCurImgBlockType() const = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰλ��ͼƬ��������Ϣ
	//  Parameters:
	//		[out]pImgBlockInfo     - ͼƬ����Ϣ
	//	Return Value:
	//		Null
	//	Remarks:
	//		����FreeCurImgBlockInfo�ͷ���Դ
	//  Availability:
	//		��ePubLib 2.6.1��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID GetCurImgBlockInfo(DKE_IMAGEBLOCK_INFO* pImgBlockInfo) const = 0;

    //-------------------------------------------
	//	Summary:
	//		�ͷ�ͼƬ��������Ϣ
	//  Parameters:
	//		[out]pImgBlockInfo     - ͼƬ����Ϣ
	//	Return Value:
	//		Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.6.1��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID FreeImgBlockInfo(DKE_IMAGEBLOCK_INFO* pImgBlockInfo) = 0;
};

#endif // __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEIMGBLOCKITERATOR_H__
