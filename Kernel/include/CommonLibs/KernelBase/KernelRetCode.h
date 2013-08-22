//===========================================================================
// Summary:
//      KernelRetCode.h
// Usage:
//      ���ڴ�����Ϣ�Ķ��塣
//          ...
// Remarks:
//      Null
// Date:
//      2011-09-15
// Author:
//      Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef __KERNELRETCODE_HEADERFILE__
#define __KERNELRETCODE_HEADERFILE__

//===========================================================================

//-------------------------------------------
//  Summary:
//      Kernel����ֵ��
//  Values:
//      0   - �ɹ���
//      <0  - �Ƿ�ֵ
//      >0  - ������
//-------------------------------------------
typedef long DK_ReturnCode;

//===========================================================================
// ��ͬ����ģ��ʹ�õķ���ֵ����

#define DKR_PDF_BASEVALUE           1000L   // PDFLib����ֵ
#define DKR_PDF_MAXVALUE            1999L
#define DKR_EPUB_BASEVALUE          2000L   // ePubLib����ֵ
#define DKR_EPUB_MAXVALUE           2999L
#define DKR_TXT_BASEVALUE           3000L   // TxtLib����ֵ
#define DKR_TXT_MAXVALUE            3999L

#define DKR_CONTAINER_BASEVALUE     5000L   // Container����ֵ
#define DKR_CONTAINER_MAXVALUE      5499L
#define DKR_IO_BASEVALUE            5500L   // IOBase����ֵ
#define DKR_IO_MAXVALUE             5999L
#define DKR_FILTER_BASEVALUE        6000L   // Filter����ֵ
#define DKR_FILTER_MAXVALUE         6499L
#define DKR_XML_BASEVALUE           6500L   // xml����ֵ
#define DKR_XML_MAXVALUE            6999L

#define DKR_TEST_BASEVALUE          9000L   // Unit Test ����ֵ
#define DKR_TEST_MAXVALUE           9999L

//===========================ͨ�÷���ֵ======================================
// �ɹ�
#define DKR_OK                      0L
// ʧ��
#define DKR_FAILED                  1L
// �޷�Ԥ֪��ʧ��
#define DKR_UNEXPECTED_ERROR        2L
// û��ʵ��
#define DKR_NOIMPLEMENT             3L
// ִ����δ��ʼ����Ϊ��
#define DKR_UNINIT                  4L
// ��Ч�������
#define DKR_INVALIDINPARAM          5L
// ��Ч��������
#define DKR_INVALIDOUTPARAM         6L
// ��֧�ֵĲ���
#define DKR_UNSUPPORTED             7L
// �����ڴ�ʧ��
#define DKR_ALLOCTMEMORY_FAIL       8L
// �˰汾��֧����������
#define DKR_NO_FONTDOWNLOAD         9L
// δ��ʼ���ں�
#define DKR_UNINITIALIZED           10L
// Ȩ����֤ʧ��
#define DKR_AUTHENTICATE_FAIL       50L
// û�в���Ȩ��
#define DKR_NORIGHT                 51L

//===========================���ƽ��״̬ʹ�÷���ֵ==============================

typedef long DKRS_RENDERSTATUS;
#define DKRS_OK                     0L
#define DKRS_MISSCHAR               1L

//===========================================================================

#endif  //#ifndef __KERNELRETCODE_HEADERFILE__
