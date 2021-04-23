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

vector<vi> solve(vi p)
{
    int        n = p.size();
    vector<vi> ans(n);
    for (int i = 0; i < n; ++i)
        ans[i].resize(i + 1, 0);

    auto in_board = [n](int r, int c) {
        return 0 <= r and r <= n and 0 <= c and c <= n and c <= r;
    };
    function<void(int, int, int, int)> dfs =
        [&](int r, int c, int col, int rem) {
            if (!rem)
                return;

            if (in_board(r, c - 1) and !ans[r][c - 1])
            {
                ans[r][c - 1] = col;
                dfs(r, c - 1, col, rem - 1);
            }
            else if (in_board(r + 1, c) and !ans[r + 1][c])
            {
                ans[r + 1][c] = col;
                dfs(r + 1, c, col, rem - 1);
            }
            else
                throw runtime_error("impossible");
        };

    for (int i = 0; i < n; ++i)
    {
        ans[i][i] = p[i];
        dfs(i, i, p[i], p[i] - 1);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi p(n);
    read(all(p));

    try
    {
        auto ans = solve(p);
        for (auto row : ans)
            write(all(row), " "), cout << endl;
    }
    catch (int e)
    {
        cout << -1 << endl;
    }

    return 0;
}
