/**
 * @file node.hpp
 * @author Luis Gorpa (Luis@hotmail.com)
 * @brief Clase Node el cual estara compuesto la clase Set
 * @version 1.0
 * @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef NODE_H
#define NODE_H
#include <cstddef>
#pragma once
/**
 * @brief representacion de un nodo el cual tiene @b dato y @b enlace_al_siguiente_nodo.
 *
 * @tparam T Tipo de elemnto.
 */
template <class T>
class Node
{
public:
  /**
   * @brief Construir un nuevo objeto Node el cual inician nulos
   *
   */
  Node();
  /**
   * @brief Construir un nuevo objeto Node con un dato en el nodo
   *
   * @param value Dato que se establecera en el atributo  @b *value
   */
  Node(T value);
  /**
   * @brief Destruir el objeto Node
   *
   */
  ~Node();
  /**
   * @brief Establecer el atributo @b *value
   *
   * @param value Dato que se establecera en el atributo  @b *value
   */
  void setValue(T value);
  /**
   * @brief Establecer el atributo @b *next
   *
   * @param next Dato que se establecera en el atributo  @b *next
   */
  void setNext(Node<T> *next);
  /**
   * @brief Obtener el atributo @b *value
   *
   * @return T*
   */
  T *getValue();
  /**
   * @brief Obtener el atributo @b *next
   *
   * @return Node<T>*
   */
  Node<T> *getNext();

private:
  /**
   * @brief Atributo para el dato
   *
   */
  T *value;
  /**
   * @brief Atributo para el enlace del siguiente nodo
   *
   */
  Node<T> *next;
};
template <class T>
Node<T>::Node() : next(NULL), value(NULL) {}
template <class T>
Node<T>::Node(T value) : next(NULL) { this->value = new T[1], *this->value = value; }
template <class T>
Node<T>::~Node() {}
template <class T>
void Node<T>::setValue(T value) { this->value = value; }
template <class T>
void Node<T>::setNext(Node<T> *next) { this->next = next; }
template <class T>
T *Node<T>::getValue() { return this->value; }
template <class T>
Node<T> *Node<T>::getNext() { return this->next; }
#endif
