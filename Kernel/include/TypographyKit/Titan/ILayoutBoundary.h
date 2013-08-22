//===========================================================================
//  Summary:
//      �Ű�߽綨�塣
//  Usage:
//      Null
//  Remarks:
//      Null
//  Date:
//      2012-06-19
//  Author:
//      Zhai Guanghe (zhaigh@duokan.com)
//===========================================================================

#ifndef __TITAN_LAYOUTBOUNDARY_ILAYOUTBOUNDARY_H__
#define __TITAN_LAYOUTBOUNDARY_ILAYOUTBOUNDARY_H__

#include "TitanDef.h"
#include "KernelRenderType.h"

class ILayoutBoundary
{
public:
    enum TYPE
    {
        RECT_BOUNDARY, 
        FOLD_LINE_BOUNDARY, 

        UNKNOWN_BOUNDARY
    };

    virtual TYPE BoundaryType() const = 0;

    virtual ILayoutBoundary * CreateCopy() const = 0;

    virtual void Transform(TP_MATRIX &matrix) const = 0;

public:
    //-------------------------------------------
    //  Summary:
    //      �����Ű�������/�±߽硣
    //  Parameters:
    //      Null
    //  Remarks:
    //      �ⲿ����Ƿ���Ч
    //  Return:
    //      ��/�±߽硣
    //-------------------------------------------
    virtual double GetTopBound() const = 0;
    virtual double GetBottomBound() const = 0;

    //-------------------------------------------
    //  Summary:
    //      �����Ű���������ȡ�
    //  Parameters:
    //      Null
    //  Remarks:
    //      �ⲿ����Ƿ���Ч
    //  Return:
    //      ����ȡ�
    //-------------------------------------------
    virtual double GetMaxWidth() const = 0;

    //-------------------------------------------
    //  Summary:
    //      ���ҿ���λ�õ��ϱ߽硣
    //  Parameters:
    //      [in] dLineWidth   - Ŀ����
    //      [in] dLineHeight  - Ŀ��߶�
    //      [in] dBaseTopLine - ���ҵ���ʼλ��
    //  Remarks:
    //      �ⲿ����Ƿ���Ч
    //  Return:
    //      ���ҵ����ϱ߽硣
    //-------------------------------------------
    virtual double SearchTopLine(double dLineWidth, double dLineHeight, double dBaseTopLine) const = 0;

    //-------------------------------------------
    //  Summary:
    //      ����ָ����������/�ұ߽硣
    //  Parameters:
    //      [in] dTopLine    - �������ϱ߽�
    //      [in] dBottomLine - �������±߽�
    //  Remarks:
    //      �ⲿ��֤���������Ч��
    //  Return:
    //      ��/�ұ߽硣
    //-------------------------------------------
    virtual double GetLeftBound(double dTopLine, double dBottomLine) const = 0;
    virtual double GetRightBound(double dTopLine, double dBottomLine) const = 0;

public:
    virtual ~ILayoutBoundary() {}
};

class LayoutBoundaryFactory
{
public:
    static ILayoutBoundary * CreateRectBoundary(double dTop, double dBottom, double dLeft, double dRight);
    static ILayoutBoundary * CreateFoldLineBoundary(double dTop, 
                                                    double dBottom, 
                                                    const std::vector<DK_POS> &vLeftPoints, 
                                                    const std::vector<DK_POS> &vRightPoints);

private:
    LayoutBoundaryFactory();
};

//===========================================================================

#endif // __TITAN_LAYOUTBOUNDARY_ILAYOUTBOUNDARY_H__
