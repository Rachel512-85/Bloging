#pragma once
#include <string>
#include <list>
#include <iostream>

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
	void Print(string levelsSpace = "");
	bool DeleteResponse(string content);
	bool PrintAncestors(string content, string levelPointer = "\n");
};

