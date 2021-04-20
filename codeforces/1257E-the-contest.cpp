#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/lazysegtree>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vector<vi> a)
{
    int n = a[0].size() + a[1].size() + a[2].size();
    vi  pos(n + 1);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < isz(a[i]); ++j)
            pos[a[i][j]] = i;

    int const  INF = 1e8;
    vector<vi> dp(n + 1, vi(3, INF));
    fill(all(dp[0]), 0);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            auto first = dp[i - 1].begin();
            dp[i][j]   = *min_element(first, first + j + 1) + (pos[i] != j);
        }
    }
    return *min_element(all(dp[n]));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    vi         k(3);
    vector<vi> a(3);
    read(all(k));
    for (int i = 0; i < 3; ++i)
    {
        a[i].resize(k[i]);
        read(all(a[i]));
    }

    cout << solve(a) << endl;

    return 0;
}
