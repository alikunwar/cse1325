
#ifndef _DESKTOP_H
#define _DESKTOP_H


#include <iostream>
#include <exception>
#include <string>
#include<vector>
#include <iomanip>

#include "options.h"

class Desktop
{
	private:
	std::vector<Options *> options;
	
	
	public:
	void add_option(Options& options);
	double price() const;
	friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);
};
#endif	