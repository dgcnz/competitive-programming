#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/grid>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

string solve(vector<string> a)
{
    int               n = a.size(), m = a.back().size();
    vector<Direction> directions = {
        UP, RIGHT, DOWN, LEFT, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == '.')
                a[i][j] = '0';

            if (a[i][j] != '*')
            {
                int x = a[i][j] - '0';
                for (auto dir : directions)
                {
                    auto v = ii{i, j} + dir;
                    if (0 <= v.first and v.first < n and 0 <= v.second and
                        v.second < m and a[v.first][v.second] == '*')
                        x--;
                }
                if (x != 0)
                    return "NO";
            }
        }
    }
    return "YES";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    read(all(a));
    cout << solve(a) << endl;
    return 0;
}
