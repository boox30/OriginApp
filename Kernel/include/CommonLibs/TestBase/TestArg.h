#ifndef __KERNEL_TESTS_TESTBASE_TESTARG_H__
#define __KERNEL_TESTS_TESTBASE_TESTARG_H__

#include "KernelType.h"

class TestArg
{
public:
    // ���arg��"key:"��ͷ�򷵻�:֮����ַ���λ��,���򷵻�DK_NULL
    static const DK_CHAR* MatchArgWithPara(const DK_CHAR* arg, const DK_CHAR* key);
    static DK_BOOL MatchArg(const DK_CHAR* arg, const DK_CHAR* key);
private:
    TestArg();
};
#endif
