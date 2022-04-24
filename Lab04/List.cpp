#include "List.h"

void List::insert(int x){
  _array.push_back(x);
}


void List::print(std::string text) const{

  std::cout<< text << "[ ";
  for(unsigned int i=0; i<_array.size(); i++)
  {
    std::cout<< _array[i] << " ";
  }
  std::cout<<"]"<<std::endl;
}

int& List::operator [] (int i){

  return _array[i];
}

List List::filter(std::function<bool(int)> filtr){

    List list_of_results;
    unsigned int i = 0;
    while (i < _array.size())
    {
      if(filtr(_array[i]))
      {
        list_of_results.insert(_array[i]);
      }
      i++;
    }
  return list_of_results;

}