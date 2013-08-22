//===========================================================================
// Summary:
//        �û��Ķ����ݵ�ʵ��
// Usage:
//        ���ڱ�ʾ��ǩ��ժ�ʼ��Ķ����ȵ�
// Remarks:
//        NULL
// Date:
//        2011-12-16
// Author:
//        Xu Kai (xukai@duokan.com)
//===========================================================================

#ifndef _CT_ReadingDataItemImpl_H_
#define _CT_ReadingDataItemImpl_H_

#include "DKXManager/ReadingInfo/ICT_ReadingDataItem.h"
#include "DKXManager/Serializable/DK_Serializable.h"
#include <vector>
#include <tr1/memory>

using std::string;
class CT_ReadingDataItemImpl : public ICT_ReadingDataItem , public DK_Serializable
{
private:
    static const char* USERDATATYPE;
    static const char* USERDATAID;
    static const char* CREATETIME;
    static const char* LASTMODTIME;
    static const char* CREATOR;
    static const char* BEGINPOS;
    static const char* ENDPOS;
    static const char* BOOKCONTENT;
    static const char* USERCONTENT;
	static const char* KERNELVERSION;
	static const char* COLOR; 
	static const char* TAG;
	static const char* UPLOADED;
    static const char* PERCENT;
    static const char* COMICSFRAMEMODE;
    static const char* CHAPTERTITLE;
public:
    CT_ReadingDataItemImpl();
    CT_ReadingDataItemImpl(UserDataType _eType);
    virtual ~CT_ReadingDataItemImpl();

	virtual std::string GetKernelVersion() const;

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
    virtual UserDataType GetUserDataType() const;

    virtual bool SetUserDataType(UserDataType _eType);

    //----------------------------------------------------
    // Summary:
    //        ���/����ID���ԣ�ID��Ϊ�û�������DKXϵͳ�е�Ψһ��ʶ
    //----------------------------------------------------
    virtual string GetId() const;
    virtual void SetId(const char*);
    bool CreateId();

    //----------------------------------------------------
    // Summary:
    //        ��ȡ/�������ݵĴ���ʱ��
    //----------------------------------------------------
    virtual string GetCreateTime() const;
    virtual bool SetCreateTime(const string &_strCreateTime);    

    //----------------------------------------------------
    // Summary:
    //        ��ȡ/������������޸�ʱ��
    //----------------------------------------------------
    virtual string GetLastModifyTime() const;
    virtual bool SetLastModifyTime(const string &_strLastModifyTime);    

    //----------------------------------------------------
    // Summary:
    //        ��ȡ/�������ݵĴ�����
    //----------------------------------------------------
    virtual string GetCreator() const;
    virtual bool SetCreator(const string &_strCreator);    

    //----------------------------------------------------
    // Summary:
    //        ��ȡ/�������ݵİٷֱ�
    //----------------------------------------------------
    virtual int GetPercent() const;
    virtual bool SetPercent(int percent);

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
    virtual CT_RefPos GetBeginPos() const;

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
    virtual bool SetBeginPos(const CT_RefPos &_clsRefPos);

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
    virtual CT_RefPos GetEndPos() const;

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
    virtual bool SetEndPos(const CT_RefPos &_clsRefPos);

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
    virtual void SetComicsFrameMode(bool frameMode);
    virtual bool IsComicsFrameMode() const;

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
    virtual string GetBookContent() const;

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
    virtual bool SetBookContent(const string &_strContent);

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
    virtual string GetUserContent() const;

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
    virtual bool SetUserContent(const string &_strContent);

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
    virtual void SetChapterTitle(const string &_strChapterTitle);
    virtual string GetChapterTitle() const;

    bool WriteToXML(XMLDomNode& _xmlNode) const;
    bool ReadFromXml(const XMLDomNode &_xmlNode);

    virtual void SetColor(const char* color)
    {
        if (NULL != color)
        {
            m_color = color;
        }
    }
    virtual string GetColor() const
    {
        return m_color;
    }

    virtual void SetTag(const char* tag)
    {
        if (NULL != tag)
        {
            m_tag = tag;
        }
    }
    virtual string GetTag() const
    {
        return m_tag;
    }

    virtual bool IsUploaded() const
    {
        return m_uploaded != 0;
    }

    virtual void SetUploaded(bool uploaded)
    {
        m_uploaded = uploaded;
    }

private:
    UserDataType m_eType;
    string m_strID;
    string m_strCreateTime;
    string m_strLastModifyTime;
    string m_strCreator;
    string m_strBookContent;
    string m_strUserContent;
	string m_strKernelVersion;
    string m_strChapterTitle;
    CT_RefPos m_clsBeginPos;
    CT_RefPos m_clsEndPos;
    string m_color;
    string m_tag;
    // �Ķ������Ƿ��ϴ�
    int m_uploaded;
    int m_percent;
    int m_comicsFrame;
};
typedef std::tr1::shared_ptr<CT_ReadingDataItemImpl> CT_ReadingDataItemImplSPtr;
typedef std::vector<CT_ReadingDataItemImplSPtr> CT_ReadingDataItemImplSPtrList;
#endif//_CT_ReadingDataItemImpl_H_

