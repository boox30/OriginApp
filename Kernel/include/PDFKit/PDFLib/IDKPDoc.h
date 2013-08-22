//===========================================================================
// Summary:
//		IDPKDoc�Ǹ����ĵ��򿪣���ȡ�ĵ�һЩ���ԵĽӿ��ࡣ 
// Usage:
//		ʹ��DPK_CreateDoc���д�����ʹ��DPK_DestoryDoc���١�
// Remarks:
//		Null
// Date:
//		2011-9-15
// Author:
//		Zhang JingDan (zhangjingdan@duokan.com)
//===========================================================================

#ifndef __KERNEL_PDFKIT_PDFLIB_IDKPDOC_H__
#define __KERNEL_PDFKIT_PDFLIB_IDKPDOC_H__

//===========================================================================

#include "KernelRetCode.h"
#include "DKPTypeDef.h"

class IDKPOutline;
class IDKPPage;
class IDKPPageEx;
class IDkStream;

//===========================================================================

class IDKPDoc
{
public:
    enum REARRANGE_PAGE_POSITION_TYPE
    {
        PREV_PAGE,      // ������һҳ
        LOCATION_PAGE,  // ����λ����ת������ҳ
        NEXT_PAGE,      // ������һҳ
    };

	//-------------------------------------------
	// Summary:
	//		���ĵ���
	// Parameters:
	//		[in] pFileOP - Ŀ���ĵ��ļ������
	// Returns��
	//		�ɹ��򷵻�DKR_OK�������Ҫ�����򷵻� DKR_PDF_NEED_READ_PASSWORD����ʧ���򷵻�DKR_FAILED��	
	// SDK Version:
	//		��DKP 1.0��ʼ֧��
	//-------------------------------------------
	virtual DK_ReturnCode OpenDoc(IDkStream* pFileOP) = 0;

    //-------------------------------------------
    // Summary:
    //		��������Դ��ĵ���
    // Parameters:
    //		[in] pFileOP - Ŀ���ĵ��ļ������
    //		[in] pPwd - ���롣
    //      [in] length - ���볤�ȡ�
    // Returns��
    //		�ɹ��򷵻�DK_TRUE�������Ҫ��������������򷵻� DKR_PDF_READ_PASSWORD_INCORRECT����ʧ���򷵻�DK_FALSE��	
    // SDK Version:
    //		��DKP 2.2.0��ʼ֧��
    //-------------------------------------------
    virtual DK_ReturnCode OpenDoc(IDkStream* pFileOP, const DK_BYTE* pPwd, DK_INT length) = 0;

	//-------------------------------------------
	// Summary:
	//		�ر��ĵ���
	// SDK Version:
	//		��DKP 1.0��ʼ֧��
	//-------------------------------------------
	virtual DK_VOID CloseDoc() = 0;

	//-------------------------------------------
	// Summary:
	//		���ҳ����
	// Returns:
	//		�ɹ��򷵻�ҳ�������򷵻�-1��
	// SDK Version:
	//		��DKP 1.0��ʼ֧��
	//-------------------------------------------
	virtual DK_INT GetPageCount() = 0;

	//-------------------------------------------
	// Summary:
	//		����ָ��ҳ�����ݡ�
	// Parameters:
	//		[in] parrRenderInfo	- ���Ʋ�����
	// Returns:
	//		���Ƴɹ��򷵻�1��ʧ���򷵻�����ֵ��
	// SDK Version:
	//		��DKP 1.0��ʼ֧��
	//-------------------------------------------
	virtual DK_INT RenderPage(DK_RENDERINFO* parrRenderInfo) = 0;

	//-------------------------------------------
	// Summary:
	//		���ָ��ҳ���ҳ����
	// Parameters:
	//		[in] nPageNum - ҳ�룬��1��ʼ��
	// Returns:
	//		�ɹ��򷵻�ָ��ҳ���ҳ����ʧ���򷵻ؿա�
	// SDK Version:
	//		��DKP 1.0��ʼ֧��
	//-------------------------------------------
	virtual IDKPPage* GetPage(DK_INT nPageNum) = 0;

    //-------------------------------------------
    // Summary:
    //		�ͷ�ҳ���󣬵��ú�ҳ����ָ�벻�ٿ��ã��ٴ�ʹ��ʱ�������GetPage��ȡ����
    // Parameters:
    //		[in] pPage - ҳ����ָ�롣
    //		[in] bAll -	�Ƿ��ͷ��������ݡ�
    // SDK Version:
    //		��DKP 1.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID ReleasePage(IDKPPage* pPage, DK_BOOL bAll = DK_FALSE) = 0;

    //-------------------------------------------
    //  Summary:
    //      ������ʽ�Ű�ģʽ��ֻ����ʽҳ��Ч
    //  Parameters:
    //      [in] typeSetting            - �Ű�ģʽ��
    //  Return Value:
    //      Null
    //  Availability:
    //      ��DKP 2.5.0��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID SetTypeSetting(const DKTYPESETTING &typeSetting) = 0;

	//-------------------------------------------
	// Summary:
	//		���ָ����λ�õ�����ҳ����
	// Parameters:
    //		[in] pos            -  ָ����ʼλ��
    //                          pos.nChapterIndex ��ʾҳ�루��ʼҳΪ1��;
    //                          pos.nParaIndex ��ʾͨ������ IDKPPage ���� GetPageTextContentStream ��õ� PDKPTEXTINFONODE �����±�;
    //                          pos.nElemIndex ��ʾ PDKPTEXTINFONODE.DKPTEXTINFO.strContent �±�;
    //      [in] option         - ѡ�����ҳ����Σ�dpi���ֺ����ŵ�
    //      [in] posType        - ҳƫ������
    //      [in/out] ppPageEx   - ���ҳ�����
	// Returns:
	//		�ɹ��򷵻� DKR_OK
	// SDK Version:
	//		��DKP 1.0��ʼ֧��
	//-------------------------------------------
	virtual DK_ReturnCode GetPageEx(const DK_FLOWPOSITION& pos, const DKP_REARRANGE_PARSER_OPTION& option, REARRANGE_PAGE_POSITION_TYPE posType, IDKPPageEx** ppPageEx) = 0;

    //-------------------------------------------
    // Summary:
    //		�ͷ�����ҳ���󣬵��ú�����ҳ����ָ�벻�ٿ��ã��ٴ�ʹ��ʱ�������GetPageEx��ȡ����
    // Parameters:
    //		[in] pPage - ����ҳ����ָ�롣
    //		[in] bAll -	�Ƿ��ͷ��������ݡ�
    // SDK Version:
    //		��DKP 1.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID ReleasePageEx(IDKPPageEx* pPage, DK_BOOL bAll = DK_FALSE) = 0;

	//-------------------------------------------
	// Summary:
	//		���Ŀ¼����
	// Returns:
	//		�ɹ��򷵻�Ŀ¼����ʧ���򷵻ؿա�
	// SDK Version:
	//		��DKP 1.0��ʼ֧��
	//-------------------------------------------
	virtual IDKPOutline* GetOutline() = 0;

	//-------------------------------------------
	// Summary:
	//		����Ĭ���������֡�
	// Parameters:
	//		[in] pszDefaultFontFaceName - �������֡�
	//		[in] charset - ������롣
	// SDK Version:
	//		��DKP 1.0��ʼ֧��
	//-------------------------------------------
	virtual DK_VOID SetDefaultFontFaceName(const DK_WCHAR* pszDefaultFontFaceName, DK_CHARSET_TYPE charset) = 0;

	//-------------------------------------------
	// Summary:
	//		��ȡ�ĵ���Ԫ���ݡ�
	// Parameters:
	//		[out] pMetaData - Ԫ����,����ռ��ɡ�
	// SDK Version:
	//		��DKP 1.0��ʼ֧��
	//-------------------------------------------
	virtual DK_BOOL GetDocMetaData(PDKPMETADATA& pMetaData) = 0;
	virtual DK_BOOL ReleaseMetaData() = 0;

    //-------------------------------------------
    // Summary:
    //		��ȡ��ǰ�ĵ�������ģʽ��
    // Parameters:
    //      ����ģʽ���ں��жϣ�����ҳ������ž�����ͬһ������ģʽ��
    // SDK Version:
    //		��DKP 2.4.0��ʼ֧��
    //-------------------------------------------
    virtual DKP_REARRANGE_MODE GetRearrangeMode() = 0;

public:
	virtual ~IDKPDoc() {}
};

//===========================================================================

#endif
