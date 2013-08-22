///////////////////////////////////////////////////////////////////////
// idk_kdfnt.h
// Contact:
// Copyright (c) Duokan Corporation. All rights reserved.
//
////////////////////////////////////////////////////////////////////////

#ifndef _IDK_KDFNT_H_
#define _IDK_KDFNT_H_

#include "KernelBaseType.h"
#include "KernelType.h"
#include <vector>

using std::wstring;

typedef const DK_CHAR* DK_LPCSTR;

#define USER_FONT_PATH       "/mnt/us/DK_System/xKindle/res/userfonts/"
#define SYSTEM_FONT_PATH     "/DuoKan/res/sysfonts/"

// Classes Defined in other header
class DKTTFInfo;

// Classes Defined in this header
class DKFont;
class DKFontManager;

//Only for ttf/ttc font files
class DKFont
{
public:
    DKFont();
    ~DKFont();
    //LoadFont and parse to get the font information from ttf/ttc
    bool   LoadFont(std::string& wsFileName);
    void   Release();

    int      GetFontStyle();
    std::string GetChineseFontName() const;
    std::vector<std::wstring>*   GetFullFontName() const;
    std::vector<std::wstring>*   GetFontFamilyName();    
    std::vector<std::wstring>*   GetFontSubFamilyName();
    bool     GetSupportedCodePage(std::vector<unsigned short>& lstCodepage);
    bool     GetSupportedCharSet(std::vector<unsigned short>&  lstCharSet);
    bool IsSupportingCharSet(DK_CHARSET_TYPE charSet);
    const char* GetFontPath(bool bFullPath = DK_TRUE);
    bool operator()(const DKFont* pLeft, const DKFont* pRight);

private:
    DKTTFInfo* m_pTTFInfo;
    std::string    m_pFilePath;
    std::string    m_pFileDir;
};

class DKFontManager
{
public:
    DKFontManager();
    virtual ~DKFontManager();
    
    virtual void Release();
 
    virtual bool    AddFont(DKFont* pFont);    
    virtual void    RemoveFont(DKFont* pFont);        
    virtual DKFont* GetFont(std::string& wsFontPath);
    virtual DKFont* GetFontForFaceName(const std::wstring& wsFaceName);
    virtual bool    GetAllFont(std::vector<DKFont*> &lstFont);
    
    virtual bool    AddFontsDir(std::string& wsFontDir);    
    virtual void    RemoveFontsDir(std::string& wsFontDir);
    virtual bool    GetFontsDir(std::vector<std::string>& lstFontDir);
    
    virtual bool GetAllFontsDir(std::string& wsFontPath, std::vector<std::string> &lstFontDir);    
    
    // ����ӵ��ļ����£������ļ��Ƿ��б䶯 ������ӡ�ɾ����
    virtual bool IsFontsDirUpdated ();
    virtual void RefreshAllFontsInfo();
    
    virtual bool GetFontListByCodePage(unsigned short wCodePage, std::vector<DKFont*> &lstFont);
    virtual bool GetFontListByCharSet(DK_CHARSET_TYPE eCharSet, std::vector<DKFont*> &lstFont);    

    virtual bool SetDefaultFontFaceNameForCodePage(unsigned short wCodePage, const wstring& strFaceName);
    virtual bool SetDefaultFontFaceNameForCharSet(DK_CHARSET_TYPE eCharSet, const wstring& strFaceName);
    virtual bool SetSystemDefaultFontFaceName(const wstring& strFaceName);

    virtual bool GetDefaultFontFaceNameForCodePage(unsigned short wCodePage, wstring* pStrFaceName);
    virtual bool GetDefaultFontFaceNameForCharSet(DK_CHARSET_TYPE eCharSet, wstring* pStrFaceName);
    virtual bool GetSystemDefaultFontFaceName(wstring* pStrFaceName);

    // ��ȡ����Ŀ¼���ļ��Ĵ�С֮��,�����ж��ļ����µ��ļ�����
    int    GetDirFileSize (const std::string& wsFontDir = std::string(USER_FONT_PATH));

protected:
    bool   AddDir(std::string& wsFontDir);
    void   RemoveDir(std::string& wsFontDir);

    std::vector<DKFont*>       m_lstFont;
    std::vector<std::string>   m_lstFontDir;
    std::wstring               m_strSysDefFontFaceName;
    int                        m_iFontSizeRecord;       // ��¼���������С֮��, ֻ���ͨ�� AddFontsDir ()��ӵ�Ŀ¼
};
extern DKFontManager* g_pFontManager;
#endif // _IDK_KDFNT_H_


