#ifndef _TAXED_H
#define _TAXED_H


#include <iostream>
#include <exception>
#include <string>

class Taxed:virtual public Product
{
	public:
	Taxed(std::string name, double cost);
	virtual ~Taxed();
	static void set_tax_rate(double sales_tax);
	virtual double price () const override;
	
	
	private:
	static double _tax;
};

#endif