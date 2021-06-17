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

ll solve(vector<ll> a)
{
    int n    = a.size();
    ll  base = 0;
    for (int i = 1; i < n; ++i)
        base += abs(a[i] - a[i - 1]);

    ll ans = min(base - abs(a[1] - a[0]), base - abs(a[n - 1] - a[n - 2]));
    for (int i = 1; i < n - 1; ++i)
    {
        if (a[i - 1] < a[i] and a[i] > a[i + 1])
            ans = min(ans, base - 2 * (a[i] - max(a[i - 1], a[i + 1])));
        else if (a[i - 1] > a[i] and a[i] < a[i + 1])
            ans = min(ans, base - 2 * (min(a[i - 1], a[i + 1]) - a[i]));
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
        vector<ll> a(n);
        read(all(a));
        cout << solve(a) << endl;
    }
    return 0;
}
