---
layout: post
mathjax: true
title: abc184_d - Increment Of Coins
problem_url: https://atcoder.jp/contests/abc184/tasks/abc184_d
tags: dp, expected_value, probability
memory_complexity: O(n^3)
time_complexity: O(n^3)
---

I'm kinda :brick: at Probability, so here's the
[Editorial](https://atcoder.jp/contests/abc184/editorial/371).


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
int const NMAX = 100 + 1;
double dp[NMAX][NMAX][NMAX];
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    for (int x = 99; x >= 0; --x)
    {
        for (int y = 99; y >= 0; --y)
        {
            for (int z = 99; z >= 0; --z)
            {
                double d = x + y + z;
                dp[x][y][z] = x / d * (dp[x + 1][y][z] + 1) +
                              y / d * (dp[x][y + 1][z] + 1) +
                              z / d * (dp[x][y][z + 1] + 1);
            }
        }
    }
    cout << setprecision(12) << fixed << dp[a][b][c] << endl;
    return 0;
}

{% endraw %}
```
</details>

