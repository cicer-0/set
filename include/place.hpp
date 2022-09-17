#ifndef PLACE_H
#define PLACE_H

#pragma once
#include "node.hpp"
#include <iostream>
using namespace std;
template <class T>
class Place
{
public:
  Place();
  Place(T);
  ~Place();
  unsigned int getSize();
  void add(T);
  template <typename _FUNCTION>
  T *find(_FUNCTION);
  T back();
  T at(unsigned int);
  template <typename _FUNCTION>
  void forEach(_FUNCTION);
  T operator[](T);

private:
  Node<T> *head;
  unsigned int size;
  Node<T> *last();
  template <typename _FUNCTION>
  Node<T> *travel(_FUNCTION);
  template <typename _FUNCTION>
  static void errorThrowerIfLambda(_FUNCTION);
};

template <class T>
Place<T>::Place() : head(NULL), size(0) {}
template <class T>
Place<T>::Place(T value) : size(1) { this->head = new Node<T>(value); }
template <class T>
Place<T>::~Place()
{
  Node<T> *next;
  while (this->head != NULL)
  {
    next = this->head->getNext();
    delete this->head;
    this->head = next;
  }
}
template <class T>
unsigned int Place<T>::getSize() { return this->size; };
template <class T>
void Place<T>::add(T value)
{
  if (this->head == NULL)
    this->head = new Node<T>(value);
  else
    (this->last())->setNext(new Node<T>(value));
  this->size++;
}
template <class T>
T Place<T>::back() { return this->last()->getValue(); }
template <class T>
Node<T> *Place<T>::last()
{
  return this->travel(
      [](Node<T> *node)
      { return false; });
}
template <class T>
template <typename _FUNCTION>
Node<T> *Place<T>::travel(_FUNCTION action)
{
  Place<T>::errorThrowerIfLambda(action);
  Node<T> *Pnode = this->head;
  Node<T> *Preturn;
  while (Pnode != NULL)
  {
    Preturn = Pnode;
    bool stop = action(Pnode);
    if (stop)
      break;
    Pnode = Pnode->getNext();
  }
  return Preturn;
}
template <class T>
T Place<T>::at(unsigned int index)
{
  if (index < 0 || index >= this->size)
  {
    throw "INDICE INVALIDO";
    exit(0);
  }
  T value;
  int position = 0;
  this->travel(
      [&position, &value, &index](Node<T> *node)
      {
        if (index == position)
        {
          value = node->getValue();
          return true;
        }
        position++;
        return false;
      });
  return value;
}
template <class T>
template <typename _FUNCTION>
T *Place<T>::find(_FUNCTION action)
{
  Place<T>::errorThrowerIfLambda(action);
  T *value = NULL;
  this->travel(
      [&action, &value](Node<T> *node)
      {
        bool found;
        found = action(node->getValue());
        if (found)
        {
          value = new T;
          *value = node->getValue();
          return true;
        }
        return false;
      });
  return value;
}
template <class T>
template <typename _FUNCTION>
void Place<T>::errorThrowerIfLambda(_FUNCTION action)
{
  const string TYPE = typeid(action).name();
  const int NUM = TYPE.find("EUl");
  if (NUM < 0 || NUM >= TYPE.length() ? 1 : 0)
    throw "NO ES UNA LAMBDA";
}
template <class T>
template <typename _FUNCTION>
void Place<T>::forEach(_FUNCTION action)
{
  Place<T>::errorThrowerIfLambda(action);
  Node<T> *Pnode = this->head;
  while (Pnode != NULL)
  {
    action(Pnode->getValue());
    Pnode = Pnode->getNext();
  }
}
template <class T>
T Place<T>::operator[](T index)
{
  if (index < 0 || index >= this->size)
  {
    throw "INDICE INVALIDO";
    exit(0);
  }
  return this->at(index);
}
#endif
