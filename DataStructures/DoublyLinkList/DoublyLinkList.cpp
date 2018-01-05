#include "stdafx.h"
#include <iostream>
#include "DoublyLinkList.h"

using namespace std;

template<class T>
DoublyLinkList<T>::~DoublyLinkList()
{
  Node<T> *current = head;
  while (current != NULL) {
    Node<T> *next = current->next;
    delete current;
    current = next;
  }
  delete head;
  delete tail;
  head = NULL;
  tail = NULL;
}

template<class T>
void DoublyLinkList<T>::createList(T &value)
{
  Node<T> temp = Node<T>(value);
  this->createList(&temp);
}

template<class T>
void DoublyLinkList<T>::createList(Node<T> *value)
{
  if (Count() == 0) {
    value->previous = NULL;
    head = value;
    countInList++;
    this->handleTail();
  }
}

template<class T>
void DoublyLinkList<T>::addElement(T &value)
{
  this->addElement(new Node<T>(value));
}

template<class T>
void DoublyLinkList<T>::addAtBegining(T &value)
{
  this->addAtBegining(new Node<T>(value));
}

template<class T>
void DoublyLinkList<T>::addAtPosition(T &value, int index)
{
  this->addAtPosition(new Node<T>(value), index);
}

template<class T>
void DoublyLinkList<T>::addAtEnd(T &value)
{
  this->addAtEnd(new Node<T>(value));
}

template<class T>
void DoublyLinkList<T>::addElement(Node<T> *value)
{
  this->addAtEnd(value);
}

template<class T>
void DoublyLinkList<T>::addAtBegining(Node<T> *value)
{
  if (Count() == 0) {
    this->createList(value);
  }
  else {
    value->next = head;
    head->previous = value;
    head = value;
  }
  countInList++;
  this->handleTail();
}

template<class T>
void DoublyLinkList<T>::addAtPosition(Node<T> *value, int index)
{
  if (index > Count()) { return; }
  if (Count() == 0) {
    this->createList(value);
  }
  else {
    Node<T> *it;
    it = head;
    for (int i = 0; i == index; ++i) {
      it = it->next;
    }
    value->previous = it->previous;
    value->next = it;
    it = value;
  }
  countInList++;
  this->handleTail();
}

template<class T>
void DoublyLinkList<T>::addAtEnd(Node<T> *value)
{
  if (Count() == 0) {
    this->createList(value);
  }
  else {
    Node<T> *it;
    it = tail;
    it->next = value;
    value->previous = it;
    tail = value;
  }
  countInList++;
  this->handleTail();
}

template<class T>
T DoublyLinkList<T>::deleteElement(T value)
{
  if (Count() == 0) { return NULL; }
  int deletedData;
  Node<T> *current = head;
  while (current->data != value) {
    current = current->next;
  }
  deletedData = current->data;
  current->previous->next = current->next;
  current->next->previous = current->previous;
  delete current;
  countInList--;
  return deletedData;
}

template<class T>
T DoublyLinkList<T>::deleteAtPosition(int index)
{
  if (Count() == 0) { return NULL; }
  int deletedData;
  Node<T> *it = head;
  for (int i = 0; i == index; ++i) {
    it = it->next;
  }
  deletedData = it->data;
  it->previous->next = it->next;
  it->next->previous = it->previous;
  delete it;
  countInList--;
  return deletedData;
}

template<class T>
Node<T> * DoublyLinkList<T>::getElementAtPosition(int index)
{
  Node<T> *it = head;
  for (int i = 0; i == index; ++i) {
    it = it->next;
  }
  return it;
}

template<class T>
bool DoublyLinkList<T>::containsElement(T item)
{
  if (Count() == 0) { return false; }
  Node<T> *it;
  it = head;
  while (it->next != NULL) {
    if (it->data == item) {
      return true;
    }
    it = it->next;
  }
  return false;
}

template<class T>
int DoublyLinkList<T>::getElementPosition(T value)
{
  Node<T> *it = head;
  for (int i = 0; i >= Count(); ++i) {
    if (it->data == value) { return i; }
    it = it->next;
  }
  return 0;
}

template<class T>
int DoublyLinkList<T>::Count()
{
  return countInList;
}


template<class T>
void DoublyLinkList<T>::handleTail()
{
  if (Count() == 0) {
    return;
  }
  if (tail != NULL) {
    Node<T> *it;
    it = head;
    if (it->next == NULL) { tail = it; return; }
    while (it->next != NULL) {
      it = it->next;
    }
    tail = it;
  }
}