#pragma once

#include <iostream>

template <class T>
class Node
{
public:
    Node();
    Node(const T d, Node<T>* n = nullptr);
    ~Node();

    void SetData(const T d);
    T GetData();
    void SetNext(Node<T>* n);
    Node<T>* GetNext();

    void PrintData();

private:
    T data;
    Node* next;
};

template <class T>
Node<T>::Node() : data(), next(nullptr) {}

template <class T>
Node<T>::Node(const T d, Node<T>* n)
{
    this->data = d;
    this->next = n;
}

template <class T>
Node<T>::~Node() {}

template <class T>
void Node<T>::SetData(const T d)
{
    this->data = d;
}

template <class T>
T Node<T>::GetData()
{
    return this->data;
}

template <class T>
void Node<T>::SetNext(Node<T>* n)
{
    this->next = n;
}

template <class T>
Node<T>* Node<T>::GetNext()
{
    return this->next;
}

template <class T>
void Node<T>::PrintData()
{
    std::cout << " [" << this->data << "] ";
}