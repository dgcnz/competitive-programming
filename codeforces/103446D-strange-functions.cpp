#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/misc>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

pair<int, int> solve(int p, int q)
{
    int g = gcd(p, q);
    p /= g, q /= g;
    for (int a = 1; a * a <= q; ++a)
    {
        if (q % a == 0)
        {
            int b = q / a;
            if (a * a + b * b == p)
                return {a, b};
        }
    }

    return {0, 0};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int p, q;
        cin >> p >> q;
        auto [a, b] = solve(p, q);
        cout << a << " " << b << endl;
    }
    return 0;
}
