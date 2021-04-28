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

pair<ll, int> solve(vector<ll> x, vector<ll> p)
{
    int        n = x.size(), m = p.size();
    vector<ll> dx(n);
    adjacent_difference(all(x), begin(dx));
    ll g = accumulate(begin(dx) + 1, end(dx), 0LL, gcd<ll, ll>);
    for (int i = 0; i < m; ++i)
        if (g % p[i] == 0)
            return {x[0], i};
    return {-1LL, -1};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), p(m);
    read(all(x)), read(all(p));

    if (auto [y, j] = solve(x, p); y != -1)
    {
        cout << "YES" << endl;
        cout << y << " " << j + 1 << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
