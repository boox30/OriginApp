// test3.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"


//int main(int argc, char* argv[])
//{
//    return 0;
//}



/***************************************************************************
 *   С����������뷨(Free Chinese Input Toys for X, FCITX)                   *
 *   ��Yuking(yuking_net@sohu.com)��д                                           *
 *   Э��: GPL                                                              *
 *   FCITX( A Chinese XIM Input Method) by Yuking (yuking_net@sohu.com)    *
 *                                                                         *
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
 * @file   main.c
 * @author Yuking yuking_net@sohu.com
 * @date   2008-1-16
 *
 * @brief  ���������
 *
 *
 */
#include "stdafx.h"

//szj #include <langinfo.h>

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "PYmain.h"
#include "tools.h"
#include "ui.h"
#include "MainWindow.h"
#include "InputWindow.h"
#ifdef _ENABLE_TRAY
#include "TrayWindow.h"
#endif

#include "vk.h"
#include "ime.h"
#include "table.h"
#include "punc.h"
#include "py.h"

#include "sp.h"
#include "QuickPhrase.h"
#include "AutoEng.h"

#ifndef CODESET
#define CODESET 14
#endif

extern Display *dpy;
extern Window   inputWindow;

extern Bool     bIsUtf8;

extern HIDE_MAINWINDOW hideMainWindow;

int main_PY()
{
//    int             c;     //���ڱ����û�����Ĳ���
//   Bool            bBackground = True;
//   char        *imname=(char *)NULL;
    extern  Bool            bPYBaseDictLoaded;
    extern Bool            bPYOtherDictLoaded;
    initConfig();  //szj
    initConfig2();  //szj

    if (!InitX ()){};
    //exit (1);

    /*�����û������ļ���ͨ���ǡ�~/.fcitx/config����������ļ������ھʹӰ�װĿ¼�п���
     * ��/data/config������~/.fcitx/config��
     */

    LoadConfig (True);

    /*�������塣ʵ���ϣ����Ǹ����û������ã�ʹ��xft��ȡ����������Ϣ��
     * xft��x11�ṩ�Ĵ����������غ�����
     */
    CreateFont ();

    //��������������봰�ڵĸ߶�
    CalculateInputWindowHeight ();

    /*���������ļ�����������ļ������û����õģ��������ڼ�¼fctix������״̬�ģ�
     * ������ȫ�ǻ��ǰ�ǵȵȡ�ͨ���ǡ�~/.fcitx/profile����������ļ������ھʹӰ�װ
     * Ŀ¼�п�����/data/profile������~/.fcitx/profile��
     */
    LoadProfile ();

    //���ر���ֵ��ļ�
    LoadPuncDict ();
    //���س���
    LoadQuickPhrase ();
    /*�� ~/.fcitx/AutoEng.dat ����������ڣ�
     * ��� /usr/local/share/fcitx/data/AutoEng.dat��
     * ��ȡ��Ҫ�Զ�ת����Ӣ������״̬�����������
     */
    LoadAutoEng ();

    //�����ǽ���Ĵ���

    CreateMainWindow ();    //���������ڣ������뷨״̬����
    CreateVKWindow ();        //������ѡ�ʴ���
    CreateInputWindow ();    //�������봰��
//szj    CreateAboutWindow ();    //�������ڴ���

    //������ɫ������ѡ�ʴ��ڵ���ɫ��Ҳ���������ڡ�~/.fcitx/config���������Щ��ɫ��Ϣ
    InitGC (inputWindow);

    //����������뵽���뷨�飬����ϵͳ��ʹ���������ַ�
    SetIM ();

    //���������ڵ���ʾ
    if (hideMainWindow != HM_HIDE) {
    DisplayMainWindow ();
    DrawMainWindow ();
    }
    if (!bPYBaseDictLoaded)
    LoadPYBaseDict ();
    if (!bPYOtherDictLoaded)
    LoadPYOtherDict ();

    //�Ժ�̨��ʽ����

#ifdef _ENABLE_TRAY
    CreateTrayWindow ();        //����ϵͳ���̴���
    DrawTrayWindow (INACTIVE_ICON);    //��ʾ����ͼ��
#endif

    return 0;
}

void Usage ()
{
    printf("Usage: fcitx [OPTION]\n"
           "\t-d\t\trun as daemon(default)\n"
           "\t-D\t\tdon't run as daemon\n"
       "\t-n[im name]\trun as specified name\n"
           "\t-v\t\tdisplay the version information and exit\n"
           "\t-h\t\tdisplay this help and exit\n");
}

void Version ()
{
}
