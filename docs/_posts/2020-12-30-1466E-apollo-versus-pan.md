---
layout: post
mathjax: true
title: 1466E - Apollo Versus Pan
problem_url: https://codeforces.com/contest/1466/problem/E
tags: math, bitmask
memory_complexity: O(n)
time_complexity: O(n \log{x_{max}})
---


[Editorial](https://codeforces.com/blog/entry/86126) is pretty cool.



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
using namespace atcoder;
using ll = long long;
using vi = vector<int>;
using mint = modint1000000007;
int const BITSZ = 60;
int solve(vector<ll> a)
{
    int n = (int)(a).size();
    vi cnt(BITSZ, 0);
    mint ans;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < BITSZ; ++j)
            cnt[j] += (a[i] >> j) & 1;
    for (int j = 0; j < n; ++j)
    {
        mint sum_or = 0, sum_and = 0;
        for (int b = 0; b < BITSZ; ++b)
        {
            if ((a[j] >> b) & 1)
            {
                sum_or += mint(1LL << b) * n;
                sum_and += mint(1LL << b) * cnt[b];
            }
            else
                sum_or += mint(1LL << b) * cnt[b];
        }
        ans += sum_or * sum_and;
    }
    return ans.val();
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a)
            cin >> x;
        cout << solve(a) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

