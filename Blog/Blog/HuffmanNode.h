#pragma once
#include <string>
#include <iostream>

using namespace std; 
class CompareNode;
class HuffmanNode
{
	friend CompareNode;
public:
	HuffmanNode();
	HuffmanNode(char str, int frequency);
	~HuffmanNode();

public:
	string m_str;
	int m_frequency;
	HuffmanNode* m_left;
	HuffmanNode* m_right;

};

class CompareNode
{

public:
	 bool operator()(HuffmanNode* const& n1, HuffmanNode* const& n2);
};

