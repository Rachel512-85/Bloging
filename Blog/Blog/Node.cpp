#include "Node.h"

Node::Node()
{
}

Node::Node(string content)
{
	m_content = content;
}

string Node::GetContent()
{
	return m_content;
}

list<Node> Node::GetResponses()
{
	return m_responses;
}

void Node::InitiateContent(string content)
{
	m_content = content;
	m_responses.clear();
}

void Node::AddNewResponse(string response)
{
	if(m_content != "")
		m_responses.push_back(Node(response));
}

void Node::AddNewResponse(Node response)
{
	if (m_content != "")
		m_responses.push_back(response);
}

void Node::Delete()
{
	m_responses.clear();
}

Node* Node::SearchContent(string content)
{
	if (m_content.find(content) != -1)
		return this;

	// Iterate over the list and search content
	for (list<Node>::iterator it = m_responses.begin(); it != m_responses.end(); it++)
	{
		if ((*it).SearchContent(content))
			return &(*it);
	}

	return nullptr;
}

void Node::Print(string levelsSpace)
{
	std::cout << levelsSpace << m_content << std::endl;

	// Iterate over the list and print content
	for (Node val : m_responses)
		val.Print(levelsSpace + "   ");
}

void Node::DeleteResponse(string content)
{
	// Iterate over the list and search content
	for (list<Node>::iterator it = m_responses.begin(); it != m_responses.end(); it++)
	{
		if ((*it).GetContent().find(content) != -1)
		{
			(*it).Delete();
			m_responses.remove(*it);
		}
		else
			(*it).DeleteResponse(content);
	}
}
