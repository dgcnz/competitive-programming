---
layout: post
mathjax: true
title: 148A - Insomnia Cure
problem_url: https://codeforces.com/contest/148/problem/A
tags: number_theory, factorization, brute_force
memory_complexity: O(1)
time_complexity: O(d)
---

Count all numbers [1, d] that are at least divisible by k, l, m or n.


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
    vi factors(4);
    for (auto &fi : factors)
        cin >> fi;
    int d, ans = 0;
    cin >> d;
    for (int i = 1; i <= d; ++i)
    {
        for (auto fi : factors)
        {
            if (i % fi == 0)
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

