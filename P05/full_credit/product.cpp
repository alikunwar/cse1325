#include "product.h"

Product::Product(std::string name, double cost): _name{name}, _cost{cost}, _quantity{0}
{
	if(_cost<0)
	{
     throw std::runtime_error{"Invalid price"};  //throwing exception for invalid cost
	}
}
 Product::~Product(){}

void Product::set_quantity(int quantity)
{
	
	_quantity = quantity;
}

 
std::ostream& operator<<(std::ostream& ost, const Product& product)
 {
     ost << product._name<<" (" << product._quantity << "@ $ "<<product._cost<<")";
	 return ost;
 }