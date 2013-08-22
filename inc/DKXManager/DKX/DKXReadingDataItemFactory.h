//===========================================================================
// Summary:
//        ��������������һ���Ķ�����
// Usage:
//        ��ͬ�ķ������ɲ�ͬ���Ķ�����
// Remarks:
//        NULL
// Date:
//        2011-12-17
// Author:
//        Xu Kai (xukai@duokan.com)
//===========================================================================

#ifndef _DKXREADINGDATAITEMFACTORY_H_
#define _DKXREADINGDATAITEMFACTORY_H_
#include "DKXManager/ReadingInfo/ICT_ReadingDataItem.h"

class DKXReadingDataItemFactory
{
public:
    //----------------------------------------------------
    //  Summary:
    //      ��������һ���Ķ�����
    //  Parameters:
    //      [in] _eType    ���ɵ��Ķ����ݵ�����
    //  Return Value:
    //      �������ɵ��Ķ����ݶ����ָ��
    //  Remarks:
    //      NULL
    //----------------------------------------------------
    static ICT_ReadingDataItem * CreateReadingDataItem(ICT_ReadingDataItem::UserDataType _eType = ICT_ReadingDataItem::BOOKMARK);

    //----------------------------------------------------
    //  Summary:
    //      ��������һ���Ķ�����
    //  Parameters:
    //      [in] _eType           ���δ���Item������
    //      [in] _clsStartPos     ��ʼ��������
    //      [in] _clsEndPos       ��������������������ǩ����ע�������øö������ݺ�_clsStartPos��ͬ
    //      [in] _strBookComment  Item�����ݣ�Ϊ��ʼ�����������ı��������ں�����ʱ���ø����ݻ��׼ȷ����������
    //      [in] _strUserComment  ������ע����Ϊ�û����������ݣ�������ժ/��ǩ�����ֶα�����
    //  Return Value:
    //      �������ɵ��Ķ����ݶ����ָ��
    //  Remarks:
    //      NULL
    //----------------------------------------------------
    static ICT_ReadingDataItem * CreateReadingDataItem(ICT_ReadingDataItem::UserDataType _eType, const CT_RefPos &_clsStartPos, const CT_RefPos &_clsEndPos, 
                                                       const string &_strBookComment, const string &_strUserComment);

    static void DestoryReadingDataItem(ICT_ReadingDataItem *&_pReadingData);
};
#endif
