---
layout: post
mathjax: true
title: 402C - Searching For Graph
problem_url: https://codeforces.com/problemset/problem/402/C
tags: greedy, graphs, constructive
memory_complexity: O(1)
time_complexity: O(n)
---

So, intuitively, we want edges to be uniformly distributed on the vertices,
as to minimize the maximum edges for each subgraph in the hope that it fits
the problem's constraints.

One way to do so is to add edges in lexicographical order.


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
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, p, m;
        cin >> n >> p;
        m = 2 * n + p;
        for (int u = 1; u < n; ++u)
        {
            for (int v = u + 1; v <= n; ++v)
            {
                if (!m)
                    break;
                cout << u << " " << v << endl;
                m--;
            }
            if (!m)
                break;
        }
    }
    return 0;
}

{% endraw %}
```
</details>

