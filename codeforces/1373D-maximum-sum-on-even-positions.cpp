#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll kadane(vector<ll> a)
{
    if (a.empty())
        return 0;
    int n   = a.size();
    ll  ans = a[0], cur = a[0];

    for (int i = 1; i < n; i++)
    {
        cur = max(a[i], cur + a[i]);
        ans = max(ans, cur);
    }
    return ans;
}

ll solve(vector<ll> a)
{
    int        n = a.size();
    vector<ll> b1, b2;
    ll         ans = 0;
    for (int i = 0; i < n; i += 2)
    {
        ans += a[i];
        if (i + 1 <= n - 1)
            b1.push_back(a[i + 1] - a[i]);
        if (i > 0)
            b2.push_back(a[i - 1] - a[i]);
    }
    return max({ans, ans + kadane(b1), ans + kadane(b2)});
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
        for (auto &ai : a)
            cin >> ai;
        cout << solve(a) << endl;
    }
    return 0;
}
