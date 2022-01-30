#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
ll sq(ll n) { return (n * (n + 1)) / 2; }

ll solve(vector<ll> k, vector<ll> h)
{
    vector<pair<ll, int>> events;

    int n = k.size();
    for (int i = 0; i < n; ++i)
    {
        events.emplace_back(k[i] - h[i] + 1, -1);
        events.emplace_back(k[i], +1);
    }
    sort(all(events));

    ll last = -1, open = 0, ans = 0;
    for (auto [pos, type] : events)
    {
        if (type == -1) // open
        {
            if (open == 0)
                last = pos;
            open++;
        }
        else
        {
            open--;
            if (open == 0)
                ans += sq(pos - last + 1);
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
        vector<ll> k(n), h(n);
        read(all(k));
        read(all(h));
        cout << solve(k, h) << endl;
    }
    return 0;
}
