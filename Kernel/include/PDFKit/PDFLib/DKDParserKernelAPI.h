//===========================================================================
// Summary:
//      DKDParserKernelAPI.h
//      Kernel ��� API ���
// Usage:
//      �ṩ KernelAPI ��������ڣ�ʹ�� Kernel ֻ��Ҫ��������ļ����ɡ�
//      ��ʹ���κνӿ�֮ǰ������Ҫ���� DKP_Initialize �������г�ʼ����
//      ʹ����Ϻ���� DKP_Destroy ����ж�ء�
//      �� Linux ƽ̨�� Mac ���ƽ̨Ҫ���� _LINUX �꣬������ Mac ƽ̨
//      Ҫ���ⶨ��_ MACOS ��
// Remarks:
//      Null
// Date:
//      2011-9-16
// Author:
//      Liu Hongjia (liuhj@duokan.com)
//===========================================================================

#ifndef __KERNEL_PDFKIT_PDFLIB_DKDPARSERKERNELAPI_H__
#define __KERNEL_PDFKIT_PDFLIB_DKDPARSERKERNELAPI_H__

#include "KernelRetCode.h"

// ���ͽӿڶ���
#include "DKPTypeDef.h"

// �ĵ�����ؽӿ���
#include "IDKPDoc.h"
#include "IDKPPage.h"
#include "IDKPOutline.h"
#include "IDKPPageDistiller.h"

#ifndef _LINUX
// �ĵ��޸Ĳ����������
class IDKPModifyDoc;
class IDKPProcDoc;
class IDKPWaterMarkDoc;
#endif

//-------------------------------------------
// Summary:
//      ��ʼ��DKDParserKernel��ʹ�� DKDParserKernel �е��κκ�������֮ǰ�����ȵ��ñ�������
// Parameters:
//      [in] pResourceDir - DKP Kernel ��Դ����·������·���°��� DKP Kernel �����
//                          Resource Ŀ¼��
// Remarks:
//      pResourceDir ����Ϊ�ջ򲻺Ϸ�������ѡ�����ģ������Ŀ¼(��ǰʵ��:WindowsȡDLL
//      ����Ŀ¼��Linux��ƽ̨ȡ��ִ�г���Ŀ¼)��
// SDK Version:
//      �� DKP 1.0 ��ʼ֧��
//-------------------------------------------
DKPKERNELAPI DKP_Initialize(const DK_WCHAR* pResourceDir = DK_NULL);

//-------------------------------------------
// Summary:
//      ִ�������ڲ���ʹ�� DKDParserKernel ����á�
// SDK Version:
//      �� DKP 1.0 ��ʼ֧��
//-------------------------------------------
DKPKERNELAPI DKP_Destroy();

//-------------------------------------------
// Summary:
//      ע�������ļ���
// Parameters:
//      [in] pFontFaceName - ����� Facename������������ƥ�䡣
//      [in] pFontFile     - �����ļ��ľ���·����
// SDK Version:
//      �� DKP 1.0 ��ʼ֧��
//-------------------------------------------
DKPKERNELAPI DKP_RegisterFontFaceName(const DK_WCHAR* pFontFaceName, const DK_WCHAR* pFontFile);

//-------------------------------------------
// Summary:
//      ��ȡ��������ʾ�ı�ʱ�Ƿ�����ת������ѡ��Դ򿪵������ĵ���Ч��
// Parameters:
//      [in] bGBToBig5 - �Ƿ�����ת����
// SDK Version:
//      �� DKP 1.0 ��ʼ֧��
//-------------------------------------------
DKPKERNELAPI DKP_GetGBToBig5(DK_BOOL &gbToBig5);
DKPKERNELAPI DKP_SetGBToBig5(DK_BOOL gbToBig5);

//-------------------------------------------
// Summary:
//      �Ƿ�ʹ����ɫת������������øĺ�����Ĭ��ʹ�á�
// Parameters:
//      [in] useColorCMS - �Ƿ�ʹ����ɫת����
// SDK Version:
//      �� DKP 1.0 ��ʼ֧��
//-------------------------------------------
DKPKERNELAPI DKP_SetUseColorCMS(DK_BOOL useColorCMS);

//-------------------------------------------
// Summary:
//		�����Ƿ�ʹ��ͼ��ԭ�з�񣬰����м�ࡢ�μ�ࡢ�����������ո����
// Parameters:
//		[in] bUseBookStyle      - �Ƿ�ʹ��ͼ��ԭ�з��
//  Return Value:
//		Null
//  Remarks:
//      Null
//  Availability:
//		�� PDFLib 2.6.0 ��ʼ֧�֡�
//-------------------------------------------
DKPKERNELAPI DKP_SetUseBookStyle(DK_BOOL bUseBookStyle);

//-------------------------------------------
// Summary:
//      �����ĵ�����
// Parameters:
//      [out] pDoc - ͨ�� DKP_CreateDoc ������ Doc ����
// SDK Version:
//      �� DKP 1.0 ��ʼ֧��
//-------------------------------------------
DKPKERNELAPI DKP_CreateDoc(IDKPDoc*& pDoc);

//-------------------------------------------
// Summary:
//      �����ĵ�����
// Parameters:
//      [out] pDoc - ͨ�� DKP_CreateDoc ������ Doc ����
// SDK Version:
//      �� DKP 1.0 ��ʼ֧��
//-------------------------------------------
DKPKERNELAPI DKP_DestroyDoc(IDKPDoc*& pDoc);

#endif // #ifndef __KERNEL_PDFKIT_PDFLIB_DKDPARSERKERNELAPI_H__
