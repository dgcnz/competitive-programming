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

int const INF = 1e9;

string inv(string s)
{
    for (auto &c : s)
        c = (c == '0' ? '1' : '0');
    return s;
}

int solve(int n, string a, string b)
{
    int a1 = count(all(a), '1');
    int a0 = n - a1;

    int b1 = count(all(b), '1');
    int b0 = n - b1;

    int ans = INF;
    if (a1 == b1 and a0 == b0)
    {
        int cur = 0;
        for (int i = 0; i < n; ++i)
            cur += a[i] != b[i];
        ans = min(ans, cur);
    }
    if (b1 == a0 + 1 and b0 == a1 - 1)
    {
        auto ainv = inv(a);
        int  cur  = 0;
        for (int i = 0; i < n; ++i)
            cur += ainv[i] != b[i];
        ans = min(ans, cur);
    }
    return ans == INF ? -1 : ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int    n;
        string a, b;
        cin >> n >> a >> b;

        cout << solve(n, a, b) << endl;
    }
    return 0;
}
