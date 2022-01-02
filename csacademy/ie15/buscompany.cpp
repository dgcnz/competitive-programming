#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graph/graph>
#include <cplib/utils/io>
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
    int n;
    cin >> n;
    vector<bool> a(n);
    read(all(a));
    Graph<void> g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g.add_undirected_edge(u, v);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int ix;
            cin >> ix, ix--;
            a[ix] = 1 - a[ix];
        }
        else
        {
            int u, v;
            cin >> u >> v, u--, v--;

            function<set<int>(int, int, int, int)> dfs =
                [&](int u, int p, int d, int target)
            {
                set<int> depths;
                if (a[u] == target)
                    depths.insert(d);
                for (auto v : g[u])
                {
                    if (v == p)
                        continue;
                    auto temp = dfs(v, u, d + 1, target);
                    if (temp.size() > depths.size())
                        swap(temp, depths);
                    depths.insert(all(temp));
                }
                return depths;
            };

            set<int> left[2], right[2], ans[2];
            int      sum[2];
            int      num[2];
            for (int target = 0; target < 2; ++target)
            {
                left[target]  = dfs(u, v, 0, target);
                right[target] = dfs(v, u, 0, target);
                for (auto x : left[target])
                    for (auto y : right[target])
                        ans[target].insert(x + y + 1);
                sum[target] = 0;
                for (auto x : ans[target])
                    sum[target] += x;
                num[target] = ans[target].size();
            }
            if (num[0] and num[1])
            {
                if (sum[0] * num[1] == sum[1] * num[0])
                {
                    cout << "TIE" << endl;
                }
                else if (sum[0] * num[1] < sum[1] * num[0])
                {
                    cout << "A" << endl;
                }
                else
                {
                    cout << "B" << endl;
                }
            }
            else if (num[0])
                cout << "A" << endl;
            else if (num[1])
                cout << "B" << endl;
            else
                cout << "TIE" << endl;
        }
    }

    return 0;
}
