#ifndef __READINGHISTORYSTAT_H__
#define __READINGHISTORYSTAT_H__

#include "singleton.h"
#include "Utility/JsonObject.h"
#include "GUI/EventArgs.h"
#include "GUI/EventSet.h"
#include "GUI/EventListener.h"
#include "Common/File_DK.h"

//���Ķ�����
#define ReadingHistoryFile "/mnt/us/system/reading.dk"
#define ReadingBooksInFile "/mnt/us/system/readingBooks.dk"
#define CompletedBooksInFile "/mnt/us/system/completedBooks.dk"

//�°���Ķ�����
#define NewReadingHistoryFile "/mnt/us/system/readingHistory.dk"

struct ReadingHistory
{
	ReadingHistory()
	{
		serverUtcTimeStamp = 0;
		totalReadingBooks = 0;
		totalSeconds = 0.0;
		totalBooks = 0;
		totalCompletedBooks = 0;
		totalDay = 0;
		rankingRatio = 0.0;
	}
	int totalReadingBooks;
	double totalSeconds;
	int totalBooks;
	int totalCompletedBooks;
	int totalDay;
	double rankingRatio;
	int serverUtcTimeStamp;
	std::vector<int> distribution;
};

struct HistortyBookInfo
{
	std::string bookID;
	std::string bookName;
	std::string bookType;
};

enum PersonalPostResult
{
	PersonalPostResult_OK,
	PersonalPostResult_Error,
	PersonalPostResult_NotLogin,
	PersonalPostResult_TimeLimit,
	PersonalPostResult_DataError
};

class PersonalReadingDataArgs: public EventArgs
{
public:
	PersonalReadingDataArgs()
	{
	}
	
	virtual EventArgs* Clone() const
	{
		return new PersonalReadingDataArgs(*this);
	}
};


class ReadingHistoryStat : public EventSet, EventListener
{
        SINGLETON_H(ReadingHistoryStat)
public:
	static const char* EventPersonalReaingDataUpdated;

public:
	


	//��ø�������(������Ϊ������������)
	bool GetReadingHistory(ReadingHistory* readingData);

	//�ϴ����ݵ�������
	PersonalPostResult PostReadingData();

	//���ط�����������
	void FetchPersonalReadingData();

	//��ĳ���鿴��ʱ���ô˺���
	bool SetBookCompleted(const char* bookID, const char* bookName, const DkFileFormat& bookType, bool isTrialBook);


	bool OnBookOpen(const char* bookID, const char* bookName, const DkFileFormat& bookType, bool isTrialBook);
	bool OnBookClose(int pagesRead);
private:
	ReadingHistoryStat();
	virtual ~ReadingHistoryStat();
    //
	//���Ķ������ǵ��ô˺�������������ظ������
	bool AddNewBook(const char* bookID, const char* bookName, const DkFileFormat& bookType);
    //
	//ͼ���ʱ���ô�ֵ
    void SetBookOpenTime(int64_t);

	//�Ķ�ͼ�����ʱ���ô�ֵ
	//������m_endTime  m_startTime ����˴��Ķ���������ʱ��ֲ�
	void SetBookCloseTime(int64_t);

	//�����Ķ���ҳ��
	bool AddCompletePageNum(int num);
	JsonObjectSPtr GetOrCreateSubObject(JsonObjectSPtr jsonObj, const char* field);
	JsonObjectSPtr CreateUserObject(const char* fileName);

	//��������Ķ�����
	bool AddNewReadSeconds(int seconds);

	//���ʱ��ֲ�
	bool UpdateDistribution(const int* distribution);

	//�����Ҫ����������ύ������
	bool AddNewBookForServer(const char* bookId, const char* title, const DkFileFormat& type);
	bool AddCompletedBookForServer(const char* bookId, const char* title, const DkFileFormat& type);

	//�������һ�δӷ������˻�ȡ�ĸ����Ķ�����
	bool UpdateLastServerData(const std::string& lastServerData, bool isGet);

	//�����ļ�
	void UpdateDataToFile(const string& fileName, JsonObjectSPtr jsonReadingData);

	//���������
	void ImportOldData();

	// ��NewReadingHistoryFile���Ϊ����ļ���ÿ���ļ����û�������
	void SplitReadingDataByUser();

	//�ж����Ķ���ʷ������еĻ������ϴ������򲻿���
	bool IsNeedToPostReadingHistory(JsonObjectSPtr jsonNewData);

	//����ϴ��󷵻�errorcode Ϊ8, ��ɾ�����ش�������
	void DeleteErrorNewData();

	// Ǩ�Ʊ��ظ��������������
	void MigrateReadingHistory(const char* account);

	void ImportNewReadBook(const std::vector<HistortyBookInfo>& bookInfo);
	void ImportCompleteBook(const std::vector<HistortyBookInfo>& bookInfo);

	std::string GetBookStringFormat(DkFileFormat bookFormat);

	bool OnGetUpdateServerReadingData(const EventArgs& args);
	bool OnPostUpdateServerReadingData(const EventArgs& args);
	bool OnWifiAvailableEvent(const EventArgs& args);

private:
	//��UTC ʱ�䣬����ϵͳ���������ڵ�ʱ�䣬����Ϊ��λ
	int64_t m_startTime;
	int64_t m_endTime;
	int64_t m_lastUploadTime;
	pthread_mutex_t m_lock;
};

#endif

