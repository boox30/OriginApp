//===========================================================================
// Summary:
//        �鼮��Ϣ������ݵĽӿ�
// Usage:
//        �鼮��Ϣ��ÿһ�������ṩ��һ��GET/SET�Ľӿڣ��ֱ�������ȡ�������������
// Remarks:
//        NULL
// Date:
//        2011-12-09
// Author:
//        Xu Kai (xukai@duokan.com)
//===========================================================================

#ifndef _DK_BookInfo_H_
#define _DK_BookInfo_H_

//===========================================================================

#include "DKXManager/Serializable/DK_Serializable.h"
#include "DKXManager/BaseType/TxtTocItem.h"
#include <vector>
#include <string>
using std::string;

//===========================================================================

class DK_BookInfo:public DK_Serializable
{
private:
    static const char* BOOKNAME;
    static const char* BOOKABSTRACT;
    static const char* BOOKAUTHOR;
    static const char* COVERIMAGE;
    static const char* BOOKSOURCE;
    static const char* BOOKDOWNLOADURL;
    static const char* FILEPATH; 
    static const char* FILEFORMAT;
    static const char* CREATETIME;
    static const char* ADDORDER;
    static const char* LASTREADTIME;
    static const char* READINGORDER;
    static const char* FILESIZE;
    static const char* BOOKISBN;
    static const char* PASSWORD;
    static const char* ISSERIALIZED;
    static const char* DOWNLOADEDCHAPTER;
    static const char* LATESTCHAPTERTITLE;
    static const char* LATESTCHAPTER;
    static const char* BOOKTAGS;
    static const char* TAGITEM;
    static const char* TXTTOCS;
    static const char* TXTTOCITEM;
    static const char* TOCEXTRACTED;
    static const char* BOOK_REVISION;
	static const char* READINGDATA_SYNC;
	static const char* CRASHBOOK;
	static const char* BOOKID;
public:
    DK_BookInfo();
    virtual ~DK_BookInfo();

public:
    
    //-----------------------------------
    //    Summary:                       
    //            ͼ���ļ�·�����ʺ���  
    //-----------------------------------
    bool SetBookFilePath(const string &_strPath);
    string GetBookFilePath()const;

    //-----------------------------------
    //    Summary:                       
    //            ͼ���ļ���ʽ���ʺ��� 
    //-----------------------------------
    string GetFileType()const;
    bool SetFileType(const string &_strType);

    //-----------------------------------
    //    Summary:                       
    //            ͼ���ļ�����ʱ����ʺ��� 
    //-----------------------------------
    string GetCreateTime()const;
    bool SetCreateTime(const string &_strTime);    

    //-----------------------------------
    //    Summary:                       
    //            ͼ���ļ��������з��ʺ��� 
    //-----------------------------------
    long GetAddOrder()const;
    bool SetAddOrder(long _lAddOrder);
    
    //-----------------------------------
    //    Summary:                       
    //            ͼ���ļ�����Ķ�ʱ����ʺ��� 
    //-----------------------------------
    string GetLastReadTime()const;
    bool SetLastReadTime(const string &_strTime);  
    
    //-----------------------------------
    //    Summary:                       
    //            ͼ���ļ��Ķ�������ʺ��� 
    //-----------------------------------  
    long GetReadingOrder()const;
    bool SetReadingOrder(long _lOrder);  

    //-----------------------------------
    //    Summary:                       
    //            ͼ�����ַ��ʺ��� 
    //-----------------------------------
    string GetBookName()const;
    bool SetBookName(const string &_strBookname);

    //-----------------------------------
    //    Summary:                       
    //            ͼ�����߷��ʺ��� 
    //-----------------------------------
    string GetBookAuthor()const;
    bool SetBookAuthor(const string &_strAuthor);

    //-----------------------------------
    //    Summary:                       
    //            �鼮����Դ���ʺ��� 
    //-----------------------------------
    string GetBookSource()const;
    bool SetBookSource(const string &_strSource);

    //-----------------------------------
    //    Summary:                       
    //            �鼮���������ӵ�ַ���ʺ��� 
    //-----------------------------------
    string GetBookUrl()const;
    bool SetBookUrl(const string &_strUrl);

    //-----------------------------------
    //    Summary:                       
    //            �鼮�����ʺ��� 
    //-----------------------------------
    string GetBookAbstract()const;
    bool SetBookAbstract(const string &_strAbstract);

    //-----------------------------------
    //    Summary:                       
    //            �鼮��С���ʺ��� 
    //-----------------------------------
    string GetFileSize()const;
    bool SetFileSize(const string &_strFileSize);

    //----------------------------------
    // Summary:
    //        �鼮������ʺ���
    //----------------------------------
    string GetBookPassword()const;
    bool SetBookPassword(const string &_strPassword);

    //-----------------------------------
    //    Summary:                       
    //            ���/���ø��鼮�࿴�鼮�汾
    //-----------------------------------
    string GetBookRevision() const;
    bool SetBookRevision(const char* bookRevision);

	//----------------------------------
    // Summary:
    //        ��Ǹ����Ƿ�ͬ����������ʱ����������������
    //----------------------------------
	bool SetSync(bool bIsSync);
	bool GetSync() const;

	//----------------------------------
    // Summary:
    //        ��Ǹ����ʱʱ���crash
    //----------------------------------
	bool SetCrash(bool bIsCrash);
	bool GetCrash() const;

	//----------------------------------
    // Summary:
    //        �鼮ID �ķ��ʺ���
    //        ������id ���������ID ���㷽ʽ��ͬ
    //----------------------------------
	bool SetBookID(const char* bookID);
	string GetBookID() const;

    //-------------------------------------
    //    Summary:
    //        ��ȡ�ļ��ı�ǩ��Ϣ
    //    Parameters:
    //        NULL
    //    Return Value:
    //        ���ص�ǰ�ļ��ı�ǩ�б�
    //-------------------------------------
    std::vector<string> GetFileTag() const;

    //-------------------------------------
    //    Summary:
    //        �����ļ��ı�ǩ��Ϣ
    //    Parameters:
    //        [in] _vFileTag    �ļ��ı�ǩ�б�
    //    Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    //-------------------------------------
    bool SetFileTag(const std::vector<string> &_vFileTag);

	//-------------------------------------
	//    Summary:
	//        ��ȡ�Ƿ���ȡ��Ŀ¼�ı�ʶ
	//    Parameters:
	//        NULL
	//    Return Value:
	//        �Ѿ���ȡ������true,û��ȡ������false
	//-------------------------------------
	bool GetTocExtractedState();

	//-------------------------------------
	//    Summary:
	//        ��ȡ�Ƿ���ȡ��Ŀ¼�ı�ʶ
	//    Parameters:
	//        [in] _bExtracted �����ȡ��TOC��true,û����false
	//    Return Value:
	//        �ɹ�����true,ʧ�ܷ���false
	//-------------------------------------
	bool SetTocExtractedState(bool _bExtracted);

	//-------------------------------------
    //    Summary:
    //        ��ȡTxt��Ŀ¼
    //    Parameters:
    //        NULL
    //    Return Value:
    //        ���ص�ǰ�ļ���Ŀ¼�б�
    //-------------------------------------
    std::vector<TxtTocItem> GetTxtToc() const;

    //-------------------------------------
    //    Summary:
    //        ����Txt��Ŀ¼
    //    Parameters:
    //        [in] _vTxtToc    Txt��Ŀ¼
    //    Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    //-------------------------------------
    bool SetTxtToc(const std::vector<TxtTocItem> &_vTxtToc);

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
    virtual bool WriteToXML(XMLDomNode& _xmlNode) const;

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
    virtual bool ReadFromXml(const XMLDomNode &_xmlNode);


    static bool WriteToXMLFunc(XMLDomNode* node, const void* arg);
private:
    static bool ReadTagsFunc(const XMLDomNode* node, void* arg);
    static bool WriteTagsFunc(XMLDomNode* node, const void* arg);
    static bool AddTxtTocFunc(const XMLDomNode* node, void* arg);
    static bool WriteTxtTocFunc(XMLDomNode* node, const void* arg);
    string		m_strBookName;
    string		m_strBookAbstract;    
    string		m_strAuthor;
    string		m_strCoverImage;
    string		m_strBookSource;
    string		m_strBookDownloadUrl;

    string		m_strFilePath;
    string		m_strFileFormat;
    string		m_strCreateTime;
    int         m_lAddOrder;
    string		m_strLastReadTime;
    int         m_lReadingOrder;
    string		m_strISBN;
    string		m_strFileSize;
    string		m_strPassword;
    int		    m_bIsSerialized;
	int		    m_bTocExtracted;
    
    std::vector<string> m_vFileTag;

    std::vector<TxtTocItem> m_vTxtToc;
    std::string  m_bookRevision;
	int			m_bIsSync;				//intֵ��ʾboolֵ����Ϊdkx����ʱֻ��intֵ
	int			m_bIsCrash;
	string 		m_strBookID;
    
};

#endif//_DK_BookInfo_H_
