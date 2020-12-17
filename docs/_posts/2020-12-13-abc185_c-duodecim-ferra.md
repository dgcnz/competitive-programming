---
layout: post
mathjax: true
title: abc185_c - Duodecim Ferra
problem_url: https://atcoder.jp/contests/abc185/tasks/abc185_c
tags: combinatorics, dp
memory_complexity: O(l^2)
time_complexity: O(l^2)
---

Compute the number of ways to cut a log of width $l$, $C(l - 1, 11)$.


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
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int l;
    cin >> l;
    vector<vector<ll>> C(l + 1, vector<ll>(l + 1, 0));
    C[0][0] = 1;
    for (int n = 1; n <= l; ++n)
    {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
    cout << C[l - 1][11] << endl;
    return 0;
}

{% endraw %}
```
</details>

