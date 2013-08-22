//===========================================================================
// Summary:
//		���ڸ��ӿ���Ű洦�����ӿڡ�
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-09-10
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef	__COMPLEXBLOCKPROCESSOR_INTERFACE_HEADERFILE__
#define __COMPLEXBLOCKPROCESSOR_INTERFACE_HEADERFILE__

//===========================================================================

#include "ITitanPart.h"

//===========================================================================

// ע�⣺һ����������ͬ���м�࣬�μ�࣬�������������뷽ʽ���м�ඨ�巽ʽ�������ǲ���
// һ������ĵ�һ�������Щֵ������ڶ��׵Ŀ鶼Ҫ������5��������ֵ��
typedef struct __TP_COMPLEXINFO
{
	TP_PIECE_TYPE nPieceType;

	TP_ALIGN_TYPE nAlignType;				// ���뷽ʽ��ȡֵ��Χ�ο�TP_ALIGN_TYPE	
	TP_LINEGAP_TYPE nLineGapType;			// �м�ඨ�巽ʽ�����Ƕ౶�о�ʱ��dLineGap��ŵ��Ǳ��������ǹ̶�ֵʱ��dLineGap��Ź̶����и�ֵ��
	double dLineGap;						// �м��
	double dParaSpacing;					// �μ��
    bool bIgnoreBeginSpace;                 // �Ƿ���Զο�ʼ�հ��ַ�
	double dIndent;							// �����������룬��λ���ֺŴ�С

    bool bEmphasis;                         // �Ƿ���������

	// ���²���ΪTP_PIECE_TEXTʱ��Ч
	TP_WCHAR* pszSrcText;					// ��������
	TP_FONT font;							// ����
	double dTabStop;						// tab��ȣ���λ���ֺŴ�С

	// ���²���ΪTP_PIECE_IMAGEʱ��Ч
    TP_FOLLOWIMAGE_TYPE nFollowImageType;   // ����ͼ����
	TP_BOX boxBoundary;						// ���Ӵ�С
	double dLeftMargin;						// ��������߾�
	double dRightMargin;					// �����ҷ���߾�
	double dTopMargin;						// �����Ϸ���߾�
	double dBottomMargin;					// �����·���߾�
    bool bTopMarginSet;                     // ����߾��Ƿ�����
    bool bBottomMarginSet;                  // ����߾��Ƿ�����
	TP_BOX_VALIGN_TYPE nVAlignType;			// ���Ӵ�ֱ����Ķ��뷽ʽ
    double dVAlignLength;                   // ���ӵ��߾��뵱ǰ�л��ߵĴ�ֱ���루�����Ϸ�Ϊ��������Ϊ��ֵ����nVAlignType = TP_BOX_VALIGN_BASELINEʱ��Ч
    TP_LENGTH_UNIT nVAlignUnit;             // ���ӵ��߾��뵱ǰ�л��ߵĴ�ֱ����ĵ�λ, ��nVAlignUnit = TP_LENGTH_PERCENTʱ������ֵΪ��ǰ���Ӹ�
	bool bRotate;							// ����ʱ������Ƿ���ת90��

	// ���²���ΪTP_PIECE_RUBYʱ��Ч
	TP_BASICATOM* pGuideText;               // ��������
	int	nGuideTextCount;
	TP_BASICATOM* pBaseText;                // �����Ӧ������
	int	nBaseTextCount;
	TP_RUBY_ALIGN_TYPE nRubyAlignType;      // ƴע�����뷽ʽ
	TP_RUBY_POSITION nRubyPosition;         // ƴע��λ��

	// ���²���ΪTP_PIECE_HORINVER����TP_PIECE_COMBINELINESʱ��Ч
	TP_BASICATOM* pAtomList;
	int	nAtomCount;
	// ���²���ΪTP_PIECE_HORINVERʱ��Ч
	bool bFitLine;                          // ���Ϊ true����ʾ��ת�������Ҫѹ�����ʺ��иߡ�
	// ���²���ΪTP_PIECE_COMBINELINESʱ��Ч
	int nCombineLines;                      // ����
	int nSkipNum;                           // ��Ҫ�������ַ�����
	// ���²���ΪTP_PIECE_RUBY��TP_PIECE_HORINVER����TP_PIECE_COMBINELINESʱ��Ч
	int nInnerNum;                          // �ڲ��ַ�����

	__TP_COMPLEXINFO()
		: nPieceType(TP_PIECE_TEXT), nAlignType(TP_ALIGN_LEFT), nLineGapType(TP_LINEGAP_MULTIPLE), dLineGap(1.0), dParaSpacing(0.0), bIgnoreBeginSpace(true), dIndent(0.0), bEmphasis(false), pszSrcText(NULL), dTabStop(0.0),
		nFollowImageType(TP_FOLLOWIMAGE_IMAGE), dLeftMargin(0.0), dRightMargin(0.0), dTopMargin(0.0), dBottomMargin(0.0), bTopMarginSet(false), bBottomMarginSet(false), nVAlignType(TP_BOX_VALIGN_BASELINE), bRotate(true), pGuideText(NULL), 
		nGuideTextCount(0), pBaseText(NULL), nBaseTextCount(0), nRubyAlignType(TP_RUBY_ALIGN_CENTER), nRubyPosition(TP_RUBY_POSITION_BEFORE), pAtomList(NULL), nAtomCount(0), bFitLine(true), nCombineLines(2), nSkipNum(0), nInnerNum(0)
	{}
} TP_COMPLEXINFO;

// ���ӿ�������Ϣ
typedef struct __TP_CBLOCK_INPUTINFO
{
	TP_COMPLEXINFO* pInputInfo;
	int	nInfoCount;

	__TP_CBLOCK_INPUTINFO()
		: pInputInfo(NULL), nInfoCount(0)
	{}
} TP_CBLOCK_INPUTINFO;

//===========================================================================

class IComplexBlockProcessor : public ITitanPart
{
public:
	//-------------------------------------------
	//	Summary:
	//		�������֡�
	//  Parameters:
	//		[in] info			- ���Ű�����ִ���
	//		[in] bFastMode		- ����ģʽ����ģʽ�²���ö���Ű�����
	//		[in] bBleedMode		- ��Ѫģʽ����ģʽ�����һ�п��Գ����Ű�����
	//	Return Value:
	//		����ȫ������ɹ�����TP_LAYOUT_SUCCEED��
	//		�������뻹�к�������TP_LAYOUT_FOLLOWAFTER��
	//		����ʧ���򷵻�TP_LAYOUT_FAIL��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual TP_LAYOUT_STATE ProcessText(const TP_CBLOCK_INPUTINFO& info, bool bFastMode = false, bool bBleedMode = false) = 0;

	//-------------------------------------------
	//	Summary:
	//		�������֡�
	//  Parameters:
	//		[in] info			- ���Ű�����ִ���
	//		[in] isp			- ��ʼ״̬����������ָ����ǰ����ʼλ���Ƿ����¶��䡣
	//		[in] bFastMode		- ����ģʽ����ģʽ�²���ö���Ű�����
	//		[in] bBleedMode		- ��Ѫģʽ����ģʽ�����һ�п��Գ����Ű�����
	//	Return Value:
	//		����ȫ������ɹ�����TP_LAYOUT_SUCCEED��
	//		�������뻹�к�������TP_LAYOUT_FOLLOWAFTER��
	//		����ʧ���򷵻�TP_LAYOUT_FAIL��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual TP_LAYOUT_STATE ProcessTextEx(const TP_CBLOCK_INPUTINFO& info, const TP_INITIALSTATEPARA& isp, bool bFastMode = false, bool bBleedMode = false) = 0;
};

//===========================================================================

#endif	//#ifndef __COMPLEXBLOCKPROCESSOR_INTERFACE_HEADERFILE__
