#pragma once
#include <queue>
#include "HuffmanNode.h"

class HuffmanCode
{

public:
	void Encode(string word);
	void Decode(int n, string chars, string treeStructure, string word);

private:
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNode> m_pQueue;
	HuffmanNode* m_HuffmanTree;
	string m_chars, m_treeStructure;

	void BuildTreeFromStructureString(HuffmanNode* tree);
	void BuildPriorityQueue(string word);
	void BuildTreeFromPriorityQueue();
	void BuildTreeStructure(HuffmanNode* tree);
	void GetTreeCodes(HuffmanNode* tree, string code, string& word);
	void Reset();
};

