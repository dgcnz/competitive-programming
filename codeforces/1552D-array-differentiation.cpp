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

string solve(vi a)
{
    for (auto &ai : a)
    {
        if (ai == 0)
            return "YES";
        ai = abs(ai);
    }

    int n = a.size();
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[j] == 0 or a[i] == a[j])
                return "YES";

    if (n == 1 or n == 2)
        return "NO";

    sort(all(a));

    vector<int> b(n, -1);
    b[0] = 0;
    b[1] = a[0];

    function<bool(int)> dfs = [&](int i)
    {
        if (i == n)
            return false;
        for (int j = 0; j < i; ++j)
        {
            b[i] = a[i - 1] + b[j];
            for (int k = 0; k < i; ++k)
            {
                int  x  = abs(b[i] - b[k]);
                auto it = lower_bound(all(a), x);
                int  ix = distance(a.begin(), it);
                // dbg(b, x, ix);
                if (ix != n and a[ix] == x and ix >= i)
                    return true;
            }
            if (dfs(i + 1))
                return true;
            b[i] = -1;
        }
        return false;
    };
    return dfs(2) ? "YES" : "NO";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        read(all(a));
        cout << solve(a) << endl;
    }
    return 0;
}
