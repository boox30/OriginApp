//===========================================================================
// Summary:
//		KernelMacro.h
// Usage:
//		�ڲ�ʹ�ú�Ķ��塣
//			...
// Remarks:
//		Null
// Date:
//		2011-09-15
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef	__KERNEL_COMMONLIBS_KERNELBASE_KERNELMACRO_H__
#define	__KERNEL_COMMONLIBS_KERNELBASE_KERNELMACRO_H__

//===========================================================================

#ifdef _WIN32
#pragma warning(disable:4127)
#endif

//===========================================================================

// �Ƿ���CJK����
#define DK_IsCJK(ch)			(((ch) >= 0x3400 && (ch) <=0x4DB5) || ((ch) >= 0x4E00 && (ch) <=0x9FBB) || \
                                ((ch) >= 0xF900 && (ch) <=0xFA2D) || ((ch) >= 0xFA30 && (ch) <=0xFA6A) || \
                                ((ch) >= 0xFA70 && (ch) <=0xFAD9) || ((ch) >= 0x20000 && (ch) <=0x2A6D6) || \
                                ((ch) >= 0x2F800 && (ch) <=0x2FA1D))

//===========================ͨ�ô�����======================================

// ��鷵��ֵ�Ƿ�ɹ�
#define DK_SUCCEEDED(nRet)	(((DK_ReturnCode)(nRet)) == DKR_OK)
#define DK_FAILED(nRet)		(((DK_ReturnCode)(nRet)) != DKR_OK)
#define DK_BOOL2DKR(bRet)	((bRet) ? DKR_OK : DKR_FAILED)

// ������Ĭ�ϵ�DK_ReturnCode���������ͷ���
#define DK_RETURNCODE_NAME	nRet
#define __DK_ERRORLABLE		Error
#define DK_ERRORLABLE		__DK_ERRORLABLE

#define DK_DECLARE_RETURNCODE			\
	DK_ReturnCode DK_RETURNCODE_NAME = DKR_OK;

#define DK_DECLARE_ERRORHANDLER			\
	DK_ERRORLABLE:

#define DK_DECLARE_ERRORHANDLER_EX(n)	\
	DK_ERRORLABLE##n:

#define DK_DEFAULT_RETURNCODE			\
	return DK_RETURNCODE_NAME;

#define DK_DEFAULT_ERRORRETURN			\
	__DK_ERRORLABLE:					\
		return DK_RETURNCODE_NAME;

#define DK_DEFAULT_VOIDRETURN			\
	__DK_ERRORLABLE:					\
		return;

// ������Ϣ����
#if ((defined DKRERR_DEBUG_PRINTF) || (defined DKRERR_DEBUG_WPRINTF))
	#ifdef _ANDROID_LINUX
		#include <android/log.h>
		#define	DKRDBG_SHOWERR \
				{\
					if (DK_FAILED(DK_RETURNCODE_NAME))\
						__android_log_print(ANDROID_LOG_INFO, "Kernel", "DKR_ERR!! Return %d at line %d of file: %s\n", (DK_INT)DK_RETURNCODE_NAME, __LINE__, __FILE__);\
				}
	#else
		#include <stdio.h>
		#include <wchar.h>
		#ifdef DKRERR_DEBUG_WPRINTF
			#define	DKRDBG_SHOWERR \
				{\
					if (DK_FAILED(DK_RETURNCODE_NAME))\
						wprintf(L"DKR_ERR!! Return %d at line %d of file: %s\n", (DK_INT)DK_RETURNCODE_NAME, __LINE__, __FILE__);\
				}
		#else
			#define	DKRDBG_SHOWERR \
				{\
					if (DK_FAILED(DK_RETURNCODE_NAME))\
						printf("DKR_ERR!! Return %d at line %d of file: %s\n", (DK_INT)DK_RETURNCODE_NAME, __LINE__, __FILE__);\
				}
		#endif
	#endif
#elif (defined DKRERR_DEBUG_ASSERT)
	#define	DKRDBG_SHOWERR DK_ASSERT(DK_SUCCEEDED(DK_RETURNCODE_NAME));
#else
	#define	DKRDBG_SHOWERR 
#endif

// ���÷���ֵ����ת��������
#define DK_RETURN(nRet)									\
do														\
{														\
	DK_RETURNCODE_NAME = nRet;							\
	DKRDBG_SHOWERR										\
	goto __DK_ERRORLABLE;								\
} while(0)

// ���÷���ֵ����ת��������
// (������һЩ��Ҫ��ȫ���ش����뵫����Ҫ����ĵط�ʹ��)
#define DK_SILENTRETURN(nRet)							\
do														\
{														\
	DK_RETURNCODE_NAME = nRet;							\
	goto __DK_ERRORLABLE;								\
} while(0)

// ���÷���ֵ,ASSERT����ת��������
#define DK_ASSERTRETURN(nRet)							\
do														\
{														\
	DK_RETURNCODE_NAME = nRet;							\
	DKRDBG_SHOWERR										\
	DK_ASSERT(DK_FALSE);								\
	goto __DK_ERRORLABLE;								\
} while(0)

// ���DK_ReturnCodeֵ������ʱ��ת��������
#define DK_CNR(retValue)								\
do														\
{														\
	DK_RETURNCODE_NAME = (DK_ReturnCode)(retValue);		\
	DKRDBG_SHOWERR										\
	if (DK_FAILED(DK_RETURNCODE_NAME))					\
		goto __DK_ERRORLABLE;							\
} while(0)

// ���DK_ReturnCodeֵ������ʱ�����Զ��巵��ֵ����ת��������
#define DK_CNR2(retValue, errorCode)					\
do														\
{														\
	DK_RETURNCODE_NAME = (DK_ReturnCode)(retValue);		\
	if (DK_FAILED(DK_RETURNCODE_NAME))					\
	{													\
		DK_RETURNCODE_NAME = (DK_ReturnCode)(errorCode);\
		DKRDBG_SHOWERR									\
		goto __DK_ERRORLABLE;							\
	}													\
} while(0)

// ���DK_ReturnCodeֵ������ʱ�����Զ��巵��ֵ����תָ��������
#define DK_CNR3(retValue, errorCode, n)					\
do														\
{														\
	DK_RETURNCODE_NAME = (DK_ReturnCode)(retValue);		\
	if (DK_FAILED(DK_RETURNCODE_NAME))					\
	{													\
		DK_RETURNCODE_NAME = (DK_ReturnCode)(errorCode);\
		DKRDBG_SHOWERR									\
		goto DK_ERRORLABLE##n;							\
	}													\
} while(0)

// ���DK_ReturnCodeֵ������ʱASSERT����ת��������
#define DK_CNRA(retValue)								\
do														\
{														\
	DK_RETURNCODE_NAME = (DK_ReturnCode)(retValue);		\
	if (DK_FAILED(DK_RETURNCODE_NAME))					\
	{													\
		DK_ASSERT(DK_FALSE);							\
		DKRDBG_SHOWERR									\
		goto __DK_ERRORLABLE;							\
	}													\
} while(0)

// ���DK_BOOLֵ������ʱ��ת��������
#define DK_CBR(bValue)									\
do														\
{														\
	if (!(bValue))										\
	{													\
		DK_RETURNCODE_NAME = (DKR_FAILED);				\
		DKRDBG_SHOWERR									\
		goto __DK_ERRORLABLE;							\
	}													\
} while(0)

// ���DK_BOOLֵ������ʱ�����Զ��巵��ֵ����ת��������
#define DK_CBR2(bValue, errorCode)						\
do														\
{														\
	if (!(bValue))										\
	{													\
		DK_RETURNCODE_NAME = (DK_ReturnCode)(errorCode);\
		DKRDBG_SHOWERR									\
		goto __DK_ERRORLABLE;							\
	}													\
} while(0)

// ���DK_BOOLֵ������ʱ�����Զ��巵��ֵ����ת��ָ��������
#define DK_CBR3(bValue, errorCode, n)					\
do														\
{														\
	if (!(bValue))										\
	{													\
		DK_RETURNCODE_NAME = (DK_ReturnCode)(errorCode);\
		DKRDBG_SHOWERR									\
		goto DK_ERRORLABLE##n;							\
	}													\
} while(0)

// ���DK_BOOLֵ������ʱASSERT����ת��������
#define DK_CBRA(bValue)									\
do														\
{														\
	if (!(bValue))										\
	{													\
		DK_RETURNCODE_NAME = (DKR_FAILED);				\
		DKRDBG_SHOWERR									\
		DK_ASSERT(DK_FALSE);							\
		goto __DK_ERRORLABLE;							\
	}													\
} while(0)

// ��������ڴ淵�ص�ָ�룬����ʱ��ת��������
#define DK_CPR(pPointer)								\
do														\
{														\
	if ((pPointer) == DK_NULL)							\
	{													\
		DK_RETURNCODE_NAME = (DKR_ALLOCTMEMORY_FAIL);	\
		DKRDBG_SHOWERR									\
		goto __DK_ERRORLABLE;							\
	}													\
} while(0)

// ��������ڴ淵�ص�ָ�룬����ʱ�����Զ��巵��ֵ����ת��������
#define DK_CPR2(pPointer, errorCode)					\
do														\
{														\
	if ((pPointer) == DK_NULL)							\
	{													\
		DK_RETURNCODE_NAME = (DK_ReturnCode)(errorCode);\
		DKRDBG_SHOWERR									\
		goto __DK_ERRORLABLE;							\
	}													\
} while(0)

// ��������ڴ淵�ص�ָ�룬����ʱ�����Զ��巵��ֵ����ת��ָ��������
#define DK_CPR3(pPointer, errorCode, n)					\
do														\
{														\
	if ((pPointer) == DK_NULL)							\
	{													\
		DK_RETURNCODE_NAME = (DK_ReturnCode)(errorCode);\
		DKRDBG_SHOWERR									\
		goto DK_ERRORLABLE##n;							\
	}													\
} while(0)

// ��������ڴ淵�ص�ָ�룬����ʱASSERT����ת��������
#define DK_CPRA(pPointer)								\
do														\
{														\
	if ((pPointer) == DK_NULL)							\
	{													\
		DK_RETURNCODE_NAME = (DKR_ALLOCTMEMORY_FAIL);	\
		DKRDBG_SHOWERR									\
		DK_ASSERT(DK_FALSE);							\
		goto __DK_ERRORLABLE;							\
	}													\
} while(0)

// ��麯��������ָ�������ΪNULLʱ��ת��������
#define DK_CIPR(pArg)									\
do														\
{														\
	if ((pArg) == DK_NULL)								\
	{													\
		DK_RETURNCODE_NAME = (DKR_INVALIDINPARAM);		\
		DKRDBG_SHOWERR									\
		goto __DK_ERRORLABLE;							\
	}													\
} while(0)

// ��麯��������ָ�������ΪNULLʱ�����Զ��巵��ֵ����ת��������
#define DK_CIPRA(pArg)									\
do														\
{														\
	if ((pArg) == DK_NULL)								\
	{													\
		DK_RETURNCODE_NAME = (DKR_INVALIDINPARAM);		\
		DK_ASSERT(DK_FALSE);							\
		DKRDBG_SHOWERR									\
		goto __DK_ERRORLABLE;							\
	}													\
} while(0)

// ��麯�������ָ�������ΪNULLʱ��ת��������
#define DK_COPR(pArg)									\
do														\
{														\
	if ((pArg) == DK_NULL)								\
	{													\
		DK_RETURNCODE_NAME = (DKR_INVALIDOUTPARAM);		\
		DKRDBG_SHOWERR									\
		goto __DK_ERRORLABLE;							\
	}													\
} while(0)

// ��麯�������ָ�������ΪNULLʱ�����Զ��巵��ֵ����ת��������
#define DK_COPRA(pArg)									\
do														\
{														\
	if ((pArg) == DK_NULL)								\
	{													\
		DK_RETURNCODE_NAME = (DKR_INVALIDOUTPARAM);		\
		DKRDBG_SHOWERR									\
		DK_ASSERT(DK_FALSE);							\
		goto __DK_ERRORLABLE;							\
	}													\
} while(0)

/////////////////////////////////////////////////////////////////////////////

#define DK_RETURN_VOID_ON_NULL(p) \
    do  \
    { \
        if (DK_NULL == p) \
        { \
            return; \
        } \
    }while(0) 

#define DK_RETURN_CODE_ON_NULL(p, retCode) \
    do  \
    { \
        if (DK_NULL == p) \
        { \
            return retCode; \
        } \
    }while(0) 

#define DK_RETURN_CODE_ON_FAILED(retValue) \
do														\
{														\
	DK_RETURNCODE_NAME = (DK_ReturnCode)(retValue);		\
	DKRDBG_SHOWERR										\
	if (DK_FAILED(DK_RETURNCODE_NAME))					\
    { \
        return DK_RETURNCODE_NAME; \
    } \
} while(0)

#define DK_RETURN_MEMORYFAIL_ON_NULL(p) DK_RETURN_CODE_ON_NULL(p, DKR_ALLOCTMEMORY_FAIL)


#endif	//#ifndef __KERNEL_COMMONLIBS_KERNELBASE_KERNELMACRO_H__
