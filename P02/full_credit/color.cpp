#include "color.h"


  Color::Color(int red, int green , int blue)    // Declaring Constructor
        : _red{red}, _green{green}, _blue{blue} {};
  std:: string Color::to_string(){                  //Changing ints to string using to_string
	   return "{" + std::to_string(_red) + "," + std::to_string(_green) + "," + std::to_string(_blue) + "}";
  }
	  
   std:: string Color::colorize(std::string text ){
	  return  "\033[38;2;" + std::to_string(_red) + ";" + std::to_string(_green) + ";" + std::to_string(_blue) + ";177m" + text + "\033[0m";   
	   
   }


