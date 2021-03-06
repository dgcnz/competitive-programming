#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/io>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll f(ll n, ll k)
{
    if (n < k)
        return n;
    return k + f((n - k) - (n - k) / 10, k);
}

ll solve(ll n)
{
    auto ok = [&](ll k) { return f(n, k) * 2 >= n; };
    itll l(1), r(n + 1);
    return *binary_search01(l, r, ok);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
