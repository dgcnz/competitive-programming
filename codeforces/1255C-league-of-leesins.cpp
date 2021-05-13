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
using ll  = long long;
using ii  = pair<int, int>;
using iii = array<int, 3>;
using vi  = vector<int>;

vi solve(vector<iii> q)
{
    int        n = q.size() + 2;
    vector<vi> g(n);
    vi         cnt(n, 0), vis(n, 0);
    for (auto [x, y, z] : q)
    {
        cnt[x]++, cnt[y]++, cnt[z]++;
        g[x].push_back(y);
        g[x].push_back(z);
        g[y].push_back(x);
        g[y].push_back(z);
        g[z].push_back(x);
        g[z].push_back(y);
    }

    int x = 0;
    for (; x < n; ++x)
        if (g[x].size() == 2)
            break;

    int y = g[x][0], z = g[x][1];

    if (cnt[y] > cnt[z])
        swap(y, z);

    vi ans(n);
    ans[0] = x, ans[1] = y, ans[2] = z;
    vis[x] = vis[y] = vis[z] = true;
    for (int i = 3; i < n; ++i)
    {
        for (auto w : g[y])
        {
            if (vis[w])
                continue;

            vis[w] = true;
            ans[i] = w;
            y      = z;
            z      = w;
        }
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<iii> q(n - 2);
    for (auto &[x, y, z] : q)
        cin >> x >> y >> z, x--, y--, z--;

    auto ans = solve(q);
    transform(all(ans), begin(ans), [](int x) { return x + 1; });
    write(all(ans), " "), cout << endl;
    return 0;
}
