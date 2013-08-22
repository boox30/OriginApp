//===========================================================================
// Summary:
//      MobiLib������붨�塣
// Usage:
//      Null
// Remarks:
//      Null
// Date:
//      2012-02-25
// Author:
//      Zhai Guanghe (zhaigh@duokan.com)
//===========================================================================

#ifndef __KERNEL_MOBIKIT_MOBILIB_EXPORT_DKMRETCODE_H__
#define __KERNEL_MOBIKIT_MOBILIB_EXPORT_DKMRETCODE_H__

#include "KernelRetCode.h"

//===========================================================================
// ���������

#define DKR_EPUB_CONTAINER_BASEVALUE    DKR_EPUB_BASEVALUE          // ���ṹ
#define DKR_EPUB_PARSER_BASEVALUE       DKR_EPUB_BASEVALUE + 200    // ����
#define DKR_EPUB_RENDER_BASEVALUE       DKR_EPUB_BASEVALUE + 400    // ��Ⱦ
#define DKR_EPUB_INTERACT_BASEVALUE     DKR_EPUB_BASEVALUE + 600    // ҳ�潻��
#define DKR_EPUB_HTMLPARSE_BASEVALUE    DKR_EPUB_BASEVALUE + 800    // HTML��������

//===========================================================================
// ���ṹ���ֵĴ�����

// �Ҳ��������
#define DKR_EPUB_CONTAINER_NOENTRYFOUND                  (DKR_EPUB_CONTAINER_BASEVALUE + 1L)
// ��ʼ������
#define DKR_EPUB_CONTAINER_INIT_ERR                      (DKR_EPUB_CONTAINER_BASEVALUE + 2L)
// Entry���ֳ���Ϊ0
#define DKR_EPUB_CONTAINER_NAMELENZERO                   (DKR_EPUB_CONTAINER_BASEVALUE + 3L)
// Entryͷ���ݶ�ȡʧ��
#define DKR_EPUB_CONTAINER_READENTRY_ERR                 (DKR_EPUB_CONTAINER_BASEVALUE + 4L)
// Entryͷ��������
#define DKR_EPUB_CONTAINER_ENTRYNAMEEXISTS               (DKR_EPUB_CONTAINER_BASEVALUE + 5L)
// �Ҳ�����Ӧ�Ľڵ�
#define DKR_EPUB_CONTAINER_NOENTRYMATCHED                (DKR_EPUB_CONTAINER_BASEVALUE + 6L)
// ����������ʧ��
#define DKR_EPUB_CONTAINER_GETSTREAM_ERR                 (DKR_EPUB_CONTAINER_BASEVALUE + 7L)
// �����ļ�����ʧ��
#define DKR_EPUB_CONTAINER_CREATEFILECACHE_ERR           (DKR_EPUB_CONTAINER_BASEVALUE + 8L)
// ѹ����ʽ������Ҫ��
#define DKR_EPUB_CONTAINER_COMPRESSMETHOD_ERR            (DKR_EPUB_CONTAINER_BASEVALUE + 9L)
// ����ʵ�ַ�ʽ��ƥ��
#define DKR_EPUB_CONTAINER_PACTYPE_ERR                   (DKR_EPUB_CONTAINER_BASEVALUE + 10L)
// ��mimetype����
#define DKR_EPUB_CONTAINER_MIMETYPE_ERR                  (DKR_EPUB_CONTAINER_BASEVALUE + 11L)
// ��ʼ��xml parser����
#define DKR_EPUB_CONTAINER_INITXMLPARSER_ERR             (DKR_EPUB_CONTAINER_BASEVALUE + 12L)
// ������ȡ���ݴ���
#define DKR_EPUB_CONTAINER_GETCONTENT_ERR                (DKR_EPUB_CONTAINER_BASEVALUE + 13L)
// open xml����
#define DKR_EPUB_CONTAINER_OPENXML_ERR                   (DKR_EPUB_CONTAINER_BASEVALUE + 14L)
// xml root��ȡ����
#define DKR_EPUB_CONTAINER_GETXMLROOT_ERR                (DKR_EPUB_CONTAINER_BASEVALUE + 15L)
// ����opf package
#define DKR_EPUB_CONTAINER_OPF_GETPACKAGE_ERR            (DKR_EPUB_CONTAINER_BASEVALUE + 16L)
#define DKR_EPUB_CONTAINER_OPF_GETMETADATA_ERR           (DKR_EPUB_CONTAINER_BASEVALUE + 17L)
#define DKR_EPUB_CONTAINER_OPF_GETADDITIONALMETADATA_ERR (DKR_EPUB_CONTAINER_BASEVALUE + 18L)
#define DKR_EPUB_CONTAINER_OPF_GETMENIFEST_ERR           (DKR_EPUB_CONTAINER_BASEVALUE + 19L)
#define DKR_EPUB_CONTAINER_OPF_PARSEMENIFEST_ERR         (DKR_EPUB_CONTAINER_BASEVALUE + 20L)
#define DKR_EPUB_CONTAINER_OPF_GETSPINE_ERR              (DKR_EPUB_CONTAINER_BASEVALUE + 21L)
#define DKR_EPUB_CONTAINER_OPF_PARSESPINE_ERR            (DKR_EPUB_CONTAINER_BASEVALUE + 22L)
#define DKR_EPUB_CONTAINER_ENCRYPTION_NOKEY              (DKR_EPUB_CONTAINER_BASEVALUE + 23L)
#define DKR_EPUB_CONTAINER_ENCRYPTED                     (DKR_EPUB_CONTAINER_BASEVALUE + 24L)
#define DKR_EPUB_MOBI_NO_TOC                             (DKR_EPUB_CONTAINER_BASEVALUE + 25L)
#define DKR_EPUB_MOBI_NO_MAIN_STREAM                     (DKR_EPUB_CONTAINER_BASEVALUE + 26L)
#define DKR_EPUB_BOOK_OPEN_FAIL                          (DKR_EPUB_CONTAINER_BASEVALUE + 27L)
#define DKR_EPUB_DRM_CHECK_VERSION_FAIL                  (DKR_EPUB_CONTAINER_BASEVALUE + 28L)

//===========================================================================
// �������ַ���ֵ������

// ��̬������ʼ������
#define DKR_EPUB_PARSER_STATICINIT_ERR                  DKR_EPUB_PARSER_BASEVALUE
// ��ʼ������
#define DKR_EPUB_PARSER_BASEBOOKINIT_ERR                (DKR_EPUB_PARSER_BASEVALUE + 1L)
// ��ε��ý���������Ϣ���ϴν����ѳ���
#define DKR_EPUB_PARSER_LASTBASIC_ERR                   (DKR_EPUB_PARSER_BASEVALUE + 2L)
// û���ҵ�OCF������ļ�·��
#define DKR_EPUB_PARSER_NOOCFPATH                       (DKR_EPUB_PARSER_BASEVALUE + 3L)
// ҳ�������ָ��Ϊ��
#define DKR_EPUB_PARSER_PAGEPARSERNULL                  (DKR_EPUB_PARSER_BASEVALUE + 4L)
// �Ҳ���ҳ���Ӧ�����ļ�
#define DKR_EPUB_PARSER_PAGELOCNULL                     (DKR_EPUB_PARSER_BASEVALUE + 5L)
// ������Ϣ������ڲ�������ȷ
#define DKR_EPUB_PARSER_BASICPARSERPARAM_ERR            (DKR_EPUB_PARSER_BASEVALUE + 6L)
// ҳ���ļ�������ڲ�������ȷ
#define DKR_EPUB_PARSER_PAGEPARSERPARAM_ERR             (DKR_EPUB_PARSER_BASEVALUE + 7L)
// CSS�ļ�������ڲ�������ȷ
#define DKR_EPUB_PARSER_CSSPARSERPARAM_ERR              (DKR_EPUB_PARSER_BASEVALUE + 8L)
// ������Ϣ���ݻ�ȡʧ��
#define DKR_EPUB_PARSER_BASICPARSERGETDATA_ERR          (DKR_EPUB_PARSER_BASEVALUE + 9L)
// ҳ�����ݻ�ȡʧ��
#define DKR_EPUB_PARSER_PAGEPARSERGETDATA_ERR           (DKR_EPUB_PARSER_BASEVALUE + 10L)
// CSS���ݻ�ȡʧ��
#define DKR_EPUB_PARSER_CSSPARSERGETDATA_ERR            (DKR_EPUB_PARSER_BASEVALUE + 11L)
// CSS���벻��ʶ���ת��ʧ��
#define DKR_EPUB_PARSER_CSSDECODING_ERR                 (DKR_EPUB_PARSER_BASEVALUE + 12L)
// ����������Ϣʧ��
#define DKR_EPUB_PARSER_BASICPARSE_ERR                  (DKR_EPUB_PARSER_BASEVALUE + 13L)
// ����ҳ��ʧ��
#define DKR_EPUB_PARSER_PAGEPARSE_ERR                   (DKR_EPUB_PARSER_BASEVALUE + 14L)
// ����CSSʧ��
#define DKR_EPUB_PARSER_CSSPARSE_ERR                    (DKR_EPUB_PARSER_BASEVALUE + 15L)
// �������ļ�״̬����
#define DKR_EPUB_PARSER_ROOTPARSESTATUS_ERR             (DKR_EPUB_PARSER_BASEVALUE + 16L)
// ����Ŀ¼�ļ�״̬����
#define DKR_EPUB_PARSER_NCXPARSESTATUS_ERR              (DKR_EPUB_PARSER_BASEVALUE + 17L)
// ����OPF״̬����
#define DKR_EPUB_PARSER_OPFPARSESTATUS_ERR              (DKR_EPUB_PARSER_BASEVALUE + 18L)
// ����OPF�Ҳ���ҳ�������ڵ�
#define DKR_EPUB_PARSER_OPFPARSENOPAGENODE              (DKR_EPUB_PARSER_BASEVALUE + 19L)
// ����ʶ��XHTML���
#define DKR_EPUB_PARSER_PAGEUNKNOWNTAG                  (DKR_EPUB_PARSER_BASEVALUE + 20L)
// ����ҳ��״̬����
#define DKR_EPUB_PARSER_PAGESTATUS_ERR                  (DKR_EPUB_PARSER_BASEVALUE + 21L)
// ����XML���ļ�������
#define DKR_EPUB_PARSER_OPENFILESTREAM_ERR              (DKR_EPUB_PARSER_BASEVALUE + 22L)
// ����XML��ȡ�ļ������ݴ���
#define DKR_EPUB_PARSER_READFILESTREAM_ERR              (DKR_EPUB_PARSER_BASEVALUE + 23L)
// ����XML���������ش���һ�����﷨����
#define DKR_EPUB_PARSER_PARSESTATUS_ERR                 (DKR_EPUB_PARSER_BASEVALUE + 24L)
// û���ҵ�ҳ��Body����
#define DKR_EPUB_PARSER_PAGENOBODYCONTENT               (DKR_EPUB_PARSER_BASEVALUE + 25L)
// �����ҳ��ʧ��
#define DKR_EPUB_PARSER_SAVEPAGEBREAK_ERR               (DKR_EPUB_PARSER_BASEVALUE + 26L)
// ��ȡdata providerʧ��
#define DKR_EPUB_PARSER_GETDATAPROVIDER_ERR             (DKR_EPUB_PARSER_BASEVALUE + 27L)
// ��ȡstructure docʧ��
#define DKR_EPUB_PARSER_GETSTRUCTUREDOC_ERR             (DKR_EPUB_PARSER_BASEVALUE + 28L)
// ��ȡhtml piece infoʧ��
#define DKR_EPUB_PARSER_GETPIECEINFO_ERR                (DKR_EPUB_PARSER_BASEVALUE + 29L)
// structure docΪ��
#define DKR_EPUB_PARSER_STRUCTUREDOCEMPTY_ERR           (DKR_EPUB_PARSER_BASEVALUE + 30L)

//===========================================================================
// ��Ⱦ���ַ���ֵ������

// ��ʼ������ʧ��
#define DKR_EPUB_RENDER_INIT_ERR                        (DKR_EPUB_RENDER_BASEVALUE + 1L)
// ��������״̬�Ƿ�
#define DKR_EPUB_RENDER_STATUS_ERR                      (DKR_EPUB_RENDER_BASEVALUE + 2L)
// δ��ȷ��
#define DKR_EPUB_RENDER_OPEN_ERR                        (DKR_EPUB_RENDER_BASEVALUE + 3L)
// δ��ȷ������ʽ��Ϣ
#define DKR_EPUB_RENDER_PARSESTRUCTURE_ERR              (DKR_EPUB_RENDER_BASEVALUE + 4L)
// δ��ȷ���ɰ�ʽ��Ϣ
#define DKR_EPUB_RENDER_CREATEFIXED_ERR                 (DKR_EPUB_RENDER_BASEVALUE + 5L)
// ����outputSystem����
#define DKR_EPUB_RENDER_OUTPUTSYSTEM_ERR                (DKR_EPUB_RENDER_BASEVALUE + 6L)
// ����device����
#define DKR_EPUB_RENDER_DEVICE_ERR                      (DKR_EPUB_RENDER_BASEVALUE + 7L)
// ��ȡ��������ʧ��
#define DKR_EPUB_RENDER_FONTENGINE_ERR                  (DKR_EPUB_RENDER_BASEVALUE + 8L)
// ��ȡ�ļ�����ʧ��
#define DKR_EPUB_RENDER_GETFILE_ERR                     (DKR_EPUB_RENDER_BASEVALUE + 9L)
// ͼƬ���ʧ��
#define DKR_EPUB_RENDER_IMAGEOUTPUT_ERR                 (DKR_EPUB_RENDER_BASEVALUE + 10L)
// ��������ʧ��
#define DKR_EPUB_RENDER_PEN_ERR                         (DKR_EPUB_RENDER_BASEVALUE + 11L)
// ������ˢʧ��
#define DKR_EPUB_RENDER_BRUSH_ERR                       (DKR_EPUB_RENDER_BASEVALUE + 12L)
// ������Ⱦ·��ʧ��
#define DKR_EPUB_RENDER_PATH_ERR                        (DKR_EPUB_RENDER_BASEVALUE + 13L)

// ҳ�潻�����ַ���ֵ������
#define DKR_EPUB_INTERACT_GETSTREAM_ERR                 (DKR_EPUB_INTERACT_BASEVALUE + 1L)
#define DKR_EPUB_INTERACT_GETLINKINFO_ERR               (DKR_EPUB_INTERACT_BASEVALUE + 2L)
#define DKR_EPUB_INTERACT_LINKUNKNOWN_ERR               (DKR_EPUB_INTERACT_BASEVALUE + 3L)

// HTML��������
#define DKR_EPUB_HTMLPARSE_READCHAR_ERR                 (DKR_EPUB_HTMLPARSE_BASEVALUE + 1L)
#define DKR_EPUB_HTMLPARSE_OFFSETCONVERT_ERR            (DKR_EPUB_HTMLPARSE_BASEVALUE + 2L)
#define DKR_EPUB_HTMLPARSE_OFFSETCHECK_ERR              (DKR_EPUB_HTMLPARSE_BASEVALUE + 3L)
//===========================================================================

#endif // #__KERNEL_MOBIKIT_MOBILIB_EXPORT_DKMRETCODE_H__
