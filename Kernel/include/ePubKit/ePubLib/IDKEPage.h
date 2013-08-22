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
//      2011-09-16
// Author:
//      Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEPAGE_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEPAGE_H__

//===========================================================================

#include "DKEDef.h"
#include "IDKETextIterator.h"
#include "IDKEFootnoteIterator.h"
#include "IDKEImageIterator.h"
#include "IDKEMediaIterator.h"
#include "IDKEComicsFrameIterator.h"
#include "IDKEGallery.h"
#include "IDKEGalleryIterator.h"
#include "IDKEHitableObjIterator.h"
#include "IDKEPreBlockIterator.h"
#include "IDKEImgBlockIterator.h"
#include "IDKEPageUnit.h"

//===========================================================================
class IDKEPage
{
public:
    //-------------------------------------------
    //  Summary:
    //      ��Ⱦҳ�����ݡ�
    //  Parameters:
    //      [in] option             - ����ѡ�
    //      [out] pResult           - ���ƽ����
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode Render(const DK_FLOWRENDEROPTION& option, DK_FLOWRENDERRESULT *pResult) = 0;


    //-------------------------------------------
    //  Summary:
    //      �ֲ���Ⱦ�ӿڡ�
    //      �ȵ���BuildPageElements����ҳ�����
    //      �ٵ���FastRenderֱ�ӻ���ҳ�����
    //  Parameters:
    //      [in] option             - ����ѡ�
    //      [out] pResult           - ���ƽ����
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.1.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode FastRender(const DK_FLOWRENDEROPTION& option, DK_FLOWRENDERRESULT *pResult) = 0;
    virtual DK_ReturnCode BuildPageElements() = 0;

    //-------------------------------------------
    //  Summary:
    //      ���ҳ���Ƿ��Ѵ���ҳ��Ԫ��
    //  Parameters:
    //      �ޡ�
    //  Return Value:
    //      DK_TRUE�Ѵ���ҳ��Ԫ�أ�DK_FALSE������
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOOL CheckPageElements() = 0;

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
    //      ��ePubLib 1.0��ʼ֧�֡�
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
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreePageCache() = 0;

    //-------------------------------------------
    //  Summary:
    //      ����ҳ���ĳ��Ԫ�ز��ɼ�
    //  Parameters:
    //      [in]pageObjType     - ҳ��Ԫ������
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetInvisible(DKE_PAGEOBJ_TYPE pageObjType) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ���Ű��Ŀ��
    //  Parameters:
    //      Null
    //  Return Value:
    //      ҳ���Ű��Ŀ��
    //  Remarks:
    //      ��BuildPageElements֮�����
    //  Availability:
    //      ��ePubLib 2.2.1 ��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_DOUBLE GetLayoutWidth() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ���Ű��߶�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��ҳ���Ű�֮�����
    //  Remarks:
    //      ��BuildPageElements֮�����
    //  Availability:
    //      ��ePubLib 2.2.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_DOUBLE GetLayoutHeight() = 0;

public:
    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ����ֹ����λ�á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ����ҳ���һ��Ԫ�ص���ʽ���ꡣ
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_FLOWPOSITION GetBeginPosition() = 0;

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
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_FLOWPOSITION GetEndPosition() = 0;

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
    //      ��ePubLib 1.0��ʼ֧�֡�
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
    //      ��startPos��endPos������һҳ�ı߽��������õ�ҳ����������ĵ㡣
    //      ���ص��ı�����ָ����ʹ����Ϻ�������FreeTextContent�ӿ��ͷš�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_WCHAR* GetTextContentOfRange(const DK_FLOWPOSITION& startPos, const DK_FLOWPOSITION& endPos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ��ָ����Χ�ڵ�HTML���ı����ݡ�
    //  Parameters:
    //      [in] startPos           - ��ʼ����λ��
    //      [in] endPos             - ��������λ��
    //  Return Value:
    //      ����λ�� [startPos, endPos) �����ڵ�ҳ��HTML���ı����ݡ�
    //  Remarks:
    //      ��startPos��endPos������һҳ�ı߽��������õ�ҳ����������ĵ㡣
    //      ���ص��ı�����ָ����ʹ����Ϻ�������FreeTextContent�ӿ��ͷš�
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_WCHAR* GetRichTextContentOfRange(const DK_FLOWPOSITION& startPos, const DK_FLOWPOSITION& endPos) = 0;

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
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeTextContent(DK_WCHAR* pContent) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ��ָ����Χ�ڵ��ı����ݣ������Χ�ڳ�������Ԫ��(������ͼƬ�ȵ�)�����¼alt��Ϣ��
    //  Parameters:
    //      [in] startPos                      - ��ʼ����λ��
    //      [in] endPos                        - ��������λ��
    //      [out] pTextContentInfo             - �ı����ݣ���������Ԫ����Ϣ��
    //  Return Value:
    //      DK_ReturnCode
    //  Remarks:
    //      ��startPos��endPos������һҳ�ı߽��������õ�ҳ����������ĵ㡣
    //      ���ص��ı�����ָ����ʹ����Ϻ�������FreeTextContentEx�ӿ��ͷš�
    //  Availability:
    //      ��ePubLib 2.2.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetTextContentOfRangeEx(const DK_FLOWPOSITION& startPos, const DK_FLOWPOSITION& endPos, DKE_TEXT_CONTENT_INFO* pTextContentInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ��ı����ݣ���������Ԫ����Ϣ����
    //  Parameters:
    //      [in] pTextContentInfo            - �ı�����ָ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.2.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeTextContentEx(DKE_TEXT_CONTENT_INFO* pTextContentInfo) = 0;

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
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetTextRects(const DK_FLOWPOSITION& startPos, const DK_FLOWPOSITION& endPos, DK_BOX** ppTextRects, DK_UINT* pRectCount) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ��ָ����Χ�ڵ�����Ԫ�ص���Ӿ��Ρ�
    //  Parameters:
    //      [in] startPos           - ��ʼ����λ��
    //      [in] endPos             - ��������λ��
    //      [out] ppInlineEleRects  - ��������Ԫ����Ӿ�������
    //      [out] rectCount         - ����Ԫ����Ӿ�������ĳ���
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ��ȡ����λ�� [startPos, endPos) �����ڵ�����Ԫ����Ӿ������飬ʹ�����֮�������� FreeRects �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.2.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetInlineEleRects(const DK_FLOWPOSITION& startPos, const DK_FLOWPOSITION& endPos, DK_BOX** ppInlineEleRects, DK_UINT* pRectCount) = 0;

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
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeRects(DK_BOX* pRects) = 0;

public:
    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ��ָ�����㷶Χ�ڵ�ѡ���������ꡣѡ��ģʽΪ����Խ�����־������߼�ѡ��
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
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetSelectionRange(const DK_POS& startPoint, const DK_POS& endPoint, DK_FLOWPOSITION* pStartPos, DK_FLOWPOSITION* pEndPos) = 0;

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
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetSelectionRangeByMode(const DK_POS& startPoint, const DK_POS& endPoint, DKE_SELECTION_MODE selectionMode, DK_FLOWPOSITION* pStartPos, DK_FLOWPOSITION* pEndPos) = 0;

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
    //      ��ePubLib 1.0��ʼ֧�֡�
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
    //      ��ePubLib 1.0��ʼ֧�֡�
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
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode HitTestTextRange(const DK_POS& point, DK_FLOWPOSITION* pStartPos, DK_FLOWPOSITION* pEndPos) = 0;

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
    virtual DK_ReturnCode HitTestTextRangeByMode(const DK_POS& point, DKE_HITTEST_TEXT_MODE hitTestTextMode, DK_FLOWPOSITION* pStartPos, DK_FLOWPOSITION* pEndPos) = 0;

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
    //      ��ePubLib 1.0��ʼ֧�֡�
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
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeHitTestLink(DKE_LINK_INFO* pLinkInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��������㷵�غ����ݵ�չʾ��ʽ���ؽ�ע��Ϣ
    //  Parameters:
    //      [in] point              - ���������
    //      [out] pFootnoteInfo     - ������Ӧ��ҳ���ע
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ��ȡ����λ��ҳ�� point ����λ�õ����ϲ�ҳ��Ľ�ע��Ϣ��ʹ�����֮�������� FreeHitTestFootnote �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.3.0��ʼ֧�֡�
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
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeHitTestFootnote(DKE_FOOTNOTE_INFO* pFootnoteInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����footnoteָ���ID������չʾ���ͻ�ȡչʾ���ݾ��
    //  Parameters:
    //      [in] pNoteId            - ��עID
    //      [in] showType           - ����չʾ������
    //      [out] pHandle           - ����չʾ���
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ʹ�����֮�������� FreeContentHandle �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetFootnoteContentHandle(const DK_WCHAR* pNoteId, DKE_SHOWCONTENT_TYPE showType, DKE_SHOWCONTENT_HANDLE* pHandle) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ�����չʾ���
    //  Parameters:
    //      [in] showType           - չʾ���ݵ�����
    //      [in] pContentHandle     - ��Ҫ�ͷŵľ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeContentHandle(DKE_SHOWCONTENT_TYPE showType, DKE_SHOWCONTENT_HANDLE* pHandle) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��������㷵�ػ�����Ϣ
    //  Parameters:
    //      [in] point              - ���������
    //      [out] ppGallery         - ������Ӧ�Ļ���
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ��ȡ����λ��ҳ�� point ����λ�õ����ϲ�ҳ��Ľ�ע��Ϣ��ʹ�����֮�������� FreeHitTestGallery �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode HitTestGallery(const DK_POS& point, IDKEGallery** ppGallery) = 0;
    
    //-------------------------------------------
    //  Summary:
    //      �ͷ�ʰȡ�Ļ�����Ϣ
    //  Parameters:
    //      [in] pGallery           - Ҫ�ͷŵĻ���
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeHitTestGallery(IDKEGallery* pGallery) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��������㷵��PRE����Ϣ
    //  Parameters:
    //      [in] point              - ���������
    //      [out] pPreBlockInfo     - PRE�������Ϣ
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ��ȡ����λ��ҳ�� point ����λ�õ����ϲ�ҳ��Ľ�ע��Ϣ��ʹ�����֮�������� FreeHitTestPreBlock �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode HitTestPreBlock(const DK_POS& point, DKE_PREBLOCK_INFO* pPreBlockInfo) = 0;
    
    //-------------------------------------------
    //  Summary:
    //      �ͷ�ʰȡ��PRE����Ϣ
    //  Parameters:
    //      [in] pPreBlockInfo      - Ҫ�ͷŵ�pre����Ϣ
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeHitTestPreBlock(DKE_PREBLOCK_INFO* pPreBlockInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��������㷵���Զ���ͼƬ����Ϣ
    //  Parameters:
    //      [in] point              - ���������
    //      [out] pImgBlockInfo     - �Զ���ͼƬ�������Ϣ
    //  Return Value:
    //      ����ɹ����� DKR_OK��
    //  Remarks:
    //      ��ȡ����λ��ҳ�� point ����λ�õ����ϲ�ҳ��Ľ�ע��Ϣ��ʹ�����֮�������� FreeHitTestImgBlock �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode HitTestImgBlock(const DK_POS& point, DKE_IMAGEBLOCK_INFO* pImgBlockInfo) = 0;
    
    //-------------------------------------------
    //  Summary:
    //      �ͷ�ʰȡ���Զ���ͼƬ����Ϣ
    //  Parameters:
    //      [in] pImgBlockInfo      - Ҫ�ͷŵ��Զ���ͼƬ����Ϣ
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeHitTestImgBlock(DKE_IMAGEBLOCK_INFO* pImgBlockInfo) = 0;

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
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKETextIterator* GetTextIterator() = 0;

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
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeTextIterator(IDKETextIterator* pTextIterator) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ���ע�ĵ������ӿڡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ҳ���ע�������ӿ�ָ�롣
    //  Remarks:
    //      ������ Render ֮����ã�ʹ�����֮����� FreeFootnoteIterator �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEFootnoteIterator* GetFootnoteIterator() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ�ҳ���ע��������
    //  Parameters:
    //      [in] pFootnoteIterator   - ҳ���ע������
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeFootnoteIterator(IDKEFootnoteIterator* pFootnoteIterator) = 0;

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
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEImageIterator* GetImageIterator() = 0;

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
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeImageIterator(IDKEImageIterator* pImageIterator) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ������Ƶ�ĵ������ӿڡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ҳ����Ƶ�������ӿ�ָ�롣
    //  Remarks:
    //      ������ Render ֮����ã�ʹ�����֮����� FreeMediaIterator �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEMediaIterator* GetMediaIterator() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ�ҳ����Ƶ��������
    //  Parameters:
    //      [in] pMediaIterator   - ҳ����Ƶ������
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeMediaIterator(IDKEMediaIterator* pMediaIterator) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ�滭�ȵĵ������ӿڡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ҳ�滭�ȵ������ӿ�ָ�롣
    //  Remarks:
    //      ������ Render ֮����ã�ʹ�����֮����� FreeGalleryIterator �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEGalleryIterator* GetGalleryIterator() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ�ҳ�滭�ȵ�������
    //  Parameters:
    //      [in] pGalleryIterator   - ҳ�滭�ȵ�����
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeGalleryIterator(IDKEGalleryIterator* pGalleryIterator) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ��ɵ������ĵ������ӿڡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      �ɵ������������ӿ�ָ�롣
    //  Remarks:
    //      ������ Render ֮����ã�ʹ�����֮����� FreeHitableObjIterator �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEHitableObjIterator* GetHitableObjIterator() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ�ҳ��ɵ������ĵ������ӿڡ�
    //  Parameters:
    //      [in] pHitableObjIterator   - ҳ��ɵ�����������
    //  Return Value:
    //      Null
    //  Remarks:
    //      NULL
    //  Availability: 
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeHitableObjIterator(IDKEHitableObjIterator* pHitableObjIterator) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ��PRE�����ĵ������ӿڡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      PRE�����������ӿ�ָ�롣
    //  Remarks:
    //      ������ Render ֮����ã�ʹ�����֮����� FreePreBlockIterator �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEPreBlockIterator* GetPreBlockIterator() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ�ҳ��PRE�����ĵ������ӿڡ�
    //  Parameters:
    //      [in] pPreBlockIterator      - ҳ��PRE����������
    //  Return Value:
    //      Null
    //  Remarks:
    //      NULL
    //  Availability: 
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreePreBlockIterator(IDKEPreBlockIterator* pPreBlockIterator) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ���Զ���ͼƬ�����ĵ������ӿڡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      �Զ���ͼƬ�����������ӿ�ָ�롣
    //  Remarks:
    //      ������ Render ֮����ã�ʹ�����֮����� FreeImgBlockIterator �ӿ��ͷš�
    //  Availability: 
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEImgBlockIterator* GetImgBlockIterator() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ�ҳ���Զ���ͼƬ�����ĵ������ӿڡ�
    //  Parameters:
    //      [in] pImgBlockIterator      - ҳ��ҳ���Զ���ͼƬ����������
    //  Return Value:
    //      Null
    //  Remarks:
    //      NULL
    //  Availability: 
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeImgBlockIterator(IDKEImgBlockIterator* pImgBlockIterator) = 0;


//===========================================================================
//  ����ҳ����ؽӿ�
//===========================================================================
    //-------------------------------------------
    //  Summary:
    //      ��ȡ��ǰ����ҳ�ϵ�֡��
    //  Parameters:
    //      null
    //  Return Value:
    //      ֡��
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_LONG GetFrameCount() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡĳһ֡����Ӿ��Σ��þ��ε�����ϵ��ͼƬΪ����
    //  Parameters:
    //      [in] pageFrameIndex     - ҳ���ϵ�֡��
    //  Return Value:
    //      ֡����Ӿ���
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetFrameBoundary(DK_LONG pageFrameIndex) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡĳһ֡����Ӿ��Σ��þ��ε�����ϵ��ҳ��Ϊ����
    //  Parameters:
    //      [in] pageFrameIndex     - ҳ���ϵ�֡��
    //  Return Value:
    //      ֡����Ӿ���
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.4.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetFrameBoxOnPage(DK_LONG pageFrameIndex) = 0;

    //-------------------------------------------
    //  Summary:
    //      ͨ��ҳ���ϵ�֡�Ż�ȡ��֡��ȫ��֡��������ţ������㿪ʼ��
    //  Parameters:
    //      [in] pageFrameIndex     - ҳ���ϵ�֡��
    //  Return Value:
    //      ֡����Ӿ���
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_LONG GetGlobalFrameIndex(DK_LONG pageFrameIndex) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����ҳ���ϵ�ĳһ�㣨����ϵ����Ϊҳ�����Ͻǣ�ʰȡ�ĵ��Ӧ��֡��
    //  Parameters:
    //      [in] hitPoint       - ʰȡ��
    //      [out] pFrameIndex   - ֡��
    //  Return Value:
    //      ����ɹ��򷵻�DKR_OK
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode HitTestComicsFrame(DK_POS point, DK_LONG* pFrameIndex) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��ǰ����ҳ��֡��ö����
    //  Parameters:
    //      Null
    //  Return Value:
    //      ����ɹ��򷵻�DKR_OK
    //  Remarks:
    //      ����FreeComicsFrameIterator�ͷŷ���ֵ�ڴ�
    //  Availability: 
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEComicsFrameIterator* GetComicsFrameIterator() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷŵ�ǰ����ҳ��֡��ö����
    //  Parameters:
    //      Null
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeComicsFrameIterator(IDKEComicsFrameIterator* pFrameIterator) = 0;

//===========================================================================
//  ҳ�����������
//===========================================================================
    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ�����block
    //  Parameters:
    //      Null
    //  Return Value:
    //      ����block
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEPageBlock* GetPageBlockUnit() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ�ҳ�����block
    //  Parameters:
    //      [in] pPageBlockUnit       - ����block
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability: 
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreePageBlockUnit(IDKEPageBlock* pPageBlockUnit) = 0;

public:
    virtual ~IDKEPage() {};
};

//===========================================================================

#endif // #ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEPAGE_H__
