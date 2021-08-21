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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vi> a(2, vi(n));
        read(all(a[0]));
        read(all(a[1]));
        decrement(all(a[0]));
        decrement(all(a[1]));

        vector<vi> p(2, vi(n));

        for (int i = 0; i < n; ++i)
        {
            p[0][a[0][i]] = i;
            p[1][a[1][i]] = i;
        }

        vector<bool> vis(n, false);
        mint         ans = 1;
        for (int i = 0; i < n; ++i)
        {
            if (vis[i])
                continue;

            int cur = 0;
            int j   = i;
            do
            {
                vis[j] = true;
                cur++;
                j = p[1][a[0][j]];
            } while (j != i);
            ans *= 2;
        }
        cout << ans.val() << endl;
    }
    return 0;
}
