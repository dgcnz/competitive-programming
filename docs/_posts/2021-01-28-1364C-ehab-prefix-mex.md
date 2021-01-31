---
layout: post
mathjax: true
title: 1364C - Ehab Prefix Mex
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
using vi = vector<int>;
const int NMAX = 1e5 + 11;
int n, a[NMAX];
bool visited[NMAX];
void solve(void)
{
    vi ans(n + 1, NMAX);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            ans[i] = a[i - 1];
            visited[ans[i]] = true;
        }
    }
    visited[a[n]] = true;
    int p = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (visited[p])
            ++p;
        if (ans[i] == NMAX)
        {
            ans[i] = p;
            visited[p] = true;
        }
        cout << ans[i] << " ";
    }
}
int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    solve();
    return 0;
}

{% endraw %}
```
</details>

