/**
 * @file print.hpp
 * @author Luis Gorpa (Luis@hotmail.com)
 * @brief Salida a Colores
 * @version 1.0
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
 * @brief declaraciones de las clases que trabajaran para una salida a Colores.
 * @note https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
 *
 */
namespace output
{
  /**
   *
   * @brief Expresa un color de acuerdo con sus componentes rojo, verde y azul
   *
   */
  class Color
  {
  private:
    /**
     * @brief Nivel de rojo 0-255
     *
     */
    unsigned char red;
    /**
     * @brief Nivel de verde 0-255
     *
     */
    unsigned char green;
    /**
     * @brief Nivel de azul 0-255
     *
     */
    unsigned char blue;

  public:
    /**
     * @brief Construir un nuevo objeto Color por defecto negro
     *
     */
    Color();
    /**
     * @brief Construir un nuevo objeto Color
     *
     * @param red Nivel de rojo 0-255
     * @param green Nivel de verde 0-255
     * @param blue Nivel de azul 0-255
     */
    Color(unsigned short int red,
          unsigned short int green,
          unsigned short int blue);
    /**
     * @brief Establcer un nuevo color
     *
     * @param red Nivel de rojo 0-255
     * @param green Nivel de verde 0-255
     * @param blue Nivel de azul 0-255
     */
    void change(unsigned short int red,
                unsigned short int green,
                unsigned short int blue);
    /**
     * @brief Establecer el atributo @b red
     *
     * @param red Nivel de rojo 0-255
     */
    void setRed(unsigned short int red);
    /**
     * @brief Establecer el atributo @b green
     *
     * @param green Nivel de verde 0-255
     */
    void setGreen(unsigned short int green);
    /**
     * @brief Establecer el atributo @b blue
     *
     * @param blue Nivel de azul 0-255
     */
    void setBlue(unsigned short int blue);
    /**
     * @brief Obtener el atributo @b red
     *
     * @return int
     */
    int getRed();
    /**
     * @brief Obtener el atributo @b green
     *
     * @return int
     */
    int getGreen();
    /**
     * @brief Obtener el atributo @b blue
     *
     * @return int
     */
    int getBlue();
    /**
     * @brief Destruir el objeto Color
     *
     */
    ~Color();
  };
  /**
   * @brief Clase encargada de la salida a colores
   *
   */
  class Print
  {
  public:
    /**
     * @brief Salida clasica
     *
     * @param message
     */
    static void to(string message);
    /**
     * @brief Salida clasica
     *
     * @param message
     */
    static void to(double message);
    /**
     * @brief Salida clasica
     *
     * @param message
     */
    static void to(int message);
    /**
     * @brief Salida clasica
     *
     * @param message
     */
    static void to(char message);
    /**
     * @brief Salida clasica
     *
     * @param message
     */
    static void to(float message);
    /**
     * @brief Salida a color del elemento y fondo
     *
     * @param color
     * @param background
     * @param message
     */
    static void to(Color color, Color background, string message);
    /**
     * @brief Salida a color del elemento y fondo
     *
     * @param color
     * @param background
     * @param message
     */
    static void to(Color color, Color background, double message);
    /**
     * @brief Salida a color del elemento y fondo
     *
     * @param color
     * @param background
     * @param message
     */
    static void to(Color color, Color background, int message);
    /**
     * @brief Salida a color del elemento y fondo
     *
     * @param color
     * @param background
     * @param message
     */
    static void to(Color color, Color background, char message);
    /**
     * @brief Salida a color del elemento y fondo
     *
     * @param color
     * @param background
     * @param message
     */
    static void to(Color color, Color background, float message);
    /**
     * @brief Salida clasica, includo un salto de linea
     *
     * @param message
     */
    static void ln(string message);
    /**
     * @brief Salida clasica, includo un salto de linea
     *
     * @param message
     */
    static void ln(double message);
    /**
     * @brief Salida clasica, includo un salto de linea
     *
     * @param message
     */
    static void ln(int message);
    /**
     * @brief Salida clasica, includo un salto de linea
     *
     * @param message
     */
    static void ln(char message);
    /**
     * @brief Salida clasica, includo un salto de linea
     *
     * @param message
     */
    static void ln(float message);
    /**
     * @brief Salida a color del elemento y fondo, includo un salto de linea
     *
     * @param color
     * @param background
     * @param message
     */
    static void ln(Color color, Color background, string message);
    /**
     * @brief Salida a color del elemento y fondo, includo un salto de linea
     *
     * @param color
     * @param background
     * @param message
     */
    static void ln(Color color, Color background, double message);
    /**
     * @brief Salida a color del elemento y fondo, includo un salto de linea
     *
     * @param color
     * @param background
     * @param message
     */
    static void ln(Color color, Color background, int message);
    /**
     * @brief Salida a color del elemento y fondo, includo un salto de linea
     *
     * @param color
     * @param background
     * @param message
     */
    static void ln(Color color, Color background, char message);
    /**
     * @brief Salida a color del elemento y fondo, includo un salto de linea
     *
     * @param color
     * @param background
     * @param message
     */
    static void ln(Color color, Color background, float message);
    /**
     * @brief Salida a color del elemento
     *
     * @param color
     * @param message
     */
    static void wColor(Color color, string message);
    /**
     * @brief Salida a color del elemento
     *
     * @param color
     * @param message
     */
    static void wColor(Color color, double message);
    /**
     * @brief Salida a color del elemento
     *
     * @param color
     * @param message
     */
    static void wColor(Color color, int message);
    /**
     * @brief Salida a color del elemento
     *
     * @param color
     * @param message
     */
    static void wColor(Color color, char message);
    /**
     * @brief Salida a color del elemento
     *
     * @param color
     * @param message
     */
    static void wColor(Color color, float message);
    /**
     * @brief Salida a color del elemento, includo un salto de linea
     *
     * @param color
     * @param message
     */
    static void wColorLn(Color color, string message);
    /**
     * @brief Salida a color del elemento, includo un salto de linea
     *
     * @param color
     * @param message
     */
    static void wColorLn(Color color, double message);
    /**
     * @brief Salida a color del elemento, includo un salto de linea
     *
     * @param color
     * @param message
     */
    static void wColorLn(Color color, int message);
    /**
     * @brief Salida a color del elemento, includo un salto de linea
     *
     * @param color
     * @param message
     */
    static void wColorLn(Color color, char message);
    /**
     * @brief Salida a color del elemento, includo un salto de linea
     *
     * @param color
     * @param message
     */
    static void wColorLn(Color color, float message);
    /**
     * @brief Salida a color del fondo
     *
     * @param background
     * @param message
     */
    static void wBKGD(Color background, string message);
    /**
     * @brief Salida a color del fondo
     *
     * @param background
     * @param message
     */
    static void wBKGD(Color background, double message);
    /**
     * @brief Salida a color del fondo
     *
     * @param background
     * @param message
     */
    static void wBKGD(Color background, int message);
    /**
     * @brief Salida a color del fondo
     *
     * @param background
     * @param message
     */
    static void wBKGD(Color background, char message);
    /**
     * @brief Salida a color del fondo
     *
     * @param background
     * @param message
     */
    static void wBKGD(Color background, float message);
    /**
     * @brief Salida a color del fondo,includo un salto de linea
     *
     * @param background
     * @param message
     */
    static void wBKGDLn(Color background, string message);
    /**
     * @brief Salida a color del fondo,includo un salto de linea
     *
     * @param background
     * @param message
     */
    static void wBKGDLn(Color background, double message);
    /**
     * @brief Salida a color del fondo,includo un salto de linea
     *
     * @param background
     * @param message
     */
    static void wBKGDLn(Color background, int message);
    /**
     * @brief Salida a color del fondo,includo un salto de linea
     *
     * @param background
     * @param message
     */
    static void wBKGDLn(Color background, char message);
    /**
     * @brief Salida a color del fondo,includo un salto de linea
     *
     * @param background
     * @param message
     */
    static void wBKGDLn(Color background, float message);
    /**
     * @brief Salida de salto de linea
     *
     */
    static void endl();
    /**
     * @brief Salida de salto de linea, n veces
     *
     * @param n Cantidad de saltos de lineas
     */
    static void endl(unsigned int n);
    /**
     * @brief Salida de tabulaciones, n veces
     *
     * @param n Cantidad de tabulaciones
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
