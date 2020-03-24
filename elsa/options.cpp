#include "options.h"

Options::Options(std::string name,double cost): _name{name}, _cost{cost}{}


Options::~Options(){}


double Options::cost()
{
  return _cost;
}

std::string Options::to_string()
{
return _name +" " + std::to_string(_cost);
}

std::ostream& operator<<(std::ostream& ost, const Options& options)
{
 ost <<options._name << options._cost << std::endl;
	 return ost;
}