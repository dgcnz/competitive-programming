---
layout: post
mathjax: true
title: 1368D - And Or And Square Sum
problem_url: https://codeforces.com/contest/1368/problem/D
tags: greedy, bitmasks, math
memory_complexity: O(n)
time_complexity: O(n \log{a_{max}})
---

To maximize each term of the summation, we should try to make large numbers
as large as possible (to maximize the contribution of each $a_i^2$).

Note that each operation effectively transfers all $1$'s from a number $a_i$
to another number $a_j$ (in binary).

We can think of a greedy strategy where we redistribute the $1$'s and
concentrate them in a few numbers in order to make them larger.


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
ll solve(vi a)
{
    int const BSZ = 20;
    vi cnt(BSZ, 0);
    for (auto ai : a)
        for (int i = 0; i < BSZ; ++i)
            cnt[i] += (ai >> i) & 1;
    vector<ll> ans(a.size(), 0);
    for (auto &ai : ans)
    {
        for (int i = 0; i < BSZ; ++i)
        {
            if (cnt[i])
            {
                ai |= (1 << i);
                cnt[i]--;
            }
        }
    }
    transform(begin(ans), end(ans), begin(ans), [](ll x) { return x * x; });
    return accumulate(begin(ans), end(ans), 0LL);
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;
    cout << solve(a) << endl;
    return 0;
}

{% endraw %}
```
</details>

