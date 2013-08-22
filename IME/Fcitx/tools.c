/***************************************************************************
 *   Copyright (C) 2002~2005 by Yuking                                     *
 *   yuking_net@sohu.com                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
/**
 * @file   tools.c
 * @author Yuking yuking_net@sohu.com
 * @date   2008-1-16
 *
 * @brief  �����ļ���д
 *
 *
 */
#include "stdafx.h"

#include "tools.h"

#include <stdio.h>
#include <stdlib.h>
//szj #include <sys/stat.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#include "ui.h"
#include "MainWindow.h"
#include "InputWindow.h"
#include "PYFA.h"
#include "py.h"
#include "sp.h"
#include "ime.h"
#include "KeyList.h"

extern Display *dpy;
extern int      iScreen;
extern int      MAINWND_WIDTH;
extern int      iMainWindowX;
extern int      iMainWindowY;
extern int      iInputWindowX;
extern int      iInputWindowY;
extern uint      iInputWindowWidth;
extern uint      iInputWindowHeight;

extern int      iMaxCandWord;
extern Bool     _3DEffectMainWindow;
extern _3D_EFFECT _3DEffectInputWindow;
extern WINDOW_COLOR inputWindowColor;
extern WINDOW_COLOR mainWindowColor;
extern MESSAGE_COLOR IMNameColor[];
extern MESSAGE_COLOR messageColor[];
extern MESSAGE_COLOR inputWindowLineColor;
extern MESSAGE_COLOR mainWindowLineColor;
extern MESSAGE_COLOR cursorColor;
extern WINDOW_COLOR VKWindowColor;
extern MESSAGE_COLOR VKWindowFontColor;
extern MESSAGE_COLOR VKWindowAlphaColor;
extern ENTER_TO_DO enterToDo;

extern HOTKEYS  hkTrigger[];
extern HOTKEYS  hkGBK[];
extern HOTKEYS  hkCorner[];
extern HOTKEYS  hkPunc[];
extern HOTKEYS  hkPrevPage[];
extern HOTKEYS  hkNextPage[];
extern HOTKEYS  hkWBAddPhrase[];
extern HOTKEYS  hkWBDelPhrase[];
extern HOTKEYS  hkWBAdjustOrder[];
extern HOTKEYS  hkPYAddFreq[];
extern HOTKEYS  hkPYDelFreq[];
extern HOTKEYS  hkPYDelUserPhr[];
extern HOTKEYS  hkLegend[];
extern HOTKEYS  hkTrack[];
extern HOTKEYS  hkGetPY[];
extern HOTKEYS  hkGBT[];
extern HOTKEYS    hkHideMainWindow[];
extern HOTKEYS    hkSaveAll[];
extern HOTKEYS    hkVK[];

extern KEY_CODE switchKey;
extern XIMTriggerKey *Trigger_Keys;
extern INT8     iTriggerKeyCount;

extern Bool     bUseGBK;
extern Bool     bEngPuncAfterNumber;

//extern Bool     bAutoHideInputWindow;
extern XColor   colorArrow;
extern Bool     bTrackCursor;
extern Bool     bCenterInputWindow;
extern HIDE_MAINWINDOW hideMainWindow;
extern Bool     bCompactMainWindow;
extern HIDE_MAINWINDOW hideMainWindow;
extern int      iFontSize;
extern int      iMainWindowFontSize;

extern Bool     bUseGBKT;

extern Bool     bChnPunc;
extern Bool     bCorner;
extern Bool     bUseLegend;

extern Bool     bPYCreateAuto;
extern Bool     bPYSaveAutoAsPhrase;
extern Bool     bPhraseTips;
extern SEMICOLON_TO_DO semicolonToDo;
extern Bool     bEngAfterCap;

//��ʾ�����ٶ�
extern Bool     bShowUserSpeed;
extern Bool     bShowVersion;
extern Bool     bShowVK;

extern char     strNameOfPinyin[];
extern char     strNameOfShuangpin[];;
extern char     strNameOfQuwei[];

extern Bool     bFullPY;
extern Bool     bDisablePagingInLegend;

extern int      i2ndSelectKey;
extern int      i3rdSelectKey;

extern char     strFontName[];
extern char     strFontEnName[];

extern ADJUSTORDER baseOrder;
extern ADJUSTORDER phraseOrder;
extern ADJUSTORDER freqOrder;

extern INT8     iIMIndex;
extern Bool     bLocked;

extern MHPY     MHPY_C[];
extern MHPY     MHPY_S[];

extern Bool     bUsePinyin;
extern Bool     bUseSP;
extern Bool     bUseQW;
extern Bool     bUseTable;

extern char     strDefaultSP[];
extern SP_FROM  iSPFrom;

extern char     cPYYCDZ[];
extern char    strExternIM[];

extern Bool     bDoubleSwitchKey;
extern Bool     bPointAfterNumber;
extern Bool     bConvertPunc;
extern unsigned int iTimeInterval;
extern uint     iFixedInputWindowWidth;
extern Bool     bShowInputWindowTriggering;

#ifdef _USE_XFT
extern Bool     bUseAA;
#endif
extern char     strUserLocale[];

extern Bool     bUseBold;

extern int      iOffsetX;
extern int      iOffsetY;

#ifdef _ENABLE_TRAY
extern Bool    bUseTrayIcon;
#endif

extern char  respath[];
#define inline

Bool MyStrcmp (const char *str1, const char *str2)
{
    return !strncmp (str1, str2, strlen (str2));
}

/* ����������Ҫ֪�����ݸ� LoadConfig �Ĳ��� */
Bool    bIsReloadConfig = True;
/* ������ profile �ļ������д���״̬��Ϣ */
Bool    bIsNeedSaveConfig = True;

/*
 * ������ֵ�����ͣ�
 *
 * ����(integer)���ַ���(string)����ɫ(color) ��������ͨ�ö�д��������д��
 * ��������(other)���ͣ�����Ҫ�ṩר�ŵĶ�д������
 */

#define CONFIG_INTEGER  1
#define CONFIG_STRING   2
#define CONFIG_COLOR    3
#define CONFIG_SWITCHKEY    4
#define CONFIG_HOTKEY   5
#define CONFIG_OTHER    6

/*
 * int(*configure_readwrite)(Configure *c, void *str_file, int isread)
 *
 * ������ȡ����д���Ӧ��������
 *
 * c        -   ��ȡ/д���������
 * str_file - ����Ƕ�ȡ����Ϊ char *�������д�룬��Ϊ FILE *
 * isread   - ����Ƕ�ȡ����Ϊ True������Ϊ False
 *
 * configure_readwrite �������ʾ�ɹ�������ֵΪʧ�ܡ�
 */

typedef struct Configure Configure;
typedef int(*config_readwrite)(Configure *, void *, int);

struct Configure {
    const char *name;         /* configure name */
    const char *comment;      /* configure comment */
    config_readwrite config_rw; /* read/write configure */
    int value_type;     /* type of this configure's value */
    union {
        struct {
            char *string;
            int string_length;
        } str_value;
        int *integer;
        XColor *color;
        HOTKEYS *hotkey;
    } value;
};

typedef struct Configure_group {
    const char *name;     /* configure group's name */
    const char *comment;  /* configure group's comment */
    struct Configure *configure;    /* configures belong to this group */
} Configure_group;

static int generic_config_integer(Configure *c, void *a, int isread)
 {
    if(isread)
        *(c->value.integer) = atoi((const char *)a);
    else
        fprintf((FILE *)a, "%s=%d\n", c->name, *(c->value.integer));

    return 0;
}

static int generic_config_string(Configure *c, void *a, int isread)
{
    if(isread){
        strncpy(c->value.str_value.string, (char *)a, c->value.str_value.string_length);
        c->value.str_value.string[c->value.str_value.string_length - 1] = '\0';
    } else
        fprintf((FILE *)a, "%s=%s\n", c->name, c->value.str_value.string);

    return 0;
}

static int generic_config_color(Configure *c, void *a, int isread)
{
    int r, g, b;

    if(isread){
        if(sscanf((char *)a, "%d %d %d", &r, &g, &b) != 3){
            fprintf(stderr, "error: configure file: color\n");
            exit(1);
        }
        c->value.color->red   = r << 8;
        c->value.color->green = g << 8;
        c->value.color->blue  = b << 8;
    }else
        fprintf((FILE *)a, "%s=%d %d %d\n", c->name,
                c->value.color->red   >> 8,
                c->value.color->green >> 8,
                c->value.color->blue  >> 8);

    return 0;
}

/* FIXME: ʵ��ͨ�ö�д���� switch key ������ */
#if 0
static int generic_config_switchkey(Configure *c, void *a, int isread)
{
    return -1;
}
#endif

/* FIXME: ʵ��ͨ�ö�д���� hot key ������ */
#if 0
static int generic_config_hotkey(Configure *c, void *a, int isread)
{
    return -1;
}
#endif

/** �� configures �е�������Ϣд�� fp */
#if 0
static int write_configures(FILE *fp, Configure *configures)
{
    Configure *tc;

    for(tc = configures; tc->name; tc++){
        if(tc->comment)
            fprintf(fp, "# %s\n", tc->comment);
        if(tc->config_rw)
            tc->config_rw(tc, fp, 0);
        else{
            switch(tc->value_type){
                case CONFIG_INTEGER:
                    generic_config_integer(tc, fp, 0);
                    break;
                case CONFIG_STRING:
                    generic_config_string(tc, fp, 0);
                    break;
                case CONFIG_COLOR:
                    generic_config_color(tc, fp, 0);
                    break;
                default:
                    fprintf(stderr, "error: shouldn't be here\n");
                    exit(1);
            }
        }
     }
    return 0;
}
#endif
/* �� str ��ȡ������Ϣ */
static int read_configure(Configure *config, char *str)
{
    if(config->config_rw)
        config->config_rw(config, str, 1);
    else{
        switch(config->value_type){
            case CONFIG_INTEGER:
                generic_config_integer(config, str, 1);
                break;
            case CONFIG_STRING:
                generic_config_string(config, str, 1);
                break;
            case CONFIG_COLOR:
                generic_config_color(config, str, 1);
                break;
            default:
                fprintf(stderr, "error: shouldn't be here\n");
                exit(1);
        }
    }
    return 0;
}

/* ���������뷨����ɫ */
inline static int main_window_input_method_name_color(Configure *c, void *a, int isread)
{
    int r[3], b[3], g[3], i;
    FILE *fp;

    if(isread){
        if(sscanf((char *)a, "%d %d %d %d %d %d %d %d %d",
                    &r[0], &g[0], &b[0], &r[1], &g[1], &b[1], &r[2], &g[2], &b[2]) != 9)
        {
            fprintf(stderr, "error: invalid configure format\n");
            exit(1);
        }

        for(i = 0; i < 3; i++){
            IMNameColor[i].color.red   = r[i] << 8;
            IMNameColor[i].color.green = g[i] << 8;
            IMNameColor[i].color.blue  = b[i] << 8;
        }
    }else{
        fp = (FILE *)a;
        fprintf(fp, "%s=", c->name);
        for(i = 0; i < 3; i++)
            fprintf(fp, "%d %d %d ",
                    IMNameColor[i].color.red   >> 8,
                    IMNameColor[i].color.green >> 8,
                    IMNameColor[i].color.blue  >> 8);
        fprintf(fp, "\n");
    }

    return 0;
}

/* ��/�ر����뷨 */
inline static int trigger_input_method(Configure *c, void *a, int isread)
{
    if(isread){
        if(bIsReloadConfig){
            SetTriggerKeys((char *)a);
            SetHotKey((char *)a, hkTrigger);
        }
    }else
        fprintf((FILE *)a, "%s=%s\n", c->name, "CTRL_SPACE");

    return 0;
}

/* ��Ӣ�Ŀ����л��� */
inline static int fast_chinese_english_switch(Configure *c, void *a, int isread)
{
    if(isread)
        SetSwitchKey((char *)a);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "L_SHIFT");

    return 0;
}

/* ������ */
inline static int cursor_follow(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkTrack);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "CTRL_K");
    return 0;
}

/* ���������� */
inline static int hide_main_window(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkHideMainWindow);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "CTRL_ALT_H");
    return 0;
}

/* �л�������� */
inline static int switch_vk(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkVK);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "CTRL_ALT_K");

    return 0;
}

/* GBK֧�� */
inline static int gbk_support(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkGBK);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "CTRL_M");

    return 0;
}

/* GBK�����л��� */
inline static int gbk_traditional_simplified_switch(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkGBT);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "CTRL_ALT_F");

    return 0;
}

/* ���� */
inline static int association(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkLegend);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "CTRL_L");

    return 0;
}

/* ����ƴ�� */
inline static int lookup_pinyin(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkGetPY);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "CTRL_ALT_E");

    return 0;
}

/*
 * DBC case = Double Byte Character case
 * SBC case = Single Byte Character case
 */

/* ȫ��� */
inline static int sbc_dbc_switch(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkCorner);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "SHIFT_SPACE");

    return 0;
}

/* ���ı�� */
inline static int chinese_punctuation(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkPunc);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "ALT_SPACE");

    return 0;
}

/* ��һҳ */
inline static int prev_page(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkPrevPage);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "-");

    return 0;
}

/* ��һҳ */
inline static int next_page(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkNextPage);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "=");

    return 0;
}

/* �ڶ�����ѡ��ѡ��� */
inline static int second_third_candidate_word(Configure *c, void *a, int isread)
{
//    char *pstr = (char *)a;
#if 0 //szj
    if(isread){
        if (!strcasecmp (pstr, "SHIFT")) {
            i2ndSelectKey = 50;        //��SHIFT��ɨ����
            i3rdSelectKey = 62;        //��SHIFT��ɨ����
        }
        else if (!strcasecmp (pstr, "CTRL")) {
            i2ndSelectKey = 37;        //��CTRL��ɨ����
            i3rdSelectKey = 109;       //��CTRL��ɨ����
        }
        else {
            i2ndSelectKey = pstr[0] ^ 0xFF;
            i3rdSelectKey = pstr[1] ^ 0xFF;
        }
    }else
        fprintf((FILE *)a, "%s=%s\n", c->name, "0");
#endif
    return 0;
}

/* ����ʿ� */
inline static int save_all(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkSaveAll);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "CTRL_ALT_S");

    return 0;
}

/* Ĭ��˫ƴ���� */
inline static int default_shuangpin_scheme(Configure *c, void *a, int isread)
{
    if(isread){
        strncpy(strDefaultSP, (char *)a, 100);  /* FIXME: ��Ӧ�ڴ�Ӳ�����ַ������ȣ���ͬ */
        iSPFrom = SP_FROM_SYSTEM_CONFIG;
    }
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, strDefaultSP);

    return 0;
}

/* ����ƴ�������� */
inline static int add_pinyin_frequently_used_word(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkPYAddFreq);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "CTRL_8");

    return 0;
}

/* ɾ��ƴ���û����� */
inline static int delete_pinyin_user_create_phrase(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkPYDelUserPhr);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "CTRL_DELETE");

    return 0;
}

/* ɾ��ƴ�������� */
inline static int delete_pinyin_frequently_used_word(Configure *c, void *a, int isread)
{
    if(isread)
        SetHotKey((char *)a, hkPYDelFreq);
    else
        fprintf((FILE *)a, "%s=%s\n", c->name, "CTRL_7");

    return 0;
}

/* ƴ���Դʶ��ּ� */
inline static int pinyin_get_word_from_phrase(Configure *c, void *a, int isread)
{
    char *pstr = (char *)a;
    if(isread){
        cPYYCDZ[0] = pstr[0];
        cPYYCDZ[1] = pstr[1];
    }else
        fprintf((FILE *)a, "%s=%c%c\n", c->name, cPYYCDZ[0], cPYYCDZ[1]);

    return 0;
}

/* ģ��an��ang */
inline static int blur_an_ang(Configure *c, void *a, int isread)
{
    if(isread){
        MHPY_C[0].bMode = MHPY_S[5].bMode = atoi((const char *)a);
    }else
        fprintf((FILE *)a, "%s=%d\n", c->name, MHPY_C[0].bMode);

    return 0;
}
#if 1//szj

Configure program_config[100];
Configure output_config[100];

Configure interface_config[100];
Configure hotkey_config[100];
Configure input_method_config[100] ;
Configure pinyin_config[100];

Configure profiles[100];

int  initConfig()
{
    program_config[0].name            = "��ʾ����(��)";
    program_config[0].value_type    = CONFIG_STRING;
    program_config[0].value.str_value.string            = strFontName;
    program_config[0].value.str_value.string_length    = 100;

    program_config[1].name            = "��ʾ����(Ӣ)";
    program_config[1].value_type    = CONFIG_STRING;
    program_config[1].value.str_value.string            = strFontName;
    program_config[1].value.str_value.string_length    = 100;

    program_config[2].name            = "��ʾ�����С";
    program_config[2].value_type    = CONFIG_STRING;
    program_config[2].value.integer            = &iFontSize;


    program_config[3].name            = "�����������С";
    program_config[3].value_type    = CONFIG_STRING;
    program_config[3].value.integer            = &iMainWindowFontSize;

    program_config[4].name            = "��������";
    program_config[4].value_type    = CONFIG_STRING;
    program_config[4].value.str_value.string            = strUserLocale;
    program_config[4].value.str_value.string_length    = 50;

//#ifdef _USE_XFT
//    program_config[5].name            = "ʹ��AA����";
//    program_config[5].value_type    = CONFIG_INTEGER;
//    program_config[5].value.integer            =  &bUseAA;

    program_config[5].name            = "ʹ�ô���";
    program_config[5].value_type    = CONFIG_INTEGER;
    program_config[5].value.integer            =  &bUseBold;

    program_config[6].name = NULL;

// #ifdef _ENABLE_TRAY

//    program_config[7].name            = "ʹ������ͼ��";
//    program_config[7].value_type    = CONFIG_INTEGER;
//    program_config[7].value.integer            =  &bUseTrayIcon;


    output_config[0].name = "���ֺ����Ƿ���";
    output_config[0].value_type = CONFIG_INTEGER;
    output_config[0].value.integer = &bEngPuncAfterNumber;

    output_config[1].name = "Enter����Ϊ";
    output_config[1].value_type = CONFIG_INTEGER;
    output_config[1].value.integer = (int*)&enterToDo; /* FIXME: ����ת����ʽҲ�����Ǹ������⣬��ͬ */

    output_config[2].name = "�ֺż���Ϊ";
    output_config[2].value_type = CONFIG_INTEGER;
    output_config[2].value.integer = (int*)&semicolonToDo;

    output_config[3].name = "��д��ĸ����Ӣ��";
    output_config[3].value_type = CONFIG_INTEGER;
    output_config[3].value.integer = (int*)&bEngAfterCap;

    output_config[4].name = "ת��Ӣ���еı��";
    output_config[4].value_type = CONFIG_INTEGER;
    output_config[4].value.integer = (int*)&bConvertPunc;

    output_config[5].name = "���뷽ʽ��ֹ��ҳ";
    output_config[5].value_type = CONFIG_INTEGER;
    output_config[5].value.integer =(int*)&bDisablePagingInLegend;
    output_config[6].name = NULL;



    interface_config[0].name = "��ѡ�ʸ���";
    interface_config[0].value_type = CONFIG_INTEGER;
    interface_config[0].value.integer = &iMaxCandWord;

    interface_config[1].name = "������ʹ��3D����";
    interface_config[1].value_type = CONFIG_INTEGER;
    interface_config[1].value.integer = &_3DEffectMainWindow;

    interface_config[2].name = "������ʹ��3D����";
    interface_config[2].value_type = CONFIG_INTEGER;
    interface_config[2].value.integer = (int *)&_3DEffectInputWindow;

    interface_config[3].name = "����������ģʽ";
    interface_config[3].value_type = CONFIG_INTEGER;
    interface_config[3].value.integer = (int *)&hideMainWindow;

    interface_config[4].name = "��ʾ�������";
    interface_config[4].value_type = CONFIG_INTEGER;
    interface_config[4].value.integer = &bShowVK;

    interface_config[5].name = "����������";
    interface_config[5].value_type = CONFIG_INTEGER;
    interface_config[5].value.integer = &bCenterInputWindow;

    interface_config[6].name = "�״���ʾ������";
    interface_config[6].value_type = CONFIG_INTEGER;
    interface_config[6].value.integer = &bShowInputWindowTriggering;

    interface_config[7].name = "�������̶����";
    interface_config[7].comment = "�������̶����(��������������뷨)��0��ʾ���̶����";
    interface_config[7].value_type = CONFIG_INTEGER;
    interface_config[7].value.integer = (int *)&iFixedInputWindowWidth;

    interface_config[8].name = "������ƫ����x";
    interface_config[8].value_type = CONFIG_INTEGER;
    interface_config[8].value.integer = &iOffsetX;

    interface_config[9].name = "������ƫ����y";
    interface_config[9].value_type = CONFIG_INTEGER;
    interface_config[9].value.integer = &iOffsetY;

    interface_config[10].name = "��ź�ӵ�";
    interface_config[10].value_type = CONFIG_INTEGER;
    interface_config[10].value.integer = &bPointAfterNumber;

    interface_config[11].name = "��ʾ�����ٶ�";
    interface_config[11].value_type = CONFIG_INTEGER;
    interface_config[11].value.integer = &bShowUserSpeed;

    interface_config[12].name = "��ʾ�汾";
    interface_config[12].value_type = CONFIG_INTEGER;
    interface_config[12].value.integer = &bShowVersion;

    interface_config[13].name = "���ɫ";
    interface_config[13].value_type = CONFIG_COLOR;
    interface_config[13].value.color = &(cursorColor.color);

    interface_config[14].name = "�����ڱ���ɫ";
    interface_config[14].value_type = CONFIG_COLOR;
    interface_config[14].value.color = &(mainWindowColor.backColor);

    interface_config[15].name = "����������ɫ";
    interface_config[15].value_type = CONFIG_COLOR;
    interface_config[15].value.color = &(mainWindowLineColor.color);

    interface_config[16].name = "���������뷨����ɫ";
    interface_config[16].value_type = CONFIG_OTHER;
    interface_config[16].config_rw = main_window_input_method_name_color;

    interface_config[17].name = "���봰����ɫ";
    interface_config[17].value_type = CONFIG_COLOR;
    interface_config[17].value.color = &(inputWindowColor.backColor);

    interface_config[18].name = "���봰��ʾɫ";
    interface_config[18].value_type = CONFIG_COLOR;
    interface_config[18].value.color = &(messageColor[0].color);

    interface_config[19].name = "���봰�û�����ɫ";
    interface_config[19].value_type = CONFIG_COLOR;
    interface_config[19].value.color = &(messageColor[1].color);

    interface_config[20].name = "���봰���ɫ";
    interface_config[20].value_type = CONFIG_COLOR;
    interface_config[20].value.color = &(messageColor[2].color);

    interface_config[21].name = "���봰��һ����ѡ��ɫ";
    interface_config[21].value_type = CONFIG_COLOR;
    interface_config[21].value.color = &(messageColor[3].color);

    interface_config[22].name = "���봰�û�����ɫ";
    interface_config[22].comment = "����ɫֵֻ����ƴ���е��û������";
    interface_config[22].value_type = CONFIG_COLOR;
    interface_config[22].value.color = &(messageColor[4].color);

    interface_config[23].name = "���봰��ʾ����ɫ";
    interface_config[23].value_type = CONFIG_COLOR;
    interface_config[23].value.color = &(messageColor[5].color);

    interface_config[24].name = "���봰�����ı�ɫ";
    interface_config[24].comment = "��ʡ�ƴ���ĵ���/ϵͳ�����ʹ�ø���ɫ";
    interface_config[24].value_type = CONFIG_COLOR;
    interface_config[24].value.color = &(messageColor[6].color);

    interface_config[25].name = "���봰����ɫ";
    interface_config[25].value_type = CONFIG_COLOR;
    interface_config[25].value.color = &(inputWindowLineColor.color);

    interface_config[26].name = "���봰��ͷɫ";
    interface_config[26].value_type = CONFIG_COLOR;
    interface_config[26].value.color = &(colorArrow);

    interface_config[27].name = "������̴�����ɫ";
    interface_config[27].value_type = CONFIG_COLOR;
    interface_config[27].value.color = &(VKWindowColor.backColor);

    interface_config[28].name = "������̴���ĸɫ";
    interface_config[28].value_type = CONFIG_COLOR;
    interface_config[28].value.color = &(VKWindowAlphaColor.color);

    interface_config[29].name = "������̴�����ɫ";
    interface_config[29].value_type = CONFIG_COLOR;
    interface_config[29].value.color = &(VKWindowFontColor.color);

    interface_config[30].name = NULL;

    hotkey_config[0].name = "��/�ر����뷨";
    hotkey_config[0].value_type = CONFIG_OTHER;
    hotkey_config[0].config_rw = trigger_input_method;

    hotkey_config[1].name = "��Ӣ�Ŀ����л���";
    hotkey_config[1].comment ="��Ӣ�Ŀ����л��� ��������ΪL_CTRL R_CTRL L_SHIFT R_SHIFT L_SUPER R_SUPER";
    hotkey_config[1].value_type = CONFIG_OTHER; /* FIXME: Ӧ��Ϊ CONFIG_SWITCHKEY */
    hotkey_config[1].config_rw = fast_chinese_english_switch;

    hotkey_config[2].name = "˫����Ӣ���л�";
    hotkey_config[2].value_type = CONFIG_INTEGER;
    hotkey_config[2].value.integer = &bDoubleSwitchKey;

    hotkey_config[3].name = "����ʱ����";
    hotkey_config[3].value_type = CONFIG_INTEGER;
    hotkey_config[3].value.integer = (int *)&iTimeInterval;

    hotkey_config[4].name = "������";
    hotkey_config[4].value_type = CONFIG_HOTKEY;
    hotkey_config[4].config_rw = cursor_follow;

    hotkey_config[5].name = "����������";
    hotkey_config[5].value_type = CONFIG_HOTKEY;
    hotkey_config[5].config_rw = hide_main_window;

    hotkey_config[6].name = "�л��������";
    hotkey_config[6].value_type = CONFIG_HOTKEY;
    hotkey_config[6].config_rw = switch_vk;

    hotkey_config[7].name = "GBK֧��";
    hotkey_config[7].value_type = CONFIG_HOTKEY;
    hotkey_config[7].config_rw = gbk_support;

    hotkey_config[8].name = "GBK�����л���";
    hotkey_config[8].value_type = CONFIG_HOTKEY;
    hotkey_config[8].config_rw = gbk_traditional_simplified_switch;

    hotkey_config[9].name = "����";
    hotkey_config[9].value_type = CONFIG_HOTKEY;
    hotkey_config[9].config_rw = association;

    hotkey_config[10].name = "����ƴ��";
    hotkey_config[10].value_type = CONFIG_HOTKEY;
    hotkey_config[10].config_rw = lookup_pinyin;

    hotkey_config[11].name = "ȫ���";
    hotkey_config[11].value_type = CONFIG_HOTKEY;
    hotkey_config[11].config_rw = sbc_dbc_switch;

    hotkey_config[12].name = "���ı��";
    hotkey_config[12].value_type = CONFIG_HOTKEY;
    hotkey_config[12].config_rw = chinese_punctuation;

    hotkey_config[13].name = "��һҳ";
    hotkey_config[13].value_type = CONFIG_HOTKEY;
    hotkey_config[13].config_rw = prev_page;

    hotkey_config[14].name = "��һҳ";
    hotkey_config[14].value_type = CONFIG_HOTKEY;
    hotkey_config[14].config_rw = next_page;

    hotkey_config[15].name = "�ڶ�����ѡ��ѡ���";
    hotkey_config[15].value_type = CONFIG_HOTKEY;
    hotkey_config[15].config_rw = second_third_candidate_word;


    hotkey_config[16].name = NULL;

    hotkey_config[17].name = "����ʿ�";
    hotkey_config[17].value_type = CONFIG_HOTKEY;
    hotkey_config[17].config_rw = save_all;

    hotkey_config[18].name = NULL;

    input_method_config[0].name = "ʹ��ƴ��";
    input_method_config[0].value_type = CONFIG_INTEGER;
    input_method_config[0].value.integer = &bUsePinyin;

    input_method_config[1].name = "ƴ������";
    input_method_config[1].value_type = CONFIG_STRING;
    input_method_config[1].value.str_value.string = strNameOfPinyin,
    input_method_config[1].value.str_value.string_length = 41;   /* FIXME: ��Ӧ�ڴ�Ӳ�����ַ������ȣ���ͬ */

    input_method_config[2].name = "ʹ��˫ƴ";
    input_method_config[2].value_type = CONFIG_INTEGER;
    input_method_config[2].value.integer = &bUseSP;

    input_method_config[3].name = "˫ƴ����";
    input_method_config[3].value_type = CONFIG_STRING;
    input_method_config[3].value.str_value.string = strNameOfShuangpin;
    input_method_config[3].value.str_value.string_length = 41;

    input_method_config[4].name = "Ĭ��˫ƴ����";
    input_method_config[4].value_type = CONFIG_OTHER;
    input_method_config[4].config_rw = &default_shuangpin_scheme;

    input_method_config[5].name = "ʹ����λ";
    input_method_config[5].value_type = CONFIG_INTEGER;
    input_method_config[5].value.integer = &bUseQW;

    input_method_config[6].name = "��λ����";
    input_method_config[6].value_type = CONFIG_STRING;
    input_method_config[6].value.str_value.string = strNameOfQuwei;
    input_method_config[6].value.str_value.string_length = 41;

    input_method_config[7].name = "ʹ�����";
    input_method_config[7].value_type = CONFIG_INTEGER;
    input_method_config[7].value.integer = &bUseTable;

    input_method_config[8].name = "��ʾ�ʿ��еĴ���";
    input_method_config[8].value_type = CONFIG_INTEGER;
    input_method_config[8].value.integer = &bPhraseTips;

    input_method_config[9].name = "�������뷨";
    input_method_config[9].value_type = CONFIG_STRING;
    input_method_config[9].value.str_value.string = strExternIM;
    input_method_config[9].value.str_value.string_length = PY_PATH_MAX;

    input_method_config[10].name = NULL;


    pinyin_config[0].name = "ʹ��ȫƴ";
    pinyin_config[0].value_type = CONFIG_INTEGER;
    pinyin_config[0].value.integer = &bFullPY;

    pinyin_config[1].name = "ƴ���Զ����";
    pinyin_config[1].value_type = CONFIG_INTEGER;
    pinyin_config[1].value.integer = &bPYCreateAuto;

    pinyin_config[2].name = "�����Զ����";
    pinyin_config[2].value_type = CONFIG_INTEGER;
    pinyin_config[2].value.integer = &bPYSaveAutoAsPhrase;

    pinyin_config[3].name = "����ƴ��������";
    pinyin_config[3].value_type = CONFIG_HOTKEY;
    pinyin_config[3].config_rw = &add_pinyin_frequently_used_word;

    pinyin_config[4].name = "ɾ��ƴ��������";
    pinyin_config[4].value_type = CONFIG_HOTKEY;
    pinyin_config[4].config_rw = &delete_pinyin_frequently_used_word;

    pinyin_config[5].name = "ɾ��ƴ���û�����";
    pinyin_config[5].value_type = CONFIG_HOTKEY;
    pinyin_config[5].config_rw = &delete_pinyin_user_create_phrase;

    pinyin_config[6].name = "ƴ���Դʶ��ּ�";
    pinyin_config[6].comment = "ƴ���Դʶ��ּ����Ⱥź�����Ӽ�����Ҫ�пո�";
    pinyin_config[6].value_type = CONFIG_OTHER;
    pinyin_config[6].config_rw = &pinyin_get_word_from_phrase;

    pinyin_config[7].name = "ƴ���������������ʽ";
    pinyin_config[7].comment = "���������ʽ˵����0-->������  1-->���ٵ���  2-->��Ƶ�ʵ���";
    pinyin_config[7].value_type = CONFIG_INTEGER;
    pinyin_config[7].value.integer = (int *)&baseOrder;

    pinyin_config[8].name = "ƴ���������������ʽ";
    pinyin_config[8].value_type = CONFIG_INTEGER;
    pinyin_config[8].value.integer = (int *)&phraseOrder;

    pinyin_config[9].name = "ƴ�����ô����������ʽ";
    pinyin_config[9].value_type = CONFIG_INTEGER;
    pinyin_config[9].value.integer = (int *)&freqOrder;

    pinyin_config[10].name = "ģ��an��ang";
    pinyin_config[10].value_type = CONFIG_OTHER;
    pinyin_config[10].config_rw = blur_an_ang;

    pinyin_config[11].name = "ģ��en��eng";
    pinyin_config[11].value_type = CONFIG_INTEGER;
    pinyin_config[11].value.integer = &(MHPY_C[1].bMode);

    pinyin_config[12].name = "ģ��ian��iang";
    pinyin_config[12].value_type = CONFIG_INTEGER;
    pinyin_config[12].value.integer = &(MHPY_C[2].bMode);

    pinyin_config[13].name = "ģ��in��ing";
    pinyin_config[13].value_type = CONFIG_INTEGER;
    pinyin_config[13].value.integer = &(MHPY_C[3].bMode);

    pinyin_config[14].name = "ģ��ou��u";
    pinyin_config[14].value_type = CONFIG_INTEGER;
    pinyin_config[14].value.integer = &(MHPY_C[4].bMode);

    pinyin_config[15].name = "ģ��uan��uang";
    pinyin_config[15].value_type = CONFIG_INTEGER;
    pinyin_config[15].value.integer = &(MHPY_C[5].bMode);

    pinyin_config[16].name = "ģ��c��ch";
    pinyin_config[16].value_type = CONFIG_INTEGER;
    pinyin_config[16].value.integer = &(MHPY_S[0].bMode);

    pinyin_config[17].name = "ģ��f��h";
    pinyin_config[17].value_type = CONFIG_INTEGER;
    pinyin_config[17].value.integer = &(MHPY_S[1].bMode);

    pinyin_config[18].name = "ģ��l��n";
    pinyin_config[18].value_type = CONFIG_INTEGER;
    pinyin_config[18].value.integer = &(MHPY_S[2].bMode);

    pinyin_config[19].name = "ģ��s��sh";
    pinyin_config[19].value_type = CONFIG_INTEGER;
    pinyin_config[19].value.integer = &(MHPY_S[3].bMode);

    pinyin_config[20].name = "ģ��z��zh";
    pinyin_config[20].value_type = CONFIG_INTEGER;
    pinyin_config[20].value.integer = &(MHPY_S[4].bMode);

    pinyin_config[21].name = NULL;




    return 0;

}


Configure_group configure_groups[] = {
    {
        "����",
        NULL,
        program_config,
    },
    {
        "���",
        NULL,
        output_config,
    },
    {
        "����",
        NULL,
        interface_config,
    },
    {
        "�ȼ�",
        "���ˡ���Ӣ�Ŀ����л������⣬�������ȼ���������Ϊ�������м��ÿո�ָ�",
        hotkey_config,
    },
    {
        "���뷨",
         NULL,
         input_method_config,
    },
    {
        "ƴ��",
        NULL,
        pinyin_config,
    },
    {
        NULL,
    },
};


#else
Configure program_config[] = {
    {
        .name = "��ʾ����(��)",
        .value_type = CONFIG_STRING,
        .value.str_value.string = strFontName,
        .value.str_value.string_length = 100,   /* FIXME: ��Ӧ�ڴ�Ӳ�����ַ����ĳ��ȣ���ͬ */
    },
    {
        .name = "��ʾ����(Ӣ)",
        .value_type = CONFIG_STRING,
        .value.str_value.string = strFontEnName,
        .value.str_value.string_length = 100,
    },
    {
        .name = "��ʾ�����С",
        .value_type = CONFIG_INTEGER,
        .value.integer = &iFontSize,
    },
    {
        .name = "�����������С",
        .value_type = CONFIG_INTEGER,
        .value.integer = &iMainWindowFontSize,
    },
    {
        .name = "��������",
        .value_type = CONFIG_STRING,
        .value.str_value.string = strUserLocale,
        .value.str_value.string_length = 50,
    },
 #ifdef _USE_XFT
    {
        .name = "ʹ��AA����",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bUseAA,
    },
 #endif
    {
        .name = "ʹ�ô���",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bUseBold,
    },
 #ifdef _ENABLE_TRAY
    {
        .name = "ʹ������ͼ��",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bUseTrayIcon,
    },
 #endif
    {
        .name = NULL,
    },

};

/* piaoairy: gcc Ĭ��enum ����ʹ��int */
Configure output_config[] = {
    {
        .name = "���ֺ����Ƿ���",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bEngPuncAfterNumber,
    },
    {
        .name = "Enter����Ϊ",
        .value_type = CONFIG_INTEGER,
        .value.integer = (int *)&enterToDo, /* FIXME: ����ת����ʽҲ�����Ǹ������⣬��ͬ */
    },
    {
        .name = "�ֺż���Ϊ",
        .value_type = CONFIG_INTEGER,
        .value.integer = (int *)&semicolonToDo,
    },
    {
        .name = "��д��ĸ����Ӣ��",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bEngAfterCap,
    },
    {
        .name = "ת��Ӣ���еı��",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bConvertPunc,
    },
    {
        .name = "���뷽ʽ��ֹ��ҳ",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bDisablePagingInLegend,
    },
    {
        .name = NULL,
    },
};

Configure interface_config[] = {
    {
        .name = "��ѡ�ʸ���",
        .value_type = CONFIG_INTEGER,
        .value.integer = &iMaxCandWord,
    },
    {
        .name = "������ʹ��3D����",
        .value_type = CONFIG_INTEGER,
        .value.integer = &_3DEffectMainWindow,
    },
    {
        .name = "������ʹ��3D����",
        .value_type = CONFIG_INTEGER,
        .value.integer = (int *)&_3DEffectInputWindow,
    },
    {
        .name = "����������ģʽ",
        .value_type = CONFIG_INTEGER,
        .value.integer = (int *)&hideMainWindow,
    },
    {
        .name = "��ʾ�������",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bShowVK,
    },
    {
        .name = "����������",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bCenterInputWindow,
    },
    {
        .name = "�״���ʾ������",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bShowInputWindowTriggering,
    },
    {
        .name = "�������̶����",
        .comment = "�������̶����(��������������뷨)��0��ʾ���̶����",
        .value_type = CONFIG_INTEGER,
        .value.integer = &iFixedInputWindowWidth,
    },
    {
        .name = "������ƫ����X",
        .value_type = CONFIG_INTEGER,
        .value.integer = &iOffsetX,
    },
    {
        .name = "������ƫ����Y",
        .value_type = CONFIG_INTEGER,
        .value.integer = &iOffsetY,
    },
    {
        .name = "��ź�ӵ�",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bPointAfterNumber,
    },
    {
        .name = "��ʾ�����ٶ�",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bShowUserSpeed,
    },
    {
        .name = "��ʾ�汾",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bShowVersion,
    },
    {
        .name = "���ɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(cursorColor.color),
    },
    {
        .name = "�����ڱ���ɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(mainWindowColor.backColor),
    },
    {
        .name = "����������ɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(mainWindowLineColor.color),
    },
    {
        .name = "���������뷨����ɫ",
        .value_type = CONFIG_OTHER,
        .config_rw = main_window_input_method_name_color,
    },
    {
        .name = "���봰����ɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(inputWindowColor.backColor),
    },
    {
        .name = "���봰��ʾɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(messageColor[0].color),
    },
    {
        .name = "���봰�û�����ɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(messageColor[1].color),
    },
    {
        .name = "���봰���ɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(messageColor[2].color),
    },
    {
        .name = "���봰��һ����ѡ��ɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(messageColor[3].color),
    },
    {
        .name = "���봰�û�����ɫ",
        .comment = "����ɫֵֻ����ƴ���е��û������",
        .value_type = CONFIG_COLOR,
        .value.color = &(messageColor[4].color),
    },
    {
        .name = "���봰��ʾ����ɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(messageColor[5].color),
    },
    {
        .name = "���봰�����ı�ɫ",
        .comment = "��ʡ�ƴ���ĵ���/ϵͳ�����ʹ�ø���ɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(messageColor[6].color),
    },
    {
        .name = "���봰����ɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(inputWindowLineColor.color),
    },
    {
        .name = "���봰��ͷɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(colorArrow),
    },
    {
        .name = "������̴�����ɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(VKWindowColor.backColor),
    },
    {
        .name = "������̴���ĸɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(VKWindowAlphaColor.color),
    },
    {
        .name = "������̴�����ɫ",
        .value_type = CONFIG_COLOR,
        .value.color = &(VKWindowFontColor.color),
    },
    {
        .name = NULL,
    },
};

Configure hotkey_config[] = {
    {
        .name = "��/�ر����뷨",
        .value_type = CONFIG_OTHER,
        .config_rw = trigger_input_method,
    },
    {
        .name = "��Ӣ�Ŀ����л���",
        .comment = "��Ӣ�Ŀ����л��� ��������ΪL_CTRL R_CTRL L_SHIFT R_SHIFT L_SUPER R_SUPER",
        .value_type = CONFIG_OTHER, /* FIXME: Ӧ��Ϊ CONFIG_SWITCHKEY */
        .config_rw = fast_chinese_english_switch,
    },
    {
        .name = "˫����Ӣ���л�",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bDoubleSwitchKey,
    },
    {
        .name = "����ʱ����",
        .value_type = CONFIG_INTEGER,
        .value.integer = (int *)&iTimeInterval,
    },
    {
        .name = "������",
        .value_type = CONFIG_HOTKEY,
        .config_rw = cursor_follow,
    },
    {
        .name = "����������",
        .value_type = CONFIG_HOTKEY,
        .config_rw = hide_main_window,
    },
    {
        .name = "�л��������",
        .value_type = CONFIG_HOTKEY,
        .config_rw = switch_vk,
    },
    {
        .name = "GBK֧��",
        .value_type = CONFIG_HOTKEY,
        .config_rw = gbk_support,
    },
    {
        .name = "GBK�����л���",
        .value_type = CONFIG_HOTKEY,
        .config_rw = gbk_traditional_simplified_switch,
    },
    {
        .name = "����",
        .value_type = CONFIG_HOTKEY,
        .config_rw = association,
    },
    {
        .name = "����ƴ��",
        .value_type = CONFIG_HOTKEY,
        .config_rw = lookup_pinyin,
    },
    {
        .name = "ȫ���",
        .value_type = CONFIG_HOTKEY,
        .config_rw = sbc_dbc_switch,
    },
    {
        .name = "���ı��",
        .value_type = CONFIG_HOTKEY,
        .config_rw = chinese_punctuation,
    },
    {
        .name = "��һҳ",
        .value_type = CONFIG_HOTKEY,
        .config_rw = prev_page,
    },
    {
        .name = "��һҳ",
        .value_type = CONFIG_HOTKEY,
        .config_rw = next_page,
    },
    {
        .name = "�ڶ�����ѡ��ѡ���",
        .value_type = CONFIG_HOTKEY,
        .config_rw = second_third_candidate_word,
    },
    {
        .name = NULL,
    },
    {
        .name = "����ʿ�",
        .value_type = CONFIG_HOTKEY,
        .config_rw = save_all,
    },
    {
        .name = NULL,
    },
};

Configure input_method_config[] = {
    {
        .name = "ʹ��ƴ��",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bUsePinyin,
    },
    {
        .name = "ƴ������",
        .value_type = CONFIG_STRING,
        .value.str_value.string = strNameOfPinyin,
        .value.str_value.string_length = 41,    /* FIXME: ��Ӧ�ڴ�Ӳ�����ַ������ȣ���ͬ */
    },
    {
        .name = "ʹ��˫ƴ",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bUseSP,
    },
    {
        .name = "˫ƴ����",
        .value_type = CONFIG_STRING,
        .value.str_value.string = strNameOfShuangpin,
        .value.str_value.string_length = 41,
    },
    {
        .name = "Ĭ��˫ƴ����",
        .value_type = CONFIG_OTHER,
        .config_rw = default_shuangpin_scheme,
    },
    {
        .name = "ʹ����λ",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bUseQW,
    },
    {
        .name = "��λ����",
        .value_type = CONFIG_STRING,
        .value.str_value.string = strNameOfQuwei,
        .value.str_value.string_length = 41,
    },
    {
        .name = "ʹ�����",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bUseTable,
    },
    {
        .name = "��ʾ�ʿ��еĴ���",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bPhraseTips,
    },
    {
        .name = "�������뷨",
        .value_type = CONFIG_STRING,
        .value.str_value.string = strExternIM,
        .value.str_value.string_length = PY_PATH_MAX,
    },
    {
        .name = NULL,
    },
};

Configure pinyin_config[] = {
    {
        .name = "ʹ��ȫƴ",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bFullPY,
    },
    {
        .name = "ƴ���Զ����",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bPYCreateAuto,
    },
    {
        .name = "�����Զ����",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bPYSaveAutoAsPhrase,
    },
    {
       .name = "����ƴ��������",
        .value_type = CONFIG_HOTKEY,
        .config_rw = add_pinyin_frequently_used_word,
    },
    {
        .name = "ɾ��ƴ��������",
        .value_type = CONFIG_HOTKEY,
        .config_rw = delete_pinyin_frequently_used_word,
    },
    {
        .name = "ɾ��ƴ���û�����",
        .value_type = CONFIG_HOTKEY,
        .config_rw = delete_pinyin_user_create_phrase,
    },
    {
        .name = "ƴ���Դʶ��ּ�",
        .comment = "ƴ���Դʶ��ּ����Ⱥź�����Ӽ�����Ҫ�пո�",
        .value_type = CONFIG_OTHER,
        .config_rw = pinyin_get_word_from_phrase,
    },
    {
        .name = "ƴ���������������ʽ",
        .comment = "���������ʽ˵����0-->������  1-->���ٵ���  2-->��Ƶ�ʵ���",
        .value_type = CONFIG_INTEGER,
        .value.integer = (int *)&baseOrder,
    },
    {
        .name = "ƴ���������������ʽ",
        .value_type = CONFIG_INTEGER,
        .value.integer = (int *)&phraseOrder,
    },
    {
        .name = "ƴ�����ô����������ʽ",
        .value_type = CONFIG_INTEGER,
        .value.integer = (int *)&freqOrder,
    },
    {
        .name = "ģ��an��ang",
        .value_type = CONFIG_OTHER,
        .config_rw = blur_an_ang,
    },
    {
        .name = "ģ��en��eng",
        .value_type = CONFIG_INTEGER,
        .value.integer = &(MHPY_C[1].bMode),
    },
    {
        .name = "ģ��ian��iang",
        .value_type = CONFIG_INTEGER,
        .value.integer = &(MHPY_C[2].bMode),
    },
    {
        .name = "ģ��in��ing",
        .value_type = CONFIG_INTEGER,
        .value.integer = &(MHPY_C[3].bMode),
    },
    {
        .name = "ģ��ou��u",
        .value_type = CONFIG_INTEGER,
        .value.integer = &(MHPY_C[4].bMode),
    },
    {
        .name = "ģ��uan��uang",
        .value_type = CONFIG_INTEGER,
        .value.integer = &(MHPY_C[5].bMode),
    },
    {
        .name = "ģ��c��ch",
        .value_type = CONFIG_INTEGER,
        .value.integer = &(MHPY_S[0].bMode),
    },
    {
        .name = "ģ��f��h",
        .value_type = CONFIG_INTEGER,
        .value.integer = &(MHPY_S[1].bMode),
    },
    {
        .name = "ģ��l��n",
        .value_type = CONFIG_INTEGER,
        .value.integer = &(MHPY_S[2].bMode),
    },
    {
        .name = "ģ��s��sh",
        .value_type = CONFIG_INTEGER,
        .value.integer = &(MHPY_S[3].bMode),
    },
    {
        .name = "ģ��z��zh",
        .value_type = CONFIG_INTEGER,
        .value.integer = &(MHPY_S[4].bMode),
    },
    {
        .name = NULL,
    },
};

Configure_group configure_groups[] = {
    {
        .name = "����",
        .configure = program_config,
    },
    {
        .name = "���",
        .configure = output_config,
    },
    {
        .name = "����",
        .configure = interface_config,
    },
    {
        .name = "�ȼ�",
        .comment = "���ˡ���Ӣ�Ŀ����л������⣬�������ȼ���������Ϊ�������м��ÿո�ָ�",
        .configure = hotkey_config,
    },
    {
        .name = "���뷨",
        .configure = input_method_config,
    },
    {
        .name = "ƴ��",
        .configure = pinyin_config,
    },
    {
        .name = NULL,
    },
};

#endif

/**
 * @brief ��ȡ�û��������ļ�
 * @param bMode ��ʶ�����ļ����û���Ŀ¼�µģ����ǴӰ�װĿ¼�¿���������
 * @return void
 */
void LoadConfig (Bool bMode)
{
    FILE    *fp;
    char    buf[PY_PATH_MAX], *pbuf, *pbuf1;
    Bool    bFromUser = True;
    //���ڱ�ʾgroup��index���������ļ����������Ƿ���ģ�������ini�ļ��ķ���
    int     group_idx;
    int        i;
    Configure   *tmpconfig;

    //���Ա�ʶ�����ļ����û���Ŀ¼�µģ����ǴӰ�װĿ¼�¿���������
    bIsReloadConfig = bMode;    // ȫ�ֱ����������ڡ�src/tool.c[193]"

//szj    pbuf = getenv("HOME");        // �ӻ��������л�ȡ��ǰ�û���Ŀ¼�ľ���·��
//    if(!pbuf){
//        fprintf(stderr, "error: get environment variable HOME\n");
//        exit(1);    // ��ʱ���Բ��˳�����ֱ���˳������������˼�
//    }
    //��ȡ�����ļ��ľ���·��
//szj    snprintf(buf, PY_PATH_MAX, "%s/.fcitx/config", pbuf);
//    sprintf(buf, "%s//config", "f://data");

    strcpy (buf, respath);
    strcat (buf, "config");

    fp = fopen(buf, "r");
    if(!fp && errno == ENOENT){ /* $HOME/.fcitx/config does not exist */
//szj        snprintf(buf, PY_PATH_MAX, PKGDATADIR "/data/config");
        bFromUser = False;
        fp = fopen(buf, "r");
        if(!fp){
            perror("fopen");
            exit(1);    // �����װĿ¼����Ҳû�������ļ����Ǿ�ֻ�ø����û����޷�������
        }
    }

    if(!bFromUser) /* create default configure file */
        SaveConfig();

    group_idx = -1;

    /* FIXME: Ҳ��Ӧ���������ǡ���Ļ��������� */
    while(fgets(buf, PY_PATH_MAX, fp)){        //ÿ��������PY_PATH_MAX��С������
        i = strlen(buf);

        /*fcitx�������ļ�ÿ�������PY_PATH_MAX���ַ�������������FIXME*/
        if(buf[i-1] != '\n'){
            fprintf(stderr, "error: configure file: line length\n");
            exit(1);
        }else
            buf[i-1] = '\0';

        pbuf = buf;
        while(*pbuf && isspace(*pbuf))    //��pbufָ���һ���ǿ��ַ�
            pbuf++;
        if(!*pbuf || *pbuf == '#')        //��������ǿ����ݻ�����ע��(��#��ͷΪע��)
            continue;

        if(*pbuf == '['){ /* get a group name(�����ĸ�ʽΪ"[����]")*/
            pbuf++;
            pbuf1 = strchr(pbuf, ']');
            if(!pbuf1){
                fprintf(stderr, "error: configure file: configure group name\n");
                exit(1);
            }

            //����group�������ҵ�����ȫ�ֱ���configure_groups�е�index
            group_idx = -1;
            for(i = 0; configure_groups[i].name; i++)
                if(strncmp(configure_groups[i].name, pbuf, pbuf1-pbuf) == 0){
                    group_idx = i;
                    break;
                }
            if(group_idx < 0){
                fprintf(stderr, "error: invalid configure group name\n");
                exit(1); /* ����Ϊ���û�б�Ҫ�˳����˴���ȫ���Ժ����������
                          * �����ں���Ҳ�������������ü��ɡ�
                          * ��Ϊ����˳�ֻ�����һ���������Ǿ�����չ�ԡ�
                          * �Ժ�������µ����ʱ���ϰ汾�ĳ�����޷�ʹ��
                          * �°汾�������ļ��ˡ����ߣ������һ����ѡ��չ��
                          * ����չ�����һ����ȵȡ����ԣ��˴�Ӧ�ø�һ�����棬
                          * �������˳���*/
            }
            continue;
        }

        //pbuf1ָ���һ���ǿ��ַ���=֮����ַ�
        pbuf1 = strchr(pbuf, '=');
        if(!pbuf1){
            fprintf(stderr, "error: configure file: configure entry name\n");
            exit(1);    // ��ǰ��һ�������ҲӦ����һ���������Ӧ������ʾ�����˳���
        }

        /*
         * ��������������һ������������ļ�ͷ����һ��������(�������롰������=����ֵ��
         * ��һ���ַ���)��û���κη��顣Ҳ���Ƿ�ֹ��������ġ�����1���͡�����2��
         * #�ļ�ͷ
         * ����1=123 ����2=123
         * [����]
         * ...
         * #�ļ�β
         */


        if(group_idx < 0){
            fprintf(stderr, "error: configure file: no group name at beginning\n");
            exit(1);
        }
        //�ҵ������е�����������䱣�浽��Ӧ��ȫ�ֱ�������ȥ
        for(tmpconfig = configure_groups[group_idx].configure;
                tmpconfig->name; tmpconfig++)
        {

            if(strncmp(tmpconfig->name, pbuf, pbuf1-pbuf) == 0)
                read_configure(tmpconfig, ++pbuf1);
        }
    }

    fclose(fp);

    /* ��������ļ���û�����ô�/�ر����뷨���ȼ�����ô����CTRL-SPACEΪĬ���ȼ� */
    if (!Trigger_Keys) {
    iTriggerKeyCount = 0;
    Trigger_Keys = (XIMTriggerKey *) malloc (sizeof (XIMTriggerKey) * (iTriggerKeyCount + 2));
    Trigger_Keys[0].keysym = XK_space;
    Trigger_Keys[0].modifier = ControlMask;
    Trigger_Keys[0].modifier_mask = ControlMask;
    Trigger_Keys[1].keysym = 0;
    Trigger_Keys[1].modifier = 0;
    Trigger_Keys[1].modifier_mask = 0;
    }
}

/**
 * ����������Ϣ
 */
void SaveConfig (void)
{
#if 0 //szj
    FILE    *fp;
    char    buf[PY_PATH_MAX], *pbuf;
    Configure_group *tmpgroup;

    pbuf = getenv("HOME");
    if(!pbuf){
        fprintf(stderr, "error: get environment variable HOME\n");
        exit(1);
    }

    snprintf(buf, PY_PATH_MAX, "%s/.fcitx", pbuf);
    if(mkdir(buf, S_IRWXU) < 0 && errno != EEXIST){
        perror("mkdir");
        exit(1);
    }

//    snprintf(buf, PY_PATH_MAX, "%s/.fcitx/config", pbuf);
    strcpy (buf, respath);
    strcat (buf, "config");

    fp = fopen (buf, "w");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    /* ʵ���ϣ�д�����ļ��ܼ򵥣����Ǵ�ȫ������configure_groups����ֱ��ÿ���������
     * д�뵽�ļ�����ȥ*/
    for(tmpgroup = configure_groups; tmpgroup->name; tmpgroup++){
        if(tmpgroup->comment)
            fprintf(fp, "# %s\n", tmpgroup->comment);    // �������ע�ͣ���д��
        fprintf(fp, "[%s]\n", tmpgroup->name);        // ������д���������
        write_configures(fp, tmpgroup->configure);    // ��󽫸����ÿ��������д�뵽�ļ���
        fprintf(fp, "\n");        // Ϊ���ӿɶ��Բ���һ������
    }
    fclose(fp);
#endif
}

/** �汾 */
inline static int get_version(Configure *c, void *a, int isread)
{
#if 0//szj
    if(isread){
        if(!strcasecmp(FCITX_VERSION, (char *)a))
            bIsNeedSaveConfig = False;
    }else
        fprintf((FILE *)a, "%s=%s\n", c->name, FCITX_VERSION);
#endif
    return 0;
}

/** ������λ��X */
inline static int get_main_window_offset_x(Configure *c, void *a, int isread)
{
#if 0

    if(isread){
        iMainWindowX = atoi((const char*)a);
        if(iMainWindowX < 0)
            iMainWindowX = 0;
        else if((iMainWindowX + MAINWND_WIDTH) > DisplayWidth(dpy, iScreen))
            iMainWindowX = DisplayWidth(dpy, iScreen) - MAINWND_WIDTH;
    }else
        fprintf((FILE *)a, "%s=%d\n", c->name, iMainWindowX);
#endif
    return 0;
}

/** ������λ��Y */
inline static int get_main_window_offset_y(Configure *c, void *a, int isread)
{
#if 0
    if(isread){
        iMainWindowY = atoi((const char*)a);
        if(iMainWindowY < 0)
            iMainWindowY = 0;
        else if((iMainWindowY + MAINWND_HEIGHT) > DisplayHeight(dpy, iScreen))
            iMainWindowY = DisplayHeight(dpy, iScreen) - MAINWND_HEIGHT;
    }else
        fprintf((FILE *)a, "%s=%d\n", c->name, iMainWindowY);
#endif
    return 0;
}

/** ���봰��λ��X */
inline static int get_input_window_offset_x(Configure *c, void *a, int isread)
{
#if 0
    if(isread){
        iInputWindowX = atoi((const char*)a);
        if(iInputWindowX < 0)
            iInputWindowX = 0;
        else if((iInputWindowX + iInputWindowWidth) > DisplayWidth(dpy, iScreen))
            iInputWindowX = DisplayWidth(dpy, iScreen) - iInputWindowWidth - 3;
    }else
        fprintf((FILE *)a, "%s=%d\n", c->name, iInputWindowX);
#endif
    return 0;
}

/** ���봰��λ��Y */
inline static int get_input_window_offset_y(Configure *c, void *a, int isread)
{
#if 0
    if(isread){
        iInputWindowY = atoi((const char*)a);
        if(iInputWindowY < 0)
            iInputWindowY = 0;
        else if((iInputWindowY + iInputWindowHeight) > DisplayHeight(dpy, iScreen))
            iInputWindowY = DisplayHeight(dpy, iScreen) - iInputWindowHeight - 3;
    }else
        fprintf((FILE *)a, "%s=%d\n", c->name, iInputWindowY);
#endif
    return 0;
}

static int iIMIndex_tmp = 0;        /* Issue 11: piaoairy add 20080518 */

#if 1   //szj
int  initConfig2()
{
    profiles[0].name = "�汾";
    profiles[0].value_type = CONFIG_OTHER;
    profiles[0].config_rw = get_version;

    profiles[1].name = "������λ��X";
    profiles[1].value_type = CONFIG_OTHER;
    profiles[1].config_rw = get_main_window_offset_x;

    profiles[2].name = "������λ��Y";
    profiles[2].value_type = CONFIG_OTHER;
    profiles[2].config_rw = get_main_window_offset_y;

    profiles[3].name = "���봰��λ��X";
    profiles[3].value_type = CONFIG_OTHER;
    profiles[3].config_rw = get_input_window_offset_x;


    profiles[4].name = "���봰��λ��Y";
    profiles[4].value_type = CONFIG_OTHER;
    profiles[4].config_rw = get_input_window_offset_y;

    profiles[5].name = "ȫ��";
    profiles[5].value_type = CONFIG_INTEGER;
    profiles[5].value.integer = &bCorner;

    profiles[6].name = "���ı��";
    profiles[6].value_type = CONFIG_INTEGER;
    profiles[6].value.integer = &bChnPunc;

    profiles[7].name = "GBK";
    profiles[7].value_type = CONFIG_INTEGER;
    profiles[7].value.integer = &bUseGBK;

    profiles[8].name = "������";
    profiles[8].value_type = CONFIG_INTEGER;
    profiles[8].value.integer = &bTrackCursor;

    profiles[9].name = "����";
    profiles[9].value_type = CONFIG_INTEGER;
    profiles[9].value.integer = &bUseLegend;

    profiles[10].name = "��ǰ���뷨";//  Issue 11: piaoairy: �������㽫iIMIndex ��Ϊint����,
    profiles[10].value_type = CONFIG_INTEGER;// ����ʹ�õĵط�̫��,
    profiles[10].value.integer = &iIMIndex_tmp;// ֻ�����¶����iIMIndex_tmp����

    profiles[11].name = "��ֹ�����л�";
    profiles[11].value_type = CONFIG_INTEGER;
    profiles[11].value.integer = &bLocked;

    profiles[12].name = "���ģʽ";
    profiles[12].value_type = CONFIG_INTEGER;
    profiles[12].value.integer = &bCompactMainWindow;

    profiles[13].name = "GBK����";
    profiles[13].value_type = CONFIG_INTEGER;
    profiles[13].value.integer = &bUseGBKT;

    profiles[14].name = NULL;

    return 0;
}
#else

Configure profiles[] = {
    {
        .name = "�汾",
        .value_type = CONFIG_OTHER,
        .config_rw = get_version,
    },
    {
        .name = "������λ��X",
        .value_type = CONFIG_OTHER,
        .config_rw = get_main_window_offset_x,
    },
    {
        .name = "������λ��Y",
        .value_type = CONFIG_OTHER,
        .config_rw = get_main_window_offset_y,
    },
    {
        .name = "���봰��λ��X",
        .value_type = CONFIG_OTHER,
        .config_rw = get_input_window_offset_x,
    },
    {
        .name = "���봰��λ��Y",
        .value_type = CONFIG_OTHER,
        .config_rw = get_input_window_offset_y,
    },
    {
        .name = "ȫ��",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bCorner,
    },
    {
        .name = "���ı��",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bChnPunc,
    },
    {
        .name = "GBK",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bUseGBK,
    },
    {
        .name = "������",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bTrackCursor,
    },
    {
        .name = "����",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bUseLegend,
    },
    {
        .name = "��ǰ���뷨",    //  Issue 11: piaoairy: �������㽫iIMIndex ��Ϊint����,
        .value_type = CONFIG_INTEGER,    // ����ʹ�õĵط�̫��,
        .value.integer = &iIMIndex_tmp,    // ֻ�����¶����iIMIndex_tmp����.
    },
    {
        .name = "��ֹ�����л�",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bLocked,
    },
    {
        .name = "���ģʽ",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bCompactMainWindow,
    },
    {
        .name = "GBK����",
        .value_type = CONFIG_INTEGER,
        .value.integer = &bUseGBKT,
    },
    {
        .name = NULL,
    },
};
#endif

/**
 * @brief ���������ļ�
 * @param void
 * @return void
 */
void LoadProfile (void)
{
    FILE           *fp;
    char            buf[PY_PATH_MAX], *pbuf, *pbuf1;
    int             i;
    Configure       *tmpconfig;


    /* ǰ�����ڵ�λ���趨Ϊ��ԭʼ��Ĭ��ֵ����������������ļ��У�
     * ��������ļ��ж�ȡ�����û�о�ʹ�������*/
    iMainWindowX = MAINWND_STARTX;        //������λ��X
    iMainWindowY = MAINWND_STARTY;        //������λ��Y
    iInputWindowX = INPUTWND_STARTX;    //���봰��λ��X
    iInputWindowY = INPUTWND_STARTY;    //���봰��λ��Y

    return ;  //szj
//szj    pbuf = getenv("HOME");
//    if(!pbuf){
//        fprintf(stderr, "error: get environment variable HOME\n");
//        exit(1);
//    }
//szj    snprintf(buf, PY_PATH_MAX, "%s/.fcitx/profile", pbuf);
    sprintf(buf, "%s//profile", "f://data");

    fp = fopen(buf, "r");
    if(!fp){
        if(errno == ENOENT)
            SaveProfile();
        return;
    }

    /* FIXME: Ҳ��Ӧ���������ǡ���Ļ��������� */
    while(fgets(buf, PY_PATH_MAX, fp)){
        i = strlen(buf);
        if(buf[i-1] != '\n'){
            fprintf(stderr, "error: profile file: line length\n");
            exit(1);
        }else
            buf[i-1] = '\0';

        pbuf = buf;
        while(*pbuf && isspace(*pbuf))
            pbuf++;
        if(!*pbuf || *pbuf == '#')
            continue;

        pbuf1 = strchr(pbuf, '=');
        if(!pbuf1){
            fprintf(stderr, "error: profile file: configure entry name\n");
            exit(1);
        }

        for(tmpconfig = profiles; tmpconfig->name; tmpconfig++)
            if(strncmp(tmpconfig->name, pbuf, pbuf1-pbuf) == 0)
                read_configure(tmpconfig, ++pbuf1);
    }

    fclose(fp);

    iIMIndex = iIMIndex_tmp;        /* piaoairy add 20080518 */

    if(bIsNeedSaveConfig){
        SaveConfig();
        SaveProfile();
     }
}

void SaveProfile (void)
{
    return;
#if 0
    FILE           *fp;
    char            buf[PY_PATH_MAX], *pbuf;

//    pbuf = getenv("HOME");
//    if(!pbuf){
//        fprintf(stderr, "error: get environment variable HOME\n");
//        exit(1);
//    }

//    snprintf(buf, PY_PATH_MAX, "%s/.fcitx", pbuf);
//    if(mkdir(buf, S_IRWXU) < 0 && errno != EEXIST){
//        perror("mkdir");
//        exit(1);
//    }

//    snprintf(buf, PY_PATH_MAX, "%s/.fcitx/profile", pbuf);

    strcpy (buf, respath);
    strcat (buf, "profile");

    fp = fopen (buf, "w");

    if (!fp) {
    perror("fopen");
        exit(1);
    }

    iIMIndex_tmp = iIMIndex;        /* piaoairy add 20080518 */
    write_configures(fp, profiles);
    fclose(fp);
#endif
}

void SetHotKey (char *strKeys, HOTKEYS * hotkey)
{
    char           *p;
    char            strKey[30];
    int             i, j;

    p = strKeys;

    while (*p == ' ')
    p++;
    i = 0;
    while (p[i] != ' ' && p[i] != '\0')
    i++;
    strncpy (strKey, p, i);
    strKey[i] = '\0';
    p += i + 1;
    j = ParseKey (strKey);
    if (j != -1)
    hotkey[0] = j;
    if (j == -1)
    j = 0;
    else
    j = 1;

    i = 0;
    while (p[i] != ' ' && p[i] != '\0')
    i++;
    if (p[0]) {
    strncpy (strKey, p, i);
    strKey[i] = '\0';

    i = ParseKey (strKey);
    if (i == -1)
        i = 0;
    }
    else
    i = 0;

    hotkey[j] = i;
}

/*
 * �����ļ����ж�����
 * ע��:�ļ��еĿ���Ҳ��Ϊһ�д���
 */
int CalculateRecordNumber (FILE * fpDict)
{
    char            strText[101];
    int             nNumber = 0;

    for (;;) {
    if (!fgets (strText, 100, fpDict))
        break;

    nNumber++;
    }
    rewind (fpDict);

    return nNumber;
}

void SetSwitchKey (char *str)
{
#if 0  //szj
    if (!strcasecmp (str, "R_CTRL"))
    switchKey = XKeysymToKeycode (dpy, XK_Control_R);
    else if (!strcasecmp (str, "R_SHIFT"))
    switchKey = XKeysymToKeycode (dpy, XK_Shift_R);
    else if (!strcasecmp (str, "L_SHIFT"))
    switchKey = XKeysymToKeycode (dpy, XK_Shift_L);
    else if (!strcasecmp (str, "R_SUPER"))
    switchKey = XKeysymToKeycode (dpy, XK_Super_R);
    else if (!strcasecmp (str, "L_SUPER"))
    switchKey = XKeysymToKeycode (dpy, XK_Super_L);
    else
    switchKey = XKeysymToKeycode (dpy, XK_Control_L);
#endif
}

void SetTriggerKeys (char *str)
{
    int             i;
    char            strKey[2][30];
    char           *p;

    //�������ж��û������˼����ȼ������Ϊ2
    p = str;

    i = 0;
    iTriggerKeyCount = 0;
    while (*p) {
    if (*p == ' ') {
        iTriggerKeyCount++;
        while (*p == ' ')
        p++;
        strcpy (strKey[1], p);
        break;
    }
    else
        strKey[0][i++] = *p++;
    }
    strKey[0][i] = '\0';

    Trigger_Keys = (XIMTriggerKey *) malloc (sizeof (XIMTriggerKey) * (iTriggerKeyCount + 2));
    for (i = 0; i <= (iTriggerKeyCount + 1); i++) {
    Trigger_Keys[i].keysym = 0;
    Trigger_Keys[i].modifier = 0;
    Trigger_Keys[i].modifier_mask = 0;
    }

    for (i = 0; i <= iTriggerKeyCount; i++) {
    if (MyStrcmp (strKey[i], "CTRL_")) {
        Trigger_Keys[i].modifier = Trigger_Keys[i].modifier | ControlMask;
        Trigger_Keys[i].modifier_mask = Trigger_Keys[i].modifier_mask | ControlMask;
    }
    else if (MyStrcmp (strKey[i], "SHIFT_")) {
        Trigger_Keys[i].modifier = Trigger_Keys[i].modifier | ShiftMask;
        Trigger_Keys[i].modifier_mask = Trigger_Keys[i].modifier_mask | ShiftMask;
    }
    else if (MyStrcmp (strKey[i], "ALT_")) {
        Trigger_Keys[i].modifier = Trigger_Keys[i].modifier | Mod1Mask;
        Trigger_Keys[i].modifier_mask = Trigger_Keys[i].modifier_mask | Mod1Mask;
    }
    else if (MyStrcmp (strKey[i], "SUPER_")) {
        Trigger_Keys[i].modifier = Trigger_Keys[i].modifier | Mod4Mask;
        Trigger_Keys[i].modifier_mask = Trigger_Keys[i].modifier_mask | Mod4Mask;
    }

    if (Trigger_Keys[i].modifier == 0) {
        Trigger_Keys[i].modifier = ControlMask;
        Trigger_Keys[i].modifier_mask = ControlMask;
    }

    p = strKey[i] + strlen (strKey[i]) - 1;
    while (*p != '_') {
        p--;
        if (p == strKey[i] || (p == strKey[i] + strlen (strKey[i]) - 1)) {
        Trigger_Keys = (XIMTriggerKey *) malloc (sizeof (XIMTriggerKey) * (iTriggerKeyCount + 2));
        Trigger_Keys[i].keysym = XK_space;
        return;
        }
    }
    p++;

#if 0 //szj

    if (strlen (p) == 1)
        Trigger_Keys[i].keysym = tolower (*p);
    else if (!strcasecmp (p, "LCTRL"))
        Trigger_Keys[i].keysym = XK_Control_L;
    else if (!strcasecmp (p, "RCTRL"))
        Trigger_Keys[i].keysym = XK_Control_R;
    else if (!strcasecmp (p, "LSHIFT"))
        Trigger_Keys[i].keysym = XK_Shift_L;
    else if (!strcasecmp (p, "RSHIFT"))
        Trigger_Keys[i].keysym = XK_Shift_R;
    else if (!strcasecmp (p, "LALT"))
        Trigger_Keys[i].keysym = XK_Alt_L;
    else if (!strcasecmp (p, "RALT"))
        Trigger_Keys[i].keysym = XK_Alt_R;
    else if (!strcasecmp (p, "LSUPER"))
        Trigger_Keys[i].keysym = XK_Super_L;
    else if (!strcasecmp (p, "RSUPER"))
        Trigger_Keys[i].keysym = XK_Super_R;
    else
        Trigger_Keys[i].keysym = XK_space;
#endif
    }

}

Bool CheckHZCharset (char *strHZ)
{
    return True;
    if (!bUseGBK) {
    //GB2312�ĺ��ֱ������Ϊ����һ���ֽڵ�ֵ��0xA1��0xFE֮��(ʵ��Ϊ0xF7)���ڶ����ֽڵ�ֵ��0xA1��0xFE֮��
    //���ڲ鵽������˵����һ�����ú�ʵ����������
    int             i;

    for (i = 0; i < (int)strlen (strHZ); i++) {
        if ((unsigned char) strHZ[i] < (unsigned char) 0xA1 || (unsigned char) strHZ[i] > (unsigned char) 0xF7 || (unsigned char) strHZ[i + 1] < (unsigned char) 0xA1 || (unsigned char) strHZ[i + 1] > (unsigned char) 0xFE)
        return False;
        i++;
    }
    }

    return True;
}

static char    *gGBKS2TTable = NULL;
static int      gGBKS2TTableSize = -1;

/**
 * �ú���װ��data/gbks2t.tab�ļ���ת��������
 * Ȼ�����GBK�ַ�ת����GBK�����ַ���
 *
 * WARNING�� �ú��������·����ڴ��ַ������������
 * ע���ͷš�
 */
char           *ConvertGBKSimple2Tradition (char *strHZ)
{
    FILE           *fp;
    char           *ret;
    char            strPath[PY_PATH_MAX];
    int             i, len;
    int                idx;

    if (strHZ == NULL)
    return NULL;

    if (!gGBKS2TTable) {
    len = 0;

//    strcpy (strPath, PKGDATADIR "/data/");
//    strcat (strPath, TABLE_GBKS2T);

    strcpy (strPath, respath);
    strcat (strPath, TABLE_GBKS2T);


    fp = fopen (strPath, "rb");
    if (!fp) {
        ret = (char *) malloc (sizeof (char) * (strlen (strHZ) + 1));
        strcpy (ret, strHZ);
        return ret;
    }

    fseek (fp, 0, SEEK_END);
    fgetpos (fp, (fpos_t *) & len);
    if (len > 0) {
        gGBKS2TTable = (char *) malloc (sizeof (char) * len);
        gGBKS2TTableSize = len;
        fseek (fp, 0, SEEK_SET);
        fread (gGBKS2TTable, sizeof (char), len, fp);
    }
    fclose (fp);
    }

    i = 0;
    len = strlen (strHZ);
    ret = (char *) malloc (sizeof (char) * (len + 1));
    for (; i < len; ++i) {
    if (i < (len - 1))
        if ((unsigned char) strHZ[i] >= (unsigned char) 0x81
        && (unsigned char) strHZ[i] <= (unsigned char) 0xfe &&
        (((unsigned char) strHZ[i + 1] >= (unsigned char) 0x40 && (unsigned char) strHZ[i + 1] <= (unsigned char) 0x7e) || ((unsigned char) strHZ[i + 1] > (unsigned char) 0x7f && (unsigned char) strHZ[i + 1] <= (unsigned char) 0xfe))) {
        idx = (((unsigned char) strHZ[i] - (unsigned char) 0x81)
               * (unsigned char) 0xbe + ((unsigned char) strHZ[i + 1] - (unsigned char) 0x40)
               - ((unsigned char) strHZ[i + 1] / (unsigned char) 0x80)) * 2;
        if (idx >= 0 && idx < gGBKS2TTableSize - 1) {
            //if ((unsigned char)gGBKS2TTable[idx] != (unsigned char)0xa1 && (unsigned char) gGBKS2TTable[idx + 1] != (unsigned char) 0x7f) {
            if ((unsigned char) gGBKS2TTable[idx + 1] != (unsigned char) 0x7f) {
            ret[i] = gGBKS2TTable[idx];
            ret[i + 1] = gGBKS2TTable[idx + 1];
            i += 1;
            continue;
            }
        }
        }
    ret[i] = strHZ[i];
    }
    ret[len] = '\0';

    return ret;
}

int CalHZIndex (char *strHZ)
{
    return (strHZ[0] + 127) * 255 + strHZ[1] + 128;
}
