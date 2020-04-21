#ifndef _RAM_H
#define _RAM_H

#include "option.h"
#include <iostream>
#include <exception>
#include <string>

class Ram : public Options{
	protected:
	int _gb;
	
	
	public:
    Ram(std::string name, double cost, int gb);
	~Ram();
	Ram(std::istream& ist);
	std::string to_string() const override;
	void save(std::ostream& ost) const override;
};
#endif	
