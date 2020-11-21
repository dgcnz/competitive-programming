---
layout: post
mathjax: true
title: 1621 Distinct Numbers
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
    int n;
    cin >> n;
    vi x(n);
    for (auto &xi : x)
        cin >> xi;
    sort(x.begin(), x.end());
    cout << distance(x.begin(), unique(x.begin(), x.end())) << endl;
    return 0;
}

{% endraw %}
```
