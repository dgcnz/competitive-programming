---
layout: post
mathjax: true
title: INVCNT - Inversion Count
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
using vi = vector<int>;
using ll = long long;
const int amax = 1e7 + 11;
struct fenwick
{
    int n;
    vi bit;
    fenwick(int _n) : n(_n + 1) { bit.assign(_n + 1, 0); }
    void point_update(int i, int delta)
    {
        ++i;
        while (i < n)
        {
            bit[i] += delta;
            i += (i & -i);
        }
    }
    ll prefix_sum(int r)
    {
        ll ans = 0;
        ++r;
        while (r > 0)
        {
            ans += bit[r];
            r -= (r & -r);
        }
        return ans;
    }
    ll sum(int l, int r)
    {
        ll ans = prefix_sum(r);
        ans -= prefix_sum(l - 1);
        return ans;
    }
};
int main(void)
{
    int t, n, x;
    ll ans;
    cin >> t;
    while (t--)
    {
        cin >> n;
        fenwick tree(amax + 1);
        ans = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            tree.point_update(x, 1);
            ans += tree.sum(x + 1, amax);
        }
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

