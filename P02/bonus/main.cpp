#include "color.h"
#include <iostream>


int main()
{
  Color c{255,0,0};  //Passing the values of red, green and blue
  Color m{37,255,0};
  Color p{95,34,73};
 
  
  
  std::cout << c.colorize("Red") << std::endl;   //Printing the name of the color in its represented color
  std::cout << m.colorize("Green") << std::endl;
  std::cout << p.colorize("Purple") << std::endl;
  
  int r,g,b;
  
  std::cout<< "Enter red, green, and blue ints: ";   //Asking the user for rgb values
  std::cin>>r>>g>>b;
  
  Color color{r,g,b};
  std::cout<< color.colorize(color.to_string())<< std::endl;      //Printing the colored string 
  
  
  
}