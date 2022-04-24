#pragma once

#include <iostream>

class MyArray {

  public:
      MyArray();//konstruktor domyślny
      explicit MyArray(int);//konstruktor jednoargumentowy
      MyArray(const MyArray &);//konstruktor kopiujący
      MyArray(MyArray &&);//konstruktor przenoszący
      ~MyArray();//destruktor

      
//operatory
      friend std::ostream& operator <<(std::ostream&, const MyArray &);//zaprzyjaźniony operator << do wypisywania obiektu
      int &operator []( int)const;//zwraca wartość elemntu o podanym indeksie
      
      MyArray& operator ++();//operator preinkrementacji ,zwraca kopie obiektu przed inkrementacja
      MyArray operator --(int);//operator postdekrementacji
      MyArray &operator =(const MyArray& tab);//operator przypisania
      MyArray & operator =(MyArray &&);//operator dolaczenia do listr, zwraca obiekt ktory chcemy dodac do listy

      void operator +=(MyArray &);//dodaje do listy nowa tablice
      void operator +=(MyArray &&);//dodaje elementy do listy




      int size()const;//zwraca rozmiar pojedynczej tablicy
      void print(const char *)const;//wypisuje liste
      MyArray& getNext();//zwraca wskaznik na następny element listy
      int sizeall()const;//zwraca ilosc intow w liscie


  private:
      int *_values;
      int _size;
      MyArray *_next;
};