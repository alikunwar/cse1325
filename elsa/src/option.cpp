#include "option.h"

Options::Options(std::string name,double cost): _name{name}, _cost{cost}{}


Options::~Options(){}


double Options::cost()
{
  return _cost;
}

std::string Options::to_string() const
{
return _name +"($" + std::to_string(_cost) + ")";
}

std::ostream& operator<<(std::ostream& ost, const Options& options)
{
 ost <<options.to_string();
	 return ost;
}

Options::Options(std::istream& ist)
{
	std::getline(ist, _name);
	ist >> _cost>>"\n";
	
}


void Options::save(std::ostream& ost)
{
	
	ost << _name << "\n" << _cost << "\n";
}