---
layout: post
title: 1334A Level Statistics
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
const int NMAX = 100 + 11;
int n, p[NMAX], c[NMAX];
bool solve(void)
{
    int lp, lc, dp, dc;
    lp = lc = 0;
    for (int i = 0; i < n; ++i)
    {
        dp = p[i] - lp;
        dc = c[i] - lc;
        if (dp < 0 or dc < 0 or dp < dc)
            return false;
        lp = p[i];
        lc = c[i];
    }
    return true;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> p[i] >> c[i];
        cout << (solve() ? "YES" : "NO") << endl;
    }
}

```
