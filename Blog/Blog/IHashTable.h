#pragma once
#include <iostream>

enum state { eEmpty, eFull, eDeleted };
template <class T, class K>
class Item
{
public:
	T data;
	K key;
	state flag;// = empty;
	Item() { flag = eEmpty; }
	Item(T d, K k, state f = eFull) { data = d; key = k; flag = f; }
};

template <class T, class K>
class IHashTable
{
protected:
	Item<T,K>* m_Table;
	int m_realSize;// = 0;

	virtual int h1(K key) = 0;
	virtual int h2(K key, int i) = 0;

public:

	IHashTable(int size) {
		m_realSize = FindPrimeNumber(size);
		m_Table = new Item<T, K>[m_realSize];
	};
	virtual ~IHashTable() { delete[] m_Table; };
	virtual int FindPrimeNumber(int size) {
		bool flag = true;

		for (int i = size; ; i++)
		{
			flag = true;
			for (int j = 2; j <= i / 2; j++)
			{
				if (i % j == 0)
				{
					flag = false;
					break;
				}
			}
			if (flag)
				return i;
		}

		return 0;
	};
	virtual int Hash(K key, int i) {
		return (h1(key) + i * h2(key,i)) % m_realSize;
	};
	virtual int Search(K key) {
		for (int i = 0; m_Table[Hash(key, i)].flag != eEmpty; i++)
		{
			if (m_Table[Hash(key, i)].key == key)
				return Hash(key, i);
		}
		return -1;
	};
	virtual int Insert(Item<T, K> val) {
		int index = Hash(val.key, 0);
		for (int i = 0; m_Table[index].flag == eFull; index = Hash(val.key, ++i));
		m_Table[index] = val;
		return index;
	};
	virtual void Remove(K key) {
		int index = Search(key);
		if (index != -1)
		{
			m_Table[index].flag = eDeleted;
		}
	};
	virtual bool Update(int index, Item<T, K> val) {
		if (m_Table[index].key == val.key)
		{
			m_Table[index] = val;
			return true;
		}
		return false;
	};
	virtual void Print() {};
};

