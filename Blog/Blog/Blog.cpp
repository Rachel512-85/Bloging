//Rachel Ankonina
//313132375
//Sara Amsalem
//316375880
#include <iostream>
#include <list>
#include <string>
#include "ForumList.h"
#include "HSubject.h"



using namespace std;
int main()
{
	char ch;
	int n;
	HSubject hs(1000);
	string subject, title;
	cout << "Hash Table\n";
	cout << "\nChoose one of the following" << endl;
	cout << "n: New hash table" << endl;
	cout << "a: Add a subject and a title" << endl;
	cout << "d: Del a subject " << endl;
	cout << "t: print all titles of the subject " << endl;
	cout << "s: print N first appearances of a subect " << endl;
	cout << "p: print all non-empty entries " << endl;
	cout << "e: Exit" << endl;

	do
	{
		cin >> ch;
		switch (ch)
		{

		case 'n':hs.Reset(); break;
		case 'a':cout << "Enter a subject and a title\n";
			cin >> subject >> title;
			hs.AddNewDiscussion(subject, title);
			break;
		case 'd':cout << "Enter a subject to remove\n";
			cin >> subject;
			hs.RemoveDiscussion(subject); break;
		case 't':cout << "enter subject to print\n";
			cin >> subject;
			if(!hs.PrintTitles(subject)) cout << "ERROR\n"; break;
		case 's':cout << "enter a subject and N\n"; cin >> subject >> n;
			if(!hs.PrintNDiscussions(subject, n)) cout << "ERROR\n"; break;
		case 'e':cout << "bye\n"; break;
		case 'p':hs.Print(); break;
		default: cout << "ERROR\n";  break;
		}
	} while (ch != 'e');

}