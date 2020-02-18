#ifndef _COIN_H
#define _COIN_H

#include <iostream>
#include <string>
#include <exception>
#include "logger.h"

enum class Coin_size {PENNY, NICKEL, DIME, QUARTER};
typedef int Year;
class Coin
{

class Coin{
	
public:
	Coin(Coin_size size, Year year, string *notes);
	Coin(const Coin &rhs);
	Coin& operator=(const Coin &rhs);
	~Coin();
	void add_note(std::string s);
	
  friend std::ostream& operator<<(std::ostream& ost, const Coin& coin);
  friend std::istream &operator>>(std::istream &ist, Coin &coin);
	
private:

Coin_size _size;
Year _year;
string *_notes;

}


