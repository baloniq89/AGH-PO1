#pragma once

#include <iostream>
#include <string>

//klasa Operation - podstawowa klasa zawierająca funnkcje witrualne
class Operation {

  public:

      Operation() = default;//konstruktor domyślny

      virtual ~Operation() = default;//virtulany domyślny destruktor

      virtual void print()const{}//virtulana funkcja wypisująca działanie matematyczne

      virtual double eval()const {return 0.0;}//virtulana funkcja zwracajaca wynik działania matemaycznego

      friend void operator >>= (const std::string &, const Operation &);// zaprzyjazniona funkcja wypisująca na ekran podany string oraz podaną operacje: string operacja string
};