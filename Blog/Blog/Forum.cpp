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

Node* Forum::SearchResponse(string content)
{
	return m_discussion->SearchContent(content);
}
