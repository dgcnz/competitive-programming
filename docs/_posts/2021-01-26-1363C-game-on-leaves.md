---
layout: post
mathjax: true
title: 1363C - Game On Leaves
problem_url: https://codeforces.com/contest/1363/problem/C
tags: constructive, trees, dfs
memory_complexity: O(n)
time_complexity: O(n)
---

First, note that if the degree of $x$ less than or equal to 1 then Ayush
wins. Assume otherwise.

Note that we have to reduce $x$'s degree to $2$ and remove almost all the
nodes from the remaining two branches to finally be able to *almost* pick
$x$.

```
   x
 /   \
 a    b

```

In this situation, the current player will necessarily have to pick either
$a$ or $b$, losing the game.

So, wrapping it up, we need to count how many leaves we have to consume first
before ending in this situation, which is $n - 3$. Only if this number is
odd, then Ayush wins.

For a proof, see [Editorial](https://codeforces.com/blog/entry/78202).



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
template <typename T>
using Tree = vector<vector<T>>;
bool solve(Tree<int> g, int x)
{
    int n = g.size();
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

{% endraw %}
```
</details>

