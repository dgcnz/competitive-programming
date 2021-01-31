---
layout: post
mathjax: true
title: abc151_c - Welcome To Atcoder
problem_url: https://atcoder.jp/contests/abc151/tasks/abc151
tags: implementation
memory_complexity: O(n)
time_complexity: O(n)
---

Implementation.


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
ii solve(vector<ii> sub_status, int n)
{
    vi problem(n, 0);
    ll penalty = 0;
    for (auto [p, s] : sub_status)
    {
        if (s == -1 and problem[p] <= 0)
        {
            problem[p] += s;
        }
        else if (s == +1)
        {
            if (problem[p] < 0)
                penalty += -problem[p];
            problem[p] = 1;
        }
    }
    ll score = count_if(begin(problem), end(problem), [](int x) { return x > 0; });
    return {score, penalty};
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ii> sub_status(m);
    for (int i = 0; i < m; ++i)
    {
        string si;
        cin >> sub_status[i].first >> si, sub_status[i].first--;
        sub_status[i].second = si == "AC" ? +1 : -1;
    }
    auto [score, penalty] = solve(sub_status, n);
    cout << score << " " << penalty << endl;
    return 0;
}

{% endraw %}
```
</details>

