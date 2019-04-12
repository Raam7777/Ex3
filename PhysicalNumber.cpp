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
  if(this->value < 0){
    return PhysicalNumber(-1*(this->value), this->unit);
  }
  return PhysicalNumber(this->value, this->unit);
}

const PhysicalNumber PhysicalNumber::operator-() const
{
  return PhysicalNumber(-1*(this->value), this->unit);
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
  ++this->value;
  return (*this);
}

PhysicalNumber& PhysicalNumber::operator--()
{
  --this->value;
  return (*this);
}

const PhysicalNumber PhysicalNumber::operator++(int _value){
  PhysicalNumber temp = *this;
  ++this->value;
  return temp;
}
const PhysicalNumber PhysicalNumber::operator--(int _value){
  PhysicalNumber temp = *this;
  --this->value;
  return temp;
}

ostream& ariel::operator<<(ostream& stream, const PhysicalNumber& other)
{
  return stream << other.value << "[" << unit_name[other.unit] << "]";
}


istream& ariel::operator>>(istream& stream, PhysicalNumber& other)
{
  ios::pos_type startPosition = stream.tellg();
  string _value="", _unit, is;
  bool flag = true;
  stream>>is;
  _value = is.substr(0, is.find("["));
  _unit = is.substr(is.find("[")+1, is.length() - is.find("[")-2);

  if(_value.length()==0 || _unit.length()==0){
    flag=false;
  }

  if(flag){

    try{
      other.value = stod(_value);
    }catch(exception& e){
      flag = false;
      return stream;
    }
  }

  if(flag){
    for(int i=0; i<9; i++) {
      if(unit_name[i] == _unit) {
        other.unit = (Unit)i;
      }
      else{
        flag = false;
      }
    }
  }



  if(!flag){
    auto errorState = stream.rdstate();
    stream.clear();
    stream.seekg(startPosition);
    stream.clear(errorState);
  }
  return stream;
}
