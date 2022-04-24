#pragma once
#include <iostream>


/**
Klasa testowa przechowujace ID obiektu oraz funkcje print oraz set
*/ 

class TestObject {

  public:
      /**
        bezargumentowy konstruktor domyślny
      */
      TestObject() = default;

      /**
        *kostruktor jednoargumentowy ustawiajacy ID obiektu
        *@param int
      */
      TestObject(int id) : _ID(id) {}

      /**
        dektruktor domyślny
      */
      ~TestObject() = default;

      /**
        *metoda sluzaca do wypisywania ID naszego obiektu  
      */
      void print ()const 
      {
        std::cout<<"Obiekt o identyfikatorze ID="<< _ID <<std::endl;
      }
      /**
        *setted ustawiajacy nowe ID obiektu
        *@param int
      */
      void set(int newID) 
      {
        _ID = newID;
      }



  private:
      int _ID;//zmienna przechowujaca ID obiektu
};