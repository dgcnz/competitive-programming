---
layout: post
mathjax: true
title: Dpe Knapsack 2
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

```cpp
{% raw %}
using namespace std;
using ll = long long;
const int NMAX = 1e2 + 11;
const int VMAX = 1e3 + 11;
int n, c, v_max, w[NMAX], v[NMAX];
ll mem[NMAX][VMAX];
ll solve(void)
{
    v_max = accumulate(v + 1, v + n + 1, 0);
    vector<vector<ll>> mem(n + 1, vector<ll>(v_max + 1, (ll)1e12));
    for (int i = 0; i <= n; ++i)
        mem[i][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int vacc = 1; vacc <= v_max; ++vacc)
        {
            ll &ans = mem[i][vacc];
            if (vacc - v[i] >= 0)
                ans = min(w[i] + mem[i - 1][vacc - v[i]], mem[i - 1][vacc]);
            else
                ans = mem[i - 1][vacc];
        }
    }
    int ans = 0;
    for (int vacc = 1; vacc <= v_max; ++vacc)
        if (mem[n][vacc] <= c)
            ans = vacc;
    return ans;
}
int main(void)
{
    cin >> n >> c;
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> v[i];
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```