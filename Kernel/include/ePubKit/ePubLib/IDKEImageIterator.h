//===========================================================================
// Summary:
//		ҳ��ͼƬ����������ӿڡ�
// Usage:
//		ö�ٵ�ǰҳ��������ͼƬ����Ϣ����ͼƬ����Ӿ��Σ�ͼƬԭʼ���ݺ��ⲿ���ݵ�
// Remarks:
//		ͼƬ���������ͨͼƬ��DKE_PAGEOBJ_IMAGE �� �ɵ��ͼƬ��DKE_PAGEOBJ_INTERACIVEIMAGE
// Date:
//		2012-02-14
// Author:
//		Zhang Jiafang (zhangjf@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEIMAGEITERATOR_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEIMAGEITERATOR_H__

//===========================================================================

#include "DKEDef.h"

//===========================================================================

class IDKEImageIterator
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
	//		��ȡ��ǰλ�õ�ͼƬ�����ͣ�����ͨͼ����̬ͼ������ͼ�ȡ�
	//  Parameters:
	//		Null
	//	Return Value:
	//	    DKE_PAGEOBJ_TYPE
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.1��ʼ֧�֡�
	//-------------------------------------------
    virtual DKE_PAGEOBJ_TYPE GetCurrentImageType() const = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰλ�õ�ͼƬ��Ϣ��
	//  Parameters:
	//		[out] pImageInfo            - ��ǰλ��ͼƬ��Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		����FreeImageInfo�ͷ�pImageInfo hold����Դ
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_VOID GetCurrentImageInfo(DKE_HITTEST_OBJECTINFO* pImageInfo) const = 0;

	//-------------------------------------------
	//	Summary:
	//		�ͷ�ͼƬ��Ϣ��
	//  Parameters:
	//		[in] pImageInfo             - ���ͷŵ���Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID FreeImageInfo(DKE_HITTEST_OBJECTINFO* pImageInfo) = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰͼƬ����Ӿ���
	//  Parameters:
	//		null
	//	Return Value:
	//	    DK_BOX ��Ӿ���
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 1.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_BOX GetCurrentImageBox() const = 0;

    //-------------------------------------------
    //	Summary:
    //		��ȡ��ǰͼƬ�Ĳü���
    //  Parameters:
    //		null
    //	Return Value:
    //	    DK_BOX �ü���
    //	Remarks:
    //		�޲ü���ʱ����ͼ������
    //  Availability:
    //		��ePubLib 2.4.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetCurrentImageClipBox() const = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰͼƬ��ԭʼ��С
	//  Parameters:
	//		null
	//	Return Value:
	//	    DK_BOX ԭʼ��С�����ϵ�Ϊ0�����µ�Ϊ���
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.1.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID GetCurrentImageSize(DK_UINT* pWidth, DK_UINT* pHeight) const = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰͼƬ�İ���ȫ·��
	//  Parameters:
	//		null
	//	Return Value:
	//	    ����ȫ·��
	//	Remarks:
	//		����FreeCurrentImagePath�ͷŷ���ֵ�ڴ�
	//  Availability:
	//		��ePubLib 2.1.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_WCHAR* GetCurrentImagePath() const = 0;

    //-------------------------------------------
	//	Summary:
	//		�ͷŵ�ǰͼƬ·�����ڴ�
	//  Parameters:
	//		[in]pImagePath          - ��ǰͼƬ�İ���ȫ·��
	//	Return Value:
	//	    ����ȫ·��
	//	Remarks:
    //      null
	//  Availability:
	//		��ePubLib 2.1.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID FreeCurrentImagePath(DK_WCHAR* pImagePath) = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰͼƬ�ı��⣬����������͸�����
	//  Parameters:
	//		[in]ppMainTitle          - ������
    //      [in]ppSubTitle           - ������
	//	Return Value:
	//	    Null
	//	Remarks:
    //      ͼƬ���ܲ������κα��⣬Ҳ����ֻ�������⣬Ҳ����������������ڡ�
    //      ����FreeCurrentImageTitle�ͷ�ռ�õ��ڴ�
	//  Availability:
	//		��ePubLib 2.2.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID GetCurrentImageTitle(RichTextString** ppMainTitle, RichTextString** ppSubTitle) const = 0;

    //-------------------------------------------
	//	Summary:
	//		�ͷŵ�ǰͼƬ�ı��⣬����������͸�����
	//  Parameters:
	//		[in]pMainTitle          - ������
    //      [in]pSubTitle           - ������
	//	Return Value:
	//	    Null
	//	Remarks:
    //      Null
	//  Availability:
	//		��ePubLib 2.2.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID FreeCurrentImageTitle(RichTextString* pMainTitle, RichTextString* pSubTitle) = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰͼƬ����������
	//  Parameters:
    //      Null
	//	Return Value:
	//	    ��ǰͼƬ����������
	//	Remarks:
    //      Null
	//  Availability:
	//		��ePubLib 2.4.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_FLOWPOSITION GetCurrentFlowPosition() const = 0;

public:
    virtual ~IDKEImageIterator() {}
};

//===========================================================================

#endif // #ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEIMAGEITERATOR_H__
