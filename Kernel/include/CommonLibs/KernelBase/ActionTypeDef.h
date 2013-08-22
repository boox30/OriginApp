//===========================================================================
// Summary:
//		ActionTypeDef.h
//      Action���Ͷ���
// Usage:
//	    Null
// Remarks:
//		Null
// Date:
//		2011-10-25
// Author:
//		Liu Hongjia(liuhj@duokan.com)
//===========================================================================

#ifndef __KERNEL_COMMONLIBS_KERNELBASE_ACTIONTYPEDEF_H__
#define __KERNEL_COMMONLIBS_KERNELBASE_ACTIONTYPEDEF_H__

//===========================================================================

#include "KernelDef.h"
#include "KernelRenderType.h"

//===========================================================================

enum DK_ACTION_TYPE
{
	DK_ACTION_UNKNOWN,	// δ�����

	DK_ACTION_GOTO,		// �ĵ��ڵ���ת
	DK_ACTION_GOTOR,	// �ĵ������ת
	DK_ACTION_LAUNCH,	// ִ��һ��Ӧ�ó��򣬻����Ǵ�һ���ĵ�
	DK_ACTION_URI,		// ָ��һ��URIλ��
	DK_ACTION_NAMED,	// ����
};

enum DK_ACTION_DEST_TYPE
{
	DK_ACTION_DEST_UNKNOWN,		// δ����

	DK_ACTION_DEST_XYZ,			// Ŀ�����������Ͻ�λ�ã�Left��Top���Լ�ҳ�����ű�����Zoom��ȷ��
	DK_ACTION_DEST_FIT,			// �ʺ�ҳ��
	DK_ACTION_DEST_FITH,		// �ʺϿ�ȣ�Ŀ������λ�ý���Top����ȷ����
	DK_ACTION_DEST_FITV,		// �ʺϸ߶ȣ�Ŀ������λ�ý���Left ����ȷ��
	DK_ACTION_DEST_FITR			// �ʺϴ��ڣ�Ŀ������Ϊ��Left��Top��Right��Bottom����ȷ���ľ�������
};

enum DK_ACTION_LAUNCH_OSTYPE
{
	DK_ACTION_LAUNCH_OSTYPE_WIN,		// Windows
	DK_ACTION_LAUNCH_OSTYPE_MAC,		// Mac
	DK_ACTION_LAUNCH_OSTYPE_UNIX		// Unix
};

//===========================================================================

struct DK_ANNOTSINFO
{
	DK_BOX			box;	// ���������
	DK_ACTION_TYPE	type;	// ��������
	DK_VOID*		pInfo;	// �������Ϣ
} ;

// ҳ��ɵ����������
enum DK_CLICKABLE_TYPE
{
	DK_CLICKABLE_ANNOT,				// ע�Ͷ���
	DK_CLICKABLE_ACTION,			// ���ж�����ͼԪ
};

// �ɵ������֧�ֵ�����¼�
enum DK_CLICKEVENT_TYPE
{
	DK_CLICKEVENT_ME = 1,			// ����������
	DK_CLICKEVENT_MX = 2,			// ����뿪����
	DK_CLICKEVENT_LMD = 3,			// ����������
	DK_CLICKEVENT_LMU = 4,			// �������ɿ�
	DK_CLICKEVENT_RMD = 5,			// ����Ҽ�����
	DK_CLICKEVENT_RMU = 6,			// ����Ҽ��ɿ�
};

// �ɵ��������Ϣ
struct DK_CLICKINFO
{
	DK_BOX				rcBBox;			// �ɵ��������Ӿ���
	DK_CLICKABLE_TYPE	nObjType;		// ��������
	DK_CLICKEVENT_TYPE	nEventType;		// ֧�ֵ�����¼�
	DK_ACTION_TYPE		nActionType;	// ��������

	DK_CLICKINFO()
	: nObjType(DK_CLICKABLE_ANNOT), nEventType(DK_CLICKEVENT_LMD), nActionType(DK_ACTION_GOTO)
	{}
};

enum DK_DESTREGION_TYPE
{
	DK_DESTREGION_XYZ,			// �����ϽǺ����űȾ���
	DK_DESTREGION_FITPAGE,		// �ʺ�ҳ��
	DK_DESTREGION_FITH,			// �ʺϿ�ȣ�λ����Top�������
	DK_DESTREGION_FITV,			// �ʺϸ߶ȣ�λ����Left�������
	DK_DESTREGION_FITR,			// �ʺϴ��ڣ�Ŀ������Ϊ��Left�� Top�� Right��Bottom����ȷ���ľ�������
	DK_DESTREGION_FITB,			// �ʺ�Bounding,�Ծ��δ�СΪ׼��������δ�ֱ��ˮƽ������ͬ��ȡ��С��ֵ�����ξ��С�
	DK_DESTREGION_FITBH,		// ͬ�ϣ�λ����Top������
	DK_DESTREGION_FITBV			// ͬ�ϣ�λ����Left������
};

// Goto Action
struct DKACTIONGOTO 
{
	DK_DESTREGION_TYPE	drType;			// Ŀ����������
	DK_DWORD			dwPageNum;		// Ŀ��ҳ��
	DK_BOX				boxRegion;		// Ŀ�����򡣸����Եĺ����ǣ�X0 - left, X1 - right, Y0 - bottom, Y1 - top��
	DK_BOOL				bLeftValid;		// boxRegion �У�left�����Ƿ���Ч�������Ч���Ķ����Ӧ���õ�ǰ��ֵ��Ĭ��ֵ��
	DK_BOOL				bTopValid;		// ���� bLeftValid��
	DK_BOOL				bRightValid;	// ���� bLeftValid��
	DK_BOOL				bBottomValid;	// ���� bLeftValid��
	DK_FLOAT			fZoom;			// ҳ���������������0 ֵ��ʾ��Ч�������Ч���Ķ����Ӧ���õ�ǰ��ֵ��
	const DK_WSTRING*   szAnchorName;	// ê����
	DKACTIONGOTO()
	: drType(DK_DESTREGION_XYZ), dwPageNum(0), bLeftValid(DK_FALSE), bTopValid(DK_FALSE),
	bRightValid(DK_FALSE), bBottomValid(DK_FALSE),fZoom(0), szAnchorName(DK_NULL)
	{}
};

//===========================================================================

// GotoR Action
struct DKACTIONGOTOR
{
	DK_BOOL			bNewWindow;					// �Ƿ����´����д�
	DK_WCHAR		pszFileLoc[DK_MAX_PATH];	// Ŀ���ĵ���λ��
	DKACTIONGOTO	dagDest;					// Ŀ����������
	DKACTIONGOTOR()
	: bNewWindow(DK_FALSE)
	{ memset(pszFileLoc, 0, sizeof(pszFileLoc)); }
};

//===========================================================================

// Launch Action
struct DKACTIONLAUNCH
{
	DK_ACTION_LAUNCH_OSTYPE		osType;						// ����ϵͳ����
	DK_WCHAR					pszFileLoc[DK_MAX_PATH];	// Ŀ������λ��
	DK_WCHAR					pszPara[DK_MAX_PATH];		// ��ִ�г������
	DKACTIONLAUNCH()
	: osType(DK_ACTION_LAUNCH_OSTYPE_WIN)
	{
		memset(pszFileLoc, 0, sizeof(pszFileLoc));
		memset(pszPara, 0, sizeof(pszPara));
	}
};

//===========================================================================

// URI Action
struct DKACTIONURI
{
	DK_WCHAR		pszURI[DK_MAX_URI];			// Ŀ��URI��λ�ã�����7λASCII����룬�μ���RFC 2396��
	DK_WCHAR		pszBase[DK_MAX_URI];		// Base URI��������Ե�ַ���á�
	DKACTIONURI()
	{
		memset(pszURI, 0, sizeof(pszURI));
		memset(pszBase, 0, sizeof(pszBase));
	}
};

//===========================================================================

#endif // #ifndef __KERNEL_COMMONLIBS_KERNELBASE_ACTIONTYPEDEF_H__
