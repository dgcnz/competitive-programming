---
layout: post
mathjax: true
title: 1475D - Cleaning The Phone
problem_url: https://codeforces.com/contest/1475/problem/D
tags: binary_search, sortings
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

[Comment](https://codeforces.com/blog/entry/87161?#comment-753182)


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
int solve(vi a, vi b, int m)
{
    int n = (int)(a).size();
    vector<ll> acc[2];
    acc[0] = {0}, acc[1] = {0};
    for (int i = 0; i < n; ++i)
        acc[b[i] - 1].push_back(a[i]);
    for (int i = 0; i < 2; ++i)
    {
        auto start = begin(acc[i]) + 1;
        sort(start, end(acc[i]), greater<int>());
        partial_sum(start, end(acc[i]), start);
    }
    ll const INF = 1e15;
    ll ans = INF;
    int n1 = acc[0].size();
    for (int i = 0; i < n1; ++i)
    {
        auto it = lower_bound(begin(acc[1]), end(acc[1]), max(0LL, m - acc[0][i]));
        if (it != acc[1].end())
        {
            int j = distance(begin(acc[1]), it);
            ans = min(ans, i + 2LL * j);
        }
    }
    return ans == INF ? -1 : ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vi a(n), b(n);
        for (auto &ai : a)
            cin >> ai;
        for (auto &bi : b)
            cin >> bi;
        cout << solve(a, b, m) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

