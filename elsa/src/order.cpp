#include "order.h"

Order::Order(Customer& customer) : _customer{&customer} {}
Order::~Order() {}
int Order::add_product(Desktop& desktop)
 {
_products.push_back(&desktop); 
return _products.size()-1;
}


double Order::price() const 
{
    double y = 0;
    for(auto p : _products)
    y += p->price();
    return y;
}

std::ostream& operator<<(std::ostream& ost, const Order& order) {
    ost << "Customer: " << *order._customer;
    for(auto p : order._products) ost << "\n  " << *p << "\n  Price: $" << p->price() << "\n";
    ost << "\nTotal price: $" << order.price();
    return ost;
}

void Order::save(std::ostream& ost)
{

_customer->save(ost);
ost << _products.size() << "\n";
	
for (auto p : _products)
{
 p->save(ost);
}

}

Order::Order(std::istream& ist)
{
	_customer = new Customer{ist};
	int size;
	ist >> size;
	ist.ignore(32767, '\n');
	for(int i = 0; i < size; i++)
	{
		_products.push_back(new Desktop{ist});
	}
}



