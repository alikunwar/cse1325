#include <iostream>
#include <exception>
#include <iterator>

#include "cart.h"
#include "item.h"

int main()
{
	Cart c1("alisha");
	Item i1{" ",0};
	Item i2{i1};
	//double price = 0.0;
	
	while(true)
	{
		std::cout << "Enter product name and price('eg. Roma Tomatoes 0.95') : " << std::endl; 
		std::cin >> i1;
		c1.add_item(i1);
	
		std::cout<<"Register receipt"<<std::endl;
		
		
		std::cout<<i1<<std::endl;
		std:: cout << "$  " <<  i1.cost()  <<"  Total price" << std::endl;
	}	
		
	
	
	//std::cout << "$" <<    <<"  " << "Total cost";
	//
	//}
}
