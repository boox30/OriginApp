//===========================================================================
// Summary:
//		����HTML���ṹ�Ŀ��Ű洦�����ӿڣ���Ҫ����EPUB��Ⱦ��
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-09-13
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef	__HTMLBLOCKPROCESSOR_INTERFACE_HEADERFILE__
#define __HTMLBLOCKPROCESSOR_INTERFACE_HEADERFILE__

//===========================================================================

#include "ITitanPart.h"

//===========================================================================

// ���ݿ��ȡ�Ļص��ӿڣ��������������ĩβ����false�����򷵻�true��
typedef bool (*PFNREADHTMLCONTENTPROC)(TP_HANDLE hContentProvider, TP_CONTENTPIECE& piece);

//===========================================================================

class ILayoutBoundary;

class IHTMLBlockProcessor : public ITitanPart
{
public:
    //-------------------------------------------
    //  Summary:
    //      �����Ű�����
    //  Parameters:
    //      [in] pLayoutBoundary    - �Ű�����
    //  Return Value:
    //  Availability:
    //-------------------------------------------
    virtual void SetBoundary(const ILayoutBoundary *pLayoutBoundary) = 0;

	//-------------------------------------------
	//	Summary:
	//		�������ݡ�
	//  Parameters:
	//		Null
	//	Return Value:
	//		������ȫ������ɹ�����TP_LAYOUT_SUCCEED��
	//		�������뻹�к�������TP_LAYOUT_FOLLOWAFTER��
	//		����ʧ���򷵻�TP_LAYOUT_FAIL��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual TP_LAYOUT_STATE ProcessContent() = 0;

	//-------------------------------------------
	//	Summary:
	//		�������ݡ�
	//  Parameters:
	//		[in] isp			- ��ʼ״̬����������ָ����ǰ����ʼλ���Ƿ����¶��䡣
	//		[in] bFastMode		- ����ģʽ����ģʽ�²���ö���Ű�����
	//	Return Value:
	//		������ȫ������ɹ�����TP_LAYOUT_SUCCEED��
	//		�������뻹�к�������TP_LAYOUT_FOLLOWAFTER��
	//		����ʧ���򷵻�TP_LAYOUT_FAIL��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual TP_LAYOUT_STATE ProcessContentEx(const TP_INITIALSTATEPARA& isp, bool bFastMode = false) = 0;

	//-------------------------------------------
	//	Summary:
	//		�������ݣ���ǿ�ƻ��У���֧�����ţ�ö�����еĽ���ǿ�Ⱥ͸߶����޴��ʱ��Ľ����
	//  Parameters:
	//		[in] isp			- ��ʼ״̬����������ָ����ǰ����ʼλ���Ƿ����¶��䡣
	//		[out] dMinLineLen	- ��С�п�ȡ�
	//		[out] dMaxLineLine	- ����п�ȡ�
	//	Return Value:
	//		������ȫ������ɹ�����TP_LAYOUT_SUCCEED��
	//		�������뻹�к�������TP_LAYOUT_FOLLOWAFTER��
	//		����ʧ���򷵻�TP_LAYOUT_FAIL��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual TP_LAYOUT_STATE ProcessContentNotForcedBreakLine(const TP_INITIALSTATEPARA& isp, double& dMinLineLen, double& dMaxLineLen) = 0;

    //-------------------------------------------
	//	Summary:
	//		���ö�ȡ���������ݵĻص��ӿڡ�
	//  Parameters:
	//		[in] hContentProvider			- �������ṩ��������
	//		[in] pfnReadHTMLContentProc     - ��ȡ���������ݵĻص�������ڡ�
    //  Return Value:
    //      Null
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void SetReadHTMLContentProc(TP_HANDLE hContentProvider, PFNREADHTMLCONTENTPROC pfnReadHTMLContentProc) = 0;

    //-------------------------------------------
    //	Summary:
    //		��ȡ��ǰ�Ű�߶ȣ����ſ��á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ��ǰ�Ű�߶ȡ�
    //  Availability:
    //		��Titan 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual double GetLayoutHeight() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��ǰ�Ű������һ�еĸ߶ȣ����ſ��á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ���һ�еĸ߶ȡ�
    //  Availability:
    //      ��Titan 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual double GetLastLineHeight() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��ǰ�Ű������һ�е��м�࣬���ſ��á�
    //  Parameters:
    //      Null
    //  Return Value:
    //      ���һ�е��м�ࡣ
    //  Availability:
    //      ��Titan 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual double GetLastLineGap() = 0;

    //-------------------------------------------
    //	Summary:
    //		�Ƿ�������һ�У������Ű�����߶Ȳ���������һ��ʱ����������һ�С�
    //  Parameters:
    //		[bool] bAtLeastProcessOneLine - �Ƿ�������һ�С�
    //-------------------------------------------
    virtual void SetAtLeastProcessOneLine(bool bAtLeastProcessOneLine) = 0;

    //-------------------------------------------
    //	Summary:
    //		��������Ѫ���ȣ��������Ű�����ĳ��ȡ�
    //		Ĭ����-1����ֵΪ�����򲻿�������Ѫ���ȵ����ơ�
    //		��ʽ��������ʱ���������������ֹ�����ַ�����������ʽ���Ű�������±߽硣
    //      �������Ű��������Ҫ���µ�������ӿڸ�ֵΪĬ��ֵ��
    //  Parameters:
    //		[double] dMaxBleedLength	- �����Ű�����ĳ��ȡ�
    //-------------------------------------------
    virtual void SetMaxBleedLength(double dMaxBleedLength) = 0;

    //-------------------------------------------
    //	Summary:
    //		����ǿ�Ƴ�Ѫģʽ���ڲ�ePublibʹ�á�
    //  Parameters:
    //		[bool] bForceBleed	- �Ƿ�ǿ�Ƴ�Ѫ��
    //-------------------------------------------
    virtual void SetForceBleed(bool bForceBleed) = 0;
};

//===========================================================================

#endif	//#ifndef __HTMLBLOCKPROCESSOR_INTERFACE_HEADERFILE__
