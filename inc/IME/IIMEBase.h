#ifndef __IIMEBASE_H__
#define __IIMEBASE_H__

#ifndef WORD16
    #define WORD16 unsigned short
#endif
#include <string>
typedef enum
{
    CAN_NOT_PROCESS    ,
    PROCESSED_NO_RESULT    ,
    PROCESSED_WITH_RESULT
}eProcessResult;

class IIMEBase
{
public:
    /******************************
    *    
    *    ������:Init()
    *    ����:���б�Ҫ�ĳ�ʼ��
    *
    *******************************/
    virtual void Init() = 0;
    /******************************
    *    
    *    ������:ProcessKeys
    *    ����:��������ַ��������뷨 �����ش���״̬
    *    ����: 
    *        iASCIICode - ASCII ��ֵ���ܳ��ֵ��� 
    *                        'a'-'z'
    *                        'A'-'Z'
    *                        8(�ظ�)
    *                        13(�س�)
    *    ����ֵ:
    *        CAN_NOT_PROCESS            - ���״̬������Z �� ����ڵ�һλʱ����8(�ظ�) ���޷����� ���ظ�ֵ
    *        PROCESSED_NO_RESULT     - ѡ��״̬û�����ս��   ��:���� 'a' �õ� "�� �� ߹"���ַ��� ������ȷ�����ս�� 
    *        PROCESSED_WITH_RESULT     - �Ѿ�ȷ�����,GetStringByIndex(0)��Ϊ���ս��.  ��:���4���ַ����ȷ��һ����
    *
    *******************************/
    virtual eProcessResult ProcessKeys(char iASCIICode) = 0;

    /******************************
    *    
    *    ������:SelectIndex
    *    ����:ѡ����ָ�������ĺ�ѡ��
    *    ����:0��ʼ������ֵ 
    *    ����ֵ:
    *        CAN_NOT_PROCESS         - һ��ֻ��4����ѡ��  �������index = 5 ���޷�����
    *        PROCESSED_NO_RESULT     - ѡ��״̬û�����ս��     ��:���� 'nh' �õ� "���=0 ��=1 ��=2 "���ַ��� ��ʹ��SelectIndex(1) �õ� "��h" ������ȷ�����ս�� 
    *        PROCESSED_WITH_RESULT    - �Ѿ�ȷ�����,GetStringByIndex(0)��Ϊ���ս�� �� 
                                        ��:���� 'nh' �õ� "���=0 ��=1 ��=2 "���ַ��� ��ʹ��SelectIndex(0) �õ� "���" ������ʹ�� GetStringByIndex(0)�õ�����ַ���
    *
    *******************************/
    virtual eProcessResult SelectIndex(int iIndex) = 0;

    /******************************
    *    
    *    ������:GetInputString
    *    ����:��ȡ��ǰ��ƴ�������ַ���
    *    ����ֵ:С��unicode������ַ���
    *    ����:
    *        ͨ��ProcessKey��������"dk"2���ַ�,�õ�����"���� �� �˿� �� ��"�Ⱥ�ѡ�ʡ���ʱ���ú���ProcessKey 3(��Ӧ"��"��) �ٵ���GetInputString �򷵻�"��k"�ַ�����
    *
    *******************************/
    virtual std::string GetInputString()= 0;

    /******************************
    *    
    *    ������:GetStringByIndex
    *    ����:��ȡָ�������ĺ�ѡ��
    *    ����:0��ʼ������ֵ
    *    ����ֵ:����00��β�� С��unicode
    *
    *******************************/
    virtual std::string GetStringByIndex(unsigned int Index)= 0;

    /******************************
    *    
    *    ������:GetStringByIndex
    *
    *******************************/
    virtual std::string GetResultString(){return this->GetStringByIndex(0);};
    
    /******************************
    *    
    *    ������:SetInputIndex
    *    ����:ָ�����λ�ڵ��ʵ�λ�� ��ǿ���� 
    *    ����:
    *    CurIndex - ��Ҫ���õ�λ������ֵ
    *    ����ֵ:
    *        ʵ�����õ�λ������
    *    ע��:
    *        ���ص�����ֵӦ���ַ�������׼
    *        ����unicode��"hello" ռ��10���ֽ� ����ֻ��5���� ����indexֵӦ��ȡ0-5 0��h֮ǰ 5��o֮��
    *******************************/
    virtual unsigned int SetInputIndex(unsigned int CurIndex) = 0;

    /******************************
    *    
    *    ������:GetInputIndex
    *    ����:ȡ�õ�ǰ���λ��
    *    ����ֵ:
    *        ���λ��ֵ
    *******************************/
    virtual unsigned int GetInputIndex() = 0;

    /******************************
    *    
    *    ������:Reset
    *    ����:������л������� ��ʼ¼���µ��� ���л��������뷨ʱ �Լ��رո����뷨ʱ�����Զ����õ���
    *******************************/
    virtual void Reset() = 0;

    virtual ~IIMEBase(){};
};

#endif
