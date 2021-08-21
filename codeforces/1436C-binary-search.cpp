#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/math/combinatorics.hpp>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint1000000007;

int solve(int n, int x, int pos)
{
    int l = 0, r = n;
    vi  cmpcnt(2, 0);
    while (l < r)
    {
        int m = (l + r) / 2;
        cmpcnt[m <= pos] += (m != pos);
        if (m <= pos)
            l = m + 1;
        else
            r = m;
    }
    // 0 : greater, 1 : less

    int const                NMAX = 1e3 + 11;
    Combinations<NMAX, mint> C;
    auto ans = C(x - 1, cmpcnt[1]) * C.factorial(cmpcnt[1]) *
               C(n - x, cmpcnt[0]) * C.factorial(cmpcnt[0]) *
               C.factorial(n - cmpcnt[0] - cmpcnt[1] - 1);
    return ans.val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, x, pos;
    cin >> n >> x >> pos;
    cout << solve(n, x, pos) << endl;
    return 0;
}
