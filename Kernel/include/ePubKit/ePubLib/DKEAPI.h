//===========================================================================
// Summary:
//		ePubLib�����ӿڡ�
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-09-15
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_DKEAPI_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_DKEAPI_H__

//===========================================================================

#include "DKEDef.h"
#include "DKEEPUBDef.h"
#include "DKEError.h"
#include "IDKEFootnoteIterator.h"
#include "IDKEGalleryIterator.h"
#include "IDKEHitableObjIterator.h"
#include "IDKEImageIterator.h"
#include "IDKEMediaIterator.h"
#include "IDKEPreBlockIterator.h"
#include "IDKETextIterator.h"
#include "IDKEImgBlockIterator.h"
#include "IDKEGallery.h"
#include "IDKEMultiCallout.h"
#include "IDKEBook.h"
#include "IDKEComicsFrame.h"
#include "IDKEComicsFrameIterator.h"
#include "IDKEFlexPage.h"
#include "IDKEPage.h"
#include "IDKEPageUnit.h"
#include "IDKESection.h"
#include "IDKETocPoint.h"

class IDkStream;

//===========================================================================

//-------------------------------------------
//	Summary:
//		��ʼ��ePubLib��ʹ��ePubLib�е��κνӿ�֮ǰ�����ȵ��ñ�������
//	Parameters:
//	    [in] szResourceDir - ePubLib��Դ����·������·���°���ePubLib�����ResourceĿ¼��
//  Return Value:
//      ����ɹ��򷵻�DK_TRUE�����򷵻�DK_FALSE��
//	Remarks:
//		szResourceDi r����Ϊ�ջ򲻺Ϸ�������ѡ�����ģ������Ŀ¼(��ǰʵ��:WindowsȡDLL����Ŀ¼��Linux��ƽ̨ȡ��ִ�г���Ŀ¼)��
//  Availability:
//		��ePubLib 1.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI DKE_Initialize(const DK_WCHAR* szResourceDir);

//-------------------------------------------
//	Summary:
//		ִ�����������
//	Parameters:
//      Null
//  Return Value:
//      ����ɹ��򷵻� DK_TRUE�����򷵻� DK_FALSE��
//  Remarks:
//      Null
//  Availability:
//		��ePubLib 1.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI DKE_Destroy();

//-------------------------------------------
//  Summary:
//		��һ�� ePub �ĵ���
//	Parameters:
//		[in] szBookPath     - �ļ�·����
//      [in] containerType  - ePub�������͡�
//	    [in] szWorkingDir   - ePub�ļ�����·����һ����Ϊϵͳ����ʱĿ¼����Ŀ¼��Ҫ��дȨ�ޡ�
//  Return Value:
//      ����ɹ����� ePub �ĵ������������򷵻� DK_NULL��
//	Remarks:
//		szWorkingDir ����Ϊ�ջ򲻺Ϸ�������ʹ��ϵͳ��ʱ�ļ�Ŀ¼��
//  Availability:
//		�� ePubLib 1.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI_(EPUBDOCHANDLE) DKE_OpenDocument(const DK_WCHAR* szBookPath,
										 DKE_CONTAINER_TYPE containerType,
										 const DK_WCHAR* szWorkingDir);

//-------------------------------------------
//  Summary:
//		��һ�����ܵ� ePub �ĵ���
//	Parameters:
//		[in] szBookPath     - �ļ�·����
//      [in] containerType  - ePub�������͡�
//	    [in] szWorkingDir   - ePub�ļ�����·����һ����Ϊϵͳ����ʱĿ¼����Ŀ¼��Ҫ��дȨ�ޡ�
//      [in] contentKey     - ���ݼ�����Կ��
//  Return Value:
//      ����ɹ����� ePub �ĵ������������򷵻� DK_NULL��
//	Remarks:
//		szWorkingDir ����Ϊ�ջ򲻺Ϸ�������ʹ��ϵͳ��ʱ�ļ�Ŀ¼��
//      ����contentKey�Ƿ�Ϊ�ն���DKE_OpenDocument�����̡�
//  Availability:
//		�� ePubLib 1.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI_(EPUBDOCHANDLE) DKE_OpenDRMDocument(const DK_WCHAR* szBookPath,
                                            DKE_CONTAINER_TYPE containerType,
                                            const DK_WCHAR* szWorkingDir,
                                            const DKE_DRMKEY* contentKey);


//-------------------------------------------
//  Summary:
//		ͨ���ṹ�����ݴ�ePub�ĵ�
//	Parameters:
//		[in] szBookPath     - �ļ�·����
//      [in] containerType  - ePub�������͡�
//	    [in] szWorkingDir   - ePub�ļ�����·����һ����Ϊϵͳ����ʱĿ¼����Ŀ¼��Ҫ��дȨ�ޡ�
//      [in] opfData        - OPF����
//      [in] pTocData       - toc��XML�ļ��ı�������UTF8����
//      [in] encData        - ��������
//      [in] extData        - �࿴��չ����
//  Return Value:
//      ����ɹ����� ePub �ĵ������������򷵻� DK_NULL��
//	Remarks:
//		szWorkingDir ����Ϊ�ջ򲻺Ϸ�������ʹ��ϵͳ��ʱ�ļ�Ŀ¼��
//  Availability:
//		�� ePubLib 1.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI_(EPUBDOCHANDLE) DKE_OpenDocumentByStructData(const DK_WCHAR* szBookPath, 
                                                    DKE_CONTAINER_TYPE containerType, 
                                                    const DK_WCHAR* szWorkingDir,
                                                    DKE_PACK_MODE packMode,
                                                    const DKEOPFData& opfData,
                                                    const DK_CHAR* pTocData,
                                                    const DKEEncryptionData& encData,
                                                    const DKEExtensionData& extData);

//-------------------------------------------
//  Summary:
//		�ر�һ�� ePub �ĵ���
//	Parameters:
//		[in] hFile	- ePub �ĵ���������
//  Return Value:
//      ����ɹ��򷵻� DK_TRUE�����򷵻� DK_FALSE��
//  Remarks:
//      Null
//  Availability:
//		��ePubLib 1.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI DKE_CloseDocument(EPUBDOCHANDLE hFile);

#if DKE_SUPPORT_HTML
//-------------------------------------------
//  Summary:
//		��һ�� html �ĵ���
//	Parameters:
//		[in] szBookPath     - �ļ�·����
//	    [in] szWorkingDir   - ePub�ļ�����·����һ����Ϊϵͳ����ʱĿ¼����Ŀ¼��Ҫ��дȨ�ޡ�
//  Return Value:
//      ����ɹ����� html �ĵ������������򷵻� DK_NULL��
//	Remarks:
//		szWorkingDir ����Ϊ�ջ򲻺Ϸ�������ʹ��ϵͳ��ʱ�ļ�Ŀ¼��
//  Availability:
//		�� ePubLib 1.1.1 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI_(HTMLDOCHANDLE) DKE_OpenHTMLDocument(const DK_WCHAR* szBookPath,
										 const DK_WCHAR* szWorkingDir);
#endif

//-------------------------------------------
//  Summary:
//		��һ��HTML��Ƭ��
//	Parameters:
//		[in] pHTMLStream    - HTML��Ƭ��
//	    [in] pHTMLPath      - HTML�Ļ���·�������ڻ�ȡHTML�����ӵ�CSS��ͼ�����������
//      [in] showType       - ����չ�ַ�ʽ��������ҳģʽ�͹���ģʽ
//  Return Value:
//      ����ɹ����ظ�HTMLƬ�ζ�Ӧ��չ�־�������򷵻� DK_NULL��
//	Remarks:
//		���������pHTMLPath����Ƭ�������ӵ��ⲿ��Դ������Ч��
//      ��Ҫ����showTypeʹ��DKE_SHOWCONTENT_HANDLE�еķ���ֵ
//  Availability:
//		�� ePubLib 2.3.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI_(DKE_SHOWCONTENT_HANDLE) DKE_OpenHTMLFragment(IDkStream* pHTMLStream, 
                                                    const DK_WCHAR* pHTMLPath,
                                                    DKE_HTMLSTYLE_TYPE htmlStyle,
                                                    DKE_SHOWCONTENT_TYPE showType);

//-------------------------------------------
//  Summary:
//		�ر�һ��HTMLƬ�εľ��
//	Parameters:
//		[in] pHandle    - HTML��Ƭ�ζ�Ӧ�Ľ�����ľ��
//  Return Value:
//      ����ɹ��򷵻� DK_TRUE�����򷵻� DK_FALSE��
//	Remarks:
//		Null
//  Availability:
//		�� ePubLib 2.3.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI DKE_CloseHTMLFragment(DKE_SHOWCONTENT_TYPE showType, DKE_SHOWCONTENT_HANDLE handle);


//-------------------------------------------
//	Summary:
//		�����������ֵ������ļ��Ķ�Ӧ��ϵ�����øýӿں�Ӱ����Ӧ�������ʾ��
//	Parameters:
//		[in] szFontFaceName     - �������֡�
//		[in] szFontFile         - �����ļ���·����
//  Return Value:
//		����ɹ��򷵻� DK_TRUE�����򷵻� DK_FALSE��
//  Remarks:
//      Null
//  Availability:
//		��ePubLib 1.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI DKE_RegisterFont(const DK_WCHAR* szFontFaceName, const DK_WCHAR* szFontFilePath);

//-------------------------------------------
//	Summary:
//		ע�������塣
//	Parameters:
//		[in] pFontFamily     - �����塣
//		[in] nCount          - ����������
//  Return Value:
//		����ɹ��򷵻� DK_TRUE�����򷵻� DK_FALSE��
//  Remarks:
//      Null
//  Availability:
//		��ePubLib 2.1.1 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI DKE_RegisterFontFamily(DK_FONTFAMILY* pFontFamily, DK_INT nCount);

//-------------------------------------------
//	Summary:
//		��ע��������
//	Parameters:
//		[in] szFontFaceName     - �������֡�
//  Return Value:
//		����ɹ��򷵻� DK_TRUE�����򷵻� DK_FALSE��
//  Remarks:
//      ����� face name �ڽӿڵ���֮ǰ��Ĭ�����壬��� face name ��Ӧ��Ĭ���������ý�ʧЧ��
//      ��Ҫ�����µ�Ĭ������
//  Availability:
//		��ePubLib 2.1.1 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI DKE_UnregisterFont(const DK_WCHAR* szFontFaceName);

//-------------------------------------------
// Summary:
//		������ʾʹ�õ�Ĭ���������֣����ڲ����ڵ����壬����ʱ��ʹ�ø�Ĭ�����塣
// Parameters:
//		[in] szDefaultFontFaceName      - Ĭ���������֡�
//		[in] charset                    - �ַ������μ� DK_CHARSET_TYPE ö��ֵ˵����
//  Return Value:
//		����ɹ��򷵻� DK_TRUE�����򷵻� DK_FALSE��
//  Remarks:
//      Null
//  Availability:
//		��ePubLib 1.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI DKE_SetDefaultFont(const DK_WCHAR* szDefaultFontFaceName, DK_CHARSET_TYPE charset);

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
//		��ePubLib 1.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI_(void) DKE_SetUseBookStyle(DK_BOOL bUseBookStyle);

//-------------------------------------------
//	Summary:
//		��ȡ�ں�֧�ֵ�����ĵ��汾�š�
//	Parameters:
//		[in] nMajorVersion      - ���汾�š�
//		[in] nMinorVersion      - �ΰ汾�š�
//		[in] nLastVersion       - С�汾�š�
//  Return Value:
//      Null
//  Remarks:
//      Null
//  Availability:
//		��ePubLib 2.3.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI_(void) DKE_GetSupportVersion(DK_INT& nMajorVersion, DK_INT& nMinorVersion, DK_INT& nLastVersion);

//-------------------------------------------
//	Summary:
//		������ʾ�ı�ʱ�Ƿ�����ת����
//	Parameters:
//		[in] bGBToBig5 - �Ƿ�����ת����
//  Return Value:
//      Null
//  Remarks:
//      Null
//  Availability:
//		��ePubLib 2.1.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI_(void) DKE_SetGBToBig5(DK_BOOL bGBToBig5);

//-------------------------------------------
//	Summary:
//		��ȡ��ʾ�ı�ʱ�Ƿ�����ת����
//	Parameters:
//	    [out] bGBToBig5 - �Ƿ�����ת����
//  Return Value:
//      Null
//  Remarks:
//      Null
//  Availability:
//		��ePubLib 2.1.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI_(void) DKE_GetGBToBig5(DK_BOOL& bGBToBig5);

//-------------------------------------------
//	Summary:
//		��ָ֤�������У��Ƿ���ڴ����ı������ַ�������
//	Parameters:
//	    [in] szFontFaceName  - ����֤����� face name��
//	    [in] szText          - ������֤���ı���
//  Return Value:
//      ��� szFontFaceName ��Ӧ�����ļ��У����� szText �������ַ������Σ�
//      �򷵻� DK_TRUE, ���򷵻� DK_FALSE
//  Remarks:
//      Null
//  Availability:
//		��ePubLib 2.1.1 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI DKE_VerifyFontFaceByText(const DK_WCHAR* szFontFaceName, const DK_WCHAR* szText);

//-------------------------------------------
//	Summary:
//		�����豸����
//	Parameters:
//	    [in] deviceWidth    - �豸���
//	    [in] deviceHeight   - �豸�߶�
//	    [in] colorIndex     - �豸��ɫ��
//	    [in] resolution     - �豸�ֱ���
//  Return Value:
//      Null
//  Remarks:
//      Null
//  Availability:
//		��ePubLib 2.2.1 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI_(void) DKE_SetDeviceParams(DK_INT deviceWidth, DK_INT deviceHeight, DK_INT colorIndex, DK_INT resolution);

//-------------------------------------------
//	Summary:
//		�����Ƿ�ʹ�ÿɽ�����pre��
//	Parameters:
//	    [out] bUseIteractivePre - �Ƿ�ʹ��pre��
//  Return Value:
//      Null
//  Remarks:
//      Null
//  Availability:
//		��ePubLib 2.7.0 ��ʼ֧�֡�
//-------------------------------------------
EPUBAPI_(void) DKE_SetUseInteractivePre(DK_BOOL bUseIteractivePre);

//===========================================================================

#endif // #ifndef __DKEAPI_HEADERFILE__
