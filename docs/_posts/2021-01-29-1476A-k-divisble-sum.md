---
layout: post
mathjax: true
title: 1476A - K Divisble Sum
problem_url: https://codeforces.com/contest/1476/problem/A
tags: math
memory_complexity: O(1)
time_complexity: O(1)
---


Assume $k \geq n$, otherwise find the smallest multiple of $k$ that matches
that condition.

We shall fill the $n$ elements with $floor(k / n)$ and then displace
uniformly the remainder over all posible $a_i$. In this way the remainder
counts for at most $1$.


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
int ceil(int a, int b) { return (a + b - 1) / b; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        k *= ceil(n, k);
        cout << k / n + ((k % n) != 0) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

