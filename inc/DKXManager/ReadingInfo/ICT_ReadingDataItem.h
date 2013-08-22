//===========================================================================
// Summary:
//        �û��Ķ����ݵĽӿ�
// Usage:
//        ���ڶ�ȡ�û�����Ķ�����
// Remarks:
//        NULL
// Date:
//        2011-12-16
// Author:
//        Xu Kai (xukai@duokan.com)
//===========================================================================

#ifndef _ICT_ReadingDataItem_H_
#define _ICT_ReadingDataItem_H_

#include "DKXManager/BaseType/CT_RefPos.h"
#include <string>
#include <vector>
#include <tr1/memory>

#define TYPE_LIST(MACRO_NAME)\
    MACRO_NAME(UNKNOWN)\
    MACRO_NAME(BOOKMARK)\
    MACRO_NAME(COMMENT)\
    MACRO_NAME(DIGEST)\
    MACRO_NAME(PROGRESS)\

#define TYPE_LIST_INDEX(TypeId)\
    TypeId,

#define TYPE_LIST_NAME(TypeId)\
    #TypeId,

using std::string;
class ICT_ReadingDataItem;
typedef std::tr1::shared_ptr<ICT_ReadingDataItem> ICT_ReadingDataItemSPtr;
typedef std::vector<ICT_ReadingDataItemSPtr> ICT_ReadingDataItemSPtrList;

class ICT_ReadingDataItem
{
public:
    ICT_ReadingDataItem(){}
    virtual ~ICT_ReadingDataItem(){}

    static bool CompareByCreateTime(ICT_ReadingDataItemSPtr lhs, ICT_ReadingDataItemSPtr rhs)
    {
        return lhs->GetCreateTime().compare(rhs->GetCreateTime()) > 0;
    }
public:
    enum UserDataType
    {
        TYPE_LIST(TYPE_LIST_INDEX)
        TYPECOUNT
    };

	//----------------------------------------------------
	// Summary:
	//        ����ں˰汾��Ϣ
	// Parameters:
	//        NULL
	// Return Value:
	//        �����ں˰汾��Ϣ
	// Remarks:
	//        NULL
	//----------------------------------------------------
	virtual std::string GetKernelVersion() const = 0;

    //----------------------------------------------------
    // Summary:
    //        ����û���������
    // Parameters:
    //        NULL
    // Return Value:
    //        �����û����ݵ�����
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual UserDataType GetUserDataType() const = 0;

    //----------------------------------------------------
    // Summary:
    //        �����û���������
    // Parameters:
    //        [in] _eType    �û���������
    // Return Value:
    //        �ɹ�����trueʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual bool SetUserDataType(UserDataType _eType) = 0;

    //----------------------------------------------------
    // Summary:
    //        ���ID���ԣ�ID��Ϊ�û�������DKXϵͳ�е�Ψһ��ʶ
    //----------------------------------------------------
    virtual string GetId() const = 0;
    virtual void SetId(const char* id) = 0;

    //----------------------------------------------------
    // Summary:
    //        ��ȡ/�������ݵĴ���ʱ��
    //----------------------------------------------------
    virtual string GetCreateTime() const = 0;
    virtual bool SetCreateTime(const string &_strCreateTime) = 0;    

    //----------------------------------------------------
    // Summary:
    //        ��ȡ/������������޸�ʱ��
    //----------------------------------------------------
    virtual string GetLastModifyTime() const = 0;
    virtual bool SetLastModifyTime(const string &_strLastModTime) = 0;    

    //----------------------------------------------------
    // Summary:
    //        ��ȡ/�������ݵĴ�����
    //----------------------------------------------------
    virtual string GetCreator() const = 0;
    virtual bool SetCreator(const string &_strCreator) = 0;    

    //----------------------------------------------------
    // Summary:
    //        ��ȡ�Ķ����ݵĵ�һ��������
    // Parameters:
    //        NULL
    // Return Value:
    //        �����Ķ����ݵĵ�һ��������
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual CT_RefPos GetBeginPos() const = 0;

    //----------------------------------------------------
    // Summary:
    //        �����Ķ����ݵĵ�һ��������
    // Parameters:
    //        [in] _clsRefPos    �Ķ������������еĿ�ʼ������
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual bool SetBeginPos(const CT_RefPos &_clsRefPos) = 0;

    //----------------------------------------------------
    // Summary:
    //        ��ȡ�Ķ����ݵĵڶ���������
    // Parameters:
    //        NULL
    // Return Value:
    //        �����Ķ����ݵĵڶ���������
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual CT_RefPos GetEndPos() const = 0;

    //----------------------------------------------------
    // Summary:
    //        �����Ķ����ݵĵڶ���������
    // Parameters:
    //        [in] _clsRefPos    �Ķ������������еĽ���������
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual bool SetEndPos(const CT_RefPos &_clsRefPos) = 0;

    //----------------------------------------------------
    // Summary:
    //        ���������鼮��ͼģʽ�Ƿ�����ģʽ
    // Parameters:
    //        [in] _clsRefPos    �Ķ������������еĽ���������
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        ֻ�����ڱ��أ����ϴ�������
    //----------------------------------------------------
    virtual void SetComicsFrameMode(bool frameMode) = 0;
    virtual bool IsComicsFrameMode() const = 0;

    //----------------------------------------------------
    // Summary:
    //        ��ȡ�Ķ�����ռȫ�İٷֱ�
    // Parameters:
    //        NULL
    // Return Value:
    //        �����Ķ�����ռȫ�İٷֱ�
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual int GetPercent() const = 0;

    //----------------------------------------------------
    // Summary:
    //        �����Ķ�����ռȫ�İٷֱ�
    // Parameters:
    //        [int] percent    �Ķ������������еİٷֱ�
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual bool SetPercent(int  percent) = 0;

    //----------------------------------------------------
    // Summary:
    //        ��ȡԭ�����������ں�����ʱλ�õ�У��
    // Parameters:
    //        NULL
    // Return Value:
    //        ����ԭ������
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual string GetBookContent() const = 0;

    //----------------------------------------------------
    // Summary:
    //        ���õ�ǰ�û����ݶ�Ӧ��ԭ������
    // Parameters:
    //        [in] _strContent    �Ķ����ݶ�Ӧ��ԭ������
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual bool SetBookContent(const string &_strContent) = 0;

    //----------------------------------------------------
    // Summary:
    //        ��ȡ�û���������
    // Parameters:
    //        NULL
    // Return Value:
    //        �����û���������
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual string GetUserContent() const = 0;

    //----------------------------------------------------
    // Summary:
    //        �����û���������
    // Parameters:
    //        [in] _strContent    �û���������
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    virtual bool SetUserContent(const string &_strContent) = 0;

    //----------------------------------------------------
    // Summary:
    //        Setting chapter title
    // Parameters:
    //        [in] _strChapterTitle The title of chapter at start position
    // Return Value:
    //        Return empty string if title is null
    // Remarks:
    //        ֻ�����ڱ��أ����ϴ�������
    //----------------------------------------------------
    virtual void SetChapterTitle(const string &_strChapterTitle) = 0;
    virtual string GetChapterTitle() const = 0;

    virtual void SetColor(const char* color) = 0;
    virtual string GetColor() const = 0;

    virtual void SetTag(const char* tag) = 0;
    virtual string GetTag() const = 0;

    virtual bool IsUploaded() const = 0;
    virtual void SetUploaded(bool uploaded) = 0;
};
#endif//_ICT_ReadingDataItem_H_

