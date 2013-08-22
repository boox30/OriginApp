//===========================================================================
// Summary:
//        DKX����ӿڣ����ڸ��ϲ��ṩ����/��ȡ���ݲ���
// Usage:
//        ͨ�����벻ͬ���鼮���Ի���鼮��������Ϣ�����������鼮�������Ϣ
// Remarks:
//        NULL
// Date:
//        2011-12-09
// Author:
//        Xu Kai (xukai@duokan.com)
//===========================================================================
#ifndef __DKXMANAGER_H__
#define __DKXMANAGER_H__

#include "DKXManager/DKX/DKXBlock.h"
#include "Common/SystemSetting_DK.h"
#include "singleton.h"
#include <string>
#include <vector>

using std::vector;
using std::string;
class DKXManager
{
    SINGLETON_H(DKXManager)
    DKXManager()
        : m_strCurFilePath("")
        , m_pCurDkx(NULL)
    {
    }
    
public:
    static DKXBlock* CreateDKXBlock(const char* path);
    static void DestoryDKXBlock(DKXBlock* block);

    virtual ~DKXManager()
    {
        SafeDeletePointer(m_pCurDkx);
    };


    /*********************************************************************
    *                     Interface on BookInfo                          *
    *********************************************************************/


    //----------------------------------------------------
    // Summary:
    //        ����ָ���鼮�Ĵ���ʱ��
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] createTime    ָ��Ŀ���鼮�Ĵ���ʱ��
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetBookCreateTime(const string &bookPath,const string &createTime);



    //----------------------------------------------------
    // Summary:
    //        ����ָ���鼮�Ĵ�������
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] addOrder    ָ��Ŀ���鼮�Ĵ���ʱ��
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetBookAddOrder(const string &bookPath,long addOrder);

    //----------------------------------------------------
    // Summary:
    //        ��ȡָ���鼮�Ĵ�������
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    // Return Value:
    //        �ɹ�����ָ���鼮�Ĵ���ʱ��,ʧ�ܷ��ؿմ�
    // Remarks:
    //        NULL
    //----------------------------------------------------
    long FetchBookAddOrder(const string &bookPath);

    //----------------------------------------------------
    // Summary:
    //        ����ָ���鼮������Ķ�ʱ��
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] lastReadTime    ָ��Ŀ���鼮������Ķ�ʱ��
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetBookLastReadTime(const string &bookPath,const string &lastReadTime);

    //----------------------------------------------------
    // Summary:
    //        ��ȡָ���鼮������Ķ�ʱ��
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    // Return Value:
    //        �ɹ�����ָ���鼮������Ķ�ʱ��,ʧ�ܷ��ؿմ�
    // Remarks:
    //        NULL
    //----------------------------------------------------
    string FetchBookLastReadTime(const string &bookPath);
    
    //----------------------------------------------------
    // Summary:
    //        ����ָ���鼮���Ķ�����
    // Parameters:
    //        [in] bookPath      ָ��Ŀ���鼮
    //        [in] readingOrder    ָ��Ŀ���鼮���Ķ�����
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetBookReadingOrder(const string &bookPath, long readingOrder);

    //----------------------------------------------------
    // Summary:
    //        ��ȡָ���鼮���Ķ�����
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    // Return Value:
    //        �ɹ�����ָ���鼮���Ķ�����,ʧ�ܷ���-1
    // Remarks:
    //        NULL
    //----------------------------------------------------
    long FetchBookReadingOrder(const string &bookPath);

    //----------------------------------------------------
    // Summary:
    //        ��ȡָ���鼮���ļ�����
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    // Return Value:
    //        �ɹ�����ָ���鼮���ļ�����,ʧ�ܷ��ؿմ�
    // Remarks:
    //        NULL
    //----------------------------------------------------
    string FetchBookFileType(const string &bookPath);

    //----------------------------------------------------
    // Summary:
    //        ����ָ���鼮���ļ�����
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] fileType    ָ��Ŀ���鼮���ļ�����
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetBookFileType(const string &bookPath, const string &fileType);    

    //----------------------------------------------------
    // Summary:
    //        ��ȡָ���鼮������
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    // Return Value:
    //        �ɹ�����ָ���鼮������,ʧ�ܷ��ؿմ�
    // Remarks:
    //        NULL
    //----------------------------------------------------
    string FetchBookName(const string &bookPath);

    //----------------------------------------------------
    // Summary:
    //        ����ָ���鼮������
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] bookName    ָ��Ŀ���鼮������
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetBookName(const string &bookPath, const string &bookName);
    
    //----------------------------------------------------
    // Summary:
    //        ��ȡָ���鼮������
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    // Return Value:
    //        �ɹ�����ָ���鼮������,ʧ�ܷ��ؿմ�
    // Remarks:
    //        NULL
    //----------------------------------------------------
    string FetchBookAuthor(const string &bookPath);

    //----------------------------------------------------
    // Summary:
    //        ����ָ���鼮������
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] author        ָ��Ŀ���鼮������
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetBookAuthor(const string &bookPath, const string &author);

	
    //----------------------------------------------------
    // Summary:
    //        ��ȡָ���鼮�������������Ƿ���dkx�ļ�ͬ��
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    // Return Value:
    //        �����Ƿ�ͬ��
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool FetchSync(const string &bookPath);

    //----------------------------------------------------
    // Summary:
    //        ����ָ���鼮�������������Ƿ���dkx�ļ�ͬ��
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] isSync        �Ƿ�ͬ��
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetSync(const string &bookPath, bool isSync);

	//----------------------------------------------------
    // Summary:
    //        ��ȡָ���鼮�Ƿ������
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    // Return Value:
    //        �����Ƿ������
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool FetchCrash(const string &bookPath);

    //----------------------------------------------------
    // Summary:
    //        ����ָ���鼮�Ƿ������
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] isCrash        �Ƿ������
    // Return Value:
    //		��������true,���򷵻�false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetCrash(const string &bookPath, bool isCrash);

	//----------------------------------------------------
    // Summary:
    //        ����ָ���鼮��bookID
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] bookID        bookID
    // Remarks:
    //        NULL
    //----------------------------------------------------
	bool SetBookID(const string& bookPath, const char* bookID);

	//----------------------------------------------------
    // Summary:
    //        ��ȡָ���鼮��bookID
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    // Return Value:
    //		����ָ���鼮��bookID
    // Remarks:
    //        NULL
    //----------------------------------------------------
	string FetchBookID(const string& bookPath);

    //----------------------------------------------------
    // Summary:
    //        ��ȡָ���鼮����Դ
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    // Return Value:
    //        �ɹ�����ָ���鼮����Դ,ʧ�ܷ��ؿմ�
    // Remarks:
    //        NULL
    //----------------------------------------------------
    string FetchBookSource(const string &bookPath);

    //----------------------------------------------------
    // Summary:
    //        ����ָ���鼮������
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] source        ָ��Ŀ���鼮����Դ
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetBookSource(const string &bookPath, const string &source);    

    
    //----------------------------------------------------
    // Summary:
    //        ��ȡָ���鼮�ļ��
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    // Return Value:
    //        �ɹ�����ָ���鼮�ļ��,ʧ�ܷ��ؿմ�
    // Remarks:
    //        NULL
    //----------------------------------------------------
    string FetchBookAbstract(const string &bookPath);

    //----------------------------------------------------
    // Summary:
    //        ����ָ���鼮�ļ��
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] abstract    ָ��Ŀ���鼮�ļ��
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetBookAbstract(const string &bookPath, const string &abstract);


    //----------------------------------------------------
    // Summary:
    //        ��ȡָ���鼮�ļ�������
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    // Return Value:
    //        �ɹ�����ָ���鼮�ļ�������,ʧ�ܷ��ؿմ�
    // Remarks:
    //        NULL
    //----------------------------------------------------
    string FetchBookPassword(const string &bookPath);

    //----------------------------------------------------
    // Summary:
    //        ����ָ���鼮�ļ�������
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] password    ָ��Ŀ���鼮�ļ�������
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetBookPassword(const string &bookPath, const string &password);

    //----------------------------------------------------
    // Summary:
    //        ��ȡָ���鼮�Ĵ�С
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    // Return Value:
    //        �ɹ�����ָ���鼮�Ĵ�С,ʧ�ܷ��ؿմ�
    // Remarks:
    //        NULL
    //----------------------------------------------------
    string FetchBookSize(const string &bookPath);

    //----------------------------------------------------
    // Summary:
    //        ����ָ���鼮�Ĵ�С
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] strSize    ָ��Ŀ���鼮�Ĵ�С
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetBookSize(const string &bookPath, const string &strSize);


 
    //-------------------------------------
    //    Summary:
    //        ��ȡTXT�ļ���Ŀ¼��Ϣ
    //    Parameters:
    //        [in] bookPath    TXT�ļ���·��
    //    Return Value:
    //        ���ص�ǰTXT�ļ���Ŀ¼��Ϣ
    //    Remarks:
    //        NULL
    //-------------------------------------
    std::vector<TxtTocItem> FetchTxtToc(const string &bookPath);

    //-------------------------------------
    //    Summary:
    //        ����TXT�ļ���Ŀ¼��Ϣ
    //    Parameters:
    //        [in] bookPath    TXT�ļ���·��
    //        [in] txtToc        TXT�ļ���Ŀ¼�б�
    //    Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    //    Remarks:
    //        NULL
    //-------------------------------------
    bool SetTxtToc(const string &bookPath,const std::vector<TxtTocItem> &txtToc);

	//----------------------------------------------------
	// Summary:
	//        �ж�Ŀ¼�Ƿ��Ѿ���ȡ
	// Parameters:
	//        [in] bookPath    ָ��Ŀ���鼮
	// Return Value:
	//        �Ѿ���ȡ����true,û����ȡ����false
	// Remarks:
	//        NULL
	//---------------------------------------------------
	bool FetchTocExtractedState(const string &bookPath);

	//---------------------------------------------------
	// Summary:
	//        ���õ�ǰ�鼮Ŀ¼�Ƿ��Ѿ���ȡ
	// Parameters:
	//        [in] bookPath		ָ��Ŀ���鼮
	//        [in] hasExtracted   ָ���Ƿ��Ѿ���ȡĿ¼����Ϊtrue,����Ϊfalse
	// Return Value:
	//        ���óɹ�����true,ʧ�ܷ���false
	// Remarks:
	//        NULL
	//---------------------------------------------------
	bool SetTocExtractedState(const string &bookPath,bool hasExtracted);


    
    /*********************************************************************
    *                     Interface on ReadingData                       *
    *********************************************************************/
    int FetchBookMarkNumber(const string &bookPath);

    //----------------------------------------------------
    // Summary:
    //        ���һ����ǩ
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] userDataItem        ��ǩ�Ļ������ݣ�ID,����ʱ�䣬���ߵȣ�
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool AddBookmark(const string &bookPath, const ICT_ReadingDataItem *userDataItem);

	//----------------------------------------------------
    // Summary:
    //      ��ȡ������ժ
    // Parameters:
    //		[in] bookPath    ָ��Ŀ���鼮
    //		[out]bookmarks  ���е���ժ����
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        _pvBookmarks���ڴ��ɵ������ͷ�
    //----------------------------------------------------
	bool FetchAllBookmarks(const string &bookPath, vector<ICT_ReadingDataItem *> *bookmarks);

    //----------------------------------------------------
    // Summary:
    //        ���һ����ǩ
    // Parameters:
    //        [in] bookPath            ָ��Ŀ���鼮
    //        [in] index                ָ��Ҫ�����һ����ǩ
    //        [out] userDataItem        ���ڻ�ȡ��ǩ�����ݣ�ID,����ʱ�䣬���ߵȣ�
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool FetchBookmarkByIndex(const string &bookPath, int index, ICT_ReadingDataItem *userDataItem);

    //----------------------------------------------------
    // Summary:
    //        ɾ��һ����ǩ
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] index        ָ��Ҫ�����һ����ǩ
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool RemoveBookmarkByIndex(const string &bookPath, int index);



    //----------------------------------------------------
    // Summary:
    //        �����Ķ�����
    // Parameters:
    //        [in] bookPath            ָ��Ŀ���鼮
    //        [in] userDataItem        �Ķ���������
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetProgress(const string &bookPath, const ICT_ReadingDataItem *userDataItem);
    
    //----------------------------------------------------
    // Summary:
    //        ��ȡ�Ķ�����
    //    Parameters:
    //        [in] bookPath        ָ��Ŀ���鼮
    //        [out]userDataItem    ���ڻ�ȡ�Ķ����ȵĻ�������
    //    Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    //    Remarks:
    //        ���α������������ռ�
    //-----------------------------------------------------
    bool FetchProgress(const string &bookPath,ICT_ReadingDataItem *userDataItem);

    /*********************************************************************
    *                     Interface on Setting Data                       *
    *********************************************************************/

    /**********************  PDF ר�в���    ������������δ��************************/

    //----------------------------------------------------
    // Summary:
    //        ��ȡpdf������ĳ���ֶε�ֵ
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] strField        ָ��Ҫ��ȡ���ֶ�
    // Return Value:
    //        �ɹ����ظ��ֶε�ֵ��ʧ�ܷ��ؿմ�
    // Remarks:
    //        NULL
    //----------------------------------------------------
    string FetchPDFSettingFieldValue(
            const string &bookPath,
            const string& strField);

    //----------------------------------------------------
    // Summary:
    //        ����pdfĳ���ֶε�ֵ
    // Parameters:
    //        [in] bookPath    ָ��Ŀ���鼮
    //        [in] strField        ָ��Ҫ���õ��ֶ�
    //        [in] fieldValue    ָ��Ҫ���õ�ֵ
    // Return Value:
    //        �ɹ�����true��ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetPDFSettingFieldValue(
            const string &bookPath,
            const string &strField,
            const string &fieldValue);    

    
    /**********************  ��PDF ר�в���    ************************/

    bool SaveCurDkx();

    bool SetBookRevision(const string& bookPath, const char* bookRevision);
    std::string GetBookRevision(const string& bookPath);

    int GetDataVersion(const string& bookPath);
    bool SetDataVersion(const string& bookPath, int dataVersion);

    bool MergeCloudBookmarks(const string& bookPath,
            const ReadingBookInfo& readingBookInfo,
            int cloudDataVersion);
    void SetReadingDataModified(const string& bookPath, bool modified);
    bool IsReadingDataModified(const string& bookPath);
    void MarkReadingDataAsUploaded(const string& bookPath);
    void Reset();


private:
    bool InitCurDkx(string _strFilePath);
    bool TestIsThisDkx(string _strFilePath);
    
private:
    string m_strCurFilePath;
    DKXBlock *m_pCurDkx;
};

#endif    //__DKXMANAGER_H__

