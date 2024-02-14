#pragma once
#include "Point.hpp"
#include "Velocity.hpp"

class Dust {
  public:
    Dust() = default;

  private:
    Point start;
    Velocity Velocity;
    int timeLife;
};