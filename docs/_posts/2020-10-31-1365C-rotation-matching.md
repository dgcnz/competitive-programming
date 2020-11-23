---
layout: post
mathjax: true
title: 1365C Rotation Matching
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
const int NMAX = 2e5 + 11;
int n, a[NMAX], b[NMAX];
int solve(void)
{
    vi desired(n, 0);
    vi moves(n, 0);
    for (int i = 0; i < n; ++i)
        desired[a[i]] = i;
    for (int i = 0; i < n; ++i)
    {
        int j = (desired[b[i]] - i + n) % n;
        ++moves[j];
    }
    return *max_element(moves.begin(), moves.end());
}
int main(void)
{
    int x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        a[i] = x - 1;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        b[i] = x - 1;
    }
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```
</details>

