#pragma once
#define ALPHABET 26
#include <string>
#include <iostream>

using namespace std;
class Trie
{
protected:
	class TrieNode
	{
	public:
		TrieNode* m_Children[ALPHABET] = { 0 };
		TrieNode* m_Father;
		bool m_IsEndWord;

	public:
		TrieNode() {}
	};
	TrieNode* m_root;

public:
	Trie();
	void InsertWord(string str);
	bool DeleteWord(string str);
	bool SearchWord(string str);
	int PrintAllWordsFromPrefix(string str);

private:
	int PrintAllWordsFromPrefix(string str, TrieNode* node);
};

