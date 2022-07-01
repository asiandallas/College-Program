#include <iostream>
using namespace std;

#ifndef PRICE_H
#define PRICE_H

class Price
{
 friend ostream& operator<<(ostream& o,const Price& p);

 private:
  int dollar;
  int cent;

 public: 
  Price(int d, int c);
  Price();
  Price operator+(const Price& m);
  Price operator-(const Price& m);
};
#endif
