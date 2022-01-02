#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/rational>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vi a)
{
    int n = a.size();

    int ans = n - 1;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            rational<int> d(a[j] - a[i], j - i);
            int           cur = n - 1;
            for (int k = i - d.den, x = 1; k >= 0; k -= d.den, ++x)
                if (a[k] == a[i] - x * d.num)
                    cur--;
            for (int k = i + d.den, x = 1; k < n; k += d.den, ++x)
                if (a[k] == a[i] + x * d.num)
                    cur--;
            ans = min(ans, cur);
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
        int n;
        cin >> n;
        vector<int> a(n);
        read(all(a));

        cout << solve(a) << endl;
    }
    return 0;
}
