#include "HSubject.h"

int HSubject::h1(string subject)
{
	return 0;
}

int HSubject::h2(string subject, int i)
{
	return i;
}

void HSubject::PrintSubjectForumList(string subject)
{
	int index = Search(subject);
	if (index != -1)
	{
		m_Table[index].data.PrintAllDiscussion();
	}
}

void HSubject::AddNewDiscussion(string subject, string title)
{
	int index = Search(subject);
	if (index != -1)
	{
		m_Table[index].data.NewDiscussion(title);
	}
	else
	{
		index = Insert(Item<ForumList, string>(ForumList(), subject));
		m_Table[index].data.NewDiscussion(title);
	}
}

void HSubject::RemoveDiscussion(string subject)
{
	Remove(subject);
}

bool HSubject::PrintNDiscussions(string subject, int num)
{
	int index = Search(subject);
	if (index != -1)
	{
		m_Table[index].data.PrintNFirstDiscussions(num);
		return true;
	}
	return false;
}

bool HSubject::PrintTitles(string subject)
{
	int index = Search(subject);
	if (index != -1)
	{
		m_Table[index].data.PrintTitles();
		return true;
	}
	return false;
}

void HSubject::Reset()
{
	delete[] m_Table;
	m_Table = new Item<ForumList, string>[m_realSize];
}

void HSubject::Print()
{
	for (int i = 0; i < m_realSize; i++)
	{
		if (m_Table[i].flag == eFull)
		{
			cout << m_Table[i].key << ":" << endl;
			m_Table[i].data.PrintAllDiscussion();
			cout << endl;
		}
	}
}
