//===========================================================================
// Summary:
//		����HTML���ṹ�Ŀ��Ű�����ѯö�����ӿڣ���Ҫ����EPUB��Ⱦ��
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-09-13
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef	__HTMLBLOCK_LAYOUTENUMERATOR_INTERFACE_HEADERFILE__
#define __HTMLBLOCK_LAYOUTENUMERATOR_INTERFACE_HEADERFILE__

//===========================================================================

#include "ILayoutEnumerator.h"

//===========================================================================

class IHTMLBlockLayoutEnumerator : public ILayoutEnumerator
{
public:
	//-------------------------------------------
	//	Summary:
	//		��ȡԴ�ַ������Ѿ��Ű��ԭ�ӵĸ�����
	//	Return Value:
	//		�ַ�������
	//	Remark:
	//		ע���������ֵ��ʾ����Դ��ʽ�����Ѿ��Ű��ԭ�Ӹ���������ö�����е�ԭ�Ӹ�����
	//		���ýӿ�MoveToNextAtom��GetCurrentAtom����ö�����е�ԭ�ӡ�
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual long GetAtomCount() = 0;

	//-------------------------------------------
	//	Summary:
	//		�ƶ�����һ��ԭ��λ�á�
	//	Return:
	//		�������false��ʾ�ѵ�����λ�á�
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool MoveToNextAtom() = 0;

	//-------------------------------------------
	//	Summary:
	//		ȡ�õ�ǰλ�õ�ԭ����Ϣ��
	//  Parameters:
	//		[out] pai	- ��ǰλ��ԭ����Ϣ��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void GetCurrentAtom(TP_PIECEATOMINFO& pai) = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ�Ű�����������
	//	Return Value:
	//		������
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual long GetLineCount() = 0;

	//-------------------------------------------
	//	Summary:
	//		�ƶ�����һ�е���ʼλ�á�
	//	Return Value:
	//		�������false��ʾ�ѵ����һ�С�
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool MoveToNextPieceLine() = 0;

	//-------------------------------------------
	//	Summary:
	//		ȡ�õ�ǰ�е���Ϣ��
	//  Parameters:
	//		[out] pli	- ��ǰ����Ϣ��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void GetCurrentPieceLine(TP_PIECELINEINFO& pli) = 0;

	//-------------------------------------------
	//	Summary:
	//		ȡ���Ű�߶ȣ����Ű��������һ�е��±߽硣
	//	Return Value:
	//		�����Ű�߶ȡ�
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual double GetLayoutHeight() = 0;

    //-------------------------------------------
    //	Summary:
    //		ȡ���Ű�߶ȣ����Ű�����ȡ�
    //	Return Value:
    //		�����Ű��ȡ�
    //  Availability:
    //		��Titan 1.0��ʼ֧�֡�
    //-------------------------------------------
    virtual double GetLayoutWidth() = 0;

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

#endif	//#ifndef __HTMLBLOCK_LAYOUTENUMERATOR_INTERFACE_HEADERFILE__
