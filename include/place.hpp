/**
 * @file place.hpp
 * @author Luis Gorpa (Luis@hotmail.com)
 * @brief Clase para el manejo de conjuntos
 * @version 0.1
 * @date 2022-09-20
 * @code {.cpp}
    #include "../include/place.hpp"
    #include "../include/random.hpp"
    #include "../include/print.hpp"
    #include <list>
    int main(int argc, char *argv[])
    {
      Place<int> setA;
      Place<int> setB;
      Place<int> result;
      for (size_t i = 0; i < 10; i++)
        setA.add(RandomMath::numberInt(30));
      for (size_t i = 0; i < 10; i++)
        setB.add(RandomMath::numberInt(30));
      result = setA + setB;
      result = setA - setB;
      result = setA * setB;
      return 0;
    }
 * @endcode
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef PLACE_H
#define PLACE_H

#pragma once
#include "../include/print.hpp"
#include "node.hpp"
#include <string>
using namespace std;
/**
 * @brief
 *
 * @tparam T
 */
template <class T>
class Place
{
public:
  /**
   * @brief Construct a new Place object
   *
   */
  Place();
  /**
   * @brief Construct a new Place object
   *
   * @param value
   */
  Place(T value);
  /**
   * @brief Construct a new Place object
   *
   * @param origin
   */
  Place(Place<T> &origin);
  /**
   * @brief Destroy the Place object
   *
   */
  ~Place();
  /**
   * @brief Get the Size object
   *
   * @return unsigned int
   */
  unsigned int getSize();
  /**
   * @brief
   *
   * @param value
   */
  void add(T value);
  /**
   * @brief
   *
   * @param value
   */
  void addNoRepeat(T value);
  /**
   * @brief
   *
   * @tparam _FUNCTION
   * @param action
   * @return T*
   */
  template <typename _FUNCTION>
  T *find(_FUNCTION action);
  /**
   * @brief
   *
   * @return T
   */
  T back();
  /**
   * @brief
   *
   * @param index
   * @return T
   */
  T at(unsigned int index);
  /**
   * @brief
   *
   * @param index
   */
  void deleteAt(unsigned int index);
  /**
   * @brief
   *
   * @tparam _FUNCTION
   * @param action
   */
  template <typename _FUNCTION>
  void forEach(_FUNCTION action);
  /**
   * @brief
   *
   * @return string
   */
  string toString();
  /**
   * @brief
   * @param index
   * @return T&
   * @link https://www.geeksforgeeks.org/overloading-subscript-or-array-index-operator-in-c/ @endlink
   */
  T &operator[](unsigned int index);
  /**
   * @brief
   *
   * @param other
   * @return Place<T>&
   */
  Place<T> &operator=(const Place<T> &other);
  /**
   * @brief
   *
   * @param addends
   * @return Place<T>
   */
  Place<T> operator+(Place<T> addends);
  /**
   * @brief
   *
   * @param subtrahend
   * @return Place<T>
   */
  Place<T> operator-(Place<T> subtrahend);
  /**
   * @brief
   *
   * @param factor
   * @return Place<T>
   */
  Place<T> operator*(Place<T> factor);
  // Place<T> operator+(const Place<T>) const;
  // Place<T> operator-(const Place<T>) const;
  // Place<T> operator*(const Place<T>) const;
  /**
   * @brief
   *
   * @param APlace
   * @param BPlace
   * @return Place<T>
   */
  static Place<T> intersectionPlace(Place<T> &APlace, Place<T> &BPlace);
  /**
   * @brief
   *
   * @param APlace
   * @param BPlace
   * @return Place<T>
   */
  static Place<T> unionPlace(Place<T> &APlace, Place<T> &BPlace);
  /**
   * @brief
   *
   * @param APlace
   * @param BPlace
   * @return Place<T>
   */
  static Place<T> differencePlace(Place<T> &APlace, Place<T> &BPlace);

private:
  /**
   * @brief
   *
   */
  Node<T> *head;
  /**
   * @brief
   *
   */
  unsigned int size;
  /**
   * @brief
   *
   * @return Node<T>*
   */
  Node<T> *last();
  /**
   * @brief
   *
   * @tparam _FUNCTION
   * @param action
   * @return Node<T>*
   */
  template <typename _FUNCTION>
  Node<T> *travel(_FUNCTION action);
  /**
   * @brief
   *
   * @param index
   * @return Node<T>*
   */
  Node<T> *_at(unsigned int index);
  /**
   * @brief
   *
   * @tparam _FUNCTION
   * @param action
   */
  template <typename _FUNCTION>
  static void errorThrowerIfLambda(_FUNCTION action);
};
template <class T>
Place<T>::Place() : head(NULL), size(0) {}
template <class T>
Place<T>::Place(T value) : size(1) { this->head = new Node<T>{value}; }
template <class T>
Place<T>::Place(Place<T> &origin) : head(NULL), size(0)
{
  Place<T> *place{this};
  origin.forEach(
      [&place](T element)
      {
        place->add(element);
      });
}
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
  this->size = 0;
}
template <class T>
unsigned int Place<T>::getSize() { return this->size; };
template <class T>
void Place<T>::add(T value)
{
  if (this->head == NULL)
    this->head = new Node<T>{value};
  else
    (this->last())->setNext(new Node<T>{value});
  this->size++;
}
template <class T>
void Place<T>::addNoRepeat(T value)
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
T Place<T>::back() { return *this->last()->getValue(); }
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
Node<T> *Place<T>::_at(unsigned int index)
{
  if (index < 0 || index >= this->size)
  {
    throw "INDICE INVALIDO";
    // exit(0);
  }
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
T Place<T>::at(unsigned int index)
{
  Node<T> *value{this->_at(index)};
  return *(value->getValue());
}
template <class T>
void Place<T>::deleteAt(unsigned int index)
{
  if (index < 0 || index >= this->size)
  {
    throw "INDICE INVALIDO";
  }
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
T *Place<T>::find(_FUNCTION action)
{
  Place<T>::errorThrowerIfLambda(action);
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
void Place<T>::errorThrowerIfLambda(_FUNCTION action)
{
  string TYPE{typeid(action).name()};
  const int NUM = TYPE.find("EUl");
  if (NUM < 0 || NUM >= TYPE.length() ? 1 : 0)
    throw "NO ES UNA LAMBDA";
}
template <class T>
template <typename _FUNCTION>
void Place<T>::forEach(_FUNCTION action)
{
  Place<T>::errorThrowerIfLambda(action);
  Node<T> *Pnode{this->head};
  while (Pnode != NULL)
  {
    action(*Pnode->getValue());
    Pnode = Pnode->getNext();
  }
}
template <class T>
string Place<T>::toString()
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
T &Place<T>::operator[](unsigned int index)
{
  Node<T> *value{this->_at(index)};
  return *value->getValue();
}
template <class T>
Place<T> &Place<T>::operator=(const Place<T> &other)
{
  this->~Place();
  Node<T> *Pnode{other.head};
  while (Pnode != NULL)
  {
    this->add(*Pnode->getValue());
    Pnode = Pnode->getNext();
  }
  return *this;
}
template <class T>
Place<T> Place<T>::operator+(Place<T> addends)
{
  Place<T> _union_;
  this->forEach(
      [&_union_](T element)
      { _union_.addNoRepeat(element); });
  addends.forEach(
      [&_union_](T element)
      { _union_.addNoRepeat(element); });
  return _union_;
}
template <class T>
Place<T> Place<T>::operator-(Place<T> subtrahend)
{
  Place<T> _difference_;
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
Place<T> Place<T>::operator*(Place<T> factor)
{
  Place<T> _intersection_;
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
Place<T> Place<T>::intersectionPlace(Place<T> &APlace, Place<T> &BPlace)
{
  Place<T> _intersection_;
  _intersection_ = APlace * BPlace;
  return _intersection_;
}
template <class T>
Place<T> Place<T>::unionPlace(Place<T> &APlace, Place<T> &BPlace)
{
  Place<T> _union_;
  _union_ = APlace + BPlace;
  return _union_;
}
template <class T>
Place<T> Place<T>::differencePlace(Place<T> &APlace, Place<T> &BPlace)
{
  Place<T> _difference_;
  _difference_ = APlace - BPlace;
  return _difference_;
}

#endif
