//===========================================================================
//  Summary:
//      ePubͼ�黭�ȶ���
//  Usage:
//      ͨ��ҳ��ʰȡ�߼���ȡ��ǰ���ȶ���Ȼ��ͨ���û��ȶ����������
//  Remarks:
//      Null
//  Date:
//      2013-03-22
// Author:
//      Zhang Jiafang (zhangjf@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEGALLERY_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEGALLERY_H__

#include "DKEDef.h"

class IDKEFootnoteIterator;
class IDKEHitableObjIterator;
class IDKEImageIterator;

class IDKEGallery
{
public:
    virtual ~IDKEGallery() {}

public:
    //-------------------------------------------
    //  Summary:
    //      ��ȡ���ȵ���ʼλ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��ʼλ��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_FLOWPOSITION GetBeginPosition() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ���ȵĽ���λ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ����λ��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_FLOWPOSITION GetEndPosition() const = 0;

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
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetBoundary() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ����ͼ���ڵ�ǰҳ�����Ӿ��Ρ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��Ӿ���
    //  Remarks:
    //      ��ҳ�����Ͻ�Ϊԭ�㡣
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetImageBoundary() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ����ͼ���ڵ�ǰ���������ڵ���Ӿ��Ρ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��Ӿ���
    //  Remarks:
    //      �Ի����������Ͻ�Ϊԭ�㡣
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetImageBoundaryInGallery() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ���ȵ�һ�����ֵı����ڵ�ǰҳ�����Ӿ��Ρ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��Ӿ���
    //  Remarks:
    //      ��ҳ�����Ͻ�Ϊԭ�㡣������titleCount==0ʱ��Ч��titleCount>=1ʱ��Ч
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetFirstTitleBoundary() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ���ȵ�һ�����ֵı����ڵ�ǰ���������ڵ���Ӿ��Ρ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��Ӿ���
    //  Remarks:
    //      �Ի����������Ͻ�Ϊԭ�㡣������titleCount==0ʱ��Ч��titleCount>=1ʱ��Ч
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetFirstTitleBoundaryInGallery() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ���ȵڶ������ֵı����ڵ�ǰҳ�����Ӿ��Ρ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��Ӿ���
    //  Remarks:
    //      ��ҳ�����Ͻ�Ϊԭ�㡣������titleCount<=1ʱ��Ч��titleCount==2ʱ��Ч
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetSecondTitleBoundary() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ���ȵڶ������ֵı����ڵ�ǰ���������ڵ���Ӿ��Ρ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��Ӿ���
    //  Remarks:
    //      �Ի����������Ͻ�Ϊԭ�㡣������titleCount<=1ʱ��Ч��titleCount==2ʱ��Ч
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetSecondTitleBoundaryInGallery() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�������ӵ�Ԫ�ĸ���
    //  Parameters:
    //      Null
    //  Return Value:
    //      �ֵ�Ԫ�ĸ���
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_INT GetCellCount() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ���ȱ���ĸ���������������͸�����
    //  Parameters:
    //      Null
    //  Return Value:
    //      �ֵ�Ԫ�ĸ���
    //  Remarks:
    //      ���ȱ���ĸ������Ϊ2��СΪ0
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_INT GetTitleCount() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ���õ�ǰ������Ļ����ӵ�Ԫ
    //  Parameters:
    //      [in] cellIndex          - �����ӵ�Ԫ����ţ� ��0��ʼ
    //  Return Value:
    //      Null
    //  Remarks:
    //      ������ǰĬ�ϱ�����ĵ�ԪΪ0�ţ�ÿ�л�һ����Ԫ�����������õ�ǰ������ĵ�Ԫ
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetCurActiveCell(DK_INT cellIndex) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��ǰ����Ļ��ȵ�Ԫ�����
    //  Parameters:
    //      Null
    //  Return Value:
    //      ���ȵ�Ԫ����ţ���0��ʼ
    //  Remarks:
    //      ������-1,��ʧ��
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_INT GetCurActiveCell() const = 0;

    //-------------------------------------------
    //  Summary:
    //      �ڴ����λͼ����Ⱦָ���Ļ��ȵ�Ԫ
    //  Parameters:
    //      [in] cellIndex          - �����ӵ�Ԫ����ţ� ��0��ʼ
    //      [in] option             - ��Ⱦѡ��
    //  Return Value:
    //      ����ɹ��򷵻�DKR_OK; ����ʧ��
    //  Remarks:
    //      �Ի��ȵ����ϵ�Ϊԭ�㿪ʼ��Ⱦ
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode RenderCell(DK_INT cellIndex, const DK_FLOWRENDEROPTION& option) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ڴ����λͼ����Ⱦָ���Ļ��ȵ�Ԫ��ͼƬ
    //  Parameters:
    //      [in] cellIndex          - �����ӵ�Ԫ����ţ� ��0��ʼ
    //      [in] option             - ��Ⱦѡ��
    //  Return Value:
    //      ����ɹ��򷵻�DKR_OK; ����ʧ��
    //  Remarks:
    //      ��ͼƬ�����ϵ�Ϊԭ�㿪ʼ��Ⱦ
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode RenderCellImage(DK_INT cellIndex, const DK_FLOWRENDEROPTION& option) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ڴ����λͼ����Ⱦָ���Ļ��ȵ�Ԫ�ĵ�һ�����ֵı���
    //  Parameters:
    //      [in] cellIndex          - �����ӵ�Ԫ����ţ� ��0��ʼ
    //      [in] option             - ��Ⱦѡ��
    //  Return Value:
    //      ����ɹ��򷵻�DKR_OK; ����ʧ��
    //  Remarks:
    //      �Ե�һ�����ֵı�������ϵ�Ϊԭ�㿪ʼ��Ⱦ����ҪtitleCount>=1����Ч
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode RenderCellFirstTitle(DK_INT cellIndex, const DK_FLOWRENDEROPTION& option) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ڴ����λͼ����Ⱦָ���Ļ��ȵ�Ԫ�ĵڶ������ֵı���
    //  Parameters:
    //      [in] cellIndex          - �����ӵ�Ԫ����ţ� ��0��ʼ
    //      [in] option             - ��Ⱦѡ��
    //  Return Value:
    //      ����ɹ��򷵻�DKR_OK; ����ʧ��
    //  Remarks:
    //      �Եڶ������ֵı�������ϵ�Ϊԭ�㿪ʼ��Ⱦ����ҪtitleCount==2����Ч
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode RenderCellSecondTitle(DK_INT cellIndex, const DK_FLOWRENDEROPTION& option) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡָ�����ȵ�Ԫ��ͼƬ��Ϣ
    //  Parameters:
    //      [in] cellIndex              - �����ӵ�Ԫ����ţ� ��0��ʼ
    //      [in] pImageInfo             - ͼƬ��Ϣ
    //  Return Value:
    //      ����ɹ��򷵻�DKR_OK; ����ʧ��
    //  Remarks:
    //      ����FreeCellImageInfo�ͷ���Դ
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetCellImageInfo(DK_INT cellIndex, DKE_HITTEST_OBJECTINFO* pImageInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ�ָ�����ȵ�Ԫ��ͼƬ��Ϣ
    //  Parameters:
    //      [in] pImageInfo             - ͼƬ��Ϣ
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeCellImageInfo(DKE_HITTEST_OBJECTINFO* pImageInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ���ȵ�ǰ���Ԫ��ָ����Χ�ڵ�����Ԫ�ص���Ӿ��Ρ�
    //  Parameters:
    //      [in] startPos           - ��ʼ����λ��
    //      [in] endPos             - ��������λ��
    //      [out] ppRects           - ��������Ԫ����Ӿ�������
    //      [out] pCount            - ����Ԫ����Ӿ�������ĳ���
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ��ȡ����λ�� [startPos, endPos) �����ڵ�����Ԫ����Ӿ������飬ʹ�����֮�������� FreeRects �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetInlineEleRects(const DK_FLOWPOSITION& startPos, const DK_FLOWPOSITION& endPos, DK_BOX** ppRects, DK_UINT* pCount) = 0;

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
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeRects(DK_BOX* pRects) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ָ����ѡ��ģʽ�»�ȡ���ȵ�ǰ���Ԫ��ָ�����㷶Χ�ڵ�ѡ���������ꡣ
    //  Parameters:
    //      [in] startPoint         - ��ʼ����㣬��ҳ�����ϵ�Ϊԭ��
    //      [in] endPoint           - ��������㣬��ҳ�����ϵ�Ϊԭ��
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
    virtual DK_ReturnCode GetSelectionRangeByMode(const DK_POS& startPoint, const DK_POS& endPoint, DKE_SELECTION_MODE selectionMode, DK_FLOWPOSITION* pStartPos, DK_FLOWPOSITION* pEndPos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ���������ͻ���ģʽ���ص��ڻ��ȵ�ǰ���Ԫ�ڲ�����������
    //  Parameters:
    //      [in] point              - ��������꣬��ҳ�����ϵ�Ϊԭ��
    //      [in] hitTestTextMode    - �Ժ���ģʽ�������֣�������ģʽ���ִ�ģʽ��
    //      [out] startPos          - ��ʼ��ʽ����λ��
    //      [out] endPos            - ������ʽ����λ��
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      null
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode HitTestTextRangeByMode(const DK_POS& point, DKE_HITTEST_TEXT_MODE hitTestTextMode, DK_FLOWPOSITION* pStartPos, DK_FLOWPOSITION* pEndPos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��������㷵�غ����ݵ�չʾ��ʽ���ػ��ȵ�ǰ���Ԫ�ڲ���ע��Ϣ
    //  Parameters:
    //      [in] point              - ��������꣬��ҳ�����ϵ�Ϊԭ��
    //      [out] pFootnoteInfo     - ������Ӧ��ҳ���ע
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ʹ�����֮�������� FreeHitTestFootnote �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode HitTestFootnote(const DK_POS& point, DKE_FOOTNOTE_INFO* pFootnoteInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷŽ�ע��Ϣ
    //  Parameters:
    //      [in] pFootnoteInfo     - ҳ���ע��Ϣ
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeHitTestFootnote(DKE_FOOTNOTE_INFO* pFootnoteInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ���ȵ�ǰ���Ԫ�ڲ���ע�ĵ������ӿڡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��ע�������ӿ�ָ�롣
    //  Remarks:
    //      ʹ�����֮����� FreeFootnoteIterator �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEFootnoteIterator* GetFootnoteIterator() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷŻ����ڲ���ע��������
    //  Parameters:
    //      [in] pFootnoteIterator   - ҳ���ע������
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeFootnoteIterator(IDKEFootnoteIterator* pFootnoteIterator) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��������㷵�ض�Ӧ�Ļ��ȵ�ǰ���Ԫ�е�������Ϣ
    //  Parameters:
    //      [in] point              - ��������꣬�����ҳ�����Ͻ�
    //      [out] pLinkInfo         - ������Ӧ��ҳ��������Ϣ
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ʹ�����֮�������� FreeHitTestLink �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
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
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeHitTestLink(DKE_LINK_INFO* pLinkInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ���ȵ�ǰ���Ԫ�ڲ����пɵ������ĵ�����
    //  Parameters:
    //      Null
    //  Return Value:
    //      �ɵ������ĵ�����
    //  Remarks:
    //      ����FreeHitableObjIterator�ͷ���Դ
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEHitableObjIterator* GetHitableObjIterator() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷŻ����ڲ����пɵ������ĵ�����
    //  Parameters:
    //      [in] pHitableObjIterator        - �ɵ������ĵ�����
    //  Return Value:
    //      Null
    //  Remarks:
    //      ����FreeHitableObjIterator�ͷ���Դ
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeHitableObjIterator(IDKEHitableObjIterator* pHitableObjIterator) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�������е�Ԫ�Ŀɽ���ͼƬ����һ����ö����
    //  Parameters:
    //      Null
    //  Return Value:
    //      ͼƬö����
    //  Remarks:
    //      ����FreeAllCellImageIterator�ͷ���Դ
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEImageIterator* GetAllCellImageIterator() = 0;
    
    //-------------------------------------------
    //  Summary:
    //      �ͷŻ������е�Ԫ�Ŀɽ���ͼƬ����һ����ö����
    //  Parameters:
    //      [in] pImageIterator         - ͼƬö����
    //  Return Value:
    //      ͼƬö����
    //  Remarks:
    //      null
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeAllCellImageIterator(IDKEImageIterator* pImageIterator) = 0;

};

#endif // __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEGALLERY_H__

