#include "item.h"
#include <iomanip>
#include <string>
#include <exception>

Item::Item(std::string name, double price): _name{name}, _price{price}{};

double Item::cost()
{
	return _price;
}

std::ostream& operator<<(std::ostream& ost, const Item& item)
 {
     ost <<"$" << "  " << std::fixed << std::setprecision(2) << item. _price;
	 ost << " " <<item._name;
	 return ost;
 }
 
 std::istream& operator>>(std::istream& ist,Item& item)
 {
	 std::string input;
     std::getline(ist, input);
	 std::size_t pos = input.size();
	 

     while (input[pos] == ' ' && pos > 0)
	 {
	 		 --pos;
	 }

     if (pos == 0) 
	 { /* string consists spaces */ }

      std::string lastword = input.substr(input.find_last_of(' ', pos));

      std::string::size_type i = input.find(lastword);
      if (i != std::string::npos)
	  {
		   input.erase(i, lastword.length());
	  }
	  
    try{
       item._price = stod(lastword);
	   } catch (std::exception& e) { std::cerr <<"Exception: "<< e.what() << std::endl;}
	   
	   item._name = input;
	  ist >> item._name;
	  ist >> item._price;
	  return ist;
 }
    