#include "../print.hpp"
#include <iostream>
using namespace std;
output::Color::Color() : red(char(255)), green(char(255)), blue(char(255)) {}
output::Color::Color(unsigned short int red, unsigned short int green, unsigned short int blue)
{
  if (red > 255 || green > 255 || blue > 255)
    throw "the assigned color is invalid";
  this->red = char(red);
  this->green = char(green);
  this->blue = char(blue);
}
void output::Color::change(unsigned short int red, unsigned short int green, unsigned short int blue)
{
  if (red > 255 || green > 255 || blue > 255)
    throw "the assigned color is invalid";
  this->red = red;
  this->green = green;
  this->blue = blue;
}
void output::Color::setRed(unsigned short int red)
{
  if (red > 255)
    throw "the assigned color is invalid";
  this->red = red;
}
void output::Color::setGreen(unsigned short int green)
{
  if (green > 255)
    throw "the assigned color is invalid";
  this->green = green;
}
void output::Color::setBlue(unsigned short int blue)
{
  if (blue > 255)
    throw "the assigned color is invalid";
  this->blue = blue;
}
int output::Color::getRed() { return this->red; }
int output::Color::getGreen() { return this->green; }
int output::Color::getBlue() { return this->blue; }
output::Color::~Color() {}

void output::Print::to(string message) { cout << message; }
void output::Print::to(double message) { cout << message; }
void output::Print::to(int message) { cout << message; }
void output::Print::to(char message) { cout << message; }
void output::Print::to(float message) { cout << message; }
void output::Print::to(Color color, Color background, string message) { output::Print::_to<string>(color, background, message); }
void output::Print::to(Color color, Color background, double message) { output::Print::_to<double>(color, background, message); }
void output::Print::to(Color color, Color background, int message) { output::Print::_to<int>(color, background, message); }
void output::Print::to(Color color, Color background, char message) { output::Print::_to<char>(color, background, message); }
void output::Print::to(Color color, Color background, float message) { output::Print::_to<float>(color, background, message); }
void output::Print::ln(string message) { cout << message << '\n'; }
void output::Print::ln(double message) { cout << message << '\n'; }
void output::Print::ln(int message) { cout << message << '\n'; }
void output::Print::ln(char message) { cout << message << '\n'; }
void output::Print::ln(float message) { cout << message << '\n'; }
void output::Print::ln(Color color, Color background, string message) { output::Print::_ln<string>(color, background, message); }
void output::Print::ln(Color color, Color background, double message) { output::Print::_ln<double>(color, background, message); }
void output::Print::ln(Color color, Color background, int message) { output::Print::_ln<int>(color, background, message); }
void output::Print::ln(Color color, Color background, char message) { output::Print::_ln<char>(color, background, message); }
void output::Print::ln(Color color, Color background, float message) { output::Print::_ln<float>(color, background, message); }
void output::Print::wColor(Color color, string message) { output::Print::_wColor<string>(color, message); }
void output::Print::wColor(Color color, double message) { output::Print::_wColor<double>(color, message); }
void output::Print::wColor(Color color, int message) { output::Print::_wColor<int>(color, message); }
void output::Print::wColor(Color color, char message) { output::Print::_wColor<char>(color, message); }
void output::Print::wColor(Color color, float message) { output::Print::_wColor<float>(color, message); }
void output::Print::wColorLn(Color color, string message) { output::Print::_wColorLn<string>(color, message); }
void output::Print::wColorLn(Color color, double message) { output::Print::_wColorLn<double>(color, message); }
void output::Print::wColorLn(Color color, int message) { output::Print::_wColorLn<int>(color, message); }
void output::Print::wColorLn(Color color, char message) { output::Print::_wColorLn<char>(color, message); }
void output::Print::wColorLn(Color color, float message) { output::Print::_wColorLn<float>(color, message); }
void output::Print::wBKGD(Color background, string message) { output::Print::_wBKGD<string>(background, message); }
void output::Print::wBKGD(Color background, double message) { output::Print::_wBKGD<double>(background, message); }
void output::Print::wBKGD(Color background, int message) { output::Print::_wBKGD<int>(background, message); }
void output::Print::wBKGD(Color background, char message) { output::Print::_wBKGD<char>(background, message); }
void output::Print::wBKGD(Color background, float message) { output::Print::_wBKGD<float>(background, message); }
void output::Print::wBKGDLn(Color background, string message) { output::Print::_wBKGDLn<string>(background, message); }
void output::Print::wBKGDLn(Color background, double message) { output::Print::_wBKGDLn<double>(background, message); }
void output::Print::wBKGDLn(Color background, int message) { output::Print::_wBKGDLn<int>(background, message); }
void output::Print::wBKGDLn(Color background, char message) { output::Print::_wBKGDLn<char>(background, message); }
void output::Print::wBKGDLn(Color background, float message) { output::Print::_wBKGDLn<float>(background, message); }
void output::Print::endl() { cout << '\n'; }
void output::Print::endl(unsigned int n)
{
  for (int i = 0; i < n; i++)
    cout << '\n';
}
void output::Print::tab(unsigned int n)
{
  for (unsigned int i = 0; i < n; i++)
    cout << '\t';
}
