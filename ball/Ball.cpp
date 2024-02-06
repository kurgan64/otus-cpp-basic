#include "Ball.hpp"

#include <cmath>
#include <istream>

/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
void Ball::setVelocity(const Velocity& velocity) {
  // TODO: место для доработки
  this->velocity = velocity;
}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() const {
  // TODO: место для доработки
  return velocity;
}

/**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter& painter) const {
  // TODO: место для доработки
  painter.draw(center, radius, color);
}

/**
 * Задает координаты центра объекта
 * @param center новый центр объекта
 */
void Ball::setCenter(const Point& center) {
  // TODO: место для доработки
  this->center = center;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() const {
  // TODO: место для доработки
  return center;
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const {
  // TODO: место для доработки
  return radius;
}

/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3.
 */
double Ball::getMass() const {
  // TODO: место для доработки
  return M_PI * sqrt(radius) * radius * 4. / 3.;
}
Ball::Ball(const double x, const double y, const double vx, const double vy,
           const double red, const double green, const double blue,
           const int radius, const bool isCollidable) {
  this->center.x = x;
  this->center.y = y;
  this->velocity.setVector({vx, vy});
  this->color = {red, green, blue};
  this->radius = radius;
  this->isCollidable = isCollidable;
};
Ball::Ball(const Point& center, const Point& vector, const Color& color,
           const double radius, const bool isCollidable) {
  this->center = center;
  this->velocity.setVector(vector);
  this->color = color;
  this->radius = radius;
  this->isCollidable = isCollidable;
}
bool Ball::IsCollidable() const { return isCollidable; };