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

int solve(vi c, int l, int r)
{
    map<int, int> cntl, cntr;
    int           reml = l, remr = r;
    for (int i = 0; i < l; ++i)
        cntl[c[i]]++;
    for (int i = l; i < l + r; ++i)
        cntr[c[i]]++;

    for (int i = 0; i < l; ++i)
    {
        int x       = c[i];
        int matched = min(cntl[x], cntr[x]);
        cntl[x] -= matched;
        cntr[x] -= matched;
        reml -= matched, remr -= matched;
    }

    int ans = 0;
    for (int i = 0; i < l; ++i)
    {
        int x = c[i];
        if (cntl[x] >= 2)
        {
            int matched = min(cntl[x] / 2, max(0, reml - remr) / 2);
            cntl[x] -= 2 * matched;
            reml -= 2 * matched;
            ans += matched;
        }
    }

    for (int i = l; i < l + r; ++i)
    {
        int x = c[i];
        if (cntr[x] >= 2)
        {
            int matched = min(cntr[x] / 2, max(0, remr - reml) / 2);
            cntr[x] -= 2 * matched;
            remr -= 2 * matched;
            ans += matched;
        }
    }

    ans += abs(remr - reml) / 2 + (remr + reml) / 2;
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vi c(n);
        read(all(c));
        cout << solve(c, l, r) << endl;
    }
    return 0;
}
