#include "desktop.h"

Desktop::Desktop()
{

}

Desktop::Desktop(std::istream& ist)
{
	int size;
	ist >> size;
	ist.ignore(32767, '\n');
	for(int i = 0; i < size; i++){
		Options* component = new Options(ist);
		options.push_back(component);
	}
}

void Desktop::add_option(Options& option) 
{
	options.push_back(&option);
}

double Desktop::price() 
{
    double p = 0.0;
    for(auto o : options) p+= o->cost();
    return p;
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop) 
{
    ost << "Desktop includes";
    for(auto o : desktop.options) ost << "\n  " << *o;
    return ost;
}

void Desktop::save(std::ostream& ost)
{
	ost << options.size() << "\n";
	for (int i = 0; i < options.size(); i++){
		options.at(i)->save(ost);
	}
}
