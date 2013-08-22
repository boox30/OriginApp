//===========================================================================
// Summary:
//		Encoding
// Usage:
//	    Null
// Remarks:
//		Null
// Date:
//		2011-09-03
// Author:
//		Peng Feng(pengf@duokan.com)
//===========================================================================
#ifndef	__KERNEL_COMMONLIBS_KERNELBASE_KERNELIENCODIN_H__
#define	__KERNEL_COMMONLIBS_KERNELBASE_KERNELIENCODIN_H__

//===========================================================================
#include "KernelBaseType.h"
#include "KernelType.h"

//===========================================================================

class CharIter
{
public:
    enum SKIP_BOM_CATEGORY
    {
        SKIP_BOM,
        NOSKIP_BOM
    };

    CharIter(const DK_BYTE* data, DK_UINT dataLen)
        : m_data(data)
    {
        m_dataEnd = data + dataLen;
    }

    virtual ~CharIter(){};
    DK_VOID SetData(const DK_BYTE* data, DK_UINT dataLen, SKIP_BOM_CATEGORY skipBom = NOSKIP_BOM)
    {
        m_data = data;
        m_dataEnd = data + dataLen;
        if (SKIP_BOM == skipBom)
        {
            SkipBom();
        }
    }
    virtual DK_VOID SkipBom()
    {
        // do nothing by default
    };

    CharIter& operator+=(DK_UINT stepInChar)
    {
        Advance(stepInChar);
        return *this;
    }
    const DK_CHAR* GetData()
    {
        return (const DK_CHAR*)m_data;
    }

	//-------------------------------------------
	//	Summary:
    //      �ж�һ��λ���Ƿ����ַ��߽磬    
	//	Parameters:
	//		[in] pos                - Ҫ����λ��
	//	Remarks:
    //      null
	//	Return Value:
    //      ���������һ���ַ��������return DK_TRUE
    //      ����return DK_FALSE
	//-------------------------------------------
    virtual DK_BOOL IsPositionOk(const DK_BYTE* pos);

	//-------------------------------------------
	//	Summary:
    //      ��ǰ�ƶ�stepInByte���ֽڣ�
	//	Parameters:
	//		[in] stepInByte          - Ҫ�ƶ����ֽ�
	//	Remarks:
    //      ����ƶ�֮���䵽һ���ַ��ķ���ʼλ��
    //      ���˻ص����ַ�����ʼλ��
	//	Return Value:
    //      ʵ���ƶ����ַ���
	//-------------------------------------------
    virtual DK_UINT AdvanceBytes(DK_UINT stepInByte);

	//-------------------------------------------
	//	Summary:
    //      ��ǰ�ƶ�stepInByte���ַ���
	//	Parameters:
	//		[in] stepInByte          - Ҫ�ƶ����ֽ�
	//	Remarks:
    //      ����ƶ�֮���䵽һ���ַ��ķ���ʼλ��
    //      ���˻ص����ַ�����ʼλ��
	//	Return Value:
    //      ʵ���ƶ����ַ���
	//-------------------------------------------
    virtual DK_UINT Advance(DK_UINT stepInChar, DK_BOOL *pHaveNewLine = DK_NULL) = 0;

	//-------------------------------------------
	//	Summary:
    //      �жϵ�ǰm_data���Ƿ�ո񣬰����س���������ȫ�ǿո�
	//	Parameters:
    //      None
	//	Remarks:
	//	Return Value:
    //      �ǿո�DK_TRUE,����DK_FALSE
	//-------------------------------------------
    virtual DK_BOOL IsSpace() const = 0;

	//-------------------------------------------
	//	Summary:
    //      �жϵ�ǰm_data���Ƿ���
	//	Parameters:
    //      None
	//	Remarks:
	//	Return Value:
    //      �ǻ���DK_TRUE,����DK_FALSE
	//-------------------------------------------
    virtual DK_BOOL IsNewLine() const = 0;

	//-------------------------------------------
	//	Summary:
    //      ����m_data��ʼ�Ŀո�(�������Ŀո�)
	//	Parameters:
    //      None
	//	Remarks:
	//	Return Value:
    //      ʵ�ʺ��ԵĿո���
	//-------------------------------------------
    DK_UINT SkipSpaces();
protected:
    const DK_BYTE* m_data;
    const DK_BYTE* m_dataEnd;
    DK_BOOL IsPositionInRange(const DK_BYTE* pos)
    {
        return m_data <= pos && pos < m_dataEnd;
    }
};

class EncodingUtil
{
public:
    enum Encoding
    {
        SYSDEFAULT,
        GBK,
        BIG5,
        SJIS,
        UNICODE_LE,
        UNICODE_BE,
        WCHAR,
        UTF8,
        LATIN1
    };
    enum {MAX_BYTES_OF_CHAR = 6};
    enum {MAX_BYTES_OF_UTF8CHAR = 6};
    
	//-------------------------------------------
	//	Summary:
	//	    Convert Encoding
	//	Parameters:
	//		[in] from               - encoding of in buf
    //		[in] to                 - encoding of out buf
    //		[in] pInBuf             - pInBuf point to begin position to 
    //		                          buf to convert,
    //      [in/out] pInBytes       - pInBytes store bytes in inBuf
    //                                to convert as in param, and store
    //                                bytes converted in inBuf as out param
    //		[in] pOutBuf            - pOutBuf points to begin position to 
    //		                          store convert result 
    //      [in/out] pOutBytes      - pOutBytesLeft store bytes in out buf
    //                                to store convert result as in param, 
    //                                and store bytes converted in out buf
	//	Remarks:
	//	   see man 3 iconv
	//	Return Value:
	//		return -1 when failed, but source can still be partially converted.
    //		check pInBytes and pOutBytes to get data converted.
    //		return non-reversible convertsions performed during this call
	//-------------------------------------------
    static DK_INT Convert(Encoding from, 
            Encoding to, 
            const DK_CHAR* pInBuf, 
            DK_SIZE_T* pInBytes, 
            DK_CHAR* pOutBuf, 
            DK_SIZE_T* pOutBytes);

	//-------------------------------------------
	//	Summary:
	//	    Force Convert Encoding
	//	Parameters:
	//		[in] from               - encoding of in buf
    //		[in] to                 - encoding of out buf
    //		[in] pInBuf             - pInBuf point to begin position to 
    //		                          buf to convert, NOTICE: the buf will be modified
    //                                if invalid multibyte sequence is encountered
    //      [in/out] pInBytes       - pInBytes store bytes in inBuf
    //                                to convert as in param, and store
    //                                bytes converted in inBuf as out param
    //		[in] pOutBuf            - pOutBuf points to begin position to 
    //		                          store convert result 
    //      [in/out] pOutBytes      - pOutBytesLeft store bytes in out buf
    //                                to store convert result as in param, 
    //                                and store bytes converted in out buf
	//	Remarks:
	//	   see man 3 iconv
    //     for invalid sequence, fill char with ?
	//	Return Value:
	//		return -1 when failed, but source can still be partially converted.
    //		check pInBytes and pOutBytes to get data converted.
    //		return non-reversible convertsions performed during this call
	//-------------------------------------------
    static DK_INT ForceConvert(Encoding from, 
            Encoding to, 
            DK_CHAR* pInBuf, 
            DK_SIZE_T* pInBytes, 
            DK_CHAR* pOutBuf, 
            DK_SIZE_T* pOutBytes);

	//-------------------------------------------
	//	Summary:
	//	    Convert Encoding wrapper
	//	Parameters:
	//		[in] src                - src string
    //		[in] encoding           - dst encoding
	//	Remarks:
    //      null
	//	Return Value:
	//		return null terminated string in dst encoding,
    //      return value must be freed by DK_FREE 
    //      return DK_NULL if out of memory or encoding error
	//-------------------------------------------
    static DK_CHAR* WCharToChar(const DK_WCHAR* src, Encoding encoding = SYSDEFAULT);    

	//-------------------------------------------
	//	Summary:
	//	    Convert Encoding wrapper
	//	Parameters:
	//		[in] src                - src wide string
    //		[in] encoding           - src encoding
	//	Remarks:
    //      null
	//	Return Value:
	//		return null terminated string in WCHAR
    //      return value must be freed by DK_FREE 
    //      return DK_NULL if out of memory or encoding error
	//-------------------------------------------
    static DK_WCHAR* CharToWChar(const DK_CHAR* src, Encoding encoding = SYSDEFAULT);

	//-------------------------------------------
	//	Summary:
	//	    Convert Single DK_WCHAR from simple Chinese to traditional one
	//	Parameters:
	//		[in] src            - src simple Chinese unicode
    //      [out] pDst          - dst traditional Chinese unicode
	//	Remarks:
    //      null
	//	Return Value:
	//		return DK_TRUE if convert succeeded.
	//-------------------------------------------
    static DK_BOOL CHStoCHTChar(DK_WCHAR src, DK_WCHAR* pDst);

	//-------------------------------------------
	//	Summary:
	//	    Convert Single DK_WCHAR from traditional Chinese to simple one
	//	Parameters:
	//		[in] src            - src traditional Chinese unicode
    //      [out] pDst          - dst simple Chinese unicode
	//	Remarks:
    //      null
	//	Return Value:
	//		return DK_TRUE if convert succeeded.
	//-------------------------------------------
    static DK_BOOL CHTtoCHSChar(DK_WCHAR src, DK_WCHAR* pDst);

    static const DK_CHAR* GetEncodingName(Encoding encoding);
    static const DK_CHAR* GetSysDefaultEncoding();
    static const Encoding GetEncodingByCodepage(DK_UINT codepage);

    static DK_SIZE_T StrLenInBytes(const DK_CHAR* str, Encoding encoding);
    static DK_SIZE_T EstimateStrLenInChars(const DK_CHAR* str, Encoding encoding);
    static DK_SIZE_T EstimateStrLenInChars(DK_SIZE_T strLenInBytes, Encoding encoding);
    static DK_SIZE_T GetMaxBytesPerChar(Encoding  encoding);

    static CharIter* CreateCharIter(const DK_BYTE* data, DK_UINT dataLen, Encoding encoding);

    // check if a byte can be a leading bye of a utf8 char sequence
    static DK_BOOL IsValidLeadingByteOfUtf8(DK_BYTE c);

    // get the length of bytes for a leading char of utf8 sequence
    // if the char is invalid leading char, return 0
    static DK_UINT GetCharSizeForUtf8LeadingByte(DK_BYTE c);

    // ���ݵ�ǰ���������ַ��ж��Ƿ���Ҫת��Ϊ����
    static DK_BOOL NeedConvertToCHT(DK_DWORD ch);

private:
    EncodingUtil();
};
#endif
