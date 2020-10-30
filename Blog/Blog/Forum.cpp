#include "Forum.h"

Forum::Forum()
{
	m_discussion = new Node();
}

Forum::~Forum()
{
	m_discussion->Delete();
	m_discussion = NULL;// nullptr;
}

Node* Forum::GetDiscussionTree()
{
	return m_discussion;
}

void Forum::StartDiscussion(string content)
{
	m_discussion->InitiateContent(content);
}

Node* Forum::SearchContent(string content)
{
	return m_discussion->SearchContent(content);
}

bool Forum::AddSon(string content, string ancestorContent)
{
	Node* ancestor = SearchContent(ancestorContent);
	if (ancestor)
	{
		ancestor->AddNewResponse(content);
		return true;
	}
	return false;
}

bool Forum::DeleteResponse(string content)
{
	return m_discussion->DeleteResponse(content);
}

void Forum::PrintDiscussion()
{
	m_discussion->Print();
}

void Forum::PrintResponseDiscussion(string content)
{
	Node* ancestor = SearchContent(content);
	if (ancestor)
	{
		ancestor->Print();
	}
}

void Forum::PrintResponseAncestors(string content)
{
	m_discussion->PrintAncestors(content);
}
