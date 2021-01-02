/** @file
 * @date                2021-01-02
 * @url                 https://atcoder.jp/contests/abc187/tasks/abc187_e
 * @tags                trees, dfs
 * @status              AC
 * @score               4
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         30
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Let's root the tree on $0$ to make our life easier.
 *
 * Without loss of generality, assume $t = 1$. We have two cases:
 *
 * 1. $b$ is parent of $a$: We only have to update with $+x$ to the subtree
 * rooted at $a$.
 * 2. $b$ is parent of $a$: We have to update ($+x$) the entire tree but the
 * subtree rooted at $a$.
 *
 * Since we only need to know the answer at the end, we may use an analogue to
 * difference arrays but on trees to perform updates on $O(1)$.
 *
 * For ase $1.$ add $x$ to `ans[a]`, for case $2.$ add $x$ to `ans[0]` and
 * subtract $x$ from `ans[a]` to cancel the excess.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const NMAX = 2e5 + 11;

int a[NMAX], b[NMAX], depth[NMAX];
ll  ans[NMAX];
vi  g[NMAX];

void precompute_depth(int u, int p)
{
    for (auto v : g[u])
    {
        if (v == p)
            continue;

        depth[v] = depth[u] + 1;
        precompute_depth(v, u);
    }
}

void solve(int u, int p)
{
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        ans[v] += ans[u];
        solve(v, u);
    }
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vi a(n), b(n);

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a[i] >> b[i], a[i]--, b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    precompute_depth(0, 0);

    int q;
    cin >> q;

    while (q--)
    {
        int t, e, x;
        cin >> t >> e >> x, e--;
        if (t == 1)
        {
            if (depth[a[e]] > depth[b[e]])
                ans[a[e]] += x;
            else
            {
                ans[0] += x;
                ans[b[e]] -= x;
            }
        }
        else
        {
            if (depth[b[e]] > depth[a[e]])
                ans[b[e]] += x;
            else
            {
                ans[0] += x;
                ans[a[e]] -= x;
            }
        }
    }

    solve(0, 0);

    for (int u = 0; u < n; ++u)
        cout << ans[u] << endl;

    return 0;
}
