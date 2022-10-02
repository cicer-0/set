/**
 * @file random.hpp
 * @author Luis Gorpa (Luis@hotmail.com)
 * @brief Generar números aleatorios
 * @version 1.0
 * @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef RANDOM_MATH_H
#define RANDOM_MATH_H

#pragma once
#include <string>
using namespace std;
/**
 * @brief Clase para generar numeros aleatorios
 *
 */
class RandomMath
{
public:
  /**
   * @brief Generador de numeros enteros aleatorios en formato texto
   *
   * @param length Limite positivo de los numeros a generar
   * @return string
   */
  static string numberStr(unsigned short int length);
  /**
   * @brief Generador de numeros enteros aleatorios
   *
   * @param limit Limite positivo de los numeros a generar
   * @return unsigned int
   */
  static unsigned int numberInt(unsigned int limit);
  /**
   * @brief Generador de numeros enteros aleatorios
   *
   * @param limitL Limite negativo de los numeros a generar
   * @param limitR Limite positivo de los numeros a generar
   * @return int
   */
  static int numberInt(int limitL, int limitR);

private:
  /**
   * @brief Indica si el srand() ya fue llamada
   *
   */
  static bool isSrand;
  /**
   * @brief Inicializar el srand()
   *
   */
  static void RANDOMINIT();
};
#endif
