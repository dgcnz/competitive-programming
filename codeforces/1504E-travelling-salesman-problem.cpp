#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/graphs/dijkstra>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(vector<ii> ac)
{
    int  n   = ac.size();
    auto acc = [](ll acc, ii ac) { return acc + ac.second; };
    ll   ans = accumulate(all(ac), 0LL, acc);
    sort(all(ac));

    Dijkstra<ll> g(n);
    for (int i = 0; i < n; ++i)
    {
        if (i < n - 1)
        {
            ll   x = ac[i].first + ac[i].second;
            auto p = [x](ii a) { return a.first <= x; };
            int  j = distance(ac.begin(), binary_search10(all(ac), p));
            if (j != i)
                g.add_edge(i, j, 0);
            if (j + 1 < n)
                g.add_edge(i, j + 1, ac[j + 1].first - x);
        }
        if (i > 0)
            g.add_edge(i, i - 1, 0);
    }

    g.run_sparse(0);
    return ans + g.d[n - 1];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> ac(n);
    for (auto &[a, c] : ac)
        cin >> a >> c;

    cout << solve(ac) << endl;

    return 0;
}
