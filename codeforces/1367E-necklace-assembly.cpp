#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> cnt(26, 0);
        for (auto c : s)
            cnt[c - 'a']++;

        auto ok = [&](int m)
        {
            int ans = 0, rep = m / gcd(m, k);
            for (auto x : cnt)
                ans += rep * (x / rep);
            return ans >= m;
        };

        int ans = 1;
        for (int m = 2; m <= n; ++m)
            if (ok(m))
                ans = m;

        cout << ans << endl;
    }
    return 0;
}
