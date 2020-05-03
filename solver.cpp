#include <iostream>
#include <complex>
#include "solver.hpp"

using namespace std;

namespace solver
{
//*******************Solve functions*******************

//A function that solves equations with complex numbers.
std::complex<double> solve(const ComplexVariable &y)
{
    complex<double> ans = 0.0;
    if (y.a() != 0.0 && y.b() != 0.0 && y.c() == 0.0)
    { //a,bx,0
        ans = (y.a() / y.b()) * (-1.0);
        return ans;
    }
    else if (y.a() == 0.0 && y.b() != 0.0 && y.c() == 0.0)
        return 0.0;
    else if ((y.a() != 0.0 && y.c() != 0.0)||(y.b() != 0.0 && y.c() != 0.0))
    {
        complex<double> s = sqrt(y.b() * y.b() - 4.0 * y.a() * y.c());
        ans = (-y.b() + s) / (2.0 * y.c());
        return ans;
    }
    else
        throw runtime_error("Can't solve this equation.");
}
//A function that solves equations with real numbers.
double solve(const RealVariable &x)
{
    double ans = 0;
    if (x.a() != 0 && x.b() != 0 && x.c() == 0)
    { //a,bx,0
        ans = (x.a() / x.b()) * (-1);
        return ans;
    }
    else if (x.a() == 0 && x.b() != 0 && x.c() == 0)
        return 0;
    else if(x.a() == 0 && x.b() == 0 && x.c() != 0)
        return 0;
    else if ((x.a() != 0 && x.c() != 0)||(x.b() != 0 && x.c() != 0))
    {

        if ((x.b() * x.b() - 4 * x.a() * x.c()) < 0)
            throw runtime_error("exception: no real solution");
        else
        {
            double s = sqrt(x.b() * x.b() - 4 * x.a() * x.c());

            ans = (-x.b() + s) / (2 * x.c());
            return ans;
        }
    }
    else
        throw runtime_error("Can't solve this equation");
}
//*******************ComplexVariable operators*******************

const ComplexVariable operator+(const complex<double> &c1, const ComplexVariable &c2)
{
    return ComplexVariable(c2.a() + c1, c2.b(), c2.c());
}
const ComplexVariable operator-(const complex<double> &c1, const ComplexVariable &c2)
{
    return ComplexVariable(c1 - c2.a(), (-1.0) * c2.b(), (-1.0) * c2.c());
}
const ComplexVariable operator*(const complex<double> &c1, const ComplexVariable &c2)
{
    return ComplexVariable(c1 * c2.a(), c1 * c2.b(), c1 * c2.c());
}
const ComplexVariable operator/(const complex<double> &c1, const ComplexVariable &c2)
{
    if (c2.a() != 0.0 && c2.b() == 0.0 && c2.c() == 0.0)
    {
        return ComplexVariable(c1 / c2.a(), c2.b(), c2.c());
    }
    else
        throw runtime_error("Can't divide by 0");
}

const ComplexVariable operator==(const complex<double> &c1, const ComplexVariable &c2)
{
    return ComplexVariable(c1 - c2.a(), (-1.0) * c2.b(), (-1.0) * c2.c());
}

//*******************RealVariable operators*******************

const RealVariable operator+(const double &r1, const RealVariable &r2)
{
    return RealVariable(r1 + r2.a(), r2.b(), r2.c());
}
const RealVariable operator-(const double &r1, const RealVariable &r2)
{
    return RealVariable(r1 - r2.a(), (-1) * r2.b(), (-1) * r2.c());
}
const RealVariable operator*(const double &r1, const RealVariable &r2)
{
    return RealVariable(r1 * r2.a(), r1 * r2.b(), r1 * r2.c());
}
const RealVariable operator/(const double &r1, const RealVariable &r2)
{
    if (r2.b() == 0 && r2.c() == 0)
    {
        return RealVariable(r1 / r2.a(), r2.b(), r2.c());
    }
    else
        throw runtime_error("Can't divide");
}
const RealVariable operator==(const double &r1, const RealVariable &r2)
{
    return RealVariable(r1 - r2.a(), (-1) * r2.b(), (-1) * r2.c());
}

} // namespace solver
