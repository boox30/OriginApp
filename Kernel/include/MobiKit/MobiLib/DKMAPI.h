//===========================================================================
//  Summary:
//      MobiLib�����ӿڡ�
//  Usage:
//      Null
//  Remarks:
//      Null
//  Date:
//      2011-09-15
//  Author:
//      Zhai Guanghe (zhaigh@duokan.com)
//===========================================================================

#ifndef __KERNEL_MOBIKIT_MOBILIB_EXPORT_DKMAPI_H__
#define __KERNEL_MOBIKIT_MOBILIB_EXPORT_DKMAPI_H__

#include "DKMDef.h"

//-------------------------------------------
//  Summary:
//      ��ʼ��MobiLib��ʹ��MobiLib�е��κνӿ�֮ǰ�����ȵ��ñ�������
//  Parameters:
//      [in] pResourceDir - ePubLib��Դ����·������·���°���ePubLib�����ResourceĿ¼��
//  Return Value:
//      ����ɹ��򷵻�DK_TRUE�����򷵻�DK_FALSE��
//  Remarks:
//      pResourceDir����Ϊ�ջ򲻺Ϸ�������ѡ�����ģ������Ŀ¼(��ǰʵ��:WindowsȡDLL����Ŀ¼��Linux��ƽ̨ȡ��ִ�г���Ŀ¼)��
//  Availability:
//      ��MobiLib 1.0.8��ʼ֧�֡�
//-------------------------------------------
MOBIAPI DKM_Initialize(const DK_WCHAR *pResourceDir);

//-------------------------------------------
//  Summary:
//      ִ�����������
//  Parameters:
//      Null
//  Return Value:
//      ����ɹ��򷵻� DK_TRUE�����򷵻� DK_FALSE��
//  Remarks:
//      Null
//  Availability:
//      ��MobiLib 1.0.8��ʼ֧�֡�
//-------------------------------------------
MOBIAPI DKM_Destroy();

//-------------------------------------------
//  Summary:
//        ��һ��Mobi�ĵ���
//    Parameters:
//        [in] pBookPath     - �ļ�·����
//        [in] pWorkingDir   - Mobi�ļ�����·����һ����Ϊϵͳ����ʱĿ¼����Ŀ¼��Ҫ��дȨ�ޡ�
//  Return Value:
//      ����ɹ�����Mobi�ĵ������������򷵻� DK_NULL��
//    Remarks:
//        pWorkingDir����Ϊ�ջ򲻺Ϸ�������ʹ��ϵͳ��ʱ�ļ�Ŀ¼��
//  Availability:
//        ��MobiLib 1.0.8��ʼ֧�֡�
//-------------------------------------------
MOBIAPI_(MOBIDOCHANDLE) DKM_OpenDocument(const DK_WCHAR *pBookPath, const DK_WCHAR *pWorkingDir);

//-------------------------------------------
//  Summary:
//        �ر�һ��Mobi�ĵ���
//    Parameters:
//        [in] hFile    - Mobi�ĵ���������
//  Return Value:
//      ����ɹ��򷵻� DK_TRUE�����򷵻� DK_FALSE��
//  Remarks:
//      Null
//  Availability:
//        ��MobiLib 1.0.8��ʼ֧�֡�
//-------------------------------------------
MOBIAPI DKM_CloseDocument(MOBIDOCHANDLE hFile);

//-------------------------------------------
//    Summary:
//        �����������ֵ������ļ��Ķ�Ӧ��ϵ�����øýӿں�Ӱ����Ӧ�������ʾ��
//    Parameters:
//        [in] pFontFaceName     - �������֡�
//        [in] pFontFilePath     - �����ļ���·����
//  Return Value:
//        ����ɹ��򷵻� DK_TRUE�����򷵻� DK_FALSE��
//  Remarks:
//      Null
//  Availability:
//        ��MobiLib 1.0.8��ʼ֧�֡�
//-------------------------------------------
MOBIAPI DKM_RegisterFont(const DK_WCHAR *pFontFaceName, const DK_WCHAR *pFontFilePath);

//-------------------------------------------
// Summary:
//        ������ʾʹ�õ�Ĭ���������֣����ڲ����ڵ����壬����ʱ��ʹ�ø�Ĭ�����塣
// Parameters:
//        [in] pDefaultFontFaceName       - Ĭ���������֡�
//        [in] charset                    - �ַ������μ� DK_CHARSET_TYPE ö��ֵ˵����
//  Return Value:
//        ����ɹ��򷵻� DK_TRUE�����򷵻� DK_FALSE��
//  Remarks:
//      Null
//  Availability:
//        ��MobiLib 1.0.8��ʼ֧�֡�
//-------------------------------------------
MOBIAPI DKM_SetDefaultFont(const DK_WCHAR *pDefaultFontFaceName, DK_CHARSET_TYPE charset);

//-------------------------------------------
// Summary:
//		�����Ƿ�ʹ��ͼ��ԭ�з�񣬰����м�ࡢ�μ�ࡢ����������
// Parameters:
//		[in] bUseBookStyle      - �Ƿ�ʹ��ͼ��ԭ�з��
//  Return Value:
//		Null
//  Remarks:
//      Null
//  Availability:
//		��MobiLib 1.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI_(void) DKM_SetUseBookStyle(DK_BOOL bUseBookStyle);

//===========================================================================

#endif // #__KERNEL_MOBIKIT_MOBILIB_EXPORT_DKMAPI_H__
