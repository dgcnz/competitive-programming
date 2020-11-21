---
layout: post
title: 1341B Nastya And Door
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = long long;
const int NMAX = 2 * 1e5 + 11;
int peaks[NMAX];
int a[NMAX];
int n, k;
int main(void)
{
    int t, maxpeaks, pos, cur;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        peaks[0] = 0;
        for (int i = 1; i < (n - 1); ++i)
        {
            peaks[i] = peaks[i - 1];
            if (a[i - 1] < a[i] and a[i] > a[i + 1])
                ++peaks[i];
        }
        peaks[n - 1] = peaks[n - 2];
        pos = 0;
        maxpeaks = 0;
        for (int i = n - 1; (i - k + 1) >= 0; --i)
        {
            cur = peaks[i - 1] - peaks[i - k + 1];
            if (cur >= maxpeaks)
            {
                maxpeaks = cur;
                pos = i - k + 1;
            }
        }
        cout << maxpeaks + 1 << " " << pos + 1 << endl;
    }
}

```
