---
layout: post
mathjax: true
title: 761C - Dasha And Password
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
using ll = long long;
const int NMAX = 50 + 11;
const int MMAX = 50 + 11;
int n, m;
int mem[NMAX][3];
int solve(void)
{
    ll ans = 3 * MMAX;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;
            for (int k = 0; k < n; ++k)
            {
                if (k == j or k == i)
                    continue;
                ans = min(ans, (ll)(mem[i][0] + mem[j][1] + mem[k][2]));
            }
        }
    }
    return ans;
}
int main(void)
{
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        mem[i][0] = mem[i][1] = mem[i][2] = MMAX;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        for (int j = 0; j < m; ++j)
        {
            if (isdigit(s[j]))
                mem[i][0] = min(mem[i][0], min(j, m - j));
            else if (isalpha(s[j]))
                mem[i][1] = min(mem[i][1], min(j, m - j));
            else
                mem[i][2] = min(mem[i][2], min(j, m - j));
        }
    }
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```
</details>

