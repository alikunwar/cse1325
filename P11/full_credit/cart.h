#ifndef _CART_H
#define _CART_H

#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include "item.h"


class Cart
{
	private:
	std::string _customer;
	typedef std::vector <Item *> Items;
	Items _items;
	
	public:
	Cart(std::string customer);
	~Cart();
	Cart(const Cart& cart);
	Cart& operator=(const Cart& cart);
	void add_item(Item& item);
	double cost();
	typedef Items::iterator iterator;
    iterator begin(){return _items.begin();};
	iterator end(){return _items.begin();};
	
};
#endif	