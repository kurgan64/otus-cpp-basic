#pragma once
// #include <iosfwd>
#include <istream>

#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"
class Ball {
  public:
    Ball() = default;
    Ball(const Point& center, const Point& vector, const Color& color,
         const double radius, const bool isCollidable);
    Ball(const double x, const double y, const double vx, const double vy,
         const double red, const double green, const double blue,
         const int radius, const bool isCollidable);
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
    bool IsCollidable() const;
    //   void setColor(Color& color);

  private:
    Point center;
    double radius;
    Velocity velocity;
    Color color;
    bool isCollidable;
};