
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
	friend std::ostream& operator<<(std::ostream& ost, const Customer& customer);
	Customer(std::istream& ist);
	void save(std::ostream& ost);
	
};
#endif	
	