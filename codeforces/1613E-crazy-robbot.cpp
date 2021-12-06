#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/grid>
#include <cplib/utils/io>
#include <cplib/utils/misc>
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
    vector<Direction> directions = {UP, RIGHT, DOWN, LEFT};

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        auto in_board = [n, m](ii u) {
            return 0 <= u.first and u.first < n and 0 <= u.second and
                   u.second < m;
        };

        vector<string> a(n, string(m, ' '));
        ii             src;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
                if (a[i][j] == 'L')
                    src = {i, j};
            }
        }

        auto neighbors = [&](ii u)
        {
            vector<ii> neigh;
            for (auto dir : directions)
            {
                auto v = u + dir; // apply direction
                if (in_board(v) and a[v.first][v.second] == '.')
                    neigh.push_back(v);
            }
            return neigh;
        };

        function<void(ii)> dfs = [&](ii u)
        {
            for (auto v : neighbors(u))
            {
                if (neighbors(v).size() <= 1)
                {
                    a[v.first][v.second] = '+';
                    dfs(v);
                }
            }
        };

        dfs(src);
        write(all(a));
    }
    return 0;
}
