---
layout: post
mathjax: true
title: abc130_d - Enough Array
problem_url: https://atcoder.jp/contests/abc130/tasks/abc130_d
tags: two_pointers
memory_complexity: O(n)
time_complexity: O(n)
---

We want to count the ranges $l, r$ inclusive whose sum is $\geq k$.

For a fixed $r$, we need to count how many $l$'s satisfy this previous
condition. We note that as we increase $l$ for any fixed $r$, its sum
decreases and there's a point where it becomes $\leq k$.

We can find this point using binary search. However, we may also note that we
can take advantage of the answer for a particular $r$, say $l_r$, to reduce
the search space of $r + 1$. Therefore, a two pointers approach can be
applied.


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
using vi = vector<int>;
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), pa(n);
    read_n(begin(a), n);
    partial_sum(begin(a), end(a), begin(pa));
    function<ll(int, int)> sum = [&pa](int l, int r) {
        return pa[r] - (l == 0 ? 0LL : pa[l - 1]);
    };
    ll ans = 0;
    for (int r = 0, l = 0; r < n; ++r)
    {
        while (sum(l, r) >= k)
            ++l;
        ans += l;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

