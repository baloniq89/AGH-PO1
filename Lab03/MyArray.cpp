#include "MyArray.h"

MyArray::MyArray(): _size(0), _values(nullptr), _next(nullptr){}


MyArray::MyArray(int rozmiar):_size(rozmiar){

  _values = new int [_size];
  for(int i=0; i<_size; i++)
  {
    _values[i] = 0;
  }
  _next = nullptr;

}

MyArray::MyArray(const MyArray &copy){
  this->_size = copy._size;
  if(_size > 0){
    _values = new int[_size];

    for(int i=0; i<_size;i++)
    {
      _values[i] = copy._values[i];
    }
  }

  _next = copy._next;
}

MyArray::MyArray(MyArray && mv): _size(std::__exchange(mv._size, 0)), _values(std::__exchange(mv._values, nullptr)), _next(std::__exchange(mv._next, nullptr)){}


MyArray::~MyArray(){
  _size = 0;
  delete [] _values;
}

int MyArray::size()const{
  return _size;
}

//operatory

std::ostream& operator <<(std::ostream & stm, const MyArray & tab){
  std::cout<<"["<< tab._values[0];
  for(int i=1; i<tab._size;i++)
  {
    std::cout<<", "<<tab._values[i];
  }
  std::cout<<"]";

  return stm;
  
}


int& MyArray::operator[]( int i)const{
  if(_size <= i){
    return _next->_values[i - _size];
  }else
    return _values[i];
} 

 


MyArray& MyArray::operator++(){
  
  for(int i=0; i<_size; i++)
  {
    ++_values[i];
  }
  return *this;
}

MyArray MyArray::operator --(int){
  MyArray *temp = this;
  for(int i=0; i<_size; i++)
  {
    _values[i]--;
  }
  return *temp;
}

MyArray& MyArray::operator =(const MyArray& tab){

  if(&tab != this)
  {
    if(tab._values == nullptr)
    {
      _size = tab._size;
      _values = new int [_size];
      for(int i=0; i<_size; i++)
        {
          _values[i] = tab._values[i];
        }

    }else if(tab._values !=nullptr)
    {
      delete[] _values;

      if(_size >0)
      {
        _size = tab._size;
        _values = new int [_size];
        for(int i=0; i<_size; i++)
        {
          _values[i] = tab._values[i];
        }
      }
    }
  _next = tab._next;
  }
  return *this;
}

MyArray& MyArray::operator =(MyArray && mv){
  delete [] _values;
  _size = std::__exchange(mv._size, 0);
   _values = std::__exchange(mv._values, nullptr);
  _next = std::__exchange(mv._next, nullptr);
}

void MyArray::operator +=(MyArray & new_tab){
  if(_next != nullptr)
  {
    *_next += new_tab;
  }else{
    _next = &new_tab;
  }

}
void MyArray::operator +=(MyArray && new_tab){
  MyArray temp(new_tab);
  int temp_size = temp_size + _size;
  int *temp_arr = new int[temp_size];

  for(int i=0; i<_size;i++)
  {
    temp_arr[i] = _values[i];
  }
  for(int j=_size; j<temp_size;j++)
  {
    temp_arr[j] = temp._values[j];
  }

  _size = temp_size;
  delete [] _values;
  _values = temp_arr;
  
}

void MyArray::print(const char * string)const{
  std::cout<< string <<" ";
  MyArray *temp = _next;

  while(temp->_next != nullptr)
  {
    std::cout<<*temp;
    temp = temp->_next;
  }
}

MyArray& MyArray::getNext(){
  return *_next;
}

int MyArray::sizeall()const{
  return _size;
}