#include <iostream>
#include <complex>
#include "solver.hpp"
#include "doctest.h"
#include <stdexcept>

#define EPS 0.0001

using namespace std;
using namespace solver;

TEST_CASE("RealVariable"){
RealVariable x;

CHECK(abs(solve(2*x-4 == 10) - 7) < EPS);
CHECK((solve((x ^ 2) == 16.0) == 4)||(solve((x ^ 2) == 16.0) == -4));
CHECK((solve((x ^ 2) == 9.0) == 3)||(solve((x ^ 2) == 9.0) == -3));
CHECK((solve((x ^ 2) + 2 * x + 4.0 == 20 + 6.0 * x / 2 - x) == 4)||(solve((x ^ 2) + 2 * x + 4.0 == 20 + 6.0 * x / 2 - x) == -4));
CHECK(solve(2 * x - 4.0 == 10.0) == 7);
CHECK(solve(4 * x -3 + x == 6 * x) == -3);
CHECK((solve(10 * (x ^ 2) - 56 == 88 - 6 * (x ^ 2)) == 3)||(solve(10 * (x ^ 2) - 56 == 88 - 6 * (x ^ 2)) == -3));
CHECK(solve(5 * x - 6 == 3 * x -8) == -1);
CHECK(solve(9 + 5 * x == 3 * x) == -4.5);
CHECK((solve(2 * (x ^ 2) + 4 * x -6 == 0) == 1)||(solve(2 * (x ^ 2) + 4 * x -6 == 0) == -3));
CHECK(solve(7 * (x ^ 2) -14 * x == -7) == 1);
CHECK(solve(5 * x + 3 * x == 10 * x - 6 * x - 80) == -20);
CHECK(solve(3 * x + x * 4 -7 == 21) == 4);
CHECK(solve(55 - 8 * x == 7) == 6);
CHECK(solve(x / 9 + 8 == 13) == 45);
CHECK((solve((x ^ 2) == 81) == 9)||(solve((x ^ 2) == 81) == -9));
CHECK((solve(12 * (x ^ 2) - 12 == 0) == 1)||(solve(12 * (x ^ 2) - 12 == 0) == -1));
CHECK(solve(2 * x  == -1) == -0.5);
CHECK(solve(2 * x -6 == 10) == 8);
CHECK(solve(6 + x - 3 == 21 - 3.5 * x) == 4);
CHECK((solve(80 + (x ^ 2) == 18 * x) == 8)||(solve(80 + (x ^ 2) == 18 * x) == 10));
CHECK(solve(55 - 8 * x == 7) == 6);
CHECK((solve(8 * (x ^ 2) - 14 * x == 15) == 2.5)||(solve(8 * (x ^ 2) - 14 * x == 15) == -0.75));
CHECK(solve(16 - 2 * x == 5 * x + 9) == 1);
CHECK((solve(16 * (x ^ 2) == 49) == 1.75)||(solve(16 * (x ^ 2) == 49) == -1.75));
CHECK(solve(2 * x -5 == 11) == 8);
CHECK(solve(4 + 3 * x - 5 == 11) == 4);
CHECK(solve(6 + 2 * x - 5 == 19 - x) == 6);
CHECK((solve(3 * (x ^ 2) - 5 == 11 - (x^2)) == 2)||(solve(3 * (x ^ 2) - 5 == 11 - (x^2)) == -2));
CHECK((solve(77 + (x ^ 2) == 18 * x - 3) == 8)||(solve(77 + (x ^ 2) == 18 * x - 3) == 10));
CHECK(solve(3 * x - 9 == 0) == 3);
CHECK(solve((x * 3) == 0) == 0);
CHECK(solve(x * 6 + 8 == 2 * x + 12) == 1);
CHECK(solve(7 * x == x * 3 + 12) == 3);
CHECK(solve(6 * (x ^ 2) == 6 * (x ^ 2) - x + 12) == 12);
CHECK(solve(x * 3 + 4 * x - 8 == 20) == 4);
CHECK(solve(21 * x -8 == 5 * x) == 0.5);
CHECK(solve(x * 21 - 8 == 5 * x + 40) == 3);
CHECK(solve(55 - 9 * x == 1) == 6);
CHECK(solve(3 * x -4 == 5) == 3);


CHECK_THROWS(solve((x ^ 2) == -2));
CHECK_THROWS(solve((x ^ 3) == 0));
CHECK_THROWS(solve(x / 0) == 8);
CHECK_THROWS(solve(x ^ 2) == -16);
CHECK_THROWS(solve(x ^ 3) == 1);
CHECK_THROWS(solve(x / 0) == 3);
CHECK_THROWS(solve(x ^ 2) == -20);
CHECK_THROWS(solve(x ^ 3) == 3);
CHECK_THROWS(solve(x / 0) == 9);
CHECK_THROWS(solve(x ^ 2) == -7);


}
TEST_CASE("ComplexVariable"){
ComplexVariable y;

CHECK((solve((y ^ 2) == 16) == std::complex<double> (4.0, 0.0))||(solve((y ^ 2) == 16) == std::complex<double>(-4.0,0.0)));
CHECK((solve((y ^ 2) == -16) == std::complex<double>(0.0, 4.0))||(solve((y ^ 2) == -16) == std::complex<double>(0.0, -4.0)));
CHECK((solve((y ^ 2) + 2 * y + 4 == 20 + 6 * y / 2 - y) == std::complex<double>(4.0, 0.0))||(solve((y ^ 2) + 2 * y + 4 == 20 + 6 * y / 2 - y) == std::complex<double>(-4.0, 0.0)));
CHECK(solve(y + 5i == 2 * y + 3i) == std::complex<double>(0.0, 2.0));
CHECK(solve(2 * y + 5i == 3 * y + 5i) == std::complex<double>(0.0,0.0));
CHECK(solve(2 * y + 5i == 3 * y + 5i ^ 2) == std::complex<double>(5.0,5.0));
CHECK(solve(2 * y + 5i == 3 * y + (5i) ^ 2) == std::complex<double>(25.0,5.0));
CHECK(solve(2 * y + 5i == 3 * y + 5i + 5) == std::complex<double>(-5.0,0.0));
CHECK(solve(4i == -4 * y + 4i +8) == std::complex<double>(2.0,0.0));
CHECK(solve(4i + 8 * y == - 4 * y + 4i + 12) == std::complex<double>(1.0,0.0));
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);
CHECK(solve(1) == 1);


CHECK_THROWS(solve(y ^ 3) == std::complex<double>(25.0,5.0));
CHECK_THROWS(solve(y ^ 3) == std::complex<double>(-25.0,-5.0));
CHECK_THROWS(solve(y / 0)== std::complex<double>(2.0,2.0));
CHECK_THROWS(solve(y ^ 3) == std::complex<double>(3.0,3.0));
CHECK_THROWS(solve(y ^ 3) == std::complex<double>(-1.0,-4.0));
CHECK_THROWS(solve(y / 0) == std::complex<double>(0.0,0.0));
CHECK_THROWS(solve(y ^ 3) == std::complex<double>(45.0,23.0));
CHECK_THROWS(solve(y ^ 3) == std::complex<double>(-45.0,-3.0));
CHECK_THROWS(solve(y / 0) == std::complex<double>(4.0,4.0));
CHECK_THROWS(solve(2 * y + 5i == 2 * y + 5i) == std::complex<double>(100.0,100.0));

 }
