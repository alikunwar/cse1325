
#ifndef _CUSTOMER_H
#define _CUSTOMER_H


#include <iostream>
#include <exception>
#include <string>

class Customer
{
	private:
	std::string _name;
	std::string _phone;
	std::string _email;
	
	public:
	
	Customer(std::string name,std::string phone, std::string email);
	Customer(std::istream& ist);
	friend std::ostream& operator<<(std::ostream& ost, const Customer& customer);
	void save(std::ostream& ost);
	
};
#endif
	