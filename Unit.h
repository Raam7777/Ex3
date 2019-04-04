#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace ariel {
  enum Unit {
    KM, M, CM, HOUR, MIN, SEC, TON, KG, G
  };

  const string unit_name[9] = {"km", "m", "cm", "hour", "min", "sec", "ton", "kg", "g"};
  const int unit_value[9] = {1, 1000, 100000, 1, 60, 3600, 1, 1000, 1000000};
}
