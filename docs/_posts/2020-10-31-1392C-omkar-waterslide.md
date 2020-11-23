---
layout: post
mathjax: true
title: 1392C Omkar Waterslide
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

```cpp
{% raw %}
using namespace std;
using ll = long long;
int const NMAX = 2e5 + 11;
ll n, a[NMAX];
ll solve(void)
{
    int i = n - 1;
    ll ans = 0;
    while (i > 0)
    {
        int j = i;
        while (j > 0 and a[j] >= a[j - 1])
            --j;
        if (j > 0)
        {
            ans += (a[j - 1] - a[j]);
            a[j] = a[j - 1];
        }
        i = j;
    }
    return ans;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```