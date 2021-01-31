---
layout: post
mathjax: true
title: 1406D - Three Sequences
problem_url: https://codeforces.com/contest/1406/problem/D
tags: difference_array, greedy, constructive
memory_complexity: O(n)
time_complexity: O(n)
---

[Editorial](https://codeforces.com/blog/entry/82560).



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
template <typename T>
T ceil(T a, T b)
{
    return a / b + (((a ^ b) >= 0) && (abs(a) % abs(b) != 0));
}
template <typename T>
struct DifferenceArray
{
    vector<T> d;
    array<ll, 2> unsigned_sum;
    DifferenceArray(const vector<T> &a) : d(a.size()), unsigned_sum({0, 0})
    {
        adjacent_difference(begin(a), end(a), begin(d));
        for (auto di : d)
            unsigned_sum[di > 0] += abs(di);
        unsigned_sum[d[0] > 0] -= abs(d[0]);
    }
    void update(int i, T x)
    {
        if (i >= (int)(d).size())
            return;
        if (i > 0)
            unsigned_sum[d[i] > 0] -= abs(d[i]);
        d[i] += x;
        if (i > 0)
            unsigned_sum[d[i] > 0] += abs(d[i]);
    }
    void update(int l, int r, T x) { update(l, +x), update(r + 1, -x); }
    vector<T> A() const
    {
        vector<T> ans(d.size());
        partial_sum(begin(d), end(d), begin(ans));
        return ans;
    }
    ll query() { return ceil(d[0] + unsigned_sum[1], 2LL); }
};
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;
    DifferenceArray da(a);
    cout << da.query() << endl;
    ((void)0);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x, l--, r--;
        da.update(l, r, x);
        cout << da.query() << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

