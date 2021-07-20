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

ll sq(ll n) { return (n * (n + 1)) / 2; }

ll solve(vi a)
{
    int n = a.size();
    if (n < 3)
        return sq(n);
    ll          ans = sq(2);
    vector<int> dp(n, -1);
    for (int i = 2; i < n; ++i)
    {
        int      j = i - 1;
        set<int> low, high;
        while (j >= 0) // at most 4
        {
            if (a[j] <= a[i])
            {
                if (i - j + 1 >= 3 and low.lower_bound(a[j]) != low.end())
                    break;
                low.insert(a[j]);
            }
            if (a[j] >= a[i])
            {
                if (i - j + 1 >= 3 and high.upper_bound(a[j]) != high.begin())
                    break;
                high.insert(a[j]);
            }
            j--;
        }
        dp[i] = max(j, dp[i - 1]);
        ans += i - dp[i];
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
        int n;
        cin >> n;
        vi a(n);
        read(all(a));
        cout << solve(a) << endl;
    }
    return 0;
}
