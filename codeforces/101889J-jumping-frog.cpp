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

ll solve(string s)
{
    int          n = s.size();
    map<ii, int> mem;
    auto         dp = [&](int start, int k) {
        auto &ans = mem[ii{start, k}];
        if (ans)
            return ans == -1 ? 0 : 1;
        else
        {
            int i = start;
            do
            {
                if (s[i] == 'P')
                {
                    ans = -1;
                    return 0;
                }
                i = (i + k) % n;
            } while (i != start);

            ans = 1;
            return 1;
        }
    };

    ll ans = 0;
    for (int k = 1; k < n; ++k)
    {
        ans += [&](int g) {
            for (int i = 0; i < g; ++i)
                if (dp(i, g))
                    return true;
            return false;
        }(gcd(k, n));
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
