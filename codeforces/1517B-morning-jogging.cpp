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

vector<vi> solve(vector<vi> b)
{
    int const  INF = 1e9 + 7;
    int        n = b.size(), m = b.front().size();
    vector<ii> runners;
    for (int j = 0; j < m; ++j)
        runners.emplace_back(INF, j);

    vector<vi> ans(n, vi(m));
    for (int i = 0; i < n; ++i)
    {
        sort(all(b[i]));
        for (int j = 0; j < m; ++j)
        {
            auto &[t, ix] = runners[j];
            ans[i][ix]    = b[i][j];
            t             = min(t, b[i][j]);
        }
        sort(all(runners), greater<ii>());
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
        int n, m;
        cin >> n >> m;
        vector<vi> b(n, vi(m));
        for (auto &bi : b)
            read(all(bi));
        auto ans = solve(b);
        for (auto row : ans)
            write(all(row), " "), cout << endl;
    }
    return 0;
}
