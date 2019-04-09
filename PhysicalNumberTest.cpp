/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);


    //my test.
    PhysicalNumber way_a(3, Unit::KM);
    PhysicalNumber way_b(500, Unit::M);
    PhysicalNumber way_c(1000, Unit::CM);

    PhysicalNumber time_a(2, Unit::HOUR);
    PhysicalNumber time_b(30, Unit::MIN);
    PhysicalNumber time_c(15, Unit::SEC);

    PhysicalNumber massa_a(10, Unit::TON);
    PhysicalNumber massa_b(500, Unit::KG);
    PhysicalNumber massa_c(20, Unit::G);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

      .setname("my test")
    .CHECK_OUTPUT(way_a, "3[km]") .CHECK_OUTPUT(way_b, "500[m]") .CHECK_OUTPUT(way_c, "1000[cm]")
    .CHECK_OUTPUT(time_a, "2[hour]") .CHECK_OUTPUT(time_b, "30[min]") .CHECK_OUTPUT(time_c, "15[sec]")
    .CHECK_OUTPUT(massa_a, "10[ton]") .CHECK_OUTPUT(massa_b, "500[kg]") .CHECK_OUTPUT(massa_c, "20[g]")

    .setname("My test - math operation: + , - , += , -= ")
    .CHECK_OUTPUT(way_a+way_b, "3.5[km]") .CHECK_OUTPUT(way_b+way_c, "510[m]") .CHECK_OUTPUT(way_c+way_a, "301000[cm]")
    .CHECK_OUTPUT(time_a+time_b, "2.5[hour]") .CHECK_OUTPUT(time_b+time_c, "30.25[min]") .CHECK_OUTPUT(time_c+time_a, "7215[sec]")
    .CHECK_OUTPUT(massa_a+massa_b, "10.5[ton]") .CHECK_OUTPUT(massa_b+massa_c, "500.02[kg]")
    .CHECK_OUTPUT(way_a-way_b, "2.5[km]") .CHECK_OUTPUT(way_b-way_c, "490[m]") .CHECK_OUTPUT(way_c-way_a, "-299000[cm]")
    .CHECK_OUTPUT(time_a-time_b, "1.5[hour]") .CHECK_OUTPUT(time_b-time_c, "29.75[min]") .CHECK_OUTPUT(time_c-time_a, "-7185[sec]")
    .CHECK_OUTPUT(massa_a-massa_b, "9.5[ton]") .CHECK_OUTPUT(massa_b-massa_c, "499.98[kg]")
    .CHECK_OUTPUT((way_a+=way_b), "3.5[km]") .CHECK_OUTPUT((way_b+=way_c), "510[m]") .CHECK_OUTPUT((way_c+=way_a), "351000[cm]")
    .CHECK_OUTPUT((time_a-=time_b), "1.5[hour]") .CHECK_OUTPUT((time_b-=time_c), "29.75[min]") .CHECK_OUTPUT((time_c-=time_a), "-5385[sec]")

    .setname("My test - operate comparison: < , > , <= , >= , == , != ")
    .CHECK_EQUAL(time_a==PhysicalNumber(1.5, Unit::HOUR), true) .CHECK_EQUAL(time_a!=PhysicalNumber(180, Unit::MIN), true) .CHECK_EQUAL(time_a>=PhysicalNumber(3000, Unit::SEC), true)
    .CHECK_EQUAL(way_a>PhysicalNumber(1.75, Unit::KM), true) .CHECK_EQUAL(way_a<PhysicalNumber(4000, Unit::M), true)

    .setname("My test - onary operation: +, - ")
    .CHECK_OUTPUT(+massa_a, "10[ton]")
    .CHECK_OUTPUT(-massa_b, "-500[kg]")

    .setname("My test - add and subtract: ++, -- ")
    .CHECK_OUTPUT(++time_b, "30.75[min]")
    .CHECK_OUTPUT(--time_b, "29.75[min]")

    .setname("My test - IO-stream: <<, >>")
    .CHECK_OK(istringstream("5[kg]") >> way_a)
    .CHECK_OUTPUT((way_a += PhysicalNumber(7, Unit::KG)), "12[kg]")
    .CHECK_THROWS(way_a -=PhysicalNumber(8,Unit::HOUR))


    .setname("Test Exception")
    .CHECK_THROWS(way_a+time_b) .CHECK_THROWS(time_c+massa_a) .CHECK_THROWS(massa_a+time_c)
    .CHECK_THROWS(way_b-time_c) .CHECK_THROWS(time_c-massa_c) .CHECK_THROWS(massa_c-way_c)


      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
