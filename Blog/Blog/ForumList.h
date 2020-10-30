#pragma once
#include "Forum.h"

class ForumList
{
private:
	list<Forum> m_list;

public:
	ForumList();
	~ForumList();
	void NewDiscussion();
	void NewDiscussion(string content);
	void DeleteDiscussion(Node* discussion);
	bool PrintResponseAncestors(string content);
	bool AddResponse(string firstContent, string responseTo, string myResponse);
	bool DeleteResponse(string firstContent, string response);
	void PrintDiscussion(string firstContent);
	void PrintSubDiscussion(string firstContent, string resonse);
	void PrintAllDiscussion();
};

