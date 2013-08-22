//===========================================================================
// Summary:
//      IDKPPageEx.h
//      ���� PDF ����ҳ�����ݻ�ȡ����Ⱦ
// Usage:
//      Null
// Remarks:
//      Null
// Date:
//      2012-01-10
// Author:
//      Liu Hongjia(liuhj@duokan.com)
//===========================================================================

#ifndef __KERNEL_PDFKIT_PDFLIB_IDKPPAGEEX_H__
#define __KERNEL_PDFKIT_PDFLIB_IDKPPAGEEX_H__

#include "DKPRetCode.h"
#include "DKPTypeDef.h"

class IDKPTextIterator;

class IDKPPageEx
{
public:
    virtual ~IDKPPageEx() {}

public:    
    enum {REARRANGE_DEFAULT_INDENT = 50};   // ����Ч��Ĭ�������Ĺ̶�ֵ
    enum {MAX_INVOLVED_PAGES = 15};         // ƴ������ҳʱ���ʹ�õ�ԭʼҳ���� 
    enum {MAX_SUM_OF_RGB = 500};            // �ı���ɫ RGB ��ɫ֮�ʹ��ڸ�ֵʱ��ǿ����Ϊ��ɫ    

    //-------------------------------------------
    //  Summary:
    //      ��Ⱦҳ�����ݡ�
    //  Parameters:
    //      [in] option             - ����ѡ�
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      Null
    //  Availability:
    //      �� PDFLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode RenderPage (const DK_FLOWRENDEROPTION& option) = 0;
    
    //-------------------------------------------
    //  Summary:
    //      ��������ҳ����ʼλ�á�
    //  Parameters:
    //      [in] pos - ����ҳ���һ��Ԫ�ض�Ӧ��ԭ�ĵ�λ�á�
    //  Return Value:
    //  Remarks:
    //      Null
    //  Availability:
    //      �� PDFLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetPageStartPos (const DK_FLOWPOSITION& pos) = 0;
    
    //-------------------------------------------
    //  Summary:
    //      ��������ҳ�����λ�á�
    //  Parameters:
    //      [in] pos - ��Ӧ����ҳ������޷���ʾ�ĵ�һ��Ԫ�أ�����Ϊ��һ������ҳ����ʼλ�á�
    //  Return Value:
    //  Remarks:
    //      Null
    //  Availability:
    //      �� PDFLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetPageEndPos (const DK_FLOWPOSITION& pos) = 0;
    
    //-------------------------------------------
    //  Summary:
    //      �������ҳ����ʼλ�á�
    //  Parameters:
    //      [out] pPos - ����ҳ���һ��Ԫ�ض�Ӧ��ԭ�ĵ�λ�á�
    //  Return Value:
    //      ��ȡ�ɹ��򷵻� DK_TRUE�����򷵻� DK_FALSE��
    //  Remarks:
    //      Null
    //  Availability:
    //      �� PDFLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL GetPageStartPos (DK_FLOWPOSITION* pPos) = 0;
    
    //-------------------------------------------
    //  Summary:
    //      �������ҳ�����λ�á�
    //  Parameters:
    //      [out] pPos - ��Ӧ����ҳ������޷���ʾ�ĵ�һ��Ԫ�أ�����Ϊ��һ������ҳ����ʼλ�á�
    //  Return Value:
    //      ��ȡ�ɹ��򷵻� DK_TRUE�����򷵻� DK_FALSE��
    //  Remarks:
    //      Null
    //  Availability:
    //      �� PDFLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL GetPageEndPos (DK_FLOWPOSITION* pPos) = 0;

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
    //      �� PDFLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_WCHAR* GetTextContent() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ��ָ����Χ�ڵ��ı����ݡ�
    //  Parameters:
    //      [in] startPos           - ��ʼ����λ��
    //      [in] endPos             - ��������λ��
    //  Return Value:
    //      ����λ�� [startPos, endPos) �����ڵ�ҳ���ı����ݡ�
    //  Remarks:
    //      ���ص��ı�����ָ����ʹ����Ϻ�������FreeTextContent�ӿ��ͷš�
    //  Availability:
    //      �� PDFLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_WCHAR* GetTextContentOfRange(const DK_FLOWPOSITION& startPos, const DK_FLOWPOSITION& endPos) = 0;
    
    //-------------------------------------------
    //  Summary:
    //      �ͷ��ı����ݡ�
    //  Parameters:
    //      [in] pContent            - �ı�����ָ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      �� PDFLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeTextContent(DK_WCHAR* pContent) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ��ָ����Χ�ڵ��ı���Ӿ��Ρ�
    //  Parameters:
    //      [in] startPos           - ��ʼ����λ��
    //      [in] endPos             - ��������λ��
    //      [out] ppTextRects       - �����ı���Ӿ�������
    //      [out] pRectCount        - �ı���Ӿ�������ĳ���
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ��ȡ����λ�� [startPos, endPos) �����ڵ��ı���Ӿ������飬ʹ�����֮�������� FreeRects �ӿ��ͷš�
    //  Availability: 
    //      �� PDFLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetTextRects(const DK_FLOWPOSITION& startPos, const DK_FLOWPOSITION& endPos, DK_BOX** ppTextRects, DK_UINT* pRectCount) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷž�������
    //  Parameters:
    //      [in] pRects            - ���ͷŵľ�������
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      �� PDFLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeRects(DK_BOX* pRects) = 0;
    
    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ�����ֶ���ĵ������ӿڡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ���ֶ���������ӿ�ָ�롣
    //  Remarks:
    //      ʹ�����֮����� FreeTextIterator �ӿ��ͷš�
    //  Availability: 
    //      �� PDFLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKPTextIterator* GetTextIterator() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ����ֶ����������
    //  Parameters:
    //      [in] pDKPTextIterator       - ���ֶ��������
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      �� PDFLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeTextIterator(IDKPTextIterator* pDKPTextIterator) = 0;
    
    //-------------------------------------------
    //  Summary:
    //      ��������㷵�ء�
    //  Parameters:
    //      [in] point               - ���������
    //      [out] pStartPos          - ��ʼ��ʽ����λ��
    //      [out] pEndPos            - ������ʽ����λ��
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      Null
    //  Availability:
    //      �� PDFLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode HitTestTextRange(const DK_POS& point, DK_FLOWPOSITION* pStartPos, DK_FLOWPOSITION* pEndPos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��������㷵�ء�
    //  Parameters:
    //      [in] point               - ���������
    //      [in] hitTestTextMode        - �Ժ���ģʽ�������֣�������ģʽ���ִ�ģʽ��
    //      [out] pStartPos          - ��ʼ��ʽ����λ��
    //      [out] pEndPos            - ������ʽ����λ��
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      Null
    //  Availability:
    //      �� PDFLib 2.2.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode HitTestTextRangeByMode(const DK_POS& point, DKP_HITTEST_TEXT_MODE hitTestTextMode, DK_FLOWPOSITION* pStartPos, DK_FLOWPOSITION* pEndPos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ָ����ѡ��ģʽ�»�ȡҳ��ָ�����㷶Χ�ڵ�ѡ���������ꡣ
    //  Parameters:
    //      [in] startPoint             - ��ʼѡ�е������
    //      [in] endPoint               - ����ѡ�е������
    //      [in] selectionMode          - ѡ��ģʽ������Խ������ѡ�л򽻲漴ѡ��
    //      [out] pStartPos             - ��ʼ������Ӧ������ʽ����
    //      [out] pEndPos               - ����������Ӧ������ʽ����
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��PDFLib 2.1.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetSelectionRangeByMode(const DK_POS& startPoint, 
                                                const DK_POS& endPoint, 
                                                DKP_SELECTION_MODE selectionMode, 
                                                DK_FLOWPOSITION* pStartPos, 
                                                DK_FLOWPOSITION* pEndPos) = 0;
};

#endif // #ifndef __KERNEL_PDFKIT_PDFLIB_IDKPPAGEEX_H__
