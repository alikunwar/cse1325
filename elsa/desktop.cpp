#include "desktop.h"
#include "options.h"

void Desktop::add_option(Options& option)
{
  options.push_back(&option);
}

double Desktop::price() const
{
    double price= 0;
    int i;
    for(i=0;i<options.size();i++)
    {
    price += (options.at(i))->cost();
    }
 return price;
}


int x =1;
std::ostream& operator<<(std::ostream& ost, const Desktop& desktop)
{
ost<< desktop.price();
return ost;
}