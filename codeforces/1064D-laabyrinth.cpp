#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graph/bfs01>
#include <cplib/graph/gridgraph>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vector<string> lab, int sr, int sc, int x, int y)
{
    auto valid = [&](ii pos) { return lab[pos.first][pos.second] != '*'; };
    auto cost  = [&](ii u, ii v) { return u.second + 1 == v.second; };
    ImplicitGridGraph<int> g(lab, valid, cost);

    BFS01<ImplicitGridGraph, int> bfs01(g);
    bfs01(g.id(sr, sc));
    int n = lab.size(), m = lab[0].size(), ans = 0;
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            if (lab[r][c] == '*')
                continue;
            int R = bfs01.distance(g.id(r, c)), L = sc - c + R;
            ans += (L <= x and R <= y);
        }
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int sr, sc;
    cin >> sr >> sc, sr--, sc--;
    int x, y;
    cin >> x >> y;
    vector<string> lab(n);
    read(all(lab));
    cout << solve(lab, sr, sc, x, y) << endl;
    return 0;
}
