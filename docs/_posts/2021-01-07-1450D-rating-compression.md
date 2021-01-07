---
layout: post
mathjax: true
title: 1450D - Rating Compression
problem_url: https://codeforces.com/problemset/problem/1450/D
tags: two_pointers, greedy, segment_tree, implementation
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

[Editorial](https://codeforces.com/blog/entry/85348).


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
int e() { return 0x7fffffff; }
int min(int a, int b) { return std::min(a, b); }
using RMQ = atcoder::segtree<int, min, e>;
vector<int> solve(vi a)
{
    int n = (int)(a).size();
    vi ans(n, 0), cnt(n, 0);
    RMQ rmq(a);
    for (auto ai : a)
        cnt[ai]++;
    ans[0] = all_of(begin(cnt), end(cnt), [](int x) { return x > 0; });
    ans[n - 1] = cnt[0] > 0;
    if (!ans[n - 1])
        return ans;
    int i = 0, l = 0, r = n - 1;
    for (; i < n - 1; ++i)
    {
        if (a[l] == i)
            l++;
        else if (a[r] == i)
            r--;
        else
            break;
        if (rmq.prod(l, r + 1) != i + 1)
            break;
    }
    for (int j = n - (i + 1); j < n - 1; ++j)
        ans[j] = true;
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
        vi a(n);
        for (auto &ai : a)
            cin >> ai, ai--;
        auto ans = solve(a);
        for (auto x : ans)
            cout << x;
        cout << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

