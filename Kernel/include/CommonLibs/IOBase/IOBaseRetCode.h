//===========================================================================
// Summary:
//     IOBaseRetCode.h
// Usage:
//     ����IOBase������Ϣ�Ķ��塣
// Remarks:
//     Null
// Date:
//     2011-09-16
// Author:
//     Zhai Guanghe (zhaigh@duokan.com)
//===========================================================================

#ifndef __KERNEL_COMMONLIBS_IOBASERETCODE_H__
#define __KERNEL_COMMONLIBS_IOBASERETCODE_H__

#include "KernelRetCode.h"

//===========================================================================
// typedef long DK_ReturnCode;
// #define DKR_IO_BASEVALUE               5500L // IOBase����ֵ
// #define DKR_IO_MAXVALUE                5999L
//===========================================================================

// ���÷���ֵ
#define DKR_IO_STREAM_NOT_SUPPORT          DKR_IO_BASEVALUE          // δ֧�ֵĹ���
#define DKR_IO_STREAM_ERR_MODE            (DKR_IO_BASEVALUE + 1L)    // ����Ĵ�ģʽ
#define DKR_IO_STREAM_OPENED              (DKR_IO_BASEVALUE + 2L)    // ���Ѿ���
#define DKR_IO_STREAM_CLOSED              (DKR_IO_BASEVALUE + 3L)    // ���Ѿ��ر�
#define DKR_IO_STREAM_OPEN_FAIL           (DKR_IO_BASEVALUE + 4L)    // ����ʧ��
#define DKR_IO_STREAM_ERR_SEEK_OFFSET     (DKR_IO_BASEVALUE + 5L)    // �Ƿ���Seekλ��
#define DKR_IO_STREAM_ERR_SEEK_ORIGIN     (DKR_IO_BASEVALUE + 6L)    // �Ƿ���SeekOrigin
#define DKR_IO_STREAM_NOT_ENOUGH_DATA     (DKR_IO_BASEVALUE + 7L)    // Ҫ���ȡ�˹�������
#define DKR_IO_STREAM_CANNOT_READ         (DKR_IO_BASEVALUE + 8L)    // �����ܶ�
#define DKR_IO_STREAM_CANNOT_WRITE        (DKR_IO_BASEVALUE + 9L)    // ������д

#endif // __KERNEL_COMMONLIBS_IOBASERETCODE_H__
