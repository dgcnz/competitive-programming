---
layout: post
mathjax: true
title: 1213D2 - Equalizing Division
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
using vi = vector<int>;
int const INF = 1e9;
int const NMAX = 2e5 + 11;
int k, best_cost[NMAX];
deque<int> costs[NMAX];
void build() { fill(best_cost, best_cost + NMAX, INF); }
int query(int x) { return (int)costs[x].size() == k ? best_cost[x] : INF; }
void insert(int x, int cur_cost)
{
    if ((int)costs[x].size() == 0)
        best_cost[x] = 0;
    costs[x].push_back(cur_cost);
    if ((int)costs[x].size() > k)
    {
        best_cost[x] -= costs[x].front();
        costs[x].pop_front();
    }
    best_cost[x] += cur_cost;
}
int solve(vi a)
{
    int ans = INF;
    vi cnt(NMAX, 0);
    vector<vi> best_cost(NMAX, vi(log2(NMAX) + 5, 0));
    sort(a.begin(), a.end());
    for_each(a.rbegin(), a.rend(), [&ans](int ai) {
        for (int i = 0, m = log2(ai) + 2; i < m; ++i, ai /= 2)
        {
            insert(ai, i);
            ans = min(ans, query(ai));
        }
    });
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n;
    vi a;
    cin >> n >> k;
    a.resize(n);
    for (auto &ai : a)
        cin >> ai;
    build();
    cout << solve(a) << endl;
    return 0;
}

{% endraw %}
```
</details>

