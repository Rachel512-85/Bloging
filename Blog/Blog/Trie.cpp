#include "Trie.h"

Trie::Trie()
{
	m_root = new TrieNode();
	m_root->m_Father = NULL;
	m_root->m_IsEndWord = false;
}

void Trie::InsertWord(string str)
{
	TrieNode* ptr = m_root;
	//run over the string and enter the new letters to the trie
	for (int i = 0; i < str.length(); i++)
	{
		if (ptr->m_Children[str[i] - 'a'] == NULL)
		{
			ptr->m_Children[str[i] - 'a'] = new TrieNode();
			ptr->m_Children[str[i] - 'a']->m_Father = ptr;
			ptr->m_Children[str[i] - 'a']->m_IsEndWord = false;
		}
		ptr = ptr->m_Children[str[i] - 'a'];
	}
	//mark the last letter as end of the word
	ptr->m_IsEndWord = true;
}

bool Trie::DeleteWord(string str)
{
	TrieNode* ptr = m_root;
	//run over the string till the end of the word if exist
	for (int i = 0; i < str.length(); i++)
	{
		if (ptr->m_Children[str[i] - 'a'] == NULL)
			return false;
		ptr = ptr->m_Children[str[i] - 'a'];
	}
	if (ptr->m_IsEndWord == false)
		return false;
	for (int i = str.length() - 1; ptr != m_root; i--)
	{
		bool isOfAnotherWord = false;
		for (int i = 0; i < ALPHABET && isOfAnotherWord == false; i++)
		{
			if (ptr->m_Children[i])
				isOfAnotherWord = true;
		}
		//end of the word to delete but also middle of another
		if (isOfAnotherWord && i == str.length() - 1)
			ptr->m_IsEndWord = false;
		//if the middle or the end of another word - finish delete process
		if (isOfAnotherWord || (ptr->m_IsEndWord && i != str.length() - 1))
			return true;
		//keep temporary the pointer to this node for deleting it later
		TrieNode* tmp = ptr;
		ptr = ptr->m_Father;
		ptr->m_Children[str[i] - 'a'] = NULL;
		//delete the letter from this word
		delete tmp;
	}
	return true;
}

bool Trie::SearchWord(string str)
{
	TrieNode* ptr = m_root;
	//run over the string till the end of the word if exist
	for (int i = 0; i < str.length(); i++)
	{
		if (ptr->m_Children[str[i] - 'a'] == NULL)
			return false;
		ptr = ptr->m_Children[str[i] - 'a'];
	}
	return ptr->m_IsEndWord;
}

int Trie::PrintAllWordsFromPrefix(string str)
{
	TrieNode* ptr = m_root;
	//run over the string till the end
	for (int i = 0; i < str.length(); i++)
	{
		if (ptr->m_Children[str[i] - 'a'] == NULL)
			return 0;
		ptr = ptr->m_Children[str[i] - 'a'];
	}
	return PrintAllWordsFromPrefix(str, ptr);
}

int Trie::PrintAllWordsFromPrefix(string str, TrieNode* node)
{
	int sumOfWords = 0;
	if (node->m_IsEndWord)
	{
		cout << str << endl;
		sumOfWords += 1;
	}

	for (int i = 0; i < ALPHABET; i++)
	{
		if (node->m_Children[i])
		{
			str += (char)(i + 'a');
			sumOfWords += PrintAllWordsFromPrefix(str, node->m_Children[i]);
			str.erase(str.size() - 1);
		}
	}
	return sumOfWords;
}
