---
layout: post
mathjax: true
title: 1640 Sum Of Two Values
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ii = pair<int, int>;
using vii = vector<ii>;
int main(void)
{
    int n, x;
    cin >> n >> x;
    vii a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        auto it = lower_bound(
            a.begin() + i + 1, a.end(), make_pair(x - a[i].first, 0));
        if (it != a.end() and it->first == x - a[i].first)
        {
            cout << a[i].second + 1 << " " << it->second + 1 << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

{% endraw %}
```
