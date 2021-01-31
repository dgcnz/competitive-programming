---
layout: post
mathjax: true
title: 1397B - Power Sequence
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
using vi = vector<int>;
using predicate = function<bool(int)>;
int const NMAX = 1e5 + 11;
int n, a[NMAX];
ll cost(int c)
{
    ll ans = 0;
    ll x = 1;
    for (int i = 0; i < n; ++i)
    {
        ans += abs((ll)a[i] - x);
        x *= (ll)c;
    }
    return ans;
}
bool worthit(ll last, int c)
{
    ll ans = 0;
    ll x = 1;
    for (int i = 0; i < n; ++i)
    {
        ans += abs((ll)a[i] - x);
        if (ans > last)
            return false;
        x *= (ll)c;
    }
    return true;
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    ll last = cost(1);
    int c = 2;
    while (worthit(last, c))
    {
        last = cost(c);
        ++c;
    }
    cout << last << endl;
    return 0;
}

{% endraw %}
```
</details>

