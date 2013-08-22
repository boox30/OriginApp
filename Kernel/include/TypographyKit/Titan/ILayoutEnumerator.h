//===========================================================================
// Summary:
//		�Ű�����ѯö���������ӿڡ�
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-08-19
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef	__LAYOUTENUMERATOR_INTERFACE_HEADERFILE__
#define __LAYOUTENUMERATOR_INTERFACE_HEADERFILE__

//===========================================================================

#include "TitanDef.h"

//===========================================================================

// ����Ϣ
typedef struct __TP_LINEINFO
{
	int nStartPos;				// �����ַ��������ַ����е�λ�ã���0��ʼ��������Hyphen��
	int nEnumPos;				// �����ַ����ַ�ö�����е�λ�ã���0��ʼ������Hyphen��
	int nCharCount;				// ���ַ��������������ɼ��ַ�������Hyphen��
	double dXStart;				// �л�����ʼx���꣬ȡ��һ���ɼ��ַ���x����
	double dXEnd;				// �л�����ֹx���꣬ȡ���һ���ɼ��ַ���x������������ֿ�
	double dYStart;				// �л�����ʼy���ꡣ
	double dMaxAscent;			// �л������ϸ߶����ֵ��
	double dMaxDescent;			// �л������¸߶����ֵ��

	__TP_LINEINFO()
		: nStartPos(-1), nEnumPos(-1), nCharCount(0), dXStart(0.0), dXEnd(0.0), dYStart(0.0), dMaxAscent(0.0), dMaxDescent(0.0)
	{}

	__TP_LINEINFO& operator=(const __TP_LINEINFO& li)
	{
		if (&li != this)
		{
			nStartPos = li.nStartPos;
			nEnumPos = li.nEnumPos;
			nCharCount = li.nCharCount;
			dXStart = li.dXStart;
			dXEnd = li.dXEnd;
			dYStart = li.dYStart;
			dMaxAscent = li.dMaxAscent;
			dMaxDescent = li.dMaxDescent;
		}
		return *this;
	}
} TP_LINEINFO;
typedef std::vector<TP_LINEINFO> LineInfoVec;

// ��ԭ����Ϣ������ʱ�����x, y, boxBoundary, nGravity���������ת��������е�ֵ,
// ��Ҫ��������任�õ���ԭʼ�Ű������е����ꡣ
struct TP_PIECEATOMINFO
{
	long lAtomID;						// ԭ��ID����0��ʼ����TP_CONTENTPIECE�е�lStartAtomID��Ӧ��
										// ע�⣺Hyphen�ַ������ֵ��������һ���ַ���ͬ��
    bool bHyphen;                       // �ַ��Ƿ���Hyphen
	int nPieceType;						// ԭ������������ͣ�ȡֵ��Χ�ο�TP_PIECE_TYPE
	bool bVisible;						// �Ƿ�ɼ�

	TP_WCHAR ch;						// �ַ�����nPieceType = TP_PIECE_TEXTʱ��Ч
                                        // ���ַ����ܺʹ��벻һ�£���������ʱ�ı���滻
	double x;							// �ַ���������x���꣬��nPieceType = TP_PIECE_TEXTʱ��Ч
	double y;							// �ַ���������y���꣬��nPieceType = TP_PIECE_TEXTʱ��Ч
	unsigned int dwGlyphIndex;			// ���α任�������������û�����α任���ֵȡĬ��ֵ0
                                        // ��index��Ϊ0ʱ��Ӧ����ʹ��index��ȡ���Σ�����������ȡ����������ʱ
	double dHScale;						// �������ַ�����ķ����ȣ�Ĭ��ֵΪ1.0

    bool bRubyGuide;                    // �Ƿ�ruby����
    bool bRubyBase;                     // �Ƿ�ruby����

	TP_BOX boxBoundary;					// ����λ�ã�Ҳ���ַ���Ӿ���
	TP_GRAVITY_DIRECTION nGravity;		// ԭ�ӵ���������
	TP_GRAVITY_DIRECTION nRealGravity;	// ԭ����ʵ���������򣬼���ԭʼ�Ű������������

	TP_PIECEATOMINFO()
		: lAtomID(0), bHyphen(false), nPieceType(TP_PIECE_TEXT), bVisible(true), ch(0), x(0.0), y(0.0), dwGlyphIndex(0), dHScale(1.0), bRubyGuide(false), bRubyBase(false), nGravity(TP_GRAVITY_DOWN), nRealGravity(TP_GRAVITY_DOWN)
	{}

	TP_PIECEATOMINFO& operator=(const TP_PIECEATOMINFO& pai)
	{
		if (&pai != this)
		{
			lAtomID = pai.lAtomID;
            bHyphen = pai.bHyphen;
			nPieceType = pai.nPieceType;
			bVisible = pai.bVisible;
            bRubyGuide = pai.bRubyGuide;
            bRubyBase = pai.bRubyBase;
			nGravity = pai.nGravity;
			nRealGravity = pai.nRealGravity;
			boxBoundary = pai.boxBoundary;
			switch (pai.nPieceType)
			{
			case TP_PIECE_TEXT:
				ch = pai.ch;
				x = pai.x;
				y = pai.y;			
				dwGlyphIndex = pai.dwGlyphIndex;
				dHScale = pai.dHScale;
				break;
			default:
				break;
			}
		}
		return *this;
	}
};

typedef std::vector<TP_PIECEATOMINFO> PieceAtomInfoVec;

// ����Ϣ
struct TP_PIECELINEINFO
{
	long lStartAtomID;				// ������ʼԭ��ID����0��ʼ
	int nAtomCount;					// ����ԭ�Ӹ���
	double dXStart;					// ������ʼx����
	double dXEnd;					// ��ĩ����x����
	double dYBaseLine;				// ���ڻ���y����
	double dYTop;					// �����ϱ߽�y����
	double dYBottom;				// �����±߽�y����
	int nSpanLines;					// ����ʱ���ӿ�Խ������

	TP_PIECELINEINFO()
		: lStartAtomID(0), nAtomCount(0), dXStart(0.0), dXEnd(0.0), dYBaseLine(0.0), dYTop(0.0), dYBottom(0.0), nSpanLines(0)
	{}

	TP_PIECELINEINFO& operator=(const TP_PIECELINEINFO& pli)
	{
		if (&pli != this)
		{
			lStartAtomID = pli.lStartAtomID;
			nAtomCount = pli.nAtomCount;
			dXStart = pli.dXStart;
			dXEnd = pli.dXEnd;
            dYBaseLine = pli.dYBaseLine;
			dYTop = pli.dYTop;
			dYBottom = pli.dYBottom;
			nSpanLines = pli.nSpanLines;
		}
		return *this;
	}
};
typedef std::vector<TP_PIECELINEINFO> PieceLineInfoVec;

//===========================================================================

class ILayoutEnumerator
{
public:
	//-------------------------------------------
	//	Summary:
	//		��ʼö�ٹ��̣�ö�����ڲ�ָ�����á�
	//  Parameters:
	//		Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void BeginEnum() = 0;

	//-------------------------------------------
	//	Summary:
	//		��ֹö�ٹ��̣�����Ű�����
	//  Parameters:
	//		Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void EndEnum() = 0;

	//-------------------------------------------
	//	Summary:
	//		�õ�����任����ö�����е�������Ҫ��������任�õ�ʵ���Ű������ϵ����ꡣ
	//  Parameters:
	//		Null
	//	Remarks:
	//		Null
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual TP_MATRIX GetTransformMatrix() = 0;

protected:
	//-------------------------------------------
	//	Summary:
	//		������������
	//-------------------------------------------
	virtual ~ILayoutEnumerator() {}
};

//===========================================================================

#endif	//#ifndef __LAYOUTENUMERATOR_INTERFACE_HEADERFILE__
