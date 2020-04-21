
#ifndef _DESKTOP_H
#define _DESKTOP_H

#include "option.h"
#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <iomanip>



class Desktop
{
	private:
	std::vector<Options*> options;
	
	
	public:
	Desktop();
	void add_option(Options& option);
	double price();
	friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);
	void save(std::ostream& ost);
	Desktop(std::istream& ist);
};
#endif	