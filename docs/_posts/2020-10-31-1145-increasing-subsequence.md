---
layout: post
mathjax: true
title: 1145 Increasing Subsequence
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
using vi = vector<int>;
int main(void)
{
    int n, x;
    vi dp;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it != dp.end())
            *it = x;
        else
            dp.push_back(x);
    }
    cout << dp.size() << endl;
    return 0;
}

{% endraw %}
```
