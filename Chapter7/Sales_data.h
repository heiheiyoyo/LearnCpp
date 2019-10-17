#include <iostream>
#include <string>

class Sales_data {
  friend std::ostream& print(std::ostream&,const Sales_data&);
public:
  Sales_data()=default;
  Sales_data(const std::string &s) :bookNo(s) {}
  Sales_data(const std::string &s,unsigned n, double p) 
    :bookNo(s),units_sold(n),revenue(p*n) {}
  Sales_data(std::istream&);
  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);
private:
  double avg_price() const;
  std::string bookNo{""}; //using initializer_list to set a default value
  unsigned units_sold = 0;
  double revenue = 0.0;
};


std::ostream& print(std::ostream&,const Sales_data&);