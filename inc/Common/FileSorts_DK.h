/**@file FileSorts_DK.h
 *
 * @brief �࿴ϵͳ�ײ��ļ�����������ӿ�
 *
 * @version 1.0
 *
 * @author wh
 * @date 2011-4-12
 * \n
 * @b ��Ȩ��Ϣ��
 *
 * - �����࿴�Ƽ����޹�˾ Copyright (C) 2011 - 2012
 *
 * _______________________________________________________________________
 */

#ifndef _DK_FILESORTS_H_
#define _DK_FILESORTS_H_

#include "Common/File_DK.h"



//�����ļ���ʽ
//enum DK_FileSorts
//{
//    UnknowSort =0,          //��ȡĳһ�����ļ� �����飨ͼ����������Ƶ
//    RecentlyAdd,            //�������
//    RecentlyReadTime,      //����Ķ�
//    Name,                   //�����ؼ���
//    DIRECTORY               //Ŀ¼
//};

enum Field
{
    FIELD_NONE = 0,                ///< Do not sort.
    LAST_ACCESS_TIME,
    BY_DIRECTORY,
    RECENTLY_ADD,
    NAME,
    TITLE,
    DESCRIPTION,
    SIZE,
    RATING,
    READ_COUNT,
    CREATE_TIME,
    NODE_TYPE,
    NODE_STATUS,
    NOT_ON_LOCAL,
    EXPAND
};

class CDKFileSorts
{
public:

public:
    CDKFileSorts();

public:
    void    SortsFile();

public:
    void SetFileListAndNum(const DKFileList& files);
    void SetFileSorts(Field Sort);
    void SetFileCategory(DkFormatCategory category);
    const DKFileList& GetFileSortResult() const
    {
        return m_sortedFiles;
    }

private:
    void    SortsFileByRecentlyReadTime();
    void    SortsFileByFileNameDefault();
    void    SortsFileByRecentlyAdd();
    void    SortsFileByFileName();

	//isNameSort ���ж����ɰ������������˺�����������ĸ���ҽ���
	//ֻ�а������ǲ���Ҫȫ�������ļ�
    void    CreateFileListIndexbyDefault(bool isNameSort);


private:
    DkFormatCategory  m_fileCategory;
    Field m_sort;
    DKFileList m_files;
    DKFileList m_sortedFiles;
};

#endif /*_DK_FILESORTS_H_*/

