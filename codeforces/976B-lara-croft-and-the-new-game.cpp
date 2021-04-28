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

ii solve(ll n, ll m, ll k)
{
    if (k < n)
        return ii{k + 1, 1};

    k -= n;
    int c = k % (m - 1);
    int r = k / (m - 1);
    if (r % 2)
        c = (m - 2) - c;
    return {n - r, c + 2};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;

    auto ans = solve(n, m, k);

    cout << ans.first << " " << ans.second << endl;
    return 0;
}
