#include <iostream>
#include "Unit.h"
#include "PhysicalNumber.h"

using namespace std;
using namespace ariel;

PhysicalNumber::PhysicalNumber(double _value, Unit _unit)
{
  value = _value;
  unit = _unit;
}

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& other) const
{
    return *this + other;
}

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& other) const
{
  return *this - other;
}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other) const
{
  return *this += other;
}

PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other) const
{
  return *this -= other;
}


const PhysicalNumber PhysicalNumber::operator+() const
{
  return PhysicalNumber(this->value, this->unit);
}

const PhysicalNumber PhysicalNumber::operator-() const
{
  return PhysicalNumber(-(this->value), this->unit);
}


bool operator==(const PhysicalNumber& left, const PhysicalNumber& right)
{
  return true;
}

bool operator<=(const PhysicalNumber& left, const PhysicalNumber& right)
{
  return true;
}

bool operator>=(const PhysicalNumber& left, const PhysicalNumber& right)
{
  return true;
}

bool operator<(const PhysicalNumber& left, const PhysicalNumber& right)
{
  return true;
}

bool operator>(const PhysicalNumber& left, const PhysicalNumber& right)
{
  return true;
}

bool operator!=(const PhysicalNumber& left, const PhysicalNumber& right)
{
  return true;
}


PhysicalNumber& PhysicalNumber::operator++()
{
  ++this->value;
  return *this;
}

PhysicalNumber& PhysicalNumber::operator--()
{
  --this->value;
  return *this;
}

ostream& ariel::operator<<(ostream& stream, const PhysicalNumber& other)
{
  return stream << other.value << "[" <<unit_string[other.unit] << "]";
}

istream& ariel::operator>>(istream& stream, PhysicalNumber& other)
{
  return stream;
}
