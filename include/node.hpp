#ifndef NODE_H
#define NODE_H

#pragma once
#include <cstddef>
template <class T>
class Node
{
public:
  Node();
  Node(T);
  ~Node();
  void setValue(T);
  void setNext(Node<T> *);
  T getValue();
  Node<T> *getNext();

private:
  T value;
  Node<T> *next;
};
template <class T>
Node<T>::Node() {}
template <class T>
Node<T>::Node(T value) : value(value), next(NULL) {}
template <class T>
Node<T>::~Node()
{
  // if (this->next != NULL)
  //     delete this->next;
}
template <class T>
void Node<T>::setValue(T value) { this->value = value; }
template <class T>
void Node<T>::setNext(Node<T> *next) { this->next = next; }
template <class T>
T Node<T>::getValue() { return this->value; }
template <class T>
Node<T> *Node<T>::getNext() { return this->next; }
#endif
