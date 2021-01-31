---
layout: post
mathjax: true
title: abc190_d - Staircase Sequences
problem_url: https://atcoder.jp/contests/abc190/tasks/abc190_d
tags: math, number_theory
memory_complexity: O(1)
time_complexity: O(\sqrt{n})
---

[Editorial](https://codeforces.com/blog/entry/87349)


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
    ll n;
    cin >> n;
    n *= 2;
    int ans = 0;
    for (ll k = 1, sqn = sqrt(n); k <= sqn; ++k)
        if (n % k == 0 and (n / k - k + 1) % 2 == 0)
            ans += 2;
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

