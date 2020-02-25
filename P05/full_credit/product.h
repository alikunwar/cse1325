#ifndef _PRODUCT_H
#define _PRODUCT_H


#include <iostream>
#include <exception>
#include <ostream>
#include <string>

class Product
{
	protected:
	
	int _quantity;
	double _cost;
	std::string _name;
	
	public:
	
	Product(std::string name, double cost);
	virtual ~Product();
	void set_quantity(int quantity);
	virtual double price() const = 0;
	friend std::ostream& operator<<(std::ostream& ost, const Product& product);
	
};
#endif	