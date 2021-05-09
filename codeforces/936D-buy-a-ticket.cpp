#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graphs/dijkstra>
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
    int n, m;
    cin >> n >> m;

    Dijkstra<ll> g(n + 1);
    while (m--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, 2 * w);
        g.add_edge(v, u, 2 * w);
    }
    for (int i = 1; i <= n; ++i)
    {
        ll ai;
        cin >> ai;
        g.add_edge(0, i, ai);
    }

    g(0);
    for (int i = 1; i <= n; ++i)
        cout << g.distance(i) << " ";
    cout << endl;
    return 0;
}
