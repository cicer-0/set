/**
 * @file random.hpp
 * @author Luis Gorpa (Luis@hotmail.com)
 * @brief
 * @version 0.1
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
 * @brief
 *
 */
class RandomMath
{
public:
  /**
   * @brief
   *
   * @param length
   * @return string
   */
  static string numberStr(unsigned short int length);
  /**
   * @brief
   *
   * @param limit
   * @return unsigned int
   */
  static unsigned int numberInt(unsigned int limit);
  /**
   * @brief
   *
   * @param limitL
   * @param limitR
   * @return int
   */
  static int numberInt(int limitL, int limitR);

private:
  /**
   * @brief
   *
   */
  static bool isSrand;
  /**
   * @brief
   *
   */
  static void RANDOMINIT();
};
#endif
