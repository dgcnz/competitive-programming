#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

const int NMAX = 2 * 1e5 + 11;

int n, k, depth[NMAX];
vi  g[NMAX], ans;

/**
 * @oj codeforces
 * @problem 1337C
 * @author dgcnz
 * @complexity O(n)
 * @idea The intuition tells you to choose the k nodes more distant from the
 *      root node, but how? Let's say we start from the leaves, what would their
 *      contribution be? Its depth, right?
 *      Now, what if we chose its parent? We would need to add its depth and
 *      subtract 1 from its child. If we generalize this idea we end up with
 *      `contribution(v) = depth(v) + num_children(v)` for node v.
 *
 **/

int dfs(int u, int parent, int depth = 0)
{
    int children = 0;

    for (int v : g[u])
        if (v != parent)
            children += 1 + dfs(v, u, depth + 1);

    ans.push_back(depth - children);
    return children;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int u, v;
    cin >> n >> k;

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    dfs(0, -1);

    sort(ans.rbegin(), ans.rend());

    cout << accumulate(ans.begin(), ans.begin() + k, 0LL) << endl;

    return 0;
}
