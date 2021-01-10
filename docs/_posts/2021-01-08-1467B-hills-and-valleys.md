---
layout: post
mathjax: true
title: 1467B - Hills And Valleys
problem_url: https://codeforces.com/contest/1467/problem/B
tags: brute_force, implementation
memory_complexity: O(n)
time_complexity: O(n)
---

Try all positions and keep the one that reduces hills/valleys the most.


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
    int n = (int)(a).size();
    auto is_hill = [n, &a](int i) {
        return (i <= 0 or i >= n - 1) ? false
                                      : a[i - 1] < a[i] and a[i] > a[i + 1];
    };
    auto is_valley = [n, &a](int i) {
        return (i <= 0 or i >= n - 1) ? false
                                      : a[i - 1] > a[i] and a[i] < a[i + 1];
    };
    auto is = [is_hill, is_valley](int i) {
        return is_hill(i) or is_valley(i);
    };
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += is(i);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int temp = a[i], cur = 0;
        bool l = is(i - 1), m = is(i), r = is(i + 1);
        if (i > 0)
        {
            a[i] = a[i - 1];
            cur = max(cur, l - is(i - 1) + m - is(i) + r - is(i + 1));
        }
        if (i < n - 1)
        {
            a[i] = a[i + 1];
            cur = max(cur, l - is(i - 1) + m - is(i) + r - is(i + 1));
        }
        a[i] = temp;
        cnt = max(cnt, cur);
    }
    return ans - cnt;
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

