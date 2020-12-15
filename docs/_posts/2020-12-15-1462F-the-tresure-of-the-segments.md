---
layout: post
mathjax: true
title: 1462F - The Tresure Of The Segments
problem_url: https://codeforces.com/contest/1462/problem/F
tags: sorting, brute_force
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

For each range $(l, r)$ present in the array, see how many ranges wouldn't be
covered and keep the one that yields the minimum answer.

To compute $ans_{l, r}$, note that we only need to know $ans_l$ and $ans_r$:

$$ans_l = \text{#right endings that are less than } l $$

$$ans_r = \text{#left endings that are greater than } r $$

We can solve those queries in $O(\log{n})$ each with two arrays:
1. $sorted_l$: Array sorted by left borders.
2. $sorted_r$: Array sorted by right borders.

For example, for a given range $l, r$ to compute $ans_l$ we only need to
binary search (on $sorted_r$) the first range whose $r$ is less than $l$. The
answer is the number of elements that precede it. Pretty much the same thing
for $ans_r$.


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
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}
int solve(vector<ii> &a)
{
    int n = (int)(a).size();
    vi lb(n), rb(n);
    for (int i = 0; i < n; ++i)
        lb[i] = a[i].first, rb[i] = a[i].second;
    sort(begin(lb), end(lb)), sort(begin(rb), end(rb));
    int ans = 1e9 + 7;
    for (auto [l, r] : a)
    {
        int ansl = distance(begin(rb), lower_bound(begin(rb), end(rb), l)),
            ansr = distance(upper_bound(begin(lb), end(lb), r), end(lb));
        ans = min(ans, ansl + ansr);
    }
    return ans;
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
        vector<ii> a(n);
        for (auto &[l, r] : a)
            cin >> l >> r;
        cout << solve(a) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

