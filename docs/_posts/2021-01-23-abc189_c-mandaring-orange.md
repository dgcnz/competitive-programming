---
layout: post
mathjax: true
title: abc189_c - Mandaring Orange
problem_url: https://atcoder.jp/contests/abc189/tasks/abc189_c
tags: greedy, segment_tree, binary_search, brute_force
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

For each element $a_i$, find indexes $l$ and $r$, such that $l \leq i \leq r$
and $\min{a_l,...,a_i,...,a_r} = a_i$. The answer for such particular index
would then be $a_i \times (r - l + 1)$.

There are several ways to do this, check
[Editorial](https://atcoder.jp/contests/abc189/editorial/592) for more info.

In my approach, I used a segment tree to handle minimum range queries and
then used binary search on it to find both indexes. Check AtCoder's
SegmentTree's
[docs](https://atcoder.github.io/ac-library/master/document_en/segtree.html)
and this [problem](https://atcoder.jp/contests/practice2/tasks/practice2_j)
for an idea of how `min_left` and `max_right` work.



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
using S = int;
int op(int a, int b) { return min(a, b); }
int e() { return 1e9; }
ll solve(vi a)
{
    int n = (int)(a).size();
    ll ans = 0;
    using RMQ = atcoder::segtree<S, op, e>;
    RMQ st(a);
    for (int i = 0; i < n; ++i)
    {
        int ai = a[i];
        auto f = [ai](S b) { return ai <= b; };
        int l = st.min_left(i, f);
        int r = st.max_right(i, f);
        ans = max(ans, a[i] * ll(r - l));
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

