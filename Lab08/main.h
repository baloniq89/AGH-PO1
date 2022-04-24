#pragma once

#include "virtual.h"
#include <iostream>

/*

*Klasami wirtualnymi są : Drawable, ClosedShape oraz Transformable
*Klasa Point jest klasą opisująca punkt, ktora zawiera kazda inna klasa reprezentujaca obiekt
*Klasy pochodne:
  -klasa Circle (dziedziczy po Drawable, ClosedShape, Transformable)
  -klasa Section (dziedziczy po Drawable, Transformable)
  -klasa Deltoid (dziedziczy po Drawable, ClosedShape, Transformable)

*/

void draw(Drawable *my_draw) {
  my_draw->draw();
}

class Point {

  public:

      double _x;// wspolrzedna x punktu
      double _y;// wspolrzedna y punkt

      Point() = default;// konstruktor domyślny
      Point(double x, double y) : _x(x), _y(y) {}// konstruktor dwuargumentowy
      
      
      

      friend std::ostream & operator <<(std::ostream& stm, const Point & point)
      {
        stm << "("<<point._x << ", " << point._y << ")";

        return stm;
      }


  
};



class Circle : public Drawable, public ClosedShape, public Transformable{

  public:
      Circle(const Point & srodek, double r) : _mid(srodek), _radius(r) {}

      double length() override 
      {
        return (2*M_PI*_radius);
      }

      double area() const override
      {
        return (M_PI * _radius * _radius);
      }

      void shift(double xShift,double yShift) override
      {
        _mid._x = _mid._x + xShift;
        _mid._y = _mid._y + yShift;
      }

      void draw() override
      {
        std::cout<< "Rysujemy kolo o srodku" << _mid << "i promieniu" << _radius << std::endl;
      }





  protected:
      Point _mid;
      double _radius;


};



class Section : public Drawable, public Transformable {

  public:
      Section(const Point & mypoint1, const Point & myPoint2) : _p1(mypoint1), _p2(myPoint2){}

      double length() override
      {
        return sqrt(pow(_p1._x - _p2._x,2) + pow(_p1._y - _p2._y,2));
      }

      void draw() override
      {
        std::cout<< "Rysujemy odcinek od " << _p1 << " do " << _p2 << std::endl;
      }

      void shift( double xShift, double yShift) override
      {
        _p1._x = _p1._x + xShift;
        _p1._y = _p1._y + yShift;
        _p2._x = _p2._x + xShift;
        _p2._y = _p2._y + yShift;
      }

      Point getP1()const { return _p1;}
      Point getP2()const { return _p2;}
  protected:
      Point _p1;
      Point _p2;

};



class Deltoid : public Drawable, public ClosedShape, public Transformable {

  public:
      Deltoid(const Point & p1, const Point & p2, const Point & p3, const Point & p4) : _p1(p1), _p2(p2), _p3(p3), _p4(p4) {}

      Deltoid(const Section & diag1, const Section & diag2) : _p1(diag1.getP1()), _p2(diag2.getP1()), _p3(diag1.getP2()), _p4(diag2.getP2()) {}

      double length() override
      {
        Section a1(_p1, _p2);
        Section a2(_p2, _p3);
        Section a3(_p3, _p4);
        Section a4(_p4, _p1);

        return a1.length() + a2.length() + a3.length() + a4.length();
      }

      double area() const override
      {
        Section diag1(_p1, _p3);
        Section diag2(_p2, _p4);

        return diag1.length() * diag2.length();
      }

      void shift(double xShift, double yShift) override
      {
        _p1._x = _p1._x + xShift;
        _p1._y = _p1._y + yShift;

        _p2._x = _p2._x + xShift;
        _p2._y = _p2._y + yShift;

        _p3._x = _p3._x + xShift;
        _p3._y = _p3._y + yShift;

        _p4._x = _p4._x + xShift;
        _p4._y = _p4._y + yShift;
      }

      void draw() override
      {
        std::cout<< "Rysujemy deltoid o wierzchołkach "<< _p1 << ", "<< _p2 << ", "<< _p3 << ", " << _p4 << std::endl;
      }

  protected:
      Point _p1;
      Point _p2;
      Point _p3;
      Point _p4;


};