//===========================================================================
// Summary:
//     FilterRetCode.h
// Usage:
//     ����Filter������Ϣ�Ķ��塣
// Remarks:
//     Null
// Date:
//     2011-09-16
// Author:
//     Zhai Guanghe (zhaigh@duokan.com)
//===========================================================================

#ifndef __KERNEL_COMMONLIBS_FILTERRETCODE_H__
#define __KERNEL_COMMONLIBS_FILTERRETCODE_H__

#include "KernelRetCode.h"

//===========================================================================
// typedef long DK_ReturnCode;
// #define DKR_FILTER_BASEVALUE        6000L   // Filter����ֵ
// #define DKR_FILTER_MAXVALUE         6999L
//===========================================================================

#define DKR_FILTER_NOT_SUPPORT          DKR_FILTER_BASEVALUE       // δ֧�ֵĹ���
#define DKR_FILTER_NOT_INIT            (DKR_FILTER_BASEVALUE + 1L) // δ��ʼ��
#define DKR_FILTER_ALREADY_INIT        (DKR_FILTER_BASEVALUE + 2L) // �ѳ�ʼ��

#endif // __KERNEL_COMMONLIBS_FILTERRETCODE_H__
