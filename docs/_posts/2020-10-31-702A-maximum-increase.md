---
layout: post
title: 702A Maximum Increase
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
int n;
int a[100010];
int solve(void)
{
    int ans = 1;
    int cur = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > a[i - 1])
            ++cur;
        else
            cur = 1;
        ans = max(ans, cur);
    }
    return ans;
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
