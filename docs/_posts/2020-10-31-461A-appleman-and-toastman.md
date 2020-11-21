---
layout: post
title: 461A Appleman And Toastman
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = long long;
int n;
int a[300010];
ll solve(void)
{
    ll ans = 0;
    ll w = 2;
    sort(a, a + n);
    for (int i = 0; i < n - 1; ++i)
    {
        ans += w * a[i];
        ++w;
    }
    return ans + (w - 1) * a[n - 1];
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << solve() << endl;
    return 0;
}

```
