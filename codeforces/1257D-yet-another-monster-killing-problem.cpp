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

int solve(vector<ll> a, vector<pair<int, ll>> sp)
{
    sort(all(sp));

    int        n = a.size(), m = sp.size();
    vector<ll> endurance(m), maxpower(m);
    for (int i = m - 1; i >= 0; --i)
    {
        endurance[i] = sp[i].first;
        if (i == m - 1)
            maxpower[i] = sp[i].second;
        else
            maxpower[i] = max(maxpower[i + 1], sp[i].second);
    }
    auto ok = [&](int e, ll p) {
        int i = distance(endurance.begin(), lower_bound(all(endurance), e));
        return i < m and maxpower[i] >= p;
    };

    int i = 0, ans = 0;
    while (i < n)
    {
        int j          = i;
        ll  maxmonster = -1;
        while (j < n and ok(j - i + 1, max(maxmonster, a[j])))
        {
            maxmonster = max(maxmonster, a[j]);
            j++;
        }
        if (maxmonster == -1)
            return -1;
        i = j;
        ++ans;
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
        int n, m;
        cin >> n;
        vector<ll> a(n);
        read(all(a));
        cin >> m;
        vector<pair<int, ll>> sp(m);
        for (auto &[s, p] : sp)
            cin >> p >> s;

        cout << solve(a, sp) << endl;
    }
    return 0;
}
