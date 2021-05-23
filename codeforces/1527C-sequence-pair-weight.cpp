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

ll solve(vector<ll> a)
{
    int          n = a.size();
    map<int, ll> cntp;
    vector<ll>   dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + cntp[a[i - 1]];
        cntp[a[i - 1]] += i;
    }
    return accumulate(all(dp), 0LL);
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
        vector<ll> a(n);
        read(all(a));
        cout << solve(a) << endl;
    }
    return 0;
}
