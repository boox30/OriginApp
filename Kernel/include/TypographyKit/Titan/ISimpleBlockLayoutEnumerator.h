//===========================================================================
// Summary:
//		�򵥿���Ű�����ѯö�����ӿڡ�
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-08-27
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef	__SIMPLEBLOCK_LAYOUTENUMERATOR_INTERFACE_HEADERFILE__
#define __SIMPLEBLOCK_LAYOUTENUMERATOR_INTERFACE_HEADERFILE__

//===========================================================================

#include "ILayoutEnumerator.h"

//===========================================================================

// �ַ���Ϣ������ʱ�����x, y, boxBoundary, nGravity���������ת��������е�ֵ,
// ��Ҫ��������任�õ���ԭʼ�Ű������е����ꡣ
typedef struct __TP_CHARINFO
{
	TP_WCHAR ch;				        // �ַ�	
	bool bVisible;				        // �ַ��Ƿ�ɼ�
	bool bHyphen;				        // �ַ��Ƿ���Hyphen
	double x;					        // �ַ���������x����
	double y;					        // �ַ���������y����
	TP_CHARSET_TYPE	nCharSet;	        // �ַ�������������뼯��ʹ��������뼯��Ӧ��������л��ơ�
	
	TP_GRAVITY_DIRECTION nGravity;		// �ַ�����������
	TP_GRAVITY_DIRECTION nRealGravity;	// �ַ���ʵ���������򣬼���ԭʼ�Ű������������
	TP_BOX boxBoundary;			        // �ַ���Ӿ���
	unsigned int dwGlyphIndex;	        // ���α任�������������û�����α任���ֵȡĬ��ֵ0

	__TP_CHARINFO()
		: ch(0), bVisible(true), bHyphen(false), x(0.0), y(0.0), nCharSet(TP_CHARSET_PRC), nGravity(TP_GRAVITY_DOWN), nRealGravity(TP_GRAVITY_DOWN), dwGlyphIndex(0)
	{}

	__TP_CHARINFO& operator=(const __TP_CHARINFO& ci)
	{
		if (&ci != this)
		{
			ch = ci.ch;
			bVisible = ci.bVisible;
			bHyphen = ci.bHyphen;
			x = ci.x;
			y = ci.y;
			nCharSet = ci.nCharSet;
			nGravity = ci.nGravity;
			nRealGravity = ci.nRealGravity;
			boxBoundary = ci.boxBoundary;
			dwGlyphIndex = ci.dwGlyphIndex;
		}
		return *this;
	}
} TP_CHARINFO;
typedef std::vector<TP_CHARINFO> CharInfoVec;

//===========================================================================

class ISimpleBlockLayoutEnumerator : public ILayoutEnumerator
{
public:
	//-------------------------------------------
	//	Summary:
	//		��ȡԴ�ַ������Ѿ��Ű���ַ��ĸ�����
	//	Remarks:
	//		ע���������ֵ��ʾ����Դ�ַ������Ѿ��Ű���ַ�����������ö�����е��ַ�������
	//		���ýӿ�MoveToNextChar��GetCurrentChar����ö�����е��ַ���
	//	Return Value:
	//		�ַ�������
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual long GetCharCount() = 0;

	//-------------------------------------------
	//	Summary:
	//		�ƶ�����һ���ַ�λ�á�
	//	Return Value:
	//		�������false��ʾ�ѵ����һ���ַ���
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool MoveToNextChar() = 0;

	//-------------------------------------------
	//	Summary:
	//		ȡ�õ�ǰλ�õ��ַ���Ϣ��
	//  Parameters:
	//		[out] ci	- ��ǰλ���ַ���Ϣ��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void GetCurrentChar(TP_CHARINFO& ci) = 0;

	//-------------------------------------------
	//	Summary:
	//		�ƶ�����һ�е���ʼλ�á�
	//	Return Value:
	//		�������false��ʾ�ѵ����һ�С�
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool MoveToNextLine() = 0;

	//-------------------------------------------
	//	Summary:
	//		ȡ�õ�ǰ�е���Ϣ��
	//  Parameters:
	//		[out] li	- ��ǰ����Ϣ��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void GetCurrentLine(TP_LINEINFO& li) = 0;
};

//===========================================================================

#endif	//#ifndef __SIMPLEBLOCK_LAYOUTENUMERATOR_INTERFACE_HEADERFILE__
