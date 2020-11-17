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
	m_list.push_front(newForum);
}

void ForumList::NewDiscussion(string content)
{
	Forum newForum;
	m_list.push_front(newForum);
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

bool ForumList::PrintResponseAncestors(string content)
{
	bool isPrinted = false;
	// Iterate over the list
	for (list<Forum>::iterator it = m_list.begin(); it != m_list.end(); it++)
	{
		if ((*it).SearchContent(content))
		{
			(*it).PrintResponseDiscussion(content);
			if ((*it).GetDiscussionTree()->GetContent() != content)
				(*it).PrintResponseAncestors(content);
			isPrinted = true;
		}
	}
	return isPrinted;
}

bool ForumList::AddResponse(string startContent, string responseTo, string myResponse)
{
	// Iterate over the list
	for (list<Forum>::iterator it = m_list.begin(); it != m_list.end(); it++)
		if ((*it).GetDiscussionTree()->GetContent() == startContent)
		{
			if ((*it).AddSon(myResponse, responseTo))
				return true;
		}
	return false;
}

bool ForumList::DeleteResponse(string startContent, string response)
{
	// Iterate over the list
	for (list<Forum>::iterator it = m_list.begin(); it != m_list.end(); it++)
	{
		if ((*it).GetDiscussionTree()->GetContent() == startContent)
		{
			if (startContent == response)
			{
				m_list.erase(it);
				return true;
			}
			else if ((*it).DeleteResponse(response))
				return true;
		}
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

void ForumList::PrintSubDiscussion(string firstContent, string response)
{
	// Iterate over the list
	for (list<Forum>::iterator it = m_list.begin(); it != m_list.end(); it++)
		if ((*it).GetDiscussionTree()->GetContent() == firstContent)
		{
			(*it).PrintResponseDiscussion(response);
			if(firstContent != response)
				(*it).PrintResponseAncestors(response);
		}
}

void ForumList::PrintAllDiscussion()
{
	int counter = 1;
	// Iterate over the list
	for (list<Forum>::iterator it = m_list.begin(); it != m_list.end(); it++)
	{
		//std::cout << "Tree #" << counter++ << std::endl;
		(*it).PrintDiscussion();
	}
}

void ForumList::PrintNFirstDiscussions(int n)
{
	int counter = 1;
	// Iterate over the list
	for (list<Forum>::iterator it = m_list.begin(); it != m_list.end(); it++)
	{
		if (counter > n)
			return;
		(*it).PrintDiscussion();
		counter++;
	}
}

void ForumList::PrintTitles()
{
	int counter = 1;
	// Iterate over the list
	for (list<Forum>::iterator it = m_list.begin(); it != m_list.end(); it++)
	{
		//std::cout << "Title #" << counter++ << std::endl;
		std::cout << (*it).GetDiscussionTree()->GetContent() << std::endl;
	}
}
