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

string solve(vector<string> a)
{
    int            n = a.size(), m = a.back().size();
    vector<string> b(n, string(m, '.'));

    vector<ii> delta = {
        {0, 0}, {1, 0}, {2, 0}, {2, 1}, {2, 2}, {1, 2}, {0, 2}, {0, 1}};

    auto paintable = [&](int i, int j)
    {
        for (auto [di, dj] : delta)
            if (i + di >= n or j + dj >= m or a[i + di][j + dj] != '#')
                return false;
        return true;
    };

    auto paint = [&](int i, int j)
    {
        for (auto [di, dj] : delta)
            b[i + di][j + dj] = '#';
    };

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (paintable(i, j))
                paint(i, j);

    return a == b ? "YES" : "NO";
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
