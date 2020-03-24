
#ifndef _OPTIONS_H
#define _OPTIONS_H


#include <iostream>
#include <exception>
#include <string>

class Options
{
	protected:
	std::string _name;
	double _cost;
	
	public:
	Options(std::string name,double cost);
	~Options();
	double cost();
	virtual std::string to_string();
	friend std::ostream& operator<<(std::ostream& ost, const Options& options);
	
};
#endif	