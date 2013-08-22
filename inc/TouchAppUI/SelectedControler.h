#ifndef __TOUCHAPPUI_SELECTEDCONTROLER_H__
#define __TOUCHAPPUI_SELECTEDCONTROLER_H__

#include "BookReader/IDKPageAdapter.h"
#include "dkBaseType.h"
#include "CommonUI/BookTextController.h"
#include <vector>

class SelectedControler : public BookTextController
{
public:
    SelectedControler();
    virtual ~SelectedControler();
    virtual LPCSTR GetClassName() const 
    {
        return "SelectedControler";
    }

    virtual bool InitMember();

    // ���ÿ�ʼѡ�������
    virtual bool SetStartPos(int _x, int _y,int _iDiffDistance, bool _isVerticalForms);

    // �ƶ���ҳβ
    virtual bool MoveToEndOfPage();

    // �ƶ���ҳ��
    virtual bool MoveToBeginOfPage();

    // ѡ�й������ƶ�
    virtual bool Move(int _x, int _y, bool rightHandler = true); 
private:
    DK_POS           m_pointPageStart;  //ÿҳ����ʼ�㣬��ҳǰ��Ӧ����m_pointStart����ҳ���Ӧ����m_pointUpLeft��m_pointDownRight
};
#endif //__TOUCHAPPUI_SELECTEDCONTROLER_H__
