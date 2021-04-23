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

int solve(vi a, int d)
{
    int ans = a[0];
    for (int i = 1, n = a.size(); i < n; ++i)
    {
        int days = min(d, a[i] * i);
        d -= days;
        ans += days / i;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vi a(n);
        read(all(a));

        cout << solve(a, d) << endl;
    }
    return 0;
}
