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

ll dist(ii a, ii b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

ll distance(ii a, ii b, ii c) { return dist(a, b) + dist(b, c) + dist(c, a); }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, i, j;
        cin >> n >> m >> i >> j, i--, j--;
        vector<ii> opts = {{0, 0}, {0, m - 1}, {n - 1, 0}, {n - 1, m - 1}};
        pair<ll, pair<ii, ii>> ans = {0, {{0, 0}, {0, 0}}};
        for (auto p1 : opts)
        {
            for (auto p2 : opts)
            {
                ll d = distance({i, j}, p1, p2);
                ans  = max(ans, {d, {p1, p2}});
            }
        }

        auto [d, p12] = ans;
        auto [p1, p2] = p12;
        cout << p1.first + 1 << " " << p1.second + 1 << " " << p2.first + 1
             << " " << p2.second + 1 << endl;
    }
    return 0;
}
