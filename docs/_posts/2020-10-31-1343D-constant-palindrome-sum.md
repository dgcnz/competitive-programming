---
layout: post
mathjax: true
title: 1343D Constant Palindrome Sum
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
using ll = long long;
using vi = vector<int>;
int solve(vi a, int k)
{
    int n = (int)a.size(), ans = 1e9;
    vi cnt(2 * k + 2, 0), pre(2 * k + 2, 0);
    for (int i = 0; i < n / 2; ++i)
    {
        int l = a[i], r = a[n - i - 1];
        int ll = l + 1, lr = l + k;
        int rl = r + 1, rr = r + k;
        ++cnt[l + r];
        ++pre[min(ll, rl)];
        --pre[max(lr, rr) + 1];
    }
    for (int i = 1; i <= 2 * k + 1; ++i)
        pre[i] += pre[i - 1];
    for (int sum = 2; sum <= 2 * k; ++sum)
        ans = min(ans, (pre[sum] - cnt[sum]) + (n / 2 - pre[sum]) * 2);
    return ans;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vi a(n);
        for (auto &ai : a)
            cin >> ai;
        cout << solve(a, k) << endl;
    }
    return 0;
}

{% endraw %}
```