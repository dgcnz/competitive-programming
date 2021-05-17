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

bool solve(ll n, ll m, vector<ii> obstacles)
{
    vector<set<int>> horizontal(n + 2), vertical(m + 2);
    for (auto [r, c] : obstacles)
    {
        horizontal[r].insert(c);
        vertical[c].insert(r);
    }

    for (int r = 1; r <= n; ++r)
        horizontal[r].insert(0), horizontal[r].insert(m + 1);

    for (int c = 1; c <= m; ++c)
        vertical[c].insert(0), vertical[c].insert(n + 1);

    ll  ans = n * m - (int)obstacles.size() - 1;
    ii  pos = {1, 1};
    int lb = 0, rb = m + 1, ub = 0, db = n + 1;
    while (true)
    {
        auto it           = upper_bound(all(horizontal[pos.first]), pos.second);
        int  displacement = max(0, min(rb, *it) - pos.second - 1);
        ans -= displacement;
        pos.second = min(rb, *it) - 1;
        if (pos.first == ub or pos.first == db or pos.second == lb or
            pos.second == rb)
            break;
        ub = pos.first;

        it           = upper_bound(all(vertical[pos.second]), pos.first);
        displacement = max(0, min(db, *it) - pos.first - 1);
        ans -= displacement;
        pos.first = min(db, *it) - 1;
        if (pos.first == ub or pos.first == db or pos.second == lb or
            pos.second == rb)
            break;
        rb = pos.second;

        it = prev(lower_bound(all(horizontal[pos.first]), pos.second));
        displacement = max(0, pos.second - max(lb, *it) - 1);
        ans -= displacement;
        pos.second = max(lb, *it) + 1;
        if (pos.first == ub or pos.first == db or pos.second == lb or
            pos.second == rb)
            break;
        db = pos.first;

        it           = prev(lower_bound(all(vertical[pos.second]), pos.first));
        displacement = max(0, pos.first - max(ub, *it) - 1);
        ans -= displacement;
        pos.first = max(ub, *it) + 1;
        if (pos.first == ub or pos.first == db or pos.second == lb or
            pos.second == rb)
            break;
        lb = pos.second;
    }
    return ans == 0;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ii> obstacles(k);
    for (auto &[r, c] : obstacles)
        cin >> r >> c;
    cout << (solve(n, m, obstacles) ? "Yes" : "No") << endl;
    return 0;
}
