---
layout: post
mathjax: true
title: 61E - Enemy Is Weak
problem_url: https://codeforces.com/problemset/problem/61/E
tags: data_structures, segment_tree
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

For each element $a_k$ we can know how many times it contributes to the
weakness of the overall army if we can support the following range query:

- `inv(l, r)`: Number of inversions with $a_i > a_j$ such that
  $l \leq a_j \leq r$.

To compute such value, we can use this additional function:
- `freq(l, r)`: Number of elements $l \leq a_i \leq r$.

For each element from the left to right, we'll do the following:

1. We'll increase our overall answer by querying for `inv(ai + 1, amax)`.
2. We'll increase the inverse count of $a_i$ by `freq(ai + 1, amax)`, i.e.
e number of elements greater than $a_i$ seen so far.
3. We'll increase the occurrence of $a_i$ in `freq` by 1.

Any range query data structure should do the job (I'm using AtCoder's Segment
ee), as long as you compress the numbers.


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
using S = ll;
S e() { return 0; }
S op(S a, S b) { return a + b; }
ll solve(vi a)
{
    using RangeSumQuery = atcoder::segtree<S, op, e>;
    auto id = compress(a);
    int n = (int)(id).size() + 1;
    ll ans = 0;
    RangeSumQuery freq(n), inv(n);
    for (auto &ai : a)
    {
        ai = id[ai];
        ll inversions = freq.prod(ai + 1, n);
        ans += inv.prod(ai + 1, n);
        inv.set(ai, inv.get(ai) + inversions);
        freq.set(ai, freq.get(ai) + 1);
    }
    return ans;
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

