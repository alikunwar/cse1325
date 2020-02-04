#include "color.h"


  Color::Color(int red, int green , int blue)    // Declaring Constructor
        : _red{red}, _green{green}, _blue{blue} {};
  std:: string Color::to_string(){                  //Changing ints to string using to_string
	   return "(" + std::to_string(_red) + "," + std::to_string(_green) + "," + std::to_string(_blue) + ":" +std::to_string(color::magnitude()) + ")" + std::to_string(color::magnitude()) ;
  }
	  
   std:: string Color::colorize(std::string text ){
	  return  "\033[38;2;" + std::to_string(_red) + ";" + std::to_string(_green) + ";" + std::to_string(_blue) + ";177m" + text + "\033[0m";   
	
    std::int Color::magnitude(){
		return 0.21*_red + 0.72*_green + 0.07* _blue;
		
    std::int Color::compare(int rhs)
	{
		if{
			(this.magnitude() < rhs.magnitude())
		    return -1;
		}
		else if{
			(this.magnitude() > rhs.magnitude())
		    return 1;
		}
		else return 0;
	
   }


