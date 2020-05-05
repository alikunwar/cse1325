#include "cart.h"
#include <vector>
#include <iterator>
#include <numeric>
#include <string>
#include <functional>
 
using namespace std;

Cart::Cart(std::string customer): _customer{customer},_items{}{};
	
	
Cart::Cart(const Cart& cart):_customer{cart._customer}, _items{}
{
	std::vector<Item*>::const_iterator itr;
    for (itr = cart._items.begin(); itr != cart._items.end(); itr++)
	{
        _items.push_back(new Item(**itr));
    }
	
}
	
	
Cart& Cart::operator=(const Cart& cart)     // Copy assignment
{                  
	 std::vector<Item*>::const_iterator itr;
    for (itr = cart._items.begin(); itr != cart._items.end(); itr++)
	{
        _items.push_back(new Item(**itr));
    }
	
    return *this; 
}



	
Cart::~Cart()
{
 while(!_items.empty())
 {
   delete _items.back();
  _items.pop_back();
  }
}


void Cart::add_item(Item& item)
{
	 _items.push_back(new Item{item});
	 
}



double Cart::cost()
{
	double dMean =0.0;
	//dMean = std::accumulate( _items.begin(), _items.end(), 0.0,
    //[] (double acc,  Item* _items) { return acc + _items->add_item(); });
	return dMean;
}



