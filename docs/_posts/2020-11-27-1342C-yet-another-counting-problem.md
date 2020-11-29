---
layout: post
mathjax: true
title: 1342C - Yet Another Counting Problem
problem_url: https://codeforces.com/contest/1342/problem/C
tags: math, lcm
memory_complexity: O(ab)
time_complexity: O(ab + q)
---

- We first observe that the after every $lcm(a, b)$, the pattern of moduli
repeats itself.
- This suggest the idea of precomputing the result for the first block of
numbers ( (of size $lcm(a,b)$). We'll refer to this array as `block` or
`pre`.
- Querying for a [0, r] range seems reasonably simple: We count how many full
blocks fit in our range + the part of the block that was cut by $r$.
- We can solve the problem's query [l, r] by splitting it into two of our
queries. [0, r] - [0, l - 1].


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
int const AMAX = 200 + 5;
ll period, pre[AMAX * AMAX];
inline ll cnt(ll r) { return pre[period - 1] * (r / period) + pre[r % period]; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, q;
        cin >> a >> b >> q;
        period = lcm(a, b);
        pre[0] = 0;
        for (int x = 1; x <= period; ++x)
            pre[x] = pre[x - 1] + (((x % a) % b) != ((x % b) % a));
        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            cout << cnt(r) - cnt(l - 1) << " ";
        }
        cout << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

