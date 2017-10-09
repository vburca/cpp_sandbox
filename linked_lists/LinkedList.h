#pragma once

#include <iostream>
#include <string>

#include "Node.h"

template <class T>
class LinkedList
{
public:
    LinkedList(Node<T>* h = nullptr, Node<T>* t = nullptr);
    ~LinkedList();

    void InsertFront(const T d);
    void InsertRear(const T d);
    void InsertAt(const T d, const int index);
    void DeleteAt(const int index);
    void DeleteAll(const T d);
    int FindFirstElement(const T d);
    int* FindElement(const T d);

    int GetSize();
    void Print();
    void Print(std::string s);
    void Reverse();

private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};

template <class T>
LinkedList<T>::LinkedList(Node<T>* h, Node<T>* t)
{
    this->head = h;
    this->tail = t;
    this->size = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* curr = this->head;

    while (curr != nullptr)
    {
        Node<T>* temp = curr->GetNext();
        delete curr;
        curr = temp;
    }
}

template <class T>
void LinkedList<T>::InsertFront(const T d)
{
    Node<T>* new_node = new Node<T>(d);
    if (this->head == nullptr)
    {
        this->head = new_node;
        this->tail = this->head;
    }
    else
    {
        new_node->SetNext(this->head);
        this->head = new_node;
    }

    this->size += 1;
}

template <class T>
void LinkedList<T>::InsertRear(const T d)
{
    Node<T>* new_node = new Node<T>(d);
    if (this->tail == nullptr)
    {
        this->head = new_node;
        this->tail = this->head;
    }
    else
    {
        this->tail->SetNext(new_node);
        this->tail = new_node;
    }

    this->size += 1;
}

template <class T>
void LinkedList<T>::InsertAt(const T d, const int index)
{
    if (index > size || index < 0)
    {
        return;
    }

    if (index == 0)
    {
        this->InsertFront(d);
    }
    else if (index == size)
    {
        this->InsertRear(d);
    }
    else
    {
        Node<T>* new_node = new Node<T>(d);
        Node<T>* curr = this->head;
        int i = 0;

        while (curr != nullptr && i + 1 < index)
        {
            curr = curr->GetNext();
            i += 1;
        }

        new_node->SetNext(curr->GetNext());
        curr->SetNext(new_node);

        this->size += 1;
    }
}

template <class T>
void LinkedList<T>::DeleteAt(const int index)
{
    if (size <= 0 || index > size - 1)
    {
        return;
    }

    if (index == 0)
    {
        Node<T>* temp = this->head;
        this->head = this->head->GetNext();
        delete temp;
    }
    else
    {
        Node<T>* curr = this->head;
        int i = 0;

        while (curr != nullptr && i + 1 < index)
        {
            curr = curr->GetNext();
            i += 1;
        }

        Node<T>* to_delete = curr->GetNext();
        curr->SetNext(to_delete->GetNext());

        if (to_delete == this->tail)
        {
            this->tail = curr;
        }

        delete to_delete;
    }

    this->size -= 1;
}

template <class T>
void LinkedList<T>::DeleteAll(const T d)
{

}

template <class T>
int LinkedList<T>::FindFirstElement(const T d)
{
    if (size <= 0)
    {
        return -1;
    }

    Node<T>* curr = this->head;
    int i = 0;

    while (curr != nullptr && curr->GetData() != d)
    {
        curr = curr->GetNext();
        i += 1;
    }

    if (curr == nullptr)
    {
        return -1;
    }

    return i;
}

template <class T>
int* LinkedList<T>::FindElement(const T d)
{
    return new int[10];
}

template <class T>
int LinkedList<T>::GetSize()
{
    return this->size;
}

template <class T>
void LinkedList<T>::Print()
{
    Node<T>* curr = this->head;

    std::cout << " {{ ";

    while (curr != nullptr)
    {
        curr->PrintData();
        curr = curr->GetNext();
    }

    std::cout << " }} " << std::endl;
}

template <class T>
void LinkedList<T>::Print(std::string s)
{
    std::cout << s << std::endl;
    this->Print();
    std::cout << std::endl;
}

template <class T>
void LinkedList<T>::Reverse()
{
    if (size <= 1)
    {
        return;
    }

    Node<T>* a = this->head;
    Node<T>* b = a->GetNext();
    a->SetNext(nullptr);

    Node<T>* temp;
    while (b != nullptr)
    {
        temp = b->GetNext();
        b->SetNext(a);
        a = b;
        b = temp;
    }

    temp = this->tail;
    this->tail = this->head;
    this->head = temp;
}