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

int solve(vi a)
{
    int const INF = 1e6;
    int       n = a.size(), ans = INF;
    vi        last(n + 1, -1);
    for (int i = 0; i < n; ++i)
    {
        if (last[a[i]] != -1)
            ans = min(ans, i - last[a[i]] + 1);
        last[a[i]] = i;
    }
    return ans == INF ? -1 : ans;
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
