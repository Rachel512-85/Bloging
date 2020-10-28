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
	void DeleteResponse(string content);
	void PrintAncestors(string content, string levelsSpace = "");
};

