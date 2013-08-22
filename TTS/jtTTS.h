#ifndef __JT_TEXTTOSPEECH_H__
#define __JT_TEXTTOSPEECH_H__

#include <stdio.h>
#include "singleton.h"
#include <pthread.h>
#include <vector>
#include <string>

using std::string;

// �ص��û����ݶ���
typedef struct tagUserData
{
    FILE *    pInputFile;        // �ı������ļ�
    FILE *    pOutputFile;    // �ϳ�������������ļ�
    unsigned long    hTTS;    // �ϳ�������
}jtUserData;

class JT_TTS
{
    SINGLETON_H(JT_TTS)

public:    
    JT_TTS();
    ~JT_TTS();
    
    int        TTS_Init();
    void       TTS_UnInit();
    
    int        TTS_Play(std::string& _strTxtBuffer, int _iBufferLen);
    int        TTS_Stop();
    
    bool       TTS_IsPlay();

private:
    static JT_TTS*                m_hInstance;
    static unsigned long        m_hTTS;
    static unsigned char*        m_pHeap;

    bool    m_bIsPlay;
};

#endif // __JT_TEXTTOSPEECH_H__
