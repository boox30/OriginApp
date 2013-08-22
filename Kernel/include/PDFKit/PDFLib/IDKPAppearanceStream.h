#ifndef __KERNEL_PDFKIT_PDFLIB_IDKPAPPEARANCESTREAM_H__
#define __KERNEL_PDFKIT_PDFLIB_IDKPAPPEARANCESTREAM_H__

#include "DKPTypeDef.h"

class IDKPAppearanceStream
{
public:
    //-------------------------------------------
    // Summary:
    //    �����߿�
    // Parameters:
    //    [in] dLineWidth - �߿�
    // Remarks:
    //    Ĭ��ֵ1.0��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID SetLineWidth(DK_DOUBLE dLineWidth) = 0;

    //-------------------------------------------
    // Summary:
    //    ������ñ���
    // Parameters:
    //    [in] lineCapType - ��ñ���
    // Remarks:
    //    Ĭ��ֵDPK_LINE_CAP_BUTT��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID SetLineCap(DKP_LINE_CAP_TYPE lineCapType) = 0;

    //-------------------------------------------
    // Summary:
    //    ���������ӷ��
    // Parameters:
    //    [in] lineJoinType - �����ӷ��
    // Remarks:
    //    Ĭ��ֵDPK_LINE_JOIN_MITER��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID SetLineJoin(DKP_LINE_JOIN_TYPE lineJoinType) = 0;

    //-------------------------------------------
    // Summary:
    //    ���ü������
    // Parameters:
    //    [in] dMiterLimit - �������
    // Remarks:
    //    Ĭ��ֵ10.0��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID SetMiterLimit(DK_DOUBLE dMiterLimit) = 0;

    //-------------------------------------------
    // Summary:
    //    �������߷��
    // Parameters:
    //    [in] dDashPhase - ������λ
    //    [in] pDashArray - ��������ָ��
    //    [in] nCount - ��������Ԫ�ظ���
    // Remarks:
    //    Ĭ��ֵʵ��"[] 0"��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID SetLineDash(DK_DOUBLE dDashPhase, const DK_DOUBLE* pDashArray, DK_UINT nCount) = 0;

    //-------------------------------------------
    // Summary:
    //    ����ƽ�������
    // Parameters:
    //    [in] nFlatTole - ƽ������ȡֵ��Χ[0, 100]��
    // Remarks:
    //    Ĭ��ֵ0��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID SetFlatnessTolerance(DK_UINT nFlatTole) = 0;

    //-------------------------------------------
    // Summary:
    //    ���ò�͸����
    // Parameters:
    //    [in] dOpacity - ��͸���ȣ�0��ʾ��ȫ͸����1��ʾ��ȫ��͸����
    // Remarks:
    //    Ĭ��ֵ1.0��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID SetOpacity(DK_DOUBLE dOpacity) = 0;

    //-------------------------------------------
    // Summary:
    //    ���û��ģʽ
    // Parameters:
    //    [in] blendModeType - ���ģʽ
    // Remarks:
    //    Ĭ��ֵDPK_BLEND_MODE_NORMAL��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID SetBlendMode(DKP_BLEND_MODE_TYPE blendModeType) = 0;

    //-------------------------------------------
    // Summary:
    //    ���浱ǰͼ��״̬��ͼ��״̬ջ
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID SaveState() = 0;

    //-------------------------------------------
    // Summary:
    //    �ָ���������ͼ��״̬
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID RestoreState() = 0;

    //-------------------------------------------
    // Summary:
    //    ����ǰ������ָ�����������Ӳ���
    // Parameters:
    //    [in] dMatrixArray - ָ����������
    // Remarks:
    //    Ĭ��ֵΪCTM����Ĭ���û�����ϵת��Ϊ�豸����ϵ�ľ���
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID ConcatenateMatrix(DK_DOUBLE dMatrixArray[6]) = 0;

    //-------------------------------------------
    // Summary:
    //    �ƶ�����㲢����һ����·��
    // Parameters:
    //    [in] x - ������
    //    [in] y - ������
    // Remarks:
    //    ʹ���û��ռ�����ϵ
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID MoveTo(DK_DOUBLE x, DK_DOUBLE y) = 0;

    //-------------------------------------------
    // Summary:
    //    �ӵ�ǰ�������ֱ����ָ�������
    // Parameters:
    //    [in] x - ������
    //    [in] y - ������
    // Remarks:
    //    ʹ���û��ռ�����ϵ
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID AddLineTo(DK_DOUBLE x, DK_DOUBLE y) = 0;

    //-------------------------------------------
    // Summary:
    //    ���һ��������ֱ�߹��ɵ���·��
    // Parameters:
    //    [in] dPoints - ���������
    //    [in] nCount - ��������
    // Remarks:
    //    ʹ���û��ռ�����ϵ
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID AddLines(const DKP_DPOINT* dPoints, DK_UINT nCount) = 0;

    //-------------------------------------------
    // Summary:
    //    �ӵ�ǰ���������ɪ������������ָ�������
    // Parameters:
    //    [in] cp1x - ���Ƶ�1������
    //    [in] cp1y - ���Ƶ�1������
    //    [in] cp2x - ���Ƶ�1������
    //    [in] cp2y - ���Ƶ�1������
    //    [in] x - �յ������
    //    [in] y - �յ�������
    // Remarks:
    //    ʹ���û��ռ�����ϵ
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID AddCurveTo(DK_DOUBLE cp1x, DK_DOUBLE cp1y, DK_DOUBLE cp2x, DK_DOUBLE cp2y, DK_DOUBLE x, DK_DOUBLE y) = 0;
    
    //-------------------------------------------
    // Summary:
    //    �ӵ�ǰ����ֱ������·����ʼ�㲢�ر���·��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID ClosePath() = 0;

    //-------------------------------------------
    // Summary:
    //    ���һ��������·��
    // Parameters:
    //    [in] dRect - ���������
    //    [in] nCount - ��������
    // Remarks:
    //    ʹ���û��ռ�����ϵ
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID AddRect(const DKP_DRECT& dRect) = 0;

    //-------------------------------------------
    // Summary:
    //    �軭·��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID StrokePath() = 0;

    //-------------------------------------------
    // Summary:
    //    ���·��
    // Parameters:
    //    [in] bNonZero - ��䷽ʽ��TRUE��ʾ������䣬FALSE��ʾ��ż��䡣
    // Remarks:
    //    ���ǰ���п��ŵ���·���������ر�
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID FillPath(DK_BOOL bNonZero = DK_TRUE) = 0;

    //-------------------------------------------
    // Summary:
    //    ��䲢�軭·��
    // Parameters:
    //    [in] bNonZero - ��䷽ʽ��TRUE��ʾ������䣬FALSE��ʾ��ż��䡣
    // Remarks:
    //    �൱�ڹ���������ͬ��·���������ν��������軭
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID FillAndStrokePath(DK_BOOL bNonZero = DK_TRUE) = 0;

    //-------------------------------------------
    // Summary:
    //    ����·���������������軭
    //-------------------------------------------
    virtual DK_VOID EndPath() = 0;

    //-------------------------------------------
    // Summary:
    //    �޸ĵ�ǰ�ü�·��
    // Parameters:
    //    [in] bNonZero - ��䷽ʽ��TRUE��ʾ������䣬FALSE��ʾ��ż��䡣
    // Remarks:
    //    ����ǰ·���뵱ǰ�ü�·���ཻ��Ϊ�µĲü�·��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID ModifyClipPath(DK_BOOL bNonZero = DK_TRUE) = 0;
        
    //-------------------------------------------
    // Summary:
    //    �����軭��ɫ
    // Parameters:
    //    [in] pColorArray - ��ɫ����ָ��
    //    [in] nCount - ����������1ΪDeviceGray��3ΪDeviceRGB��4ΪDeviceCMYK��
    // Remarks:
    //    Ĭ��ֵ����ɫ
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID SetStrokeColor(const DK_DOUBLE* pColorArray, DK_UINT nCount) = 0;

    //-------------------------------------------
    // Summary:
    //    ���������ɫ
    // Parameters:
    //    [in] pColorArray - ��ɫ����ָ��
    //    [in] nCount - ����������1ΪDeviceGray��3ΪDeviceRGB��4ΪDeviceCMYK��
    // Remarks:
    //    Ĭ��ֵ����ɫ
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID SetFillColor(const DK_DOUBLE* pColorArray, DK_UINT nCount) = 0;

    //-------------------------------------------
    // Summary:
    //    ����һ���ı�����
    // Remarks:
    //    ��ʼ���ı�������ı��о���Ϊ��Ⱦ����ı�������Ƕ�ס�
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID BeginText() = 0;

    //-------------------------------------------
    // Summary:
    //    ����һ���ı�����
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID EndText() = 0;

    //-------------------------------------------
    // Summary:
    //    �����ı�����ĵ�ǰ���塢�ֺ�
    // Parameters:
    //    [in] bChinese - �������ͣ�TRUE��ʾ�������壬FALSE��ʾӢ������
    //    [in] nFontSize - �����ֺţ���λ����
    // Remarks:
    //    ��������������壬Ӣ���������Helvetica��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID SetFont(DK_BOOL bChinese, DK_UINT nFontSize) = 0;

    //-------------------------------------------
    // Summary:
    //    ������һ���ı���Ҫ��ʾ��λ��
    // Parameters:
    //    [in] x - ������
    //    [in] y - ������
    // Remarks:
    //    ʹ���û��ռ�����ϵ
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID SetTextPosition(DK_DOUBLE x, DK_DOUBLE y) = 0;

    //-------------------------------------------
    // Summary:
    //    ��ʾһ���ı�����
    // Parameters:
    //    [in] szText - ָ���ı����ݵ�ָ��
    // Remarks:
    //    unicode�ַ�������'\0'��β
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID ShowText(const DK_WCHAR* szText) = 0;

    //-------------------------------------------
    // Summary:
    //    ��ָ��λ����ʾһ���ı�����
    // Parameters:
    //    [in] szText - ָ���ı����ݵ�ָ��
    //    [in] x - ������
    //    [in] y - ������
    // Remarks:
    //    unicode�ַ�������'\0'��β��ʹ���û��ռ�����ϵ��
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID ShowTextAtPosition(const DK_WCHAR* szText, DK_DOUBLE x, DK_DOUBLE y) = 0;

    //-------------------------------------------
    // Summary:
    //    �����������е����е����á����Ʋ���
    // Remarks:
    //    ��������´���������������Լ������Դ�����壬͸���ȵȣ�
    // SDK Version:
    //    ��DKP 1.0.0��ʼ֧��
    //-------------------------------------------
    virtual DK_VOID Clear() = 0;

public:
    virtual ~IDKPAppearanceStream() {}
};

#endif // #ifndef __KERNEL_PDFKIT_PDFLIB_IDKPAPPEARANCESTREAM_H__
