//===========================================================================
// Summary:
//		ҳ��ɵ������ĵ�����
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2013-05-21
// Author:
//		Zhang Jiafang(zhangjf@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEHITABLEOBJITERATOR_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEHITABLEOBJITERATOR_H__

//===========================================================================

#include "DKEDef.h"

//===========================================================================

class IDKEGallery;

class IDKEHitableObjIterator
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
	//		��ePubLib 2.5.0��ʼ֧�֡�
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
	//		��ePubLib 2.5.0��ʼ֧�֡�
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
	//		��ePubLib 2.5.0��ʼ֧�֡�
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
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_BOOL MoveToNextAdjacentLine() = 0;

    //-------------------------------------------
	//	Summary:
	//		���õ����������һ��λ��
	//  Parameters:
	//		Null
	//	Return Value:
	//		������� DK_FALSE ���ƶ�ʧ��
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_BOOL MoveToLast() = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ����ҳ����������
	//  Parameters:
	//		Null
	//	Return Value:
	//		ҳ���������
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DKE_PAGEOBJ_TYPE GetCurrentObjType() const = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ����ҳ��������ʽ����
	//  Parameters:
	//		Null
	//	Return Value:
	//		��ǰҳ�����ʽ����
	//	Remarks:
	//		����ʱ���ػ��ȵĿ�ʼ����
	//  Availability:
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_FLOWPOSITION GetCurrentFlowPosition() const = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ����ҳ��������Ӿ���
	//  Parameters:
	//		Null
	//	Return Value:
	//		��ǰҳ��������Ӿ���
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_BOX GetCurrentBoundingBox() const = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰλ�õ��ַ���Ϣ��
	//  Parameters:
	//		[out] pCharInfo          - ��ǰλ���ַ���Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		��ǰ��ҳ���������ΪDKE_PAGEOBJ_TEXTʱ��Ч
	//  Availability:
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
	virtual DK_VOID GetCurrentCharInfo(DKE_CHAR_INFO* pCharInfo) const = 0;

    //-------------------------------------------
	//	Summary:
	//		�жϵ�ǰλ�õ�ͼƬ�Ƿ������ĸ�ý�����
	//  Parameters:
	//		Null
	//	Return Value:
	//	    Null
	//	Remarks:
	//		��ǰ��ҳ���������ΪDKE_PAGEOBJ_IMAGE��DKE_PAGEOBJ_AUDIOʱ��Ч
	//  Availability:
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_BOOL IsCurrentFollowRichMedia() const = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰλ�õĸ�ý�������Ϣ
	//  Parameters:
	//		[out] pObjInfo          - ��ǰλ�ø�ý����Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		��ǰ��ҳ���������ΪͼƬ��������ͨͼ����̬ͼ������ͼ������Ƶ����Ƶʱ��Ч������FreeCurrentRichMediaInfo�ͷ�
	//  Availability:
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID GetCurrentRichMediaInfo(DKE_HITTEST_OBJECTINFO* pObjInfo) const = 0;

    //-------------------------------------------
	//	Summary:
	//		�ͷŵ�ǰλ�õĸ�ý�������Ϣ
	//  Parameters:
	//		[out] pObjInfo          - ��ǰλ�ø�ý����Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		null
	//  Availability:
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID FreeRichMediaInfo(DKE_HITTEST_OBJECTINFO* pObjInfo) = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰλ�õĽ�ע��Ϣ��
	//  Parameters:
	//		[out] pFnInfo            - ��ǰλ�ý�ע��Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		��ǰҳ�����ΪDKE_PAGEOBJ_FOOTNOTEʱ��Ч������FreeFootnoteInfo�ͷ���Դ
	//  Availability:
	//		��ePubLib 2.5.0��ʼ֧�֡�
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
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID FreeFootnoteInfo(DKE_FOOTNOTE_INFO* pFnInfo) = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰλ�õĻ��ȶ�����Ϣ
	//  Parameters:
	//		[out] ppGallery          - ��ǰ������Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		��ǰ��ҳ�����ΪDKE_PAGEOBJ_GALLERYʱ��Ч������FreeGalleryInfo�ͷ���Դ
	//  Availability:
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID GetCurrentGalleryInfo(IDKEGallery** ppGallery) const = 0;

    //-------------------------------------------
	//	Summary:
	//		�ͷŵ�ǰλ�õĻ��ȶ�����Ϣ
	//  Parameters:
	//		[out] pGallery          - ��ǰλ�û�����Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.5.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID FreeGalleryInfo(IDKEGallery* pGallery) = 0;

    //-------------------------------------------
	//	Summary:
	//		��ȡ��ǰλ�õ�PRE�������Ϣ
	//  Parameters:
	//		[out] pPreBlockInfo         - ��ǰPRE����Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		��ǰ��ҳ�����ΪDKE_PAGEOBJ_PREBLOCKʱ��Ч������FreeGalleryInfo�ͷ���Դ
	//  Availability:
	//		��ePubLib 2.7.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID GetCurrentPreBlockInfo(DKE_PREBLOCK_INFO* pPreBlockInfo) const = 0;

    //-------------------------------------------
	//	Summary:
	//		�ͷŵ�ǰλ�õĻ��ȶ�����Ϣ
	//  Parameters:
	//		[out] pPreBlockInfo          - ��ǰPRE����Ϣ��
	//	Return Value:
	//	    Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��ePubLib 2.7.0��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID FreePreBlockInfo(DKE_PREBLOCK_INFO* pPreBlockInfo) = 0;

public:
    virtual ~IDKEHitableObjIterator() {}
};

//===========================================================================

#endif // __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEHITABLEOBJITERATOR_H__
