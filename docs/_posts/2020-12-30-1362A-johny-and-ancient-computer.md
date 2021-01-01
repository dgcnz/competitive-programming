---
layout: post
mathjax: true
title: 1362A - Johny And Ancient Computer
problem_url: https://codeforces.com/contest/1362/problem/A
tags: math, implementation
memory_complexity: O(1)
time_complexity: O(\log{\max(a, b)})
---

Without loss of generality, say $a \geq b$. We'll try to make $b$ into $a$ by
multiplying it by $2$, $4$ and $8$.

Note that this is only possible if $a = b \times 2^k$, for some integer $k$.
We verify that, and then decompose $2^k$ into $8$s, $4$s and $2$s.


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
int solve(ll a, ll b)
{
    if (a % b)
        return -1;
    ll twok = a / b;
    int k = 0;
    while (twok != 1)
    {
        if (twok % 2)
            return -1;
        twok /= 2;
        k++;
    }
    int ans = 0;
    ans += k / 3;
    k %= 3;
    ans += k / 2;
    k %= 2;
    ans += k / 1;
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a < b)
            swap(a, b);
        cout << solve(a, b) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

