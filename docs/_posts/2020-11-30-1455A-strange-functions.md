---
layout: post
mathjax: true
title: 1455A - Strange Functions
problem_url: https://codeforces.com/contest/1455/problem/A
tags: math
memory_complexity: O(1)
time_complexity: O(1)
---

Observations:
1. $f(f(x))$ is the same as stripping $x$ from all it's trailing zeros.
2. $\frac{x}{f(f(x))}$ will always be the biggest power of $10$ that is a
factor of $x$.
3. Finding all unique values of the formula is the same as finding all
possible powers of ten less or equal than $x$.


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
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << (int)(s).size() << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

