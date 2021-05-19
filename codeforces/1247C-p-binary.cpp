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

int needed(ll x) { return __builtin_popcountll(x); }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n, p;
    cin >> n >> p;

    int m = 1;
    while (n - m * p > 0 and n - m * p >= m)
    {
        if (needed(n - m * p) <= m)
        {
            cout << m << endl;
            return 0;
        }
        ++m;
    }
    cout << -1 << endl;
    return 0;
}
