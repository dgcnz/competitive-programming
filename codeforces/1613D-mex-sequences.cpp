#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint998244353;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        read(all(a));

        vector<mint> dp1(n + 2, 0), dp2(n + 2, 0);
        dp1[0] = 1;
        for (auto x : a)
        {
            dp1[x + 1] = 2 * dp1[x + 1] + dp1[x];
            if (x > 0)
                dp2[x - 1] = 2 * dp2[x - 1] + dp1[x - 1];
            dp2[x + 1] = dp2[x + 1] + dp2[x + 1];
        }

        mint ans = 0;
        ans      = accumulate(all(dp1), ans);
        ans      = accumulate(all(dp2), ans);
        cout << (ans - 1).val() << endl;
    }
    return 0;
}
