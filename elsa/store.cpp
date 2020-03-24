#include "store.h"


void Store::add_customer(Customer& customer)
{
	customers.push_back(&customer);

}

int Store::num_customers()
{
	return customers.size();
}
	
	
Customer& Store::customer(int index)
{
	return customers.at(index);	
		
}
	
	
void Store::add_option(Options& option)
{
	options.push_back(&option);
}

	
int Store::num_options()
{
	return options.size();
	
}
	
	
Options& Store::option(int index)
{
	return *options.at(index);		
}
	
	
int Store::new_desktop()
{
	desktops.push_back(desktop);
	return desktops.at(index);	
}


void Store::add_option(int option, int desktop)
{
	desktops.at(desktop).add_option(options->at(option));	
}

int Store::num_desktops()
{
	return desktops.size();
}

Desktop& Store::desktop(int index)
{
	return desktop.at(index);
}

int Store::new_order(int customer)
{
	customers.push_back(customer);
	return .at(index);
}

void Store::add_desktop(int desktop, int order)
{
	orders.at(order).add_product(desktop.at(desktop));	
}

int Store::num_orders()
{
	return orders.size();
}

Order& Store::order(int index)
{
	return order->at(index);
}