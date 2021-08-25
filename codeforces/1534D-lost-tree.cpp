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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    set<ii> edges;

    auto query = [n](int u) {
        cout << "? " << u + 1 << endl;
        cout.flush();
        vi d(n);
        read(all(d));
        return d;
    };

    auto process = [n, &edges](int u, vi &d) {
        for (int v = 0; v < n; ++v)
            if (d[v] == 1)
                edges.emplace(min(u, v), max(u, v));
    };

    auto d = query(0);
    process(0, d);
    vector<vi> cnt(n);
    vi         rem(2, 0);
    for (int v = 0; v < n; ++v)
    {
        cnt[d[v]].push_back(v);
        rem[d[v] % 2]++;
    }
    int dist = 2;
    if (rem[0] > rem[1])
        dist = 1;

    while (cnt[dist].size() and (int) edges.size() < n - 1)
    {
        for (auto v : cnt[dist])
        {
            auto d = query(v);
            process(v, d);
        }
        dist += 2;
    }

    cout << "!\n";
    for (auto [u, v] : edges)
    {
        cout << u + 1 << " " << v + 1 << endl;
    }

    return 0;
}
