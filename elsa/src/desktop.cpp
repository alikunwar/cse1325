#include "desktop.h"

Desktop::Desktop() {}
void Desktop::add_option(Options& option)
{
  options.push_back(&option);
}

double Desktop::price()
{
    double pr= 0;
    int i;
    for(auto o: options)
    {
    pr += o->cost();
    }
 return pr;
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
   
		options.push_back(new Options{ist});
	}
}
