#include "desktop.h"


void Desktop::add_option(Options& option)
{
  options.push_back(&option);
}

double Desktop::price()
{
    double price= 0;
    int i;
    for(auto o: options)
    {
    price += o->cost();
    }
 return price;
}


int x =1;
std::ostream& operator<<(std::ostream& ost, const Desktop& desktop)
{
ost<< "Desktop includes";
for(auto o: desktop.options)ost << "\n " << *o;   
return ost;
}

void Desktop::save(std::ostream& ost)
{
	
	ost << options.size() << "\n";
	for (int i = 0; i < options.size(); i++){
		options.at(i)->save(ost);
	}
}


Desktop::Desktop(std::istream& ist)
{
	int size;
	ist >> size;
	ist.ignore(32767, '\n');
	for(int i = 0; i < size; i++)
	{
    Options* option = new Options(ist);
		options.push_back(option);
	}
}