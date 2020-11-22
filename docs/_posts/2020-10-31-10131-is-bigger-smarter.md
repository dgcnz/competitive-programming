---
layout: post
mathjax: true
title: 10131 Is Bigger Smarter
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
using iii = tuple<int, int, int>;
using ii = pair<int, int>;
const int NMAX = 1e5 + 11;
int n;
bool vis[NMAX];
iii wsi[NMAX];
ii dp[NMAX];
void reconstruct(int i)
{
    if (i == -1)
        return;
    reconstruct(dp[i].second);
    cout << get<2>(wsi[i]) + 1 << endl;
}
void solve(void)
{
    sort(wsi, wsi + n);
    for (int i = 0; i < n; ++i)
    {
        dp[i].second = -1;
        for (int j = 0; j < i; ++j)
        {
            if (get<1>(wsi[j]) > get<1>(wsi[i]) and
                get<0>(wsi[j]) < get<0>(wsi[i]))
            {
                if (dp[i].first < dp[j].first)
                    dp[i] = make_pair(dp[j].first, j);
            }
        }
        dp[i].first += 1;
    }
    int lasti, lastv = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (lastv < dp[i].first)
        {
            lasti = i;
            lastv = dp[i].first;
        }
    }
    cout << lastv << endl;
    reconstruct(lasti);
}
int main(void)
{
    int i = 0, w, s;
    while (cin >> w >> s)
    {
        wsi[i] = make_tuple(w, s, i);
        ++i;
    }
    n = i;
    solve();
    return 0;
}

{% endraw %}
```