

#include<stdio.h>
#include <libxml/HTMLparser.h>
#include<libxml/xpath.h>
xmlXPathObjectPtr getNodeSet(xmlDocPtr doc, const xmlChar *szXpath)
{
    if(doc == NULL || szXpath == NULL)
    {
        return NULL;
    }
    xmlXPathContextPtr context = NULL;    //XPATH������ָ��
    xmlXPathObjectPtr result = NULL;       //XPATH����ָ�룬�����洢��ѯ���
    context = xmlXPathNewContext(doc);     //����һ��XPath������ָ��

    if (context == NULL)
    {
       return NULL;
    }

    result = xmlXPathEvalExpression(szXpath, context); //��ѯXPath���ʽ���õ�һ����ѯ���
    xmlXPathFreeContext(context);             //�ͷ�������ָ��

    if (result == NULL)
    {
       return NULL;
    }

    if (xmlXPathNodeSetIsEmpty(result->nodesetval))   //����ѯ����Ƿ�Ϊ��
    {
       xmlXPathFreeObject(result);
       return NULL;
    }

    return result;
}

