#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint1000000007;

int solve(vector<string> &s, int k)
{
    int              n = s.size();
    vector<mint>     dp(n, 0);
    vector<mint>     delta(n, 0);
    vector<int>      r(n);
    map<string, int> last;

    mint sum = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        // preupdate
        sum += delta[i];
        dp[i] = 1 + sum;

        r[i] = i - k - 1;
        if (r[i] >= 0)
        {
            delta[r[i]] += dp[i];
        }
        if (last.find(s[i]) != last.end())
        {
            int j = last[s[i]];
            if (i > 0 and r[i] >= 0)
                delta[min(r[i], r[j])] -= dp[j];
        }
        last[s[i]] = i;
    }

    mint ans = 0;
    for (auto [w, i] : last)
        ans += dp[i];
    return ans.val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<string> s(n);
        read(all(s));

        cout << solve(s, k) << endl;
    }
    return 0;
}
