//Rachel Ankonina
//313132375
//Sara Amsalem
//316375880
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "HuffmanCode.h"


int main()
{
	char choice;
	string word, chars, treeStructure;
	int n;

	HuffmanCode* t = new HuffmanCode();
	cout << "enter 1 to encode a text\n";
	cout << "enter 2 to decode a text\n";
	cout << "enter 3 to exit\n";

	do
	{
		cin >> choice;
		switch (choice)
		{
		case '1':

			cout << "enter the original text" << endl;
			cin >> word;

			//Build Huffman tree given the data inside "word".
			t->Encode(word);
			break;

		case '2':
			//input the number of leaves
			cout << "enter n ";
			cin >> n;
			//input the order of letters
			cout << "enter the letters ";
			cin >> chars;
			//input the tree structure
			cout << "enter the encoded structure ";
			cin >> treeStructure;
			//input the encoded text.
			cout << "enter the encoded text ";
			cin >> word;
			t->Decode(n, chars, treeStructure, word);
			break;

		case '3':/*cout << "bye " << endl;*/ break;

		default: cout << "ERROR " << endl;  break;
		}

	} while (choice != '3');
	return 0;
}