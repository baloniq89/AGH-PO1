#pragma once
#include <cmath>

class Drawable {

  public:
      virtual ~Drawable() = default;
      virtual double length() = 0;
      virtual void draw() = 0;
};

class ClosedShape {

  public:
      virtual ~ClosedShape() = default;
      virtual double area()const = 0;

};

class Transformable {

  public:
      virtual ~Transformable() = default;
      virtual void shift(double, double) = 0;
};