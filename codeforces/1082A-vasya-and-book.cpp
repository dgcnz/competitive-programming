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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll const INF = 1e17;
        ll       n, x, y, d, ans = INF;
        cin >> n >> x >> y >> d;
        x--, y--, n--;
        if (y % d == x % d)
        {
            ans = min(ans, abs(x - y) / d);
        }
        if (y % d == 0)
        {
            ans = min(ans, ceil(x, d) + y / d);
        }
        if (y % d == n % d)
        {
            ans = min(ans, ceil(n - x, d) + (n - y) / d);
        }
        cout << (ans == INF ? -1 : ans) << endl;
    }
    return 0;
}
