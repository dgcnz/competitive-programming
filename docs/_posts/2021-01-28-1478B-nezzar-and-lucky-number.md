---
layout: post
mathjax: true
title: 1478B - Nezzar And Lucky Number
problem_url: https://codeforces.com/contest/1478/problem/B
tags: observation, ad-hoc, brute_force
memory_complexity: O(1)
time_complexity: O(q \log{n})
---


For a given $d$, we can observe the following:
1. Each number $x$, $x \geq 10d$ can be built by a combination of an element
in the range $10d, 10d + 9$ and zero or more $d$.
2. Each number $x$, $x < 10d$ has the form: $10 k_1 + d k_2$.

Using these two facts, we can can brute_force $x < 10d$ and answer right away
$x \geq 10d$.



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
bool test(int x, int d)
{
    for (int i = d; i <= x; i += d)
        if (x % 10 == i % 10)
            return true;
    while (x)
    {
        if (x % 10 == d)
            return true;
        x /= 10;
    }
    return false;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int q, d;
        cin >> q >> d;
        while (q--)
        {
            int x;
            cin >> x;
            if (x >= d * 10 or test(x, d))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}

{% endraw %}
```
</details>

