#pragma once
#include "Node.h"

class Forum
{
private:
	Node* m_discussion;

public:
	Forum();
	~Forum();
	Node* GetDiscussionTree();
	void StartDiscussion(string content);
	Node* SearchContent(string content);
	bool AddSon(string content, string ancestorContent);
	bool DeleteResponse(string content);
	void PrintDiscussion();
	void PrintResponseDiscussion(string content);
	void PrintResponseAncestors(string content);
};

