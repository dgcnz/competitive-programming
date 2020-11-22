---
layout: post
mathjax: true
title: 1623 Apple Division
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
const int NMAX = 20 + 11;
int p[NMAX];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, sum = 0, ans = INT_MAX;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
        sum += p[i];
    }
    for (ll mask = 0; mask < (1 << n); mask++)
    {
        ll cur = 0;
        for (ll i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                cur += p[i];
        }
        ans = min(ans, abs(sum - cur - cur));
    }
    cout << ans;
    return 0;
}

{% endraw %}
```