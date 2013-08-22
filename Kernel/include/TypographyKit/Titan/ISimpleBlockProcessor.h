//===========================================================================
// Summary:
//		���ڼ򵥿���Ű洦�����ӿڡ�
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-08-31
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef	__SIMPLEBLOCKPROCESSOR_INTERFACE_HEADERFILE__
#define __SIMPLEBLOCKPROCESSOR_INTERFACE_HEADERFILE__

//===========================================================================

#include "ITitanPart.h"

//===========================================================================

class ISimpleBlockProcessor : public ITitanPart
{
public:
	//-------------------------------------------
	//	Summary:
	//		װ�ض�Ӧ�ַ��������塣
	//  Parameters:
	//		[in] csType				- �ַ������͡�
	//		[in] pszFontFaceName	- �������֡�
	//		[in] dFontSize			- �����С��
	//	Remarks:
	//		Ŀǰֻ֧��TP_CHARSET_PRC��TP_CHARSET_ANSI������룬�Դ�����������û��ʵ��LoadFont�ӿڡ�
	//		��ˣ�ʹ���Դ�����������ʱ��Ҫ������ӿ�װ�����塣
	//	Return Value:
	//		����ɹ��򷵻�true�����򷵻�false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool LoadFont(TP_CHARSET_TYPE csType, const TP_WCHAR* pszFontFaceName, double dFontSize) = 0;

	//-------------------------------------------
	//	Summary:
	//		װ�ض�Ӧ�ַ��������塣
	//  Parameters:
	//		[in] csType				- �ַ������͡�
	//		[in] pszFontFilePath	- �����ļ�ȫ·������
	//		[in] dFontSize			- �����С��
	//	Remarks:
	//		���ô˷�����������һ��װ�ص�ͬ�ַ������壬Ŀǰֻ֧��TP_CHARSET_PRC��TP_CHARSET_ANSI������롣
	//	Return Value:
	//		����װ�سɹ��򷵻�true�����򷵻�false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool LoadFontFile(TP_CHARSET_TYPE csType, const TP_WCHAR* pszFontFilePath, double dFontSize) = 0;

	//-------------------------------------------
	//	Summary:
	//		�����ֺŴ�С��
	//  Parameters:
	//		[in] dFontSize		- �ֺŴ�С��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void SetFontSize(double dFontSize) = 0;

	//-------------------------------------------
	//	Summary:
	//		����Tab�Ʊ�λ����λΪ�ֺŴ�С��
	//  Parameters:
	//		[in] dTabStop		- �Ʊ�λ���롣
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void SetTabStop(double dTabStop) = 0;

	//-------------------------------------------
	//	Summary:
	//		��������������
	//  Parameters:
	//		[in] dIndent		- �����������룬��λΪ�ֺŴ�С��
	//	Remarks:
	//		�������������������������Ĭ�ϲ�������
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void SetFirstLineIndent(double dIndent) = 0;

	//-------------------------------------------
	//	Summary:
	//		���ö��뷽ʽ��
	//  Parameters:
	//		[in] aType			- ���뷽ʽ��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void SetAlignType(TP_ALIGN_TYPE aType) = 0;

	//-------------------------------------------
	//	Summary:
	//		�����м�ࡣ
	//  Parameters:
	//		[in] dLineGap		- �м�࣬�����иߵı�����
	//	Remarks:
	//		����������м�࣬�����������õ����и���ΪĬ���м�ࡣ
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void SetLineGap(double dLineGap) = 0;

	//-------------------------------------------
	//	Summary:
	//		���öμ�ࡣ
	//  Parameters:
	//		[in] dParaGap		- �μ�࣬�����иߵı�����
	//	Remarks:
	//		��������öμ�࣬������Ĭ�϶μ��Ϊ0��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void SetParaSpacing(double dParaSpacing) = 0;

	//-------------------------------------------
	//	Summary:
	//		�������ٷֱȣ��������������Ҫ��Hyphen����
	//  Parameters:
	//		[in] dStretchRate		- �������ٷֱȡ�
	//	Remarks:
	//		�ڲ����Ժ�����
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void SetStretchMaxRate(double dStretchRate) = 0;

public:
	//-------------------------------------------
	//	Summary:
	//		�������֡�
	//  Parameters:
	//		[in] pszSrcText		- ���Ű�����ִ���
	//		[in] bFastMode		- ����ģʽ����ģʽ�²���ö���Ű�����
	//	Return Value:
	//		����ȫ������ɹ�����TP_LAYOUT_SUCCEED��
	//		�������뻹�к�������TP_LAYOUT_FOLLOWAFTER��
	//		����ʧ���򷵻�TP_LAYOUT_FAIL��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual TP_LAYOUT_STATE ProcessText(const TP_WCHAR* pszSrcText, bool bFastMode = false) = 0;

	//-------------------------------------------
	//	Summary:
	//		�������֣�����ָ����ʼ״̬������
	//  Parameters:
	//		[in] pszSrcText		- ���Ű�����ִ���
	//		[in] isp			- ��ʼ״̬����������ָ����ǰ����ʼλ���Ƿ����¶��䡣
	//		[in] bFastMode		- ����ģʽ����ģʽ�²���ö���Ű�����
	//	Return Value:
	//		����ȫ������ɹ�����TP_LAYOUT_SUCCEED��
	//		�������뻹�к�������TP_LAYOUT_FOLLOWAFTER��
	//		����ʧ���򷵻�TP_LAYOUT_FAIL��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual TP_LAYOUT_STATE ProcessTextEx(const TP_WCHAR* pszSrcText, const TP_INITIALSTATEPARA& isp, bool bFastMode = false) = 0;
};

//===========================================================================

#endif	//#ifndef __SIMPLEBLOCKPROCESSOR_INTERFACE_HEADERFILE__
