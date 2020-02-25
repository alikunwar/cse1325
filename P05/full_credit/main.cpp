//Alisha Kunwar 1001668106


#include "taxed.h"
#include "taxfree.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 
#include <exception>


int main()
{
	int quantity, index;
	std::vector<Taxed> taxed_cart;    //Storing taxfree items in a vector
	std::vector<Taxfree> taxfree_cart;  //Storing taxed items in a vector
	
	
	do
	{
		
		
	std::cout << "\n====================\n";
	std::cout <<"Welcome to the store\n";
	std::cout << "====================\n";
	
	int i =0;
	std::cout<< i <<") Milk($2.85)\n";
	std::cout<< i+1 <<") Bread($1.99)\n";
	std::cout<< i+2 <<") Cheese($0.99)\n";
	std::cout<< i+3 <<") Ice Cream($4.95)\n";
	std::cout<< i+4 <<") Poptarts($3.49)\n";
	std::cout<< i+5 <<") Oreos($5.99)\n";
	


	
	std::cout << "\n\nEnter quantity (0 to exit) and product index: ";
	std::cin>>quantity;
	std::cin>>index;
	std::cout << "\n" ;
	
	
  	try{   
	  if((quantity <0)||(index<0 || index>5)){
		  throw 0;  //throwing an exception for invalid input
	  }
	}
	catch(int e){
		std::cout<<"Negative quantity or undefined grocery items\n";
        continue;		
	}

	
	std::cout <<"====================\n";
	std::cout <<"Welcome to the store\n";
	std::cout <<"====================\n";
	
	
	std::cout<< i <<") Milk($2.85)\n";
	std::cout<< i+1 <<") Bread($1.99)\n";
	std::cout<< i+2 <<") Cheese($0.99)\n";
	std::cout<< i+3 <<") Ice Cream($4.95)\n";
	std::cout<< i+4 <<") Poptarts($3.49)\n";
	std::cout<< i+5 <<") Oreos($5.99)\n\n\n";
	
	
	
	if(index == 0)
	{
		Taxfree b{"Milk" , 2.85};  //Passing string name and cost in the class Taxfree by creating object
		b.set_quantity(quantity);  //Adding input quantity  to the vector
		taxfree_cart.push_back(b);
		
		
	}
	else if(index == 1)
	{
		Taxfree b{"Bread" , 1.99};
		b.set_quantity(quantity);
	    taxfree_cart.push_back(b);
		 
	}
	else if(index == 2)
	{
		Taxfree b{"Cheese" , 0.99};
		b.set_quantity(quantity);
		taxfree_cart.push_back(b);
		
	}
	else if(index == 3)
	{
		Taxed b{"Ice cream" , 4.95};
		b.set_quantity(quantity);
		taxed_cart.push_back(b);
		
	}	
	else if(index == 4)
	{
		Taxed b{"Poptarts" , 4.95};
		b.set_quantity(quantity);
		taxed_cart.push_back(b);
		
	}
	else if(index == 5)
	{
		Taxed b{"Oreos", 5.99};
		b.set_quantity(quantity);
		taxed_cart.push_back(b);
		 
	}
	std::cout<< "Current order " << std::endl;
	std::cout <<"-----------\n";
	
	double total = 0;
    for(int i = 0; i<taxfree_cart.size() ; i++)
	{
		std::cout << taxfree_cart[i] << std::endl;   //Calling the elements of index i 
		total = total + taxfree_cart[i].price();      //Calculating the price of the respected items
	}

	for(int i = 0; i< taxed_cart.size() ; i++)
	{
		std::cout << taxed_cart[i] << std::endl; 
		total = total + taxed_cart[i].price();
	}
	std::cout<<"Total price :"  << std::fixed << std::setprecision(2) << total<< "\n\n"; // Showing two digits of decimal places
	 
 }

	while(quantity!=0);
		
}