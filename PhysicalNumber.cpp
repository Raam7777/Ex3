#include <iostream>
#include <sstream>
#include "Unit.h"
#include "PhysicalNumber.h"

using namespace std;
using namespace ariel;

PhysicalNumber::PhysicalNumber(double _value, Unit _unit)
{
  value = _value;
  unit = _unit;
}

PhysicalNumber::PhysicalNumber(const PhysicalNumber& other)
{
  value = other.value;
  unit = other.unit;
}

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& other) const
{
  if(this->unit/3 != other.unit/3)
  {
    throw "diffrent unit";
  }
  double v = unit_value[unit]*(this->value/double(unit_value[this->unit]) + other.value/double(unit_value[other.unit]));
  return PhysicalNumber(v, this->unit);
}

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& other) const
{
  if(this->unit/3 != other.unit/3)
  {
    throw "diffrent unit";
  }
  double v = unit_value[unit]*(this->value/double(unit_value[this->unit]) - other.value/double(unit_value[other.unit]));
  return PhysicalNumber(v, this->unit);
}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other)
{
  if(this->unit/3 != other.unit/3)
  {
    throw "diffrent unit";
  }
  double v = unit_value[unit]*(this->value/double(unit_value[this->unit]) + other.value/double(unit_value[other.unit]));
  this->value = v;
  return *this;
}

PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other)
{
  if(this->unit/3 != other.unit/3)
  {
    throw "diffrent unit";
  }
  double v = unit_value[unit]*(this->value/double(unit_value[this->unit]) - other.value/double(unit_value[other.unit]));
  this->value = v;
  return *this;
}


const PhysicalNumber PhysicalNumber::operator+() const
{
  return PhysicalNumber(this->value, this->unit);
}

const PhysicalNumber PhysicalNumber::operator-() const
{
  return PhysicalNumber(-(this->value), this->unit);
}


bool ariel::operator==(const PhysicalNumber& left, const PhysicalNumber& right)
{
  if(left.unit/3 != right.unit/3)
  {
    throw "diffrent unit";
  }
  double v = unit_value[right.unit]*(left.value/double(unit_value[left.unit]));
  return v == right.value;
}

bool ariel::operator<=(const PhysicalNumber& left, const PhysicalNumber& right)
{
  if(left.unit/3 != right.unit/3)
  {
    throw "diffrent unit";
  }
  double v = unit_value[right.unit]*(left.value/double(unit_value[left.unit]));
  return v <= right.value;
}

bool ariel::operator>=(const PhysicalNumber& left, const PhysicalNumber& right)
{
  if(left.unit/3 != right.unit/3)
  {
    throw "diffrent unit";
  }
  double v = unit_value[right.unit]*(left.value/double(unit_value[left.unit]));
  return v >= right.value;
}

bool ariel::operator<(const PhysicalNumber& left, const PhysicalNumber& right)
{
  if(left.unit/3 != right.unit/3)
  {
    throw "diffrent unit";
  }
  double v = unit_value[right.unit]*(left.value/double(unit_value[left.unit]));
  return v < right.value;
}

bool ariel::operator>(const PhysicalNumber& left, const PhysicalNumber& right)
{
  if(left.unit/3 != right.unit/3)
  {
    throw "diffrent unit";
  }
  double v = unit_value[right.unit]*(left.value/double(unit_value[left.unit]));
  return v > right.value;
}

bool ariel::operator!=(const PhysicalNumber& left, const PhysicalNumber& right)
{
  return !(left == right);
}


PhysicalNumber& PhysicalNumber::operator++()
{
  this->value = this->value + 1;
  return (*this);
}

PhysicalNumber& PhysicalNumber::operator--()
{
  this->value = this->value - 1;
  return (*this);
}

const PhysicalNumber PhysicalNumber::operator++(int _value){
  PhysicalNumber temp = *this;
  this->value = this->value + 1;
  return temp;
}
const PhysicalNumber PhysicalNumber::operator--(int _value){
  PhysicalNumber temp = *this;
  this->value = this->value - 1;
  return temp;
}

ostream& ariel::operator<<(ostream& stream, const PhysicalNumber& other)
{
  return stream << other.value << "[" << unit_name[other.unit] << "]";
}

istream& ariel::operator>>(istream& stream, PhysicalNumber& other)
{
  // double _value;
  // Unit _unit;
  //
  //   ios::pos_type startPosition = stream.tellg();
  //
  //   if ( (!(stream >> _value))                 ||
  //        (!getAndCheckNextCharIs(stream,'[')) ||
  //        (!(stream >> _unit))                 ||
  //        (!(getAndCheckNextCharIs(stream,']'))) ) {
  //
  //       // rewind on error
  //       auto errorState = stream.rdstate(); // remember error state
  //       stream.clear(); // clear error so seekg will work
  //       stream.seekg(startPosition); // rewind
  //       stream.clear(errorState); // set back the error flag
  //   } else {
  //       other.value = _value;
  //       other.unit = _unit;
  //   }

  return stream;
}
