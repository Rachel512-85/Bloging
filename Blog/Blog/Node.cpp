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
	if (m_content.find(content, sizeof(content)) != -1)
		return this;

	// Iterate over the list and search content
	for (Node val : m_responses)
		if (val.SearchContent(content))
			return &val;

	return nullptr;
}
