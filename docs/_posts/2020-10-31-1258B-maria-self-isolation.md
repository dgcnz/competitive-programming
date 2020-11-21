---
layout: post
mathjax: true
title: 1258B Maria Self Isolation
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

```cpp
{% raw %}
using namespace std;
const int NMAX = 1e5 + 11;
int n, a[NMAX];
int solve(void)
{
    int grannies = 0;
    bool found = false;
    sort(a, a + n);
    for (int i = n - 1; i >= 0; --i)
    {
        grannies = i + 1;
        if (grannies >= a[i])
        {
            found = true;
            break;
        }
    }
    return grannies + found;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```
