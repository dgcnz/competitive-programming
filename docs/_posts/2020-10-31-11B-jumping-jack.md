---
layout: post
mathjax: true
title: 11B Jumping Jack
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
using predicate = function<bool(int)>;
int bs(int l, int r, predicate p)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}
ll psum(ll n) { return (n * (n + 1)) / 2; }
int main(void)
{
    int x;
    cin >> x;
    x = abs(x);
    int n = bs(0, 1e9 + 11, [x](ll n) { return x <= psum(n); });
    while (psum(n) % 2 != x % 2)
        ++n;
    cout << n << endl;
    return 0;
}

{% endraw %}
```
</details>

