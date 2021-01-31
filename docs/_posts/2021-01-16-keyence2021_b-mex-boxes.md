---
layout: post
mathjax: true
title: keyence2021_b - Mex Boxes
problem_url: https://atcoder.jp/contests/keyence2021/tasks/keyence2021_b
tags: greedy
memory_complexity: O(n)
time_complexity: O(n \log{n})
---


Observations:
1. For a given $a_i$, we can only add $a_i + 1$ to the answer if we place all
  $0 \leq a_j \leq a_i - 1$ in the same box.
2. To maximize the answer, we should try to place the biggest valid $a_i$
possible (following observation 1) on as many boxes as we can.

We can store all numbers ordered in a multiset, and for each box try to place
the biggest valid $a_i$, deleting all the used elements from the multiset in
that attempt. All the remaining elements will be thrown in the last box, as
they don't contribute to anything.


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
int solve(vi a, int k)
{
    multiset<int> ms(begin(a), end(a));
    int ans = 0;
    while (k--)
    {
        int cur = 0;
        auto it = ms.find(cur);
        while (it != ms.end())
        {
            ms.erase(it);
            it = ms.find(++cur);
        }
        ans += cur;
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;
    cout << solve(a, k) << endl;
    return 0;
}

{% endraw %}
```
</details>

