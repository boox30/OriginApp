//===========================================================================
// Summary:
//        IBookReader�ӿڶ���
// Version:
//    0.1 draft - creating.
//
// Usage:
//        Null
// Remarks:
//        Null
// Date:
//        2011-11-21
// Author:
//        Chen Mao (chenm@duokan.com)
//===========================================================================

#ifndef __KINDLEAPP_INC_IBOOKREADER_H__
#define __KINDLEAPP_INC_IBOOKREADER_H__

#include "DKXManager/BaseType/CT_RefPos.h"
#include "DKXManager/ReadingInfo/ICT_ReadingDataItem.h"
#include "DKXManager/DKX/DKXReadingDataItemFactory.h"
#include "BMPProcessor/IBMPProcessor.h"
#include "BookReader/TocInfo.h"
#include "KernelBaseType.h"
#include <vector>
#include <stdint.h>
#include "Common/File_DK.h"
#include "BookStore/ReadingBookInfo.h"
#include "GUI/EventSet.h"
#include "GUI/EventArgs.h"

class BookTextController;
class DKXBlock;
using namespace dk::bookstore::sync;
using std::string;
using std::wstring;

#define  DoublePrecision 0.005 //���嵼�������Ű�Ĳ�������
#define LINEMAXSTRETCHRATE 2.0
//-------------------------------------------
// Summary:
//        �Ű����
//-------------------------------------------
struct DK_LAYOUTSETTING
{
    int    dFontSize;		// �����ֺŴ�С
    double dLineGap;		// �м�౶��
    double dParaSpacing;	// �μ�౶��
    double dTabStop;		// Tab�Ĵ�С�����ַ����Ϊ��λ
    double dIndent;			// ��������
    bool   bOriginalLayout; // ʹ��ԭʼ��ʽ��������м�࣬�μ�࣬��������������
    //Fontsize �����4���������� 24, 28, 32, 48Ϊ��
    DK_LAYOUTSETTING()
        : dFontSize(24)
        , dLineGap(1.5)
        , dParaSpacing(1)
        , dTabStop(2)
        , dIndent(2)
        , bOriginalLayout(false)
    {
    }
};

typedef CT_RefPos ATOM;

//-------------------------------------------
// Summary:
//        PDF�Ķ�ģʽ
//-------------------------------------------
enum TurnPageMode
{
    PDF_TPM_SinglePage,//��ҳģʽ
    PDF_TPM_ScrollPage,//����ģʽ
};

enum ReadingMode
{
    PDF_RM_NormalPage,//����ģʽ
    PDF_RM_Split4Page,//�ķ���
    PDF_RM_Split2Page,//������
    PDF_RM_ZoomPage,//�Ŵ�ģʽ
    PDF_RM_AdaptiveWidth,//�������Ӧ
    PDF_RM_Rearrange //����ģʽ
};

enum CuttingEdgeMode
{
    PDF_CEM_Normal,//�������б�
    PDF_CEM_Smart,//�����б�
    PDF_CEM_Custom,//�Զ����ֶ��б�
};

//�жԴ���ֵ�Ĳ���
enum CHAPTER_POSITION_MODE
{
    PRIVIOUS_CHAPTER = 0,
    CURRENT_CHAPTER = 1,
    NEXT_CHAPTER = 2,
};

struct PdfModeController
{
    DK_INT m_iRotation;//��ǰ�Ƕ�

    TurnPageMode m_eTurnPageMode;
    DK_UINT m_uCurSubPage;//��ǰ��ҳ(����ģʽ)
    DK_UINT m_uCurPageStartPos;//��ҳ���Ϸ���λ��

    ReadingMode  m_eReadingMode;
    DK_DOUBLE    m_dUserZoom;//�Ŵ�ģʽ�ķŴ���
    DK_DOUBLE    m_zoomX0; //���Ͻ�X
    DK_DOUBLE    m_zoomY0; // ���Ͻ�Y
    DK_DOUBLE    m_imageX; //ͼ���ڷŴ�ͼƬ�����Ͻ�X
    DK_DOUBLE	 m_imageY;//ͼƬ�ڷŴ�ͼƬ�����Ͻ�Y
    DK_UINT      m_uSubPageOrder;//���������ҳ�ķ�ҳ˳��
    DK_DOUBLE    m_dWidth;//������ռ��Ȱٷֱ�
    DK_DOUBLE    m_dHeight;//������ռ�߶Ȱٷֱ�

    CuttingEdgeMode m_eCuttingEdgeMode;
    DK_BOOL      m_bIsSmartCutting;
    DK_BOOL      m_bIsNormalCutting; //���ΪtrueΪ�����бߣ�false����洢������ҳ�б�����
    DK_DOUBLE    m_dTopEdge;//�ϱߵı߾�ռ�߶Ȱٷֱ�
    DK_DOUBLE    m_dBottomEdge;//�±߱߾�ռ�߶Ȱٷֱ�
    DK_DOUBLE    m_dLeftEdge;//��߱߾�ռ��Ȱٷֱ�
    DK_DOUBLE    m_dRightEdge;//�ұ߱߾�ռ��Ȱٷֱ�
    PdfModeController()
        : m_iRotation(0)
        , m_eTurnPageMode(PDF_TPM_SinglePage)
        , m_uCurSubPage(0)
        , m_uCurPageStartPos(0)
        , m_eReadingMode(PDF_RM_NormalPage)
        , m_dUserZoom(1)
        , m_zoomX0(0)
        , m_zoomY0(0)
        , m_uSubPageOrder(0)
        , m_dWidth(0)
        , m_dHeight(0)
        , m_eCuttingEdgeMode(PDF_CEM_Normal)
        , m_bIsSmartCutting(false)
        , m_bIsNormalCutting(true)
        , m_dTopEdge(0)
        , m_dBottomEdge(0)
        , m_dLeftEdge(0)
        , m_dRightEdge(0)
    {
    }
};

enum BOOKREADER_PARSE_STATUS
{
    BOOKREADER_PARSE_START = 0,
    BOOKREADER_PARSE_ERROR,
    BOOKREADER_PARSE_FINISHED,
};

struct SEARCH_RESULT_DATA
{
    ICT_ReadingDataItem** pSearchResultTable;
    unsigned int* pHighlightStartPosTable;
    unsigned int* pHighlightEndPosTable;
    int* pLocationTable;
};

// ��ʾҳ����ȵ�ģʽ
enum PAGE_PROGRESS_DISPLAY_MODE
{
    PPDM_COUNT,
    PPDM_PERCENT
};

struct BOOK_INFO_DATA
{
    std::string author;
    std::string title;
    const uint8_t* coverData;
    uint32_t coverDataLen;
    BOOK_INFO_DATA()
        : coverData(0)
        , coverDataLen(0)
    {
    }
};

enum BOOK_DIRECTION_TYPE
{
    BOOK_MODE_HTB = 0x10,
    BOOK_MODE_HBT = 0x20,
    BOOK_MODE_VRL = 0x40,
    BOOK_MODE_VLR = 0x80,
    BOOK_DIRECTION_LTR = 0x1,
    BOOK_DIRECTION_RTL = 0x2,
    BOOK_MODE_HTB_DIRECTION_LTR = BOOK_MODE_HTB | BOOK_DIRECTION_LTR,
    BOOK_MODE_HTB_DIRECTION_RTL = BOOK_MODE_HTB | BOOK_DIRECTION_RTL,
    BOOK_MODE_HBT_DIRECTION_LTR = BOOK_MODE_HBT | BOOK_DIRECTION_LTR,
    BOOK_MODE_HBT_DIRECTION_RTL = BOOK_MODE_HBT | BOOK_DIRECTION_RTL,
    BOOK_MODE_VRL_DIRECTION_LTR = BOOK_MODE_VRL | BOOK_DIRECTION_LTR,
    BOOK_MODE_VRL_DIRECTION_RTL = BOOK_MODE_VRL | BOOK_DIRECTION_RTL,
    BOOK_MODE_VLR_DIRECTION_LTR = BOOK_MODE_VLR | BOOK_DIRECTION_LTR,
    BOOK_MODE_VLR_DIRECTION_RTL = BOOK_MODE_VLR | BOOK_DIRECTION_RTL
};

class ParseStatusEventArgs: public EventArgs
{
public:
    ParseStatusEventArgs()
    {}
    virtual EventArgs* Clone() const
    {
        return new ParseStatusEventArgs(*this);
    }
};

class UIBookParseStatusListener: public EventSet
{
public:
    static const char* EventBookParseFinished;
    static UIBookParseStatusListener* GetInstance();
    void FireBookParseFinishedEvent();
};

#define BOOKREADER_GOTOPAGE_SUCCESS 0x0
#define BOOKREADER_GOTOPAGE_FAIL    0x1
#define BOOKREADER_GOTOPAGE_WAIT    0x2

//-------------------------------------------
// Summary:
//        IBookReader �ӿ�
//-------------------------------------------
class IBookReader
{
public:
    virtual ~IBookReader(){};

    //-------------------------------------------
    // Summary:
    //        ��ͼ��
    //-------------------------------------------
    virtual bool OpenDocument(const string &_strFilename) = 0;

    //-------------------------------------------
    // Summary:
    //        �ر�ͼ��
    //-------------------------------------------
    virtual bool CloseDocument() = 0;

	//-------------------------------------------
    // Summary:
    //        �����Ű�ģʽ
    //-------------------------------------------
	virtual void SetTypeSetting(const DKTYPESETTING& typeSetting) = 0;

    //-------------------------------------------
    // Summary:
    //        �����Ű�ҳ���С
    //-------------------------------------------
    virtual bool SetPageSize(int _iLeftMargin, int _iTopMargin, int _iWidth, int _iHeight) = 0;
    //
    //-------------------------------------------
    // Summary:
    //        ������Ļ��С
    //-------------------------------------------
    virtual void SetScreenSize(int screenWidth, int screenHeight) = 0;

    //-------------------------------------------
    // Summary:
    //        ��õ�ǰҳ�Ƿ�ȫ��ҳ
    //-------------------------------------------
    virtual bool IsCurrentPageFullScreen() = 0;

    //-------------------------------------------
    // Summary:
    //        ����ϵͳȱʡ����
    //-------------------------------------------
    virtual bool SetDefaultFont(const wstring &_strFaceName, DK_CHARSET_TYPE _clsCharSet) = 0;

    //-------------------------------------------
    // Summary:
    //        ��õ�ǰҳ������
    //-------------------------------------------
    virtual long GetCurrentPageIndex() = 0;

    //-------------------------------------------
    // Summary:
    //        �Ϸ�ҳ
    //-------------------------------------------
    virtual int GotoPrevPage() = 0;

    //-------------------------------------------
    // Summary:
    //        �·�ҳ
    //-------------------------------------------
    virtual int GotoNextPage() = 0;

    //-------------------------------------------
    // Summary:
    //        ȡ��Ŀ¼
    // Remarks:
    //        ����epub �����ڶΣ����Ըöε�position ��ָ��ǰ�µ�
    //-------------------------------------------
    virtual vector<DK_TOCINFO*>* GetTOC(DKXBlock* curDKXBlock = NULL) = 0;

    //-------------------------------------------
    // Summary:
    //        ��ת��ĳһҳ
    //-------------------------------------------
    virtual int MoveToPage(long _lPageNumber) = 0;

    //-------------------------------------------
    // Summary:
    //        ȡ�õ�ǰҳ���ı���For TTS��
    //-------------------------------------------
    virtual string GetCurrentPageText() = 0;

    //-------------------------------------------
    // Summary:
    //        ��ת�����������ƶ�ҳ
    //-------------------------------------------
    virtual int MoveToFlowPosition(const DK_FLOWPOSITION &_pos) = 0;

    //-------------------------------------------
    // Summary:
    //        ��ת��ָ����Ŀ¼
    //-------------------------------------------
    virtual int MoveToTOC(DK_TOCINFO* pCurToc)
    {
        if(pCurToc)
        {
            return MoveToFlowPosition(pCurToc->GetBeginPos());
        }
        return BOOKREADER_GOTOPAGE_FAIL;
    }

    //-------------------------------------------
    // Summary:
    //        ȡ�ø��������ؼ��ֵ���������ı���
    //    [in] _clsStartPos ������ʼ��ƫ�ƣ�����������
    //    [in] _strSearchText ���������ַ���
    //    [out] _uHighLightenStartPos _strSearchText�ڷ��ؽ�����е���ʼλ�ã����������ؼ����ڽ���еĸ�����ʾ��
    //    [out] _uHighLightenEndPos _strSearchText�ڷ��ؽ�����еĽ���λ�ã����������ؼ����ڽ���еĸ�����ʾ��
    //    [return] �����ؼ����ڸ���ʼλ�õ��������
    //-------------------------------------------
    virtual string GetText(const ATOM & _clsStartPos, const string _strSearchText, unsigned int & _uHighLightenStartPos, unsigned int & _uHighLightenEndPos) = 0;

    //-------------------------------------------
    // Summary:
    //        ȡ�õ�ǰ��ʾ���ݵ�������������Ϊ���������
    //        text mobi ������������û��chapterIndex ֵ��
    //-------------------------------------------
    virtual bool GetCurrentPageATOM(ATOM & beginATOM, ATOM& endATOM) = 0;


    //-------------------------------------------
    // Summary:
    //       ��ȡdkx �ļ��е�readingData
    //-------------------------------------------
    //virtual bool GetAllBookmarksForUpgrade(DKXBlock* curDKXBlock, vector<ICT_ReadingDataItem *>* vBookmarks) = 0;

    //-------------------------------------------
    // Summary:
    //       
    //-------------------------------------------
    virtual bool GetDKXProgressForUpgrade(DKXBlock* curDKXBlock, ICT_ReadingDataItem* localReadingDataItem) = 0;

    virtual bool ProcessCloudBookmarks(ReadingBookInfo& bookInfo) = 0;

    virtual bool ProcessCloudDKXProgress(ICT_ReadingDataItem* localReadingDataItem) = 0;

    //-------------------------------------------
    // Summary:
    //        ��������
    //-------------------------------------------
    virtual bool SearchInCurrentBook(const string& _strText, const DK_FLOWPOSITION& _startPos, const int& _iMaxResultCount, SEARCH_RESULT_DATA* _pSearchResultData, unsigned int* _puResultCount) = 0;

    //-------------------------------------------
    // Summary:
    //        �ж���ʽ�����Ƿ��ڵ�ǰҳ
    //-------------------------------------------
    virtual bool IsPositionInCurrentPage(const DK_FLOWPOSITION &_pos) = 0;

    //-------------------------------------------
    // Summary:
    //        ��ȡ��������ҳ��
    //-------------------------------------------
    virtual long GetTotalPageNumber() const = 0;

    //-------------------------------------------
    // Summary:
    //        ��ȡ��������ҳ��
    //-------------------------------------------
    virtual long GetPageNumber4CurrentChapter() = 0;

    //-------------------------------------------
    // Summary:
    //        ���ͼƬԤ������
    // ��ʵ�ֹ��ܣ�
    //      ����ʵ��ҳ����ת����
    //-------------------------------------------
    virtual bool AddBMPProcessor(IBMPProcessor* _pProcessor) = 0;

    //-------------------------------------------
    // Summary:
    //        ɾ��ͼƬԤ������
    // ��ʵ�ֹ��ܣ�
    //      ����ʵ��ҳ����ת����
    //-------------------------------------------
    virtual bool RemoveBMPProcessor(IBMPProcessor* _pProcessor) = 0;

    //-------------------------------------------
    // Summary:
    //        ö��ͼƬԤ������
    // ��ʵ�ֹ��ܣ�
    //      ����ʵ��ҳ����ת����
    //-------------------------------------------
    virtual bool GetAllBMPProcessor(std::vector<IBMPProcessor*> &_ProcessorList) = 0;

    //-------------------------------------------
    // Summary:
    //        �����Ű����
    //-------------------------------------------
    virtual bool SetLayoutSettings(const DK_LAYOUTSETTING &_clsLayoutSetting) = 0;
    //-------------------------------------------
    // Summary:
    //        Ŀǰ�����reader��֪���Ű������Ƿ񱻸ı䣬�����Ҫ�ṩ�ӿڹ��ⲿ����
    //-------------------------------------------
    virtual void SetFontChange(const bool bFontChange) = 0;
    //-------------------------------------------
    // Summary:
    //        ȡ����ǰҳ����ȾBMP���
    // ��ʵ�ֹ��ܣ�
    //      ���нӿڣ��ɸ�����ʽ֧��ȥ��� cache
    //-------------------------------------------
    virtual DK_IMAGE* GetPageBMP() = 0;

    //-------------------------------------------
    // Summary:
    //        ��ȡ��ǰ�Ľ���״̬
    //-------------------------------------------
    virtual BOOKREADER_PARSE_STATUS GetParseStatus() = 0;

    //-------------------------------------------
    // Summary:
    //        ����PDF�Ķ�ģʽ
    //-------------------------------------------
    virtual bool SetPdfModeController(const PdfModeController* pPdfModeCtl) = 0;

    //-------------------------------------------
    // Summary:
    //        ��ȡPDF�Ķ�ģʽ
    //-------------------------------------------
    virtual const PdfModeController* GetPdfModeController() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ���鵱ǰҳ�Ĺ�������
    //-------------------------------------------
    virtual BookTextController* GetBookTextControlerOfCurPage() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��DKX�ж�ȡ��ǰ�Ķ���Ϣ: �����/��ժ/��ǩ
    //-------------------------------------------
    virtual bool GotoBookMark(const ICT_ReadingDataItem* _pReadingEntry) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ӵ�ǰ�Ķ������ȡ�Ķ����ȣ�����ǩ��ʽ���ء����ⲿ�����߸����ͷŷ��ض�����ڴ棬�����Ķ����ȴ���DKX
    //      text mobi ������������û��chapterIndex ֵ��
    //-------------------------------------------
    virtual ICT_ReadingDataItem* GetCurPageProgress() = 0;


    //-------------------------------------------
    //  Summary:
    //      ����������Ⱦ��ɫ
    //-------------------------------------------
    virtual bool SetTextGrayScaleLevel(double _dGamma) = 0;

    //-------------------------------------------
    //  Summary:
    //      ����������Ⱦ��ʽ(ƽ������)
    //-------------------------------------------
    virtual bool SetFontSmoothType(DK_FONT_SMOOTH_TYPE _eFontSmoothType) =0;

    //-------------------------------------------
    //  Summary:
    //      ����������Ⱦ��ɫ
    //-------------------------------------------
    virtual bool SetGraphicsGrayScaleLevel(double _dGamma) = 0;

    //-------------------------------------------
    //  Summary:
    //      �����Ƿ���м���ת����
    //-------------------------------------------
    virtual bool SetFamiliarToTraditional(bool toTraditional) = 0;

    //-------------------------------------------
    //  Summary:
    //      �����Ƿ�Ϊ˲��
    //-------------------------------------------
    virtual bool SetInstantTurnPageModel(bool _bIsInstant) = 0;

    //-------------------------------------------
    //  Summary:
    //      �������������������Ƿ���Ҫ��дdkx
    //-------------------------------------------
    virtual bool UpdateReadingData(
        const char* oldBookRevision,
        const std::vector<ICT_ReadingDataItem *> *_pvOld,
        const char* newBookRevision,
        std::vector<ICT_ReadingDataItem *> *_pvNew) = 0;

    //-------------------------------------------
    //  Summary:
    //      ������ct_refpos,����ֻ��flow position,û��offset�����offset
    //-------------------------------------------
    virtual void CompletePosRange(CT_RefPos* startPos, CT_RefPos* endPos) = 0;

    virtual PAGE_PROGRESS_DISPLAY_MODE GetPageProgressDisplayMode() const = 0;

    static IBookReader* CreateBookReaderFromFormat(DkFileFormat fileFormat);

    virtual BOOK_INFO_DATA GetBookInfo()
    {
        return BOOK_INFO_DATA(); 
    }

    //-------------------------------------------
    //  Summary:
    //      �����������������Ӧȫ�ĵİٷֱȣ�δ�����귵��-1
    //-------------------------------------------
    virtual double GetPercent(const CT_RefPos& startPos) = 0;

    //
    //-------------------------------------------
    //  Summary:
    //      �����������������Ӧȫ�ĵ�ҳ��,��0��ʼ��δ�����귵��-1
    //-------------------------------------------
    virtual long GetPageIndex(const CT_RefPos& startPos)
    {
        return -1;
    }

	//-------------------------------------------
    //  Summary:
    //      ����ҳ�룬���ظ�ҳ����ʼλ�õ���������
    //-------------------------------------------
    virtual bool GetPosByPageIndex(int pageIndex, DK_FLOWPOSITION* pos)
    {
        return false;
    }

    //-------------------------------------------
    //  Summary:
    //      �����½����������ظ��½ڵ�title
    //-------------------------------------------
    virtual string GetChapterTitle(const DK_FLOWPOSITION& posChapter, DKXBlock* curDKXBlock = NULL)
    {
        return "";
    }

    //-------------------------------------------
    //  Summary:
    //      ���������������½�λ�ã�������Ҫ�½ڵ�Ŀ¼��Ϣ
    //-------------------------------------------
    virtual const DK_TOCINFO* GetChapterInfo(const DK_FLOWPOSITION& posPage, CHAPTER_POSITION_MODE positionMode, DKXBlock* curDKXBlock = NULL) = 0;


    //-------------------------------------------
    //  Summary:
    //      ��ȡ�ļ��汾��
    //-------------------------------------------
    virtual std::string GetBookRevision()
    {
        return "";
    }
    //
    //-------------------------------------------
    //  Summary:
    //      ��ȡ�ļ�id
    //-------------------------------------------
    virtual std::string GetBookId()
    {
        return "";
    }

    //-------------------------------------------
    //  Summary:
    //      �Ƿ����ѹ���Ķ࿴�鼮
    //-------------------------------------------
    virtual bool IsPurchasedDuoKanBook()
    {
        return false;
    }

    //-------------------------------------------
    //  Summary:
    //      ��ȡ�鼮�Ű淽��
    //-------------------------------------------
    virtual BOOK_DIRECTION_TYPE GetBookDirection() const
    {
        return BOOK_MODE_HTB_DIRECTION_LTR;
    }

    //-------------------------------------------
    //  Summary:
    //      �Ƿ��Ӧ�½��������½�
    //-------------------------------------------
    virtual bool IsComicsChapter(long chapterIndex) const
    {
        return false;
    }

    virtual bool SetComicsFrameMode(bool comicsFrame, long frameIndex = -1)
    {
        return true;
    }
    virtual bool IsComicsFrameMode() const
    {
        return false;
    }

    virtual bool GotoNextFrameInGallery(const DK_POS& pos) { return false; }
    virtual bool GotoPreFrameInGallery(const DK_POS& pos) { return false; }

    virtual bool IsFirstPageInChapter() { return false; }
    virtual bool IsLastPageInChapter() { return false; }
};

#endif

