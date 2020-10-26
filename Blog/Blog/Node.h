#pragma once
#include <string>
#include <list>

using namespace std;
class Node
{
private:
	string m_content;
	list<Node> m_responses;

public:
	Node();
	Node(string content);
	string GetContent();
	list<Node> GetResponses();
	void InitiateContent(string content);
	void AddNewResponse(string response);
	void AddNewResponse(Node response);
	void Delete();
	Node* SearchContent(string content);
};
