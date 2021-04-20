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

int solve(int m, ll k, vector<ll> p)
{
    int  i = 0, removed = 0, ans = 0;
    auto pos   = [&](ll pi) -> ll { return pi - removed; };
    auto block = [&](ll pi) -> ll { return ll(pos(pi) - 1) / k; };
    while (i < m)
    {
        auto ok = [&](ll pi) { return block(pi) == block(p[i]); };
        int  j  = i;
        while (j < m and ok(p[j]))
            ++j;
        removed += j - i;
        ans += 1;
        i = j;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll  n, k;
    int m;
    cin >> n >> m >> k;
    vector<ll> p(m);
    read(all(p));
    cout << solve(m, k, p) << endl;
    return 0;
}
