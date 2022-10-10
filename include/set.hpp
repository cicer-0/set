/**
 * @file set.hpp
 * @author Luis Gorpa (Luis@hotmail.com)
 * @brief Manipular conjuntos
 * @version 1.0
 * @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef SET_H
#define SET_H

#pragma once
#include "../include/print.hpp"
#include "node.hpp"
#include <string>
using namespace std;
/**
 * @brief Contenedor generico que representa a un Conjunto.
 *
 * @tparam T Tipo de elemnto.
 */
template <class T>
class Set
{
public:
  /**
   * @brief Construir un nuevo objeto Set el cual inicia con el atributo @b head nulo , @b size 0 y @b name un texto vacio.
   *
   */
  Set();
  /**
   * @brief Construir un nuevo objeto Set el cual inicia con el atributo @b head nulo , @b size 0 y @b name es asignado.
   *
   * @param name
   */
  Set(string name);
  /**
   * @brief (Contructor copia) Construir un nuevo objeto Set copiando de otro objeto Set
   *
   * @param origin
   */
  Set(Set<T> &origin);
  /**
   * @brief Destruir el objeto Set
   *
   */
  ~Set();
  /**
   * @brief Obtener el atributo @b size
   *
   * @return unsigned int
   */
  unsigned int getSize();
  /**
   * @brief Obtener el atributo @b name
   *
   * @return string
   */
  string getName();
  /**
   * @brief Establecer el atributo @b name
   *
   * @param name
   */
  void setName(string name);
  /**
   * @brief Añadir un elemento al cojunto
   *
   * @param value
   */
  void add(T value);
  /**
   * @brief Añadir un elemento al cojunto, no se añadira si este dato ya existe
   *
   * @param value
   */
  void addNoRepeat(T value);
  /**
   * @brief Añadir un elemento al cojunto, de acuerdo al indice
   *
   * @param index
   * @param value
   */
  void insert(unsigned int index, T value);
  /**
   * @brief (buscador) Devuelve el valor del primer elemento del conjunto donde el predicado es verdadero.
   *
   * @tparam _FUNCTION Funcion lambda
   * @param action Find llama al predicado una vez para cada elemento del conjunto, en orden ascendente, hasta que encuentra uno en el que el predicado devuelve verdadero. Si se encuentra dicho elemento, find devuelve inmediatamente ese valor de elemento. De lo contrario, find devuelve nulo.
   * @return T*
   */
  template <typename _FUNCTION>
  T *find(_FUNCTION action);
  /**
   * @brief Devuelve el último elemento que puede encontrarse en el Conjunto, ó nulo si el elemento no se encontrara
   *
   * @return T
   */
  T *back();
  /**
   * @brief Recibe un valor numérico entero y devuelve el elemento en esa posición
   *
   * @param index
   * @return T
   */
  T at(unsigned int index);
  /**
   * @brief Recibe un valor numérico entero y elimina el elemento en esa posición
   *
   * @param index
   */
  void deleteAt(unsigned int index);
  /**
   * @brief Ejecuta la función indicada una vez por cada elemento del conjunto
   *
   * @tparam _FUNCTION
   * @param action Función a ejecutar por cada elemento, el cual
   * recibe como parametro @b <T> elemento actual siendo procesado en el conjunto
   */
  template <typename _FUNCTION>
  void forEach(_FUNCTION action);
  /**
   * @brief Devuelve una cadena que representa al Conjunto
   *
   * @return string
   */
  string toString();
  /**
   * @brief Obtener elemento del conjunto mediante un indice
   * @param index
   * @return T&
   * @link https://www.geeksforgeeks.org/overloading-subscript-or-array-index-operator-in-c/ @endlink
   */
  T &operator[](unsigned int index);
  /**
   * @brief Asigna el conjunto del operando derecho al operando izquierdo
   *
   * @param other
   * @return Set<T>&
   */
  Set<T> &operator=(const Set<T> &other);
  /**
   * @brief Unir dos conjuntos
   *
   * @param addends
   * @return Set<T>
   */
  Set<T> operator+(const Set<T> addends);
  /**
   * @brief Diferencia de dos conjuntos
   *
   * @param subtrahend
   * @return Set<T>
   */
  Set<T> operator-(const Set<T> subtrahend);
  /**
   * @brief Interseccion de dos conjuntos
   *
   * @param factor
   * @return Set<T>
   */
  Set<T> operator*(const Set<T> factor);
  /**
   * @brief Interseccion de dos conjuntos
   *
   * @param ASet
   * @param BSet
   * @return Set<T>
   */
  static Set<T> intersectionSet(Set<T> &ASet, Set<T> &BSet);
  /**
   * @brief Unir dos conjuntos
   *
   * @param ASet
   * @param BSet
   * @return Set<T>
   */
  static Set<T> unionSet(Set<T> &ASet, Set<T> &BSet);
  /**
   * @brief Diferencia de dos conjuntos
   *
   * @param ASet
   * @param BSet
   * @return Set<T>
   */
  static Set<T> differenceSet(Set<T> &ASet, Set<T> &BSet);

private:
  /**
   * @brief Node cabezera el cual empieza la lista enlazadas
   *
   */
  Node<T> *head;
  /**
   * @brief Tamaño del conjunto
   *
   */
  unsigned int size;
  /**
   * @brief nombre del conjunto
   *
   */
  string name;
  /**
   * @brief Devuelve el último Node que puede encontrarse en el Conjunto, ó nulo si el Node no se encontrara
   *
   * @return Node<T>*
   */
  Node<T> *last();
  /**
   * @brief (Recorrer Conjunto) Devuelve el Node donde se detiene el recorrido
   *
   * @tparam _FUNCTION
   * @param action Es la funcion lambda que se ejecuta en cada Node. Debe retornar un @b bool
   * para indicar su detencion del recorrido, el cual recibe como parametro un Node<T> *
   * @return Node<T>*
   */
  template <typename _FUNCTION>
  Node<T> *travel(_FUNCTION action);
  /**
   * @brief Recibe un valor numérico entero y devuelve el Node en esa posición
   *
   * @param index
   * @return Node<T>*
   */
  Node<T> *_at(unsigned int index);
  /**
   * @brief Lanza un error si @b action no es una funcion lambda
   *
   * @tparam _FUNCTION
   * @param action
   */
  template <typename _FUNCTION>
  static void errorThrowerIfLambda(_FUNCTION action);
  /**
   * @brief Lanza un error si @b index esta fuera de rando del tamaño del indice
   *
   * @param index
   */
  static void errorThrowerOutOfRange(unsigned int index, Set<T> set);
};
template <class T>
Set<T>::Set() : head(NULL), size(0), name("") {}
template <class T>
Set<T>::Set(string name) : head(NULL), size(0), name(name) {}
template <class T>
Set<T>::Set(Set<T> &origin) : head(NULL), size(0)
{
  Set<T> *Set{this};
  origin.forEach(
      [&Set](T element)
      {
        Set->add(element);
      });
}
template <class T>
Set<T>::~Set()
{
  Node<T> *next;
  while (this->head != NULL)
  {
    next = this->head->getNext();
    delete this->head;
    this->head = next;
  }
  this->size = 0;
}
template <class T>
unsigned int Set<T>::getSize() { return this->size; };
template <class T>
string Set<T>::getName() { return this->name; }
template <class T>
void Set<T>::setName(string name) { this->name = name; }
template <class T>
void Set<T>::add(T value)
{
  if (this->head == NULL)
    this->head = new Node<T>{value};
  else
    (this->last())->setNext(new Node<T>{value});
  this->size++;
}
template <class T>
void Set<T>::addNoRepeat(T value)
{
  if (this->head == NULL)
    this->head = new Node<T>{value}, this->size++;
  else
  {
    T *repeated{
        this->find(
            [&value](T element)
            {
              return element == value;
            })};
    if (repeated == NULL)
      (this->last())->setNext(new Node<T>{value}), this->size++;
  }
}
template <class T>
void Set<T>::insert(unsigned int index, T value)
{
  errorThrowerOutOfRange(index, *this);
  this->size++;
  int position{0};
  if (index == 0)
  {
    Node<T> *newHead = new Node<T>(value);
    newHead->setNext(this->head);
    this->head = newHead;
    return;
  }
  this->travel(
      [&position, index, value](Node<T> *node)
      {
        if (position == index - 1)
        {
          Node<T> *insert = new Node<T>(value);
          insert->setNext(node->getNext());
          node->setNext(insert);
          return true;
        }
        position++;
        return false;
      });
}
template <class T>
T *Set<T>::back()
{
  T *value;
  value = this->last()->getValue();
  return value;
}
template <class T>
Node<T> *Set<T>::last()
{
  return this->travel(
      [](Node<T> *node)
      { return false; });
}
template <class T>
template <typename _FUNCTION>
Node<T> *Set<T>::travel(_FUNCTION action)
{
  Set<T>::errorThrowerIfLambda(action);
  Node<T> *Pnode{this->head};
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
Node<T> *Set<T>::_at(unsigned int index)
{
  errorThrowerOutOfRange(index, *this);
  int position{0};
  return this->travel(
      [&position, &index](Node<T> *node)
      {
        if (index == position)
        {
          return true;
        }
        position++;
        return false;
      });
}
template <class T>
T Set<T>::at(unsigned int index)
{
  Node<T> *value{this->_at(index)};
  return *(value->getValue());
}
template <class T>
void Set<T>::deleteAt(unsigned int index)
{
  errorThrowerOutOfRange(index, *this);
  int position{0};
  Node<T> *Ppast;
  Node<T> *Pnode{this->head};
  Node<T> *Pnext;
  while (Pnode != NULL)
  {
    if (position == index)
    {
      if (index == this->size - 1)
      {
        if (this->size == 1)
        {
          delete this->head;
          this->head = NULL;
          break;
        }
        delete Pnode;
        Ppast->setNext(NULL);
        break;
      }
      Pnext = Pnode->getNext();
      delete Pnode;
      *Pnode = *Pnext;
      break;
    }
    Ppast = Pnode;
    position++;
    Pnode = Pnode->getNext();
  }
  this->size--;
}

template <class T>
template <typename _FUNCTION>
T *Set<T>::find(_FUNCTION action)
{
  Set<T>::errorThrowerIfLambda(action);
  T *value{NULL};
  this->travel(
      [&action, &value](Node<T> *node)
      {
        bool found;
        found = action(*node->getValue());
        if (found)
        {
          value = new T;
          *value = *node->getValue();
          return true;
        }
        return false;
      });
  return value;
}
template <class T>
template <typename _FUNCTION>
void Set<T>::errorThrowerIfLambda(_FUNCTION action)
{
  string TYPE{typeid(action).name()};
  const int NUM = TYPE.find("EUl");
  if (NUM < 0 || NUM >= TYPE.length() ? 1 : 0)
    throw "NO ES UNA LAMBDA";
}
template <class T>
void Set<T>::errorThrowerOutOfRange(unsigned int index, Set<T> set)
{
  if (index < 0 || index >= set.size)
    throw "INDICE INVALIDO";
}
template <class T>
template <typename _FUNCTION>
void Set<T>::forEach(_FUNCTION action)
{
  Set<T>::errorThrowerIfLambda(action);
  Node<T> *Pnode{this->head};
  while (Pnode != NULL)
  {
    action(*Pnode->getValue());
    Pnode = Pnode->getNext();
  }
}
template <class T>
string Set<T>::toString()
{
  string type(typeid(*(this->head->getValue())).name());
  string inText{"{"};
  this->travel(
      [&inText](Node<T> *node)
      {
        inText += to_string(*(node->getValue()));
        if ((node->getNext()) == NULL)
          return true;
        inText += ", ";
        return false;
      });
  inText += "}";
  return inText;
}

template <class T>
T &Set<T>::operator[](unsigned int index)
{
  Node<T> *value{this->_at(index)};
  return *value->getValue();
}
template <class T>
Set<T> &Set<T>::operator=(const Set<T> &other)
{
  this->~Set();
  Node<T> *Pnode{other.head};
  while (Pnode != NULL)
  {
    this->add(*Pnode->getValue());
    Pnode = Pnode->getNext();
  }
  return *this;
}
template <class T>
Set<T> Set<T>::operator+(Set<T> addends)
{
  Set<T> _union_;
  this->forEach(
      [&_union_](T element)
      { _union_.addNoRepeat(element); });
  addends.forEach(
      [&_union_](T element)
      { _union_.addNoRepeat(element); });
  return _union_;
}
template <class T>
Set<T> Set<T>::operator-(Set<T> subtrahend)
{
  Set<T> _difference_;
  this->forEach(
      [&_difference_, &subtrahend](T elementThis)
      {
        T *found{
            subtrahend.find(
                [&elementThis](T elementSubtrahend)
                {
                  return elementSubtrahend == elementThis;
                })};
        if (found == NULL)
          _difference_.addNoRepeat(elementThis);
      });
  return _difference_;
}
template <class T>
Set<T> Set<T>::operator*(Set<T> factor)
{
  Set<T> _intersection_;
  this->forEach(
      [&_intersection_, &factor](T elementThis)
      {
        T *found{
            factor.find(
                [&elementThis](T elementFactor)
                {
                  return elementFactor == elementThis;
                })};
        if (found != NULL)
          _intersection_.addNoRepeat(*found);
      });
  return _intersection_;
}
template <class T>
Set<T> Set<T>::intersectionSet(Set<T> &ASet, Set<T> &BSet)
{
  Set<T> _intersection_;
  _intersection_ = ASet * BSet;
  return _intersection_;
}
template <class T>
Set<T> Set<T>::unionSet(Set<T> &ASet, Set<T> &BSet)
{
  Set<T> _union_;
  _union_ = ASet + BSet;
  return _union_;
}
template <class T>
Set<T> Set<T>::differenceSet(Set<T> &ASet, Set<T> &BSet)
{
  Set<T> _difference_;
  _difference_ = ASet - BSet;
  return _difference_;
}

#endif
