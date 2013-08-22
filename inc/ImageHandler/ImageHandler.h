#ifndef __IMAGEHANDLER_INCLUDE__
#define __IMAGEHANDLER_INCLUDE__

#include "dkObjBase.h"
#include "DkSPtr.h"
#include "GUI/dkImage.h"
#include "dkBuffer.h"
#include "SequentialStream.h"

class IDkStream;

namespace DkFormat
{
    class ImageHandler
    {
    public:
        virtual ~ImageHandler() {};

        virtual bool LoadFromFile(const char *pFileName) = 0;
        virtual bool LoadFromStream(IDkStream *pStream) = 0;
        // ����ԭʼ���
        virtual int GetWidth() = 0;
        // ����ԭʼ�߶�
        virtual int GetHeight() = 0;
        // ��ͼƬָ������ü��������ŵ�ָ����С
        // ����ȱ������ŵĻ����ϲ�Ӧ��֤����ĸ߿��һ��
        virtual bool CropAndResize(DK_RECT srcRect, int iNewWidth, int iNewHeight, int iColorChannels = 4) = 0;
        // ������ת�Ƕȣ�Ҫ��CropAndResize����ã�����0/90/180/270
        virtual bool Rotate(int iAngle) = 0;
        // ��ȡDK_IMAGE��Ӧ��CropAndResize��RotateImage�������Ҫ�������
        virtual bool GetImage(DK_IMAGE *pImg) = 0;
    };
}
#endif
