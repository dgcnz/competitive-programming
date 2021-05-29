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

string solve(vi a)
{
    int      n   = a.size();
    ll const INF = 1e17;

    set<ll> prefix_sums;
    ll      sum = 0, ans = -INF;
    for (int i = 0; i < n; ++i)
    {
        ll best = (i < n - 1 ? 0 : INF);
        if (i > 0)
            best = min(best, *prefix_sums.begin());
        sum += a[i];
        ans = max(ans, sum - best);
        prefix_sums.insert(sum);
    }
    return sum > ans ? "YES" : "NO";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        read(all(a));

        cout << solve(a) << endl;
    }
    return 0;
}
