#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll ceil(ll a, ll b) { return (a + b - 1) / b; }

array<int, 3> solve(int l, int r, ll m)
{
    for (int a = l; a <= r; ++a)
    {
        ll n = (m + r - l) / a;
        if (n > 0 and m - r + l <= n * a and n * a <= m - l + r)
        {
            int x = m - n * a;
            int b = x, c = 0;
            if (x > 0)
                b += l, c += l;
            else
                b += r, c += r;
            if (l <= b and b <= r)
                return {a, b, c};
        }
    }
    throw runtime_error("UNU");
    return {-1, -1, -1};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        ll  m;
        cin >> l >> r >> m;
        auto ans = solve(l, r, m);
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
