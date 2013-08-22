//===========================================================================
// Summary:
//		���ӿ���Ű�����ѯö�����ӿڡ�
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-09-10
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef	__COMPLEXBLOCK_LAYOUTENUMERATOR_INTERFACE_HEADERFILE__
#define __COMPLEXBLOCK_LAYOUTENUMERATOR_INTERFACE_HEADERFILE__

//===========================================================================

#include "ILayoutEnumerator.h"

//===========================================================================

// �ַ���Ϣ������ʱ�����x, y, boxBoundary, nGravity���������ת��������е�ֵ,
// ��Ҫ��������任�õ���ԭʼ�Ű������е����ꡣ
typedef struct __TP_COMPLEX_CHARINFO
{
	TP_WCHAR ch;                        // �ַ�
	bool bVisible;                      // �ַ��Ƿ�ɼ�
	bool bHyphen;                       // �ַ��Ƿ���Hyphen
	double x;                           // �ַ���������x����
	double y;                           // �ַ���������y����
	unsigned int dwGlyphIndex;	        // �������α任�������������û�����α任���ֵȡĬ��ֵ0
	double dHScale;				        // �������ַ�����ķ����ȣ�Ĭ��ֵΪ1.0

    bool bRubyGuide;                    // �Ƿ�ruby����
    bool bRubyBase;                     // �Ƿ�ruby����

	TP_PIECE_TYPE nPieceType;
	TP_BOX boxBoundary;			        // ����λ�ã���nPieceType = TP_PIECE_GRAPH | TP_PIECE_IMAGEʱ��Ч
	long nPos;					        // �ַ����ߺ�����������е���������0��ʼ
	TP_GRAVITY_DIRECTION nGravity;		// �ַ����ߺ��ӵ���������
	TP_GRAVITY_DIRECTION nRealGravity;	// �ַ����ߺ�����ʵ���������򣬼���ԭʼ�Ű������������

	__TP_COMPLEX_CHARINFO()
		: ch(0), bVisible(true), bHyphen(false), x(0.0), y(0.0), dwGlyphIndex(0), dHScale(1.0), bRubyGuide(false), bRubyBase(false), nPieceType(TP_PIECE_TEXT), nPos(0), nGravity(TP_GRAVITY_DOWN), nRealGravity(TP_GRAVITY_DOWN)
	{}

	__TP_COMPLEX_CHARINFO& operator=(const __TP_COMPLEX_CHARINFO& ci)
	{
		if (&ci != this)
		{
			ch = ci.ch;			
			bVisible = ci.bVisible;
			bHyphen = ci.bHyphen;
            bRubyGuide = ci.bRubyGuide;
            bRubyBase = ci.bRubyBase;
			nPieceType = ci.nPieceType;
			nPos = ci.nPos;
			nGravity = ci.nGravity;
			nRealGravity = ci.nRealGravity;
			boxBoundary = ci.boxBoundary;			
			if (ci.nPieceType == TP_PIECE_TEXT)
			{
				x = ci.x;
				y = ci.y;
				dwGlyphIndex = ci.dwGlyphIndex;
				dHScale = ci.dHScale;
			}
		}
		return *this;
	}
} TP_COMPLEX_CHARINFO;
typedef std::vector<TP_COMPLEX_CHARINFO> ComplexCharInfoVec;

//===========================================================================

class IComplexBlockLayoutEnumerator : public ILayoutEnumerator
{
public:
	//-------------------------------------------
	//	Summary:
	//		��ȡԴ�ַ������Ѿ��Ű���ַ��ĸ�����
	//	Return Value:
	//		�ַ�������
	//	Remarks:
	//		ע���������ֵ��ʾ����Դ�ַ������Ѿ��Ű���ַ�����������ö�����е��ַ�������
	//		���ýӿ�MoveToNextChar��GetCurrentChar����ö�����е��ַ���
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
	virtual void GetCurrentChar(TP_COMPLEX_CHARINFO& ci) = 0;

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

    //-------------------------------------------
    //  Summary:
    //      ȡ��ö������ȫ���ַ��������Ρ�
    //  Parameters:
    //      Null
    //  Remarks:
    //      Null
    //  Availability:
    //      ��Titan 2.0��ʼ֧�֡�
    //-------------------------------------------
    virtual TP_BOX GetBoxBoundary() const = 0;
};

//===========================================================================

#endif	//#ifndef __COMPLEXBLOCK_LAYOUTENUMERATOR_INTERFACE_HEADERFILE__
