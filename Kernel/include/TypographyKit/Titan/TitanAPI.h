//===========================================================================
// Summary:
//		Titan��һ������������Ч���Ű����档
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-08-18
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef	__TITANAPI_HEADERFILE__
#define __TITANAPI_HEADERFILE__

//===========================================================================

#include "TitanDef.h"
#include "ITitanPart.h"
#include "ILayoutEnumerator.h"
#include "ITitanFontEngine.h"
#include "ISimpleBlockLayoutEnumerator.h"
#include "ISimpleBlockProcessor.h"
#include "IComplexBlockLayoutEnumerator.h"
#include "IComplexBlockProcessor.h"
#include "IHTMLBlockLayoutEnumerator.h"
#include "IHTMLBlockProcessor.h"

//===========================================================================

//---------------------------------------------------------------------------
//	Summary:
//		��ʼ��Titan��ʹ��TitanProcessor�е��κκ�������֮ǰ�����ȵ��ñ�������
//	Parameters:
//	    [in] szResourceDir - TitanProcessor��Դ����·������·���°���TitanProcessor�����ResourceĿ¼��
//	Remarks:
//		szResourceDir����Ϊ�ջ򲻺Ϸ�������ѡ�����ģ������Ŀ¼(��ǰʵ��:WindowsȡDLL����Ŀ¼��Linux��ƽ̨ȡ��ִ�г���Ŀ¼)��
//  Availability:
//		��Titan 1.0��ʼ֧�֡�
//---------------------------------------------------------------------------
TITANAPI TP_Initialize(TP_WCHAR* szResourceDir = NULL);

//---------------------------------------------------------------------------
//	Summary:
//		ִ�������ڲ���ʹ��TitanProcessor����á�
//  Availability:
//		��Titan 1.0��ʼ֧�֡�
//---------------------------------------------------------------------------
TITANAPI TP_Destroy();

//===========================================================================

//---------------------------------------------------------------------------
//	Summary:
//		�����򵥿���Ű洦������
//	Parameters:
//		[in] rcBlock					- ��߽���Ρ�
//		[in] msType						- ���������õĶ�����λ��
//		[in] nDPI						- DPI��������msType = TP_MEASURE_PIXELʱ��Ч��
//		[in] pCustomFontEngine			- �û��Զ����������档
//	Remarks:
//		rcBlock��λ������msType��ö�����е����ݵ�λҲ��msType��
//		pCustomFontEngine=NULLʱʹ���Ű������Դ����������档
//	Return Value:
//		����ɹ����ؿ鴦����ָ�룬���򷵻�Null��
//  Availability:
//		��Titan 1.0��ʼ֧�֡�
//---------------------------------------------------------------------------
TITANAPI_(ISimpleBlockProcessor*) CreateSimpleBlockProcessor(const TP_BOX& rcBlock,
                                                             TP_MEASURE_TYPE msType,
                                                             int nDPI,
                                                             ITitanFontEngine* pCustomFontEngine);

//---------------------------------------------------------------------------
//	Summary:
//		ɾ���򵥿���Ű洦������
//	Parameters:
//		[in] pProcessor		- ��ɾ���Ŀ鴦����ָ�롣
//	Return Value:
//		����ɹ�ɾ������true�����򷵻�false��
//  Availability:
//		��Titan 1.0��ʼ֧�֡�
//---------------------------------------------------------------------------
TITANAPI DestroySimpleBlockProcessor(ISimpleBlockProcessor* pProcessor);

//---------------------------------------------------------------------------
//	Summary:
//		�������ӿ���Ű洦������
//	Parameters:
//		[in] rcBlock					- ��߽���Ρ�
//		[in] msType						- ���������õĶ�����λ��
//		[in] nDPI						- DPI��������msType = TP_MEASURE_PIXELʱ��Ч��
//	Remarks:
//		rcBlock��λ������msType��ö�����е����ݵ�λҲ��msType��
//		pCustomFontEngine=NULLʱʹ���Ű������Դ����������档
//	Return Value:
//		����ɹ����ؿ鴦����ָ�룬���򷵻�Null��
//  Availability:
//		��Titan 1.0��ʼ֧�֡�
//---------------------------------------------------------------------------
TITANAPI_(IComplexBlockProcessor*) CreateComplexBlockProcessor(const TP_BOX& rcBlock,
                                                               TP_MEASURE_TYPE msType,
                                                               int nDPI,
                                                               ITitanFontEngine* pCustomFontEngine);

//---------------------------------------------------------------------------
//	Summary:
//		ɾ�����ӿ���Ű洦������
//	Parameters:
//		[in] pProcessor		- ��ɾ���Ŀ鴦����ָ�롣
//	Return Value:
//		����ɹ�ɾ������true�����򷵻�false��
//  Availability:
//		��Titan 1.0��ʼ֧�֡�
//---------------------------------------------------------------------------
TITANAPI DestroyComplexBlockProcessor(IComplexBlockProcessor* pProcessor);

//---------------------------------------------------------------------------
//	Summary:
//		�����������ṹ�Ŀ��Ű洦����������EPUBת����
//	Parameters:
//		[in] rcBlock					- ��߽���Ρ�
//		[in] msType						- ���������õĶ�����λ��
//		[in] nDPI						- DPI��������msType = TP_MEASURE_PIXELʱ��Ч��
//		[in] hContentProvider			- �������ṩ��������
//		[in] pfnReadHTMLContentProc		- ��ȡ���������ݵĻص�������ڡ�
//		[in] pCustomFontEngine			- �û��Զ����������档
//	Remarks:
//		rcBlock��λ������msType��ö�����е����ݵ�λҲ��msType��
//		pCustomFontEngine=NULLʱʹ���Ű������Դ����������档
//		�û���Ҫ�Լ�ʵ�ֶ�ȡ���������ݵĻص�������
//	Return Value:
//		����ɹ����ؿ鴦����ָ�룬���򷵻�Null��
//  Availability:
//		��Titan 1.0��ʼ֧�֡�
//---------------------------------------------------------------------------
TITANAPI_(IHTMLBlockProcessor*) CreateHTMLBlockProcessor(const TP_BOX& rcBlock,
                                                         TP_MEASURE_TYPE msType,
                                                         int nDPI,
                                                         TP_HANDLE hContentProvider,
                                                         PFNREADHTMLCONTENTPROC pfnReadHTMLContentProc,
                                                         ITitanFontEngine* pCustomFontEngine);

//---------------------------------------------------------------------------
//	Summary:
//		ɾ���������ṹ�Ŀ��Ű洦����������EPUBת����
//	Parameters:
//	   [in] pProcessor		- ��ɾ���Ŀ鴦����ָ�롣
//	Return Value:
//		����ɹ�ɾ������true�����򷵻�false��
//  Availability:
//		��Titan 1.0��ʼ֧�֡�
//---------------------------------------------------------------------------
TITANAPI DestroyHTMLBlockProcessor(IHTMLBlockProcessor* pProcessor);

//===========================================================================

#endif	//#ifndef __TITANAPI_HEADERFILE__
