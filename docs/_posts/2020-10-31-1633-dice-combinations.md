---
layout: post
mathjax: true
title: 1633 Dice Combinations
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
const int NMAX = 1e6 + 11;
const int MOD = 1e9 + 7;
int mem[NMAX];
bool vis[NMAX];
ll dp(int sum)
{
    if (sum < 0)
        return 0;
    else if (sum == 0)
        return 1;
    int &ans = mem[sum];
    if (vis[sum])
        return ans;
    vis[sum] = true;
    for (int d = 1; d <= 6; ++d)
        ans = (ans + dp(sum - d) % MOD) % MOD;
    return ans;
}
int main(void)
{
    int n;
    cin >> n;
    cout << dp(n) << endl;
    return 0;
}

{% endraw %}
```