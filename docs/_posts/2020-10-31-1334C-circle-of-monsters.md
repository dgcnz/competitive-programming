---
layout: post
mathjax: true
title: 1334C Circle Of Monsters
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
using ll = long long;
const int NMAX = 3 * 1e5 + 11;
int n;
ll sum, a[NMAX], b[NMAX];
ll solve(void)
{
    ll suma, sumb, mn = LLONG_MAX;
    suma = sumb = 0;
    for (int i = 0; i < n; ++i)
    {
        suma += a[i];
        b[i] = min(b[i], a[(i + 1) % n]);
        sumb += b[i];
        mn = min(mn, b[i]);
    }
    return suma - sumb + mn;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        sum = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```