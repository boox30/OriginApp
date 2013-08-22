#ifndef _MD5Checker_H
#define _MD5Checker_H

/*
����Կ��MD5�㷨��md5.h�������к�����

char* MDString (char *);
// ��������һ���ַ���������md5�㷨����󣬷��ؽ����һ��������32���ַ����ַ���
char* MDFile (char *);
// ��������һ���ļ������ļ����ݾ���md5�㷨����󣬷��ؽ����һ��������32���ַ����ַ���
char* hmac_md5(char* text, char* key);
// ��������һ���ַ���text,��һ��������Կ���ַ���key,����hmac_md5�㷨�������ش�������һ�������ַ�����32���ַ���
*/


#include <stdio.h>
#include <time.h>
#include <string.h>
#include "singleton.h"

#define MD 5  //cy?

/* GLOBAL.H - RSAREF types and constants
 */

/* PROTOTYPES should be set to one if and only if the compiler supports
  function argument prototyping.
  The following makes PROTOTYPES default to 0 if it has not already
  been defined with C compiler flags.
 */
#ifndef PROTOTYPES
#define PROTOTYPES 0
#endif

/* POINTER defines a generic pointer type */
typedef unsigned char *POINTER;

/* UINT2 defines a two byte word */
typedef unsigned short int UINT2;

/* UINT4 defines a four byte word */
typedef unsigned long int UINT4;

/* PROTO_LIST is defined depending on how PROTOTYPES is defined above.
If using PROTOTYPES, then PROTO_LIST returns the list, otherwise it
  returns an empty list.
 */
#if PROTOTYPES
#define PROTO_LIST(list) list
#else
#define PROTO_LIST(list) ()
#endif


 /* Length of test block, number of test blocks.
 */
#define TEST_BLOCK_LEN 1000
#define TEST_BLOCK_COUNT 1000



/* Constants for MD5Transform routine.
 */
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

typedef struct {
  UINT4 state[4];                                   /* state (ABCD) */
  UINT4 count[2];        /* number of bits, modulo 2^64 (lsb first) */
  unsigned char buffer[64];                         /* input buffer */
} MD5_CTX;





/* F, G, H and I are basic MD5 functions.
 */
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

/* ROTATE_LEFT rotates x left n bits.
 */
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

/* FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
Rotation is separate from addition to prevent recomputation.
 */
#define FF(a, b, c, d, x, s, ac) {              \
 (a) += F((b), (c), (d)) + (x) + (UINT4)(ac);   \
 (a) = ROTATE_LEFT ((a), (s));                  \
 (a) += (b);                                    \
  }
#define GG(a, b, c, d, x, s, ac) {              \
 (a) += G ((b), (c), (d)) + (x) + (UINT4)(ac);  \
 (a) = ROTATE_LEFT ((a), (s));                  \
 (a) += (b);                                    \
  }
#define HH(a, b, c, d, x, s, ac) {              \
 (a) += H ((b), (c), (d)) + (x) + (UINT4)(ac);  \
 (a) = ROTATE_LEFT ((a), (s));                  \
 (a) += (b);                                    \
  }
#define II(a, b, c, d, x, s, ac) {              \
 (a) += I ((b), (c), (d)) + (x) + (UINT4)(ac);  \
 (a) = ROTATE_LEFT ((a), (s));                  \
 (a) += (b);                                    \
  }

class MD5Checker
{
    SINGLETON_H(MD5Checker);

    MD5Checker(){}
    ~MD5Checker(){}

    /*void MD5Init PROTO_LIST ((MD5_CTX *));
    void MD5Update PROTO_LIST
      ((MD5_CTX *, unsigned char *, unsigned int));
    void MD5Final PROTO_LIST ((unsigned char [16], MD5_CT X *));

    static void MD5Transform PROTO_LIST ((UINT4 [4], unsigned char [64]));
    static void Encode PROTO_LIST
      ((unsigned char *, UINT4 *, unsigned int));
    static void Decode PROTO_LIST
      ((UINT4 *, unsigned char *, unsigned int));
    static void MD5_memcpy PROTO_LIST ((POINTER, POINTER, unsigned int));
    static void MD5_memset PROTO_LIST ((POINTER, int, unsigned int));
    */

    void DK_MD5Init (MD5_CTX *context);
    void DK_MD5Update(MD5_CTX *context, unsigned char *input,unsigned int inputLen);
    char* DK_hmac_md5(char* text, char* key);
    void DK_MD5Final (unsigned char digest[16], MD5_CTX *context);
    void DK_MD5Transform  (UINT4 [4], unsigned char [64]) ;
    void DK_Encode(unsigned char *, UINT4 *, unsigned int);
    void DK_Decode (UINT4 *, unsigned char *, unsigned int);
    void DK_MD5_memcpy(POINTER, POINTER, unsigned int);
    void DK_MD5_memset(POINTER, int, unsigned int);

    public:
        char* DK_MDFile (const char *filename);
        char* DK_MDString (const char *string);
};

#endif //_MD5Checker_H
