#include "store.h"
#include <iostream>

Store::Store()
{

}

Store::Store(std::istream& ist)
{
	int size;
	ist >> size;
	ist.ignore(32767, '\n');
	for(int i=0; i < size; i++){
		Customer customer_data = Customer(ist);
		add_customer(customer_data);
	}if(!ist.good()) throw std::runtime_error("Cannot read data file");

	ist >> size;
	ist.ignore(32767, '\n');
	for(int i=0; i < size; i++){
		Options option_data = Options(ist);
		add_option(option_data);
	}if(!ist.good()) throw std::runtime_error("Cannot read data file");

	ist >> size;
	ist.ignore(32767, '\n');
	for(int i=0; i < size; i++){
		Desktop desktop_data = Desktop(ist);
		desktops.push_back(desktop_data);
	}if(!ist.good()) throw std::runtime_error("Cannot read data file");

	ist >> size;
	ist.ignore(32767, '\n');
	for(int i=0; i < size; i++){
		Order order_data(ist);
		orders.push_back(order_data);
	}if(!ist.good()) throw std::runtime_error("Cannot read data file");
}

void Store::save(std::ostream& ost)
{
	ost << customers.size() << "\n";
	for(int i=0; i < customers.size(); i++)
		customers.at(i).save(ost);
	if(!ost.good()) throw std::runtime_error("Cannot write to data file");

	ost << options.size() << "\n";
	for(int i=0; i < options.size(); i++)
		options.at(i)->save(ost);
	if(!ost.good()) throw std::runtime_error("Cannot write to data file");

	ost << desktops.size() << "\n";
	for(int i=0; i < desktops.size(); i++)
		desktops.at(i).save(ost);
	if(!ost.good()) throw std::runtime_error("Cannot write to data file");

	ost << orders.size() << "\n";
	for(int i=0; i < orders.size(); i++)
		orders.at(i).save(ost);
	if(!ost.good()) throw std::runtime_error("Cannot write to data file");
}

//
// Customers
//
void Store::add_customer(Customer& customer) 
{
	customers.push_back(customer);
}

int Store::num_customers() 
{
	return customers.size();
}

Customer& Store::customer(int index) 
{
	return customers.at(index);
}

//
// Options
//
void Store::add_option(Options& option) 
{
	options.push_back(new Options{option});
}

int Store::num_options() 
{
	return options.size();
}

Options& Store::option(int index) 
{
	return *options.at(index);
}

//
// Products
//
int Store::new_desktop() {
    desktops.push_back(Desktop{});
    return desktops.size()-1;
}
void Store::add_option(int option, int desktop) { // to desktop
    desktops.at(desktop).add_option(*options.at(option));
}
int Store::num_desktops() {return desktops.size();}
Desktop& Store::desktop(int index) {return desktops.at(index);}

//
// Orders
//
int Store::new_order(int customer) {
    orders.push_back(Order{customers.at(customer)});
    return orders.size()-1;
}
    
void Store::add_desktop(int desktop, int order) { // to order
    orders.at(order).add_product(desktops.at(desktop));
}
int Store::num_orders() {return orders.size();}
Order& Store::order(int index) {return orders.at(index);}
