#include <iostream>
#include <string>
#include <pthread.h>
#include <vector>
#include <semaphore.h>

class IDownloadTask;
namespace Download
{

#define MAX_URL_LENGTH 1024
#define MAX_NAME_LENGTH 1024
#define RANGE_BUF_LENGTH 128

    struct UrlFileInfo
    {
        unsigned int    uLength;                            // ����
        char            szFileName[MAX_NAME_LENGTH];        // �ļ���(http header����)
        char            szRange[RANGE_BUF_LENGTH];          // range��������Ч
        bool            bSupportBreakpointContinuingly;     // �Ƿ�֧�ֶϵ�����(�д�����)
        char            szUrl[MAX_URL_LENGTH];				// ���յ���ЧURL
        char            origUrl[MAX_URL_LENGTH];			// ԭʼURL
        char            szUesrAgent[RANGE_BUF_LENGTH];      // userAgent
    };


    enum DLResult{
        DOWNLOAD_OK,
        DOWNLOAD_NOT_SUPPORT_BREAKPOINT_CONTINUINGLY,
        DOWNLOAD_INVALID_ARGUMENT,
        DOWNLOAD_INIT_ERROR,
        DOWNLOAD_EXECUTE_ERROR,
        DOWNLOAD_NETWORK_ERROR,
        DOWNLOAD_FILE_ERROR,
        DOWNLOAD_OUT_OF_MEMORY,
        DOWNLOAD_HIBERNATED,
        DOWNLOAD_ABORTED,
		DOWNLOAD_WRITE_ERROR
    };

    struct TaskState
    {
        bool *taskworking;                // �Ƿ���������
        unsigned int *pDLPercentage;    // ��ǰ�����ؽ��Ȱٷֱ�,������ʱ����DownloadManager��TASK�����ؽ���
        unsigned int uDownloadedBytes;    // �����ص��ֽ���
        unsigned int uCurTransferBytes;    // ��ǰ�����Ѵ�����ֽ���
        unsigned int uTotalBytes;        // �ܵ��ֽ���
    };

    struct HttpHeaderState
    {
	public:
		HttpHeaderState()
			: bIsFromBreak(false)
			, uRequestCode(0)
		{

		}
		~HttpHeaderState(){}
        bool bIsFromBreak;        // ��ʾ���ڶϵ�����
        unsigned int uRequestCode;    // httpͷ���ص�״̬��
    };

	struct HttpHeaderInfo
	{
	public:
		HttpHeaderInfo()
			: m_clsHeaderState()
			, m_strLocation("")
			, m_strAcceptRanges("")
			, m_strFileName("")
			, m_strContentType("")
		{

		}
		~HttpHeaderInfo(){}
		HttpHeaderState m_clsHeaderState;
		std::string m_strLocation;			// ������Ч���ӵ�ַ
		std::string m_strAcceptRanges;		// httpͷ��Accept-Ranges�ֶ�
		std::string m_strFileName;			// httpͷ��Content-Disposition:filename�ֶ�
		std::string m_strContentType;		// httpͷ��Content-Type�ֶ�
	};
    
    struct WriteDataInfo
    {
        HttpHeaderInfo* headerInfo;
        FILE *fp;
    };

    DLResult getFileInfoFromWeb(
        const std::string& strUrl,  //����1�����������ṩ��URL
        struct UrlFileInfo* info    //����2���ļ���Ϣ�ṹ�壬���Ի�ȡ����http headerָ���ļ������ļ����ȣ��ϵ�����֧��(�д�����)������szRange��Ч
    );

    DLResult download2Path(
        const std::string& strUrl,			// ����1��url��
		struct UrlFileInfo* _pclsInfo,		//����2���ļ���Ϣ�ṹ�壬���Ի�ȡ����http headerָ���ļ������ļ����ȣ��ϵ�����֧��(�д�����)������szRange��Ч
        const char* lpszPath,				// ���ص�·����ֻ��δָ���ļ���ʱ��Ч��
        IDownloadTask* task					// ����״̬�������������ص���ͣ�����ؽ��ȵ�
    );

	// ��HTTPͷ�����ļ���һЩ������Ϣ
	bool GetUrlFileInfo(const HttpHeaderInfo &_clsHeader,struct UrlFileInfo* _pInfo);

    size_t WriteDataCallBack(void *ptr, size_t size, size_t nmemb, void *data);

}
