
//===================================
//    Summary:
//        ���л��ӿ�
//    Usage:
//        ��������Ϣд��/��ȡ XML �Ĳ������̡�
//  Remarks��
//      
//    Author:
//        Xuk
//====================================

#ifndef __DK_Serializable_H__
#define __DK_Serializable_H__

//========================================

#include<string>
#include<sstream>
//#include<iostream>
#include "XMLDomDocument.h"
#include "XMLDomNode.h"
using std::string;

//=========================================


class DK_Serializable
{
public:
    DK_Serializable(){};
    virtual ~DK_Serializable(){};

public:

    //----------------------------------------------------
    // Summary:
    //        ����������д��XMLNODE��
    // Parameters:
    //        [in] _xmlNode    -���ڴ洢�������ݵĽ�㣬ÿһ������
    //                         ��Ϊ���ӽ����ӵ��ý���С�
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //         ������Ҫ���л��Ķ��󣬶�Ҫʵ������ӿ�
    //----------------------------------------------------
    virtual bool WriteToXML(XMLDomNode& node) const =0;

    //----------------------------------------------------
    // Summary:
    //        �ѻ������ݴ�XMLNODE��ȡ����
    // Parameters:
    //        [in] _xmlNode    -�洢�������ݵĽ�㣬��ÿ���ӽ���Ӧ��һ���������ԣ�
    //                         ͨ���������������д�س�Ա������
    // Return Value:
    //        �ɹ�����true,ʧ�ܷ���false
    // Remarks:
    //         ������Ҫ���л��Ķ��󣬶�Ҫʵ������ӿ�
    //----------------------------------------------------
    virtual bool ReadFromXml(const XMLDomNode& node)=0;
public:
    DK_ReturnCode AddCommentNodeToXML(string _strName,XMLDomNode& _xmlNode/*,XMLDomNode& _SubNode*/) const;

    //-------------------------------------
    //    Summary:
    //        Ϊ��������ԭ���ӽ��
    //    Parameters:
    //        [in]_pNode            ����㣬����Ϊ�����һ��ԭ���ӽ��
    //        [in]_pName            ԭ�ӽ�������
    //        [in]_pValue            ԭ�ӽ���ֵ
    //    Remarks:
    //        ��νԭ�ӽ�����û���ӽ�㣬ֻ��ֵ�Ľ��
    //-------------------------------------
    DK_ReturnCode AddAtomSubNode(XMLDomNode &_pNode,const string &_strName,const string &_strValue) const;

    //-----------------------------------
    //    Summary:
    //        ��ȡԭ�ӽ���ֵ
    //    Parameters:
    //        [in]_pNode            XMLԭ�ӽ��
    //        [in]_pValueStr        ���ڴ洢�ӽ���ж�������ֵ
    //-----------------------------------
    DK_ReturnCode ReadAtomNodeValue(XMLDomNode &_pNode,string &_strValue) const;

};

#endif//__DK_Serializable_H__


