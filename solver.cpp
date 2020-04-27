#include <iostream>
#include <complex>
#include "solver.hpp"

using namespace std;

namespace solver
{

std::complex<double> solve(ComplexVariable &y)
{
    return complex<double>(0);
}

double solve(RealVariable &x)
{
    return 0.0;
}

//*******************ComplexVariable operators*******************

const ComplexVariable operator+(const complex<double> c1, const ComplexVariable &c2)
{
    ComplexVariable temp(c2._a + c1, c2._b, c2._c);
        return temp;
}
const ComplexVariable operator-(const complex<double> c1, const ComplexVariable &c2)
{
    ComplexVariable temp(c1 - c2._a, c2._b, c2._c);
    return temp;
}
const ComplexVariable operator*(const complex<double> c1, const ComplexVariable &c2)
{
    ComplexVariable temp(c1 * c2._a, c1 * c2._b, c1 * c2._c);
    return temp;
}
const ComplexVariable operator/(const complex<double> c1, const ComplexVariable &c2)
{
    if (c2._a != 0.0 && c2._b == 0.0 && c2._c == 0.0)
        {
            ComplexVariable temp(c1 / c2._a, c2._b, c2._c);
            return temp;
        }
        else
            throw runtime_error("Can't divide by 0");
}

const ComplexVariable operator==(const complex<double> &c1, const ComplexVariable &c2)
{
    return c2;
}

//*******************RealVariable operators*******************

const RealVariable operator+(const double &r1, const RealVariable &r2)
{
    RealVariable temp(r1 + r2._a, r2._b, r2._c);
        return temp;
}
const RealVariable operator-(const double &r1, const RealVariable &r2)
{
    RealVariable temp(r1 - r2._a, r2._b, r2._c);
    return temp;
}
const RealVariable operator*(const double &r1, const RealVariable &r2)
{
    RealVariable temp(r1 * r2._a, r1 * r2._b, r1 * r2._c);
    return temp;
}
const RealVariable operator/(const double &r1, const RealVariable &r2)
{
    if (r2._a != 0 && r2._b == 0 && r2._c == 0)
        {
            RealVariable temp(r1 / r2._a,r2._b, r2._c);
            return temp;
        }
        else
            throw runtime_error("Can't divide by 0");
}
const RealVariable operator==(const double &r1, const RealVariable &r2)
{
    return r2;
}

} // namespace solver
