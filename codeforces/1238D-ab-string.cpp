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
    ll n   = s.size();
    ll ans = (n * (n - 1)) / 2;

    for (int t = 0; t < 2; ++t)
    {
        int cur = 1;
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == s[i - 1])
                cur++;
            else
            {
                ans -= cur - t;
                cur = 1;
            }
        }
        reverse(all(s));
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int    n;
    string s;
    cin >> n >> s;
    cout << solve(s) << endl;
    return 0;
}
