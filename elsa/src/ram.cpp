#include "ram.h"


Ram::Ram(std::string name, double cost, int gb):Options{name,cost}, _gb{gb}{}
	Ram::~Ram(){}
	
	Ram::Ram(std::istream& ist): Options(ist)
	{
		ist >> _gb;
      ist.ignore(32767, '\n');
	}
	
	std::string Ram::to_string() const 
    {
     return _name +"($" + std::to_string(_cost) + std::to_string(_gb)+ ")";
    }
	
	void Ram::save(std::ostream& ost) const
	{
		Options::save(ost);
	  ost << _name << "\n" << std::to_string(_gb) <<"\n" <<std::to_string(_cost) << "\n";
	}