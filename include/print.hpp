/**
 * @file print.hpp
 * @author Luis Gorpa (Luis@hotmail.com)
 * @brief
 * @version 0.1
 *  @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef PRINT_H
#define PRINT_H

#pragma once
#include <string>
#include <iostream>
using namespace std;
/**
 * @brief declaraciones de las clases que trabajaran para una salida de a Colores.
 * @note https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
 *
 */
namespace output
{
  /**
   *
   * @brief
   *
   */
  class Color
  {
  private:
    /**
     * @brief
     *
     */
    unsigned char _red;
    /**
     * @brief
     *
     */
    unsigned char _green;
    /**
     * @brief
     *
     */
    unsigned char _blue;

  public:
    /**
     * @brief Construct a new Color object
     *
     */
    Color();
    /**
     * @brief Construct a new Color object
     *
     * @param red
     * @param green
     * @param blue
     */
    Color(unsigned short int red,
          unsigned short int green,
          unsigned short int blue);
    /**
     * @brief
     *
     * @param red
     * @param green
     * @param blue
     */
    void change(unsigned short int red,
                unsigned short int green,
                unsigned short int blue);
    /**
     * @brief Set the Red object
     *
     * @param red
     */
    void setRed(unsigned short int red);
    /**
     * @brief Set the Green object
     *
     * @param green
     */
    void setGreen(unsigned short int green);
    /**
     * @brief Set the Blue object
     *
     * @param blue
     */
    void setBlue(unsigned short int blue);
    /**
     * @brief Get the Red object
     *
     * @return int
     */
    int getRed();
    /**
     * @brief Get the Green object
     *
     * @return int
     */
    int getGreen();
    /**
     * @brief Get the Blue object
     *
     * @return int
     */
    int getBlue();
    /**
     * @brief Destroy the Color object
     *
     */
    ~Color();
  };
  /**
   * @brief
   *
   */
  class Print
  {
  public:
    /**
     * @brief
     *
     * @param message
     */
    static void to(string message);
    /**
     * @brief
     *
     * @param message
     */
    static void to(double message);
    /**
     * @brief
     *
     * @param message
     */
    static void to(int message);
    /**
     * @brief
     *
     * @param message
     */
    static void to(char message);
    /**
     * @brief
     *
     * @param message
     */
    static void to(float message);
    /**
     * @brief
     *
     * @param color
     * @param background
     * @param message
     */
    static void to(Color color, Color background, string message);
    /**
     * @brief
     *
     * @param color
     * @param background
     * @param message
     */
    static void to(Color color, Color background, double message);
    /**
     * @brief
     *
     * @param color
     * @param background
     * @param message
     */
    static void to(Color color, Color background, int message);
    /**
     * @brief
     *
     * @param color
     * @param background
     * @param message
     */
    static void to(Color color, Color background, char message);
    /**
     * @brief
     *
     * @param color
     * @param background
     * @param message
     */
    static void to(Color color, Color background, float message);
    /**
     * @brief
     *
     * @param message
     */
    static void ln(string message);
    /**
     * @brief
     *
     * @param message
     */
    static void ln(double message);
    /**
     * @brief
     *
     * @param message
     */
    static void ln(int message);
    /**
     * @brief
     *
     * @param message
     */
    static void ln(char message);
    /**
     * @brief
     *
     * @param message
     */
    static void ln(float message);
    /**
     * @brief
     *
     * @param color
     * @param background
     * @param message
     */
    static void ln(Color color, Color background, string message);
    /**
     * @brief
     *
     * @param color
     * @param background
     * @param message
     */
    static void ln(Color color, Color background, double message);
    /**
     * @brief
     *
     * @param color
     * @param background
     * @param message
     */
    static void ln(Color color, Color background, int message);
    /**
     * @brief
     *
     * @param color
     * @param background
     * @param message
     */
    static void ln(Color color, Color background, char message);
    /**
     * @brief
     *
     * @param color
     * @param background
     * @param message
     */
    static void ln(Color color, Color background, float message);
    /**
     * @brief
     *
     * @param color
     * @param message
     */
    static void wColor(Color color, string message);
    /**
     * @brief
     *
     * @param color
     * @param message
     */
    static void wColor(Color color, double message);
    /**
     * @brief
     *
     * @param color
     * @param message
     */
    static void wColor(Color color, int message);
    /**
     * @brief
     *
     * @param color
     * @param message
     */
    static void wColor(Color color, char message);
    /**
     * @brief
     *
     * @param color
     * @param message
     */
    static void wColor(Color color, float message);
    /**
     * @brief
     *
     * @param color
     * @param message
     */
    static void wColorLn(Color color, string message);
    /**
     * @brief
     *
     * @param color
     * @param message
     */
    static void wColorLn(Color color, double message);
    /**
     * @brief
     *
     * @param color
     * @param message
     */
    static void wColorLn(Color color, int message);
    /**
     * @brief
     *
     * @param color
     * @param message
     */
    static void wColorLn(Color color, char message);
    /**
     * @brief
     *
     * @param color
     * @param message
     */
    static void wColorLn(Color color, float message);
    /**
     * @brief
     *
     * @param background
     * @param message
     */
    static void wBKGD(Color background, string message);
    /**
     * @brief
     *
     * @param background
     * @param message
     */
    static void wBKGD(Color background, double message);
    /**
     * @brief
     *
     * @param background
     * @param message
     */
    static void wBKGD(Color background, int message);
    /**
     * @brief
     *
     * @param background
     * @param message
     */
    static void wBKGD(Color background, char message);
    /**
     * @brief
     *
     * @param background
     * @param message
     */
    static void wBKGD(Color background, float message);
    /**
     * @brief
     *
     * @param background
     * @param message
     */
    static void wBKGDLn(Color background, string message);
    /**
     * @brief
     *
     * @param background
     * @param message
     */
    static void wBKGDLn(Color background, double message);
    /**
     * @brief
     *
     * @param background
     * @param message
     */
    static void wBKGDLn(Color background, int message);
    /**
     * @brief
     *
     * @param background
     * @param message
     */
    static void wBKGDLn(Color background, char message);
    /**
     * @brief
     *
     * @param background
     * @param message
     */
    static void wBKGDLn(Color background, float message);
    /**
     * @brief
     *
     */
    static void endl();
    /**
     * @brief
     *
     * @param n
     */
    static void endl(unsigned int n);
    /**
     * @brief
     *
     * @param n
     */
    static void tab(unsigned int n);

  private:
    /**
     * @brief
     *
     * @tparam T
     * @param color
     * @param message
     */
    template <class T>
    static void _wColor(Color color, T message);
    /**
     * @brief
     *
     * @tparam T
     * @param color
     * @param message
     */
    template <class T>
    static void _wColorLn(Color color, T message);
    /**
     * @brief
     *
     * @tparam T
     * @param color
     * @param background
     * @param message
     */
    template <class T>
    static void _to(Color color, Color background, T message);
    /**
     * @brief
     *
     * @tparam T
     * @param color
     * @param background
     * @param message
     */
    template <class T>
    static void _ln(Color color, Color background, T message);
    /**
     * @brief
     *
     * @tparam T
     * @param background
     * @param message
     */
    template <class T>
    static void _wBKGD(Color background, T message);
    /**
     * @brief
     *
     * @tparam T
     * @param background
     * @param message
     */
    template <class T>
    static void _wBKGDLn(Color background, T message);
  };
} // namespace output

template <class T>
void output::Print::_to(Color color, Color background, T message)
{
  cout << "\033[38;2;" << color.getRed() << ";" << color.getGreen() << ";" << color.getBlue() << "m"
       << "\033[48;2;" << background.getRed() << ";" << background.getGreen() << ";" << background.getBlue() << "m" << message << "\033[0m";
}
template <class T>
void output::Print::_ln(Color color, Color background, T message)
{
  output::Print::_to<T>(color, background, message);
  cout << '\n';
}
template <class T>
void output::Print::_wColor(Color color, T message)
{
  cout << "\033[38;2;" << color.getRed() << ";" << color.getGreen() << ";" << color.getBlue() << "m" << message << "\033[0m";
}
template <class T>
void output::Print::_wColorLn(Color color, T message)
{
  output::Print::_wColor<T>(color, message);
  cout << '\n';
}
template <class T>
void output::Print::_wBKGD(Color background, T message)
{
  cout << "\033[48;2;" << background.getRed() << ";" << background.getGreen() << ";" << background.getBlue() << "m" << message << "\033[0m";
}
template <class T>
void output::Print::_wBKGDLn(Color background, T message)
{
  output::Print::_wBKGD<T>(background, message);
  cout << '\n';
}
#endif
