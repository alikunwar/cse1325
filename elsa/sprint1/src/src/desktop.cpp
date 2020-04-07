#include "desktop.h"


void Desktop::add_option(Options& option)
{
  options.push_back(&option);
}

double Desktop::price()
{
    double price= 0;
    int i;
    for(auto o: options)
    {
    price += o->cost();
    }
 return price;
}


int x =1;
std::ostream& operator<<(std::ostream& ost, const Desktop& desktop)
{
ost<< "Desktop includes";
for(auto o: desktop.options)ost << "\n " << *o;   
return ost;
}