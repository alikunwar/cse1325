#ifndef _ORDER_H
#define _ORDER_H

#include <iostream>
#include <exception>
#include <string>
#include <vector>


#include "customer.h"
#include "desktop.h"

class Order
{
	private:
	Customer* _customer;
	std::vector<Desktop* > _products;
	
	public:
	Order(Customer& customer);
	Order(std::istream& ist);
	virtual ~Order();
	int add_product(Desktop& desktop);
	double price() const;
	void save(std::ostream& ost);
	friend std::ostream& operator<<(std::ostream& ost, const Order& order);
	
	
};
#endif	
