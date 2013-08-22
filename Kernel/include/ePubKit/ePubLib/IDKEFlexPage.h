//===========================================================================
//  Summary:
//      ePubͼ�������ҳ�����ࡣ
//  Usage:
//      ����ҳ��Ŀ�Ȼ�߶Ⱥ��ֺţ��Ű�󷵻�ҳ��ĸ߶ȣ���Ⱦҳ�棬ʰȡҳ�����
//      ���������ÿ�ȣ�Ҳ�����ø߶�ʱ���տ�߾���������
//  Remarks:
//      Null
//  Date:
//      2011-10-17
// Author:
//      Zhang Jiafang (zhangjf@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEFLEXPAGE_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEFLEXPAGE_H__

//===========================================================================

#include "DKEDef.h"

//===========================================================================


class IDKEFlexPage
{
public:
    virtual ~IDKEFlexPage() {}

public:
    //-------------------------------------------
    //  Summary:
    //      ����ҳ���ֺŴ�С��
    //  Parameters:
    //      [in] fontSize        - ҳ���ֺŴ�С��
    //  Return Value:
    //      Null
    //  Remarks:
    //      ҳ���ֺ�ֻ��һ���ο�ֵ����Ӱ�����кʹ˲ο�ֵ��ص��ֺš�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetFontSize(DK_DOUBLE fontSize) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����ҳ���м�ࡣ
    //  Parameters:
    //      [in] lineGap        - �м�౶����
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetLineGap(DK_DOUBLE lineGap) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����ҳ��μ�౶����
    //  Parameters:
    //      [in] paraSpacing    - �μ�౶����
    //  Return Value:
    //      Null
    //  Remarks:
    //      ���μ��С���У�lineGap - 1��ʱ�μ��ȡ��lineGap - 1��
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetParaSpacing(DK_DOUBLE paraSpacing) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����ҳ��Tab��С��
    //  Parameters:
    //      [in] tabStop        - Tab�Ĵ�С�����ַ����Ϊ��λ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetTabStop(DK_DOUBLE tabStop) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����ҳ������������
    //  Parameters:
    //      [in] indent            - Ĭ���ֺŴ�С��
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetFirstLineIndent(DK_DOUBLE indent) = 0;

    //-------------------------------------------
    //  Summary:
    //      �����½�������ɫ��
    //  Parameters:
    //      [in] textColor      - �ı���ɫֵ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      �˽ӿڽ���������������ֵ���ɫ�����������½���ָ������ɫ��
    //      ���� ResetAllColor �ӿڽ��ָ��½�ԭɫ���á�
    //      �ýӿ��������½������Ű棬���� ParseChapter ����á�
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
    //      �˽ӿڽ���������������ֵ���ɫ���ָ��½�ԭɫ���á�
    //      �ýӿ��������½������Ű棬���� ParseContent ����á�
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
    //      Null
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetTypeSetting(DKTYPESETTING typeSetting) = 0;


    //-------------------------------------------
    //  Summary:
    //      ����ҳ������Ͻ�����
    //  Parameters:
    //      [in] topLeft          - ҳ�����Ͻǵ�
    //  Return Value:
    //      Null
    //  Remarks:
    //      ��Ϊ����ҳ�����Ͻ����꣬�����Ͻ�Ϊ(0,0)
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetPageTopLeft(DK_POS topLeft) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����Ҫ������ʱ��������ҳ���ȡ�
    //  Parameters:
    //      [in] pageWidth        - ҳ���ȡ�
    //  Return Value:
    //      Null
    //  Remarks:
    //      ����ҳ���ȣ����ݸÿ���Ű�ɲ��޸ߣ�����󷵻���ʵ�Ű�߶ȡ�
    //      ���������ÿ�ȣ�Ҳ�����ø߶�ʱ���տ�߾���������
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetPageWidth(DK_DOUBLE pageWidth) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����Ҫ������ʱ��������ҳ��߶ȡ�
    //  Parameters:
    //      [in] pageHeight        - ҳ��߶ȡ�
    //  Return Value:
    //      Null
    //  Remarks:
    //      ����ҳ��߶ȣ����ݸø߶��Ű�ɲ��޿�����󷵻���ʵ�Ű��ȣ�����ʹ�����ģʽ
    //      ���������ÿ�ȣ�Ҳ�����ø߶�ʱ���տ�߾���������
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetPageHeight(DK_DOUBLE pageHeight) = 0;

public:
    //-------------------------------------------
    //  Summary:
    //      ��ҳ������Ű棬����ҳ����󣬷���ҳ����ʵ�߶�
    //  Parameters:
    //      Null
    //  Return Value:
    //      Null
    //  Remarks:
    //      �����������ֺź��Ű��Ⱥ���ܽ����Ű�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID CalcPageLayout() = 0;

    //-------------------------------------------
    //  Summary:
    //      �����ǰ���Ű���
    //  Parameters:
    //      Null
    //  Return Value:
    //      Null
    //  Remarks:
    //      ����Ű�������Ҫ�����Ű���ܽ���ҳ�����Ⱦ��ʰȡ�Ȳ���
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID ClearLayoutResult() = 0;

    //-------------------------------------------
    //  Summary:
    //      ����������ҳ�Ŀ�ߣ��ڼ䲻����ҳ��Ԫ��
    //  Parameters:
    //      Null
    //  Return Value:
    //      Null
    //  Remarks:
    //      �����������ֺź��Ű��Ⱥ���ܽ��в���, 
    //      ͨ��GetLayoutWidth��GetLayoutHeight��ȡ�������
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID MeasurePageSize() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ���Ű��Ŀ��
    //  Parameters:
    //      Null
    //  Return Value:
    //      ҳ���Ű��Ŀ��
    //  Remarks:
    //      �ڲ�����ʱ����Ҫ�ڵ���CalcPageLayout���֪��ҳ��Ŀ��
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_DOUBLE GetLayoutWidth() = 0;
    
    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ���Ű��ĸ߶�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ҳ���Ű��ĸ߶�
    //  Remarks:
    //      �ڲ�����ʱ����Ҫ�ڵ���CalcPageLayout���֪��ҳ��ĸ߶�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_DOUBLE GetLayoutHeight() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ҳ�������Ⱦ
    //  Parameters:
    //      [in] option             - ����ѡ�
    //      [out] pResult           - ���ƽ����
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ������CalcPageLayout����֮����ܽ�����Ⱦ
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode Render(const DK_FLOWRENDEROPTION& option, DK_FLOWRENDERRESULT *pResult) = 0 ;

    //-------------------------------------------
    //  Summary:
    //      ��ҳ����оֲ���Ⱦ
    //  Parameters:
    //      [in] option             - ����ѡ�
    //      [in] areaBox            - ���Ƶľֲ�����
    //      [out] pResult           - ���ƽ����
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ������CalcPageLayout����֮����ܽ�����Ⱦ
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode RenderArea(const DK_FLOWRENDEROPTION& option, const DK_BOX& areaBox, DK_FLOWRENDERRESULT *pResult) = 0 ;

public:
    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ���ı����ݡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ����ҳ���ı����ݣ����ʧ���򷵻� DK_NULL��
    //  Remarks:
    //      ���ص��ı�����ָ����ʹ����Ϻ������� FreeTextContent �ӿ��ͷš�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_WCHAR* GetTextContent() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ��ı����ݡ�
    //  Parameters:
    //      [in] content            - �ı�����ָ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeTextContent(DK_WCHAR* pText) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ��ָ����Χ�ڵ��ı���Ӿ��Ρ�
    //  Parameters:
    //      [in] startPos           - ��ʼ����λ��
    //      [in] endPos             - ��������λ��
    //      [out] textRects         - �����ı���Ӿ�������
    //      [out] rectCount         - �ı���Ӿ�������ĳ���
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ��ȡ����λ�� [startPos, endPos) �����ڵ��ı���Ӿ������飬ʹ�����֮�������� FreeRects �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetTextRects(const DK_FLOWPOSITION& startPos, const DK_FLOWPOSITION& endPos, DK_BOX** ppTextRects, DK_UINT* pRectCount) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷž�������
    //  Parameters:
    //      [in] rects            - ���ͷŵľ�������
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeRects(DK_BOX* pRects) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��������㷵�ض�Ӧ��ҳ���е�������Ϣ
    //  Parameters:
    //      [in] point              - ���������
    //      [out] pLinkInfo         - ������Ӧ��ҳ��������Ϣ
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ��ȡ����λ��ҳ�� point ����λ�õ����ϲ�ҳ���������Ϣ��ʹ�����֮�������� FreeHitTestLink �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode HitTestLink(const DK_POS& point, DKE_LINK_INFO* pLinkInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ�ҳ��������Ϣ��
    //  Parameters:
    //      [in] pLinkInfo            - ���ͷŵ�ҳ��������Ϣ
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeHitTestLink(DKE_LINK_INFO* pLinkInfo) = 0;
};

//===========================================================================

#endif //__KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEFLEXPAGE_H__
