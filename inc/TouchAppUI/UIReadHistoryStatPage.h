////////////////////////////////////////////////////////////////////////
//
// UIReadHistoryStatPage.h
// Contact: liujt
// Copyright (c) Duokan Corporation. All rights reserved.
//
//
////////////////////////////////////////////////////////////////////////

#ifndef __UIREADHISTORYSTATISTICS_H__
#define __UIREADHISTORYSTATISTICS_H__

#include "GUI/UIImage.h"
#include "GUI/UIPage.h"
#include "GUI/UITextSingleLine.h"
#include "GUI/UIComplexButton.h"
#include <string>

#define MinStartX 70
#define MinStartY 300
#define MaxStartX 360
#define MaxStartY 600
#define XDISTANCE 5
#define YDISTANCE 120

#define MiddleX  299
#define HALFWIDTH  300


class UIReadHistoryStatPage : public UIPage
{
public:
    UIReadHistoryStatPage();
    static LPCSTR GetClassNameStatic()
    {
        return ("UIReadHistoryStatPage");
    }

    virtual LPCSTR GetClassName() const
    {
        return this->GetClassNameStatic();
    }
    virtual ~UIReadHistoryStatPage();
    void OnCommand(DWORD dwCmdId, UIWindow * pSender, DWORD dwParam);    

protected:
    HRESULT Init();
    void InitImages();
    void InitImage(std::vector<UIImage*> &vImageList, float fNumber, int decimalLen);    
    int  GetStartingX_Images(std::vector<UIImage*> &vImages, BOOL bLeft);
    void Dispose();
    void OnLeave();
    HRESULT Draw(DK_IMAGE drawingImg);
    void DrawImages();

private:

    UIImage                   m_imgTitle;//�Ķ�ͳ��
    UIComplexButton           m_btnReset;
        
    UITextSingleLine          m_txtTotalReadingHours;//�Ķ���Сʱ��
    UITextSingleLine          m_txtAverageReadingHoursPerBook;//ƽ��ÿ�����Ķ�ʱ��
    UITextSingleLine          m_txtReadingPagesPerHour;//ÿСʱ�Ķ�ҳ��
    UITextSingleLine          m_txtReadedBooks;    //�Ķ�����鼮����
    
    std::vector<UIImage*>     m_vTotalHours;//�Ķ���Сʱ����ͼ���б�
    std::vector<UIImage*>     m_vAverageHoursPerBook;//ƽ��ÿ�����Ķ�ʱ���ͼ���б�
    std::vector<UIImage*>     m_vReadingPagesPerHour;//ÿСʱ�Ķ�ҳ����ͼ���б�
    std::vector<UIImage*>     m_vTotalReadedBooks;//�Ķ�����鼮������ͼ���б�
};

#endif


