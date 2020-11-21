---
layout: post
title: Dpd Knapsack 1
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
const int NMAX = 1e2 + 11;
const int WMAX = 1e5 + 11;
int n, c, w[NMAX], v[NMAX];
ll mem[NMAX][WMAX];
bool vis[NMAX][WMAX];
ll dp(int i, int cl)
{
    ll &ans = mem[i][cl];
    if (i == n)
        return 0;
    if (vis[i][cl])
        return mem[i][cl];
    vis[i][cl] = true;
    ans = 0;
    if (cl - w[i] >= 0)
        ans = dp(i + 1, cl - w[i]) + v[i];
    return (ans = max(ans, dp(i + 1, cl)));
}
int main(void)
{
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        cin >> w[i] >> v[i];
    cout << dp(0, c) << endl;
    return 0;
}

{% endraw %}
```
