---
layout: post
mathjax: true
title: 1085 Array Division
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
using predicate = function<bool(ll)>;
const int NMAX = 2e5 + 11;
ll n, k, x[NMAX];
ll bs(ll l, ll r, predicate p)
{
    while (l < r)
    {
        ll m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}
bool max_sum_test(ll max_sum)
{
    ll last_sum = 0;
    int n_partitions = 0;
    for (int i = 0; i < n; ++i)
    {
        if (last_sum + x[i] > max_sum)
        {
            last_sum = 0;
            n_partitions += 1;
        }
        last_sum += x[i];
    }
    n_partitions += 1;
    return (n_partitions <= k);
}
int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    cout << bs(*max_element(x, x + n), 1e18, max_sum_test) << endl;
    return 0;
}

{% endraw %}
```