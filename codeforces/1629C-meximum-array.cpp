#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

vector<int> solve(vector<int> a)
{
    int                 n = a.size();
    vector<vector<int>> nxt(n + 1);

    for (int i = 0; i < n; ++i)
        nxt[a[i]].push_back(i);

    auto get_max_mex = [&](int i) -> pair<int, int>
    {
        vector<bool> vis(n + 1, false);
        for (int x = 0; x <= n; ++x)
        {
            if (vis[x])
                continue;

            auto it = lower_bound(all(nxt[x]), i);
            if (it == nxt[x].end())
            {
                return {x, i};
            }
            else
            {
                while (i <= *it)
                {
                    vis[a[i]] = true;
                    i += 1;
                }
            }
        }
        return {n + 1, i};
    };

    vector<int> b;
    int         i = 0;
    while (i < n)
    {
        auto [mex, j] = get_max_mex(i);
        b.push_back(mex);
        if (i == j)
            i++;
        else
            i = j;
    }
    return b;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        read(all(a));
        auto b = solve(a);
        cout << b.size() << endl;
        write(all(b), " "), cout << endl;
    }
    return 0;
}
