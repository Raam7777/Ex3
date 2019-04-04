#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace ariel {
  enum Unit {
    KM, M, CM, HOUR, MIN, SEC, TON, KG, G
  };

  const string unit_string[9] = {"km", "m", "cm", "hour", "min", "sec", "ton", "kg", "g"};
}
