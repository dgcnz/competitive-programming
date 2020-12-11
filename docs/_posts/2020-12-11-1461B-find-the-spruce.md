---
layout: post
mathjax: true
title: 1461B - Find The Spruce
problem_url: https://codeforces.com/contest/1461/problem/B
tags: dp, brute_force
memory_complexity: O(n^2)
time_complexity: O(n^2)
---

Note that you can know what is the largest spruce that can be constructed
with root $(r, c)$, by merging the spruces at $(r + 1, c - 1)$, $(r + 1, c)$
and $(r + 1,c + 1)$ and cutting the excess. With this idea in mind, define
the following dp state:

$$ dp(r, c) = 1 + min(dp(r + 1, c - 1), dp(r + 1, c), dp(r + 1, c + 1)) $$

if $(r, c) == '*'$.


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
int const NMAX = 500 + 11;
int n, m, board[NMAX][NMAX];
ll solve(void)
{
    ll ans = 0;
    for (int r = n; r >= 1; --r)
    {
        for (int c = m; c >= 1; --c)
        {
            if (board[r][c])
            {
                board[r][c] = 1 + min({board[r + 1][c - 1],
                                       board[r + 1][c],
                                       board[r + 1][c + 1]});
                ans += board[r][c];
            }
        }
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(board, 0, sizeof board);
        for (int r = 1; r <= n; ++r)
        {
            for (int c = 1; c <= m; ++c)
            {
                char ch;
                cin >> ch;
                board[r][c] = (ch == '*');
            }
        }
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

