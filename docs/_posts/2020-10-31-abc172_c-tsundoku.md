---
layout: post
title: Abc172_C Tsundoku
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = long long;
int const NMAX = 2e5 + 11;
int n, m;
ll k, pa[NMAX], pb[NMAX];
int main(void)
{
    int ai, bi;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> ai, pa[i] = ai + pa[i - 1];
    for (int i = 1; i <= m; ++i)
        cin >> bi, pb[i] = bi + pb[i - 1];
    int ans = 0, j;
    for (int i = 0; i <= n; ++i)
    {
        if (k - pa[i] < 0)
            break;
        auto match = prev(upper_bound(pb + 1, pb + m + 1, k - pa[i]));
        j = distance(pb, match);
        ans = max(ans, i + j);
    }
    cout << ans << endl;
    return 0;
}

```
