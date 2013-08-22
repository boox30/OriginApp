//===========================================================================
// Summary:
//      IDKPOutline.h
//      �����ĵ�Ŀ¼��ȡ�Ľӿ��ࡣ
// Usage:
//      Null
// Remarks:
//      Null
// Date:
//      2011-10-24
// Author:
//      Liu Hongjia(liuhj@duokan.com)
//===========================================================================
#ifndef __KERNEL_PDFKIT_PDFLIB_IDKPOUTLINE_H__
#define __KERNEL_PDFKIT_PDFLIB_IDKPOUTLINE_H__

//===========================================================================

#include "ActionTypeDef.h"
#include "DKPTypeDef.h"

//===========================================================================

class IDKPOutline
{
public:
    //-------------------------------------------
    // Summary:
    //    ��ô򿪵�Ŀ¼��������
    // Returns:
    //    �ɹ��򷵻ش�Ŀ¼��������ʧ���򷵻�-1��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_INT GetOutlineOpenCount() = 0;

    //-------------------------------------------
    // Summary:
    //    ���ָ����ŵ�Ŀ¼�����ݡ�
    // Parameters:
    //    [in] itemIndex    - Ŀ¼����ţ���1��ʼ��
    //    [out] pItemInfo   - Ŀ¼�����ݡ�
    // Returns:
    //    �ɹ��򷵻�DK_TRUE��ʧ���򷵻�DK_FALSE��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_BOOL GetOutlineItemByIndex(DK_INT itemIndex, DKPOUTLINEITEMINFO* pItemInfo) = 0;

    //-------------------------------------------
    // Summary:
    //    ��ȡĿ¼���Action��������
    // Parameters:
    //    [in] itemIndex - Ŀ¼����ţ���1��ʼ��
    // Returns:
    //    ����Action��������
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_INT GetOutlineItemActionCount(DK_INT itemIndex) = 0;

    //-------------------------------------------
    // Summary:
    //    ��ȡ���������ݡ�
    // Parameters:
    //    [in] itemIndex    - Ŀ¼����ţ���1��ʼ��
    //    [in] actionIndex  - Action����š�
    //    [out] actionType  - Ŀ¼���������͡�
    //    [out] pActionInfo - ���������ݡ�
    // Returns:
    //    �ɹ��򷵻�DK_TRUE,ʧ�ܷ���DK_FALSE��
    // Remarks:
    //    �ýӿڵ������Σ���һ��pActionInfoΪDK_NULL,��ȡactionType��
    //    �ڶ��θ���actionType��ȡpActionInfo�����ݡ�
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_BOOL GetOutlineItemAction(DK_INT itemIndex, DK_INT actionIndex, DK_ACTION_TYPE& actionType, DK_VOID* pActionInfo) = 0;

    //-------------------------------------------
    // Summary:
    //    ��ȡĿ¼��ָ���ҳ�롣
    // Parameters:
    //    [in] itemIndex - Ŀ¼����ţ���1��ʼ��
    // Returns:
    //    �ɹ��򷵻�ҳ�룬ʧ���򷵻�-1��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_INT GetOutlineDestPageNum(DK_INT itemIndex) = 0;

    //-------------------------------------------
    // Summary:
    //    ��ȡָ��ָ��ҳ��ĵ�һ��Ŀ¼����š�
    // Parameters:
    //    [in] pageNum - ҳ�룬��1��ʼ��
    // Returns:
    //    �ɹ��򷵻�Ŀ¼����ţ�ʧ���򷵻�-1��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_INT GetOutlineIndexByPageNum(DK_INT pageNum) = 0;

    //-------------------------------------------
    // Summary:
    //    ��ȡĿ¼�
    // Parameters:
    //    [in] itemIndex    - Ŀ¼��������
    //    [out] pItemInfo   - Ŀ¼�����ݡ�
    //    [in] queryType    - ��ѯ���͡�
    // Return:
    //    �鵽����DK_TURE,ʧ�ܷ���DK_FALSE��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_BOOL GetOutlineNextItemInfo(const DK_WORD itemIndex, DKPOUTLINEITEMINFO* pItemInfo, DKP_TREEQUERY_TYPE queryType) = 0;

    //-------------------------------------------
    // Summary:
    //    �ͷ�Ŀ¼
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_INT Release() = 0;

public:
    virtual ~IDKPOutline() {}
};

//===========================================================================

#endif
