#include "HuffmanCode.h"
#define MAX_SIZE 50

void HuffmanCode::Encode(string word)
{
	//building the priority queue
	BuildPriorityQueue(word);

	//build the tree and his structure string
	BuildTreeFromPriorityQueue();
	BuildTreeStructure(m_HuffmanTree);

	//find the code of each letter
	string code = "";
	GetTreeCodes(m_HuffmanTree, code, word);	

	//print the output - number of leaves, order of letters, tree structure and the encoded text
	cout << "The encoded string is:" << endl;
	cout << m_chars.length() << endl;
	cout << m_chars << endl;
	cout << m_treeStructure << endl;
	cout << word << endl;

	Reset();
}

void HuffmanCode::Decode(int n, string chars, string treeStructure, string word)
{
	//notice - there is exceptional case when there is only one character in the tree
	if (chars.length() > 1)
	{
		//initiate the class members with input data
		m_HuffmanTree = new HuffmanNode();
		m_chars = chars;
		m_treeStructure = treeStructure;

		//build the Huffman Tree according to the tree strcture.  put the letters in the leaves according to the given order.
		BuildTreeFromStructureString(m_HuffmanTree);

		//decode the word according the huffman tree, find the original text
		cout << "The decoded string is:" << endl;
		HuffmanNode* ptr = m_HuffmanTree;
		for (string::iterator it = word.begin(); it != word.end(); it++)
		{
			if (ptr->m_left == NULL)
				ptr = m_HuffmanTree;

			if (*it == '0')
				ptr = ptr->m_left;
			else if (*it == '1')
				ptr = ptr->m_right;
			cout << ptr->m_str;
		}
	}
	else
	{
		cout << "The decoded string is:" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << chars[0];
		}
	}
	cout << endl;

	Reset();
}

void HuffmanCode::BuildTreeFromStructureString(HuffmanNode* tree)
{
	if (m_treeStructure == "")
		return;
	if (m_treeStructure[0] == '0')
	{
		tree->m_left = new HuffmanNode();
		tree->m_right = new HuffmanNode();
	}
	else if (m_treeStructure[0] == '1')
	{
		tree->m_str = m_chars[0];
		m_chars.erase(0, 1);
		m_treeStructure.erase(0, 1);
		return;
	}
	m_treeStructure.erase(0, 1);
	BuildTreeFromStructureString(tree->m_left);
	BuildTreeFromStructureString(tree->m_right);
}

void HuffmanCode::BuildPriorityQueue(string word)
{
	char freq[MAX_SIZE] = { 0 };
	//memset(freq, 0, sizeof(freq));
	//get the frequency of each letter
	for (string::iterator it = word.begin(); it != word.end(); it++)
	{
		if(m_chars.find(*it) == -1)
			m_chars.push_back(*it);
		freq[m_chars.find(*it)]++;
	}

	//enter the frequncies to the queue
	for (int i = 0; freq[i] > 0; i++)
	{
		if (freq[i])
		{
			char str = m_chars[i];
			HuffmanNode* node = new HuffmanNode(str, freq[i]);
			m_pQueue.push(node);
		}
	}
	m_chars = "";
}

void HuffmanCode::BuildTreeFromPriorityQueue()
{
	while (m_pQueue.size() > 1)
	{
		HuffmanNode* left = m_pQueue.top();
		m_pQueue.pop();
		HuffmanNode* right = m_pQueue.top();
		m_pQueue.pop();

		HuffmanNode* node = new HuffmanNode('\0', left->m_frequency + right->m_frequency);
		node->m_left = left;
		node->m_right = right;
		m_pQueue.push(node);
	}

	m_HuffmanTree = m_pQueue.top();
}

void HuffmanCode::BuildTreeStructure(HuffmanNode* tree)
{
	if (tree == NULL)
		return;

	if (tree->m_left)
	{
		m_treeStructure.push_back('0');
		BuildTreeStructure(tree->m_left);
		BuildTreeStructure(tree->m_right);
	}
	else
	{
		m_treeStructure.push_back('1');
		m_chars.push_back(tree->m_str[0]);
	}
}

void HuffmanCode::GetTreeCodes(HuffmanNode* tree, string code, string& word)
{
	if (tree->m_left)
	{
		code.push_back('0');
		GetTreeCodes(tree->m_left, code, word);
		code.erase(code.size() - 1);
	}

	if (tree->m_right)
	{
		code.push_back('1');
		GetTreeCodes(tree->m_right, code, word);
		code.erase(code.size() - 1);
	}

	if (!tree->m_left && !tree->m_right)
	{
		size_t pos;
		while ((pos = word.find(tree->m_str)) != std::string::npos) {
			word.replace(pos, 1, code);
		}
	}


	
}

void HuffmanCode::Reset()
{
	//empty the queue before we start again
	while (m_pQueue.size() != 0)
	{
		HuffmanNode* tmp = m_pQueue.top();
		m_pQueue.pop();
		delete tmp;
	}

	m_treeStructure = "";
	m_chars = "";
}
