//===========================================================================
// Summary:
//		һ������֡����󣬽�������֡����Ⱦ����ȡ֡�����Ϣ��
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2012-12-24
// Author:
//		Zhang JiaFang(zhangjf@duokan.com)
//===========================================================================

#ifndef __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKECOMICSFRAME_H__
#define __KERNEL_EPUBKIT_EPUBLIB_EXPORT_IDKECOMICSFRAME_H__


//===========================================================================

#include "DKEDef.h"

//===========================================================================

class IDKEComicsFrame
{
public:
    virtual ~IDKEComicsFrame() {}

public:
    //-------------------------------------------
    //  Summary:
    //      ��Ⱦ����֡
    //  Parameters:
    //      [in] option             - ����ѡ�
    //      [out] pResult           - ���ƽ����
    //  Return Value:
    //      ����ɹ�����DKR_OK��
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode RenderFrame(const DK_FLOWRENDEROPTION& option, DK_FLOWRENDERRESULT *pResult) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ����֡����Ӿ��Σ���֡����ͼƬ�����Ͻ�Ϊ����
    //  Parameters:
    //      Null
    //  Return Value:
    //      ֡����Ӿ���
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetFrameBoundaryOnImage() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��ǰ֡���ڵ�ͼƬ�ľ���
    //  Parameters:
    //      Null
    //  Return Value:
    //      ֡����Ӿ���
    //  Remarks:
    //      Null
    //  Availability:

    //      ��ePubLib 2.3.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_BOX GetComicsImageBoundary() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��ǰ����֡����������֡�Ķ������е�λ�ã����㿪ʼ��
    //  Parameters:
    //      Null
    //  Return Value:
    //      ֡����
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_LONG GetFrameIndexInThread() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��ǰ����֡��ָ����½���ţ����㿪ʼ��
    //  Parameters:
    //      Null
    //  Return Value:
    //      �½����
    //  Remarks:
    //      Null
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_LONG GetChapterIndexOfFrame() = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��ǰ֡��������ͼƬ������
    //  Parameters:
    //      [out] pImageData        - ͼƬ�ļ�����
    //  Return Value:
    //      �ɹ�����DKR_OK�����򷵻�ʧ��
    //  Remarks:
    //      ����FreeComicsImageData�ͷ�����
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_ReturnCode GetComicsImageData(DKFILEINFO* pImageData) = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷŵ�ǰ֡��������ͼƬ������
    //  Parameters:
    //      [in] pImageData        - ͼƬ�ļ�����
    //  Return Value:
    //      Null
    //  Remarks:
    //      ����GetComicsImageData����øú���
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeComicsImageData(DKFILEINFO* pImageData) = 0;

    //-------------------------------------------
    //  Summary:
    //      ��ȡ��ǰ֡��������ͼƬ��ePub���ڵ�ȫ·��
    //  Parameters:
    //      Null
    //  Return Value:
    //      ����·��
    //  Remarks:
    //      ����FreeComicsImagePath�ͷŷ���ֵ�ڴ�
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_WCHAR* GetComicsImagePath() = 0;

    //-------------------------------------------
    //  Summary:
    //      �ͷŵ�ǰ֡��������ͼƬ��ePub���ڵ�ȫ·��
    //  Parameters:
    //      [in]pPath       - ����·��
    //  Return Value:
    //      Null
    //  Remarks:
    //      ����GetComicsImagePath�����
    //  Availability:
    //      ��ePubLib 2.3.1��ʼ֧�֡�
    //-------------------------------------------
    virtual DK_VOID FreeComicsImagePath(DK_WCHAR* pPath) = 0;
};


//===========================================================================
#endif

