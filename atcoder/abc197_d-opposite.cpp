#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll    = long long;
using ii    = pair<int, int>;
using vi    = vector<int>;
using Point = complex<double>;

pair<double, double> solve(int n, Point p0, Point pm)
{
    double theta = 2 * M_PI / n;
    Point  pc    = (p0 + pm) / 2.0;
    Point  p1    = (p0 - pc) * polar(1.0, theta) + pc;
    return {p1.real(), p1.imag()};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, x0, y0, xm, ym;
    cin >> n;
    cin >> x0 >> y0 >> xm >> ym;
    Point p0(x0, y0), pm(xm, ym);

    auto [x1, y1] = solve(n, p0, pm);
    cout << fixed << setprecision(12) << x1 << " " << y1 << endl;

    return 0;
}
