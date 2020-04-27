#include <iostream>
#include <complex>

using namespace std;
namespace solver
{

class ComplexVariable
{

private:
    complex<double> _a; // power 0
    complex<double> _b; //power 1
    complex<double> _c; // power 2

public:
    // Constructor.
    ComplexVariable(const complex<double> &a = 0.0, const complex<double> &b = 0.0, const complex<double> &c = 0.0)
        : _a(a), _b(b), _c(c)
    {
    }
    // getters.
    complex<double> a() const
    {
        return _a;
    }

    complex<double> b() const
    {
        return _b;
    }
    complex<double> c() const
    {
        return _c;
    }

    //Operators.

    //operator+
    const friend ComplexVariable operator+(const complex<double> c1, const ComplexVariable &c2);

    const ComplexVariable operator+(const ComplexVariable &other) const
    {
        ComplexVariable temp(_a + other._a, _b + other._b, _c + other._c);
        return temp;
    }
    const ComplexVariable operator+(complex<double> other) const
    {
        ComplexVariable temp(_a + other, _b, _c);
        return temp;
    }
    //operator-
    const friend ComplexVariable operator-(const complex<double> c1, const ComplexVariable &c2);

    const ComplexVariable operator-(const ComplexVariable &other) const
    {
        ComplexVariable temp(_a - other._a, _b - other._b, _c - other._c);
        return temp;
    }
    const ComplexVariable operator-(const complex<double> other) const
    {
        ComplexVariable temp(_a - other, _b, _c);
        return temp;
    }
    //operator*
    const friend ComplexVariable operator*(const complex<double> c1, const ComplexVariable &c2);

    const ComplexVariable operator*(const ComplexVariable &other) const
    {
        return ComplexVariable(_a * other._a, _a * other._b + _b * other._a, _b * other._b);
    }
    const ComplexVariable operator*(const complex<double> other) const
    {
        ComplexVariable temp(_a * other, _b * other, _c * other);
        return temp;
    }
    //operator/
    const friend ComplexVariable operator/(const complex<double> c1, const ComplexVariable &c2);

    const ComplexVariable operator/(const ComplexVariable &other) const
    {
        if (other._a != 0.0 && other._b == 0.0 && other._c == 0.0)
        {
            ComplexVariable temp(_a / other._a, _b / other._a, _c / other._a);
            return temp;
        }
        else
            throw runtime_error("Can't divide by 0");
    }
    const ComplexVariable operator/(const complex<double> other) const
    {
        if (other != 0.0)
        {
            ComplexVariable temp(_a / other, _b / other, _c / other);
            return temp;
        }
        else
            throw runtime_error("Can't divide by 0");
    }
    //operator==
    const friend ComplexVariable operator==(const complex<double> c1, const ComplexVariable &c2);

    const ComplexVariable operator==(const ComplexVariable &other) const
    {
        return other;
    }
    const ComplexVariable operator==(const complex<double> other) const
    {
        return ComplexVariable();
    }
    //operator^
    const ComplexVariable operator^(const complex<double> other) const
    {
        if (other != 2.0)
            throw runtime_error("Can't use operator^ >2");
        if (_c != 0.0)
            throw runtime_error("Can't use operator^");
        else if (_a == 0.0 && _b != 0.0 && _c == 0.0) //bx
        {
            ComplexVariable temp(_a, 0, _b);
            return temp;
        }
        else if (_a != 0.0 && _b != 0.0 && _c == 0.0)
        { //(a+bx)^2=a^2+2ab+(bx)^2
            ComplexVariable temp(_a * _a, 2.0 * _a * _b, _b * _b);
            return temp;
        }
        else
            throw runtime_error("Can't use operator^");
    }
};

class RealVariable
{
private:
    double _a; // power 0
    double _b; // power 1
    double _c; // power 2

public:
    // Constructor.
    RealVariable(const double &a = 0.0, const double &b = 0.0, const double &c = 0.0)
        : _a(a), _b(b), _c(c)
    {
    }
    // getters.
    double a() const
    {
        return _a;
    }
    double b() const
    {
        return _b;
    }
    double c() const
    {
        return _c;
    }

    //Operators.
    //operator+
    const friend RealVariable operator+(const double &r1, const RealVariable &r2);

    const RealVariable operator+(const RealVariable &other) const
    {

        RealVariable temp(_a + other._a, _b + other._b, _c + other._c);
        return temp;
    }
    const RealVariable operator+(const double &other) const
    {
        RealVariable temp(_a + other, _b, _c);
        return temp;
    }
    //operator-
    const friend RealVariable operator-(const double &r1, const RealVariable &r2);

    const RealVariable operator-(const RealVariable &other) const
    {
        RealVariable temp(_a - other._a, _b - other._b, _c - other._c);
        return temp;
    }
    const RealVariable operator-(const double &other) const
    {
        RealVariable temp(_a - other, _b, _c);
        return temp;
    }
    //operator*
    const friend RealVariable operator*(const double &r1, const RealVariable &r2);

    const RealVariable operator*(const RealVariable &other) const
    {
        RealVariable temp(_a * other._a, _a * other._b + _b * other._a, _b * other._b);
        return temp;
    }
    const RealVariable operator*(const double &other) const
    {
        RealVariable temp(_a * other, _b * other, _c * other);
        return temp;
    }
    //operator/
    const friend RealVariable operator/(const double &r1, const RealVariable &r2);

    const RealVariable operator/(const RealVariable &other) const
    {
        if (other._a != 0 && other._b == 0 && other._c == 0)
        {
            RealVariable temp(_a / other._a, _b / other._a, _c / other._a);
            return temp;
        }
        else
            throw runtime_error("Can't divide by 0");
    }
    const RealVariable operator/(const double &other) const
    {
        if (other != 0)
        {
            RealVariable temp(_a / other, _b / other, _c / other);
            return temp;
        }
        else
            throw runtime_error("Can't divide by 0");
    }
    //operator==
    const friend RealVariable operator==(const double &r1, const RealVariable &r2);

    const RealVariable operator==(const RealVariable &other) const
    {
        return RealVariable();
    }
    const RealVariable operator==(const double &other) const;
    //operator^
    const RealVariable operator^(const double &other) const
    {
        if (other > 2)
            throw runtime_error("Can't use operator^ >2");

        if (_c != 0)
            throw runtime_error("Can't use operator^");
        else if (_a == 0 && _b != 0 && _c == 0) //bx
        {
            RealVariable temp(_a, 0, _b);
            return temp;
        }
        else if (_a != 0 && _b != 0 && _c == 0)
        { //(a+bx)^2=a^2+2ab+(bx)^2
            RealVariable temp(_a * _a, 2 * _a * _b, _b * _b);
            return temp;
        }
        else
            throw runtime_error("Can't use operator^");
    }
};

std::complex<double> solve(ComplexVariable &y);

double solve(RealVariable &x);

template <typename T>
double solve(T t);

} // namespace solver