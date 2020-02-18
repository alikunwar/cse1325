#include "coin.h"



	Coin(Coin_size size, Year year, string *notes:_size{size} year{year} *_notes{nullptr} {}
	{
		Coin::Coin
	};

	Coin::Coin(const Coin &rhs): _size{rhs.size()} _year{rhs.year()} *notes{nullptr} {}
	Coin& operator=(const Coin &rhs){
		if (this != &rhs) _notes = rhs.notes();
		return *this;
	}
	~Coin();
	string notes() const {return _notes;}
	void add_note(std::string s)
	{
	  if(!_	notes){
		  _notes = s;
	  }
	  else
	  {
		  notes = s;
	  }
	}
	
	std::ostream &operator<<(std::ostream &ost, const Coin& coin){
		ost << year << " " << "\n" << _notes;
		return ost;
	}