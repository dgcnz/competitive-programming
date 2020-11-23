---
layout: post
mathjax: true
title: 1003D Coins And Queries
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



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
using ii = pair<int, int>;
using mii = map<int, int, greater<int>>;
int const INF = 2e9;
int solve(int x, mii &a)
{
    int cnt = 0, ccnt;
    auto begin = a.begin();
    while (x > 0)
    {
        auto it = lower_bound(begin, a.end(), make_pair(x, INF), greater<ii>());
        if (it == a.end())
            return -1;
        ccnt = min(it->second, x / it->first);
        x -= it->first * ccnt;
        begin = next(it);
        cnt += ccnt;
    }
    return cnt;
}
int main(void)
{
    int n, q, x;
    mii a;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai;
        a[ai]++;
    }
    while (q--)
    {
        cin >> x;
        cout << solve(x, a) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

