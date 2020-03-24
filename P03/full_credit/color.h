#ifndef _COLOR_H
#define _COLOR_H

#include <iostream>
#include <string>
#include <exception>

class Color
{
  public:
  Color();
  Color(int red, int green , int blue);
  
  std::string to_string();
   

  friend std::ostream& operator<<(std::ostream& ost, const Color& color);
  friend std::istream &operator>>(std::istream &ist, Color &color);

private:
  
  int _red;
  int _green;
  int _blue;
  bool _reset;
};

  

#endif