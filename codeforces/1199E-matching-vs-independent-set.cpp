#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graphs/graph>
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> vis(3 * n, false);
        vector<int> ans;
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v, u--, v--;
            if (vis[u] or vis[v])
                continue;
            vis[u] = vis[v] = true;
            ans.push_back(i);
        }

        if ((int)ans.size() >= n)
        {
            ans.resize(n);
            increment(all(ans));
            cout << "Matching" << endl;
            write(all(ans), " "), cout << endl;
        }
        else
        {
            cout << "IndSet" << endl;
            int k = n;
            for (int u = 0; u < 3 * n and k; ++u)
                if (not vis[u])
                    cout << u + 1 << " ", k--;
            cout << endl;
        }
    }
    return 0;
}
