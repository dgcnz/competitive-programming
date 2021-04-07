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

int bs(int l, int r, function<bool(ll)> p)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

ll solve(ll W, vector<ll> w)
{
    int n = w.size();
    sort(all(w), greater<ll>());
    auto p = [&](int h) -> bool {
        multiset<ll> widths;
        while (h--)
            widths.insert(W);
        for (int i = 0; i < n; ++i)
        {
            auto it = widths.lower_bound(w[i]);
            if (it == widths.end())
                return false;
            widths.insert(*it - w[i]);
            widths.erase(it);
        }
        return true;
    };

    return bs(1, n, p);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll  W;
        cin >> n >> W;
        vector<ll> w(n);
        for (auto &wi : w)
            cin >> wi;
        cout << solve(W, w) << endl;
    }
    return 0;
}
