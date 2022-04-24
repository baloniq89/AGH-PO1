#include "Table.h"

bool cmp(const Data &data1, const Data &data2, int c){
  return data1[c] < data2[c];
}

void Table::operator+=(const Data &new_data){

  _day.push_back(new_data);

}

void Table::print()const {

  for(auto &x : _day)
  {
    x.print();
  }
  std::cout<<std::endl;

}

Table& Table::sort(int column) {

  int temp = _day[0].size();

  for(auto & x : _day)
  {
    if(temp > x.size())
    {
      temp = x.size();
    }
  }

  if(column >= temp)
  {
    std::cout<< "Indeks " << column << " nieprawidlowy!\n";
    return *this;
  }

  using namespace std::placeholders;
  auto compare = std::bind(cmp, _1, _2, column);
  std::sort(_day.begin(), _day.end(), compare);

  return *this;

}

Table& Table::sortBy(std::function<bool(const Data&, const Data&)> cmp){

  std::sort(_day.begin(), _day.end(), cmp);

  return *this;

}