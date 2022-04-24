#pragma once 

#include <iostream>
#include <vector>

  /*
  * klasa będąca tablica asocjacyjną ,ktora przyjmuje 2 typy danych:  klucze T1 oraz wartosci T2
  */

template <typename T1, typename T2>
class Assoc {

  public:
      /** 
        kostruktor domyslny
      */
      Assoc() = default;

      /**
        destruktor domyslny 
      */
      ~Assoc() = default;

      /**
       *metoda dodajaca nowy klucz oraz nowa wartosc
       *@param T1 klucz 
       *@param T2 wartosc
      */
      void insert(T1 key, T2 value);

      /**
        *metoda wypisujaca wszystkie elementy
        *@param std::string text - prefiks wypisania  
      */
      void print(std::string text)const;

      /** 
        *operator [], zwracajacy referencje do warttosci znajdujacej sie pod podanych kluczem mykey
        *@param T1 - podany klucz
        *@return T2& - wartosc znadujaca sie pod kluczem 
      */
      T2& operator [](T1 mykey);

      /** 
        *metoda zwracajaca stala referencje do wartosci na podstawie klucza, jesli nie znajdziemy klucza dodajemy go do tablicy
        *@param T1 - podany klucz
        *@return const T2& - wartosc znadujaca sie pod kluczem 
      */
      const T2& operator [](T1 mykey)const;

      /** 
        *metoda sprawdzajaca czy w naszej tablicy istnieje element o zadanym kluczu mykey
        *@param T1
        *@bool - true or false
      */
      bool contains(T1 mykey)const;




  private:
      std::vector<T1> _key;
      std::vector<T2> _value;
};

/** 
        *metoda wypisujaca czy obiekt zostal znaleziony
        *@param bool
        *@std::string - "Znaleziono" lub "Nieleziono"
*/
std::string print(bool objectFound) {

  if(objectFound) {
    return "Znaleziono";
  }
  else {
    return "Nie Znaleziono";
  }

}


template <typename T>
std::string operator *(T value, int m){

  std::string newValue = "";

  for(unsigned int i = 0; i < static_cast<unsigned int>(m); i++)
  {
    newValue += static_cast<std::string>(value);
  }
  return newValue;

}

template <typename T>
std::string operator *(int m, T value) {

  std::string newValue = "";

  for(unsigned int i = 0; i < static_cast<unsigned int>(m); i++)
  {
    newValue += static_cast<std::string>(value);
  }
  return newValue;
}






template <typename T1, typename T2>
void Assoc<T1, T2>::insert(T1 key, T2 value) {

  _key.push_back(key);
  _value.push_back(value);
  
}

template <typename T1, typename T2>
void Assoc<T1, T2>::print(std::string text)const {

  for(unsigned int i = 0; i < _key.size(); i++)
  {
    std::cout<<"--- "<<text<<" --- klucz: "<<_key[i]<<" wartosc: "<<_value[i]<<std::endl;
  }
}

template <typename T1, typename T2>
T2& Assoc<T1, T2>::operator [](T1 mykey) {

  unsigned int i = 0;
  for(const auto& key : _key) 
  {
    if( key == mykey)
    {
      return _value[i];
    }
    i++;
  }
  _key.push_back(mykey);
  _value.push_back(T2());

  return _value[_value.size() - 1];

}

template <typename T1, typename T2>
const T2& Assoc<T1, T2>::operator [](T1 mykey)const {

  unsigned int i = 0;
  for(const auto& key : _key) 
  {
    if( key == mykey)
    {
      return _value[i];
    }
    i++;
  }

  return _value[0];

}

template <typename T1, typename T2>
bool Assoc<T1, T2>::contains(T1 mykey)const {

  for(const auto& key : _key) 
  {
    if( key == mykey)
    {
      return true;
    }
  }
  return false;

}