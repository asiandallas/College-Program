#include "price.h"

// default constructor

Price::Price()
{
  dollar = 0;
  cent = 0;
}

Price::Price(int d, int c)
{
  dollar = d;
  cent = c;
}

Price Price::operator+(const Price& m)
{
  int doll = this->dollar+m.dollar;
  int cen = this->cent+m.cent;
  Price p(doll, cen); // new object

  return p;
}

Price Price::operator-(const Price& m)
{
  int doll = this->dollar-m.dollar;
  int cen = this->cent-m.cent;
  Price p(doll, cen); // new object                                                                             
  return p;
}

ostream& operator<<(ostream& o, const Price& p)
{
  if(p.cent>100)
    {
      int diff = p.cent-100;
      if(diff<10)
	{
	  o << p.dollar+1 << "." << "0" << diff;
	}
      else
	{
	  o << p.dollar+1 << "." << diff;
	}
    }
  else if(p.cent==100)
    {
      o << p.dollar+1 << "." << "00";
    }
  else if(p.cent<0)
    {
      int diff = p.cent+100;
      o << p.dollar-1 << "." << diff;
    }
  else // normal
    {
      o << p.dollar << "." << p.cent;
    }
}
