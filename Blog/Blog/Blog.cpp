//Rachel Ankonina
//313132375
#include <iostream>
#include <list>
#include <string>
#include "ForumList.h"

using namespace std;
int main()
{
	ForumList tl;
	string title, father, val, son;
	char ch;
	cout << "\nDISCUSSION TREE\n";
	cout << "Choose one of the following:" << endl;
	cout << "n: New discussion tree" << endl;
	cout << "s: Add a new response" << endl;
	cout << "d: Delete a sub-discussion" << endl;
	cout << "p: Print all discussion trees" << endl;
	cout << "r: Print a sub-tree" << endl;
	cout << "w: Search a string in all discussion trees" << endl;
	cout << "e: exit:" << endl;
	do
	{
		cin >> ch;
		switch (ch)
		{
		case 'n':cout << "enter the discussion title (with no space) "; cin >> val; tl.NewDiscussion(val); break;
		case 's':cout << "enter the discussion title (with no space) "; cin >> title;
			cout << "enter the last message (with no space) "; cin >> father;
			cout << "enter the new respond "; cin >> son;
			if (tl.AddResponse(title, father, son)) cout << "success\n"; else cout << "ERROR\n"; break;
		case 'd':cout << "enter the discussion title (with no space) "; cin >> title;
			cout << "enter string of subtree to delete (with no space) "; cin >> val;
			if (tl.DeleteResponse(title, val)) cout << "success\n"; else cout << "ERROR\n"; break;
		case 'p':tl.PrintAllDiscussion();  break;
		case 'r':
			cout << "enter the discussion title (with no space) "; cin >> title;
			cout << "enter the last message (with no space) "; cin >> val;
			tl.PrintSubDiscussion(title, val); cout << endl;  break;
		case 'w':cout << "enter a string (with no space) "; cin >> val;
			if (tl.PrintResponseAncestors(val)) cout << "\n"; else cout << "ERROR\n"; break;
		case 'e':cout << "bye "; break;
		default: cout << "ERROR\n";  break;
		}
	} while (ch != 'e');
}