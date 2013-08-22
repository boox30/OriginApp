//===========================================================================
// Summary:
//		�Զ�����������ӿڡ�
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-08-27
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef	__FONTENGINE_INTERFACE_HEADERFILE__
#define __FONTENGINE_INTERFACE_HEADERFILE__

//===========================================================================

#include "TitanDef.h"

//===========================================================================

class ITitanFontEngine
{
public:
    //-------------------------------------------
	//	Summary:
	//		������������
	//-------------------------------------------
    virtual ~ITitanFontEngine(){}

	//-------------------------------------------
	//	Summary:
	//		��ʼ���������档
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void Init() = 0;
	
	//-------------------------------------------
	//	Summary:
	//		�����������档
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void Destroy() = 0;

	//-------------------------------------------
	//	Summary:
	//		�������塣
	//  Parameters:
	//		[in] pszFontFaceName	- �������֡�
	//		[in] dFontSize			- �����С��
	//		[in] nSytle				- ������
	//		[in] nWeight			- ����Ũ����
	//	Remarks:
	//		�Ű������Դ�����������û��ʵ�����������
	//	Return Value:
	//		����ɹ��򷵻�true�����򷵻�false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool LoadFont(const TP_WCHAR* pszFontFaceName, double dFontSize,
						  TP_FONTSTYLE_TYPE nSytle = TP_FONTSTYLE_NORMAL,
						  TP_FONTWEIGHT_TYPE nWeight = TP_FONTWEIGHT_NORMAL) = 0;

	//-------------------------------------------
	//	Summary:
	//		���������ļ���
	//  Parameters:
	//		[in] pszFontFilePath	- �����ļ�·����
	//		[in] dFontSize			- �����С��
	//		[in] nSytle				- ������
	//		[in] nWeight			- ����Ũ����
	//	Return Value:
	//		����ɹ��򷵻�true�����򷵻�false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool LoadFontFile(const TP_WCHAR* pszFontFilePath, double dFontSize,
							  TP_FONTSTYLE_TYPE nSytle = TP_FONTSTYLE_NORMAL,
							  TP_FONTWEIGHT_TYPE nWeight = TP_FONTWEIGHT_NORMAL) = 0;

	//-------------------------------------------
	//	Summary:
	//		�����Զ�����������
	//  Parameters:
	//		[in] hFont				- �Զ�����������
	//		[in] dFontSize			- �����С��
	//		[in] nSytle				- ������
	//		[in] nWeight			- ����Ũ����
	//	Remarks:
	//		�Ű������Դ�����������û��ʵ�����������
	//	Return Value:
	//		����ɹ��򷵻�true�����򷵻�false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool LoadFontHandle(TP_HANDLE hFont, double dFontSize,
								TP_FONTSTYLE_TYPE nSytle = TP_FONTSTYLE_NORMAL,
								TP_FONTWEIGHT_TYPE nWeight = TP_FONTWEIGHT_NORMAL) = 0;

	//-------------------------------------------
	//	Summary:
	//		���õ�ǰ��������塣
	//  Parameters:
	//		[in] pszFontFaceName	- �������֡�
	//	Remarks:
	//		�Ű������Դ�����������û��ʵ�����������
	//	Return Value:
	//		����ɹ��򷵻�true�����򷵻�false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool SetActiveFont(const TP_WCHAR* pszFontFaceName) = 0;

	//-------------------------------------------
	//	Summary:
	//		���õ�ǰ�������������
	//  Parameters:
	//		[in] hFont				- ��������
	//	Remarks:
	//		�Ű������Դ�����������û��ʵ�����������
	//	Return Value:
	//		����ɹ��򷵻�true�����򷵻�false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool SetActiveFontHandle(TP_HANDLE hFont) = 0;

	//-------------------------------------------
	//	Summary:
	//		������Ҫ֧�ֵ��ַ�����
	//  Parameters:
	//		[in] charset			- ������Ҫ֧�ֵ��ַ�����������Ϊ���ֵ����ϡ�
	//	Remarks:
	//		����ʵ������Ը��ݴ˲������������ĳЩ���ԣ����統Ҫ��������岻����ʱ��
	//		���ݴ˲���ѡ��Ĭ�����塣
	//	Return Value:
	//		����ɹ��򷵻�true�����򷵻�false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool SetSupportedCharset(TP_FONTCHARSET_TYPE charset) = 0;

	//-------------------------------------------
	//	Summary:
	//		���õ�ǰ�����С��
	//  Parameters:
	//		[in] dFontSize			- �����С��
	//	Return Value:
	//		����ɹ��򷵻�true�����򷵻�false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool SetFontSize(double dFontSize) = 0;

	//-------------------------------------------
	//	Summary:
	//		���õ�ǰ������
	//  Parameters:
	//		[in] nSytle			- ������
	//	Remarks:
	//		�Ű������Դ�����������û��ʵ�����������
	//	Return Value:
	//		����ɹ��򷵻�true�����򷵻�false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool SetFontStyle(TP_FONTSTYLE_TYPE nSytle) = 0;

	//-------------------------------------------
	//	Summary:
	//		���õ�ǰ����Ũ����
	//  Parameters:
	//		[in] nWeight			- ����Ũ����
	//	Remarks:
	//		�Ű������Դ�����������û��ʵ�����������
	//	Return Value:
	//		����ɹ��򷵻�true�����򷵻�false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool SetFontWeight(TP_FONTWEIGHT_TYPE nWeight) = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ����ָ���ַ��������ϲ��ֵĸ߶ȡ�
	//  Parameters:
	//		[in] ch				- �ַ����롣
	//	Return Value:
	//		����ɹ��򷵻ص�ǰ�����ַ��������ϲ��ֵĸ߶ȡ�
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual double GetCharAscent(TP_WCHAR ch) = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ����ָ���ַ��������²��ֵĸ߶ȡ�
	//  Parameters:
	//		[in] ch				- �ַ����롣
	//	Return Value:
	//		����ɹ��򷵻ص�ǰ�����ַ��������²��ֵĸ߶ȡ�
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual double GetCharDescent(TP_WCHAR ch) = 0;
	
	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ�������Ascent�߶ȡ�
	//	Return Value:
	//		����ɹ��򷵻ص�ǰ��������Ascent��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------	
	virtual double GetMaxAscent() = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ�������Descent�߶ȡ�
	//	Return Value:
	//		����ɹ��򷵻ص�ǰ��������Descent��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------	
	virtual double GetMaxDescent() = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ�������߶ȡ�
	//	Return Value:
	//		����ɹ��򷵻ص�ǰ��������߶ȡ�
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------	
	virtual double GetMaxHeight() = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ��������ȡ�
	//	Return Value:
	//		����ɹ��򷵻ص�ǰ���������ȡ�
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------	
	virtual double GetMaxWidth() = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ����ָ���ַ��Ŀ�ȡ�
	//  Parameters:
	//		[in] ch				- �ַ����롣
	//	Return Value:
	//		����ɹ��򷵻��ַ���ȡ�
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual double GetCharWidth(TP_WCHAR ch) = 0;

	//-------------------------------------------
	//	Summary:
	//		��ǰ�����Ƿ���Kerning��
	//	Return Value:
	//		�з���true��û�з���false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool HasKerning() = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ2���ַ����־������Ϣ��
	//  Parameters:
	//		[in] ch				- ��һ���ַ����롣
	//		[in] ch				- �ڶ����ַ����롣
	//		[out] dx			- x�����־������
	//		[out] dy			- y�����־������
	//	Return Value:
	//		����ɹ��򷵻�true�����򷵻�false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool GetKerning(TP_WCHAR chFirst, TP_WCHAR chSecond, double& dx, double& dy) = 0;

	//-------------------------------------------
	//	Summary:
	//		��ǰ�����Ƿ�֧�����š�
	//	Return Value:
	//		֧�ַ���true�����򷵻�false��
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual bool HasVertical() = 0;

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ����ָ���ַ������ζ�����
	//  Parameters:
	//		[in]  ch				- �ַ����롣
	//		[out] glyphMetrics		- ���ζ�����
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void GetCharMetrics(TP_WCHAR ch, TP_GLYPHMETRICS& glyphMetrics) = 0; 

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ����ָ���������������ζ�����
	//  Parameters:
	//		[in]  dwGlyphIndex		- ����������
	//		[out] glyphMetrics		- ���ζ�����
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual void GetGlyphMetrics(unsigned int dwGlyphIndex, TP_GLYPHMETRICS& glyphMetrics) = 0; 

	//-------------------------------------------
	//	Summary:
	//		��ȡ��ǰ����ָ���������������ζ�����
	//  Parameters:
	//		[in]  ch			- �ַ����롣
	//		[out]  bChanged		- ����ʱ�������Ƿ�ı䡣
	//	Return Value:
	//		�õ��ַ�����ʱ������������������Ǿ������α任���µ����ε�������
	//  Availability:
	//		��Titan 1.0��ʼ֧�֡�
	//-------------------------------------------
	virtual unsigned int GetVerticalGlyphIndex(TP_WCHAR ch, bool& bChanged) = 0;

	//-------------------------------------------
	//	Summary:
	//		���ñ��������ļ�
	//  Parameters:
	//		[in]   backupFontFile - �ַ����롣
	//	Return Value:
	//		None
	//  Availability:
	//		��Titan 1.0.6��ʼ֧�֡�
	//-------------------------------------------
    virtual void SetBackupFontFile(const TP_WCHAR* backupFontFile) = 0;
};

//===========================================================================

#endif	//#ifndef __FONTENGINE_INTERFACE_HEADERFILE__
