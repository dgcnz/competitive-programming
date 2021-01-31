---
layout: post
mathjax: true
title: 1475G - Strange Beauty
problem_url: https://codeforces.com/contest/1475/problem/G
tags: dp, number_theory
memory_complexity: O(a_{max})
time_complexity: O(a_{max} \log{a_max})
---

[Editorial](https://codeforces.com/blog/entry/87188)
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
int solve(vi a)
{
    int const AMAX = *max_element(begin(a), end(a)) + 1, n = a.size();
    vi dp(AMAX, 0), cnt(AMAX, 0);
    for (auto ai : a)
        cnt[ai]++;
    for (int x = 1; x < AMAX; ++x)
    {
        dp[x] += cnt[x];
        for (int y = 2 * x; y < AMAX; y += x)
            dp[y] = max(dp[y], dp[x]);
    }
    return n - *max_element(begin(dp), end(dp));
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
            cin >> ai;
        cout << solve(a) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

