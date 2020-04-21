  
#include "store.h"

Store::Store(){}

//Customer

void Store::add_customer(Customer& customer)
{
  customers.push_back(customer);
}
int Store::num_customers()
{
  return customers.size();
}
Customer &Store::customer(int index)
{
  return customers.at(index);
}

// Options

void Store::add_option(Options& option)
{
  options.push_back(new Options{option});
}
int Store::num_options()
{
  return options.size();
}
Options &Store::option(int index)
{
  return *options.at(index);
}

// Products

int Store::new_desktop()
 {
    desktops.push_back(Desktop{});
    return desktops.size()-1;
}

void Store::add_option(int option, int desktop)
{
  desktops[desktop].add_option(*options[option]);
}

int Store::num_desktops()
{
  return desktops.size();
}

Desktop &Store::desktop(int index)
{
  return desktops[index];
}

// Orders

int Store::new_order(int customer)
{
  orders.push_back(Order{customers[customer]});
  return orders.size() - 1;
}

void Store::add_desktop(int desktop, int order)
{ 
  orders[order].add_product(desktops[desktop]);
}

int Store::num_orders()
{
  return orders.size();
}

Order &Store::order(int index)
{
  return orders[index];
}

Store::Store(std::istream& ist) {
   
    
    int size;
	
    // Load Customers
    ist >> size; ist.ignore(32767, '\n');
    while(size--) customers.push_back(Customer{ist});
    if(!ist) throw std::runtime_error{"Invalid data"};

    // Load Options
    ist >> size; ist.ignore(32767, '\n');
    while(size--) options.push_back(new Options{ist});
    if(!ist) throw std::runtime_error{"Invalid Data"};

    // Load desktops
    ist >> size; ist.ignore(32767, '\n');
    while(size--) desktops.push_back(Desktop{ist});
    if(!ist) throw std::runtime_error{"Invalid Data"};

    // Load Orders
    ist >> size; ist.ignore(32767, '\n');
    while(size--) orders.push_back(Order{ist});
    if(!ist) throw std::runtime_error{"Invali Data"};
}

void Store::save(std::ostream &ost)
{
	ost << customers.size()<<"\n";
	for(auto c: customers)
	{
		c.save(ost);
	}
	if (ost.bad()) throw std::runtime_error("Cannot read data file");
	
	
	
	ost << options.size()<<"\n";
	for(auto p: options)
	{
		p->save(ost);
	}
	if (ost.bad()) throw std::runtime_error("Cannot read data file");
	
	
	
	ost << desktops.size()<<"\n";
	for(auto d: desktops)
	{
		d.save(ost);
	}
	if (ost.bad()) throw std::runtime_error("Cannot read data file");
	
	
	ost << orders.size()<<"\n";
	for(auto k: orders)
	{
		k.save(ost);
	}
	if (ost.bad()) throw std::runtime_error("Cannot read data file");
		
}



