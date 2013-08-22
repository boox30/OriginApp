//===========================================================================
// Summary:
//		XMLAPI.h
// Usage:
//		XML API
// Remarks:
//		Null
// Date:
//		2012-01-10
// Author:
//		pengf(pengf@duokan.com)
//===========================================================================

#ifndef __KERNEL_COMMONLIBS_XMLBASE_XMLAPI_H__
#define __KERNEL_COMMONLIBS_XMLBASE_XMLAPI_H__
#include "XMLDef.h"
#include "XMLBase.h"

//-------------------------------------------
//	Summary:
//		��ʼ��xmlbase��
//	Parameters:
//	    Null
//  Return Value:
//      ����ɹ��򷵻�DK_TRUE�����򷵻�DK_FALSE��
//	Remarks:
//		��XMLBase 1.0.5 ��ʼ֧�֡�
//-------------------------------------------
XMLAPI DKX_Initialize();

//-------------------------------------------
//	Summary:
//		����xmlbase��
//	Parameters:
//	    Null
//  Return Value:
//      ����ɹ��򷵻�DK_TRUE�����򷵻�DK_FALSE��
//	Remarks:
//		��XMLBase 1.0.5 ��ʼ֧�֡�
//-------------------------------------------
XMLAPI DKX_Destroy();
#endif
