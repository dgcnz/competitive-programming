/** @file
 * @date                2021-01-26
 * @url                 https://codeforces.com/contest/1363/problem/C
 * @tags                constructive, trees, dfs
 * @status              AC
 * @score               3
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         15
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * First, note that if the degree of $x$ less than or equal to 1 then Ayush
 * wins. Assume otherwise.
 *
 * Note that we have to reduce $x$'s degree to $2$ and remove almost all the
 * nodes from the remaining two branches to finally be able to *almost* pick
 * $x$.
 *
 * ```
 *    x
 *  /   \
 *  a    b
 *
 * ```
 *
 * In this situation, the current player will necessarily have to pick either
 * $a$ or $b$, losing the game.
 *
 * So, wrapping it up, we need to count how many leaves we have to consume first
 * before ending in this situation, which is $n - 3$. Only if this number is
 * odd, then Ayush wins.
 *
 * For a proof, see [Editorial](https://codeforces.com/blog/entry/78202).
 *
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

template <typename T>
using Tree = vector<vector<T>>;

bool solve(Tree<int> g, int x)
{
    int         n = g.size();
    vector<int> deg(n, 0);

    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto v : g[u])
        {
            deg[u]++;
            if (v != p)
                dfs(v, u);
        }
    };

    dfs(x, -1);

    if (deg[x] <= 1)
        return 1;

    return ((n - 3) % 2) == 1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;

    string ans[2] = {"Ashish", "Ayush"};
    while (t--)
    {
        int n, x;
        cin >> n >> x, x--;

        Tree<int> g(n);
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v, u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << ans[solve(g, x)] << endl;
    }
    return 0;
}
