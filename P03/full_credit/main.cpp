#include "color.h"
#include <iostream>
#include <string>


int main()
{
  Color red{255,0,0};  //Passing the values of red, green and blue
  Color green{0,255,0};
  Color blue{0,0,255};
  Color reset;
 
  std::cout <<red<<" Rose is red "<<std::endl<< green << "Trees are green"<< std::endl
                       << blue << "Sky is blue "  << reset << std::endl;
  
   Color x;
  std::cout<< "Enter color as (red, green, blue):  ";   //Asking the user for rgb values
  std::cin>>x;
  
  
  
  std::cout << x.to_string()<< reset << std::endl;
  
  
  
}