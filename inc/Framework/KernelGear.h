//===========================================================================
// Summary:
//      KernelGear.h
//      ������� Kernel �����ӿڵĳ�ʼ�������١�����ע�ᡢ�������õ�
// Version:
//      0.1 draft - creating.
//
// Usage:
//      Null
// Remarks:
//      Null
// Date:
//      2011-12-28
// Author:
//      liuhj@duokan.com
//===========================================================================

#ifndef __KINDLEAPP_INC_FRAMEWORK_KERNELGEAR_H__
#define __KINDLEAPP_INC_FRAMEWORK_KERNELGEAR_H__

//-------------------------------------------
// Summary:
//        ��ʼ������ʽ��������
//-------------------------------------------
void InitializeKernel ();

//-------------------------------------------
// Summary:
//        ���ٸ���ʽ��������
//-------------------------------------------
void DestroyKernel ();

//-------------------------------------------
// Summary:
//        Ϊ����ʽ��������ע������
// Remarks:
//        ���û���ӡ�ɾ�������ļ�ʱ����Ҫ�ٴ�ע������
//-------------------------------------------
void RegisterKernelFonts ();
void UnRegisterKernelFonts ();

//-------------------------------------------
// Summary:
//        Ϊ����ʽ������������Ĭ������
// Remarks:
//        ���û��Զ�������ʱ�� ��Ҫ�ٴ�����Ĭ������
//-------------------------------------------
void SetKernelDefaultFonts ();



#endif // #ifndef__KINDLEAPP_INC_FRAMEWORK_KERNELGEAR_H__
