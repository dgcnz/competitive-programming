---
layout: post
title: 1334C Circle Of Monsters
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
const int NMAX = 3 * 1e5 + 11;
int n;
ll sum, a[NMAX], b[NMAX];
ll solve(void)
{
    ll suma, sumb, mn = LLONG_MAX;
    suma = sumb = 0;
    for (int i = 0; i < n; ++i)
    {
        suma += a[i];
        b[i] = min(b[i], a[(i + 1) % n]);
        sumb += b[i];
        mn = min(mn, b[i]);
    }
    return suma - sumb + mn;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        sum = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```
