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

int solve(vector<int> p, vector<ii> pairs)
{
    int n = p.size();
    if (n == 1)
        return 0;

    vector<bool> good(n, false);
    vector<vi>   back(n);
    for (auto [u, v] : pairs)
    {
        if (v == p.back())
            good[u] = true;
        back[u].push_back(v);
    }

    int      ans = 0;
    set<int> vs;
    for (int i = n - 2; i >= 0; i--)
    {
        int u = p[i];
        if (good[u])
        {
            int cnt = vs.size();
            for (auto v : back[u])
                if (vs.count(v))
                    cnt--;
            if (cnt == 0)
            {
                ans++;
                continue;
            }
        }
        vs.insert(u);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    read(all(p));
    decrement(all(p));
    vector<ii> pairs(m);
    for (auto &[u, v] : pairs)
        cin >> u >> v, u--, v--;

    cout << solve(p, pairs) << endl;
    return 0;
}
