//===========================================================================
//  Summary:
//      ePub����Ƭ�ζ����ࡣ
//  Usage:
//      ������Ƭ�������ֺţ������Ű���Ϣ�����Ը�Ƭ�ν����Ű棬��ȡ�Ű���ҳ�����
//  Remarks:
//      Null
//  Date:
//      2011-10-17
//  Author:
//      Zhang Jiafang (zhangjf@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKESECTION_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKESECTION_H__


//===========================================================================

#include "DKEDef.h"

//===========================================================================

class IDKEPage;

class IDKESection
{
public:
    virtual ~IDKESection() {}

public:
    //-------------------------------------------
    //  Summary:
    //      ����Ƭ���ֺŴ�С��
    //  Parameters:
    //      [in] fontSize        - �ֺŴ�С��
    //  Return Value:
    //      Null
    //  Remarks:
    //      �����ֺ�ֻ��һ���ο�ֵ����Ӱ�����кʹ˲ο�ֵ��ص��ֺš���parse֮ǰ���á�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetFontSize(DK_DOUBLE fontSize) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����Ƭ���м�ࡣ
    //  Parameters:
    //      [in] lineGap        - �м�౶����
    //  Return Value:
    //      Null
    //  Remarks:
    //      ��parse֮ǰ���á�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetLineGap(DK_DOUBLE lineGap) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����Ƭ�ζμ�౶����
    //  Parameters:
    //      [in] paraSpacing    - �μ�౶����
    //  Return Value:
    //      Null
    //  Remarks:
    //      ���μ��С���У�lineGap - 1��ʱ�μ��ȡ��lineGap - 1������parse֮ǰ���á�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetParaSpacing(DK_DOUBLE paraSpacing) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����Ƭ��Tab��С��
    //  Parameters:
    //      [in] tabStop        - Tab�Ĵ�С�����ַ����Ϊ��λ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      ��parse֮ǰ���á�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetTabStop(DK_DOUBLE tabStop) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����Ƭ������������
    //  Parameters:
    //      [in] indent            - Ĭ���ֺŴ�С��
    //  Return Value:
    //      Null
    //  Remarks:
    //      ��parse֮ǰ���á�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetFirstLineIndent(DK_DOUBLE indent) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����Ƭ��������ɫ��
    //  Parameters:
    //      [in] textColor      - �ı���ɫֵ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      �˽ӿڽ���������������ֵ���ɫ����������Ƭ����ָ������ɫ��
    //      ���� ResetAllColor �ӿڽ��ָ�Ƭ��ԭɫ���á�
    //      �ýӿ��������½������Ű棬���� ParseChapter ����á�
    //      ��parse֮ǰ���á�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetTextColor(const DK_ARGBCOLOR& textColor) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����������ɫ��
    //  Parameters:
    //      Null
    //  Return Value:
    //      Null
    //  Remarks:
    //      �˽ӿڽ���������������ֵ���ɫ���ָ�Ƭ��ԭɫ���á�
    //      �ýӿ��������½������Ű棬���� ParseContent ����á�
    //      ��parse֮ǰ���á�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID ResetAllTextColor() = 0;

    //-------------------------------------------
    //  Summary:
    //      �����Ű�ģʽ��
    //  Parameters:
    //      [in] typeSetting            - �Ű�ģʽ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      ��parse֮ǰ���á�
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetTypeSetting(DKTYPESETTING typeSetting) = 0;

public:
    //-------------------------------------------
    //  Summary:
    //      ����ҳ������
    //  Parameters:
    //      [in] pageBox             - ҳ������
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ��parse֮ǰ���á�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetPageBox(const DK_BOX& pageBox) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����Ƭ�����ݡ�
    //  Parameters:
    //      [in] option             - ������ѡ��μ� DKE_PARSER_OPTION �ṹ˵����
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode ParseSection(DK_BOOL bDoPageBreaking = DK_TRUE) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡƬ�ν������ҳ��
    //  Parameters:
    //      Null
    //  Return Value:
    //      Ƭ��ҳ��
    //  Remarks:
    //      ��Ҫ�� ParseChapter ����֮�����
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_LONG GetPageCount() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ����ҳ���ȡҳ����
    //  Parameters:
    //      [in] pageNum        - ��Ƭ�η�Χ�ڵ�ҳ�룬��0��ʼ��
    //  Return Value:
    //      ҳ�����ָ��
    //  Remarks:
    //      ��Ҫ�� ParseChapter ����֮�����
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEPage* GetPage(DK_LONG pageNum) = 0;

    //-------------------------------------------
    //  Summary:
    //      ������ʽ������Ӧ��ҳ�롣����ʽ��������ҳ�������ڼ���
    //  Parameters:
    //      [in] pos            - ��ʽ���ꡣ
    //  Return Value:
    //      ҳ�룬��0��ʼ
    //  Remarks:
    //      ��Ҫ�� ParseChapter ����֮�����
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_LONG GetPageNum(const DK_FLOWPOSITION& pos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����ê������ƻ�ȡ��ê����Ƭ���ڵ���ʽ����
    //  Parameters:
    //      [in] pAnchor            - ê�������
    //      [out] pPos              - ê���Ӧ����ʽ����
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ��Ҫ�� ParseChapter ����֮�����
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetAnchorPosition(const DK_WCHAR* pAnchor, DK_FLOWPOSITION* pPos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ���Ƭ�����ѽ�����ҳ����
    //  Parameters:
    //      Null
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID ClearParsedPages() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡƬ�ε��ı�
    //  Parameters:
    //      Null
    //  Return Value:
    //      �ı�ָ��
    //  Remarks:
    //      ��Ҫ����FreeChapterText�ͷŷ���ֵ���ڴ�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_WCHAR* GetSectionText() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡƬ�ε��ı�
    //  Parameters:
    //      [in] pText            - ��Ҫ�ͷŵ��ı�
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeSectionText(DK_WCHAR* pText) = 0;
};

//===========================================================================

#endif // __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKECHAPTER_H__
