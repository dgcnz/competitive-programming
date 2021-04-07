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

vi solve(vi a, vi b, vi c)
{
    int n = a.size(), m = c.size();

    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i])
            pos[b[i]].push_back(i);

    int  pivot = -1;
    auto next  = [&](int color) {
        int ans = pivot;
        if (!pos[color].empty())
            ans = pos[color].back(), pos[color].pop_back();
        return ans;
    };

    if (pivot = next(c.back()); pivot == -1)
    {
        if (auto it = find(all(b), c.back()); it != b.end())
            pivot = distance(b.begin(), it);
        else
            return {};
    }
    vi ans(m);
    for (int i = 0; i < m; ++i)
    {
        int j  = next(c[i]);
        a[j]   = c[i];
        ans[i] = j + 1;
    }
    return a == b ? ans : vi();
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
        vi a(n), b(n), c(m);
        read(all(a));
        read(all(b));
        read(all(c));
        if (auto ans = solve(a, b, c); not ans.empty())
        {
            cout << "Yes" << endl;
            write(all(ans), " "), cout << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}
