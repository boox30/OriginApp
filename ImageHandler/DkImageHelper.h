#ifndef __DKIMAGEHELPER_INCLUDE__
#define __DKIMAGEHELPER_INCLUDE__

#include "dkBaseType.h"
#include "ImageHandler/ImageHandler.h"

namespace DkFormat
{
    class DkImageHelper
    {
    public:
        // �ڴ����ⲿ����
        static bool DitherRGB32ToGray16(const DK_IMAGE &srcImage, DK_IMAGE *pDstImage);
        // ���滻�ڴ�
        static bool ConvertRGB32ToGray256(DK_IMAGE *pImage);
        // �����滻�ڴ�
        static void ConvertGray256ToGray16(const DK_IMAGE &image);
        static void ConvertGray256ToBinary(const DK_IMAGE &image);
        static void DitherGray256ToGray16(const DK_IMAGE &image);
        static void DitherGray256ToBinary(const DK_IMAGE &image);
    public:
        static ImageHandler * CreateImageHandlerInstance(const char *pFilePath);
        static ImageHandler * CreateImageHandlerInstance(IDkStream *pImgStream);
    };
}

#endif
