//===========================================================================
// Summary:
//		�ӿ��ļ��еĻ������ݽṹ
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-9-13
// Author:
//		Zhang Jingdan (zhangjingdan@duokan.com)
//===========================================================================

#ifndef __KERNEL_PDFKIT_PDFLIB_DKPTYPEDEF_PDFLIB_H__
#define __KERNEL_PDFKIT_PDFLIB_DKPTYPEDEF_PDFLIB_H__

//===========================================================================
#include "KernelType.h"
#include "DKPTypeDef.h"

enum DKP_GRAOPEX_TYPE
{
	DKP_GRAOPEX_m		= 0,
	DKP_GRAOPEX_l		= 1,
	DKP_GRAOPEX_c		= 2,
	DKP_GRAOPEX_v		= 3,
	DKP_GRAOPEX_y		= 4,
	DKP_GRAOPEX_re		= 5,
	DKP_GRAOPEX_cp		= 6,
	DKP_GRAOPEX_ep		= 7,
	DKP_GRAOPEX_eoep	= 8
};

// ·��������Ϣ
typedef struct __DKPGRACONTENT
{
	DK_DOUBLE			fPoint[6];		// ·�����Ƶ�����
	DKP_GRAOPEX_TYPE	graOP;			// ·��ͼ�β�������
	__DKPGRACONTENT*	pNextNode;
} DKPGRACONTENT, *PDKPGRACONTENT;

//===========================================================================

typedef struct __DKPIMAGEOBJ
{
	DK_INT			nRefNum;
	DK_INT			nImageType;					// ͼ������
	DKP_DRECT		rcImageBBox;				// ͼ����Ӿ���
	DK_BITMAPINFO*	pBmpInfo;					// ͼ��ͷ��Ϣ
	DK_BYTE*		pBMPbuffer;					// ͼ������
	DK_INT			nImageDataLen;				// ͼ�����ݳ���
	DK_DOUBLE		dFillOpacity;				// ͸����
	DK_DOUBLE		szCTM[6];					// ͼ�����ʱ������任����
	DKP_DRECT		rcClipBox;					// ͼ��Ĳü���

	DK_INT			nMaskType;					// ͼ����Ĥ�����ͣ�	0:��Mask 1:image mask 2:soft mask
												//						3:��ɫͨ��mask	 4:��ɫmask
	DK_BITMAPINFO*	pBmpInfoMask;				// Maskͼ��ͷ��Ϣ
	DK_BYTE*		pMaskBMPbuffer;				// Mask��ģͼ����
	DK_RGBQUAD		clrCurFill;					// ��ǰ�����ɫ
	DK_RGBQUAD		clrMaskMin;					// ��Ĥ����ɫ����
	DK_RGBQUAD		clrMaskMax;
	__DKPIMAGEOBJ()
	{
		nRefNum = -1;
		pBmpInfo = DK_NULL;
		pBMPbuffer = DK_NULL;
		dFillOpacity = 1;
		nMaskType = 0;
		pBmpInfoMask = DK_NULL;
		pMaskBMPbuffer = DK_NULL;
	}
	// �ü���
	__DKPGRACONTENT* pClipArea;
} DKPIMAGEOBJ, *PDKPIMAGEOBJ;

// Form����
typedef struct __DKPFORMOBJ
{
	DKP_DRECT			rcFormBBox;				// ��Ӿ���
	DK_DOUBLE			szCTM[6];				// ����ʱ������任����
	PDKPOBJNODE			pContent;				// ��������
	DK_BOOL				bSoftMask;				// Form�����Ƿ�ΪSoftMask
	DK_DOUBLE			dStrokAlpha;			// Strok Alpha
	DK_DOUBLE			dFillAlpha;				// Fill Alpha
	PDKPGRACONTENT		pClipArea;				// �ü���
} DKPFORMOBJ;

struct __DKPPATTERNNODE;

// ·��ͼ�����ڵ�
typedef struct __DKPPATHCONTENTNODE
{
	DKPDRAWPATHINFO			drawpathinfo;
	PDKPGRACONTENT			pPathContent;		// ·����Ϣ
	PDKPGRACONTENT			pClip;				// ·���ü�������
	__DKPPATTERNNODE*		pFillPattern;
	__DKPPATTERNNODE*		pStrokePattern;
	DK_INT					nPathsID;			// �����Path�ڵ㱻Build Path���������IDֵ���Ա�дPieceʱ�õ�  	
	DKP_DRECT				rcBBox;				// ��Ӿ���
	__DKPPATHCONTENTNODE*	pNext;				// ��һ��·���ڵ�
	__DKPPATHCONTENTNODE(){};
	__DKPPATHCONTENTNODE(const __DKPPATHCONTENTNODE &ctnod)
	{
		drawpathinfo = ctnod.drawpathinfo;
		pPathContent = ctnod.pPathContent;
		pClip = ctnod.pClip;
		pFillPattern = ctnod.pFillPattern;
		pStrokePattern = ctnod.pStrokePattern;
		nPathsID = ctnod.nPathsID;
		rcBBox = ctnod.rcBBox;
		pNext = ctnod.pNext;
	}
} DKPPATHCONTENTNODE, *PDKPPATHCONTENTNODE;

// �ļ��а������ַ�����Ϣ������unicode�汾��ֻ��string
typedef struct __DKPTEXTINFOEX
{
	DK_WCHAR*			pContent;			// ��������
	PDKPDISPLAYCHARNODE pCodeContent;		// ���ֵı�����Ϣ
	DK_WCHAR*			pFontName;			// ����
	DK_VOID*			pXRef;
	DK_INT				nOBJNum;			// Font OBJ ID
	DK_FONT_STYLE		nFontStyle;			// ���
	DK_DOUBLE			dXFontSize;			// �ֺ�
	DK_DOUBLE			dYFontSize;
	DK_DOUBLE			dCharSpace;			// �ַ����
	DK_DOUBLE			dWordSpace;			// �ʼ��
	DK_INT				nRenderMode;		// RenderMode
	DK_INT				nWritingMode;		// WritingMode  0:����;1:����
	DK_DWORD			rgbTextColor;		// ��ɫ
	DK_RGBCOLOR			rgbFillColor;		// ���ֹ�����ɫ
	DK_RGBCOLOR			rgbStrokeColor;		// ���ֹ�����ɫ
	DK_DOUBLE			dLineWith;			// ���ֹ����߿�
	DKP_DRECT			rcBBox;				// ��Ӿ���
	DK_DOUBLE			szCTM[6];			// ����任����
	DK_WCHAR*			pEncoding;			// ����ı�������
	PDKPGRACONTENT		pClip;
	DK_INT				lMainID;				 	
	DK_INT				lSubID;				  	
	__DKPTEXTINFOEX(){};
	__DKPTEXTINFOEX(const __DKPTEXTINFOEX &textinfo)
	{
		pContent = textinfo.pContent;
		pFontName = textinfo.pFontName;
		nOBJNum = textinfo.nOBJNum;
		nFontStyle = textinfo.nFontStyle;
		dXFontSize = textinfo.dXFontSize;
		dYFontSize = textinfo.dYFontSize;
		rgbTextColor = textinfo.rgbTextColor;
		rgbFillColor = textinfo.rgbFillColor;
		rgbStrokeColor = textinfo.rgbStrokeColor;
		dCharSpace = textinfo.dCharSpace;
		dWordSpace = textinfo.dWordSpace;
		nRenderMode = textinfo.nRenderMode;
		nWritingMode = textinfo.nWritingMode;
		rcBBox = textinfo.rcBBox;
		pEncoding = textinfo.pEncoding;
		pClip = textinfo.pClip;
		lMainID = textinfo.lMainID;
		lSubID = textinfo.lSubID;
	};
} DKPTEXTINFOEX, *PDKPTEXTINFOEX;

// �������ڵ�
typedef struct __DKPTEXTINFONODEEX
{
	DKPTEXTINFOEX Node;
	__DKPTEXTINFONODEEX* pNext;
	__DKPTEXTINFONODEEX(){};
	__DKPTEXTINFONODEEX(const __DKPTEXTINFONODEEX &ctnod)
	{
		Node = ctnod.Node;
		pNext = ctnod.pNext;
	}
} DKPTEXTINFONODEEX, *PTEXTINFONODEEX;

typedef struct __DKPAXIALSHDNODEEX
{
	DKPAXIALSHDINFO			Node;
	PDKPGRACONTENT			pClip;
	DK_INT					nAXShdID;
	DKP_DRECT				rcBBox;
	__DKPAXIALSHDNODEEX(){};
	__DKPAXIALSHDNODEEX(const __DKPAXIALSHDNODEEX &ctnod)
	{
		Node = ctnod.Node;
		pClip = ctnod.pClip;
		nAXShdID = ctnod.nAXShdID;
		rcBBox = ctnod.rcBBox;
	}
} DKPAXIALSHDNODEEX, *PDKPAXIALSHDNODEEX;

typedef struct __DKPRADIALSHDNODEEX
{
	DKPRADIALSHDINFO		Node;
	PDKPGRACONTENT			pClip;
	DK_INT					nRDShdID;
	DKP_DRECT				rcBBox;
	__DKPRADIALSHDNODEEX(){};
	__DKPRADIALSHDNODEEX(const __DKPRADIALSHDNODEEX &ctnod)
	{
		Node = ctnod.Node;
		pClip = ctnod.pClip;
		nRDShdID = ctnod.nRDShdID;
		rcBBox = ctnod.rcBBox;
	}
} DKPRADIALSHDNODEEX, *PDKPRADIALSHDNODEEX;

typedef struct __DKPTRISHDNODEEX
{
	DK_DOUBLE*				pParsedData;
	DK_INT					nDataNum;
	PDKPGRACONTENT			pClip;
	DK_INT					nTriShdID;
	DKP_DRECT				rcBBox;
	__DKPTRISHDNODEEX(){};
	__DKPTRISHDNODEEX(const __DKPTRISHDNODEEX &ctnod)
	{
		pParsedData = ctnod.pParsedData;
		nDataNum = ctnod.nDataNum;
		pClip = ctnod.pClip;
		nTriShdID = ctnod.nTriShdID;
		rcBBox = ctnod.rcBBox;
	}
} DKPTRISHDNODEEX, *PDKPTRISHDNODEEX;

typedef struct __DKPPATTERNNODE
{
	DK_DOUBLE			szContentSize[4];
	DK_DOUBLE			szCTM[6];				// ����任����
	PDKPOBJNODE			pContent;
	__DKPPATTERNNODE(){};
	__DKPPATTERNNODE(const __DKPPATTERNNODE &ctnod)
	{
		szContentSize[0] = ctnod.szContentSize[0];
		szContentSize[1] = ctnod.szContentSize[1];
		szContentSize[2] = ctnod.szContentSize[2];
		szContentSize[3] = ctnod.szContentSize[3];
		pContent = ctnod.pContent;
	}
} DKPPATTERNNODE, *PDKPPATTERNNODE;

//===========================================================================

#endif// __KERNEL_PDFKIT_PDFLIB_DKPTYPEDEF_PDFLIB_H__
