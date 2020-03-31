#include "order.h"


Order::Order(Customer& customer) : _customer{customer} { }

Order::~Order() 
{ 
   
} 

int Order::add_product(Desktop& desktop) {_products.push_back(new Desktop(desktop));}
double Order::price() const{
    double x = 0.0;
    for(int i=0; i<_products.size(); ++i) 
    {
        x = x +  _products.at(i)->price();
    }
    return x;
}


std::ostream& operator<<(std::ostream& ost, const Order& order) {
  ost<< "Customer " << order._customer <<"\n";
  
    for (auto y : order._products)
{
    ost<< *y;
}
    
     ost << "Total cost:  " << order.price();
    return ost;
}
