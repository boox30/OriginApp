//===========================================================================
// Summary:
//	    DKEEPUBDef.h
// Usage:
//      ����EPUB�ڽ���������ʹ�õ���һЩö�ٻ�ṹ��
//  		...
// Remarks:
//	    Null
// Date:
//	    2011-09-21
// Author:
//	    Zhang Jiafang(zhangjf@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_DKEEPUBDEF_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_DKEEPUBDEF_H__

#include "KernelRenderType.h"
#include "KernelType.h"
#include "RichTextString.h"

class IDKEFlexPage;
class IDKESection;

// EPUB����������
enum DKE_CONTAINER_TYPE
{
    DKE_CONTAINER_FOLDER,           // �ļ�ϵͳĿ¼����
    DKE_CONTAINER_ZIP,              // ZIP�鵵����
    DKE_CONTAINER_UNKNOWN           // δ֪������
};

// HTML�ķ������
enum DKE_HTMLSTYLE_TYPE
{
    DKE_HTMLSTYLE_STANDARD,         // ��׼��HTML���
    DKE_HTMLSTYLE_MOBI              // MOBI�Ƶ�ʹ������������ǩ��HTML���
};

// ePub metadata�еĽ�ɫ��opf:role��
enum DKE_METAROLE_TYPE
{
    DKE_METAROLE_UNKNOWN = -1,
    DKE_METAROLE_EDT,
    DKE_METAROLE_TRL,
    DKE_METAROLE_COUNT
};

// EPUB�ļ��Ļ�����Ϣ
struct DKEBOOKINFO
{
    DK_WCHAR* pTitle;
    DK_WCHAR* pIdentifierID;
	DK_WCHAR* pIdentifierSchema;
    DK_WCHAR* pIdentifier;
    DK_WCHAR* pLanguage;
    DK_WCHAR* pCreator;
	DK_WCHAR* pAuthor;
    DK_WCHAR* pSubject;
	DK_WCHAR* pPublisher;
	DK_WCHAR* pDescription;
	DK_WCHAR* pCoverage;
	DK_WCHAR* pSource;
	DK_WCHAR* pDate;
	DK_WCHAR* pRights;
	DK_WCHAR* pContributor;
	DK_WCHAR* pTypeStr;
	DK_WCHAR* pFormat;
	DK_WCHAR* pRelation;
	DK_WCHAR* pBuilder;
	DK_WCHAR* pBuilderVersion;

    // ͨ��ö��DKE_METAROLE_TYPE����ȡÿ��role��ֵ
    DK_WCHAR* pRoles[DKE_METAROLE_COUNT];

    DKEBOOKINFO()
        : pTitle(DK_NULL)
        , pIdentifierID(DK_NULL)
        , pIdentifierSchema(DK_NULL)
        , pIdentifier(DK_NULL)
        , pLanguage(DK_NULL)
        , pCreator(DK_NULL)
        , pAuthor(DK_NULL)
        , pSubject(DK_NULL)
        , pPublisher(DK_NULL)
        , pDescription(DK_NULL)
        , pCoverage(DK_NULL)
        , pSource(DK_NULL)
        , pDate(DK_NULL)
        , pRights(DK_NULL)
        , pContributor(DK_NULL)
        , pTypeStr(DK_NULL)
        , pFormat(DK_NULL)
        , pRelation(DK_NULL)
        , pBuilder(DK_NULL)
        , pBuilderVersion(DK_NULL)
    {
        DkZero(pRoles);
    }
};

struct DKE_DRMKEY
{
    DK_BYTE* key;
    DK_UINT length;

    DKE_DRMKEY() 
        : key(DK_NULL)
        , length(0)
    {
        // do nothing
    }
};

enum DKE_PAGEOBJ_TYPE
{
    DKE_PAGEOBJ_UNKNOWN = 0,
    DKE_PAGEOBJ_TEXT,                   // ���֣�ԭ�Ӷ���
    DKE_PAGEOBJ_IMAGE,                  // ��ͨͼ��ԭ�Ӷ���
    DKE_PAGEOBJ_STATICIMAGE,            // ��̬ͼ��ԭ�Ӷ���
    DKE_PAGEOBJ_FOOTNOTE,               // ��ע��ԭ�Ӷ���
    DKE_PAGEOBJ_INTERACTIVEIMAGE,       // �ɽ���ͼ��ԭ�Ӷ���
    DKE_PAGEOBJ_CROSSPAGE,              // ��ҳͼ��ԭ�Ӷ���
    DKE_PAGEOBJ_GALLERY,                // ���ȣ�ԭ�Ӿۺ϶���
    DKE_PAGEOBJ_GRAPH,                  // ͼ�Σ�ԭ�Ӷ���
    DKE_PAGEOBJ_PATH,                   // ·����ԭ�Ӷ���
    DKE_PAGEOBJ_INVISIBLE,              // ���ض���ԭ�Ӷ���
    DKE_PAGEOBJ_BLOCK,                  // �����ԭ�Ӿۺ϶���
    DKE_PAGEOBJ_TABLE,                  // ������ԭ�Ӿۺ϶���
    DKE_PAGEOBJ_VIDEO,                  // ��Ƶ����ԭ�Ӷ���
    DKE_PAGEOBJ_AUDIO,                  // ��Ƶ����ԭ�Ӷ���
    DKE_PAGEOBJ_BGIMAGE,                // ����ͼ��ԭ�Ӷ���
    DKE_PAGEOBJ_PREBLOCK,               // PRE�����ԭ�Ӿۺ϶���
    DKE_PAGEOBJ_IMAGEBLOCK              // �࿴��չͼ��飨ԭ�Ӿۺ϶���
};


enum DKE_IMAGEBLOCK_TYPE
{
    DKE_IMAGEBLOCK_UNKNOWN = 0,
    DKE_IMAGEBLOCK_STATIC,              // ��̬ͼ��Ӧ��ͼ���
    DKE_IMAGEBLOCK_SINGLE,              // ����ͼ��Ӧ��ͼ��� 
    DKE_IMAGEBLOCK_CROSSPAGE,           // ��ҳͼ��Ӧ��ͼ���
    DKE_IMAGEBLOCK_MULTICALLOUT         // ��㽻��ͼ��Ӧ��ͼ���
};

struct DKE_HITTEST_STREAMINGMEDIA_INFO
{
    DKSTREAMINFO* pSrcData;             // ����Ƶ��ԭʼ���ݡ��������������Ƶ��pSrcDataΪ��
    DK_WCHAR* pSrcURL;                  // ����ƵURL
    DK_MIME_TYPE type;                  // MIME ����Ƶ����
};

enum DKE_TRACK_KIND
{
    DKE_TRACK_KIND_UNKNOWN = 0,
    DKE_TRACK_KIND_SUBTITLES,
    DKE_TRACK_KIND_CAPTIONS,
    DKE_TRACK_KIND_DESCRIPTIONS,
    DKE_TRACK_KIND_CHAPTERS,
    DKE_TRACK_KIND_METADATA,
};

// ��Ļ��Ϣ
struct DKE_TRACK_INFO
{
    DKE_TRACK_KIND kind;
    DKSTREAMINFO* pSrcData;
    DK_WCHAR* pSrc;
    DK_LANG_CODE srcLang;
    DK_WCHAR* pLabel;
    DK_BOOL trackDefault;

    DKE_TRACK_INFO()
        : kind(DKE_TRACK_KIND_UNKNOWN),
          srcLang(DK_LANG_UNKNOWN),
          trackDefault(DK_FALSE)
    {
        // do nothing
    }
};

enum DKE_MEDIA_PRELOAD_TYPE
{
    DKE_MEDIA_PRELOAD_AUTO,          // Indicates that the audio/video should start loading as soon as the page loads
    DKE_MEDIA_PRELOAD_METADATA,      // Indicates that only the metadata for the audio/video should be loaded when the page loads
    DKE_MEDIA_PRELOAD_NONE           // Indicates that the audio/video should NOT start loading as soon as the page loads
};

struct DKE_SMIL_PAR_INFO
{
    DK_FLOAT clipBegin;             // audio begin
    DK_FLOAT clipEnd;               // audio end
    DK_WCHAR* textURL;              // text URL
    DK_WCHAR* textAnchor;           // text anchor
    DK_WCHAR* audioURL;             // audio URL

    DKE_SMIL_PAR_INFO()
        : clipBegin(0.0), clipEnd(0.0), textURL(DK_NULL), textAnchor(DK_NULL), audioURL(DK_NULL)
    {}
};

struct DKE_HITTEST_MEDIA_INFO
{
    DKE_HITTEST_STREAMINGMEDIA_INFO* pSources;              // ����Ƶ����Դ���飬��ҳ�е�����Ƶ��ǩ����ָ���������Դ
    DK_UINT sourcesCount;                                   // pSources ����Ԫ�ظ���

    DKE_TRACK_INFO* pTracks;                                // ��Ļ���ݣ���ҳ�е�����Ƶ��ǩ����ָ�������Ļ
    DK_UINT tracksCount;                                    // pTracks ����Ԫ�ظ���

    DK_BOOL autoplay;                                       // �Ƿ��Զ�����
    DK_BOOL controls;                                       // �Ƿ���ʾ�����ݶ��Ȱ�ť
    DK_BOOL loop;                                           // �Ƿ�ѭ������
    DK_BOOL muted;                                          // �Ƿ���
    DKE_MEDIA_PRELOAD_TYPE preloadType;
    DK_WCHAR* pMediaGroup;
    DK_WCHAR* pTitle;                                       // �࿴��չ��Ƶ�ڵ�ı���

    DKFILEINFO* pPoster;                                    // չλͼ���ļ�����
    DKFILEINFO* pActiveState;                               // ��Ƶ�ڻ״̬�µ�ռλͼ����

    DKE_HITTEST_MEDIA_INFO()
        : pSources(DK_NULL)
        , sourcesCount(0)
        , pTracks(DK_NULL)
        , tracksCount(0)
        , autoplay(DK_FALSE)
        , controls(DK_FALSE)
        , loop(DK_FALSE)
        , muted(DK_FALSE)
        , preloadType(DKE_MEDIA_PRELOAD_AUTO)
        , pMediaGroup(DK_NULL)
        , pTitle(DK_NULL)
        , pPoster(DK_NULL)
        , pActiveState(DK_NULL)
    {
        // do nothing
    }
};

struct DKE_HITTEST_OBJECTINFO
{
    DKE_PAGEOBJ_TYPE objType;           // ��������
    DK_BOX boundingBox;                 // ��Ӿ���
    DK_MATRIX transformMatrix;          // �任����
    DK_BOX clipBox;                     // �ü�����������ʱ��ֵ����ͼ������    
    
    union
    {
        DK_WCHAR *altText;              // �� objType Ϊ DKE_PAGEOBJ_FOOTNOTE ʱ��Ч

        // �� objType Ϊ DKE_PAGEOBJ_STATICIMAGE �� DKE_PAGEOBJ_INTERACTIVEIMAGE �� DKE_PAGEOBJ_CROSSPAGE ʱ��Ч
        struct
        {
            DKFILEINFO* srcImageData;           // ͼƬ��ԭʼ����
            DKFILEINFO* extImageData;           // @Deprecated
            DK_WCHAR* srcImagePath;				// ͼƬ��EPUB���ڵ�ȫ·��
            DK_UINT srcImageWidth;              // ͼƬ�Ŀ��
            DK_UINT srcImageHeight;             // ͼƬ�ĸ߶�
            RichTextString* mainTitle;          // ͼƬ��ͼע�����⣬û����Ϊ��
            RichTextString* subTitle;           // ͼƬ��ͼע�����⣬û����Ϊ��
        };

        // �� objType Ϊ DKE_PAGEOBJ_VIDEO �� DKE_PAGEOBJ_AUDIO ʱ��Ч
        DKE_HITTEST_MEDIA_INFO* pMedia;
    };

    DKE_HITTEST_OBJECTINFO()
        : objType(DKE_PAGEOBJ_UNKNOWN)
        , srcImageData(DK_NULL)
        , extImageData(DK_NULL)
		, srcImagePath(DK_NULL)
        , srcImageWidth(0)
        , srcImageHeight(0)
        , mainTitle(DK_NULL)
        , subTitle(DK_NULL)
    {
        // do nothing
    }
};

struct DKE_CHAR_INFO
{
    DK_BOX boundingBox;                 // ��Ӿ���
    DK_WCHAR charCode;                  // ���ֵ� Unicode ����
    DK_FLOWPOSITION pos;                // ���ֵ�����λ��

    DKE_CHAR_INFO()
        : charCode(0)
    {
        // do nothing
    }
};

enum DKE_SHOWCONTENT_TYPE
{
    DKE_SHOWCONTENT_FLEXPAGE,           // �Կ�������ҳչʾ����
    DKE_SHOWCONTENT_FIXEDPAGE           // �Թ̶�ҳ��ҳ����ʽչʾ����
};

union DKE_SHOWCONTENT_HANDLE
{
    IDKEFlexPage* pFlexPage;            // �������DKE_SHOWCONTENT_TYPEΪDKE_SHOWCONTENT_FLEXPAGEʱ���Ϊ������ҳ
    IDKESection* pSection;              // �������DKE_SHOWCONTENT_TYPEΪDKE_SHOWCONTENT_FIXEDPAGEʱ���Ϊ�ɷ�ҳ��HTMLƬ��
};

enum DKE_FOOTNOTECONTENT_TYPE
{
    DKE_FOOTNOTECONTENT_ALTTEXT,
    DKE_FOOTNOTECONTENT_RICHTEXT
};

struct DKE_FOOTNOTE_INFO
{
    DK_BOX boundingBox;                     // ��Ӿ���
    DKE_FOOTNOTECONTENT_TYPE noteType;      // ��ע���ݵ�����

    union
    {
        DK_WCHAR* noteText;                 // ע���ı�����noteTypeΪDKE_FOOTNOTECONTENT_ALTTEXTʱ��Ч
        DK_WCHAR* noteId;                   // ���ı�ע��ָ���ID������ͨ����ID��ȡչʾ���ı��ľ������noteTypeΪDKE_FOOTNOTECONTENT_RICHTEXTʱ��Ч
    };

    DKFILEINFO* srcImageData;           // ͼƬ��ԭʼ����
    DK_WCHAR* srcImagePath;				// ͼƬ��EPUB���ڵ�ȫ·��

    DKE_FOOTNOTE_INFO()
        : noteType(DKE_FOOTNOTECONTENT_ALTTEXT)
        , noteText(DK_NULL)
        , srcImageData(DK_NULL)
        , srcImagePath(DK_NULL)
    {
        // do nothing
    }
};

struct DKE_PREBLOCK_INFO
{
    DK_BOX boundingBox;                     // pre����ҳ���ڵ���Ӿ���
    DK_FLOWPOSITION startPos;               // pre����ҳ���ڵ���ʼ��ʽ����
    DK_FLOWPOSITION endPos;                 // pre����ҳ���ڵĽ�����ʽ����
    DK_DOUBLE maxPreWidth;                  // pre�������õ��Ű�����µ�����ȣ��Ű�����ı��Ǵ�ֵ��Ч
    IDKEFlexPage* pPreFlexPage;             // pre���Ӧ�Ŀ�����ҳ

    DKE_PREBLOCK_INFO()
        : maxPreWidth(0)
        , pPreFlexPage(DK_NULL)
    {
        // do nothing
    }
};

struct DKE_CALLOUT_INFO
{
    DK_DOUBLE imageScale;               // ������ͼƬ�����ű�
    DK_POS position;                    // callout��������ĵ���ԭͼ�ϵ�����
    DK_POS target;                      // ָʾĿ����ԭͼ�ϵ�����
    DK_INT width;                       // callout����Ŀ��
    DK_INT maxHeight;                   // callout����������

    DKE_CALLOUT_INFO()
        : imageScale(1.0)
        , width(0)
        , maxHeight(0)
    {
        // do nothing
    }
};

class IDKEMultiCallout;

struct DKE_IMAGEBLOCK_INFO
{
    DKE_IMAGEBLOCK_TYPE imgBlockType;               // ͼƬ�������

    union
    {
        IDKEMultiCallout* pMultiCallout;            // ��㽻��ͼ��Ϣ��imgBlockType==DKE_IMAGEBLOCK_MULTICALLOUTʱ��Ч
        // TODO: �������ͼƬ����չ
    };

    DKE_IMAGEBLOCK_INFO()
        : imgBlockType(DKE_IMAGEBLOCK_UNKNOWN)
        , pMultiCallout(DK_NULL)
    {
        // do nothing
    }
};

// the type of the chapter
enum DKE_CHAPTER_TYPE
{
    DKE_CHAPTER_UNKNOWN,
    DKE_CHAPTER_NORMAL,
    DKE_CHAPTER_FULLSCREEN,
    DKE_CHAPTER_FITWINDOW
};

enum DKE_LINK_TYPE
{
    DKE_LINK_UNKNOWN,
    DKE_LINK_URL,
    DKE_LINK_FILEPOS
};

struct DKE_LINK_INFO
{
    DKE_LINK_TYPE linkType;         // ���ӵ�����
    union
    {
        struct
        {
            DK_WCHAR* linkTarget;           // ��linkTypeΪDKE_LINK_URLʱ, linkTargetΪ����URL
            DK_WCHAR* linkAnchor;           // ��linkTypeΪDKE_LINK_URLʱ, linkAnchorΪê������
        };
                                        
        DK_UINT filePos;                    // ��linkTypeΪDKE_LINK_FILEPOSʱ��filePosΪ�ļ��ڲ�ƫ����
    };

    // ���¿�ʼ�����Ϊ����ҿ�����
    DK_FLOWPOSITION startPos;       // ���Ӷ�Ӧ��ҳ��Ԫ�ص���ʼ����
    DK_FLOWPOSITION endPos;         // ���Ӷ�Ӧ��ҳ��Ԫ�صĽ�������

    DKE_LINK_INFO()
        : linkType(DKE_LINK_UNKNOWN)
        , linkTarget(DK_NULL)
        , linkAnchor(DK_NULL)
    {
        // do nothing
    }
};

// �������ķ�ҳģʽ
enum DKE_PARSER_PAGETABLEMODE
{
    DKE_PARSER_PAGETABLE_BOOK,      // ��Ҫ����������з�ҳ
    DKE_PARSER_PAGETABLE_CHAPTER,   // ��Ҫ��ĳ�½ڽ��з�ҳ
    DKE_PARSER_PAGETABLE_BUILTIN    // ��ҳ����������
};

// ��ҳ���������ɻ���
struct DKE_PAGEBREAK_ENV
{
    DK_UINT         pageWidth;      // ҳ��������
    DK_UINT         pageHeight;     // ҳ������߶�
    DK_DOUBLE       bodyFontSize;   // �����ֺ�
};

// ���ݽ�����ѡ�����
struct DKE_PARSER_OPTION
{
    DK_BOX                      pageBox;            // ҳ������
    DK_BOX                      paddingBox;         // ҳ����padding����
    DK_MEASURE_TYPE             msType;             // ������λ���μ� DK_MEASURE_TYPE ö��ֵ˵����
    DK_LONG                     dpi;                // ����豸��DPIֵ���� msType = DK_MEASURE_PIXEL ʱ��Ч��

    DKE_PARSER_PAGETABLEMODE    ptMode;             // ��ҳģʽ���μ� DKE_PARSER_PAGETABLEMODE ö��ֵ˵����
    DK_LONG                     chapter;            // ��ʼ�½��������� 0 ��ʼ���� ptMode = DKE_PARSER_PAGETABLE_CHAPTER ʱ��Ч��
    const DK_WCHAR*             ptFilePath;         // ���÷�ҳ�������ļ�·������ ptMode = DKE_PARSER_PAGETABLE_BUILTIN ʱ��Ч��

    DKE_PARSER_OPTION() : msType(DK_MEASURE_PIXEL),
                          dpi(RenderConst::SCREEN_DPI),
                          ptMode(DKE_PARSER_PAGETABLE_BOOK),
                          chapter(0),
                          ptFilePath(DK_NULL)
    {}
};

enum DKE_BOOKCONTENT_TYPE
{
    DKE_BOOKCONTENT_UNKNOWN,
    DKE_BOOKCONTENT_RELEASE,
    DKE_BOOKCONTENT_TRIAL
};

enum DKE_SELECTION_MODE
{
    DKE_SELECTION_UNKNOWN,
    DKE_SELECTION_MIDDLECROSS,                      // �������Խ������ʱ��ѡ�е�ǰ���� 
    DKE_SELECTION_INTERCROSS,                       // �������뵱ǰ���н���ʱ��ѡ�е�ǰ����
    DKE_SELECTION_INTERCROSS_WORD                   // ��������뵱ǰ���н���ʱ��ѡ�а�����ǰ�����ڵĴ�
};

enum DKE_HITTEST_TEXT_MODE
{
    DKE_HITTEST_TEXT_UNKNOWN,
    DKE_HITTEST_TEXT_SENTENCE,                      // �������ı���ʽ HitTest ҳ������
    DKE_HITTEST_TEXT_WORD                           // ���ı��ִʷ�ʽ HitTest ҳ������
};

struct DKE_CSS_ERROR
{
    DK_WCHAR* pFilePath;                            // �������ڵ�CSS�ļ�
    DK_UINT lineNum;                                // �������ļ��ڵ��к�
    DK_UINT columnNum;                              // ���������ڵ��к�
    DK_WCHAR* pErrorMsg;                            // ������Ϣ

    DKE_CSS_ERROR()
        : pFilePath(DK_NULL)
        , lineNum(0)
        , columnNum(0)
        , pErrorMsg(DK_NULL)
    {
        // do nothing
    }
};

enum DKE_FOLLOWELEM_TYPE
{
    DKE_FOLLOWELEM_UNKNOWN = 0,
    DKE_FOLLOWELEM_IMAGE,               // ����ͼ
    DKE_FOLLOWELEM_DUOKAN_FOOTNOTE,     // �࿴��չ������ע
    DKE_FOLLOWELEM_AUDIO                // ������Ƶ
};

struct DKE_FOLLOWELEM_INFO
{
    DKE_FOLLOWELEM_TYPE type;           // ����Ԫ������
    DK_UINT offsetInTextContent;        // ����Ԫ���������ı��е�λ��

    DK_WCHAR* pAltText;                 // ����ͼ��alt�ı�

    DKE_FOLLOWELEM_INFO()
        : type(DKE_FOLLOWELEM_UNKNOWN),
          offsetInTextContent(0),
          pAltText(DK_NULL)
    {
        // do nothing
    }
};

struct DKE_TEXT_CONTENT_INFO
{
    DK_WCHAR* pTextContent;                     // ���ĵ��л�ȡ���ı�
    DKE_FOLLOWELEM_INFO* pFollowElemInfo;       // ԭ�ĵ��ı� pTextContent ֮�����������Ԫ�أ�������ͼ������
    DK_UINT followElemInfoCount;                // ����Ԫ��������Ԫ�ظ���

    DKE_TEXT_CONTENT_INFO()
        : pTextContent(DK_NULL),
          pFollowElemInfo(DK_NULL),
          followElemInfoCount(0)
    {
        // do nothing
    }
};

enum DKE_WRITING_MODE_TYPE
{
    DKE_WRITING_MODE_HTB,   // horizontal-tb
    DKE_WRITING_MODE_VRL,   // vertical-rl
    DKE_WRITING_MODE_VLR    // vertical-lr
};

enum DKE_WRITING_DIRECTION_TYPE
{
    DKE_WRITING_DIRECTION_LTR,  // ltr
    DKE_WRITING_DIRECTION_RTL   // rtl
};

struct DKEWRITINGOPT
{
    DKE_WRITING_MODE_TYPE writingMode;
    DKE_WRITING_DIRECTION_TYPE writingDirection;

    DKEWRITINGOPT()
        : writingMode(DKE_WRITING_MODE_HTB), writingDirection(DKE_WRITING_DIRECTION_LTR)
    {}
};

enum DKE_BOOKLAYOUT_TYPE
{
    DKE_BOOKLAYOUT_REFLOW,
    DKE_BOOKLAYOUT_FIXED_PAGE,
    DKE_BOOKLAYOUT_COMICS_FRAME
};

enum DKE_ORIENTATIONLOCK_TYPE
{
    DKE_ORIENTATIONLOCK_NONE,
    DKE_ORIENTATIONLOCK_LANDSCAPE_ONLY,
    DKE_ORIENTATIONLOCK_PORTRAIT_ONLY
};

struct DKEDISPLAYOPT
{
    DKE_BOOKLAYOUT_TYPE layout;                 // ҳ���Ű淽ʽ
    DKE_ORIENTATIONLOCK_TYPE orinentationLock;  // ��Ļ������������
    DK_BOOL bOpenToSpread;                      // �Ƿ��Ƕ�ҳģʽ
    DK_BOOL bFirstOnRight;                      // ��bOpenToSpreadΪtrue����ҳģʽ����Ч

    DKEDISPLAYOPT()
        : layout(DKE_BOOKLAYOUT_REFLOW)
        , orinentationLock(DKE_ORIENTATIONLOCK_NONE)
        , bOpenToSpread(DK_FALSE)
        , bFirstOnRight(DK_TRUE)
    {
        // do nothing
    }
};

struct DKEOPFManifestItem
{
    DK_WCHAR* pItemId;                  // manifest���ID��ʶ�������½ڼ�Ϊchapter ID
    DK_WCHAR* pFullPath;                // ��ePub container�е�ȫ·��

    DKEOPFManifestItem()
        : pItemId(DK_NULL)
        , pFullPath(DK_NULL)
    {
        // do nothing
    }
};

struct DKEOPFData
{
    DK_WCHAR* pDuokanBookId;                // duokan book id
    DKEOPFManifestItem* pManifest;          // manifest���ݵ�����
    DK_INT manifestItemCount;               // manifest��������Ĵ�С
    DK_WCHAR** pSpine;                      // spine���ݣ��洢�����½�ָ���manifest item id�������Ķ�����
    DK_INT spineItemCount;                  // spine����Ĵ�С  

    DKEOPFData()
        : pDuokanBookId(DK_NULL)
        , pManifest(DK_NULL)
        , manifestItemCount(0)
        , pSpine(DK_NULL)
        , spineItemCount(0)
    {
        // do nothing
    }
};

struct DKEEncryptionData
{
    DK_WCHAR* pCipherData;                    // ���ڱ��ؼ���ʱ��ȡAES��Կ���ַ���
    DK_WCHAR** pEncryptedFiles;               // �����Ѽ����ļ���ePub container�е�ȫ·��
    DK_INT encryptedFileCount;                // �Ѽ��ܵ��ļ���

    DKEEncryptionData()
        : pCipherData(DK_NULL)
        , pEncryptedFiles(DK_NULL)
        , encryptedFileCount(0)
    {
        // do nothing
    }
};

struct DKEExtensionData
{
    DK_WCHAR* pExtensionVersion;            // extension �汾��
    DKEWRITINGOPT writingOpt;               // ���ķ�ʽ
    DKEDISPLAYOPT displayOpt;               // �鼮չ�ַ�ʽ

    DKEExtensionData()
        : pExtensionVersion(DK_NULL)
    {
        // do nothing
    }
};

enum DKE_PACK_MODE
{
    DKE_PACK_ENCRYPT_COMPRESS,      // �ȼ�����ѹ��
    DKE_PACK_COMPRESS_ENCRYPT       // ��ѹ���ټ���
};

//===========================================================================

enum DKE_PAGEUNIT_TYPE
{
    DKE_PAGEUNIT_UNSUPPORT,
    DKE_PAGEUNIT_TEXT,
    DKE_PAGEUNIT_FOOTNOTE,
    DKE_PAGEUNIT_IMAGE,
    DKE_PAGEUNIT_PATH,
    DKE_PAGEUNIT_BLOCK
};

struct DKEPageTextInfo
{
    DK_POS          basePos;
    DK_WCHAR        textChar;
    DK_WCHAR*       fontName;
    DK_FLOAT        fontSize;
    DK_FONT_STYLE   fontStyle;
    DK_ARGBCOLOR    fontColor;

    DKEPageTextInfo()
        : textChar(0),
          fontName(DK_NULL)
    {}
};

enum DKE_PAGEATOM_TYPE
{
    DKE_PAGEATOM_TEXT,
    DKE_PAGEATOM_IMAGE,
    DKE_PAGEATOM_PATH
};

enum DKE_PAGEPATHNODE_TYPE
{
    DKE_PAGEPATHNODE_MOVETO,
    DKE_PAGEPATHNODE_LINETO,
    DKE_PAGEPATHNODE_QBEZIER           // ����Bezier����
};

struct DKEPagePathNode
{
    DKE_PAGEPATHNODE_TYPE   nodeType;
    DK_POS                  endPoint;
    DK_POS                  controlPoint;               // ����Bezier���ߵĿ��Ƶ�
};

enum DKE_LINESTYLE_TYPE
{
    DKE_LINESTYLE_DOTTED,
    DKE_LINESTYLE_DASHED,
    DKE_LINESTYLE_SOLID,
    DKE_LINESTYLE_DOUBLE
};

struct DKEPagePathInfo
{
    DKEPagePathNode*    pathNodes;
    DK_UINT             pathNodeCount;
    DK_BOOL             fillPath;
    DK_ARGBCOLOR        fillColor;
    DK_BOOL             strokePath;
    DK_ARGBCOLOR        strokeColor;
    DKE_LINESTYLE_TYPE  lineType;
    DK_FLOAT            lineWidth;

    DKEPagePathInfo()
        : pathNodes(DK_NULL), pathNodeCount(0), lineType(DKE_LINESTYLE_SOLID)
    {}
};

#endif
