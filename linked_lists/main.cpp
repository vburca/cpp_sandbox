#include <iostream>
#include <string>

#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int>* my_list = new LinkedList<int>();

    my_list->InsertFront(6);
    my_list->Print("Insert front 6");

    my_list->InsertFront(3);
    my_list->Print("Insert front 3");

    my_list->InsertRear(7);
    my_list->Print("Insert rear 7");

    my_list->InsertAt(4, 1);
    my_list->Print("Insert at index 1, 4");

    my_list->InsertAt(1, 0);
    my_list->Print("Insert at index 0, 1");

    my_list->InsertAt(8, 5);
    my_list->Print("Insert at index 5, 8");

    my_list->InsertAt(10, 10);
    my_list->Print("Insert at index 10, 10");

    my_list->DeleteAt(5);
    my_list->Print("Delete from index 5");

    my_list->DeleteAt(0);
    my_list->Print("Delete from index 0");

    my_list->DeleteAt(1);
    my_list->Print("Delete from index 1");

    int element = 7;
    int i = my_list->FindFirstElement(element);
    cout << "First index of element " << element << " is " << i << endl << endl;

    int size = my_list->GetSize();
    cout << "Size of my list: " << size << endl << endl;

    my_list->Reverse();
    my_list->Print("Reversed list");

    my_list->InsertFront(21);
    my_list->Print("Insert at front of reversed 21");

    my_list->InsertRear(91);
    my_list->Print("Insert at rear of reversed 91");

    my_list->InsertAt(11, 2);
    my_list->Print("Insert at index 2 of reversed, 11");

    my_list->Reverse();
    my_list->Print("Reversed list again");

    return 0;
}