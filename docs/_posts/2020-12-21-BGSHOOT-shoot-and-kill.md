---
layout: post
mathjax: true
title: BGSHOOT - Shoot And Kill
problem_url: https://url.com
tags: data_structures, segment_tree, coordinate_compression
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

Essentially the problem asks you to find the maximum number of intersections
of ranges `[x, y]` in a given range `[l, r]`.

Since the ranges are too big, we have to do coordinate compression to be able
to fit all of them in an array.

So, ideally we'll have a frequency array $freq$, where $freq_i$ denotes the
number of ranges that pass through that point. To compute this efficiently,
we may use a difference array to construct the frequency array in $O(n)$.

Having done this, we may use a segment tree built on top of the resulting
frequency array, to efficiently query for maximum on a range `[l, r]`.


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
using ii = pair<int, int>;
using vi = vector<int>;
template <typename T>
map<T, int> compress(vector<T> values)
{
    map<T, int> mp;
    int cnt = 0;
    for (auto v : values)
        mp[v];
    for (auto &[k, v] : mp)
        v = cnt++;
    return mp;
}
int e(void) { return 0; }
int f(int a, int b) { return max(a, b); }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n;
    vector<ii> xy(n);
    vector<int> values;
    for (auto &[x, y] : xy)
    {
        cin >> x >> y, x--, y--;
        values.push_back(x), values.push_back(y);
    }
    cin >> q;
    vector<ii> lr(q);
    for (auto &[l, r] : lr)
    {
        cin >> l >> r, l--, r--;
        values.push_back(l), values.push_back(r);
    }
    auto c = compress(values);
    int m = (int)(c).size();
    vector<int> freq(m + 2, 0);
    for (auto [x, y] : xy)
        freq[c[x]] += 1, freq[c[y] + 1] -= 1;
    int cnt = 0;
    for (auto &x : freq)
        cnt += x, x = cnt;
    segtree<int, f, e> st(freq);
    for (auto [l, r] : lr)
        cout << st.prod(c[l], c[r] + 1) << endl;
    return 0;
}

{% endraw %}
```
</details>

