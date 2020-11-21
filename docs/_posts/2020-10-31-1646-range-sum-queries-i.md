---
layout: post
mathjax: true
title: 1646 Range Sum Queries I
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
using ii = pair<int, int>;
using vi = vector<int>;
int const NMAX = 2e5 + 11;
ll n, a[NMAX], p[NMAX];
inline ll sum(int l, int r) { return p[r] - p[l - 1]; }
int main(void)
{
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], p[i] = a[i] + p[i - 1];
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum(l, r) << endl;
    }
    return 0;
}

{% endraw %}
```
