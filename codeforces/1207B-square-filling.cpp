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

pair<bool, vector<ii>> solve(vector<vi> a)
{
    int        n = a.size(), m = a.front().size();
    vector<vi> b(n, vi(m, 0));
    vector<ii> ans;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            if (a[i][j] == 1 and a[i][j + 1] == 1 and a[i + 1][j] == 1 and
                a[i + 1][j + 1] == 1)
            {
                ans.emplace_back(i, j);
                b[i][j] = b[i][j + 1] = b[i + 1][j] = b[i + 1][j + 1] = 1;
            }
        }
    }

    return {a == b, ans};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    for (auto &ai : a)
        read(all(ai));

    if (auto [ok, ans] = solve(a); ok)
    {
        cout << ans.size() << endl;
        for (auto [x, y] : ans)
            cout << x + 1 << " " << y + 1 << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
