#include "Sales_data.h"

double Sales_data::avg_price() const
{
  if(units_sold)
    return revenue/units_sold;
  else
    return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
  units_sold+=rhs.units_sold;
  revenue+=rhs.revenue;
  return *this;
}

Sales_data::Sales_data(std::istream& is)
{
  double price=0;
  is >> bookNo>>units_sold>>price;
  revenue=price*units_sold;
}

std::ostream& print(std::ostream& os,const Sales_data& item)
{
  os<<"isbn:"<<item.isbn()<<" units_sold:"<<item.units_sold<<" revenue:"<<item.revenue<<" avg_price:"<<item.avg_price();
  return os;
}