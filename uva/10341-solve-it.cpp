#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// f(x) is non-increasing
// exp(-x)  : decreasing * >= 0     decreasing
// sin(x)   : increasing * <= 0     decreasing
// cos(x)   : decreasing * >= 0     decreasing
// tan(x)   : increasing * <= 0     decreasing
// x^2      : increasing * <= 0     decreasing

const double EPSILON = 1e-8;

int p, q, r, s, t, u;

inline double f(double x)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main(void)
{
    double lo, hi, y, yp, mid;
    y = 0;
    while (cin >> p >> q >> r >> s >> t >> u)
    {
        lo = 0, hi = 1;
        if (f(1) > 0 or f(0) < 0)
            cout << "No solution" << endl;
        else
        {
            do
            {
                mid = lo + (hi - lo) / 2;
                yp  = f(mid);
                if (yp > 0)
                    lo = mid;
                else
                    hi = mid;
            } while (abs(y - yp) > EPSILON);
            cout << fixed << setprecision(4) << mid << endl;
        }
    }
    return 0;
}
