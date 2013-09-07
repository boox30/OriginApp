#ifndef __COMMONUI_BOOKTEXTCONTROLLER_H__
#define __COMMONUI_BOOKTEXTCONTROLLER_H__

#include "BookReader/IDKPageAdapter.h"
#include "dkBaseType.h"
#include <vector>

class IDKEGallery;

struct PageObjectInfo
{
    DKE_PAGEOBJ_TYPE m_objectType;
    DK_RECT m_bounding;
    DK_FLOWPOSITION m_objectFlowposition;
};

struct GalleryObjectInfo
{
    DK_RECT m_bounding;
#ifdef KINDLE_FOR_TOUCH
    DK_RECT m_boundingImage;
#endif
    int m_activeCellIndex;
    int m_cellCount;

    GalleryObjectInfo()
        : m_activeCellIndex(0)
        , m_cellCount(0)
    {
        m_bounding.left = m_bounding.top = m_bounding.right = m_bounding.bottom = 0;
#ifdef KINDLE_FOR_TOUCH
        m_boundingImage.left = m_boundingImage.top = m_boundingImage.right = m_boundingImage.bottom = 0;
#endif
    }
};

class BookTextController
{
#ifndef KINDLE_FOR_TOUCH
public:
    enum MoveDirection
    {
        CURSOR_UP, 
        CURSOR_DOWN, 
        CURSOR_LEFT, 
        CURSOR_RIGHT
    };
#endif
public:
    BookTextController();
    virtual ~BookTextController();
    virtual LPCSTR GetClassName() const 
    {
        return "BookTextController";
    }
    
    //-------------------------------------------
    //  Summary:
    //      ��ȡ��ǰҳ��Ĺ������
    //  Remarks:
    //      Ӧ��ÿ��ҳ��Rander���������
    //-------------------------------------------
    template <typename IDKPageTraits>
    bool Initialize(typename IDKPageTraits::BookType *_pBook, typename IDKPageTraits::PageType *_pPage)
    {
        if (NULL == _pPage)
        {
            return false;
        }

        Release();
        m_pPage = new DKPageAdapter<IDKPageTraits>(_pBook, _pPage);
        return InitMember();
    }

    virtual void SetModeController(const PdfModeController* pModeController);

    virtual bool InitMember() = 0;

    // �ͷ�ҳ����ر���
    virtual void Release();
    virtual bool IsInitialized() const;
    // ��������
    virtual bool IsSelectionMode() const;
    virtual void SetSelectionMode(bool selection);
    
    // �������ƫ��
    virtual void SetBasePoint(int left, int top);

    // �ƶ���ҳ��
    virtual bool MoveToBeginOfPage() = 0;
    // �ƶ���ҳβ
    virtual bool MoveToEndOfPage() = 0;
    
    // ѡ�й������ƶ�
    virtual bool Move(int x, int y, bool rightHandler = true) { return false;}

    virtual bool GetSelectionRange(const DK_POS& startPoint, const DK_POS& endPoint, DK_FLOWPOSITION* pStartPos, DK_FLOWPOSITION* pEndPos);
    virtual bool GetSelectionRangeByMode(const DK_POS& startPoint, const DK_POS& endPoint, int selectionMode, DK_FLOWPOSITION* pStartPos, DK_FLOWPOSITION* pEndPos);
    // ��ȡ��ǰҳ��ѡ�п�
    virtual void GetSelectionRectsOfThisPage(std::vector<DK_RECT> *_pvRects);
    
    // ��ȡ�ϴ�Move�������ĵ�ǰҳѡ�п�
    virtual void GetSelectionRectsOfLastMove(std::vector<DK_RECT> *_pvRects);

    // ��ȡѡ�����������
    virtual bool GetSelectionContent(DK_FLOWPOSITION *_pBeginPos, DK_FLOWPOSITION *_pEndPos, std::string& bookComment);

    // ��ȡ��ǰҳ����λ��֮��Ŀ�
    virtual void GetRectsBetweenPos(const DK_FLOWPOSITION &_pos1, const DK_FLOWPOSITION &_pos2, std::vector<DK_RECT> *_pvRects);

    virtual bool GetPosition(int _x, int _y, CT_RefPos& _CurPos);
    virtual bool GetPosition(int _x, int _y, DK_FLOWPOSITION& pos, bool getStart = true);

    virtual DK_FLOWPOSITION GetStartPos();
    virtual DK_FLOWPOSITION GetEndPos();
    virtual DK_POS GetStartPoint();
    virtual DK_POS GetLastPoint() const;
    virtual DK_POS GetEndPoint();

    // ���º�������Ҫ��ѡ��״̬����
    virtual bool GetHitTestBoundBox(const DK_POS& _point, DK_BOX** _pBoundingBox, DK_UINT* _pBoundBoxCount, bool* _bIsHitTest);
    virtual bool FreeHitTestBoundBox(DK_BOX* _pBoundingBox);

    virtual bool CheckInGallery(const DK_POS& point);
    virtual bool CheckIsLink(const DK_POS& point, bool& isInternalLink) const;
    virtual bool CheckCurPosIsLink(bool& isInternalLink) const;
    virtual bool GetLinkFlowPosition(const DK_POS& _point, DK_FLOWPOSITION* _posLink);
    virtual bool GetLinkExternalURL(const DK_POS& _point, std::string& url);

    virtual bool GetHitObject(const DK_POS& point, DKE_HITTEST_OBJECTINFO* pObjInfo);
    virtual void FreeHitObject(DKE_HITTEST_OBJECTINFO* pObjInfo);

    virtual bool HitTestFootnote(const DK_POS& point, DKE_FOOTNOTE_INFO* pFootnoteInfo);
    virtual void FreeHitTestFootnote(DKE_FOOTNOTE_INFO* pFootnoteInfo);
    virtual bool GetFootnoteContentHandle(const DK_WCHAR* pNoteId, DKE_SHOWCONTENT_TYPE showType, DKE_SHOWCONTENT_HANDLE* pHandle);
    virtual void FreeContentHandle(DKE_SHOWCONTENT_TYPE showType, DKE_SHOWCONTENT_HANDLE* pHandle);

    virtual bool InitInteractiveObjects(std::vector<PageObjectInfo>& interactiveObjects);
    virtual bool InitComicsObjects(std::vector<PageObjectInfo>& comicsObjects);
    virtual bool InitGalleryObjects(std::vector<GalleryObjectInfo>& galleryObjects);

    virtual bool GetStringBetweenPos(const DK_FLOWPOSITION &pos1, const DK_FLOWPOSITION &pos2, std::string &content);

    virtual bool HitTestTextRangeByMode(const DK_POS& point, int hitTestTextMode, DK_FLOWPOSITION* pStartPos, DK_FLOWPOSITION* pEndPos);

    virtual DK_LONG HitTestComicsFrame(DK_POS point);

    virtual bool HitTestGallery(const DK_POS& point, IDKEGallery** ppGallery);
    virtual void FreeHitTestGallery(IDKEGallery* pGallery);
    virtual bool HitTestPreBlock(const DK_POS& point, DKE_PREBLOCK_INFO* pPreBlockInfo);
    virtual void FreeHitTestPreBlock(DKE_PREBLOCK_INFO* pPreBlockInfo);

    virtual IDKEHitableObjIterator* GetHitableObjIterator();
    virtual DK_VOID FreeHitableObjIterator(IDKEHitableObjIterator* pHitableObjIterator);

    // ��ȡ�������λ���Ҳ�ľ���
    DK_RECT GetRectFromBox(const DK_BOX &_box) const;

//#ifdef KINDLE_FOR_TOUCH
    // ���ÿ�ʼѡ�������
    virtual bool SetStartPos(int x, int y,int diffDistance, bool verticalForms);

    //����ÿҳ�����ϽǺ����½ǵ�����
    virtual void SetPageUpLeftAndRightDownPoint(const DK_POS& _pointUpLeft, const DK_POS& _pointDownRight);

    // �ж��Ƿ���ҳβ
    virtual bool IsEndOfPage(int _x, int _y);

    // �ж��Ƿ���ҳ��
    virtual bool IsBeginOfPage(int _x, int _y);

    virtual bool GetTextRects(const DK_FLOWPOSITION &startPos, const DK_FLOWPOSITION &endPos, DK_BOX **ppTextRects, DK_UINT *pRectCount);
    virtual void FreeRects(DK_BOX* pTextRect);

    virtual DK_RECT GetStartRect() const ;
    virtual DK_RECT GetEndRect() const ;

    void ValidPositionAndRects();
    bool PosInCurPage(const DK_FLOWPOSITION& pos) const;

    virtual bool SelectingInGallery() const;
    virtual void SetSelectionRangeMode(int mode);
#ifndef KINDLE_FOR_TOUCH
    // ��������
    virtual bool IsVisible() { return false; }
    virtual void SetVisible(bool _bVisible) {}
    virtual bool IsLastCursorLink() { return false; }
    virtual DK_RECT GetLastCursorRect() const { return DK_RECT(); }
    virtual bool GetPosition(DK_FLOWPOSITION* _posCur) const { return false; }
    virtual bool GetLastPosition(DK_FLOWPOSITION* _posCur) const { return false; }
    virtual bool GetHitTestText(std::string *_pText) { return false; }
    // �ƶ����
    virtual bool Move(MoveDirection _eDirection) { return false; }

    virtual DKE_PAGEOBJ_TYPE GetLastObjType() const;
    virtual DKE_PAGEOBJ_TYPE GetCurObjType() const;

    virtual bool IsEndOfGallery() const;
    virtual bool LastIsEndOfGallery() const;
#endif

private:
    bool CheckLinkInfo(const DKE_LINK_INFO& linkInfo, bool& isInternalLink) const;
    bool GetLink(const DKE_LINK_INFO& linkInfo, DK_FLOWPOSITION* posLink);

    bool CheckIsLinkOfGallery(const DK_POS& _point) const;
    bool CheckIsLinkOfURL(const DK_POS& _point, bool& isInternalLink) const;

    bool CheckFootnote(DK_POS& pos, IDKEFootnoteIterator* pFootNoteIterator);
    bool HitGalleryFootnote(const DK_POS& point, DKE_FOOTNOTE_INFO* pFootnoteInfo);
    bool HitPageFootnote(const DK_POS& point, DKE_FOOTNOTE_INFO* pFootnoteInfo);

    int GetMinBoxIndex(DK_BOX *pTextRects, int rectCount);
    int GetMaxBoxIndex(DK_BOX *pTextRects, int rectCount);
    int CompareDKBox(const DK_BOX& leftBox, const DK_BOX& rightBox);
//#else
//#endif
protected:
    IDKPageAdapter*  m_pPage;              // ҳ����ر���
    const PdfModeController* m_pModeController;
    bool             m_bSelectionMode;  
    int              m_iBaseLeft;          // λ�õĻ���ƫ����
    int              m_iBaseTop;
    DK_POS           m_pointUpLeft;     //ÿһҳ�����Ͻ�
    DK_POS           m_pointDownRight;  //ÿһҳ�����½�
    DK_POS           m_pointStart;      //�ʼ����ʼ��
    DK_POS           m_pointLast;
    DK_POS           m_pointEnd;
    DK_FLOWPOSITION  m_posBegin;           // ����ѡȡ�Ŀ�ʼ����λ��
    DK_FLOWPOSITION  m_posLast;
    DK_FLOWPOSITION  m_posEnd;
    DKE_SELECTION_MODE m_selectionMode;
    bool m_rightSelecter;
    DK_RECT m_rectStart;
    DK_RECT m_rectEnd;
    IDKEGallery* m_pGallery;
    bool m_endOfGallery;
    bool m_lastIsEndOfGallery;
    bool m_selectingInGallery;
};
#endif //__COMMONUI_BOOKTEXTCONTROLLER_H__
