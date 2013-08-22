//===========================================================================
//  Summary:
//      ePubͼ������ࡣ
//  Usage:
//      Null
//  Remarks:
//      Null
//  Date:
//      2011-09-16
//  Author:
//      Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEBOOK_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEBOOK_H__

//===========================================================================

#include "DKEDef.h"

//===========================================================================

class IDKEPage;
class IDKETocPoint;
class IDKEComicsFrame;

//===========================================================================

class IDKEBook
{
public:
    //-------------------------------------------
    //  Summary:
    //      ���������ֺŴ�С��
    //  Parameters:
    //      [in] fontSize        - Ĭ���ֺŴ�С��
    //  Return Value:
    //      Null
    //  Remarks:
    //      �����ֺ�ֻ��һ���ο�ֵ����Ӱ�����кʹ˲ο�ֵ��ص��ֺţ�����������֡�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetBodyFontSize(DK_DOUBLE fontSize) = 0;

    //-------------------------------------------
    //  Summary:
    //      �����м�ࡣ
    //  Parameters:
    //      [in] lineGap        - �м�౶����
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetLineGap(DK_DOUBLE lineGap) = 0;

    //-------------------------------------------
    //  Summary:
    //      ���öμ�ࡣ
    //  Parameters:
    //      [in] paraSpacing    - �μ�౶����
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetParaSpacing(DK_DOUBLE paraSpacing) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����Tab��С��
    //  Parameters:
    //      [in] tabStop        - Tab�Ĵ�С�����ַ����Ϊ��λ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetTabStop(DK_DOUBLE tabStop) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��������������
    //  Parameters:
    //      [in] indent            - Ĭ���ֺŴ�С��
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetFirstLineIndent(DK_DOUBLE indent) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����������ɫ��
    //  Parameters:
    //      [in] textColor      - �ı���ɫֵ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      �˽ӿڽ���������������ֵ���ɫ���������� ePub ��ָ������ɫ��
    //      ���� ResetAllColor �ӿڽ��ָ� ePub ԭɫ���á�
    //      �ýӿ��������½������Ű棬���� ParseContent ����á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
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
    //      �˽ӿڽ���������������ֵ���ɫ���ָ� ePub ԭɫ���á�
    //      �ýӿ��������½������Ű棬���� ParseContent ����á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
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
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetTypeSetting(DKTYPESETTING typeSetting) = 0;

public:
    //-------------------------------------------
    //  Summary:
    //      ���н����ĳ�ʼ��������
    //  Parameters:
    //      [in] pCallBackManager    - �ص��ӿڹ�������
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ��ִ�� ParseContent ǰ������ô˽ӿڣ����ڻص������趨��ͼ�������Ϣ�����Ȳ�����
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode PrepareParseContent(IDKECallBackManager *pCallBackManager) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����ePubͼ�����ݡ�
    //  Parameters:
    //      [in] option             - ������ѡ��μ� DKE_PARSER_OPTION �ṹ˵����
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ������ PrepareParseContent ����֮��ſɵ��ô˽ӿڣ�����ʧ�ܡ� 
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode ParseContent(const DKE_PARSER_OPTION& option) = 0;

    //-------------------------------------------
    //  Summary:
    //      �����鼮��ʹ�õ�������
    //  Parameters:
    //      [out] pppFontFamilys     - ���ҵ���font family
    //      [out] pFamilyCount       - font family����Ŀ
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ������ PrepareParseContent ����֮��ſɵ��ô˽ӿڣ�����ʧ�ܡ�
    //      ����Զ࿴����Ч������FreeBookFontFamily�ͷ���Դ
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode ResolveBookFontFamily(DK_WCHAR*** pppFontFamilys, DK_UINT* pFamilyCount) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷŵ����鼮����Ľ��
    //  Parameters:
    //      [in] ppFontFamilys     - ���ҵ���font family
    //      [in] familyCount       - font family����Ŀ
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ������ PrepareParseContent ����֮��ſɵ��ô˽ӿڣ�����ʧ�ܡ�
    //      ����Զ࿴����Ч
    //  Availability:
    //      ��ePubLib 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeBookFontFamily(DK_WCHAR** ppFontFamilys, DK_UINT familyCount) = 0;

    //-------------------------------------------
    //  @Deprecated
    //  Summary:
    //      ����ʽ����ת��Ϊ�½�HTML�ı���ԭʼ�ֽ�ƫ����
    //  Parameters:
    //      [in] position           - ��ʽ����
    //      [out] chapterIndex      - ����ţ���0��ʼ
    //      [out] offset            - �½�HTML�ı���ԭʼ�ֽ�ƫ����
    //  Return:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      �����FlowPosition�����ǺϷ��ģ�����᷵��ʧ�ܡ���������ǩ�ȵ���λ�õ�ת����
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode DKFlowPosition2Offset(const DK_FLOWPOSITION &position, DK_UINT* pChapterIndex, DK_OFFSET* pOffset) = 0;

    //-------------------------------------------
    //  @Deprecated
    //  Summary:
    //      ���½�HTML�ı���ԭʼ�ֽ�ƫ����ת��Ϊ��ʽ����
    //  Parameters:
    //      [in] chapterIndex           - ����ţ���0��ʼ
    //      [in] offset                 - �½�HTML�ı���ԭʼ�ֽ�ƫ����
    //      [out] pPposition            - ��ʽ����
    //  Return:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      �����offset�����ǺϷ��ģ�����᷵��ʧ�ܡ���������ǩ�ȵ���λ�õ�ת����
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode DKOffset2FlowPosition(DK_UINT chapterIndex, DK_OFFSET offset, DK_FLOWPOSITION* pPosition) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����flow position��ʾ������ת��Ϊ�������ֽ�ƫ������ʾ������
    //  Parameters:
    //      [in] startPos                   - ���俪ʼflow position
    //      [in] endPos                     - �������flow position
    //      [out] pStartChapterIndex        - ��ʼλ�����ڵ��µ����
    //      [out] pStartOffset              - ���ڿ�ʼλ�õ��ֽ�ƫ����
    //      [out] pEndChapterIndex          - ����λ�����ڵ��µ����
    //      [out] pEndOffset                - ���ڽ���λ�õ��ֽ�ƫ����
    //  Return:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ���������Ϊ����ҿ������伴[startPos, endPos);
    //      ����������ҲΪ����ҿ������伴[(pStartChapterIndex, pStartOffset), (pEndChapterIndex, pEndOffset))��
    //      ��start position�Ƿ�ʱ�����Ѱ����һ���Ϸ���λ�ã��������λ�õ��ֽ�ƫ������
    //      ��end position�Ƿ�������ǰѰ����һ���Ϸ���λ�ã��������λ�õĺ�һ��λ�õ��ֽ�ƫ������
    //      ��������ժ����ע��λ�������ת����
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode DKFlowPositionRange2OffsetRange(const DK_FLOWPOSITION& startPos, 
                                                        const DK_FLOWPOSITION& endPos, 
                                                        DK_UINT* pStartChapterIndex, 
                                                        DK_OFFSET* pStartOffset, 
                                                        DK_UINT* pEndChapterIndex, 
                                                        DK_OFFSET* pEndOffset) = 0;

    //-------------------------------------------
    //  Summary:
    //      ���������ֽ�ƫ������ʾ������ת��Ϊ��flow position��ʾ������
    //  Parameters:
    //      [in] startChapterIndex          - ��ʼλ�����ڵ��µ����
    //      [in] startOffset                - ���ڿ�ʼλ�õ��ֽ�ƫ����
    //      [in] endChapterIndex            - ����λ�����ڵ��µ����
    //      [in] endOffset                  - ���ڽ���λ�õ��ֽ�ƫ����
    //      [in] pStartPos                  - ���俪ʼflow position
    //      [in] pEndPos                    - �������flow position
    //  Return:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ���������Ϊ����ҿ������伴[(startChapterIndex, startOffset), (endChapterIndex, endOffset));
    //      ����������ҲΪ����ҿ�������[pStartPos, pEndPos)��
    //      ��start offset�Ƿ�ʱ�����Ѱ����һ���Ϸ���λ�ã��������λ�õ�flow position��
    //      ��end offset�Ƿ�������ǰѰ����һ���Ϸ���λ�ã��������λ�õĺ�һ��λ�õ�flow position��
    //      ��������ժ����ע��λ�������ת����
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode DKOffsetRange2FlowPositionRange(DK_UINT startChapterIndex, 
                                                        DK_OFFSET startOffset, 
                                                        DK_UINT endChapterIndex, 
                                                        DK_OFFSET endOffset, 
                                                        DK_FLOWPOSITION* pStartPos, 
                                                        DK_FLOWPOSITION* pEndPos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ͨ��extension.xml�����patch��Ϣ��patch�ļ����ɵ�Offsetת�����µ�
    //  Parameters:
    //      [in]  pSrcRevision          - ���鼮�汾��
    //      [in]  pDestRevision         - ���鼮�汾��
    //      [in]  pChapterID            - ��ID
    //      [in]  srcOffset             - ��Offset
    //      [out] pDestOffset           - ��Offset
    //      [out] pDeleted              - ��ǰ���Ƿ��ѱ�ɾ��
    //  Return:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode UpdateOffsetByPatch(const DK_WCHAR *pSrcRevision, const DK_WCHAR *pDestRevision, 
                                              const DK_WCHAR *pChapterID, DK_OFFSET srcOffset, 
                                              DK_OFFSET *pDestOffset, DK_BOOL *pDeleted) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷż��ص�patch��Ϣ�������ͷ��ڴ�
    //  Parameters:
    //  Return:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ���ú�UpdateOffsetByPatch�Կ�ʹ�ã��˽ӿڽ�Ϊ�ڴ濪������
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID ReleasePatches() = 0;

    //-------------------------------------------
    //  Summary:
    //      �����½���Ż�ȡ���µ����ڱ�ʶID
    //  Parameters:
    //      [in] chapterIndex           - ����ţ���0��ʼ
    //  Return:
    //      ����ɹ�����ID�ַ��������򷵻�NULL
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual const DK_WCHAR* GetChapterID(DK_UINT chapterIndex) const = 0;

    //-------------------------------------------
    //  Summary:
    //      �����½ڵ����ڱ�ʶID��ȡ���µ����
    //  Parameters:
    //      [in] pChapterID           - �½ڵ����ڱ�ʶID
    //  Return:
    //      ����ɹ������µ���ţ����򷵻�-1
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_INT GetChapterIndex(const DK_WCHAR* pChapterID) const = 0;

    //-------------------------------------------
    //  Summary:
    //      �����½ڵ�����URL��ȡ���µ����
    //  Parameters:
    //      [in] pChapterUrl           - �½ڵ�����URL
    //  Return:
    //      ����ɹ������µ���ţ����򷵻�-1
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_INT GetChapterIndexByURL(const DK_WCHAR* pChapterURL) const = 0;

    //-------------------------------------------
    //  Summary:
    //      �ض���ĳ��chapter idָ���chapter HTML��pChapterPathָ���HTML
    //  Parameters:
    //      [in] pChapterId         - ��Ҫ�ض����chapter id
    //      [in] pChapterPath       - ������chapter HTML
    //      [in] isEncrypted        - ������HTML�Ƿ񱻼���
    //  Return:
    //      ����ɹ�����DKR_OK�����򷵻�ʧ��
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //      ����֮ǰӦ�ò�����ֶ����ԭ���½��ѽ��������ݡ�
    //      ��containerΪfolder��pChapterPathΪ������ļ��е�ȫ·����
    //      ��containerΪZIP��pChapterPathΪѹ������ȫ·����
    //  Availability:
    //      ��ePubLib 2.4.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode RedirectChapter(const DK_WCHAR* pChapterId, const DK_WCHAR* pChapterPath, DK_BOOL isEncrypted) = 0;
    
public:
    //-------------------------------------------
    //  Summary:
    //      ��ȡ�ĵ���Ϣ��
    //  Parameters:
    //      Null
    //  Return Value:
    //      ����ͼ��Ԫ���ݡ�
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual const DKEBOOKINFO* GetBookInfo() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�鼮��ID
    //  Parameters:
    //      Null
    //  Return Value:
    //      �����鼮ID�ִ���
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual const DK_WCHAR* GetBookID() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�鼮�ķ־��ļ�ID
    //  Parameters:
    //      Null
    //  Return Value:
    //      �����鼮�ķ־��ļ�ID�ִ���
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual const DK_WCHAR* GetResourceID() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�鼮���޶��汾��
    //  Parameters:
    //      Null
    //  Return Value:
    //      �����鼮�޶��汾���ִ���
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual const DK_WCHAR* GetBookRevision() const = 0;

    //-------------------------------------------
    //  @Deprecated
    //  Summary:
    //      ��ȡ�鼮�ı༭����dobby�İ汾��
    //  Parameters:
    //      Null
    //  Return Value:
    //      �����鼮�ı༭����dobby�İ汾���ִ���
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡����ӿ��ѱ�����������ʹ��GetStudioVersion�ӿ�
    //-------------------------------------------
    virtual const DK_WCHAR* GetDobbyVersion() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�鼮�ı༭���ߵİ汾��
    //  Parameters:
    //      Null
    //  Return Value:
    //      �����鼮�ı༭���ߵİ汾���ִ���
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual const DK_WCHAR* GetStudioVersion() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�鼮�汾�š�
    //  Parameters:
    //      [in] majorVersion      - ���汾�š�
    //      [in] minorVersion      - �ΰ汾�š�
    //  Return Value:
    //      DKR_OK     : �ɹ�
    //      DKR_FAILED : ʧ��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.1.2 ��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetDuokanBookVersion(DK_INT &majorVersion, DK_INT &minorVersion) const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�鼮�����ݵ�����
    //  Parameters:
    //      Null
    //  Return Value:
    //      �����鼮�����ݵ����͵�ö�١�
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DKE_BOOKCONTENT_TYPE GetBookContentType() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�鼮�Ű淽��
    //  Parameters:
    //      Null
    //  Return Value:
    //      �����鼮�����ݵ����͵�ö�١��Ű淽��
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DKEWRITINGOPT GetBookWritingOpt() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�����鼮չ�ַ�ʽ
    //  Parameters:
    //      Null
    //  Return Value:
    //      �����鼮�����ݵ�չ�ַ�ʽ��ö�ٺͱ�ʶ��
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 2.3.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DKEDISPLAYOPT GetBookDisplayOpt() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡͼ��������ݡ�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ����ͼ�����������Ϣ�����ʧ���򷵻�DK_NULL��
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual const DKFILEINFO* GetBookCover() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡͼ���½�������
    //  Parameters:
    //      Null
    //  Return Value:
    //      �½�������
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_LONG GetChapterCount() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�ĵ���ĳһҳ��
    //  Parameters:
    //      [in] pageNum        - ���鷶Χ�ڵ�ҳ�룬��0��ʼ��
    //  Return Value:
    //      ����ҳ����ָ�롣
    //  Remarks:
    //      �ýӿ��� DKE_PARSER_PAGETABLE_CHAPTER ģʽ����Ч��
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEPage* GetPage(DK_LONG pageNum) = 0;

    //-------------------------------------------
    //  Summary:
    //      ������ʽ�����ȡĳһҳ������ʽ��������ҳ�������ڼ���
    //  Parameters:
    //      [in] pos        - ��ʽ���ꡣ
    //  Return Value:
    //      ����ҳ����ָ�롣
    //  Remarks:
    //      ���ָ����λ�û�δ��ɷ�ҳ����㣬�򽫷���DK_NULL��
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEPage* GetPage(const DK_FLOWPOSITION& pos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�ĵ���ĳһҳ��
    //  Parameters:
    //      [in] chapterIndex       - �½���������0��ʼ��
    //      [in] pageNumOfChapter    - ���½ڷ�Χ�ڵ�ҳ�룬��0��ʼ��
    //  Return Value:
    //      ����ҳ����ָ�롣
    //  Remarks:
    //      ���ָ����λ�û�δ��ɷ�ҳ����㣬�򽫷���DK_NULL��
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKEPage* GetPageOfChapter(DK_LONG chapterIndex, DK_LONG pageNumOfChapter) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ����
    //  Parameters:
    //      Null
    //  Return Value:
    //      ����ɹ�������ҳ�������򽫷���-1��
    //  Remarks:
    //      �ýӿ��� DKE_PARSER_PAGETABLE_CHAPTER ģʽ����Ч��
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_LONG GetPageCount() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡҳ����
    //  Parameters:
    //      [in] chapterIndex       - �½���������0��ʼ��
    //  Return Value:
    //      ����ɹ����ظ��½ڵ�ҳ�������򽫷���-1��
    //  Remarks:
    //      ���ָ���½�δ��ɷ�ҳ����㣬�򽫷���-1��
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_LONG GetPageCountOfChapter(DK_LONG chapterIndex) const = 0;

    //-------------------------------------------
    //  Summary:
    //      ͨ����ʽ�����ȡ����ҳ�롣��ʽ��������ҳ�����伴��
    //  Parameters:
    //      [in] pos            - ��ʽ���ꡣ
    //  Return Value:
    //      ����ɹ���������ҳ�룬���򽫷���-1��ҳ���0��ʼ��
    //  Remarks:
    //      ���ָ���½�δ��ɷ�ҳ����㣬�򽫷���-1��
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_LONG GetPageNumOfChapter(const DK_FLOWPOSITION& pos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�ĵ���Ŀ¼�ṹ��
    //  Parameters:
    //      Null
    //  Return Value:
    //      ����Ŀ¼�ӿ�ָ�롣
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual IDKETocPoint* GetTocRoot() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�ĵ�ĳһ�½ڵ����ͣ����ͼҳ
    //  Parameters:
    //      [in] chapterIndex       - �½���������0��ʼ��
    //  Return Value:
    //      DKE_CHAPTER_TYPE �½����͵�ö��
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DKE_CHAPTER_TYPE GetChapterType(DK_LONG chapterIndex) const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�ĵ�ĳһ�½ڵ��ļ���С
    //  Parameters:
    //      [in] chapterIndex       - �½���������0��ʼ��
    //  Return Value:
    //      �ļ���С�����ʧ�ܣ��粻���ڣ�����-1
    //  Remarks:
    //      ��PrepareParseContent�ӿڵ���֮�󼴿�ʹ�á�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_LONG GetChapterSize(DK_LONG chapterIndex) const = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�ĵ�ĳһ�½��ڵ�ĳ��ê���Ӧ����ʽ����
    //  Parameters:
    //      [in] chapterIndex       - �½���������0��ʼ��
    //      [in] pAnchor            - ê�������
    //      [out] pPos              - ê���Ӧ����ʽ����
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ���ص���ʽ�����chapterIndex�봫�����chapterIndex����һ�¡�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetAnchorPosition(DK_LONG chapterIndex, const DK_WCHAR* pAnchor, DK_FLOWPOSITION* pPos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�ĵ�ĳһ�½��ڵ�ĳ��ê���Ӧ����ʽ��������
    //  Parameters:
    //      [in] chapterIndex       - �½���������0��ʼ��
    //      [in] pAnchor            - ê�������
    //      [out] pStartPos         - ê���Ӧ����ʼ��ʽ����
    //      [out] pEndPos           - ê���Ӧ�Ľ�����ʽ����
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ���ص���ʽ�����chapterIndex�봫�����chapterIndex����һ�¡�
    //  Availability:
    //      ��ePubLib 2.7.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetAnchorPosRange(DK_LONG chapterIndex, const DK_WCHAR* pAnchor, DK_FLOWPOSITION* pStartPos, DK_FLOWPOSITION* pEndPos) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�ĵ�ĳһ�½��ڵ�MediaOverlay��Ϣ
    //      ��ʱֻ֧��ͬ����Ļ������Ϣ
    //  Parameters:
    //      [in] chapterIndex       - �½���������0��ʼ��
    //      [out] pParInfos         - ͬ����Ļ������Ϣ
    //  Return Value:
    //      ͬ����Ļ������Ϣ������0��ʾû�С�
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.6��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_UINT GetChapterMediaOverlayParInfo(DK_LONG chapterIndex, DKE_SMIL_PAR_INFO*& pParInfos) = 0;
    virtual DK_VOID FreeParInfo(DKE_SMIL_PAR_INFO* pParInfos, DK_UINT nCount) = 0;
    virtual DK_BOOL GetChapterMediaByUrl(DK_LONG chapterIndex, const DK_WCHAR* url, DKSTREAMINFO*& mediaInfo) = 0;
    virtual DK_VOID FreeChapterMediaInfo(DKSTREAMINFO* mediaInfo) = 0;

public:
    //-------------------------------------------
    //  Summary:
    //      �������÷�ҳ�����ݡ�
    //  Parameters:
    //      [in] infoFilePath       - ���÷�ҳ�������ļ�·����
    //      [in] msType             - ������λ��
    //      [in] dpi                - �豸�� dpi ��Ϣ��
    //      [in] envArray           - �����������С�
    //      [in] envCount           - �������в������г��ȡ�
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      ������ PrepareParseContent ����֮��ſɵ��ô˽ӿڣ�����ʧ�ܡ�
    //      ���뱣֤���øýӿ�֮ǰ����������Ű���ز������趨���������ɵķ�ҳ��������Ч��
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode CreatePageBreakInfo(const DK_WCHAR* infoFilePath,
                                              DK_MEASURE_TYPE msType,
                                              DK_LONG dpi,
                                              const DKE_PAGEBREAK_ENV* envArray,
                                              DK_UINT envCount) = 0;

    //-------------------------------------------
    //  Summary:
    //      ������ܵ�ͼ���ļ���
    //  Parameters:
    //      [in] encryptedBookPath  - ���ܡ�
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode ExportEncryptedBook(const DK_WCHAR* encryptedBookPath, const DKE_DRMKEY *pKey = DK_NULL, DK_BOOL compressFirst = DK_FALSE) = 0;

public:
    //-------------------------------------------
    //  Summary:
    //      ��ȫ���ڲ����ı��������� PrepareParseContent ֮����á�
    //  Parameters:
    //      [in] startPos               - ��ʼ������λ��
    //      [in] text                   - �����ı�
    //      [in] maxResultCount         - �������Ŀ
    //      [out] findResults           - ���������Ϊһϵ�� [start, end) �����
    //      [out] resultCount           - ���������Ŀ
    //  Return Value:
    //      ���������ʹû���ҵ����Ҳ���� DKR_OK���� resultCount �жϲ����Ƿ��н����
    //      �����ش����롣
    //  Remarks:
    //      findResults ��Ԫ�صĸ���Ӧ��Ϊ 2*resultCount��
    //      ʹ�����֮�������� FreeFindTextResults �ӿ��ͷš�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode FindTextInBook(const DK_FLOWPOSITION& startPos,
                                         const DK_WCHAR* text,
                                         DK_UINT maxResultCount,
                                         DK_FLOWPOSITION** findResults,
                                         DK_UINT* resultCount) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ĳ�½��ڲ����ı��������� PrepareParseContent ֮����á�
    //  Parameters:
    //      [in] startPos               - ��ʼ������λ��
    //      [in] text                   - �����ı�
    //      [in] maxResultCount         - �������Ŀ
    //      [out] findResults           - ���������Ϊһϵ�� [start, end) �����
    //      [out] resultCount           - ���������Ŀ
    //  Return Value:
    //      ���������ʹû���ҵ����Ҳ���� DKR_OK���� resultCount �жϲ����Ƿ��н����
    //      �����ش����롣
    //  Remarks:
    //      findResults ��Ԫ�صĸ���Ӧ��Ϊ 2*resultCount��
    //      ʹ�����֮�������� FreeFindTextResults �ӿ��ͷš�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode FindTextInChapter(const DK_FLOWPOSITION& startPos,
                                            const DK_WCHAR* text,
                                            DK_UINT maxResultCount,
                                            DK_FLOWPOSITION** findResults,
                                            DK_UINT* resultCount) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ��ı����ҽ��
    //  Parameters:
    //      [in] findResults            - �������
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeFindTextResults(DK_FLOWPOSITION* findResults) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ò��ҽ����������Ƭ�Ρ�
    //  Parameters:
    //      [in] pos                    - ���ҽ����λ��
    //      [in] text                   - ����֮�ı�
    //      [in] ellipsis               - ʡ�Է���
    //      [in] snippetLen             - snippet ���ȣ�������������
    //      [out] result                - ���ܷ��� snippet �� buffer
    //      [out] startPosInSnippet     - �������� snippet �е���ʼλ��
    //      [out] endPosInSnippet       - �������� snippet �еĽ���λ��
    //  Return Value:
    //      �����ش����롣
    //  Remarks:
    //      ��������Ƭ�β��ڶ���߽���ֹʱ��������ָ����ʡ�Է��š�
    //      result buffer�ĳ���������Ҫ������ snippetLen + 2*ellipsisLen + 1 ���ϡ�
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetFindTextSnippet(const DK_FLOWPOSITION& pos,
                                             const DK_WCHAR* text,
                                             const DK_WCHAR* ellipsis,
                                             DK_UINT snippetLen,
                                             DK_WCHAR* result,
                                             DK_UINT* startPosInSnippet,
                                             DK_UINT* endPosInSnippet) = 0;

    //-------------------------------------------
    //  Summary:
    //      ���һ�µ�ȫ���ı�
    //  Parameters:
    //      [in] chapterIndex           - �½�������,0��ʼ
    //      [out] resultText            - ���ղ��ҵ��ı�
    //  Return Value:
    //      �����ش�����,��ȷ����DKR_OK
    //  Remarks:
    //      �������FreeChapterText�ͷŻ�ȡ���ı���      
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetChapterText(DK_LONG chapterIndex, DK_WCHAR** resultText) = 0;

    //-------------------------------------------
    //  Summary:
    //      ͨ��������ʼ��ʽ����ͽ�����ʽ������һ�µ�ĳ���ı�
    //  Parameters:
    //      [in] startPos               - ������ʼ��ʽ����
    //      [in] endPos                 - ���ڽ�����ʽ����
    //      [out] ppResultText          - ���ղ��ҵ��ı�
    //  Return Value:
    //      �����ش�����,��ȷ����DKR_OK
    //  Remarks:
    //      startPos��endPosΪ����ҿ����䡣
    //      startPos��endPos��chapterIndex����һ�£����򷵻ش���
    //      �������FreeChapterText�ͷŻ�ȡ���ı���
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetChapterTextOfRange(const DK_FLOWPOSITION& startPos, const DK_FLOWPOSITION& endPos, DK_WCHAR** ppResultText) = 0;

    //-------------------------------------------
    //  Summary:
    //      ͨ��������ʼ��ʽ����ͽ�����ʽ������һ�µ�ĳ��HTML���ı�
    //  Parameters:
    //      [in] startPos               - ������ʼ��ʽ����
    //      [in] endPos                 - ���ڽ�����ʽ����
    //      [out] ppRichText            - �����ĸ��ı�
    //  Return Value:
    //      �����ش�����,��ȷ����DKR_OK
    //  Remarks:
    //      startPos��endPosΪ����ҿ����䡣
    //      startPos��endPos��chapterIndex����һ�£����򷵻ش���
    //      �������FreeChapterText�ͷŻ�ȡ���ı���
    //  Availability:
    //      ��ePubLib 2.6.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetChapterRichTextOfRange(const DK_FLOWPOSITION& startPos, const DK_FLOWPOSITION& endPos, DK_WCHAR** ppRichText) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ���GetChapterText��ȡ���ı�
    //  Parameters:
    //      [in] resultText             - ���ͷŵ��ı�
    //  Return Value:
    //      None
    //  Remarks:
    //      None
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeChapterText(DK_WCHAR* resultText) = 0;

    //-------------------------------------------
    //  Summary:
    //      ͨ��������ʼ��ʽ����ͽ�����ʽ������һ�µ�ĳ���ı��������Χ�ڳ�������Ԫ��(������ͼƬ�ȵ�)�����¼alt��Ϣ��
    //  Parameters:
    //      [in] startPos                      - ��ʼ����λ��
    //      [in] endPos                        - ��������λ��
    //      [out] pTextContentInfo             - �ı����ݣ���������Ԫ����Ϣ��
    //  Return Value:
    //      DK_ReturnCode
    //  Remarks:
    //      ��startPos��endPos������һҳ�ı߽��������õ�ҳ����������ĵ㡣
    //      ���ص��ı�����ָ����ʹ����Ϻ�������FreeChapterTextEx�ӿ��ͷš�
    //  Availability:
    //      ��ePubLib 2.2.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetChapterTextOfRangeEx(const DK_FLOWPOSITION& startPos, const DK_FLOWPOSITION& endPos, DKE_TEXT_CONTENT_INFO* pTextContentInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷ���GetChapterTextOfRangeEx��ȡ���ı����ݣ���������Ԫ����Ϣ����
    //  Parameters:
    //      [in] pTextContentInfo            - �ı�����ָ��
    //  Return Value:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.2.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeChapterTextEx(DKE_TEXT_CONTENT_INFO* pTextContentInfo) = 0;

    //-------------------------------------------
    //  Summary:
    //      �����ַ��������ض�Ӧ��DK_FLOWPOSITION
    //  Parameters:
    //      [in] chapterIndex           -   �½�����
    //      [in] charOffset:            -   �����׵��ַ�ƫ����
    //      [out] flowPosition          -   ������Ӧ��flow position
    //                                      ���������ʹԽ��Ҳ����
    //                                      �������һ���ַ���Ӧ��flow position,
    //  Return:
    //      DKR_OK
    //      �����ش�����
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetFlowPositionByCharOffsetForChapter(DK_LONG chapterIndex, DK_UINT charOffset, DK_FLOWPOSITION* flowPosition) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����ֹͣ��ҳ�ı�־
    //  Parameters:
    //      None
    //  Return:
    //      None
    //  Remarks:
    //      �ñ�־���ò�����parse�̻߳���������,
    //      ��parse�̻߳���ÿ��һҳ����ñ�־��
    //      ΪDK_TRUE���жϷ���,Ӧ����ȴ�parse�߳���ֹ������book�Ͻ������Ż�رյȲ���
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetStopParsingFlag() = 0;

    //-------------------------------------------
    //  Summary:
    //      ���ĳ�����Ű��ҳ��     
    //  Parameters:
    //      [in] chapterIndex       - �½�����
    //  Return Value:
    //      Null��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID ClearParsedPagesForChapter(DK_LONG chapterIndex) = 0;

    //-------------------------------------------
    //  Summary:
    //      ���ĳ�����Ű��ҳ�沢���µ��ڲ���������     
    //  Parameters:
    //      [in] chapterIndex       - �½�����
    //  Return Value:
    //      Null��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.0.9��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID ClearChapterData(DK_LONG chapterIndex) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����������Ű��ҳ��     
    //  Parameters:
    //      Null
    //  Return Value:
    //      Null��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID ClearAllParsedPages() = 0;

    //-------------------------------------------
    //  Summary:
    //     У���ҳ�������Ƿ�Ϸ�     
    //  Parameters:
    //      [in] pageBreakFile      - ��ҳ���ļ�
    //      [in] msType             - ������λ��
    //      [in] dpi                - �豸�� dpi ��Ϣ��
    //  Return Value:
    //      Null��
    //  Remarks:
    //      ���ô˺���ǰ�����Ű�����������ҳ������ʱһ�£������ʧ��
    //  Availability:
    //      ��ePubLib 1.0.10��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode VerifyPageBreakFile(const DK_WCHAR* pageBreakFile, DK_MEASURE_TYPE msType, DK_LONG dpi) = 0;

#if DKE_SUPPORT_FONT_DOWNLOAD
	//-------------------------------------------
	//	Summary:
	//	    ������������ 	
	//	Parameters:
	//		[in] downloadFontDir        - �������������Ŀ¼,�������
	//	Return Value:
	//		�ɹ�return DKR_OK,ʧ������
	//	Remarks:
	//		�ڴ�֮ǰ��Ҫ����ParseContent,������ȫ��
	//  Availability:
	//		��ePubLib 1.0.6��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_ReturnCode GenerateDownloadFonts(const DK_WCHAR* downloadFontDir) = 0;
#endif

#if DKE_SUPPORT_DUMP
	//-------------------------------------------
	//	Summary:
	//	    Dump����,���ڵ������ 	
	//	Parameters:
    //      None
    //  Remarks:
	//		��ePubLib 1.0.7��ʼ֧�֡�
	//-------------------------------------------
    virtual DK_VOID Dump() = 0;
#endif

    //-------------------------------------------
	//	Summary:
	//	    ����鼮�ڲ�CSS�ļ����﷨����
	//	Parameters:
    //      [out]ppErrors           - ��鵽���﷨���������
    //      [out]pErrorCount        - ��鵽���﷨����ĸ���
    //  Remarks:
	//		������ PrepareParseContent ����֮��ſɵ��ô˽ӿڡ�
    //      ����FreeCSSGrammarError�ͷ�ppErrors����
    //  Availability:
    //      ��ePubLib 2.0.1��ʼ֧��
	//-------------------------------------------
    virtual DK_VOID CheckBookCSSGrammar(DKE_CSS_ERROR** ppErrors, DK_UINT* pErrorCount) = 0;

    //-------------------------------------------
	//	Summary:
	//	    �ͷż�鵽��CSS�ļ����﷨����
	//	Parameters:
    //      [in]pErrors             - CSS�﷨���������
    //      [in]errorCount          - ����Ĵ�С
    //  Remarks:
	//		������ CheckBookCSSGrammar ����֮��ſɵ��ô˽ӿڡ�
    //  Availability:
    //      ��ePubLib 2.0.1��ʼ֧��
	//-------------------------------------------
    virtual DK_VOID FreeCSSGrammarError(DKE_CSS_ERROR* pErrors, DK_UINT errorCount) = 0;

    //-------------------------------------------
	//	Summary:
	//	    ����鼮�ڲ����õ��ļ�
	//	Parameters:
    //      [out]pppFilePaths       - ��鵽�����õ��ļ�·��������
    //      [out]pFileCount        - ��鵽�����õ��ļ��ĸ���
    //  Remarks:
	//		������ PrepareParseContent ����֮��ſɵ��ô˽ӿڡ�
    //      ����FreeUnusedFiles�ͷ�pppFilePaths����
    //  Availability:
    //      ��ePubLib 2.0.1��ʼ֧��
	//-------------------------------------------
    virtual DK_VOID CheckBookUnusedFiles(DK_WCHAR*** pppFilePaths, DK_UINT* pFileCount) = 0;

    //-------------------------------------------
	//	Summary:
	//	    �ͷż�⵽�������ļ���·��
	//	Parameters:
    //      [in]ppFilePaths       - ��鵽�����õ��ļ�·��������
    //      [in]fileCoount        - ��鵽�����õ��ļ��ĸ���
    //  Remarks:
	//		������ CheckBookUnusedFiles ����֮��ſɵ��ô˽ӿڡ�
    //  Availability:
    //      ��ePubLib 2.0.1��ʼ֧��
	//-------------------------------------------
    virtual DK_VOID FreeUnusedFiles(DK_WCHAR** ppFilePaths, DK_UINT fileCount) = 0;

    //-------------------------------------------
	//	Summary:
	//	    ��Ⱦ����ͼƬ��ָ����λͼ��ָ���Ĵ�С
	//	Parameters:
    //      [in]pImagePath          - ����ͼƬ�ļ�ȫ·��
    //      [in]option              - ��Ⱦѡ��
    //      [in]dstBox              - Ŀ�����
    //      [in]alpha               - ͸����,0.0-1.0, 0ȫ͸��,1��͸��
    //  Remarks:
	//		NULL
    //  Availability:
    //      ��ePubLib 2.1.0��ʼ֧��
	//-------------------------------------------
    virtual DK_ReturnCode RenderImage(const DK_WCHAR* pImagePath, const DK_FLOWRENDEROPTION& option, const DK_BOX& srcBox, const DK_BOX& dstBox) = 0;

    //-------------------------------------------
	//	Summary:
	//	    ��ȡ����ͼ������֡�ĸ���
	//	Parameters:
    //      Null
    //  Remarks:
	//		��PrepareParseContent֮�����
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧��
	//-------------------------------------------
    virtual DK_LONG GetComicsFrameCount() = 0;

    //-------------------------------------------
	//	Summary:
	//	    ����֡����Ż�ȡ֡ �����㿪ʼ��
	//	Parameters:
    //      [in] frameIndex         - ֡���
    //  Remarks:
	//		��ParseContent֮�����
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧��
	//-------------------------------------------
    virtual IDKEComicsFrame* GetComicsFrame(DK_LONG frameIndex) = 0;

    //-------------------------------------------
	//	Summary:
	//	    �����½�����жϸ��½��Ƿ��������½�
	//	Parameters:
    //      [in] chapterIndex       - �����
    //  Remarks:
	//		��ParseContent֮�����
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧��
	//-------------------------------------------
    virtual DK_BOOL IsComicsChapter(DK_LONG chapterIndex) = 0;

    //-------------------------------------------
	//	Summary:
	//	    ����֡����Ż�ȡ��֡�����½ڵ���� ��ȫ�����㿪ʼ��
	//	Parameters:
    //      [in] frameIndex       - ֡���
    //  Remarks:
	//		��ParseContent֮�����
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧��
	//-------------------------------------------
    virtual DK_LONG GetChapterIndexOfFrame(DK_LONG frameIndex) = 0;

    //-------------------------------------------
	//	Summary:
	//	    ������������ɵ�����֡
	//	Parameters:
    //      Null
    //  Remarks:
	//		��ParseContent֮�����
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧��
	//-------------------------------------------
    virtual DK_VOID ClearAllComicsFrame() = 0;

    //-------------------------------------------
	//	Summary:
	//	    ���ĳһ�½������ɵ�����֡
	//	Parameters:
    //      Null
    //  Remarks:
	//		��ParseContent֮�����
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧��
	//-------------------------------------------
    virtual DK_VOID ClearComicsFrameForChapter(DK_LONG chapterIndex) = 0;

public:
    virtual ~IDKEBook() {};
};

//===========================================================================

#endif // #ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKEBOOK_H__
