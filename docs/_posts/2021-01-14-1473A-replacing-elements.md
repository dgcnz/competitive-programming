---
layout: post
mathjax: true
title: 1473A - Replacing Elements
problem_url: https://codeforces.com/contest/1473/problem/A
tags: greedy
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

If all elements are less than $d$, then no change is need to be made. Assume
otherwise.

Note that the optimal strategy is to pick the two smallest values as $a_j$
and $a_k$ and replace every $a_i > a_j + a_k$ with their sum. Iff $a_j + a_k
\leq d$ then it is possible.


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
bool solve(vi a, int d)
{
    sort(begin(a), end(a));
    if (a.back() <= d)
        return true;
    if (a.size() > 1 and a[0] + a[1] <= d)
        return true;
    return false;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vi a(n);
        for (auto &ai : a)
            cin >> ai;
        cout << (solve(a, d) ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

