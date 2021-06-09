#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/combinatorics>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(string s)
{
    vector<ll> fact(19, 0);
    fact[0] = 1;
    for (int i = 1; i < 19; ++i)
        fact[i] = fact[i - 1] * i;

    auto C = [&](int n, int k) {
        if (k > n or k < 0)
            return 0LL;
        return fact[n] / (fact[k] * fact[n - k]);
    };

    int          len = s.size();
    vector<bool> vis(10, false);
    for (auto c : s)
        vis[c - '0'] = true;

    ll            ans = 0;
    map<vi, bool> visited;
    for (int mask = 0; mask < (1LL << len); ++mask)
    {
        vector<int> cnt(10, 0);
        for (int i = 0; i < len; ++i)
            if (mask & (1LL << i))
                cnt[s[i] - '0']++;

        if (visited[cnt])
            continue;
        visited[cnt] = true;

        bool flag = true;
        for (int x = 0; x < 10; ++x)
            if (cnt[x] == 0 and vis[x])
                flag = false;
        if (!flag)
            continue;

        int m     = __builtin_popcount(mask);
        ll  nom   = fact[m - cnt[0]];
        ll  denom = 1;
        for (int x = 1; x < 10; ++x)
            denom *= fact[cnt[x]];

        ll cur = nom / denom;
        cur *= C(m - 1, m - cnt[0] - 1);
        ans += cur;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
