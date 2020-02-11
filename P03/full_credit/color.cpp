#include "color.h"

  
  Color::Color() // Declaring default constructor
  :_reset{true}{}
 
  Color::Color(int red, int green , int blue)    // Declaring Constructor
        : _red{red}, _green{green}, _blue{blue},_reset{false}{
		if( red<0 || red >256)throw std::runtime_error{"Invalid number"};
		if( blue<0 || blue>256)throw std::runtime_error{"Invalid number"};
		if( green<0 || green>256)throw std::runtime_error{"Invalid number"};
		}
  std:: string Color::to_string()             //Changing ints to string using to_string
  {                 
	   return  std::to_string(_red) + std::to_string(_green)  + std::to_string(_blue) ;
  }

std::ostream& operator<<(std::ostream& ost, const Color& color)
{
	if(color._reset == false)
 {
    ost << "\033[38;2;" + std::to_string(color._red) + ";" + std::to_string(color._green) + ";" + std::to_string(color._blue)+"m";
    return ost;
 }	
    else
 {
	 
    ost<< "\033[0m" ;
    return ost;
   
 }
  
} 

std::istream &operator>>(std::istream &ist, Color &color){
		ist >> color._red >> color._green >> color._blue; 
		color._reset = false;
		return ist;
}

	


