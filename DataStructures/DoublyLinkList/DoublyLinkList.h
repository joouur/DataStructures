#pragma once

template <class Type>
class Node {
public:
  Node(Type v) : data(v) { next = NULL; previous = NULL; }
  Type data;
  Node<Type> *next;
  Node<Type> *previous;
};

template <class T>
class DoublyLinkList {
public:
  DoublyLinkList() { head = NULL; tail = NULL; countInList = 0; }
  DoublyLinkList(T value) { createList(value); }
  ~DoublyLinkList();

  void createList(T &value);
  void createList(Node<T> *value);

  void addElement(T &value);
  void addAtBegining(T &value);
  void addAtPosition(T &value, int index);
  void addAtEnd(T &value);

  void addElement(Node<T> *value);
  void addAtBegining(Node<T> *value);
  void addAtPosition(Node<T> *value, int index);
  void addAtEnd(Node<T> *value);

  T deleteElement(T value);
  T deleteAtPosition(int index);

  Node<T> *getElementAtPosition(int index);
  bool containsElement(T item);
  int getElementPosition(T value);
  int Count();
   
private:
  Node<T> *head;
  Node<T> *tail;
  int countInList;
  void handleTail();
};