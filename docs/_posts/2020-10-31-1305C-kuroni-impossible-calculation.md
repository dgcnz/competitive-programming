---
layout: post
title: 1305C Kuroni Impossible Calculation
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = long long;
int n, m;
int a[200010];
ll solve(void)
{
    ll ans = 1;
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
            ans = (ans * (a[i] - a[j]) % m) % m;
    }
    return ans;
}
int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n <= m)
        cout << solve() << endl;
    else
        cout << 0 << endl;
    return 0;
}

```
