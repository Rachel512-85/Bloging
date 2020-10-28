#pragma once
#include "Node.h"

class Forum
{
private:
	Node* m_discussion;

public:
	Forum();
	~Forum();
	void StartDiscussion(string content);
	Node* SearchContent(string content);
	void AddSon(string content, string ancestorContent);
	void DeleteResponse(string content);
	void PrintDiscussion();
	void PrintResponseDiscussion(string content);
	void PrintResponseAncestors(string content);
};

