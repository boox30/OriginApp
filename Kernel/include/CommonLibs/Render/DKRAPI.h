//===========================================================================
// Summary:
//		Render�����ӿڡ�
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2012-01-30
// Author:
//		Peng Feng (pengf@duokan.com)
//===========================================================================

#ifndef __KERNEL_COMMONLIBS_RENDER_EXPORT_DKRAPI_H__
#define __KERNEL_COMMONLIBS_RENDER_EXPORT_DKRAPI_H__

#include "DKRDef.h"
#include "KernelType.h"
#include "KernelRetCode.h"

class IDkStream;

//-------------------------------------------
//  Summary:
//      ��ȡͼ������Ϣ
//  Parameters:
//      [in]  pStream                    - ͼ��������
//      [out] pWidth                     - ͼ����
//      [out] pHeight                    - ͼ��߶�
//  Return Value:
//      ����ɹ��򷵻�DKR_OK�����򷵻�ʧ�ܡ�
//  Remarks:
//  Availability:
//      ��Render 1.0 ��ʼ֧�֡�
//-------------------------------------------
RENDERAPI_(DK_ReturnCode) DKR_AnalyseImageStream(IDkStream *pStream, DK_UINT *pWidth, DK_UINT *pHeight);

//-------------------------------------------
//  Summary:
//      ��ȡͼ������Ϣ
//  Parameters:
//      [in]  pImageFile                 - ͼ�������ļ�
//      [out] pWidth                     - ͼ����
//      [out] pHeight                    - ͼ��߶�
//  Return Value:
//      ����ɹ��򷵻�DKR_OK�����򷵻�ʧ�ܡ�
//  Remarks:
//  Availability:
//      ��Render 1.0 ��ʼ֧�֡�
//-------------------------------------------
RENDERAPI_(DK_ReturnCode) DKR_AnalyseImageFile(const DK_WCHAR *pImageFile, DK_UINT *pWidth, DK_UINT *pHeight);

//-------------------------------------------
//  Summary:
//      ��Ⱦͼ����
//  Parameters:
//      [in] option                      - Render option
//      [in] dstBox                      - Ŀ�����
//      [in] srcBox                      - Դ����
//      [in] alpha                       - ͸����,0.0-1.0, 0ȫ͸��,1��͸��
//      [in] stream                      - ͼ��������
//  Return Value:
//      ����ɹ��򷵻�DKR_OK�����򷵻�ʧ�ܡ�
//  Remarks:
//  Availability:
//      ��Render 1.0 ��ʼ֧�֡�
//-------------------------------------------
RENDERAPI_(DK_ReturnCode) DKR_RenderImageStream(
        const DK_FLOWRENDEROPTION& option,
        const DK_BOX& dstBox,
        const DK_BOX& srcBox,
        DK_DOUBLE alpha,
        IDkStream* stream);

//-------------------------------------------
//  Summary:
//      ��Ⱦͼ���ļ�
//  Parameters:
//      [in] option                      - Render option
//      [in] dstBox                      - Ŀ�����
//      [in] srcBox                      - Դ����
//      [in] alpha                       - ͸����,0.0-1.0, 0ȫ͸��,1��͸��
//      [in] imageFile                   - ͼ�������ļ�
//  Return Value:
//      ����ɹ��򷵻�DKR_OK�����򷵻�ʧ�ܡ�
//  Remarks:
//  Availability:
//      ��Render 1.0 ��ʼ֧�֡�
//-------------------------------------------
RENDERAPI_(DK_ReturnCode) DKR_RenderImageFile(
        const DK_FLOWRENDEROPTION& option,
        const DK_BOX& dstBox,
        const DK_BOX& srcBox,
        DK_DOUBLE alpha,
        const DK_WCHAR* imageFile);

#endif
