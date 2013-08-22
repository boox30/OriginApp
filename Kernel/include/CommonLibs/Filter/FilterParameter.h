//===========================================================================
// Summary:
//     Filter ����
// Usage:
//     Null
// Remarks:
//     Null
// Date:
//     2011-12-02
// Author:
//     Zhai Guanghe(zhaigh@duokan.com)
//===========================================================================

#ifndef __KERNEL_COMMONLIBS_FILTER_FILTERPARAMETER_H__
#define __KERNEL_COMMONLIBS_FILTER_FILTERPARAMETER_H__

#include "KernelType.h"
#include "KernelBaseType.h"
#include "KernelRenderType.h"

enum FilterAlgorithm
{
    FILTER_NONE, 
    // ѹ������
    FILTER_ZIP, FILTER_ZIP_EX, FILTER_FLATE, 
    FILTER_LZW, FILTER_RUN_LENGTH, FILTER_CCITTFAX, 
    FILTER_DCT, FILTER_JBIG2, FILTER_JPX, 
    // ���벿��
    FILTER_ASCIIHEX, FILTER_ASCII85, FILTER_BASE64, FILTER_URL, 
    // ���ܲ���
    FILTER_AES_CBC, FILTER_AES_CTR, FILTER_AES_ECB, FILTER_AES_KW, 
    FILTER_AES_CTR_EX, 
    FILTER_TWOFISH, 
    FILTER_RC4, FILTER_RSA_V15, FILTER_RSA, 
    // ɢ�в���
    FILTER_MD5, FILTER_SHA_1, FILTER_SHA_224, FILTER_SHA_256, FILTER_SHA_384, FILTER_SHA_512 
};

struct ZipParam
{
    DK_UINT uncompSize;
};

struct FlateParam
{
    DK_INT predictor;        // ��־
    DK_INT colors;           // һ�����ص���ɫ������
    DK_INT bitsPerComponent; // ÿ����ɫ����ռ��λ��
    DK_INT columns;          // ������ÿ�����ظ�����
    DK_INT earlyChange;      // LZW����
};

// ��Ϊͬһ��������ʹ��ͳһ�Ĳ�ֺ���
typedef FlateParam LzwParam;

struct CCITTFaxParam
{
    DK_INT  k;
    DK_BOOL endOfLine;
    DK_BOOL encodedByteAlign;
    DK_INT  columns;
    DK_INT  rows;
    DK_BOOL endOfBlock;
    DK_BOOL blackIs1;
    DK_INT  damagedRowsBeforeError;
};

struct DctParam
{
    DK_INT    colorTransform;
    DK_DOUBLE scale;  // ���ű��ʣ�ʹ��jpeg�����С������ܣ�������ű���Ϊ?/8��ͼ������ٶȲ������ڴ�ռ�ã�
};

struct Jbig2Param
{
    DK_INT    globalDataLen;
    DK_BYTE * pJBIG2Globals;
    DK_UINT   length;        // ѹ�����ݵ��ܳ�
};

struct JpxParam
{
    DK_UINT   length; // ѹ�����ݵ��ܳ�
    DK_DOUBLE scale;  // ���ű��ʣ�ʹ��JPX�����С������ܣ�������ű���λ��[scale, 1.0]��ͼ������ٶȲ������ڴ�ռ�ã�
};

struct AesParam
{
    DK_BYTE userKey[32];    // ���256λ��Կ
    DK_UINT keyLen;         // ���볤��
    DK_BYTE initVector[16]; // �ֿ鳤��128λ
};

struct TwofishParam
{
    DK_BYTE userKey[32];    // ���256λ��Կ
    DK_UINT keyLen;         // ���볤��
};

struct Rc4Param
{
    DK_BYTE userKey[32];    // ���256λ��Կ
    DK_UINT keyLen;         // ���볤��
};

struct RsaParam
{
    DK_BOOL         isPublicKey;
    const DK_BYTE * n;
    DK_UINT         nLen;
    const DK_BYTE * e;
    DK_UINT         eLen;
    const DK_BYTE * d;
    DK_UINT         dLen;
    // ���½�˽Կʹ�ã�����ٶ�
    const DK_BYTE * p;
    DK_UINT         pLen;
    const DK_BYTE * q;
    DK_UINT         qLen;
    const DK_BYTE * dmp1;
    DK_UINT         dmp1Len;
    const DK_BYTE * dmq1;
    DK_UINT         dmq1Len;
    const DK_BYTE * iqmp;
    DK_UINT         iqmpLen;
};

union FilterParam
{
    // ѹ������
    ZipParam      zip;
    FlateParam    flate;
    LzwParam      lzw;
    CCITTFaxParam ccittfax;
    DctParam      dct;
    Jbig2Param    jbig2;
    JpxParam      jpx;
    // ���ܲ���
    AesParam      aes;
    TwofishParam  twofish;
    Rc4Param      rc4;
    RsaParam      rsa;
};

enum FILTER_COLORSPACE_TYPE
{
    FILTER_COLORSPACE_UNDEFINED,
    FILTER_COLORSPACE_GRAY,
    FILTER_COLORSPACE_RGB
};

struct FilterInfo
{
    DK_UINT bound;                      // Decode / Encode�����ݳ����Ͻ�
    // ͼ�����ԣ���ǰֻ��JPX����
    FILTER_COLORSPACE_TYPE colorSpace;
    DK_UINT width;
    DK_UINT height;

    FilterInfo()
    : bound(0)
    , colorSpace(FILTER_COLORSPACE_UNDEFINED)
    , width(0)
    , height(0)
    {
    }
};

#endif // __KERNEL_COMMONLIBS_FILTER_FILTERPARAMETER_H__
