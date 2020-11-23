---
layout: post
mathjax: true
title: 11466 Largest Prime Divisor
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
ll qn;
ll trial_division(ll n)
{
    ll count = 0;
    ll max_prime = -1;
    for (ll d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
            ++count;
        while (n % d == 0)
        {
            n /= d;
            max_prime = max(max_prime, d);
        }
    }
    if (n > 1 and n != qn)
    {
        max_prime = max(max_prime, n);
        ++count;
    }
    if (count >= 2)
        return max_prime;
    return -1;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> qn and qn)
    {
        cout << trial_division(abs(qn)) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

