---
layout: post
mathjax: true
title: Dpc Vacation
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
const int NMAX = 1e5 + 11;
int n, abc[NMAX][3], mem[NMAX][3];
bool vis[NMAX][3];
int dp(int i, int p)
{
    int &ans = mem[i][p];
    if (i == n)
        return 0;
    if (vis[i][p])
        return mem[i][p];
    vis[i][p] = true;
    ans = INT_MIN;
    for (int j = 0; j < 3; ++j)
    {
        if (j == p)
            continue;
        ans = max(ans, dp(i + 1, j) + abc[i][j]);
    }
    return ans;
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> abc[i][j];
    cout << dp(0, -1) << endl;
    return 0;
}

{% endraw %}
```