//===========================================================================
// Summary:
//        TXTĿ¼��Ŀ�ṹ��
// Usage:
//        ���Ա���Ŀ¼���Լ�Ŀ¼��Ӧ�����еľ���ƫ��
// Remarks:
//        �����������Ľṹ����ʾĳһ��Ŀ¼�������еľ���ƫ��
// Date:
//        2011-12-27
// Author:
//        Xu Kai (xukai@duokan.com)
//===========================================================================

#ifndef _DKXMANAGER_BOOKINFO_TXTTOCITEM_H_
#define _DKXMANAGER_BOOKINFO_TXTTOCITEM_H_

#include "DKXManager/BaseType/CT_RefPos.h"
#include "DKXManager/Serializable/DK_Serializable.h"
#include <string>

class TxtTocItem 
{
private:
    static const char* TXTTOCTITLE;
    static const char* TXTTOCPOS;
public:
    TxtTocItem();
    ~TxtTocItem();

public:

    //----------------------------------------------------
    // Summary:
    //      ����Ŀ¼��
    // Parameters:
    //        [in] _strTitle    Ŀ¼��
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetTitle(const std::string &_strTitle);

    //----------------------------------------------------
    // Summary:
    //      ���Ŀ¼��
    // Parameters:
    //        NULL
    // Return Value:
    //        �ɹ�����Ŀ¼��,ʧ�ܷ���""
    // Remarks:
    //        NULL
    //----------------------------------------------------
    std::string GetTitle()const;

    //----------------------------------------------------
    // Summary:
    //      ����Ŀ¼��Ӧ����ƫ��
    // Parameters:
    //        [in] _clsPos    ƫ����������������
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //        NULL
    //----------------------------------------------------
    bool SetRefPos(const CT_RefPos &_clsPos);

    //----------------------------------------------------
    // Summary:
    //      ���Ŀ¼��Ӧ������ƫ��
    // Parameters:
    //        NULL
    // Return Value:
    //        ����Ŀ¼������ĵ�ƫ�ƣ�����������
    // Remarks:
    //        NULL
    //----------------------------------------------------
    CT_RefPos GetRefPos()const;

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
    bool WriteToXML(XMLDomNode& node) const;

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
    bool ReadFromXml(const XMLDomNode& node);

private:
    static bool ReadPosFunc(const XMLDomNode* node, void* arg);
    std::string m_strTitle;
    CT_RefPos    m_clsPos;
};
#endif//_DKXMANAGER_BOOKINFO_TXTTOCITEM_H_
