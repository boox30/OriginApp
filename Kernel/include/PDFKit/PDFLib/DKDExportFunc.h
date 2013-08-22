//===========================================================================
// Summary:
//      DKDExportFunc.h
//      DKD������������ɹ��ⲿ����
// Usage:
// Remarks:
//      Null
// Date:
//      2011-9-28
// Author:
//      Liu Hongjia (liuhj@duokan.com)
//===========================================================================
 
#ifndef __KERNEL_PDFKIT_PDFLIB_DKDEXPORTFUNC_H__
#define __KERNEL_PDFKIT_PDFLIB_DKDEXPORTFUNC_H__

#include "DKPRetCode.h"
#include "DKPTypeDef.h"

// �ж����������Ƿ��ཻ
DK_ReturnCode IsRectCut(const DKP_RECT* pRc1, const DKP_RECT* pRc2);
DK_ReturnCode IsDRectCut(const DKP_DRECT* pRc1, const DKP_DRECT* pRc2);

// �ж����������Ƿ����ཻ��������ཻ����Ƿ����0
DK_ReturnCode IsIntersectRect(const DKP_RECT* pRc1, const DKP_RECT* pRc2);
DK_ReturnCode IsIntersectDRect(const DKP_DRECT* pRc1, const DKP_DRECT* pRc2);

// �������
DK_ReturnCode NormalizeDRect(DKP_DRECT* pDRect);

DK_ReturnCode IsValidDRect(const DKP_DRECT* pDRect);

#endif // #ifndef __KERNEL_PDFKIT_PDFLIB_DKDEXPORTFUNC_H__
