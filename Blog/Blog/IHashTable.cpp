//#include "IHashTable.h"
//template <class T, class K>
//IHashTable < T,K > ::IHashTable(int size)
//{
//    m_realSize = FindPrimeNumber(size);
//    m_Table = new Item<T, K>[m_realSize];
//}
//
//template <class T, class K>
//IHashTable< T,K >::~IHashTable()
//{
//    delete m_Table;
//}
//
//template <class T, class K>
//int IHashTable< T, K >::FindPrimeNumber(int size)
//{
//    bool flag = true;
//
//    for (int i = size; ; i++)
//    {
//        flag = true;
//        for (int j = 2; j <= i / 2; j++)
//        {
//            if (i % j == 0)
//            {
//                flag = false;
//                break;
//            }
//        }
//        if (flag)
//            return i;
//    }
//
//    return 0;
//}
//
//template<class T, class K>
//int IHashTable<T, K>::Hash(K key, int i)
//{
//    return (h1(key) + i*h2(key)) % m_realSize;
//}
//
//template<class T, class K>
//int IHashTable<T, K>::Search(K key)
//{
//    for (int i = 0; m_Table[Hash(key, i)].flag != state::empty ; i++)
//    {
//        if (m_Table[Hash(key, i)].key == key)
//            return Hash(key, i);
//    }
//    return -1;
//}
//
//template<class T, class K>
//int IHashTable<T, K>::Insert(Item<T, K> val)
//{
//    int index = Hash(val.key, 0);
//    for (int i = 0; m_Table[index].flag == state::full; index = Hash(val.key, ++i));
//    m_Table[index] = val;
//    return index;
//}
//
//template<class T, class K>
//void IHashTable<T, K>::Remove(K key)
//{
//    int index = Search(key);
//    if (index != -1)
//    {
//        m_Table[index].flag = state::deleted;
//    }
//}
//
//template<class T, class K>
//bool IHashTable<T, K>::Update(int index, Item<T, K> val)
//{
//    if (m_Table[index].key == val.key)
//    {
//        m_Table[index] = val;
//        return true;
//    }
//    return false;
//}
//
//template<class T, class K>
//void IHashTable<T, K>::Print()
//{
//}
