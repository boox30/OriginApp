//===========================================================================
// Summary:
//      DKMDef.h
// Usage:
//      Mobi�����Html����չ���壬MobiLib�Ĺ���ͷ�ļ�
// Remarks:
//      Null
// Date:
//      2012-02-25
// Author:
//      Zhai Guanghe(zhaigh@duokan.com)
//===========================================================================

#ifndef __KERNEL_MOBIKIT_MOBILIB_EXPORT_DKMDEF_H__
#define __KERNEL_MOBIKIT_MOBILIB_EXPORT_DKMDEF_H__

#include "DKEDef.h" // ��ʱ����ePub�Ķ��壬�Ժ��ΪHtml��
#include "DKMRetCode.h"

// MOBI�ļ��Ļ�����Ϣ // TODO ����Mobi����
struct DKMBookInfo
{
    DK_WCHAR* pTitle;
    DK_WCHAR* pAuthor;
    DK_WCHAR* pSubject;
    DK_WCHAR* pPublisher;
    DK_WCHAR* pDescription;
    DK_WCHAR* pSource;
    DK_WCHAR* pDate;
    DK_WCHAR* pRights;
    DK_WCHAR* pContributor;

    DKMBookInfo()
        : pTitle(DK_NULL)
        , pAuthor(DK_NULL)
        , pSubject(DK_NULL)
        , pPublisher(DK_NULL)
        , pDescription(DK_NULL)
        , pSource(DK_NULL)
        , pDate(DK_NULL)
        , pRights(DK_NULL)
        , pContributor(DK_NULL)
    {
        // do nothing
    }
};

struct DKM_CHAR_INFO
{
    DK_BOX   boundingBox; // ��Ӿ���
    DK_WCHAR charCode;    // ���ֵ� Unicode ����
    DK_UINT  offset;      // ���ֵ�����λ��
};

#define MOBIAPI        extern "C" EPUB_API DK_BOOL
#define MOBIAPI_(type) extern "C" EPUB_API type

#ifndef MOBIDOCHANDLE // ��ʱ����redefine������
#define MOBIDOCHANDLE  DK_VOID *
#endif // MOBIDOCHANDLE

#endif // __KERNEL_MOBIKIT_MOBILIB_EXPORT_DKMDEF_H__
