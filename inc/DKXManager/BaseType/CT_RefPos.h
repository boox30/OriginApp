//===========================================================================
// Summary:
//        ������õ����ݡ�
// Usage:
//        ͨ��һ��Set/Get������/���������õ��Ӧ���£��Σ��ֽ�ƫ��
// Remarks:
//        �����������Ľṹ����ʾĳһ�����������еľ���ƫ��
// Date:
//        2011-12-09
// Author:
//        Xu Kai (xukai@duokan.com)
//===========================================================================
#ifndef _CT_REFPOS_H_
#define _CT_REFPOS_H_

//===========================================================================

#include "DKXManager/Serializable/DK_Serializable.h"
#include "Utility/EncodeUtil.h"

using dk::utility::EncodeUtil;

//===========================================================================


class CT_RefPos: public DK_Serializable
{
private:
    static const char* CHAPTERINDEX;
    static const char* PARAINDEX;
    static const char* ATOMINDEX;
    static const char* OFFSET_IN_CHAPTER;
    static const char* CHAPTER_ID;
public:
    
    CT_RefPos();
    bool InitFromSyncData(const XMLDomNode* node);
    CT_RefPos(int chapterIndex, int paraIndex, int elementIndex, int offsetInChapter);
    virtual ~CT_RefPos();


    //----------------------------------------------------
    // Summary:
    //        ���/�����½�����
    //----------------------------------------------------
    bool SetChapterIndex(int chapterIndex);
    int GetChapterIndex()const;
    
    //----------------------------------------------------
    // Summary:
    //        ���/���ö�������
    //----------------------------------------------------
    bool SetParaIndex(int paraIndex);
    int GetParaIndex()const;
    
    //----------------------------------------------------
    // Summary:
    //        ���/�����ֽ�����
    //----------------------------------------------------
    bool SetAtomIndex(int atomIndex);
    int GetAtomIndex()const;

    bool SetOffsetInChapter(int offsetInChapter);
    int GetOffsetInChapter() const;
    bool HasOffsetInChapter() const
    {
        return -1 != m_offsetInChapter;
    }

    void SetChapterId(const DK_WCHAR* chapterId)
    {
        m_chapterId = EncodeUtil::ToString(chapterId);
    }

    std::string GetChapterId() const
    {
        return m_chapterId;
    }

    bool HasChapterId() const
    {
        return !m_chapterId.empty();
    }

    //----------------------------------------------------
    // Summary:
    //        ����������д��XMLNODE��
    // Parameters:
    //        [in] _xmlNode    -���ڴ洢�������ݵĽ�㣬ÿһ������
    //                         ��Ϊ���ӽ����ӵ��ý���С�
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual bool WriteToXML(XMLDomNode& node) const;

    //----------------------------------------------------
    // Summary:
    //        �ѻ������ݴ�XMLNODE��ȡ����
    // Parameters:
    //        [in] _xmlNode    -�洢�������ݵĽ�㣬��ÿ���ӽ���Ӧ��һ���䱾���ԣ�
    //                         ͨ���������������д�س�Ա������
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual bool ReadFromXml(const XMLDomNode& node);

    //----------------------------------------------------
    // Summary:
    //        ���ء�==���������ʹ��ͨ���ж��Ƿ����еĳ�Ա����������������������Ƿ����
    // Parameters:
    //        [in] rhs    -���ȽϵĶ���
    // Return Value:
    //        ���г�Ա������ȷ���true,��һ������ȷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool operator==(const CT_RefPos& rhs)
    {
        return ((m_chapterIndex == rhs.m_chapterIndex)
                && (m_paraIndex == rhs.m_paraIndex)
                && (m_atomIndex == rhs.m_atomIndex)
                && (m_offsetInChapter == rhs.m_offsetInChapter));
     }

    //----------------------------------------------------
    // Summary:
    //        �Ƚ���������������λ�ù�ϵ
    // Parameters:
    //        [in] _clsRefPos    ���Ƚϵ���������
    // Return Value:
    //        int  0��ʾ���,������ʾ������������_clsRefPosλ�ÿ��� ������ʾ����������λ�ÿ�ǰ
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual int CompareTo(const CT_RefPos &_clsRefPos);

    DK_FLOWPOSITION ToFlowPosition() const
    {
        return DK_FLOWPOSITION(m_chapterIndex, m_paraIndex, m_atomIndex);
    }

    bool IsValid() const
    {
        return m_chapterIndex >= 0
            && m_paraIndex >= 0
            && m_atomIndex >= 0;
    }
    bool WriteToSyncDomNode(XMLDomNode* domNode) const;
    static bool WriteToXMLFunc(XMLDomNode* node, const void* arg);
    static bool ReadFromXmlFunc(const XMLDomNode* node, void* arg);
private:
    int m_chapterIndex;
    int m_paraIndex;
    int m_atomIndex;    
    int m_offsetInChapter;
    std::string m_chapterId;
};
#endif

