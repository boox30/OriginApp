//===========================================================================
//  Summary:
//      ePubҳ�����
//  Usage:
//      ͨ��ҳ�浼���ӿڻ��ҳ���������ҳ�������ȴ���
//  Remarks:
//      Null
//  Date:
//      2013-07-22
// Author:
//      Zhang Lei (zhanglei@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEPAGEUNIT_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEPAGEUNIT_H__

//===========================================================================

#include "DKEDef.h"

//===========================================================================

class IDKEPageUnit
{
public:
    virtual ~IDKEPageUnit() {}

public:
    //-------------------------------------------
    //  Summary:
    //      ��ȡ�������͡�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��������
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DKE_PAGEUNIT_TYPE GetType() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�����ڵ�ǰҳ�����Ӿ��Ρ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��Ӿ���
    //  Remarks:
    //      ��ҳ�����Ͻ�Ϊԭ�㡣
    //  Availability:
    //      ��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetBoundary() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�������ʽλ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��ʽλ��
    //  Remarks:
    //      ����ԭ��Ԫ��Ϊ���������������ڷ�ԭ��Ԫ�ص�������ʼ��ʽλ��
    //  Availability:
    //      ��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_FLOWPOSITION GetFlowPosition() const = 0;
};

//===========================================================================

class IDKEPageBlock : public IDKEPageUnit
{
public:
    virtual ~IDKEPageBlock() {}

public:
    //-------------------------------------------
    //  Summary:
    //      ��ȡ�������ʼλ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��ʼλ��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_FLOWPOSITION GetBeginPosition() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ����Ľ���λ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ����λ��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_FLOWPOSITION GetEndPosition() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ʼö�١�
    //  Parameters:
    //      Null
    //  Return Value:
    //      �ɹ����
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL BeginEnum() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ƶ�����һ��ö��λ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      �ɹ����
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL MoveNext() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��ǰö�ٶ���
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��ǰö�ٶ���
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEPageUnit* GetCurUnit() = 0;

    //-------------------------------------------
    //  Summary:
    //      ����ö�١�
    //  Parameters:
    //      Null
    //  Return Value:
    //      �ɹ����
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL EndEnum() = 0;
};

//===========================================================================

class IDKEPageText : public IDKEPageUnit
{
public:
    virtual ~IDKEPageText() {}

public:
    //-------------------------------------------
    //	Summary:
    //		��ȡ��ǰλ�õ�Text��Ϣ��
    //  Parameters:
    //		[out] pTextInfo            - ��ǰλ��Text��Ϣ��
    //	Return Value:
    //	    Null
    //	Remarks:
    //		����FreeTextInfo�ͷ�pTextInfo hold����Դ
    //  Availability:
    //		��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID GetTextInfo(DKEPageTextInfo* pTextInfo) const = 0;

    //-------------------------------------------
    //	Summary:
    //		�ͷ�Text��Ϣ��
    //  Parameters:
    //		[in] pTextInfo             - ���ͷŵ���Ϣ��
    //	Return Value:
    //	    Null
    //	Remarks:
    //		Null
    //  Availability:
    //		��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeTextInfo(DKEPageTextInfo* pTextInfo) = 0;
};

//===========================================================================

class IDKEPageImage : public IDKEPageUnit
{
public:
    virtual ~IDKEPageImage() {}

public:
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
    //		��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID GetImageInfo(DKE_HITTEST_OBJECTINFO* pImageInfo) const = 0;

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
    //		��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeImageInfo(DKE_HITTEST_OBJECTINFO* pImageInfo) = 0;
};

//===========================================================================

class IDKEPagePath : public IDKEPageUnit
{
public:
    virtual ~IDKEPagePath() {}

public:
    //-------------------------------------------
    //	Summary:
    //		��ȡ��ǰλ�õ�Path��Ϣ��
    //  Parameters:
    //		[out] pPathInfo            - ��ǰλ��Path��Ϣ��
    //	Return Value:
    //	    Null
    //	Remarks:
    //		����FreePathInfo�ͷ�pPathInfo hold����Դ
    //  Availability:
    //		��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID GetPathInfo(DKEPagePathInfo* pPathInfo) const = 0;

    //-------------------------------------------
    //	Summary:
    //		�ͷ�Path��Ϣ��
    //  Parameters:
    //		[in] pPathInfo             - ���ͷŵ���Ϣ��
    //	Return Value:
    //	    Null
    //	Remarks:
    //		Null
    //  Availability:
    //		��ePubLib 2.6.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreePathInfo(DKEPagePathInfo* pPathInfo) = 0;
};

//===========================================================================

#endif // __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEPAGEUNIT_H__

