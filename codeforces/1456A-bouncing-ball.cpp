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

int solve(int p, int k, string a, int x, int y)
{
    int        n = a.size();
    vector<ll> cost(n, 0);
    for (int i = n - 1; i >= 0; --i)
    {
        cost[i] = x * (a[i] == '0');
        if (i + k < n)
            cost[i] += cost[i + k];
    }

    p -= 1;
    ll ans = 1e17;
    for (int i = 0; i + p < n; ++i)
        ans = min(ans, i * y + cost[i + p]);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int    n, p, k, x, y;
        string a;
        cin >> n >> p >> k >> a >> x >> y;
        cout << solve(p, k, a, x, y) << endl;
    }
    return 0;
}
