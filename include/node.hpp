/**
 * @file node.hpp
 * @author Luis Gorpa (Luis@hotmail.com)
 * @brief Clase Node el cual estara compuesto la clase Place
 * @version 0.1
 * @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef NODE_H
#define NODE_H
#include <cstddef>
#pragma once
template <class T>
class Node
{
public:
  /**
   * @brief Construct a new Node object
   *
   */
  Node();
  /**
   * @brief Construct a new Node object
   *
   * @param value
   */
  Node(T value);
  /**
   * @brief Destroy the Node object
   *
   */
  ~Node();
  /**
   * @brief Set the Value object
   *
   * @param value
   */
  void setValue(T value);
  /**
   * @brief Set the Next object
   *
   * @param next
   */
  void setNext(Node<T> *next);
  /**
   * @brief Get the Value object
   *
   * @return T*
   */
  T *getValue();
  /**
   * @brief Get the Next object
   *
   * @return Node<T>*
   */
  Node<T> *getNext();

private:
  /**
   * @brief
   *
   */
  T *value;
  /**
   * @brief
   *
   */
  Node<T> *next;
};
template <class T>
Node<T>::Node() : next(NULL), value(NULL) {}
template <class T>
Node<T>::Node(T value) : next(NULL) { this->value = new T[1], *this->value = value; }
template <class T>
Node<T>::~Node()
{
  // delete this->value;
  // if (this->next != NULL)
  //     delete this->next;
}
template <class T>
void Node<T>::setValue(T value) { this->value = value; }
template <class T>
void Node<T>::setNext(Node<T> *next) { this->next = next; }
template <class T>
T *Node<T>::getValue() { return this->value; }
template <class T>
Node<T> *Node<T>::getNext() { return this->next; }
#endif
