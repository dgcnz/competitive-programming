---
layout: post
mathjax: true
title: 1646 - Range Sum Queries I
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



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
int const NMAX = 2e5 + 11;
ll n, a[NMAX], p[NMAX];
inline ll sum(int l, int r) { return p[r] - p[l - 1]; }
int main(void)
{
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], p[i] = a[i] + p[i - 1];
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum(l, r) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

