---
layout: post
mathjax: true
title: 1364C Ehab Prefix Mex
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

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
