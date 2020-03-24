#include "order.h"
#include "options.h"
#include "customer.h"

Order::Order(Customer& customer):_customer{customer}{}

Order::~Order(){}

int Order::add_product(Desktop& desktop)
{
_products.push_back(&desktop);
return _products.size()-1;
}

double Order::price() const
{
double x= 0;
    int i;
    for(i=0;i<_products.size();i++)
    {
        x += (_products.at(i))->price();
    }
 return x;
 
}


std::ostream& operator<<(std::ostream& ost, const Order& order)
{
ost<< order.price();
return ost;
}