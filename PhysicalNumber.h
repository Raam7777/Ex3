#include <iostream>
#include "Unit.h"

namespace ariel {

  class PhysicalNumber {

  private:
    double value;
    Unit unit;

  public:

    //constractors
    PhysicalNumber(double _value, Unit _unit);
    PhysicalNumber(const PhysicalNumber& other);

    //math operation
    PhysicalNumber operator+(const PhysicalNumber& other) const;
    PhysicalNumber operator-(const PhysicalNumber& other) const;
    PhysicalNumber& operator+=(const PhysicalNumber& other);
    PhysicalNumber& operator-=(const PhysicalNumber& other);

    //onary operation
    const PhysicalNumber operator+() const;
    const PhysicalNumber operator-() const;

    //operate comparison
    friend bool operator==(const PhysicalNumber& left, const PhysicalNumber& right);
    friend bool operator<=(const PhysicalNumber& left, const PhysicalNumber& right);
    friend bool operator>=(const PhysicalNumber& left, const PhysicalNumber& right);
    friend bool operator<(const PhysicalNumber& left, const PhysicalNumber& right);
    friend bool operator>(const PhysicalNumber& left, const PhysicalNumber& right);
    friend bool operator!=(const PhysicalNumber& left, const PhysicalNumber& right);

    //add and subtract
    PhysicalNumber& operator++();
    PhysicalNumber& operator--();

    //IO-stream
    friend ostream& operator<<(ostream& stream, const PhysicalNumber& other);
    friend istream& operator>>(istream& stream, PhysicalNumber& other);
  };
}
