#pragma once
#include <string>
#include "ForumList.h"
#include "IHashTable.h"

class HSubject :public IHashTable<ForumList, string>
{
private:

	int h1(string subject);
	int h2(string subject, int i);

public:
	HSubject(int size) :IHashTable(size) {};
	void PrintSubjectForumList(string subject);
	void AddNewDiscussion(string subject, string title);
	void RemoveDiscussion(string subject);
	bool PrintNDiscussions(string subject, int num);
	bool PrintTitles(string subject);
	void Reset();
	void Print();// override;
};

