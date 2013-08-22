//===========================================================================
// Summary:
//		DKTDef.h
// Usage:
//	    txt lib基本类型定义
// Remarks:
//		Null
// Date:
//		2011-11-14
// Author:
//		Peng Feng(pengf@duokan.com)
//===========================================================================
#ifndef __KERNEL_TXTKIT_TXTLIB_DKTDEF_H__
#define __KERNEL_TXTKIT_TXTLIB_DKTDEF_H__

#include "KernelType.h"

#ifdef _LINUX
	#ifndef NOT_SUPPORT_FVISIBILITY
		#define TXT_API					__attribute__((visibility("default")))
		#define TXTSTDMETHODCALLTYPE		__attribute__((stdcall))
		#define TXTCALLBACK				__attribute__((stdcall))
	#else
		#define TXT_API					
		#define TXTSTDMETHODCALLTYPE	
		#define TXTCALLBACK				
	#endif
#else
    #define TXT_API					
	#define TXTSTDMETHODCALLTYPE		__stdcall
	#define TXTCALLBACK				__stdcall
#endif

#define TXTAPI				extern "C" TXT_API bool
#define TXTAPI_(type)		extern "C" TXT_API type

typedef DK_VOID* TXTDOCHANDLE;
typedef DK_VOID* TXTRENDERHANDLE;

struct DKT_CHAR_INFO
{
    DK_WCHAR ch;
    DK_BOX boundingBox;                 // ��Ӿ���
    DK_UINT offsetInBytes;                // ���ֵ�����λ��
};

struct DKT_CHAR_INFO_FOR_RENDER
{
    DK_WCHAR ch;
    DK_CHARSET_TYPE charset; 
    DK_BOX boundingBox; // ��Ӿ���
    DK_DOUBLE x, y; // ��������
    DK_BOOL hyphen; // �Ƿ�hyphen
    DK_BOOL visible; // �Ƿ�ɼ�
    DK_UINT index; // ��ԭ���е�index
};

struct DKT_LINE_INFO_FOR_RENDER
{
    DK_BOX lineBox;
    DK_UINT lineStartIndex; // line��һ���ַ���Ӧ��index
};

enum DKT_HITTEST_TEXT_MODE
{
    DKT_HITTEST_TEXT_UNKNOWN,
    DKT_HITTEST_TEXT_SENTENCE,                      // �������ı���ʽ HitTest ҳ������
    DKT_HITTEST_TEXT_WORD                           // ���ı��ִʷ�ʽ HitTest ҳ������
};

enum DKT_SELECTION_MODE
{
    DKT_SELECTION_UNKNOWN,
    DKT_SELECTION_MIDDLECROSS,                      // �������Խ������ʱ��ѡ�е�ǰ���� 
    DKT_SELECTION_INTERCROSS,                       // �������뵱ǰ���н���ʱ��ѡ�е�ǰ����
    DKT_SELECTION_INTERCROSS_WORD                   // �������뵱ǰ���н���ʱ���������ڴ�Ҳ����ѡ��
};

#endif
