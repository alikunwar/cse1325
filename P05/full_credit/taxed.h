#ifndef _TAXED_H
#define _TAXED_H

#include "product.h"
#include <iostream>
#include <exception>
#include <string>

class Taxed: public Product
{
	public:
	Taxed(std::string name, double cost);
	virtual ~Taxed();
	static void set_tax_rate(double sales_tax);
	double price() const override;
	
	
	private:
	static double _tax;
};

#endif