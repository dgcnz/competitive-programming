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

int solve(vi a, int x)
{
    int ans = 1e9;
    for (auto ai : a)
    {
        if (ai == x)
            ans = min(ans, 1);
        else
        {
            int d = x / ai;
            if (d == 0)
                ans = min(ans, 2);
            else
                ans = min(ans, d + (x % ai != 0));
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vi a(n);
        read(all(a));

        cout << solve(a, x) << endl;
    }
    return 0;
}
