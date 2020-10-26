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
	Node* SearchResponse(string content);
};

