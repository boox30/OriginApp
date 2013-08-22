//===========================================================================
//  Summary:
//      ePubͼ��ҳ�����ࡣ
//  Usage:
//      ����ʹ��Restart��Ȼ��ѭ��check MoveNext
//      ʹ��Current��ȡ��ǰ����ֱ��MoveNext����ʧ��Ϊֹ
//      ���ҳ������ö�ٹ���
//  Remarks:
//      Null
//  Date:
//      2012-02-27
//  Author:
//      Zhai Guanghe (zhaigh@duokan.com)
//===========================================================================

#ifndef __KERNEL_MOBIKIT_MOBILIB_EXPORT_IDKMPAGE_H__
#define __KERNEL_MOBIKIT_MOBILIB_EXPORT_IDKMPAGE_H__

#include "DKMDef.h"

class IDKMTextIterator;
class IDKEImageIterator;

class IDKMPage
{
public:
    virtual ~IDKMPage() {}
public:
    virtual DK_ReturnCode Render(const DK_FLOWRENDEROPTION &option, DK_FLOWRENDERRESULT *pResult) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����ϴλ����Ƿ�ȱ�֡�
    //  Parameters:
    //      �ޡ�
    //  Return Value:
    //      �����Ƿ�ȱ�֡�
    //  Remarks:
    //      Null
    //  Availability:
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DKRS_RENDERSTATUS CheckRenderStatus() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ�ҳ����Ⱦ�󻺴�����ݡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      Null
    //  Remarks:
    //      ������ Render �ӿڵ���֮��ʹ�ã�������Ч��
    //  Availability:
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreePageCache() = 0;

public:
    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ����ʼ����λ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ����ҳ���һ��Ԫ�ص���ʽ���ꡣ
    //  Remarks:
    //      Null
    //  Availability:
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_UINT GetBeginPosition() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ���������λ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ����ҳ�����һ��Ԫ�ص���ʽ���ꡣ
    //  Remarks:
    //      Null
    //  Availability:
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_UINT GetEndPosition() = 0;

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
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetTextRects(DK_UINT startPos, DK_UINT endPos, DK_BOX** ppTextRects, DK_UINT* pRectCount) = 0;

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
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeRects(DK_BOX* pRects) = 0;

public:
    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ��ָ�����㷶Χ�ڵ�ѡ���������ꡣΪԽ�����߼�ѡ��
    //  Parameters:
    //      [in] startPoint         - ��ʼ�����
    //      [in] endPoint           - ���������
    //      [out] startPos          - ��ʼ��ʽ����λ��
    //      [out] endPos            - ������ʽ����λ��
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ������ Render ֮����á�
    //  Availability:
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetSelectionRange(const DK_POS& startPoint, const DK_POS& endPoint, DK_UINT *pStartPos, DK_UINT *pEndPos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ָ����ѡ��ģʽ�»�ȡҳ��ָ�����㷶Χ�ڵ�ѡ���������ꡣ
    //  Parameters:
    //      [in] startPoint         - ��ʼ�����
    //      [in] endPoint           - ���������
    //      [in] selectionMode      - ѡ��ģʽ������Խ������ѡ�л򽻲漴ѡ��
    //      [out] startPos          - ��ʼ��ʽ����λ��
    //      [out] endPos            - ������ʽ����λ��
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ������ Render ֮����á�
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetSelectionRangeByMode(const DK_POS& startPoint, const DK_POS& endPoint, DKE_SELECTION_MODE selectionMode, DK_UINT* pStartPos, DK_UINT* pEndPos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��������㷵�ض�Ӧ��ҳ�������Ϣ��
    //  Parameters:
    //      [in] point              - ���������
    //      [out] pObjInfo          - ������Ӧ��ҳ�������Ϣ
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ��ȡ����λ��ҳ�� point ����λ�õ����ϲ�ҳ�������Ϣ��ʹ�����֮�������� FreeHitTestObject �ӿ��ͷš�
    //  Availability: 
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode HitTestObject(const DK_POS& point, DKE_HITTEST_OBJECTINFO* pObjInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ�ҳ�������Ϣ��
    //  Parameters:
    //      [in] pObjInfo            - ���ͷŵ�ҳ�������Ϣ
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeHitTestObject(DKE_HITTEST_OBJECTINFO* pObjInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��������㷵�ء�
    //  Parameters:
    //      [in] point              - ���������
    //      [out] startPos          - ��ʼ��ʽ����λ��
    //      [out] endPos            - ������ʽ����λ��
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ������ Render ֮����á�
    //  Availability:
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode HitTestTextRange(const DK_POS& point, DK_UINT *pStartPos, DK_UINT *pEndPos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��������㷵�ء�
    //  Parameters:
    //      [in] point              - ���������
    //      [in] hitTestTextMode    - �Ժ���ģʽ�������֣�������ģʽ���ִ�ģʽ��
    //      [out] startPos          - ��ʼ��ʽ����λ��
    //      [out] endPos            - ������ʽ����λ��
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ������ Render ֮����á�
    //  Availability:
    //      ��ePubLib 2.1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode HitTestTextRangeByMode(const DK_POS& point, DKE_HITTEST_TEXT_MODE hitTestTextMode, DK_UINT* pStartPos, DK_UINT* pEndPos) = 0;

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
    //      ��MobiLib 1.0.8��ʼ֧�֡�
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
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeHitTestLink(DKE_LINK_INFO* pLinkInfo) = 0;

public:
    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ�����ֶ���ĵ������ӿڡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ���ֶ���������ӿ�ָ�롣
    //  Remarks:
    //      ������ Render ֮����ã�ʹ�����֮����� FreeTextIterator �ӿ��ͷš�
    //  Availability: 
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKMTextIterator * GetTextIterator() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ����ֶ����������
    //  Parameters:
    //      [in] textIterator       - ���ֶ��������
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeTextIterator(IDKMTextIterator *pTextIterator) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ��ͼƬ�ĵ������ӿڡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ҳ��ͼƬ�������ӿ�ָ�롣
    //  Remarks:
    //      ������ Render ֮����ã�ʹ�����֮����� FreeImageIterator �ӿ��ͷš�
    //  Availability: 
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEImageIterator * GetImageIterator() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ�ҳ��ͼƬ��������
    //  Parameters:
    //      [in] pImageIterator   - ҳ��ͼƬ������
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeImageIterator(IDKEImageIterator *pImageIterator) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ж�page�Ƿ�Ϊ��һҳ
    //  Parameters:
    //      None
    //  Return Value:
    //      True if is first page, false otherwise
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL IsFirstPage() const = 0;

    //-------------------------------------------
    //  Summary:
    //      �ж�page�Ƿ�Ϊ���һҳ
    //  Parameters:
    //      None
    //  Return Value:
    //      True if is last page, false otherwise
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��MobiLib 1.0.8��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL IsLastPage() const = 0;
};

//===========================================================================

#endif // __KERNEL_MOBIKIT_MOBILIB_EXPORT_IDKMPAGE_H__
