#ifndef _ITEM_H
#define _ITEM_H

#include <iostream>
#include <exception>
#include <iterator>


class Item
{
	private:
	std::string _name;
	double _price;
	
	
	public:
	Item(std::string name, double price);
	double cost();
    friend std::ostream& operator<<(std::ostream& ost, const Item& item);
    friend std::istream& operator>>(std::istream& ist,  Item& item);	
};
#endif	