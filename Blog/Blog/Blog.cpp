// Blog.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Forum.h"

using namespace std;
int main()
{
    Forum f;
    f.StartDiscussion("hello how are you?");
    //string m_content = "hello how are you?";
    //int size = sizeof("hello how are you?");
    //int find = m_content.find("hello how are you?1");
    //if (find != -1)
    //    return 0;
    f.AddSon("fine1 thanks", "hello how are you?");
    f.AddSon("fine2 thanks", "hello how are you?");
    f.AddSon("fine3 thanks", "hello how are you?");
    f.AddSon("fine4 thanks", "hello how are you?");
    f.AddSon("fine5 thanks", "hello how are you?");
    f.AddSon("fine6 thanks", "hello how are you?");
    f.AddSon("fine7 thanks", "hello how are you?");
    f.AddSon("fine8 thanks", "hello how are you?");
    f.AddSon("fine9 thanks", "hello how are you?");
    f.AddSon("fine0 thanks", "hello how are you?");
    f.AddSon("wow I am happy you are", "fine4 thanks");
    f.AddSon("wow I am happy you are", "fine7 thanks");
    f.PrintDiscussion();
    f.DeleteResponse("wow I am happy you are");
    f.PrintDiscussion();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
