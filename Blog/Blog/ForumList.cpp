#include "ForumList.h"

ForumList::ForumList()
{
}

ForumList::~ForumList()
{
	m_list.clear();
}

void ForumList::NewDiscussion()
{
	Forum newForum;
	m_list.push_back(newForum);
}

void ForumList::NewDiscussion(string content)
{
	Forum newForum;
	m_list.push_back(newForum);
	newForum.StartDiscussion(content);
}

void ForumList::DeleteDiscussion(Node* discussion)
{
	// Iterate over the list and search content
	list<Forum>::iterator it = m_list.begin();
	while (it != m_list.end())
		if ((*it).GetDiscussionTree() == discussion)
			m_list.erase(it++);
		else
			it++;
}

void ForumList::PrintResponseAncestors(string content)
{
	// Iterate over the list
	for (list<Forum>::iterator it = m_list.begin(); it != m_list.end(); it++)
		(*it).PrintResponseAncestors(content);
}

bool ForumList::AddResponse(string startContent, string responseTo, string myResponse)
{
	// Iterate over the list
	for (list<Forum>::iterator it = m_list.begin(); it != m_list.end(); it++)
		if ((*it).GetDiscussionTree()->GetContent() == startContent)
		{
			(*it).AddSon(myResponse, responseTo);
			return true;
		}
	return false;
}

bool ForumList::DeleteResponse(string startContent, string response)
{
	// Iterate over the list
	for (list<Forum>::iterator it = m_list.begin(); it != m_list.end(); it++)
		if ((*it).GetDiscussionTree()->GetContent() == startContent)
		{
			(*it).DeleteResponse(response);
			return true;
		}
	return false;
}

void ForumList::PrintDiscussion(string startContent)
{
	// Iterate over the list
	for (list<Forum>::iterator it = m_list.begin(); it != m_list.end(); it++)
		if ((*it).GetDiscussionTree()->GetContent() == startContent)
			(*it).PrintDiscussion();
}

void ForumList::PrintSubDiscussion(string firstContent, string resonse)
{
	// Iterate over the list
	for (list<Forum>::iterator it = m_list.begin(); it != m_list.end(); it++)
		if ((*it).GetDiscussionTree()->GetContent() == firstContent)
			(*it).PrintResponseDiscussion(resonse);
}

void ForumList::PrintAllDiscussion()
{
	// Iterate over the list
	for (list<Forum>::iterator it = m_list.begin(); it != m_list.end(); it++)
		(*it).PrintDiscussion();
}
