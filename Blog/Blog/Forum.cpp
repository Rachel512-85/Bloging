#include "Forum.h"

Forum::Forum()
{
	m_discussion = new Node();
}

Forum::~Forum()
{
	m_discussion->Delete();
	m_discussion = nullptr;
}

void Forum::StartDiscussion(string content)
{
	m_discussion->InitiateContent(content);
}

Node* Forum::SearchContent(string content)
{
	return m_discussion->SearchContent(content);
}

void Forum::AddSon(string content, string ancestorContent)
{
	Node* ancestor = SearchContent(ancestorContent);
	if(ancestor)
		ancestor->AddNewResponse(content);
}

void Forum::DeleteResponse(string content)
{
	m_discussion->DeleteResponse(content);
}

void Forum::PrintDiscussion()
{
	m_discussion->Print();
}

void Forum::PrintDiscussionResponse(string content)
{
	SearchContent(content)->Print();
}
