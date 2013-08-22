//====================================
//    Summary:
//        �Ķ����ݽӿڣ����ڻ���鼮���Ķ����ݣ���ǩ��ժ�ȣ�
//    Usage:
//        ���Ի�ø�����ǩ��ժ������������ָ����ȡĳһ����ǩ����ժ��
//            ����ɾ��ĳ����ǩ��ժ������������е���ǩ��ժ
//    Author:
//        Xuk
//===================================
#ifndef _CT_READINGDATA_H_
#define _CT_READINGDATA_H_

#include "DKXManager/Serializable/DK_Serializable.h"
#include "DKXManager/ReadingInfo/CT_ReadingDataItemImpl.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class CT_ReadingData : public DK_Serializable
{
private:
    static const string VERSION;
    static const string BOOKMARK;
    static const string COMMENT;
    static const string DIGEST;
    static const string PROGRESS;
    static const string USERNAME;
    static const string MODIFIED;
    static const string DATA_VERSION;
public:
    CT_ReadingData();
    virtual ~CT_ReadingData();

    string GetVersion()const;
    bool SetVersion(const string &_strVersion);    

    int GetBookmarkCount()const;
    bool AddBookmark(const CT_ReadingDataItemImpl &_bookmark);
    void RemoveUploadedBookmarks();
//    bool RemoveBookmark(const CT_SimpleRefContent &_SimRefContent);
    bool RemoveBookmark(int _iIndex);
    bool RemoveBookmark(const std::string& dataID);
	bool MigrateReadingData(const CT_ReadingData&);
    bool GetBookmarkByIndex(int _iIndex,CT_ReadingDataItemImpl *_pclsMark)const;
    bool SetProgress(const CT_ReadingDataItemImpl &_Progress);
    bool GetProgress(CT_ReadingDataItemImpl *_pclsProgress)const;

    std::string GetUser() const
    {
        return m_user;
    }

    void SetUser(const char* user)
    {
        m_user = user;
    }

    virtual bool WriteToXML(XMLDomNode& _xmlNode) const;
    virtual bool ReadFromXml(const XMLDomNode &_xmlNode);
    virtual bool IsModified()
    {
        return m_modified;
    }
    virtual void SetModified(bool modified)
    {
        m_modified = modified;
    }

    void MarkAsUploaded(bool uploaded = true);

    //-----------------------------------
    //    Summary:                       
    //            ���/���ø��鼮��ͬ�������ݰ汾
    //-----------------------------------
    int GetDataVersion()const;
    bool SetDataVersion(int dataVersion);
    
private:
    string m_strVersion;
    string m_user; // reading data is binding to user
    vector <CT_ReadingDataItemImpl>     m_vBookmarks;
    CT_ReadingDataItemImpl                 m_Progress;    
    bool m_modified;
    int m_dataVersion;
};
#endif//_ICT_READINGDATA_H_
