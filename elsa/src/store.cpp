
#include "store.h"

Store::Store(){}

//Customer

void Store::add_customer(Customer &customer)
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

void Store::add_option(Options &option)
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
{ // to order
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

Store::Store(std::istream& ist)
{
	
  int csize;
  ist >> csize ;
  ist.ignore(32767,'\n');
  int i;
  Customer customer(ist);
  for(i = 1; i <csize ; i++)
  {
	  Customer customer(ist);
     customers.push_back(customer);
     	 
  }
  
  if (!ist.bad()) throw std::runtime_error("Cannot read data file");
  
  
  ist >> csize ;
  ist.ignore(32767,'\n');
  
  
  for(i = 1; i <csize ; i++)
  {
     Order order(ist);
	 orders.push_back(order);
      
  }
  
  if (!ist.bad()) throw std::runtime_error("Cannot read data file");
  
  
  ist >> csize ;
  ist.ignore(32767,'\n');
  
  
  for(i = 1; i <csize ; i++)
  {
	  Options option;
     options.push_back(new Options{option});
		 
  }
  
  if (!ist.bad()) throw std::runtime_error("Cannot read data file");
  
 
  ist >> csize ;
  ist.ignore(32767,'\n');
  
  
  for(i = 1; i <csize ; i++)
  {
         Desktop desktop(ist);
		desktops.push_back(desktop);
     	 
  }
  
  if (!ist.bad()) throw std::runtime_error("Cannot read data file");
  

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
